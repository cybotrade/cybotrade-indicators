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

int ti_supertrend_start(TI_REAL const *options)
{
  UNUSED(options);
  return 0;
}

int ti_supertrend(int size, TI_REAL const *const *inputs,
                  TI_REAL const *options, TI_REAL *const *outputs)
{
  const TI_REAL *high = inputs[0];
  const TI_REAL *low = inputs[1];
  const TI_REAL *close = inputs[2];
  TI_REAL *superTrend = outputs[0];
  TI_REAL *direction = outputs[1];
  double *color = outputs[2];
  double *signal = outputs[3];

  const int period = (int)options[0];
  const TI_REAL factor = options[1];
  if (period < 1)
    return TI_INVALID_OPTION;

  for (int i = 0; i < size; i++)
  {
    superTrend[i] = 0;
    direction[i] = 0;
    color[i] = 0;
    signal[i] = 0;
  }
  // get atr data
  const double nz_atr_options[] = {options[0]};
  double *nz_atr = malloc((unsigned int)size * sizeof(double));
  assert(nz_atr != 0);
  const double *nz_atr_inputs[] = {high, low, close};
  double *nz_atr_outputs[] = {nz_atr};
  int error = ti_atr(size, nz_atr_inputs, nz_atr_options, nz_atr_outputs);
  assert(error == TI_OKAY);

  // refill the missing zero in atr
  double *atr = (double *)calloc((size_t)size, sizeof(double));
  const double *atr_inputs[] = {nz_atr};
  double *atr_outputs[] = {atr};
  int range = period - 1;
  double value = 0;
  const double atr_options[] = {value, range};
  int error1 = ti_unshift(size, atr_inputs, atr_options, atr_outputs);
  assert(error1 == TI_OKAY);

  double *upperBand = (double *)calloc((size_t)size, sizeof(double));
  double *lowerBand = (double *)calloc((size_t)size, sizeof(double));
  for (int i = 0; i < size; i++)
  {
    upperBand[i] = ((high[i] + low[i]) / 2) + (factor * atr[i]);
    lowerBand[i] = ((high[i] + low[i]) / 2) - (factor * atr[i]);
  }
  for (int j = 1; j < size; j++)
  {
    if (lowerBand[j] > lowerBand[j - 1] || close[j - 1] < lowerBand[j - 1])
      lowerBand[j] = lowerBand[j];
    else
      lowerBand[j] = lowerBand[j - 1];

    if (upperBand[j] < upperBand[j - 1] || close[j - 1] > upperBand[j - 1])
      upperBand[j] = upperBand[j];
    else
      upperBand[j] = upperBand[j - 1];
  }
  for (int i = 1; i < size; i++)
  {
    if (superTrend[i - 1] == upperBand[i - 1])
    {
      if (close[i] > upperBand[i])
        direction[i] = -1;
      else
        direction[i] = 1;
    }
    else
    {
      if (close[i] < lowerBand[i])
        direction[i] = 1;
      else
        direction[i] = -1;
    }
    if (direction[i] == -1)
      superTrend[i] = lowerBand[i];
    else
      superTrend[i] = upperBand[i];

    signal[0] = TI_NOTHING;
  }

  for (int i = 1; i < size; i++)
    if (direction[i] == 1 && direction[i - 1] == -1)
      signal[i] = TI_SELL;
    else if (direction[i] == -1 && direction[i - 1] == 1)
      signal[i] = TI_BUY;
    else
      signal[i] = TI_NOTHING;

  for (int i = 0; i < size; i++)
    if (direction[i] == -1)
      color[i] = TI_GREEN;
    else
      color[i] = TI_RED;

  free(nz_atr);
  free(atr);
  free(upperBand);
  free(lowerBand);

  return TI_OKAY;
}
