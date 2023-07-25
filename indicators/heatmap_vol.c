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

int ti_heatmap_vol_start(TI_REAL const *options)
{
  UNUSED(options);
  return 0;
}

double calc_average(double arr[], int size)
{
  double total = 0;
  int count = 0;
  for (int j = 0; j < size; j++)
  {
    total += arr[j];
    count += 1;
  }
  double avg = total / (double)count;
  return avg;
}

double pstdev(double arr[], int input_size, double mean, int period)
{
  int summation_size = input_size + 1;
  double *summation = (double *)calloc((size_t)summation_size, sizeof(double));
  for (int j = 1; j < summation_size; j++)
  {
    double sampleMinusMean = not_zero(arr[j - 1], 0) - mean;
    summation[j] = summation[j - 1] + sampleMinusMean * sampleMinusMean;
  }

  double std = sqrt((float)summation[summation_size - 1] / (float)period);
  free(summation);

  return std;
}

int ti_heatmap_vol(int size, TI_REAL const *const *inputs,
                   TI_REAL const *options, TI_REAL *const *outputs)
{
  const TI_REAL *volume = inputs[0];

  double *volume_color = outputs[0];

  const int length = (int)options[0];
  const int std_length = (int)options[1];
  const double thresholdExtraHigh = (double)options[2];
  const double thresholdHigh = (double)options[3];
  const double thresholdMedium = (double)options[4];
  const double thresholdNormal = (double)options[5];

  if (length < 1)
    return TI_INVALID_OPTION;

  for (int i = 0; i < size; i++)
    volume_color[i] = 0;

  for (int i = length - 1; i < size; i++)
  {
    int start_index = i - (length - 1);
    int end_index = i;
    int temp_size = end_index - start_index + 1;
    double *temp_arr = (double *)calloc((size_t)temp_size, sizeof(double));
    const double *slice_array_inputs[] = {volume};
    double *slice_array_outputs[] = {temp_arr};
    slice_array(slice_array_inputs, start_index, end_index, size,
                slice_array_outputs);

    const double nz_mean_options[] = {length};
    double *nz_mean = malloc((unsigned int)temp_size * sizeof(double));
    assert(nz_mean != 0);
    const double *nz_mean_inputs[] = {temp_arr};
    double *nz_mean_outputs[] = {nz_mean};
    int error =
        ti_sma(temp_size, nz_mean_inputs, nz_mean_options, nz_mean_outputs);
    assert(error == TI_OKAY);

    double *mean = malloc((unsigned int)temp_size * sizeof(double));
    const double *mean_inputs[] = {nz_mean};
    double *mean_outputs[] = {mean};
    int range = length - 1;
    double value = 0;
    const double mean_options[] = {value, range};
    int error1 = ti_unshift(temp_size, mean_inputs, mean_options, mean_outputs);
    assert(error1 == TI_OKAY);

    double mean_dev = calc_average(temp_arr, temp_size);
    double std = pstdev(temp_arr, temp_size, mean_dev, std_length);
    double stdbar = (volume[i] - mean[temp_size - 1]) / std;

    // Free all the memory allocated in this function call
    free(nz_mean);
    free(mean);
    free(temp_arr);

    if (stdbar > thresholdExtraHigh)
      volume_color[i] = TI_HEATMAP_EXTRAHIGH;
    else if (stdbar > thresholdHigh)
      volume_color[i] = TI_HEATMAP_HIGH;
    else if (stdbar > thresholdMedium)
      volume_color[i] = TI_HEATMAP_MEDIUM;
    else if (stdbar > thresholdNormal)
      volume_color[i] = TI_HEATMAP_NORMAL;
    else
      volume_color[i] = TI_HEATMAP_LOW;
  }

  return TI_OKAY;
}
