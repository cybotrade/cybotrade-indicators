/*
 * Tulip Indicators
 * https://tulipindicators.org/
 * Copyright (c) 2010-2018 Tulip Charts LLC
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

int ti_di_dx_start(TI_REAL const *options)
{
    UNUSED(options);
    return 0;
}

int ti_di_dx(int size, TI_REAL const *const *inputs, TI_REAL const *options,
             TI_REAL *const *outputs)
{
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];

    const int period = (int)options[0];

    TI_REAL *DX = outputs[0];
    TI_REAL *DIPlus = outputs[1];
    TI_REAL *DIMinus = outputs[2];

    if (period < 1)
        return TI_INVALID_OPTION;

    double *SmoothedTrueRange = (double *)calloc((size_t)size, sizeof(double));
    double *SmoothedDirectionalMovementPlus =
        (double *)calloc((size_t)size, sizeof(double));
    double *SmoothedDirectionalMovementMinus =
        (double *)calloc((size_t)size, sizeof(double));

    for (int i = 1; i < size; i++)
    {
        double TrueRange =
            fmax(fmax(high[i] - low[i], fabs(high[i] - not_zero(close[i - 1], 0))),
                 fabs(low[i] - not_zero(close[i - 1], 0)));

        double DirectionalMovementPlus =
            (high[i] - not_zero(high[i - 1], 0) > not_zero(low[i - 1], 0) - low[i])
                ? fmax(high[i] - not_zero(high[i - 1], 0), 0)
                : 0;

        double DirectionalMovementMinus =
            not_zero(low[i - 1], 0) - low[i] > high[i] - not_zero(high[i - 1], 0)
                ? fmax(not_zero(low[i - 1], 0) - low[i], 0)
                : 0;

        SmoothedTrueRange[i] =
            not_zero(SmoothedTrueRange[i - 1], 0) -
            (not_zero(SmoothedTrueRange[i - 1], 0) / (double)period) + TrueRange;

        SmoothedDirectionalMovementPlus[i] =
            not_zero(SmoothedDirectionalMovementPlus[i - 1], 0) -
            (not_zero(SmoothedDirectionalMovementPlus[i - 1], 0) / (double)period) +
            DirectionalMovementPlus;

        SmoothedDirectionalMovementMinus[i] =
            not_zero(SmoothedDirectionalMovementMinus[i - 1], 0) -
            (not_zero(SmoothedDirectionalMovementMinus[i - 1], 0) /
             (double)period) +
            DirectionalMovementMinus;

        DIPlus[i] =
            (float)SmoothedDirectionalMovementPlus[i] / SmoothedTrueRange[i] * 100;

        DIMinus[i] =
            (float)SmoothedDirectionalMovementMinus[i] / SmoothedTrueRange[i] * 100;
    }

    for (int i = 0; i < size; i++)
        DX[i] =
            (float)fabs(DIPlus[i] - DIMinus[i]) / (DIPlus[i] + DIMinus[i]) * 100;

    free(SmoothedTrueRange);
    free(SmoothedDirectionalMovementPlus);
    free(SmoothedDirectionalMovementMinus);

    return TI_OKAY;
}
