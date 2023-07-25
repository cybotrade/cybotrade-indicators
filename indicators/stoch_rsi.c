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

int ti_stoch_rsi_start(TI_REAL const *options)
{
    UNUSED(options);
    return 0;
}

int ti_stoch_rsi(int size, TI_REAL const *const *inputs,
                   TI_REAL const *options, TI_REAL *const *outputs)
{

    const TI_REAL *close = inputs[0];

    TI_REAL *k = outputs[0];
    TI_REAL *d = outputs[1];
    const int smoothk = (int)options[0];
    const int smoothd = (int)options[1];
    const int rsi_period = (int)options[2];
    const int stoch_period = (int)options[3];
    if (rsi_period < 1, stoch_period < 1, smoothk < 1, smoothd < 1)
        return TI_INVALID_OPTION;

    // get rsi data
    const double nz_rsi_options[] = {rsi_period};
    double *nz_rsi = malloc((unsigned int)size * sizeof(double));
    assert(nz_rsi != 0);
    const double *nz_rsi_inputs[] = {close};
    double *nz_rsi_outputs[] = {nz_rsi};
    int error = ti_rsi(size, nz_rsi_inputs, nz_rsi_options, nz_rsi_outputs);
    assert(error == TI_OKAY);

    double *rsi = malloc((unsigned int)size * sizeof(double));
    const double *rsi_inputs[] = {nz_rsi};
    double *rsi_outputs[] = {rsi};
    int range = rsi_period;
    double value = 0;
    const double rsi_options[] = {value, range};
    int error2 = ti_unshift(size, rsi_inputs, rsi_options, rsi_outputs);
    assert(error2 == TI_OKAY);

    const double nz_stoch_options[] = {stoch_period, smoothk, smoothd};
    double *nz_stoch1 = malloc((unsigned int)size * sizeof(double));
    double *nz_stoch2 = malloc((unsigned int)size * sizeof(double));
    assert(nz_stoch1 != 0);
    const double *nz_stoch_inputs[] = {rsi, rsi, rsi};
    double *nz_stoch_outputs[] = {nz_stoch1, nz_stoch2};
    int error44 =
        ti_stoch(size, nz_stoch_inputs, nz_stoch_options, nz_stoch_outputs);
    assert(error44 == TI_OKAY);

    const double *stk1_inputs[] = {nz_stoch1};
    double *stk1_outputs[] = {k};
    int range1 = stoch_period + smoothk + smoothd - 3;
    double value1 = 0;
    const double stk1_options[] = {value1, range1};
    int error4444 = ti_unshift(size, stk1_inputs, stk1_options, stk1_outputs);
    assert(error4444 == TI_OKAY);

    const double *stk2_inputs[] = {nz_stoch2};
    double *stk2_outputs[] = {d};
    int range2 = stoch_period + smoothd + smoothk - 3;
    double value2 = 0;
    const double stk2_options[] = {value2, range2};
    int error555 = ti_unshift(size, stk2_inputs, stk2_options, stk2_outputs);
    assert(error555 == TI_OKAY);

    free(nz_rsi);
    free(rsi);
    free(nz_stoch1);
    free(nz_stoch2);

    return TI_OKAY;
}
