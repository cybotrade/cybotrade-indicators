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

int ti_volatility_oscillator_start(TI_REAL const *options)
{
  UNUSED(options);
  return 0;
}

int ti_volatility_oscillator(int size, TI_REAL const *const *inputs,
                             TI_REAL const *options, TI_REAL *const *outputs)
{
  const TI_REAL *open = inputs[0];
  const TI_REAL *close = inputs[1];
  TI_REAL *spike = outputs[0];
  TI_REAL *upper_line = outputs[1];
  TI_REAL *lower_line = outputs[2];

  const int length = (int)options[0];

  if (length < 1)
    return TI_INVALID_OPTION;

  double *nz_lower = (double *)calloc((size_t)size, sizeof(double));
  double *nz_upper = (double *)calloc((size_t)size, sizeof(double));

  for (int i = 0; i < size; i++)
  {
    spike[i] = close[i] - open[i];
  }

  const double nz_upper_options[] = {length};
  const double *nz_upper_inputs[] = {spike};
  double *nz_upper_outputs[] = {nz_upper};
  int error =
      ti_stddev(size, nz_upper_inputs, nz_upper_options, nz_upper_outputs);
  assert(error == TI_OKAY);

  const double *upper_inputs[] = {nz_upper};
  double *upper_outputs[] = {upper_line};
  int range = length - 1;
  double value = 0;
  const double upper_options[] = {value, range};
  int error1 = ti_unshift(size, upper_inputs, upper_options, upper_outputs);
  assert(error1 == TI_OKAY);

  const double nz_lower_options[] = {length};
  const double *nz_lower_inputs[] = {spike};
  double *nz_lower_outputs[] = {nz_lower};
  int error3 =
      ti_stddev(size, nz_lower_inputs, nz_lower_options, nz_lower_outputs);
  assert(error3 == TI_OKAY);

  const double *lower_inputs[] = {nz_lower};
  double *lower_outputs[] = {lower_line};
  int range1 = length - 1;
  double value1 = 0;
  const double lower_options[] = {value1, range1};
  int error2 = ti_unshift(size, lower_inputs, lower_options, lower_outputs);
  assert(error2 == TI_OKAY);

  for (int i = 0; i < size; i++)
  {
    lower_line[i] = lower_line[i] * -1;
  }

  free(nz_lower);
  free(nz_upper);

  return TI_OKAY;
}
