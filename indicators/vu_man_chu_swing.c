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

int ti_vu_man_chu_swing_start(TI_REAL const *options)
{
  UNUSED(options);
  return 0;
}

int ti_vu_man_chu_swing(int size, TI_REAL const *const *inputs,
                        TI_REAL const *options, TI_REAL *const *outputs)
{
  const TI_REAL *close = inputs[0];
  TI_REAL *longCondition = outputs[0];
  TI_REAL *shortCondition = outputs[1];

  const int swing_period = (int)options[0];
  const int swing_multiplier = (int)options[1];

  if (swing_period < 1 || swing_multiplier < 1)
    return TI_INVALID_OPTION;

  for (int i = 0; i < size; i++)
  {
    longCondition[i] = 0;
    shortCondition[i] = 0;
  }

  double *rng_ = (double *)calloc((size_t)size, sizeof(double));
  double *dif_x = (double *)calloc((size_t)size, sizeof(double));
  int wper = swing_period * 2 - 1;
  for (int i = 1; i < size; i++)
  {
    dif_x[i] = fabs(close[i] - close[i - 1]);
  }
  const double avrng_options[] = {swing_period};
  double *avrng = (double *)calloc((size_t)size, sizeof(double));
  const double *avrng_inputs[] = {dif_x};
  double *avrng_outputs[] = {avrng};
  int error1 = ti_ema(size, avrng_inputs, avrng_options, avrng_outputs);
  assert(error1 == TI_OKAY);

  const double ac1_options[] = {wper};
  double *ac1 = (double *)calloc((size_t)size, sizeof(double));
  const double *ac1_inputs[] = {avrng};
  double *ac1_outputs[] = {ac1};
  int error2 = ti_ema(size, ac1_inputs, ac1_options, ac1_outputs);
  assert(error2 == TI_OKAY);
  for (int i = 0; i < size; i++)
  {
    rng_[i] = ac1[i] * swing_multiplier;
  }

  double *rfilt = (double *)calloc((size_t)size, sizeof(double));
  rfilt[0] = close[0];
  double *hi_band = (double *)calloc((size_t)size, sizeof(double));
  double *lo_band = (double *)calloc((size_t)size, sizeof(double));
  double *fdir = (double *)calloc((size_t)size, sizeof(double));
  double *upward = (double *)calloc((size_t)size, sizeof(double));
  double *downward = (double *)calloc((size_t)size, sizeof(double));
  double *longCond = (double *)calloc((size_t)size, sizeof(double));
  double *shortCond = (double *)calloc((size_t)size, sizeof(double));
  double *CondIni = (double *)calloc((size_t)size, sizeof(double));

  for (int i = 1; i < size; i++)
  {
    if (close[i] - rng_[i] > rfilt[i - 1])
    {
      rfilt[i] = close[i] - rng_[i];
    }
    else if (close[i] + rng_[i] < rfilt[i - 1])
    {
      rfilt[i] = close[i] + rng_[i];
    }
    else
    {
      rfilt[i] = rfilt[i - 1];
    }
    hi_band[i] = rfilt[i - 1] + rng_[i];
    lo_band[i] = rfilt[i - 1] - rng_[i];
  }
  for (int i = 1; i < size; i++)
  {
    if (rfilt[i] > rfilt[i - 1])
    {
      fdir[i] = 1;
    }
    else if (rfilt[i] < rfilt[i - 1])
    {
      fdir[i] = -1;
    }
    else
    {
      fdir[i] = fdir[i - 1];
    }
  }
  for (int i = 0; i < size; i++)
  {
    if (fdir[i] == 1)
    {
      upward[i] = 1;
      downward[i] = 0;
    }
    else if (fdir[i] == -1)
    {
      upward[i] = 0;
      downward[i] = 1;
    }
    else
    {
      upward[i] = 0;
      downward[i] = 0;
    }
  }
  for (int i = 1; i < size; i++)
  {
    if (close[i] > rfilt[i] && upward[i] == 1 &&
        (close[i] > close[i - 1] || close[i] < close[i - 1]))
    {
      longCond[i] = 1;
      shortCond[i] = 0;
    }
    else if (close[i] < rfilt[i] && downward[i] == 1 &&
             (close[i] > close[i - 1] || close[i] < close[i - 1]))
    {
      longCond[i] = 0;
      shortCond[i] = 1;
    }
    else
    {
      longCond[i] = 0;
      shortCond[i] = 0;
    }
  }
  for (int i = 1; i < size; i++)
  {
    if (longCond[i] == 1)
    {
      CondIni[i] = 1;
    }
    else if (shortCond[i] == 1)
    {
      CondIni[i] = -1;
    }
    else
    {
      CondIni[i] = CondIni[i - 1];
    }
  }
  for (int i = 1; i < size; i++)
  {
    if (longCond[i] == 1 && CondIni[i - 1] == -1)
    {
      longCondition[i] = 1;
      shortCondition[i] = 0;
    }
    else if (shortCond[i] == 1 && CondIni[i - 1] == 1)
    {
      longCondition[i] = 0;
      shortCondition[i] = -1;
    }
    else
    {
      longCondition[i] = 0;
      shortCondition[i] = 0;
    }
  }

  free(rng_);
  free(dif_x);
  free(avrng);
  free(ac1);
  free(rfilt);
  free(hi_band);
  free(lo_band);
  free(fdir);
  free(upward);
  free(downward);
  free(longCond);
  free(shortCond);
  free(CondIni);

  return TI_OKAY;
}
