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

int ti_macd_hist_divergence_start(TI_REAL const *options)
{
  UNUSED(options);
  return 0;
}

int ti_macd_hist_divergence(int size, TI_REAL const *const *inputs,
                            TI_REAL const *options, TI_REAL *const *outputs)
{
  const TI_REAL *high = inputs[0];
  const TI_REAL *low = inputs[1];
  const TI_REAL *close = inputs[2];

  double *bull = outputs[0];
  double *bear = outputs[1];

  const int fast_length = (int)options[0];
  const int slow_length = (int)options[1];
  const int signal_length = (int)options[2];

  if (fast_length < 1 || slow_length < 1 || signal_length < 1)
    return TI_INVALID_OPTION;

  for (int i = 0; i < size; i++)
  {
    bull[i] = TI_NOTHING;
    bear[i] = TI_NOTHING;
  }

  const double nz_macd_options[] = {fast_length, slow_length, signal_length};
  double *nz_macd = malloc((unsigned int)size * sizeof(double));
  double *nz_signal = malloc((unsigned int)size * sizeof(double));
  double *nz_hist = malloc((unsigned int)size * sizeof(double));
  assert(nz_macd != 0);
  const double *nz_macd_inputs[] = {close};
  double *nz_macd_outputs[] = {nz_macd, nz_signal, nz_hist};
  int error = ti_macd(size, nz_macd_inputs, nz_macd_options, nz_macd_outputs);
  assert(error == TI_OKAY);

  double *histogram = malloc((unsigned int)size * sizeof(double));
  const double *hist_inputs[] = {nz_hist};
  double *hist_outputs[] = {histogram};
  int range = slow_length - 1;
  double value = 0;
  const double hist_options[] = {value, range};
  int error1 = ti_unshift(size, hist_inputs, hist_options, hist_outputs);
  assert(error1 == TI_OKAY);

  int *ph_index = (int *)calloc((size_t)size, sizeof(int));
  int *pl_index = (int *)calloc((size_t)size, sizeof(double));

  int pl_count = 1;
  int ph_count = 1;
  int x = 1;
  int y = 1;
  for (int i = 2; i < size; i++)
  {
    if (histogram[i] < 0 && histogram[i - 1] < 0 && histogram[i - 2] < 0 &&
        histogram[i - 2] > histogram[i - 1] &&
        histogram[i - 1] < histogram[i])
    {
      pl_index[x++] = i - 1;
      pl_count += 1;
    }
    else if (histogram[i] > 0 && histogram[i - 1] > 0 &&
             histogram[i - 2] > 0 && histogram[i - 2] < histogram[i - 1] &&
             histogram[i - 1] > histogram[i])
    {
      ph_index[y++] = i - 1;
      ph_count += 1;
    }
  }

  for (int i = 1; i < ph_count; i++)
  {
    int start_index = ph_index[i - 1];
    int end_index = ph_index[i];
    int *temp_arr = (int *)calloc((size_t)size, sizeof(int));
    int *temp_arr_size = (int *)calloc(1, sizeof(int));
    const int *slice_array_inputs[] = {pl_index};
    int *slice_array_outputs[] = {temp_arr, temp_arr_size};
    slice_index(slice_array_inputs, start_index, end_index, pl_count,
                slice_array_outputs);
    int index_size = temp_arr_size[0];

    double prev_low = 0;
    double prev_hist = 0;
    if (index_size >= 2)
    {
      for (int z = 1; z < index_size; z++)
      {
        int prev_index = temp_arr[z - 1];
        int cur_index = temp_arr[z];
        prev_hist = histogram[temp_arr[0]];
        prev_low = low[temp_arr[0]];
        if (histogram[prev_index] < histogram[cur_index] &&
            low[prev_index] > low[cur_index])
        {
          bull[cur_index] = TI_BULL;
        }
        else if (prev_hist != 0 && prev_low != 0)
        {
          if (prev_hist < histogram[cur_index] && prev_low > low[cur_index])
          {
            bull[cur_index] = TI_BULL;
          }
        }
      }
    }
    if (i == ph_count - 1)
    {
      int _start_index = ph_index[i];
      int _end_index = size - 1;
      int *_temp_arr = (int *)calloc((size_t)size, sizeof(int));
      int *_temp_arr_size = (int *)calloc((size_t)1, sizeof(int));
      const int *_slice_array_inputs[] = {pl_index};
      int *_slice_array_outputs[] = {_temp_arr, temp_arr_size};
      slice_index(_slice_array_inputs, _start_index, _end_index, size,
                  _slice_array_outputs);
      int _index_size = _temp_arr_size[0];
      double _prev_low = 0;
      double _prev_hist = 0;
      if (_index_size >= 2)
      {
        for (int z = 1; z < _index_size; z++)
        {
          int _prev_index = _temp_arr[z - 1];
          int cur_index = _temp_arr[z];
          _prev_hist = histogram[_temp_arr[0]];
          _prev_low = low[_temp_arr[0]];
          if (histogram[_prev_index] < histogram[cur_index] &&
              low[_prev_index] > low[cur_index])
          {
            bull[cur_index] = TI_BULL;
          }
          else if (_prev_hist != 0 && _prev_low != 0)
          {
            if (_prev_hist < histogram[cur_index] &&
                _prev_low > low[cur_index])
            {
              bull[cur_index] = TI_BULL;
            }
          }
        }
      }

      free(_temp_arr);
      free(_temp_arr_size);
    }

    free(temp_arr);
    free(temp_arr_size);
  }

  for (int i = 1; i < pl_count; i++)
  {
    int start_index = pl_index[i - 1];
    int end_index = pl_index[i];
    int *temp_arr = (int *)calloc((size_t)size, sizeof(int));
    int *temp_arr_size = (int *)calloc((size_t)1, sizeof(int));
    const int *slice_array_inputs[] = {ph_index};
    int *slice_array_outputs[] = {temp_arr, temp_arr_size};
    slice_index(slice_array_inputs, start_index, end_index, size,
                slice_array_outputs);
    int index_size = temp_arr_size[0];
    double prev_high = 0;
    double prev_hist = 0;
    if (index_size >= 2)
    {
      for (int z = 1; z < index_size; z++)
      {
        int prev_index = temp_arr[z - 1];
        int cur_index = temp_arr[z];
        prev_hist = histogram[temp_arr[0]];
        prev_high = high[temp_arr[0]];
        if (histogram[prev_index] > histogram[cur_index] &&
            high[prev_index] < high[cur_index])
        {
          bear[cur_index] = TI_BEAR;
        }
        else if (prev_hist != 0 && prev_high != 0)
        {
          if (prev_hist > histogram[cur_index] && prev_high < high[cur_index])
          {
            bear[cur_index] = TI_BEAR;
          }
        }
      }
    }
    if (i == pl_count - 1)
    {
      int _start_index = pl_index[i];
      int _end_index = size - 1;
      int *_temp_arr = calloc((size_t)size, sizeof(int));
      int *_temp_arr_size = calloc((size_t)1, sizeof(int));
      const int *_slice_array_inputs[] = {ph_index};
      int *_slice_array_outputs[] = {_temp_arr, temp_arr_size};
      slice_index(_slice_array_inputs, _start_index, _end_index, size,
                  _slice_array_outputs);
      int _index_size = _temp_arr_size[0];
      double _prev_high = 0;
      double _prev_hist = 0;
      if (_index_size >= 2)
      {
        for (int z = 1; z < _index_size; z++)
        {
          int _prev_index = _temp_arr[z - 1];
          int cur_index = cur_index;
          _prev_hist = histogram[_temp_arr[0]];
          _prev_high = high[_temp_arr[0]];
          if (histogram[_prev_index] > histogram[cur_index] &&
              high[_prev_index] < high[cur_index])
          {
            bear[cur_index] = TI_BEAR;
          }
          else if (_prev_hist != 0 && prev_high != 0)
          {
            if (_prev_hist > histogram[cur_index] &&
                _prev_high < high[cur_index])
            {
              bear[cur_index] = TI_BEAR;
            }
          }
        }
      }

      free(_temp_arr);
      free(_temp_arr_size);
    }

    free(temp_arr);
    free(temp_arr_size);
  }

  free(nz_macd);
  free(nz_signal);
  free(nz_hist);
  free(histogram);
  free(ph_index);
  free(pl_index);

  return TI_OKAY;
}
