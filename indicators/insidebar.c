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

int ti_insidebar_start(TI_REAL const *options)
{
  UNUSED(options);
  return 0;
}

int ti_insidebar(int size, TI_REAL const *const *inputs, TI_REAL const *options,
                 TI_REAL *const *outputs)
{
  UNUSED(options);
  const TI_REAL *open = inputs[0];
  const TI_REAL *high = inputs[1];
  const TI_REAL *low = inputs[2];
  const TI_REAL *close = inputs[3];

  double *bar_color = outputs[0];

  double *bodyStatus = (double *)calloc((size_t)size, sizeof(double));
  double *isInsidePattern = (double *)calloc((size_t)size, sizeof(double));
  int bullishBar = 1;
  int bearishBar = -1;

  for (int i = 0; i < size; i++)
    if (close[i] >= open[i])
      bodyStatus[i] = bullishBar;
    else
      bodyStatus[i] = bearishBar;

  for (int i = 1; i < size; i++)
    if (high[i] < high[i - 1] && low[i] > low[i - 1])
      isInsidePattern[i] = bodyStatus[i];
    else
      isInsidePattern[i] = 0;

  for (int i = 0; i < size; i++)
    if (isInsidePattern[i] == 1)
      bar_color[i] = TI_BUY;
    else if (isInsidePattern[i] == -1)
      bar_color[i] = TI_SELL;
    else
      bar_color[i] = TI_NOTHING;

  free(bodyStatus);
  free(isInsidePattern);

  return TI_OKAY;
}
