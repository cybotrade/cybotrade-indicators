/*
 * Tulip Indicators
 * https://tulipindicators.org/
 * Copyright (c) 2010-2018 Tulip Charts LLC
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
#include "dx.h"
#include "utils.h"

int ti_adx_start(TI_REAL const *options)
{
  UNUSED(options);
  return 0;
}

int ti_adx(int size, TI_REAL const *const *inputs, TI_REAL const *options,
           TI_REAL *const *outputs)
{
  const TI_REAL *high = inputs[0];
  const TI_REAL *low = inputs[1];

  const int period = (int)options[0];

  TI_REAL *output = outputs[0];

  if (period < 1)
    return TI_INVALID_OPTION;
  if (size <= ti_adx_start(options))
    return TI_OKAY;

  const double nz_DX_options[] = {period};
  double *nz_DX_data = (double *)calloc((unsigned long)size, sizeof(double));
  const double *nz_DX_inputs[] = {high, low};
  double *nz_DX_outputs[] = {nz_DX_data};
  int error = ti_dx(size, nz_DX_inputs, nz_DX_options, nz_DX_outputs);
  assert(error == TI_OKAY);

  double *DX = (double *)calloc((unsigned long)size, sizeof(double));
  const double *DX_inputs[] = {nz_DX_data};
  double *DX_outputs[] = {DX};
  int range = period - 1;
  double value = 0;
  const double DX_options[] = {value, range};
  int error1 = ti_unshift(size, DX_inputs, DX_options, DX_outputs);
  assert(error1 == TI_OKAY);

  const double nz_adx_options[] = {period};
  double *nz_adx_data = (double *)calloc((unsigned long)size, sizeof(double));
  const double *nz_adx_inputs[] = {DX};
  double *nz_adx_outputs[] = {nz_adx_data};
  int error2 = ti_sma(size, nz_adx_inputs, nz_adx_options, nz_adx_outputs);
  assert(error2 == TI_OKAY);

  const double *ADX_inputs[] = {nz_adx_data};
  double *ADX_outputs[] = {output};
  int range1 = period - 1;
  const double ADX_options[] = {value, range1};
  int error3 = ti_unshift(size, ADX_inputs, ADX_options, ADX_outputs);
  assert(error3 == TI_OKAY);

  free(nz_DX_data);
  free(DX);
  free(nz_adx_data);

  return TI_OKAY;
}
