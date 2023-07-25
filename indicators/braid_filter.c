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

int ti_braid_filter_start(TI_REAL const *options)
{
  UNUSED(options);
  return 0;
}

int ti_braid_filter(int size, TI_REAL const *const *inputs,
                    TI_REAL const *options,
                    TI_REAL *const *outputs) //, char *const *char_outputs
{
  const TI_REAL *open = inputs[0];
  const TI_REAL *high = inputs[1];
  const TI_REAL *low = inputs[2];
  const TI_REAL *close = inputs[3];

  TI_REAL *dif = outputs[0];
  TI_REAL *atr_filter = outputs[1];
  TI_REAL *braid_color = outputs[2];

  const int ma01_length = (int)options[0];
  const int ma02_length = (int)options[1];
  const int ma03_length = (int)options[2];
  const int atr_length = (int)14;
  const double PipsMinSepPercent = (float)options[3];
  if (ma01_length < 1 || ma02_length < 1 || ma03_length < 1)
    return TI_INVALID_OPTION;

  double *max = (double *)calloc((unsigned long)size, sizeof(double));
  double *min = (double *)calloc((unsigned long)size, sizeof(double));

  const double ma01_options[] = {ma01_length};
  double *ma01 = (double *)calloc((unsigned long)size, sizeof(double));
  const double *ma01_inputs[] = {close};
  double *ma01_outputs[] = {ma01};
  int error2 = ti_ema(size, ma01_inputs, ma01_options, ma01_outputs);
  assert(error2 == TI_OKAY);

  const double ma02_options[] = {ma02_length};
  double *ma02 = (double *)calloc((unsigned long)size, sizeof(double));
  const double *ma02_inputs[] = {open};
  double *ma02_outputs[] = {ma02};
  int error3 = ti_ema(size, ma02_inputs, ma02_options, ma02_outputs);
  assert(error3 == TI_OKAY);

  const double ma03_options[] = {ma03_length};
  double *ma03 = (double *)calloc((unsigned long)size, sizeof(double));
  const double *ma03_inputs[] = {close};
  double *ma03_outputs[] = {ma03};
  int error4 = ti_ema(size, ma03_inputs, ma03_options, ma03_outputs);
  assert(error4 == TI_OKAY);

  // get atr data
  const double nz_atr_options[] = {atr_length};
  double *nz_atr = malloc((unsigned int)size * sizeof(double));
  assert(nz_atr != 0);
  const double *nz_atr_inputs[] = {high, low, close};
  double *nz_atr_outputs[] = {nz_atr};
  int error = ti_atr(size, nz_atr_inputs, nz_atr_options, nz_atr_outputs);
  assert(error == TI_OKAY);

  // refill the missing zero in atr
  double *atr = (double *)calloc((unsigned long)size, sizeof(double));
  const double *atr_inputs[] = {nz_atr};
  double *atr_outputs[] = {atr};
  int range = atr_length - 1;
  double value = 0;
  const double atr_options[] = {value, range};
  int error1 = ti_unshift(size, atr_inputs, atr_options, atr_outputs);
  assert(error1 == TI_OKAY);

  for (int i = 0; i < size; i++)
  {
    double temp_ma_arr[3] = {ma01[i], ma02[i], ma03[i]};
    max[i] = max_value(temp_ma_arr, 3);
    min[i] = min_value(temp_ma_arr, 3);
    dif[i] = max[i] - min[i];
    atr_filter[i] = atr[i] * PipsMinSepPercent / 100;
  }
  for (int i = 0; i < size; i++)
    if (ma01[i] > ma02[i] && dif[i] > atr_filter[i])
      braid_color[i] = TI_GREEN;
    else if (ma02[i] > ma01[i] && dif[i] > atr_filter[i])
      braid_color[i] = TI_RED;
    else
      braid_color[i] = TI_NOTHING;

  free(max);
  free(min);
  free(ma01);
  free(ma02);
  free(ma03);
  free(nz_atr);
  free(atr);

  return TI_OKAY;
}
