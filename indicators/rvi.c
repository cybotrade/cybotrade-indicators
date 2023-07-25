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

int ti_rvi_start(TI_REAL const *options)
{
  UNUSED(options);
  return 0;
}

int ti_rvi(int size, TI_REAL const *const *inputs, TI_REAL const *options,
           TI_REAL *const *outputs)
{
  const TI_REAL *close = inputs[0];
  TI_REAL *rvi = outputs[0];
  const int std_length = (int)options[0];
  const int ema_length = (int)options[1];
  if (std_length < 1 || ema_length < 1)
    return TI_INVALID_OPTION;

  const double nz_std_options[] = {std_length};
  double *nz_std_data = (double *)calloc((size_t)size, sizeof(double));
  const double *nz_std_inputs[] = {close};
  double *nz_std_outputs[] = {nz_std_data};
  int error = ti_stddev(size, nz_std_inputs, nz_std_options, nz_std_outputs);
  assert(error == TI_OKAY);

  double *std = (double *)calloc((size_t)size, sizeof(double));
  const double *std_inputs[] = {nz_std_data};
  double *std_outputs[] = {std};
  int range = std_length - 1;
  double value = 0;
  const double std_options[] = {value, range};
  int error1 = ti_unshift(size, std_inputs, std_options, std_outputs);
  assert(error1 == TI_OKAY);

  double *diff = (double *)calloc((size_t)size, sizeof(double));
  double *upper_arr = (double *)calloc((size_t)size, sizeof(double));
  double *lower_arr = (double *)calloc((size_t)size, sizeof(double));

  for (int i = 1; i < size; i++)
    diff[i] = close[i] - close[i - 1];

  for (int i = 0; i < size; i++)
  {
    if (diff[i] <= 0)
      upper_arr[i] = 0;
    else
      upper_arr[i] = std[i];

    if (diff[i] > 0)
      lower_arr[i] = 0;
    else
      lower_arr[i] = std[i];
  }

  const double upper_options[] = {ema_length};
  double *upper = (double *)calloc((size_t)size, sizeof(double));
  const double *upper_inputs[] = {upper_arr};
  double *upper_outputs[] = {upper};
  int error2 = ti_ema(size, upper_inputs, upper_options, upper_outputs);
  assert(error2 == TI_OKAY);

  const double lower_options[] = {ema_length};
  double *lower = (double *)calloc((size_t)size, sizeof(double));
  const double *lower_inputs[] = {lower_arr};
  double *lower_outputs[] = {lower};
  int error3 = ti_ema(size, lower_inputs, lower_options, lower_outputs);
  assert(error3 == TI_OKAY);

  for (int i = 0; i < size; i++)
    rvi[i] = upper[i] / (upper[i] + lower[i]) * 100;

  free(nz_std_data);
  free(std);
  free(diff);
  free(upper_arr);
  free(lower_arr);
  free(upper);
  free(lower);

  return TI_OKAY;
}
