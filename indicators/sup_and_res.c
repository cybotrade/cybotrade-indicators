/*
 * Tulip Indicators
 * https://tulipindicators.org/
 * Copyright (c) 2010-2017 Tulip Charts LLC
 * Lewis Van Winkle (LV@tulipcharts.org)
 *
 * This file is part of Tulip Indicators.
 *
 * Tulip Indicators is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * Tulip Indicators is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Tulip Indicators.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "../indicators.h"
#include "utils.h"

int ti_sup_and_res_start(TI_REAL const *options)
{
  UNUSED(options);
  return 0;
}

double get_pivothigh_close(TI_REAL const *const *inputs, int size, int left_bar,
                           int right_bar, int index)
{
  const TI_REAL *close = inputs[0];

  double middle_point = close[index - right_bar];
  int start_index = index - (left_bar + right_bar);
  int end_index = index;
  int temp_size = end_index - start_index + 1;
  double *temp_arr = (double *)calloc((size_t)temp_size, sizeof(double));

  const double *slice_array_inputs[] = {close};
  double *slice_array_outputs[] = {temp_arr};
  slice_array(slice_array_inputs, start_index, end_index, size,
              slice_array_outputs);

  double max_temp_arr = max_value(temp_arr, temp_size);

  free(temp_arr);

  if (max_temp_arr == middle_point)
    return middle_point;
  else
    return (double)0;
}

double get_pivotlow_close(TI_REAL const *const *inputs, int size, int left_bar,
                          int right_bar, int index)
{
  const TI_REAL *close = inputs[0];

  double middle_point = close[index - right_bar];
  int start_index = index - (left_bar + right_bar);
  int end_index = index;
  int temp_size = end_index - start_index + 1;
  double *temp_arr = (double *)calloc((size_t)temp_size, sizeof(double));

  const double *slice_array_inputs[] = {close};
  double *slice_array_outputs[] = {temp_arr};
  slice_array(slice_array_inputs, start_index, end_index, size,
              slice_array_outputs);

  double max_temp_arr = min_value(temp_arr, temp_size);

  free(temp_arr);

  if (max_temp_arr == middle_point)
    return middle_point;
  else
    return (double)0;
}

int ti_sup_and_res(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs)
{
  const TI_REAL *close = inputs[0];

  TI_REAL *buy1 = outputs[0];
  TI_REAL *buy2 = outputs[1];
  TI_REAL *buy3 = outputs[2];
  TI_REAL *buy4 = outputs[3];
  TI_REAL *buy5 = outputs[4];
  TI_REAL *buy6 = outputs[5];
  TI_REAL *buy7 = outputs[6];
  TI_REAL *buy8 = outputs[7];
  TI_REAL *sell1 = outputs[8];
  TI_REAL *sell2 = outputs[9];
  TI_REAL *sell3 = outputs[10];
  TI_REAL *sell4 = outputs[11];
  TI_REAL *sell5 = outputs[12];
  TI_REAL *sell6 = outputs[13];
  TI_REAL *sell7 = outputs[14];
  TI_REAL *sell8 = outputs[15];

  const int left_bar = (int)options[0];
  const int right_bar1 = (int)options[1];
  const int right_bar2 = (int)options[2];
  const int hma_length = (int)options[3];

  if (hma_length < 1)
    return TI_INVALID_OPTION;

  // get atr data
  const double nz_hma_options[] = {hma_length};
  double *nz_hma = malloc((unsigned int)size * sizeof(double));
  assert(nz_hma != 0);
  const double *nz_hma_inputs[] = {close};
  double *nz_hma_outputs[] = {nz_hma};
  int error = ti_hma(size, nz_hma_inputs, nz_hma_options, nz_hma_outputs);
  assert(error == TI_OKAY);

  // refill the missing zero in hma
  double *hma = (double *)calloc((size_t)size, sizeof(double));
  const double *hma_inputs[] = {nz_hma};
  double *hma_outputs[] = {hma};
  int range = hma_length - 2 + (int)floor(sqrt(hma_length));
  double value = 0;
  const double hma_options[] = {value, range};
  int error1 = ti_unshift(size, hma_inputs, hma_options, hma_outputs);
  assert(error1 == TI_OKAY);

  double *level1 = (double *)calloc((size_t)size, sizeof(double));
  double *level2 = (double *)calloc((size_t)size, sizeof(double));
  double *level3 = (double *)calloc((size_t)size, sizeof(double));
  double *level4 = (double *)calloc((size_t)size, sizeof(double));
  double *level5 = (double *)calloc((size_t)size, sizeof(double));
  double *level6 = (double *)calloc((size_t)size, sizeof(double));
  double *level7 = (double *)calloc((size_t)size, sizeof(double));
  double *level8 = (double *)calloc((size_t)size, sizeof(double));

  for (int i = left_bar + right_bar1; i < size; i++)
  {
    const double *pivot_inputs[] = {close};
    double pivothigh =
        get_pivothigh_close(pivot_inputs, size, left_bar, right_bar1, i);
    double pivotlow =
        get_pivotlow_close(pivot_inputs, size, left_bar, right_bar1, i);
    if (pivothigh != 0)
    {
      level3[i] = pivothigh;
      level5[i] = pivothigh;
      level7[i] = pivothigh;
    }
    else
    {
      level3[i] = level3[i - 1];
      level5[i] = level5[i - 2];
      level7[i] = level7[i - 3];
    }
    if (pivotlow != 0)
    {
      level4[i] = pivotlow;
      level6[i] = pivotlow;
      level8[i] = pivotlow;
    }
    else
    {
      level4[i] = level4[i - 1];
      level6[i] = level6[i - 2];
      level8[i] = level8[i - 3];
    }
  }
  for (int i = left_bar + right_bar2; i < size; i++)
  {
    const double *pivot_inputs[] = {close};
    double pivothigh_quick =
        get_pivothigh_close(pivot_inputs, size, left_bar, right_bar2, i);
    double pivotlow_quick =
        get_pivotlow_close(pivot_inputs, size, left_bar, right_bar2, i);
    if (pivothigh_quick != 0)
    {
      level1[i] = pivothigh_quick;
    }
    else
    {
      level1[i] = level1[i - 1];
    }
    if (pivotlow_quick != 0)
    {
      level2[i] = pivotlow_quick;
    }
    else
    {
      level2[i] = level2[i - 1];
    }
  }
  for (int z = 2; z < size; z++)
  {
    buy1[z] = hma[z] > level1[z] && hma[z - 1] < level1[z - 1] &&
                      close[z] > close[z - 2]
                  ? 1
                  : -1;
    buy2[z] = hma[z] > level2[z] && hma[z - 1] < level2[z - 1] &&
                      close[z] > close[z - 2]
                  ? 1
                  : -1;
    buy3[z] = hma[z] > level3[z] && hma[z - 1] < level3[z - 1] &&
                      close[z] > close[z - 2]
                  ? 1
                  : -1;
    buy4[z] = hma[z] > level4[z] && hma[z - 1] < level4[z - 1] &&
                      close[z] > close[z - 2]
                  ? 1
                  : -1;
    buy5[z] = hma[z] > level5[z] && hma[z - 1] < level5[z - 1] &&
                      close[z] > close[z - 2]
                  ? 1
                  : -1;
    buy6[z] = hma[z] > level6[z] && hma[z - 1] < level6[z - 1] &&
                      close[z] > close[z - 2]
                  ? 1
                  : -1;
    buy7[z] = hma[z] > level7[z] && hma[z - 1] < level7[z - 1] &&
                      close[z] > close[z - 2]
                  ? 1
                  : -1;
    buy8[z] = hma[z] > level8[z] && hma[z - 1] < level8[z - 1] &&
                      close[z] > close[z - 2]
                  ? 1
                  : -1;
    sell1[z] = hma[z] < level1[z] && hma[z - 1] > level1[z - 1] &&
                       close[z] < close[z - 2]
                   ? 1
                   : -1;
    sell2[z] = hma[z] < level2[z] && hma[z - 1] > level2[z - 1] &&
                       close[z] < close[z - 2]
                   ? 1
                   : -1;
    sell3[z] = hma[z] < level3[z] && hma[z - 1] > level3[z - 1] &&
                       close[z] < close[z - 2]
                   ? 1
                   : -1;
    sell4[z] = hma[z] < level4[z] && hma[z - 1] > level4[z - 1] &&
                       close[z] < close[z - 2]
                   ? 1
                   : -1;
    sell5[z] = hma[z] < level5[z] && hma[z - 1] > level5[z - 1] &&
                       close[z] < close[z - 2]
                   ? 1
                   : -1;
    sell6[z] = hma[z] < level6[z] && hma[z - 1] > level6[z - 1] &&
                       close[z] < close[z - 2]
                   ? 1
                   : -1;
    sell7[z] = hma[z] < level7[z] && hma[z - 1] > level7[z - 1] &&
                       close[z] < close[z - 2]
                   ? 1
                   : -1;
    sell8[z] = hma[z] < level8[z] && hma[z - 1] > level8[z - 1] &&
                       close[z] < close[z - 2]
                   ? 1
                   : -1;
  }

  free(nz_hma);
  free(hma);
  free(level1);
  free(level2);
  free(level3);
  free(level4);
  free(level5);
  free(level6);
  free(level7);
  free(level8);

  return TI_OKAY;
}
