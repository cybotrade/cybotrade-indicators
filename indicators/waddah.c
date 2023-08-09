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

int ti_waddah_start(TI_REAL const *options)
{
  UNUSED(options);
  return 0;
}

int ti_waddah(int size, TI_REAL const *const *inputs, TI_REAL const *options,
              TI_REAL *const *outputs)
{
  const TI_REAL *close = inputs[0];
  TI_REAL *t1 = outputs[0];
  TI_REAL *e1 = outputs[1];
  TI_REAL *trendUp = outputs[2];
  TI_REAL *trendDown = outputs[3];

  const int fast_length = (int)options[0];
  const int slow_length = (int)options[1];
  const int signal_length = (int)options[2];
  const int BB_length = (int)options[3];
  const double multiplier = (double)options[4];
  const double sensitivity = (double)options[5];
  if (fast_length < 1 || slow_length < 1 || signal_length < 1 || BB_length < 1)
    return TI_INVALID_OPTION;

  for (int i = 0; i < size; i++)
  {
    t1[i] = 0;
    e1[i] = 0;
    trendUp[i] = 0;
    trendDown[i] = 0;
  }

  const double nz_macd_options[] = {fast_length, slow_length, signal_length};
  double *nz_macd = malloc((size_t)size * sizeof(double));
  double *nz_signal = malloc((size_t)size * sizeof(double));
  double *nz_hist = malloc((size_t)size * sizeof(double));
  assert(nz_macd != 0);
  const double *nz_macd_inputs[] = {close};
  double *nz_macd_outputs[] = {nz_macd, nz_signal, nz_hist};
  int error = ti_macd(size, nz_macd_inputs, nz_macd_options, nz_macd_outputs);
  assert(error == TI_OKAY);

  double *macd_line = malloc((unsigned int)size * sizeof(double));
  const double *macd_inputs[] = {nz_macd};
  double *macd_outputs[] = {macd_line};
  int range = slow_length - 1;
  double value = 0;
  const double macdline_option[] = {value, range};
  int error1 = ti_unshift(size, macd_inputs, macdline_option, macd_outputs);
  assert(error1 == TI_OKAY);

  const double nz_bb_bands_options[] = {BB_length, multiplier};
  double *nz_bbands_lower = malloc((unsigned int)size * sizeof(double));
  double *nz_bbands_middle = malloc((unsigned int)size * sizeof(double));
  double *nz_bbands_upper = malloc((unsigned int)size * sizeof(double));
  assert(nz_bbands_lower != 0);
  const double *nz_bb_bands_inputs[] = {close};
  double *nz_bb_bands_outputs[] = {nz_bbands_lower, nz_bbands_middle,
                                   nz_bbands_upper};
  int error2 = ti_bbands(size, nz_bb_bands_inputs, nz_bb_bands_options,
                         nz_bb_bands_outputs);
  assert(error2 == TI_OKAY);

  double *bbands_upper = malloc((unsigned int)size * sizeof(double));
  const double *bbands_upper_inputs[] = {nz_bbands_upper};
  double *bbands_upper_outputs[] = {bbands_upper};
  int range1 = BB_length - 1;
  double value1 = 0;
  const double bbupper_option[] = {value1, range1};
  int error3 = ti_unshift(size, bbands_upper_inputs, bbupper_option,
                          bbands_upper_outputs);
  assert(error3 == TI_OKAY);

  double *bbands_lower = malloc((unsigned int)size * sizeof(double));
  const double *bbands_lower_inputs[] = {nz_bbands_lower};
  double *bbands_lower_outputs[] = {bbands_lower};
  int range2 = BB_length - 1;
  double value2 = 0;
  const double bblower_option[] = {value2, range2};
  int error4 = ti_unshift(size, bbands_lower_inputs, bblower_option,
                          bbands_lower_outputs);
  assert(error4 == TI_OKAY);

  for (int i = 0; i < size; i++)
  {
    e1[i] = bbands_upper[i] - bbands_lower[i];
  }
  for (int i = 1; i < size; i++)
  {
    t1[i] = (macd_line[i] - macd_line[i - 1]) * sensitivity;
  }
  for (int i = 0; i < size; i++)
  {
    if (t1[i] >= 0)
    {
      trendUp[i] = t1[i];
      trendDown[i] = 0;
    }
    else if (t1[i] < 0)
    {
      trendDown[i] = -1 * t1[i];
      trendUp[i] = 0;
    }
    else
    {
      trendDown[i] = 0;
      trendUp[i] = 0;
    }
  }

  free(nz_macd);
  free(nz_signal);
  free(nz_hist);
  free(macd_line);
  free(nz_bbands_lower);
  free(nz_bbands_middle);
  free(nz_bbands_upper);
  free(bbands_upper);
  free(bbands_lower);

  return TI_OKAY;
}
