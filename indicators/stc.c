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

int ti_stc_start(TI_REAL const *options)
{
  UNUSED(options);
  return 0;
}

int ti_stc(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs)
{
  const TI_REAL *close = inputs[0];
  TI_REAL *stc = outputs[0];
  TI_REAL *stc_color = outputs[1];

  const int length = (int)options[0];
  const int fast_length = (int)options[1];
  const int slow_length = (int)options[2];
  const double aaa = (double)options[3];

  if (length < 1 || fast_length < 1 || slow_length < 1 || aaa < 0)
    return TI_INVALID_OPTION;

  double *ema_diff = (double *)calloc((size_t)size, sizeof(double));

  double *fastema = (double *)calloc((size_t)size, sizeof(double));
  const double fastema_options[] = {fast_length};
  const double *fastema_inputs[] = {close};
  double *fastema_outputs[] = {fastema};
  int error = ti_ema(size, fastema_inputs, fastema_options, fastema_outputs);
  assert(error == TI_OKAY);

  double *slowema = (double *)calloc((size_t)size, sizeof(double));
  const double slowema_options[] = {slow_length};
  const double *slowema_inputs[] = {close};
  double *slowema_outputs[] = {slowema};
  int error3 = ti_ema(size, slowema_inputs, slowema_options, slowema_outputs);
  assert(error3 == TI_OKAY);

  for (int i = 0; i < size; i++)
  {
    ema_diff[i] = fastema[i] - slowema[i];
  }

  const double nz_CCC_options[] = {length};
  double *nz_CCC = malloc((unsigned int)size * sizeof(double));
  assert(nz_CCC != 0);
  const double *nz_CCC_inputs[] = {ema_diff};
  double *nz_CCC_outputs[] = {nz_CCC};
  int error4 = ti_min(size, nz_CCC_inputs, nz_CCC_options, nz_CCC_outputs);
  assert(error4 == TI_OKAY);

  // refill the missing zero in atr
  double *CCC = (double *)calloc((size_t)size, sizeof(double));
  const double *CCC_inputs[] = {nz_CCC};
  double *CCC_outputs[] = {CCC};
  int range1 = length - 1;
  double value1 = 0;
  const double ccc_options[] = {value1, range1};
  int error5 = ti_unshift(size, CCC_inputs, ccc_options, CCC_outputs);
  assert(error5 == TI_OKAY);

  const double nz_CCCC_options[] = {length};
  double *nz_CCCC = malloc((unsigned int)size * sizeof(double));
  assert(nz_CCCC != 0);
  const double *nz_CCCC_inputs[] = {ema_diff};
  double *nz_CCCC_outputs[] = {nz_CCCC};
  int error6 = ti_max(size, nz_CCCC_inputs, nz_CCCC_options, nz_CCCC_outputs);
  assert(error6 == TI_OKAY);

  // refill the missing zero in atr
  double *CCCC = (double *)calloc((size_t)size, sizeof(double));
  const double *CCCC_inputs[] = {nz_CCCC};
  double *CCCC_outputs[] = {CCCC};
  int range3 = length - 1;
  double value3 = 0;
  const double cccc_options[] = {value3, range3};
  int error7 = ti_unshift(size, CCCC_inputs, cccc_options, CCCC_outputs);
  assert(error7 == TI_OKAY);

  double *CCCCC = (double *)calloc((size_t)size, sizeof(double));
  double *DDD = (double *)calloc((size_t)size, sizeof(double));

  for (int i = 0; i < size; i++)
    CCCC[i] = CCCC[i] - CCC[i];
  for (int i = 1; i < size; i++)
    if (CCCC[i] > 0)
      CCCCC[i] = (float)(ema_diff[i] - CCC[i]) / CCCC[i] * 100;
    else
      CCCCC[i] = not_zero(CCCCC[i - 1], 0);

  DDD[0] = CCCCC[0];
  for (int i = 1; i < size; i++)
  {
    DDD[i] = DDD[i - 1] + aaa * (CCCCC[i] - DDD[i - 1]);
  }

  const double nz_DDDD_options[] = {length};
  double *nz_DDDD = malloc((unsigned int)size * sizeof(double));
  assert(nz_DDDD != 0);
  const double *nz_DDDD_inputs[] = {DDD};
  double *nz_DDDD_outputs[] = {nz_DDDD};
  int error8 = ti_min(size, nz_DDDD_inputs, nz_DDDD_options, nz_DDDD_outputs);
  assert(error8 == TI_OKAY);

  // refill the missing zero in atr
  double *DDDD = (double *)calloc((size_t)size, sizeof(double));
  const double *DDDD_inputs[] = {nz_DDDD};
  double *DDDD_outputs[] = {DDDD};
  int range2 = length - 1;
  double value2 = 0;
  const double dddd_options[] = {value2, range2};
  int error9 = ti_unshift(size, DDDD_inputs, dddd_options, DDDD_outputs);
  assert(error9 == TI_OKAY);

  const double nz_DDDDD_options[] = {length};
  double *nz_DDDDD = malloc((unsigned int)size * sizeof(double));
  assert(nz_DDDDD != 0);
  const double *nz_DDDDD_inputs[] = {DDD};
  double *nz_DDDDD_outputs[] = {nz_DDDDD};
  int error10 =
      ti_max(size, nz_DDDDD_inputs, nz_DDDDD_options, nz_DDDDD_outputs);
  assert(error10 == TI_OKAY);

  // refill the missing zero in atr
  double *DDDDD = (double *)calloc((size_t)size, sizeof(double));
  const double *DDDDD_inputs[] = {nz_DDDDD};
  double *DDDDD_outputs[] = {DDDDD};
  int range5 = length - 1;
  double value5 = 0;
  const double ddddd_options[] = {value5, range5};
  int error11 = ti_unshift(size, DDDDD_inputs, ddddd_options, DDDDD_outputs);
  assert(error11 == TI_OKAY);

  for (int i = 0; i < size; i++)
    DDDDD[i] = DDDDD[i] - DDDD[i];

  double *DDDDDD = (double *)calloc((size_t)size, sizeof(double));

  for (int i = 1; i < size; i++)
  {
    if (DDDDD[i] > 0)
    {
      DDDDDD[i] = (float)(DDD[i] - DDDD[i]) / DDDDD[i] * 100;
    }
    else
    {
      DDDDDD[i] = not_zero(DDDDDD[i - 1], 0);
    }
  }

  stc[0] = DDDDDD[0];
  for (int i = 1; i < size; i++)
  {
    stc[i] = stc[i - 1] + aaa * (DDDDDD[i] - stc[i - 1]);
  }

  stc_color[0] = TI_NOTHING;
  for (int i = 1; i < size; i++)
    if (stc[i] > stc[i - 1])
      stc_color[i] = TI_GREEN;
    else
      stc_color[i] = TI_RED;

  free(ema_diff);
  free(fastema);
  free(slowema);
  free(nz_CCC);
  free(CCC);
  free(nz_CCCC);
  free(CCCC);
  free(CCCCC);
  free(DDD);
  free(nz_DDDD);
  free(DDDD);
  free(nz_DDDDD);
  free(DDDDD);
  free(DDDDDD);

  return TI_OKAY;
}
