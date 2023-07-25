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

int ti_rvi_divergence_start(TI_REAL const *options)
{
  UNUSED(options);
  return 0;
}

int ti_rvi_divergence(int size, TI_REAL const *const *inputs,
                      TI_REAL const *options, TI_REAL *const *outputs)
{
  const TI_REAL *high = inputs[0];
  const TI_REAL *low = inputs[1];
  const TI_REAL *close = inputs[2];

  double *bull = outputs[0];
  double *bear = outputs[1];
  // double *filter_ph_index = outputs[0];
  // double *filter_ph_div_data = outputs[1];
  // double *filter_ph_high = outputs[2];
  // double *filter_pl_index = outputs[3];
  // double *filter_pl_div_data = outputs[4];
  // double *filter_pl_low = outputs[5];

  // double *ph_index = outputs[0];
  // double *ph_size = outputs[1];
  // double *filter_pl_div_data = outputs[4];
  // double *filter_pl_low = outputs[5];

  const int left_bar = (int)options[0];
  const int right_bar = (int)options[1];
  const int stdev_length = (int)options[2];
  const int ema_length = (int)options[3];

  if (stdev_length < 1 || ema_length < 1 || left_bar < 0 || right_bar < 0)
    return TI_INVALID_OPTION;

  for (int i = 0; i < size; i++)
  {
    bull[i] = TI_NOTHING;
    bear[i] = TI_NOTHING;
  }

  const double rvi_options[] = {stdev_length, ema_length};
  double *rvi = malloc((unsigned int)size * sizeof(double));
  assert(rvi != 0);
  const double *rvi_inputs[] = {close};
  double *rvi_outputs[] = {rvi};
  int error = ti_rvi(size, rvi_inputs, rvi_options, rvi_outputs);
  assert(error == TI_OKAY);

  double *ph_index = (double *)calloc((size_t)size, sizeof(double));
  double *ph_div_data = (double *)calloc((size_t)size, sizeof(double));
  double *ph_high = (double *)calloc((size_t)size, sizeof(double));
  double *ph_size = (double *)calloc((size_t)size, sizeof(double));
  double *pl_index = (double *)calloc((size_t)size, sizeof(double));
  double *pl_div_data = (double *)calloc((size_t)size, sizeof(double));
  double *pl_low = (double *)calloc((size_t)size, sizeof(double));
  double *pl_size = (double *)calloc((size_t)size, sizeof(double));

  const double *ph_inputs[] = {high, rvi};
  double *ph_outputs[] = {ph_index, ph_div_data, ph_high, ph_size};
  get_diver_pivot_high(ph_inputs, size, left_bar, right_bar, ph_outputs);
  const double *pl_inputs[] = {low, rvi};
  double *pl_outputs[] = {pl_index, pl_div_data, pl_low, pl_size};
  get_diver_pivot_low(pl_inputs, size, left_bar, right_bar, pl_outputs);

  int ph_count = (int)ph_size[0];
  int pl_count = (int)pl_size[0];
  double *filter_ph_index = (double *)calloc((size_t)ph_count, sizeof(double));
  double *filter_ph_div_data =
      (double *)calloc((size_t)ph_count, sizeof(double));
  double *filter_ph_high = (double *)calloc((size_t)ph_count, sizeof(double));
  double *filter_pl_index = (double *)calloc((size_t)pl_count, sizeof(double));
  double *filter_pl_div_data =
      (double *)calloc((size_t)pl_count, sizeof(double));
  double *filter_pl_low = (double *)calloc((size_t)pl_count, sizeof(double));

  const double *filter_ph_inputs[] = {ph_index, ph_div_data, ph_high};
  double *filter_ph_outputs[] = {filter_ph_index, filter_ph_div_data,
                                 filter_ph_high};
  filter_array(filter_ph_inputs, size, filter_ph_outputs);

  const double *filter_pl_inputs[] = {pl_index, pl_div_data, pl_low};
  double *filter_pl_outputs[] = {filter_pl_index, filter_pl_div_data,
                                 filter_pl_low};
  filter_array(filter_pl_inputs, size, filter_pl_outputs);

  for (int i = 1; i < pl_count; i++)
  {
    int prev_index = (int)filter_pl_index[i - 1];
    double prev_rvi = filter_pl_div_data[i - 1];
    double prev_low = filter_pl_low[i - 1];
    int index = (int)filter_pl_index[i];
    double _rvi = filter_pl_div_data[i];
    double _low = filter_pl_low[i];
    if (_rvi > prev_rvi && _low < prev_low && index - prev_index >= 6 &&
        index - prev_index <= 60)
    {
      bull[index] = TI_BULL;
    }
  }
  for (int i = 1; i < ph_count; i++)
  {
    int prev_index = (int)filter_ph_index[i - 1];
    double prev_rvi = filter_ph_div_data[i - 1];
    double prev_high = filter_ph_high[i - 1];
    int index = (int)filter_ph_index[i];
    double _rvi = filter_ph_div_data[i];
    double _high = filter_ph_high[i];
    if (_rvi < prev_rvi && _high > prev_high && index - prev_index >= 6 &&
        index - prev_index <= 60)
    {
      bear[index] = TI_BEAR;
    }
  }

  free(rvi);
  free(ph_index);
  free(ph_div_data);
  free(ph_high);
  free(ph_size);
  free(pl_index);
  free(pl_div_data);
  free(pl_low);
  free(pl_size);
  free(filter_ph_index);
  free(filter_ph_div_data);
  free(filter_pl_index);
  free(filter_pl_div_data);

  return TI_OKAY;
}
