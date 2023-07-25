#ifndef __UTILS_H__
#define __UTILS_H__

#include "../indicators.h"

// This is only used to suppress -Wunused-parameter warnings.
#define UNUSED(x) (void)(x)

double max_value(double arr[], int n);
double min_value(double arr[], int n);
double not_zero(double x, double y);
void slice_index(int const *const *inputs, int start_index, int end_index,
                 int input_size, int *const *outputs);
void slice_array(double const *const *inputs, int start_index, int end_index,
                 int input_size, double *const *outputs);
void filter_array(double const *const *inputs, int input_size,
                  double *const *outputs);
void get_diver_pivot_low(double const *const *inputs, int size, int left_bar,
                         int right_bar, double *const *outputs);
void get_diver_pivot_high(double const *const *inputs, int size, int left_bar,
                          int right_bar, double *const *outputs);

#endif /*__UTILS_H__*/
