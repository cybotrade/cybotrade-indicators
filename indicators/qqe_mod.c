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

int ti_qqe_mod_start(TI_REAL const *options)
{
  UNUSED(options);
  return 0;
}

int ti_qqe_mod(int size, TI_REAL const *const *inputs, TI_REAL const *options,
               TI_REAL *const *outputs)
{
  const TI_REAL *close = inputs[0];
  double *qqeGreenbar = outputs[0];
  double *qqeRedbar = outputs[1];

  const int rsi_length1 = (int)options[0];
  const int rsi_smoothing1 = (int)options[1];
  const double QQE_factor1 = (double)options[2];
  const double threshold1 = (double)options[3];
  const int rsi_length2 = (int)options[4];
  const int rsi_smoothing2 = (int)options[5];
  const double QQE_factor2 = (double)options[6];
  const double threshold2 = (double)options[7];
  const int bollinger_length = (int)options[8];
  const double QQE_multiplier = (double)options[9];

  if (rsi_length1 < 1 || rsi_smoothing1 < 1 || rsi_length2 < 1 ||
      rsi_smoothing2 < 1 || QQE_factor1 < 1 || threshold1 < 1 ||
      QQE_factor2 < 1 || threshold2 < 1 || bollinger_length < 1 ||
      QQE_multiplier < 0)
    return TI_INVALID_OPTION;

  double Wilders_Period1 = rsi_length1 * 2 - 1;
  // double Wilders_Period2 = rsi_length2 * 2 - 1;

  const double nz_rsi1_options[] = {rsi_length1};
  double *nz_rsi1 = malloc((unsigned int)size * sizeof(double));
  assert(nz_rsi1 != 0);
  const double *nz_rsi1_inputs[] = {close};
  double *nz_rsi1_outputs[] = {nz_rsi1};
  int error = ti_rsi(size, nz_rsi1_inputs, nz_rsi1_options, nz_rsi1_outputs);
  assert(error == TI_OKAY);

  double *rsi1 = malloc((unsigned int)size * sizeof(double));
  const double *rsi1_inputs[] = {nz_rsi1};
  double *rsi1_outputs[] = {rsi1};
  int range = rsi_length1;
  double value = 0;
  const double rsi1_options[] = {value, range};
  int error1 = ti_unshift(size, rsi1_inputs, rsi1_options, rsi1_outputs);
  assert(error1 == TI_OKAY);

  const double nz_rsi2_options[] = {rsi_length2};
  double *nz_rsi2 = malloc((unsigned int)size * sizeof(double));
  assert(nz_rsi2 != 0);
  const double *nz_rsi2_inputs[] = {close};
  double *nz_rsi2_outputs[] = {nz_rsi2};
  int error2 = ti_rsi(size, nz_rsi2_inputs, nz_rsi2_options, nz_rsi2_outputs);
  assert(error2 == TI_OKAY);

  double *rsi2 = malloc((unsigned int)size * sizeof(double));
  const double *rsi2_inputs[] = {nz_rsi2};
  double *rsi2_outputs[] = {rsi2};
  int range1 = rsi_length2;
  double value1 = 0;
  const double rsi2_options[] = {value1, range1};
  int error3 = ti_unshift(size, rsi2_inputs, rsi2_options, rsi2_outputs);
  assert(error3 == TI_OKAY);

  const double rsima1_options[] = {rsi_smoothing1};
  double *rsima1 = malloc((unsigned int)size * sizeof(double));
  assert(rsima1 != 0);
  const double *rsima1_inputs[] = {rsi1};
  double *rsima1_outputs[] = {rsima1};
  int error4 = ti_ema(size, rsima1_inputs, rsima1_options, rsima1_outputs);
  assert(error4 == TI_OKAY);

  const double rsima2_options[] = {rsi_smoothing2};
  double *rsima2 = malloc((unsigned int)size * sizeof(double));
  assert(rsima2 != 0);
  const double *rsima2_inputs[] = {rsi2};
  double *rsima2_outputs[] = {rsima2};
  int error5 = ti_ema(size, rsima2_inputs, rsima2_options, rsima2_outputs);
  assert(error5 == TI_OKAY);

  double *atr_rsi1 = (double *)calloc((size_t)size, sizeof(double));
  for (int i = 1; i < size; i++)
  {
    atr_rsi1[i] = fabs(rsima1[i] - rsima1[i - 1]);
  }

  const double Ma_atrRsi1_options[] = {Wilders_Period1};
  double *Ma_atrRsi1 = malloc((unsigned int)size * sizeof(double));
  assert(Ma_atrRsi1 != 0);
  const double *Ma_atrRsi1_inputs[] = {atr_rsi1};
  double *Ma_atrRsi1_outputs[] = {Ma_atrRsi1};
  int error6 =
      ti_ema(size, Ma_atrRsi1_inputs, Ma_atrRsi1_options, Ma_atrRsi1_outputs);
  assert(error6 == TI_OKAY);

  const double dar1_options[] = {Wilders_Period1};
  double *dar1 = malloc((unsigned int)size * sizeof(double));
  assert(dar1 != 0);
  const double *dar1_inputs[] = {Ma_atrRsi1};
  double *dar1_outputs[] = {dar1};
  int error7 = ti_ema(size, dar1_inputs, dar1_options, dar1_outputs);
  assert(error7 == TI_OKAY);

  double *newshortband = (double *)calloc((size_t)size, sizeof(double));
  double *newlongband = (double *)calloc((size_t)size, sizeof(double));
  double *longband = (double *)calloc((size_t)size, sizeof(double));
  double *shortband = (double *)calloc((size_t)size, sizeof(double));
  double *trend = (double *)calloc((size_t)size, sizeof(double));
  double *FastAtrRsiTL = (double *)calloc((size_t)size, sizeof(double));
  double *upper = (double *)calloc((size_t)size, sizeof(double));
  double *lower = (double *)calloc((size_t)size, sizeof(double));

  for (int i = 0; i < size; i++)
  {
    newlongband[i] = rsima1[i] - dar1[i] * QQE_factor1;
    newshortband[i] = rsima1[i] + dar1[i] * QQE_factor1;
  }
  for (int i = 1; i < size; i++)
  {
    if (rsima1[i - 1] > longband[i - 1] && rsima1[i] > longband[i - 1])
    {
      longband[i] = fmax(longband[i - 1], newlongband[i]);
    }
    else
    {
      longband[i] = newlongband[i];
    }
    if (rsima1[i - 1] < shortband[i - 1] && rsima1[i] < shortband[i - 1])
    {
      shortband[i] = fmin(shortband[i - 1], newshortband[i]);
    }
    else
    {
      shortband[i] = newshortband[i];
    }
  }

  double *longband_prev = (double *)calloc((size_t)size, sizeof(double));
  double *shortband_prev = (double *)calloc((size_t)size, sizeof(double));
  for (int i = 1; i < size; i++)
  {
    longband_prev[i] = longband[i - 1];
    shortband_prev[i] = shortband[i - 1];
  }

  const double nz_cross_1_options[] = {0};
  double *nz_cross_1 = (double *)calloc((size_t)size, sizeof(double));
  const double *nz_cross_1_inputs[] = {longband_prev, rsima1};
  double *nz_cross_1_outputs[] = {nz_cross_1};
  int error9 = ti_crossany(size, nz_cross_1_inputs, nz_cross_1_options,
                           nz_cross_1_outputs);
  assert(error9 == TI_OKAY);

  double *cross_1 = (double *)calloc((size_t)size, sizeof(double));
  const double *cross_1_inputs[] = {nz_cross_1};
  double *cross_1_outputs[] = {cross_1};
  int range101 = 1;
  double value101 = 0;
  const double cross1_options[] = {value101, range101};
  int error101 =
      ti_unshift(size, cross_1_inputs, cross1_options, cross_1_outputs);
  assert(error101 == TI_OKAY);

  const double nz_cross_2_options[] = {0};
  double *nz_cross_2 = (double *)calloc((size_t)size, sizeof(double));
  const double *nz_cross_2_inputs[] = {rsima1, shortband_prev};
  double *nz_cross_2_outputs[] = {nz_cross_2};
  int error8 = ti_crossany(size, nz_cross_2_inputs, nz_cross_2_options,
                           nz_cross_2_outputs);
  assert(error8 == TI_OKAY);

  double *cross_2 = (double *)calloc((size_t)size, sizeof(double));
  const double *cross_2_inputs[] = {nz_cross_2};
  double *cross_2_outputs[] = {cross_2};
  int range105 = 1;
  double value105 = 0;
  const double cross2_options[] = {value105, range105};
  int error105 =
      ti_unshift(size, cross_2_inputs, cross2_options, cross_2_outputs);
  assert(error105 == TI_OKAY);

  for (int i = 1; i < size; i++)
  {
    if (cross_2[i] == 1)
      trend[i] = 1;
    else if (cross_1[i] == 1)
      trend[i] = -1;
    else
      trend[i] = not_zero(trend[i - 1], 1);

    if (trend[i] == 1)
      FastAtrRsiTL[i] = longband[i] - 50;
    else
      FastAtrRsiTL[i] = shortband[i] - 50;
  }

  const double nz_basis_options[] = {bollinger_length};
  double *nz_basis = malloc((unsigned int)size * sizeof(double));
  assert(nz_basis != 0);
  const double *nz_basis_inputs[] = {FastAtrRsiTL};
  double *nz_basis_outputs[] = {nz_basis};
  int error10 =
      ti_sma(size, nz_basis_inputs, nz_basis_options, nz_basis_outputs);
  assert(error10 == TI_OKAY);

  // refill the missing zero in atr
  double *basis = (double *)calloc((size_t)size, sizeof(double));
  const double *basis_inputs[] = {nz_basis};
  double *basis_outputs[] = {basis};
  int range2 = bollinger_length - 1;
  double value2 = 0;
  const double basis_options[] = {value2, range2};
  int error11 = ti_unshift(size, basis_inputs, basis_options, basis_outputs);
  assert(error11 == TI_OKAY);

  const double nz_dev_options[] = {bollinger_length};
  double *nz_dev = malloc((unsigned int)size * sizeof(double));
  assert(nz_dev != 0);
  const double *nz_dev_inputs[] = {FastAtrRsiTL};
  double *nz_dev_outputs[] = {nz_dev};
  int error12 = ti_stddev(size, nz_dev_inputs, nz_dev_options, nz_dev_outputs);
  assert(error12 == TI_OKAY);

  // refill the missing zero in atr
  double *dev = (double *)calloc((size_t)size, sizeof(double));
  const double *dev_inputs[] = {nz_dev};
  double *dev_outputs[] = {dev};
  int range3 = bollinger_length - 1;
  double value3 = 0;
  const double dev_options[] = {value3, range3};
  int error13 = ti_unshift(size, dev_inputs, dev_options, dev_outputs);
  assert(error13 == TI_OKAY);

  for (int i = 0; i < size; i++)
  {
    dev[i] = dev[i] * QQE_multiplier;
    upper[i] = basis[i] + dev[i];
    lower[i] = basis[i] - dev[i];
  }

  double *Greenbar1 = (double *)calloc((size_t)size, sizeof(double));
  double *Greenbar2 = (double *)calloc((size_t)size, sizeof(double));
  double *Redbar1 = (double *)calloc((size_t)size, sizeof(double));
  double *Redbar2 = (double *)calloc((size_t)size, sizeof(double));

  for (int z = 0; z < size; z++)
  {
    if (rsima1[z] - 50 > upper[z])
      Greenbar2[z] = 1;
    else
      Greenbar2[z] = 0;

    if (rsima1[z] - 50 < lower[z])
      Redbar2[z] = 1;
    else
      Redbar2[z] = 0;
  }

  for (int z = 0; z < size; z++)
  {
    if (rsima2[z] - 50 > threshold2)
      Greenbar1[z] = 1;
    else
      Greenbar1[z] = 0;

    if (rsima2[z] - 50 < 0 - threshold2)
      Redbar1[z] = 1;
    else
      Redbar1[z] = 0;
  }

  for (int i = 0; i < size; i++)
  {
    if (Greenbar1[i] == 1 && Greenbar2[i] == 1)
      qqeGreenbar[i] = TI_GREEN;
    else
      qqeGreenbar[i] = TI_NOTHING;

    if (Redbar1[i] == 1 && Redbar2[i] == 1)
      qqeRedbar[i] = TI_RED;
    else
      qqeRedbar[i] = TI_NOTHING;
  }

  free(nz_rsi1);
  free(rsi1);
  free(nz_rsi2);
  free(rsi2);
  free(rsima1);
  free(rsima2);
  free(atr_rsi1);
  free(Ma_atrRsi1);
  free(dar1);
  free(newshortband);
  free(newlongband);
  free(longband);
  free(shortband);
  free(trend);
  free(FastAtrRsiTL);
  free(upper);
  free(lower);
  free(longband_prev);
  free(shortband_prev);
  free(nz_cross_1);
  free(cross_1);
  free(nz_cross_2);
  free(cross_2);
  free(nz_basis);
  free(basis);
  free(nz_dev);
  free(dev);
  free(Greenbar1);
  free(Greenbar2);
  free(Redbar1);
  free(Redbar2);

  return TI_OKAY;
}
