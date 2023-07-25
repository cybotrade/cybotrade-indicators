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

int ti_ha_start(TI_REAL const *options) {
  UNUSED(options);
  return 0;
}

int ti_ha(int size, TI_REAL const *const *inputs, TI_REAL const *options,
          TI_REAL *const *outputs) {
  UNUSED(options);
  const TI_REAL *open = inputs[0];
  const TI_REAL *high = inputs[1];
  const TI_REAL *low = inputs[2];
  const TI_REAL *close = inputs[3];
  TI_REAL *HA_open = outputs[0];
  TI_REAL *HA_high = outputs[1];
  TI_REAL *HA_low = outputs[2];
  TI_REAL *HA_close = outputs[3];

  for (int i = 0; i < size; i++)
    HA_close[i] = (open[i] + high[i] + low[i] + close[i]) / 4;

  HA_open[0] = (open[0] + HA_close[0]) / 2;

  for (int j = 1; j < size; j++)
    HA_open[j] = (HA_open[j - 1] + HA_close[j - 1]) / 2;

  for (int z = 0; z < size; z++) {
    double temp_arr1[3] = {high[z], HA_close[z], HA_open[z]};
    double max_data = max_value(temp_arr1, 3);
    HA_high[z] = max_data;
    double temp_arr2[3] = {low[z], HA_close[z], HA_open[z]};
    double min_data = min_value(temp_arr2, 3);
    HA_low[z] = min_data;
  }

  return TI_OKAY;
}
