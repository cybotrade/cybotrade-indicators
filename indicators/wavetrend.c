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

int ti_wavetrend_start(TI_REAL const *options)
{
  UNUSED(options);
  return 0;
}

int ti_wavetrend(int size, TI_REAL const *const *inputs, TI_REAL const *options,
                 TI_REAL *const *outputs)
{
  const TI_REAL *high = inputs[0];
  const TI_REAL *low = inputs[1];
  const TI_REAL *close = inputs[2];
  TI_REAL *wt1 = outputs[0];
  TI_REAL *wt2 = outputs[1];
  const int period1 = (int)options[0];
  const int period2 = (int)options[1];
  if (period1 < 1 || period2 < 1)
    return TI_INVALID_OPTION;

  // get hlc3 data
  const double hlc3_options[] = {0};
  double *hlc3 = malloc((size_t)size * sizeof(double));
  assert(hlc3 != 0);
  const double *hlc3_inputs[] = {high, low, close};
  double *hlc3_outputs[] = {hlc3};
  int error = ti_hlc3(size, hlc3_inputs, hlc3_options, hlc3_outputs);
  assert(error == TI_OKAY);

  const double esa_options[] = {period1};
  double *esa = (double *)calloc((size_t)size, sizeof(double));
  const double *esa_inputs[] = {hlc3};
  double *esa_outputs[] = {esa};
  int error1 = ti_ema(size, esa_inputs, esa_options, esa_outputs);
  assert(error1 == TI_OKAY);
  double *d1_data = (double *)calloc((size_t)size, sizeof(double));
  for (int i = 0; i < size; i++)
  {
    d1_data[i] = fabs(hlc3[i] - esa[i]);
  }

  const double d1_options[] = {period1};
  double *d1 = (double *)calloc((size_t)size, sizeof(double));
  const double *d1_inputs[] = {d1_data};
  double *d1_outputs[] = {d1};
  int error2 = ti_ema(size, d1_inputs, d1_options, d1_outputs);
  assert(error2 == TI_OKAY);

  double *ci_data = (double *)calloc((size_t)size, sizeof(double));
  for (int i = 0; i < size; i++)
  {
    double ci_data1 = (hlc3[i] - esa[i]) / (0.015 * d1[i]);
    double ci_data2 = isnan(ci_data1) ? 0 : ci_data1;
    ci_data[i] = ci_data2;
  }

  const double wt1_options[] = {period2};
  const double *wt1_inputs[] = {ci_data};
  double *wt1_outputs[] = {wt1};
  int error3 = ti_ema(size, wt1_inputs, wt1_options, wt1_outputs);
  assert(error3 == TI_OKAY);

  double *wt2_data = (double *)calloc((size_t)size, sizeof(double));
  const double wt2_options[] = {4};
  const double *wt2_inputs[] = {wt1};
  double *wt2_outputs[] = {wt2_data};
  int error4 = ti_sma(size, wt2_inputs, wt2_options, wt2_outputs);
  assert(error4 == TI_OKAY);

  const double *wt2_data_inputs[] = {wt2_data};
  double *wt2_data_outputs[] = {wt2};
  int range = 4 - 1;
  double value = 0;
  const double unshift_options[] = {value, range};
  int error5 =
      ti_unshift(size, wt2_data_inputs, unshift_options, wt2_data_outputs);
  assert(error5 == TI_OKAY);

  free(hlc3);
  free(esa);
  free(d1_data);
  free(d1);
  free(ci_data);
  free(wt2_data);

  return TI_OKAY;
}
