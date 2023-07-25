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

int ti_cm_ema_trendbars_start(TI_REAL const *options)
{
  UNUSED(options);
  return 0;
}

int ti_cm_ema_trendbars(int size, TI_REAL const *const *inputs,
                        TI_REAL const *options, TI_REAL *const *outputs)
{
  UNUSED(options);
  const TI_REAL *high = inputs[0];
  const TI_REAL *low = inputs[1];
  const TI_REAL *close = inputs[2];

  TI_REAL *usedema = outputs[0];
  TI_REAL *bar_color = outputs[1];

  const int ema_length = (int)options[0];
  if (ema_length < 1)
    return TI_INVALID_OPTION;

  double *hlc3 = (double *)calloc((size_t)size, sizeof(double));

  const double ema_options[] = {ema_length};
  const double *ema_inputs[] = {close};
  double *ema_outputs[] = {usedema};
  int error2 = ti_ema(size, ema_inputs, ema_options, ema_outputs);
  assert(error2 == TI_OKAY);

  const double hlc3_options[] = {0};
  const double *hlc3_inputs[] = {high, low, close};
  double *hlc3_outputs[] = {hlc3};
  int error3 = ti_hlc3(size, hlc3_inputs, hlc3_options, hlc3_outputs);
  assert(error3 == TI_OKAY);

  for (int i = 0; i < size; i++)
    if (hlc3[i] >= not_zero(usedema[i], (double)0))
      bar_color[i] = TI_BUY;
    else if (hlc3[i] < not_zero(usedema[i], (double)0))
      bar_color[i] = TI_SELL;
    else
      bar_color[i] = TI_NOTHING;

  free(hlc3);

  return TI_OKAY;
}
