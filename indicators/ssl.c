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

int ti_ssl_start(TI_REAL const *options)
{
  UNUSED(options);
  return 0;
}

int ti_ssl(int size, TI_REAL const *const *inputs, TI_REAL const *options,
           TI_REAL *const *outputs)
{
  const TI_REAL *high = inputs[0];
  const TI_REAL *low = inputs[1];
  const TI_REAL *close = inputs[2];
  TI_REAL *BBMC = outputs[0];
  TI_REAL *color_bar = outputs[1];
  TI_REAL *upperk = outputs[2];
  TI_REAL *lowerk = outputs[3];
  TI_REAL *base_cross_Long = outputs[4];
  TI_REAL *base_cross_Short = outputs[5];

  const int ma_length = (int)options[0];
  const int ssl3_length = (int)options[1];
  if (ma_length < 1 || ssl3_length < 1)
    return TI_INVALID_OPTION;

  const double nz_hma_options[] = {ma_length};
  double *nz_hma = malloc((unsigned int)size * sizeof(double));
  assert(nz_hma != 0);
  const double *nz_hma_inputs[] = {close};
  double *nz_hma_outputs[] = {nz_hma};
  int error = ti_hma(size, nz_hma_inputs, nz_hma_options, nz_hma_outputs);
  assert(error == TI_OKAY);

  const double *hma_inputs[] = {nz_hma};
  double *hma_outputs[] = {BBMC};
  int range = ma_length - 2 + (int)floor(sqrt(ma_length));
  double value = 0;
  const double hma_options[] = {value, range};
  int error1 = ti_unshift(size, hma_inputs, hma_options, hma_outputs);
  assert(error1 == TI_OKAY);

  double *true_range = (double *)calloc((size_t)size, sizeof(double));
  for (int i = 1; i < size; i++)
  {
    true_range[i] =
        fmax(fmax(high[i] - low[i], fabs(high[i] - not_zero(close[i - 1], 0))),
             fabs(low[i] - not_zero(close[i - 1], 0)));
  }

  double *rangema = (double *)calloc((size_t)size, sizeof(double));
  const double ema_options[] = {ma_length};
  const double *ema_inputs[] = {true_range};
  double *ema_outputs[] = {rangema};
  int error2 = ti_ema(size, ema_inputs, ema_options, ema_outputs);
  assert(error2 == TI_OKAY);

  for (int i = 0; i < size; i++)
  {
    upperk[i] = BBMC[i] + (rangema[i] * 0.2);
    lowerk[i] = BBMC[i] - (rangema[i] * 0.2);
    double colour_bar;
    if (close[i] > upperk[i])
    {
      colour_bar = 1;
    }
    else if (close[i] < lowerk[i])
    {
      colour_bar = -1;
    }
    else
    {
      colour_bar = 0;
    }
    color_bar[i] = colour_bar;
  }

  double *Hlv3 = (double *)calloc((size_t)size, sizeof(double));
  double *sslExit = (double *)calloc((size_t)size, sizeof(double));

  const double nz_ExitHigh_options[] = {ssl3_length};
  double *nz_ExitHigh = malloc((unsigned int)size * sizeof(double));
  assert(nz_ExitHigh != 0);
  const double *nz_ExitHigh_inputs[] = {high};
  double *nz_ExitHigh_outputs[] = {nz_ExitHigh};
  int error3 = ti_hma(size, nz_ExitHigh_inputs, nz_ExitHigh_options,
                      nz_ExitHigh_outputs);
  assert(error3 == TI_OKAY);

  double *ExitHigh = (double *)calloc((size_t)size, sizeof(double));
  const double *ExitHigh_inputs[] = {nz_ExitHigh};
  double *ExitHigh_outputs[] = {ExitHigh};
  int range1 = ssl3_length - 2 + (int)floor(sqrt(ssl3_length));
  double value1 = 0;
  const double exithigh_options[] = {value1, range1};
  int error4 =
      ti_unshift(size, ExitHigh_inputs, exithigh_options, ExitHigh_outputs);
  assert(error4 == TI_OKAY);

  const double nz_ExitLow_options[] = {ssl3_length};
  double *nz_ExitLow = malloc((unsigned int)size * sizeof(double));
  assert(nz_ExitLow != 0);
  const double *nz_ExitLow_inputs[] = {low};
  double *nz_ExitLow_outputs[] = {nz_ExitLow};
  int error5 =
      ti_hma(size, nz_ExitLow_inputs, nz_ExitLow_options, nz_ExitLow_outputs);
  assert(error5 == TI_OKAY);

  double *ExitLow = (double *)calloc((size_t)size, sizeof(double));
  const double *ExitLow_inputs[] = {nz_ExitLow};
  double *ExitLow_outputs[] = {ExitLow};
  int range2 = ssl3_length - 2 + (int)floor(sqrt(ssl3_length));
  double value2 = 0;
  const double exitlow_options[] = {value2, range2};
  int error6 =
      ti_unshift(size, ExitLow_inputs, exitlow_options, ExitLow_outputs);
  assert(error6 == TI_OKAY);

  for (int i = 1; i < size; i++)
    if (close[i] > ExitHigh[i])
      Hlv3[i] = 1;
    else if (close[i] < ExitLow[i])
      Hlv3[i] = -1;
    else
      Hlv3[i] = Hlv3[i - 1];

  for (int i = 0; i < size; i++)
    if (Hlv3[i] < 0)
      sslExit[i] = ExitHigh[i];
    else
      sslExit[i] = ExitLow[i];

  double *nz_base_cross_Long = (double *)calloc((size_t)size, sizeof(double));
  const double nz_base_cross_Long_options[] = {0};
  const double *nz_base_cross_Long_inputs[] = {close, sslExit};
  double *nz_base_cross_Long_outputs[] = {nz_base_cross_Long};
  int error7 =
      ti_crossover(size, nz_base_cross_Long_inputs, nz_base_cross_Long_options,
                   nz_base_cross_Long_outputs);
  assert(error7 == TI_OKAY);

  const double *base_cross_Long_inputs[] = {nz_base_cross_Long};
  double *base_cross_Long_outputs[] = {base_cross_Long};
  int range105 = 1;
  double value105 = 0;
  const double base_cross_Long_options[] = {value105, range105};
  int error105 = ti_unshift(size, base_cross_Long_inputs,
                            base_cross_Long_options, base_cross_Long_outputs);
  assert(error105 == TI_OKAY);

  double *nz_base_cross_Short = (double *)calloc((size_t)size, sizeof(double));
  const double nz_base_cross_Short_options[] = {0};
  const double *nz_base_cross_Short_inputs[] = {sslExit, close};
  double *nz_base_cross_Short_outputs[] = {nz_base_cross_Short};
  int error8 =
      ti_crossover(size, nz_base_cross_Short_inputs,
                   nz_base_cross_Short_options, nz_base_cross_Short_outputs);
  assert(error8 == TI_OKAY);

  const double *base_cross_Short_inputs[] = {nz_base_cross_Short};
  double *base_cross_Short_outputs[] = {base_cross_Short};
  int range200 = 1;
  double value200 = 0;
  const double base_cross_Short_options[] = {value200, range200};
  int error200 = ti_unshift(size, base_cross_Short_inputs,
                            base_cross_Short_options, base_cross_Short_outputs);
  assert(error200 == TI_OKAY);

  free(nz_hma);
  free(true_range);
  free(rangema);
  free(Hlv3);
  free(sslExit);
  free(nz_ExitHigh);
  free(ExitHigh);
  free(nz_ExitLow);
  free(ExitLow);
  free(nz_base_cross_Long);
  free(nz_base_cross_Short);

  return TI_OKAY;
}
