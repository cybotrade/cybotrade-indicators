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

int ti_hull_suite_start(TI_REAL const *options)
{
  UNUSED(options);
  return 0;
}

int ti_hull_suite(int size, TI_REAL const *const *inputs,
                  TI_REAL const *options, TI_REAL *const *outputs)
{
  const TI_REAL *close = inputs[0];

  double *bar_color = outputs[0];

  const int hma_length = (int)options[0];
  if (hma_length < 1)
    return TI_INVALID_OPTION;

  double *SHULL = (double *)calloc((size_t)size, sizeof(double));

  const double nz_hma_options[] = {options[0]};
  double *nz_hma = malloc((unsigned int)size * sizeof(double));
  assert(nz_hma != 0);
  const double *nz_hma_inputs[] = {close};
  double *nz_hma_outputs[] = {nz_hma};
  int error = ti_hma(size, nz_hma_inputs, nz_hma_options, nz_hma_outputs);
  assert(error == TI_OKAY);

  // refill the missing zero in hma
  double *hma = (double *)calloc((size_t)size, sizeof(double));
  const double *hma_inputs[] = {nz_hma};
  double *hma_outputs[] = {hma};
  int range = hma_length - 2 + (int)floor(sqrt(hma_length));
  double value = 0;
  const double hma_options[] = {value, range};
  int error1 = ti_unshift(size, hma_inputs, hma_options, hma_outputs);
  assert(error1 == TI_OKAY);

  for (int i = 2; i < size; i++)
    SHULL[i] = hma[i - 2];

  for (int i = 0; i < size; i++)
    if (hma[i] > SHULL[i])
      bar_color[i] = TI_GREEN;
    else
      bar_color[i] = TI_RED;

  free(SHULL);
  free(nz_hma);
  free(hma);

  return TI_OKAY;
}
