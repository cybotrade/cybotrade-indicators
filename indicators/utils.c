#include "utils.h"

double max_value(double arr[], int n)
{
  int i;

  // Initialize maximum element
  double max_value = arr[0];

  // Traverse array elements from second and
  // compare every element with current max
  for (i = 1; i < n; i++)
    if (arr[i] > max_value)
      max_value = arr[i];

  return max_value;
}

double min_value(double arr[], int n)
{
  int i;

  // Initialize min element
  double min_value = arr[0];

  // Traverse array elements from second and
  // compare every element with current min_value
  for (i = 1; i < n; i++)
    if (arr[i] < min_value)
      min_value = arr[i];

  return min_value;
}

double not_zero(double x, double y) { return isnan(x) ? y : x; }

void slice_index(int const *const *inputs, int start_index, int end_index,
                 int input_size, int *const *outputs)
{
  const int *new_arr = inputs[0];
  int *output = outputs[0];
  int *size = outputs[1];
  int x = 0;
  int count = 0;
  for (int i = 0; i < input_size; i++)
  {
    if (new_arr[i] > start_index && new_arr[i] < end_index && new_arr[i] != 0)
    {
      output[x++] = new_arr[i];
      count += 1;
    }
  }
  size[0] = count;
}

void slice_array(double const *const *inputs, int start_index, int end_index,
                 int input_size, double *const *outputs)
{
  const double *new_arr = inputs[0];
  double *output = outputs[0];
  int x = 0;
  for (int i = 0; i < input_size; i++)
  {
    if (i >= start_index && i <= end_index)
    {
      output[x++] = new_arr[i];
    }
  }
}

void filter_array(double const *const *inputs, int input_size,
                  double *const *outputs)
{
  const double *new_arr = inputs[0];
  const double *new_arr1 = inputs[1];
  const double *new_arr2 = inputs[2];
  double *output1 = outputs[0];
  double *output2 = outputs[1];
  double *output3 = outputs[2];
  int x = 0;
  int y = 0;
  int z = 0;
  for (int i = 0; i < input_size; i++)
  {
    if (new_arr[i] != 0)
    {
      output1[x++] = new_arr[i];
      output2[y++] = new_arr1[i];
      output3[z++] = new_arr2[i];
    }
  }
}

void get_diver_pivot_low(double const *const *inputs, int size, int left_bar,
                         int right_bar, double *const *outputs)
{
  const double *low = inputs[0];
  const double *div_data = inputs[1];
  double *pl_index = outputs[0];
  double *pl_div_data = outputs[1];
  double *pl_low = outputs[2];
  double *pl_size = outputs[3];
  int x = 0;
  for (int i = left_bar + right_bar; i < size; i++)
  {
    double middle_point = div_data[i - right_bar];
    int start_index = i - (left_bar + right_bar);
    int end_index = i;
    int temp_size = end_index - start_index + 1;
    double *temp_arr = (double *)calloc((size_t)temp_size, sizeof(double));
    const double *slice_array_inputs[] = {div_data};
    double *slice_array_outputs[] = {temp_arr};
    slice_array(slice_array_inputs, start_index, end_index, size,
                slice_array_outputs);
    double min_temp_arr = min_value(temp_arr, temp_size);
    if (min_temp_arr == middle_point)
    {
      pl_index[i] = (i - right_bar);
      pl_div_data[i] = div_data[i - right_bar];
      pl_low[i] = low[i - right_bar];
      x += 1;
    }

    free(temp_arr);
  }
  pl_size[0] = (double)x;
}

void get_diver_pivot_high(double const *const *inputs, int size, int left_bar,
                          int right_bar, double *const *outputs)
{
  const double *high = inputs[0];
  const double *div_data = inputs[1];
  double *ph_index = outputs[0];
  double *ph_div_data = outputs[1];
  double *ph_high = outputs[2];
  double *ph_size = outputs[3];
  int x = 0;
  for (int i = left_bar + right_bar; i < size; i++)
  {
    double middle_point = div_data[i - right_bar];
    int start_index = i - (left_bar + right_bar);
    int end_index = i;
    int temp_size = end_index - start_index + 1;
    double *temp_arr = (double *)calloc((size_t)temp_size, sizeof(double));
    const double *slice_array_inputs[] = {div_data};
    double *slice_array_outputs[] = {temp_arr};
    slice_array(slice_array_inputs, start_index, end_index, size,
                slice_array_outputs);
    double max_temp_arr = max_value(temp_arr, temp_size);

    if (max_temp_arr == middle_point)
    {
      ph_index[i] = (double)(i - right_bar);
      ph_div_data[i] = div_data[i - right_bar];
      ph_high[i] = high[i - right_bar];
      x += 1;
    }

    free(temp_arr);
  }
  ph_size[0] = (double)x;
}
