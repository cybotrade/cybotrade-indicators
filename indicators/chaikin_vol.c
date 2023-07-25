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

int ti_chaikin_vol_start(TI_REAL const *options)
{
    UNUSED(options);
    return 0;
}

int ti_chaikin_vol(int size, TI_REAL const *const *inputs,
              TI_REAL const *options, TI_REAL *const *outputs)
{
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];

    TI_REAL *cvi = outputs[0];
    const int ema_period = (int)options[0];
    const int roc_period = (int)options[1];
    if (ema_period < 1, roc_period < 1)
        return TI_INVALID_OPTION;

    double *diff = (double *)calloc((size_t)size, sizeof(double));
    for (int i = 0; i < size; i++)
    {
        diff[i] = high[i] - low[i];
    }

    // get atr data
    const double ema_options[] = {ema_period};
    double *ema = malloc((unsigned int)size * sizeof(double));
    assert(ema != 0);
    const double *ema_inputs[] = {diff};
    double *ema_outputs[] = {ema};
    int error = ti_ema(size, ema_inputs, ema_options, ema_outputs);
    assert(error == TI_OKAY);

    // refill the missing zero in atr
    double *nz_roc_ema = (double *)calloc((size_t)size, sizeof(double));
    const double *nz_roc_ema_inputs[] = {ema};
    double *nz_roc_ema_outputs[] = {nz_roc_ema};
    const double nz_roc_ema_options[] = {roc_period};
    int error1 = ti_roc(size, nz_roc_ema_inputs, nz_roc_ema_options, nz_roc_ema_outputs);
    assert(error1 == TI_OKAY);

    const double *roc_ema_inputs[] = {nz_roc_ema};
    double *roc_ema_outputs[] = {cvi};
    int range = roc_period;
    double value = 0;
    const double roc_ema_options[] = {value, range};
    int error2 = ti_unshift(size, roc_ema_inputs, roc_ema_options, roc_ema_outputs);
    assert(error2 == TI_OKAY);

    for (int i = 0; i < size; i++)
    {
        cvi[i] = cvi[i] * 100.0;
    }

    free(diff);
    free(nz_roc_ema);
    free(ema);

    return TI_OKAY;
}
