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

int ti_boom_pro_start(TI_REAL const *options)
{
  UNUSED(options);
  return 0;
}

int ti_boom_pro(int size, TI_REAL const *const *inputs, TI_REAL const *options,
                TI_REAL *const *outputs)
{
  const TI_REAL *close = inputs[0];

  double *trigger = outputs[0];
  double *q4 = outputs[1];
  // double *Filt = outputs[2];
  // double *Peak = outputs[3];

  const int LPPeriod = (int)options[0];
  const double K1_quotient = (double)options[1];
  const int trigno = (int)options[2];
  const int LPPeriod2 = (int)options[3];
  const double K22_eot = (double)options[4];

  if (LPPeriod < 1 || LPPeriod2 < 1)
    return TI_INVALID_OPTION;

  double *alpha1 = (double *)calloc((unsigned long)size, sizeof(double));
  double *HP = (double *)calloc((unsigned long)size, sizeof(double));
  double *a1 = (double *)calloc((unsigned long)size, sizeof(double));
  double *b1 = (double *)calloc((unsigned long)size, sizeof(double));
  double *c1 = (double *)calloc((unsigned long)size, sizeof(double));
  double *c2 = (double *)calloc((unsigned long)size, sizeof(double));
  double *c3 = (double *)calloc((unsigned long)size, sizeof(double));
  double *Filt = (double *)calloc((unsigned long)size, sizeof(double));
  double *Peak = (double *)calloc((unsigned long)size, sizeof(double));
  double *a12 = (double *)calloc((unsigned long)size, sizeof(double));
  double *b12 = (double *)calloc((unsigned long)size, sizeof(double));
  double *c12 = (double *)calloc((unsigned long)size, sizeof(double));
  double *c22 = (double *)calloc((unsigned long)size, sizeof(double));
  double *c32 = (double *)calloc((unsigned long)size, sizeof(double));
  double *Filt2 = (double *)calloc((unsigned long)size, sizeof(double));
  double *Peak2 = (double *)calloc((unsigned long)size, sizeof(double));
  double *X = (double *)calloc((unsigned long)size, sizeof(double));
  double *Quotient1 = (double *)calloc((unsigned long)size, sizeof(double));
  double *X2 = (double *)calloc((unsigned long)size, sizeof(double));
  double *Quotient4 = (double *)calloc((unsigned long)size, sizeof(double));
  double *q1 = (double *)calloc((unsigned long)size, sizeof(double));

  double esize = 60;
  double ey = 50;
  double pi = (double)2 * asin((double)1);

  for (int i = 2; i < size; i++)
  {
    alpha1[i] =
        (float)(cos(0.707 * 2 * pi / 100) + sin(0.707 * 2 * pi / 100) - 1) /
        cos(0.707 * 2 * pi / 100);
    HP[i] = ((1 - (float)alpha1[i] / 2) * (1 - (float)alpha1[i] / 2) *
             (close[i] - (2 * close[i - 1]) + close[i - 2])) +
            (2 * (1 - alpha1[i]) * not_zero(HP[i - 1], 0)) -
            ((1 - alpha1[i]) * (1 - alpha1[i]) * not_zero(HP[i - 2], 0));
    a1[i] = exp(-1.414 * pi / LPPeriod);
    b1[i] = 2 * a1[i] * cos(1.414 * pi / LPPeriod);
    c2[i] = b1[i];
    c3[i] = -1 * a1[i] * a1[i];
    c1[i] = 1 - c2[i] - c3[i];
    Filt[i] = (c1[i] * (HP[i] + not_zero(HP[i - 1], 0)) / 2) +
              (c2[i] * not_zero(Filt[i - 1], 0)) +
              (c3[i] * not_zero(Filt[i - 2], 0));
    Peak[i] = 0.991 * not_zero(Peak[i - 1], 0);
    if (fabs(Filt[i]) > Peak[i])
      Peak[i] = fabs(Filt[i]);
    if (Peak[i] != 0)
      X[i] = Filt[i] / Peak[i];
    Quotient1[i] = (X[i] + K1_quotient) / (K1_quotient * X[i] + 1);

    a12[i] = exp(-1.414 * pi / LPPeriod2);
    b12[i] = 2 * a12[i] * cos(1.414 * pi / LPPeriod2);
    c22[i] = b12[i];
    c32[i] = -a12[i] * a12[i];
    c12[i] = 1 - c22[i] - c32[i];
    Filt2[i] = (c12[i] * (HP[i] + not_zero(HP[i - 1], 0)) / 2) +
               (c22[i] * not_zero(Filt2[i - 1], 0)) +
               (c32[i] * not_zero(Filt2[i - 2], 0));
    Peak2[i] = 0.991 * not_zero(Peak2[i - 1], 0);
    if (fabs(Filt2[i]) > Peak2[i])
      Peak2[i] = fabs(Filt2[i]);
    if (Peak2[i] != 0)
      X2[i] = Filt2[i] / Peak2[i];
    Quotient4[i] = (X2[i] + K22_eot) / (K22_eot * X2[i] + 1);
    q4[i] = Quotient4[i] * esize + ey;
    q1[i] = Quotient1[i] * esize + ey;
  }

  const double nz_trigger_options[] = {trigno};
  double *nz_trigger = (double *)calloc((unsigned long)size, sizeof(double));
  const double *nz_trigger_inputs[] = {q1};
  double *nz_trigger_outputs[] = {nz_trigger};
  int error8 =
      ti_sma(size, nz_trigger_inputs, nz_trigger_options, nz_trigger_outputs);
  assert(error8 == TI_OKAY);

  const double *trigger_inputs[] = {nz_trigger};
  double *trigger_outputs[] = {trigger};
  int range101 = trigno - 1;
  double value101 = 0;
  const double trigger_options[] = {value101, range101};
  int error101 =
      ti_unshift(size, trigger_inputs, trigger_options, trigger_outputs);
  assert(error101 == TI_OKAY);

  free(alpha1);
  free(HP);
  free(a1);
  free(b1);
  free(c1);
  free(c2);
  free(c3);
  free(Filt);
  free(Peak);
  free(a12);
  free(b12);
  free(c12);
  free(c22);
  free(c32);
  free(Filt2);
  free(Peak2);
  free(X);
  free(Quotient1);
  free(X2);
  free(Quotient4);
  free(q1);
  free(nz_trigger);

  return TI_OKAY;
}
