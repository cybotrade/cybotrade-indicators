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
#include <stdbool.h>

int ti_psar_start(TI_REAL const *options)
{
    (void)options;
    return 0;
}

int ti_psar(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs)
{
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];

    const TI_REAL accel_start = options[0];
    const TI_REAL accel_step = options[1];
    const TI_REAL accel_max = options[2];

    TI_REAL *psar = outputs[0];

    if (accel_start <= 0)
        return TI_INVALID_OPTION;
    if (accel_step <= 0)
        return TI_INVALID_OPTION;
    if (accel_max <= accel_step)
        return TI_INVALID_OPTION;
    if (size < 2)
        return TI_OKAY;

    for (int i = 0; i < size; i++)
    {
        psar[i] = close[i];
    }

    double hp = high[0];
    double lp = low[0];
    bool bull = true;
    double af = accel_start;

    for (int i = 2; i < size; i++)
    {
        if (bull == true)
        {
            psar[i] = psar[i - 1] + af * (hp - psar[i - 1]);
        }
        else
        {
            psar[i] = psar[i - 1] + af * (lp - psar[i - 1]);
        }
        bool reverse = false;
        if (bull == true)
        {
            if (low[i] < psar[i])
            {
                bull = false;
                reverse = true;
                psar[i] = hp;
                lp = low[i];
                af = accel_start;
            }
        }
        else
        {
            if (high[i] > psar[i])
            {
                bull = true;
                reverse = true;
                psar[i] = lp;
                hp = high[i];
                af = accel_start;
            }
        }
        if (reverse == false)
        {
            if (bull == true)
            {
                if (high[i] > hp)
                {
                    hp = high[i];
                    af = fmin(af + accel_step, accel_max);
                }
                if (low[i - 1] < psar[i])
                {
                    psar[i] = low[i - 1];
                }
                if (low[i - 2] < psar[i])
                {
                    psar[i] = low[i - 2];
                }
            }

            else
            {
                if (low[i] < lp)
                {
                    lp = low[i];
                    af = fmin(af + accel_step, accel_max);
                }
                if (high[i - 1] > psar[i])
                {
                    psar[i] = high[i - 1];
                }
                if (high[i - 2] > psar[i])
                {
                    psar[i] = high[i - 2];
                }
            }
        }
    }

    return TI_OKAY;
}
