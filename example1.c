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

#include "indicators.h"
#include <stdio.h>
#include <stdlib.h>

void print_array(const double *p, const int size)
{
    int i;
    for (i = 0; i < size; ++i)
    {
        printf("%.4f,", p[i]);
    }
    printf("\n");
}

int main()
{
    const double high[] = {23509.68, 23459.89, 23647.68, 23223.32, 23472.86,
                           23354.36, 23402, 24245, 23933.25, 24226,
                           24918.54, 24456.5, 24888, 25047.56, 25211.32};

    const double low[] = {22850, 22654.37, 22681.22, 22400, 22586.95,
                          22909.52, 22844.62, 23154.25, 22865, 22664.69,
                          23852.13, 23583, 24291.22, 24144, 23773.22};

    const double close[] = {23268.01, 22987.79, 22818.37, 22622.98, 23312.42,
                            22954.21, 23174.39, 23810, 23149.95, 23954.05,
                            23934.39, 24403.68, 24441.38, 24305.24, 24094.82};


    const int input_length = sizeof(close) / sizeof(double);

    // printf("We have %d bars of input data.\n", input_length);
    // print_array(open, input_length);

    const double options[] = {2, 2};
    // printf("Our option array is: ");
    // print_array(options, sizeof(options) / sizeof(double));

    const int start = ti_ssl_start(options);
    // printf("The start amount is: %d\n", start);

    const int output_length = input_length - start;
    double *data_out1 = (double *)calloc(input_length, sizeof(double));
    double *data_out2 = (double *)calloc(input_length, sizeof(double));
    double *data_out3 = (double *)calloc(input_length, sizeof(double));
    double *data_out4 = (double *)calloc(input_length, sizeof(double));
    double *data_out5 = (double *)calloc(input_length, sizeof(double));
    double *data_out6 = (double *)calloc(input_length, sizeof(double));
    // double *data_out7 = (double *)calloc(input_length, sizeof(double));
    assert(data_out1 != 0);
    // printf("The output length is: %d\n", output_length);

    const double *all_inputs[] = {high, low, close};
    double *all_outputs[] = {data_out1, data_out2, data_out3, data_out4, data_out5, data_out6}; //, data_out7};
    int error = ti_ssl(input_length, all_inputs, options, all_outputs);
    assert(error == TI_OKAY);

    printf("The output data is: \n");
    print_array(data_out1, input_length);
    print_array(data_out2, input_length);
    print_array(data_out3, input_length);
    print_array(data_out4, input_length);
    print_array(data_out5, input_length);
    print_array(data_out6, input_length);
    // print_array(data_out7, input_length);
    return 0;
}
