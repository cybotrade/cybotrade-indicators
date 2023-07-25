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

int ti_andean_osc_start(TI_REAL const *options)
{
  UNUSED(options);
  return 0;
}

int ti_andean_osc(int size, TI_REAL const *const *inputs,
                  TI_REAL const *options, TI_REAL *const *outputs)
{
  const TI_REAL *open = inputs[0];
  const TI_REAL *close = inputs[1];

  TI_REAL *bull = outputs[0];
  TI_REAL *bear = outputs[1];
  TI_REAL *signal = outputs[2];

  const int period1 = (int)options[0];
  const int signal_length = (int)options[1];
  if (period1 < 1 || signal_length < 1)
    return TI_INVALID_OPTION;

  double alpha = (float)2 / (float)(period1 + 1);
  double *up1 = (double *)calloc((size_t)size, sizeof(double));
  double *up2 = (double *)calloc((size_t)size, sizeof(double));
  double *dn1 = (double *)calloc((size_t)size, sizeof(double));
  double *dn2 = (double *)calloc((size_t)size, sizeof(double));
  double *max_data = (double *)calloc((size_t)size, sizeof(double));

  for (int i = 1; i < size; i++)
  {
    double double_close = close[i] * close[i];
    double double_open = open[i] * open[i];

    double temp_up1 = up1[i - 1] - ((up1[i - 1] - close[i]) * alpha);
    double temp_arr_up1[3] = {close[i], open[i], temp_up1};
    double max_value1 = max_value(temp_arr_up1, 3);
    up1[i] = isnan(max_value1) ? close[i] : max_value1;

    double temp_up2 = (up2[i - 1] - ((up2[i - 1] - double_close) * alpha));
    double temp_arr_up2[3] = {double_close, double_open, temp_up2};
    double max_value2 = max_value(temp_arr_up2, 3);
    up2[i] = isnan(max_value2) ? double_close : max_value2;

    double temp_dn1 = dn1[i - 1] + ((close[i] - dn1[i - 1]) * alpha);
    double temp_arr_dn1[3] = {close[i], open[i], temp_dn1};
    double min_value3 = min_value(temp_arr_dn1, 3);
    dn1[i] = isnan(min_value3) ? close[i] : min_value3;

    double temp_dn2 = dn2[i - 1] + ((double_close - dn2[i - 1]) * alpha);
    double temp_arr_dn2[3] = {double_close, double_open, temp_dn2};
    double min_value4 = min_value(temp_arr_dn2, 3);
    dn2[i] = isnan(min_value4) ? double_close : min_value4;
  }

  for (int i = 0; i < size; i++)
  {
    bull[i] = sqrt(dn2[i] - (dn1[i] * dn1[i]));
    bear[i] = sqrt(up2[i] - (up1[i] * up1[i]));
  }

  for (int i = 0; i < size; i++)
    max_data[i] = fmax(bull[i], bear[i]);

  const double signal_options[] = {signal_length};
  const double *signal_inputs[] = {max_data};
  double *signal_outputs[] = {signal};
  int error2 = ti_ema(size, signal_inputs, signal_options, signal_outputs);
  assert(error2 == TI_OKAY);

  free(up1);
  free(up2);
  free(dn1);
  free(dn2);
  free(max_data);

  return TI_OKAY;
}
