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

int ti_chandelier_exit_start(TI_REAL const *options)
{
  UNUSED(options);
  return 0;
}

int ti_chandelier_exit(int size, TI_REAL const *const *inputs,
                       TI_REAL const *options, TI_REAL *const *outputs)
{
  const TI_REAL *high = inputs[0];
  const TI_REAL *low = inputs[1];
  const TI_REAL *close = inputs[2];
  TI_REAL *ce_signal = outputs[0];
  const int period = (int)options[0];
  const double atr_multiplier = (double)options[1];
  if (period < 1)
    return TI_INVALID_OPTION;

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

  double *longstop_new = (double *)calloc((size_t)size, sizeof(double));
  double *shortstop_new = (double *)calloc((size_t)size, sizeof(double));
  double *direc = (double *)calloc((size_t)size, sizeof(double));
  double *longstop = (double *)calloc((size_t)size, sizeof(double));
  double *shortstop = (double *)calloc((size_t)size, sizeof(double));

  for (int i = 0; i < size; i++)
    ce_signal[i] = TI_NOTHING;

  for (int i = 0; i < size; i++)
  {
    longstop[i] = high[i] - (atr_multiplier * atr[i]);
    shortstop[i] = low[i] + (atr_multiplier * atr[i]);
  }
  for (int i = 1; i < size; i++)
  {
    if (close[i - 1] > longstop_new[i - 1])
      longstop_new[i] = fmax(longstop[i], longstop_new[i - 1]);
    else
      longstop_new[i] = longstop[i];

    if (close[i - 1] < shortstop_new[i - 1])
      shortstop_new[i] = fmin(shortstop[i], shortstop_new[i - 1]);
    else
      shortstop_new[i] = shortstop[i];
  }

  for (int i = 1; i < size; i++)
  {
    if (close[i] > shortstop_new[i - 1])
      direc[i] = 1;
    else if (close[i] < longstop_new[i - 1])
      direc[i] = -1;
    else
      direc[i] = direc[i - 1];
  }

  for (int i = 1; i < size; i++)
  {
    if (direc[i] == 1 && direc[i - 1] == -1)
      ce_signal[i] = TI_BUY;
    else if (direc[i] == -1 && direc[i - 1] == 1)
      ce_signal[i] = TI_SELL;
    else
      ce_signal[i] = TI_NOTHING;
  }

  free(nz_atr);
  free(atr);
  free(longstop_new);
  free(shortstop_new);
  free(direc);
  free(longstop);
  free(shortstop);

  return TI_OKAY;
}
