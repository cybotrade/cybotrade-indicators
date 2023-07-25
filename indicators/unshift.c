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

int ti_unshift_start(TI_REAL const *options) {
  UNUSED(options);
  return 0;
}

int ti_unshift(int size, TI_REAL const *const *inputs, TI_REAL const *options,
               TI_REAL *const *outputs) {
  const TI_REAL *new_arr = inputs[0];
  TI_REAL *output = outputs[0];
  const int n = (int)options[0];
  const int length = (int)options[1];
  for (int i = 0; i < length; i++)
    output[i] = n;
  for (int i = length; i < size; i++)
    output[i] = new_arr[i - length];
  return 0;
}
