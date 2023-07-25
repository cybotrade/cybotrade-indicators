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

int ti_half_trend_start(TI_REAL const *options)
{
  UNUSED(options);
  return 0;
}

int ti_half_trend(int size, TI_REAL const *const *inputs,
                  TI_REAL const *options, TI_REAL *const *outputs)
{
  const TI_REAL *high = inputs[0];
  const TI_REAL *low = inputs[1];
  const TI_REAL *close = inputs[2];

  double *ht = outputs[0];
  double *ht_color = outputs[1];

  const int amplitude = (int)options[0];
  const double channelDeviation = (double)options[1];
  const int atr_length = (int)options[2];

  if (amplitude < 0 || channelDeviation < 0)
    return TI_INVALID_OPTION;

  const double nz_atr_options[] = {atr_length};
  double *nz_atr = malloc((unsigned int)size * sizeof(double));
  assert(nz_atr != 0);
  const double *nz_atr_inputs[] = {high, low, close};
  double *nz_atr_outputs[] = {nz_atr};
  int error = ti_atr(size, nz_atr_inputs, nz_atr_options, nz_atr_outputs);
  assert(error == TI_OKAY);

  double *atr = (double *)calloc((size_t)size, sizeof(double));
  const double *atr_inputs[] = {nz_atr};
  double *atr_outputs[] = {atr};
  int range1 = atr_length - 1;
  double value1 = 0;
  const double atr_options[] = {value1, range1};
  int error1 = ti_unshift(size, atr_inputs, atr_options, atr_outputs);
  assert(error1 == TI_OKAY);

  double *dev = (double *)calloc((size_t)size, sizeof(double));
  for (int i = 0; i < size; i++)
    dev[i] = (float)atr[i] / 2 * channelDeviation;

  const double nz_highma_options[] = {amplitude};
  double *nz_highma = (double *)calloc((size_t)size, sizeof(double));
  const double *nz_highma_inputs[] = {high};
  double *nz_highma_outputs[] = {nz_highma};
  int error9 =
      ti_sma(size, nz_highma_inputs, nz_highma_options, nz_highma_outputs);
  assert(error9 == TI_OKAY);

  double *highma = (double *)calloc((size_t)size, sizeof(double));
  const double *highma_inputs[] = {nz_highma};
  double *highma_outputs[] = {highma};
  int range10 = amplitude - 1;
  double value10 = 0;
  const double highma_options[] = {value10, range10};
  int error10 = ti_unshift(size, highma_inputs, highma_options, highma_outputs);
  assert(error10 == TI_OKAY);

  const double nz_lowma_options[] = {amplitude};
  double *nz_lowma = (double *)calloc((size_t)size, sizeof(double));
  const double *nz_lowma_inputs[] = {low};
  double *nz_lowma_outputs[] = {nz_lowma};
  int error8 =
      ti_sma(size, nz_lowma_inputs, nz_lowma_options, nz_lowma_outputs);
  assert(error8 == TI_OKAY);

  double *lowma = (double *)calloc((size_t)size, sizeof(double));
  const double *lowma_inputs[] = {nz_lowma};
  double *lowma_outputs[] = {lowma};
  int range101 = amplitude - 1;
  double value101 = 0;
  const double lowma_options[] = {value101, range101};
  int error101 = ti_unshift(size, lowma_inputs, lowma_options, lowma_outputs);
  assert(error101 == TI_OKAY);

  double *trend = (double *)calloc((size_t)size, sizeof(double));
  double *nextTrend = (double *)calloc((size_t)size, sizeof(double));
  double *maxLowPrice = (double *)calloc((size_t)size, sizeof(double));
  double *minHighPrice = (double *)calloc((size_t)size, sizeof(double));
  double *up = (double *)calloc((size_t)size, sizeof(double));
  double *down = (double *)calloc((size_t)size, sizeof(double));
  double *atrHigh = (double *)calloc((size_t)size, sizeof(double));
  double *atrLow = (double *)calloc((size_t)size, sizeof(double));

  maxLowPrice[0] = low[0];
  minHighPrice[0] = high[0];

  const double nz_highPrice_options[] = {amplitude};
  double *nz_highPrice = malloc((unsigned int)size * sizeof(double));
  assert(nz_highPrice != 0);
  const double *nz_highPrice_inputs[] = {high};
  double *nz_highPrice_outputs[] = {nz_highPrice};
  int error44 = ti_max(size, nz_highPrice_inputs, nz_highPrice_options,
                       nz_highPrice_outputs);
  assert(error44 == TI_OKAY);

  double *highPrice = (double *)calloc((size_t)size, sizeof(double));
  const double *highPrice_inputs[] = {nz_highPrice};
  double *highPrice_outputs[] = {highPrice};
  int range16 = amplitude - 1;
  double value16 = 0;
  const double highPrice_options[] = {value16, range16};
  int error56 =
      ti_unshift(size, highPrice_inputs, highPrice_options, highPrice_outputs);
  assert(error56 == TI_OKAY);

  const double nz_lowPrice_options[] = {amplitude};
  double *nz_lowPrice = malloc((unsigned int)size * sizeof(double));
  assert(nz_lowPrice != 0);
  const double *nz_lowPrice_inputs[] = {low};
  double *nz_lowPrice_outputs[] = {nz_lowPrice};
  int error66 = ti_min(size, nz_lowPrice_inputs, nz_lowPrice_options,
                       nz_lowPrice_outputs);
  assert(error66 == TI_OKAY);

  double *lowPrice = (double *)calloc((size_t)size, sizeof(double));
  const double *lowPrice_inputs[] = {nz_lowPrice};
  double *lowPrice_outputs[] = {lowPrice};
  int range33 = amplitude - 1;
  double value33 = 0;
  const double lowPrice_options[] = {value33, range33};
  int error73 =
      ti_unshift(size, lowPrice_inputs, lowPrice_options, lowPrice_outputs);
  assert(error73 == TI_OKAY);

  for (int i = 1; i < size; i++)
  {
    if (nextTrend[i - 1] == 1)
    {
      maxLowPrice[i] = fmax(lowPrice[i], maxLowPrice[i - 1]);
      if (highma[i] < maxLowPrice[i] &&
          close[i] < not_zero(low[i - 1], low[i]))
      {
        trend[i] = 1;
        nextTrend[i] = 0;
        minHighPrice[i] = highPrice[i];
      }
      else
      {
        trend[i] = trend[i - 1];
        nextTrend[i] = nextTrend[i - 1];
        minHighPrice[i] = minHighPrice[i - 1];
      }
    }
    else
    {
      minHighPrice[i] = fmin(highPrice[i], minHighPrice[i - 1]);
      if (lowma[i] > minHighPrice[i] &&
          close[i] > not_zero(high[i - 1], high[i]))
      {
        trend[i] = 0;
        nextTrend[i] = 1;
        maxLowPrice[i] = lowPrice[i];
      }
      else
      {
        trend[i] = trend[i - 1];
        nextTrend[i] = nextTrend[i - 1];
        maxLowPrice[i] = maxLowPrice[i - 1];
      }
    }
    if (trend[i] == 0)
    {
      if (trend[i - 1] != 0)
        up[i] = down[i - 1];
      else
        up[i] = fmax(maxLowPrice[i], up[i - 1]);
      atrHigh[i] = up[i] + dev[i];
      atrLow[i] = up[i] - dev[i];
    }
    else
    {
      if (trend[i - 1] != 1)
        down[i] = up[i - 1];
      else
        down[i] = fmin(minHighPrice[i], down[i - 1]);
      atrHigh[i] = down[i] + dev[i];
      atrLow[i] = down[i] - dev[i];
    }
  }

  for (int i = 0; i < size; i++)
  {
    if (trend == 0)
    {
      ht[i] = up[i];
      ht_color[i] = TI_GREEN;
    }
    else
    {
      ht[i] = down[i];
      ht_color[i] = TI_RED;
    }
  }

  free(nz_atr);
  free(atr);
  free(dev);
  free(nz_highma);
  free(highma);
  free(nz_lowma);
  free(lowma);
  free(trend);
  free(nextTrend);
  free(maxLowPrice);
  free(minHighPrice);
  free(up);
  free(down);
  free(atrHigh);
  free(atrLow);
  free(nz_highPrice);
  free(highPrice);
  free(nz_lowPrice);
  free(lowPrice);

  return TI_OKAY;
}
