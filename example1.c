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
    const double open[] = {23296.36, 23266.9, 22985.93, 22816.91, 22622.41,
                           23313.56, 22954.21, 23174.39, 23810.98, 23151.32,
                           23954.05, 23933.09, 24401.7, 24443.06, 24305.25,
                           24093.04, 23856.15, 23342.66, 23191.45, 20834.39,
                           21140.07, 21516.7, 21400.75, 21529.11, 21368.05,
                           21559.04, 20239.14, 20037.6, 19555.61, 20287.2,
                           19813.03, 20048.44, 20132.64, 19950.98, 19832.45,
                           20000.3, 19795.34, 18790.61, 19292.85, 19320.54,
                           21361.62, 21647.21, 21826.87, 22395.44, 20173.62,
                           20227.17, 19701.88, 19803.3, 20112.61, 19417.45,
                           19537.02, 18874.31, 18461.36, 19401.63, 19288.57,
                           18921.99, 18809.13, 19226.68, 19078.1, 19412.82,
                           19590.54, 19422.61, 19312.24, 19057.74, 19629.08,
                           20337.82, 20158.26, 19960.67, 19530.09, 19416.52};

    const double high[] = {23509.68, 23459.89, 23647.68, 23223.32, 23472.86,23354.36, 23402, 24245, 23933.25,24226,24918.54, 24456.5, 24888, 25047.56, 25211.32};

    const double low[] = {22850, 22654.37, 22681.22, 22400, 22586.95,22909.52, 22844.62, 23154.25, 22865, 22664.69,23852.13, 23583, 24291.22, 24144, 23773.22};

    const double close[] = {23268.01, 22987.79, 22818.37, 22622.98, 23312.42,22954.21, 23174.39, 23810, 23149.95, 23954.05,23934.39, 24403.68, 24441.38, 24305.24, 24094.82};

    const double volume[] = {144210.16219, 158073.28225, 145948.80995, 154854.67016, 175251.69749,
                             83911.80307, 88890.00877, 170958.44152, 143182.50858, 208916.54953,
                             249759.79557, 174207.5704, 152852.25435, 151206.14473, 242539.54758,
                             179324.94821, 210668.68766, 144185.97011, 283995.87747, 183041.68363,
                             159200.6841, 222222.04526, 200967.77164, 174383.22046, 169915.78301,
                             273811.61955, 162582.46032, 139307.95976, 210509.49545, 256634.35529,
                             276946.60765, 245289.97263, 245986.6033, 146639.03204, 145588.77893,
                             222543.01057, 356315.05718, 287394.7788, 262813.28273, 428919.74652,
                             307997.33504, 280702.55149, 395395.61828, 431915.03333, 340826.40151,
                             333069.76076, 283791.07064, 179350.24338, 254217.46904, 380512.40306,
                             324098.3286, 385034.10021, 379321.72111, 385886.91829, 239496.56746,
                             191191.4492, 439239.21943, 593260.74161, 521385.45547, 406424.93256,
                             444322.9534, 165625.13959, 206812.47032, 293585.75212, 327012.00127,
                             312239.75224, 320122.1702, 220874.83913, 102480.09842, 113900.82681};
    const int input_length = sizeof(high) / sizeof(double);

    // printf("We have %d bars of input data.\n", input_length);
    // print_array(open, input_length);

    const double options[] = {2, 1.5};
    // printf("Our option array is: ");
    // print_array(options, sizeof(options) / sizeof(double));

    const int start = ti_supertrend_start(options);
    // printf("The start amount is: %d\n", start);

    const int output_length = input_length - start;
    double *data_out1 = malloc((unsigned int)output_length * sizeof(double));
    double *data_out2 = (double *)calloc(input_length, sizeof(double));
    double *data_out3 = (double *)calloc(input_length, sizeof(double));
    double *data_out4 = (double *)calloc(input_length, sizeof(double));
    assert(data_out1 != 0);
    // printf("The output length is: %d\n", output_length);

    const double *all_inputs[] = {high, low, close};
    double *all_outputs[] = {data_out1, data_out2, data_out3, data_out4};
    int error = ti_supertrend(input_length, all_inputs, options, all_outputs);
    assert(error == TI_OKAY);

    printf("The output data is: \n");
    print_array(data_out1, input_length);
    print_array(data_out2, input_length);
    print_array(data_out3, input_length);
    print_array(data_out4, input_length);

    return 0;
}