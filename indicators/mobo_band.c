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

int ti_mobo_band_start(TI_REAL const *options)
{
  UNUSED(options);
  return 0;
}

int ti_mobo_band(int size, TI_REAL const *const *inputs, TI_REAL const *options,
                 TI_REAL *const *outputs)
{
  const TI_REAL *high = inputs[0];
  const TI_REAL *low = inputs[1];
  TI_REAL *final_signal = outputs[0];

  const int dpolength = (int)options[0];
  const int mobolength = (int)options[1];
  const double numDevDn = (double)options[2];
  const double numDevUp = (double)options[3];
  if (dpolength < 1 || mobolength < 1)
    return TI_INVALID_OPTION;

  double *price1 = (double *)calloc((size_t)size, sizeof(double));
  double *hl2 = (double *)calloc((size_t)size, sizeof(double));

  for (int i = 0; i < size; i++)
    hl2[i] = (float)(high[i] + low[i]) / 2;

  int start_index = (int)floor((float)dpolength / 2 + 1);
  for (int i = start_index; i < size; i++)
    price1[i] = hl2[i - start_index];

  // get atr data
  const double nz_xsma_options[] = {dpolength};
  double *nz_xsma = malloc((unsigned int)size * sizeof(double));
  assert(nz_xsma != 0);
  const double *nz_xsma_inputs[] = {price1};
  double *nz_xsma_outputs[] = {nz_xsma};
  int error = ti_sma(size, nz_xsma_inputs, nz_xsma_options, nz_xsma_outputs);
  assert(error == TI_OKAY);

  // refill the missing zero in atr
  double *xsma = (double *)calloc((size_t)size, sizeof(double));
  const double *xsma_inputs[] = {nz_xsma};
  double *xsma_outputs[] = {xsma};
  int range1 = dpolength - 1;
  double value1 = 0;
  const double xsma_options[] = {value1, range1};
  int error1 = ti_unshift(size, xsma_inputs, xsma_options, xsma_outputs);
  assert(error1 == TI_OKAY);

  double *DPO = (double *)calloc((size_t)size, sizeof(double));
  for (int i = 0; i < size; i++)
  {
    DPO[i] = hl2[i] - xsma[i];
  }

  const double nz_Midline_options[] = {mobolength};
  double *nz_Midline = malloc((unsigned int)size * sizeof(double));
  assert(nz_Midline != 0);
  const double *nz_Midline_inputs[] = {DPO};
  double *nz_Midline_outputs[] = {nz_Midline};
  int error2 =
      ti_sma(size, nz_Midline_inputs, nz_Midline_options, nz_Midline_outputs);
  assert(error2 == TI_OKAY);

  // refill the missing zero in atr
  double *Midline = (double *)calloc((size_t)size, sizeof(double));
  const double *Midline_inputs[] = {nz_Midline};
  double *Midline_outputs[] = {Midline};
  int range2 = dpolength - 1;
  double value2 = 0;
  const double midline_options[] = {value2, range2};
  int error3 =
      ti_unshift(size, Midline_inputs, midline_options, Midline_outputs);
  assert(error3 == TI_OKAY);

  const double nz_sDev_options[] = {mobolength};
  double *nz_sDev = malloc((unsigned int)size * sizeof(double));
  assert(nz_sDev != 0);
  const double *nz_sDev_inputs[] = {DPO};
  double *nz_sDev_outputs[] = {nz_sDev};
  int error4 =
      ti_stddev(size, nz_sDev_inputs, nz_sDev_options, nz_sDev_outputs);
  assert(error4 == TI_OKAY);

  // refill the missing zero in atr
  double *sDev = (double *)calloc((size_t)size, sizeof(double));
  const double *sDev_inputs[] = {nz_sDev};
  double *sDev_outputs[] = {sDev};
  int range3 = dpolength - 1;
  double value3 = 0;
  const double sdev_options[] = {value3, range3};
  int error5 = ti_unshift(size, sDev_inputs, sdev_options, sDev_outputs);
  assert(error5 == TI_OKAY);

  double *LowerBand = (double *)calloc((size_t)size, sizeof(double));
  double *UpperBand = (double *)calloc((size_t)size, sizeof(double));
  double *Signal1 = (double *)calloc((size_t)size, sizeof(double));
  double *Signal2 = (double *)calloc((size_t)size, sizeof(double));
  double *wasUp = (double *)calloc((size_t)size, sizeof(double));
  double *wasDn = (double *)calloc((size_t)size, sizeof(double));

  for (int i = 0; i < size; i++)
  {
    LowerBand[i] = Midline[i] + (numDevDn * sDev[i]);
    UpperBand[i] = Midline[i] + (numDevUp * sDev[i]);
  }

  for (int i = 1; i < size; i++)
  {
    double last_DPO = DPO[i];
    double last_second_DPO = DPO[i - 1];
    double last_upper = UpperBand[i];
    double last_second_upper = UpperBand[i - 1];
    double last_lower = LowerBand[i];
    double last_second_lower = LowerBand[i - 1];
    if (last_DPO > last_upper && last_second_DPO < last_second_upper)
    {
      Signal1[i] = 1;
      Signal2[i] = 0;
    }
    else if (last_DPO < last_lower && last_second_DPO > last_second_lower)
    {
      Signal1[i] = 0;
      Signal2[i] = 1;
    }
    else
    {
      Signal1[i] = 0;
      Signal2[i] = 0;
    }
  }

  for (int i = 1; i < size; i++)
  {
    if (Signal1[i] == 1)
    {
      wasUp[i] = 1;
      wasDn[i] = 0;
    }
    else if (Signal2[i] == 1)
    {
      wasUp[i] = 0;
      wasDn[i] = 1;
    }
    else
    {
      wasUp[i] = wasUp[i - 1];
      wasDn[i] = wasDn[i - 1];
    }
  }

  for (int i = 1; i < size; i++)
    if (Signal1[i] == 1 && wasDn[i - 1] == 1)
      final_signal[i] = 1;
    else if (Signal2[i] == 1 && wasUp[i - 1] == 1)
      final_signal[i] = -1;
    else
      final_signal[i] = 0;

  free(price1);
  free(hl2);
  free(nz_xsma);
  free(xsma);
  free(DPO);
  free(nz_Midline);
  free(Midline);
  free(nz_sDev);
  free(sDev);
  free(LowerBand);
  free(UpperBand);
  free(Signal1);
  free(Signal2);
  free(wasUp);
  free(wasDn);

  return TI_OKAY;
}
