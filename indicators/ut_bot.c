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

int ti_ut_bot_start(TI_REAL const *options)
{
  UNUSED(options);
  return 0;
}

int ti_ut_bot(int size, TI_REAL const *const *inputs, TI_REAL const *options,
              TI_REAL *const *outputs)
{
  const TI_REAL *high = inputs[0];
  const TI_REAL *low = inputs[1];
  const TI_REAL *close = inputs[2];

  double *signal = outputs[0];

  const int atr_period = (int)options[0];
  const double sensitivity = (double)options[1];

  if (atr_period < 1 || sensitivity < 0)
    return TI_INVALID_OPTION;

  const double nz_xATR_options[] = {atr_period};
  double *nz_xATR = malloc((unsigned int)size * sizeof(double));
  assert(nz_xATR != 0);
  const double *nz_xATR_inputs[] = {high, low, close};
  double *nz_xATR_outputs[] = {nz_xATR};
  int error = ti_atr(size, nz_xATR_inputs, nz_xATR_options, nz_xATR_outputs);
  assert(error == TI_OKAY);

  double *xATR = (double *)calloc((size_t)size, sizeof(double));
  const double *xATR_inputs[] = {nz_xATR};
  double *xATR_outputs[] = {xATR};
  int range1 = atr_period - 1;
  double value1 = 0;
  const double xATR_options[] = {value1, range1};
  int error1 = ti_unshift(size, xATR_inputs, xATR_options, xATR_outputs);
  assert(error1 == TI_OKAY);

  for (int i = 0; i < size; i++)
    xATR[i] = xATR[i] * sensitivity;

  double *xATRTrailingStop = (double *)calloc((size_t)size, sizeof(double));

  double *ema = (double *)calloc((size_t)size, sizeof(double));
  const double ema_options[] = {1};
  const double *ema_inputs[] = {close};
  double *ema_outputs[] = {ema};
  int error2 = ti_ema(size, ema_inputs, ema_options, ema_outputs);
  assert(error2 == TI_OKAY);

  for (int i = 1; i < size; i++)
  {
    if (close[i] > not_zero(xATRTrailingStop[i - 1], 0) &&
        close[i - 1] > not_zero(xATRTrailingStop[i - 1], 0))
      xATRTrailingStop[i] =
          fmax(not_zero(xATRTrailingStop[i - 1], 0), close[i] - xATR[i]);
    else if (close[i] < not_zero(xATRTrailingStop[i - 1], 0) &&
             close[i - 1] < not_zero(xATRTrailingStop[i - 1], 0))
      xATRTrailingStop[i] =
          fmin(not_zero(xATRTrailingStop[i - 1], 0), close[i] + xATR[i]);
    else if (close[i] > not_zero(xATRTrailingStop[i - 1], 0))
      xATRTrailingStop[i] = close[i] - xATR[i];
    else
      xATRTrailingStop[i] = close[i] + xATR[i];
  }

  const double nz_above_options[] = {0};
  double *nz_above = (double *)calloc((size_t)size, sizeof(double));
  const double *nz_above_inputs[] = {ema, xATRTrailingStop};
  double *nz_above_outputs[] = {nz_above};
  int error9 =
      ti_crossover(size, nz_above_inputs, nz_above_options, nz_above_outputs);
  assert(error9 == TI_OKAY);

  double *above = (double *)calloc((size_t)size, sizeof(double));
  const double *above_inputs[] = {nz_above};
  double *above_outputs[] = {above};
  int range10 = 1;
  double value10 = 0;
  const double above_options[] = {value10, range10};
  int error10 = ti_unshift(size, above_inputs, above_options, above_outputs);
  assert(error10 == TI_OKAY);

  const double nz_below_options[] = {0};
  double *nz_below = (double *)calloc((size_t)size, sizeof(double));
  const double *nz_below_inputs[] = {xATRTrailingStop, ema};
  double *nz_below_outputs[] = {nz_below};
  int error8 =
      ti_crossover(size, nz_below_inputs, nz_below_options, nz_below_outputs);
  assert(error8 == TI_OKAY);

  double *below = (double *)calloc((size_t)size, sizeof(double));
  const double *below_inputs[] = {nz_below};
  double *below_outputs[] = {below};
  int range101 = 1;
  double value101 = 0;
  const double below_options[] = {value101, range101};
  int error101 = ti_unshift(size, below_inputs, below_options, below_outputs);
  assert(error101 == TI_OKAY);

  for (int i = 0; i < size; i++)
  {
    if (close[i] > xATRTrailingStop[i] && above[i] == 1)
      signal[i] = TI_BUY;
    else if (close[i] < xATRTrailingStop[i] && below[i] == 1)
      signal[i] = TI_SELL;
    else
      signal[i] = TI_NOTHING;
  }

  // Free all the memory allocated in this function call
  free(below);
  free(nz_below);
  free(above);
  free(nz_above);
  free(ema);
  free(xATR);
  free(xATRTrailingStop);
  free(nz_xATR);

  return TI_OKAY;
}
