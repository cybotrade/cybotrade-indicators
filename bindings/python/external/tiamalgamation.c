/*
 * TULIP INDICATORS AMALGAMATION
 * This is all of Tulip Indicators in one file.
 * To get the original sources, go to https://tulipindicators.org
 */


/*
 * Tulip Indicators
 * https://tulipindicators.org/
 * Copyright (c) 2010-2020 Tulip Charts LLC
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

#ifndef __TI_INDICATORS_H__
#define __TI_INDICATORS_H__


/*
 *
 * Version 0.9.2
 * Header Build 1688954421
 *
 */

/*
 *
 * This file is generated. Do not modify directly.
 *
 */




#define TI_VERSION "0.9.2"
#define TI_BUILD 1688954421



#ifndef TI_SKIP_SYSTEM_HEADERS
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

const char *ti_version(void);
long int ti_build(void);
int ti_indicator_count(void);

#define TI_REAL double

#define TI_INDICATOR_COUNT 125 /* Total number of indicators. */

#define TI_OKAY 0
#define TI_INVALID_OPTION 1
#define TI_OUT_OF_MEMORY 2

// Custom indicator buy/sell signal
#define TI_NOTHING 0
#define TI_BUY 1
#define TI_SELL -1

// Custom indicator green/red region
#define TI_GREEN 1
#define TI_RED -1

// Heatmap Volume Output
#define TI_HEATMAP_LOW 0
#define TI_HEATMAP_NORMAL 1
#define TI_HEATMAP_MEDIUM 2
#define TI_HEATMAP_HIGH 3
#define TI_HEATMAP_EXTRAHIGH 4

// Divergence Output
#define TI_BULL 1
#define TI_BEAR -1

#define TI_TYPE_OVERLAY                                                        \
  1 /* These have roughly the same range as the input data. */
#define TI_TYPE_INDICATOR 2 /* Everything else (e.g. oscillators). */
#define TI_TYPE_MATH                                                           \
  3 /* These aren't so good for plotting, but are useful with formulas. */
#define TI_TYPE_SIMPLE                                                         \
  4 /* These apply a simple operator (e.g. addition, sin, sqrt). */
#define TI_TYPE_COMPARATIVE                                                    \
  5 /* These are designed to take inputs from different securities. i.e.       \
       compare stock A to stock B.*/

#define TI_MAXINDPARAMS                                                        \
  16 /* No indicator will use more than this many inputs, options, or outputs. \
      */

typedef int (*ti_indicator_start_function)(TI_REAL const *options);
typedef int (*ti_indicator_function)(int size, TI_REAL const *const *inputs,
                                     TI_REAL const *options,
                                     TI_REAL *const *outputs);

struct ti_stream;
typedef struct ti_stream ti_stream;
typedef int (*ti_indicator_stream_new)(TI_REAL const *options,
                                       ti_stream **stream);
typedef int (*ti_indicator_stream_run)(ti_stream *stream, int size,
                                       TI_REAL const *const *inputs,
                                       TI_REAL *const *outputs);
typedef void (*ti_indicator_stream_free)(ti_stream *stream);

typedef struct ti_indicator_info {
  const char *name;
  const char *full_name;
  ti_indicator_start_function start;
  ti_indicator_function indicator;
  ti_indicator_function indicator_ref;
  int type, inputs, options, outputs;
  const char *input_names[TI_MAXINDPARAMS];
  const char *option_names[TI_MAXINDPARAMS];
  const char *output_names[TI_MAXINDPARAMS];
  ti_indicator_stream_new stream_new;
  ti_indicator_stream_run stream_run;
  ti_indicator_stream_free stream_free;
} ti_indicator_info;

/*Complete array of all indicators. Last element is 0,0,0,0...*/
extern ti_indicator_info ti_indicators[];

/*Searches for an indicator by name. Returns 0 if not found.*/
const ti_indicator_info *ti_find_indicator(const char *name);

int ti_stream_run(ti_stream *stream, int size, TI_REAL const *const *inputs,
                  TI_REAL *const *outputs);
ti_indicator_info *ti_stream_get_info(ti_stream *stream);
int ti_stream_get_progress(ti_stream *stream);
void ti_stream_free(ti_stream *stream);

/*
 *
 *
 *
 *
 *
 *        All indicators below, sorted alphabetically.
 *
 *
 *
 *
 *
 */

/* Vector Absolute Value */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: abs */
#define TI_INDICATOR_ABS_INDEX 0
int ti_abs_start(TI_REAL const *options);
int ti_abs(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Vector Arccosine */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: acos */
#define TI_INDICATOR_ACOS_INDEX 1
int ti_acos_start(TI_REAL const *options);
int ti_acos(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Accumulation/Distribution Line */
/* Type: indicator */
/* Input arrays: 4    Options: 0    Output arrays: 1 */
/* Inputs: high, low, close, volume */
/* Options: none */
/* Outputs: ad */
#define TI_INDICATOR_AD_INDEX 2
int ti_ad_start(TI_REAL const *options);
int ti_ad(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Vector Addition */
/* Type: simple */
/* Input arrays: 2    Options: 0    Output arrays: 1 */
/* Inputs: value_one, value_two */
/* Options: none */
/* Outputs: add */
#define TI_INDICATOR_ADD_INDEX 3
int ti_add_start(TI_REAL const *options);
int ti_add(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Accumulation/Distribution Oscillator */
/* Type: indicator */
/* Input arrays: 4    Options: 2    Output arrays: 1 */
/* Inputs: high, low, close, volume */
/* Options: short_period, long_period */
/* Outputs: adosc */
#define TI_INDICATOR_ADOSC_INDEX 4
int ti_adosc_start(TI_REAL const *options);
int ti_adosc(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Average Directional Movement Index */
/* Type: indicator */
/* Input arrays: 2    Options: 1    Output arrays: 1 */
/* Inputs: high, low */
/* Options: period[14] */
/* Outputs: adx */
#define TI_INDICATOR_ADX_INDEX 5
int ti_adx_start(TI_REAL const *options);
int ti_adx(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Average Directional Movement Rating */
/* Type: indicator */
/* Input arrays: 2    Options: 1    Output arrays: 1 */
/* Inputs: high, low */
/* Options: period */
/* Outputs: adxr */
#define TI_INDICATOR_ADXR_INDEX 6
int ti_adxr_start(TI_REAL const *options);
int ti_adxr(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Andean Osc */
/* Type: overlay */
/* Input arrays: 2    Options: 2    Output arrays: 3 */
/* Inputs: open, close */
/* Options: period[50], signal_length[9] */
/* Outputs: ?bull_data, ?bear_data, ao_data */
#define TI_INDICATOR_ANDEAN_OSC_INDEX 7
int ti_andean_osc_start(TI_REAL const *options);
int ti_andean_osc(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Awesome Oscillator */
/* Type: indicator */
/* Input arrays: 2    Options: 0    Output arrays: 1 */
/* Inputs: high, low */
/* Options: none */
/* Outputs: ao */
#define TI_INDICATOR_AO_INDEX 8
int ti_ao_start(TI_REAL const *options);
int ti_ao(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Absolute Price Oscillator */
/* Type: indicator */
/* Input arrays: 1    Options: 2    Output arrays: 1 */
/* Inputs: real */
/* Options: short_period, long_period */
/* Outputs: apo */
#define TI_INDICATOR_APO_INDEX 9
int ti_apo_start(TI_REAL const *options);
int ti_apo(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Aroon */
/* Type: indicator */
/* Input arrays: 2    Options: 1    Output arrays: 2 */
/* Inputs: high, low */
/* Options: period */
/* Outputs: aroon_down, aroon_up */
#define TI_INDICATOR_AROON_INDEX 10
int ti_aroon_start(TI_REAL const *options);
int ti_aroon(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Aroon Oscillator */
/* Type: indicator */
/* Input arrays: 2    Options: 1    Output arrays: 1 */
/* Inputs: high, low */
/* Options: period */
/* Outputs: aroonosc */
#define TI_INDICATOR_AROONOSC_INDEX 11
int ti_aroonosc_start(TI_REAL const *options);
int ti_aroonosc(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Vector Arcsine */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: asin */
#define TI_INDICATOR_ASIN_INDEX 12
int ti_asin_start(TI_REAL const *options);
int ti_asin(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Vector Arctangent */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: atan */
#define TI_INDICATOR_ATAN_INDEX 13
int ti_atan_start(TI_REAL const *options);
int ti_atan(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Average True Range */
/* Type: indicator */
/* Input arrays: 3    Options: 1    Output arrays: 1 */
/* Inputs: high, low, close */
/* Options: period[14] */
/* Outputs: atr */
#define TI_INDICATOR_ATR_INDEX 14
int ti_atr_start(TI_REAL const *options);
int ti_atr(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
int ti_atr_ref(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
int ti_atr_stream_new(TI_REAL const *options, ti_stream **stream);
int ti_atr_stream_run(ti_stream *stream, int size, TI_REAL const *const *inputs, TI_REAL *const *outputs);
void ti_atr_stream_free(ti_stream *stream);
/* Average Price */
/* Type: overlay */
/* Input arrays: 4    Options: 0    Output arrays: 1 */
/* Inputs: open, high, low, close */
/* Options: none */
/* Outputs: avgprice */
#define TI_INDICATOR_AVGPRICE_INDEX 15
int ti_avgprice_start(TI_REAL const *options);
int ti_avgprice(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Bollinger Bands */
/* Type: overlay */
/* Input arrays: 1    Options: 2    Output arrays: 3 */
/* Inputs: real */
/* Options: period[20], stddev[2] */
/* Outputs: bbands_lower(ohlcv), bbands_middle(ohlcv), bbands_upper(ohlcv) */
#define TI_INDICATOR_BBANDS_INDEX 16
int ti_bbands_start(TI_REAL const *options);
int ti_bbands(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Boom Pro */
/* Type: overlay */
/* Input arrays: 1    Options: 5    Output arrays: 2 */
/* Inputs: close */
/* Options: lp_period_one[6], k1_quotient[0], trig_no[2], lp_period_two[27], k22_eot[0.3] */
/* Outputs: trigger(ohlc), q4(ohlc) */
#define TI_INDICATOR_BOOM_PRO_INDEX 17
int ti_boom_pro_start(TI_REAL const *options);
int ti_boom_pro(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Balance of Power */
/* Type: indicator */
/* Input arrays: 4    Options: 0    Output arrays: 1 */
/* Inputs: open, high, low, close */
/* Options: none */
/* Outputs: bop */
#define TI_INDICATOR_BOP_INDEX 18
int ti_bop_start(TI_REAL const *options);
int ti_bop(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Braid Filter */
/* Type: overlay */
/* Input arrays: 4    Options: 4    Output arrays: 3 */
/* Inputs: open, high, low, close */
/* Options: ma01_length[3], ma02_length[7], ma03_length[14], pips_min_sep_percent[40] */
/* Outputs: ?dif, ?atr_filter, bar_color */
#define TI_INDICATOR_BRAID_FILTER_INDEX 19
int ti_braid_filter_start(TI_REAL const *options);
int ti_braid_filter(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Commodity Channel Index */
/* Type: indicator */
/* Input arrays: 3    Options: 1    Output arrays: 1 */
/* Inputs: high, low, close */
/* Options: period[20] */
/* Outputs: cci */
#define TI_INDICATOR_CCI_INDEX 20
int ti_cci_start(TI_REAL const *options);
int ti_cci(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Vector Ceiling */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: ceil */
#define TI_INDICATOR_CEIL_INDEX 21
int ti_ceil_start(TI_REAL const *options);
int ti_ceil(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Chaikin Volatility */
/* Type: overlay */
/* Input arrays: 2    Options: 2    Output arrays: 1 */
/* Inputs: high, low */
/* Options: ema_period[7], roc_period[14] */
/* Outputs: cvi */
#define TI_INDICATOR_CHAIKIN_VOL_INDEX 22
int ti_chaikin_vol_start(TI_REAL const *options);
int ti_chaikin_vol(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Chandelier Exit */
/* Type: overlay */
/* Input arrays: 3    Options: 2    Output arrays: 1 */
/* Inputs: high, low, close */
/* Options: period[22], atr_multiplier[3] */
/* Outputs: buy_sell_signal */
#define TI_INDICATOR_CHANDELIER_EXIT_INDEX 23
int ti_chandelier_exit_start(TI_REAL const *options);
int ti_chandelier_exit(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* CM EMA TRENDBARS */
/* Type: overlay */
/* Input arrays: 3    Options: 1    Output arrays: 2 */
/* Inputs: high, low, close */
/* Options: ema_length[34] */
/* Outputs: ?usdema(ohlc), bar_color */
#define TI_INDICATOR_CM_EMA_TRENDBARS_INDEX 24
int ti_cm_ema_trendbars_start(TI_REAL const *options);
int ti_cm_ema_trendbars(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Chande Momentum Oscillator */
/* Type: indicator */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: cmo */
#define TI_INDICATOR_CMO_INDEX 25
int ti_cmo_start(TI_REAL const *options);
int ti_cmo(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Vector Cosine */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: cos */
#define TI_INDICATOR_COS_INDEX 26
int ti_cos_start(TI_REAL const *options);
int ti_cos(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Vector Hyperbolic Cosine */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: cosh */
#define TI_INDICATOR_COSH_INDEX 27
int ti_cosh_start(TI_REAL const *options);
int ti_cosh(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Crossany */
/* Type: math */
/* Input arrays: 2    Options: 0    Output arrays: 1 */
/* Inputs: value_one, value_two */
/* Options: none */
/* Outputs: crossany */
#define TI_INDICATOR_CROSSANY_INDEX 28
int ti_crossany_start(TI_REAL const *options);
int ti_crossany(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Crossover */
/* Type: math */
/* Input arrays: 2    Options: 0    Output arrays: 1 */
/* Inputs: value_one, value_two */
/* Options: none */
/* Outputs: crossover */
#define TI_INDICATOR_CROSSOVER_INDEX 29
int ti_crossover_start(TI_REAL const *options);
int ti_crossover(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Chaikins Volatility */
/* Type: indicator */
/* Input arrays: 2    Options: 1    Output arrays: 1 */
/* Inputs: high, low */
/* Options: period */
/* Outputs: cvi */
#define TI_INDICATOR_CVI_INDEX 30
int ti_cvi_start(TI_REAL const *options);
int ti_cvi(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Linear Decay */
/* Type: math */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: decay */
#define TI_INDICATOR_DECAY_INDEX 31
int ti_decay_start(TI_REAL const *options);
int ti_decay(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Double Exponential Moving Average */
/* Type: overlay */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period[9] */
/* Outputs: dema(ohlcv) */
#define TI_INDICATOR_DEMA_INDEX 32
int ti_dema_start(TI_REAL const *options);
int ti_dema(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Directional Indicator */
/* Type: indicator */
/* Input arrays: 3    Options: 1    Output arrays: 2 */
/* Inputs: high, low, close */
/* Options: period */
/* Outputs: plus_di, minus_di */
#define TI_INDICATOR_DI_INDEX 33
int ti_di_start(TI_REAL const *options);
int ti_di(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* DI-DX */
/* Type: indicator */
/* Input arrays: 3    Options: 1    Output arrays: 3 */
/* Inputs: high, low, close */
/* Options: period[14] */
/* Outputs: ?dx, di_plus, di_minus */
#define TI_INDICATOR_DI_DX_INDEX 34
int ti_di_dx_start(TI_REAL const *options);
int ti_di_dx(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Vector Division */
/* Type: simple */
/* Input arrays: 2    Options: 0    Output arrays: 1 */
/* Inputs: value_one, value_two */
/* Options: none */
/* Outputs: div */
#define TI_INDICATOR_DIV_INDEX 35
int ti_div_start(TI_REAL const *options);
int ti_div(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Directional Movement */
/* Type: indicator */
/* Input arrays: 2    Options: 1    Output arrays: 2 */
/* Inputs: high, low */
/* Options: period */
/* Outputs: plus_dm, minus_dm */
#define TI_INDICATOR_DM_INDEX 36
int ti_dm_start(TI_REAL const *options);
int ti_dm(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Detrended Price Oscillator */
/* Type: indicator */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: dpo */
#define TI_INDICATOR_DPO_INDEX 37
int ti_dpo_start(TI_REAL const *options);
int ti_dpo(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Directional Movement Index */
/* Type: indicator */
/* Input arrays: 2    Options: 1    Output arrays: 1 */
/* Inputs: high, low */
/* Options: period[14] */
/* Outputs: dx */
#define TI_INDICATOR_DX_INDEX 38
int ti_dx_start(TI_REAL const *options);
int ti_dx(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Exponential Decay */
/* Type: math */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: edecay */
#define TI_INDICATOR_EDECAY_INDEX 39
int ti_edecay_start(TI_REAL const *options);
int ti_edecay(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Exponential Moving Average */
/* Type: overlay */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period[9] */
/* Outputs: ema(ohlcv) */
#define TI_INDICATOR_EMA_INDEX 40
int ti_ema_start(TI_REAL const *options);
int ti_ema(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Ease of Movement */
/* Type: indicator */
/* Input arrays: 3    Options: 0    Output arrays: 1 */
/* Inputs: high, low, volume */
/* Options: none */
/* Outputs: emv */
#define TI_INDICATOR_EMV_INDEX 41
int ti_emv_start(TI_REAL const *options);
int ti_emv(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Vector Exponential */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: exp */
#define TI_INDICATOR_EXP_INDEX 42
int ti_exp_start(TI_REAL const *options);
int ti_exp(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Vector Floor */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: floor */
#define TI_INDICATOR_FLOOR_INDEX 43
int ti_floor_start(TI_REAL const *options);
int ti_floor(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Forecast Oscillator */
/* Type: indicator */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: fosc */
#define TI_INDICATOR_FOSC_INDEX 44
int ti_fosc_start(TI_REAL const *options);
int ti_fosc(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Heikin-Ashi */
/* Type: simple */
/* Input arrays: 4    Options: 0    Output arrays: 4 */
/* Inputs: open, high, low, close */
/* Options: none */
/* Outputs: ha_open, ha_high, ha_low, ha_close */
#define TI_INDICATOR_HA_INDEX 45
int ti_ha_start(TI_REAL const *options);
int ti_ha(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Half Trend */
/* Type: overlay */
/* Input arrays: 3    Options: 3    Output arrays: 2 */
/* Inputs: high, low, close */
/* Options: amplitude[2], channel_deviation[2], atr_length[100] */
/* Outputs: ?ht(ohlc), bar_color */
#define TI_INDICATOR_HALF_TREND_INDEX 46
int ti_half_trend_start(TI_REAL const *options);
int ti_half_trend(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Heatmap Volume */
/* Type: overlay */
/* Input arrays: 1    Options: 6    Output arrays: 1 */
/* Inputs: volume */
/* Options: length[610], std_length[610], threshold_extra_high[4], threshold_high[2.5], threshold_medium[1], threshold_normal[-0.5] */
/* Outputs: heatmap_level */
#define TI_INDICATOR_HEATMAP_VOL_INDEX 47
int ti_heatmap_vol_start(TI_REAL const *options);
int ti_heatmap_vol(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* HLC3 */
/* Type: math */
/* Input arrays: 3    Options: 0    Output arrays: 1 */
/* Inputs: high, low, close */
/* Options: none */
/* Outputs: hlc3_data */
#define TI_INDICATOR_HLC3_INDEX 48
int ti_hlc3_start(TI_REAL const *options);
int ti_hlc3(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Hull Moving Average */
/* Type: overlay */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period[9] */
/* Outputs: hma(ohlcv) */
#define TI_INDICATOR_HMA_INDEX 49
int ti_hma_start(TI_REAL const *options);
int ti_hma(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Hull Suite */
/* Type: overlay */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: close */
/* Options: hma_length[55] */
/* Outputs: bar_color */
#define TI_INDICATOR_HULL_SUITE_INDEX 50
int ti_hull_suite_start(TI_REAL const *options);
int ti_hull_suite(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Inside Bar */
/* Type: indicator */
/* Input arrays: 4    Options: 0    Output arrays: 1 */
/* Inputs: open, high, low, close */
/* Options: none */
/* Outputs: buy_sell_signal */
#define TI_INDICATOR_INSIDEBAR_INDEX 51
int ti_insidebar_start(TI_REAL const *options);
int ti_insidebar(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Kaufman Adaptive Moving Average */
/* Type: overlay */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: kama */
#define TI_INDICATOR_KAMA_INDEX 52
int ti_kama_start(TI_REAL const *options);
int ti_kama(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Klinger Volume Oscillator */
/* Type: indicator */
/* Input arrays: 4    Options: 2    Output arrays: 1 */
/* Inputs: high, low, close, volume */
/* Options: short_period, long_period */
/* Outputs: kvo */
#define TI_INDICATOR_KVO_INDEX 53
int ti_kvo_start(TI_REAL const *options);
int ti_kvo(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Lag */
/* Type: math */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: lag */
#define TI_INDICATOR_LAG_INDEX 54
int ti_lag_start(TI_REAL const *options);
int ti_lag(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Linear Regression */
/* Type: overlay */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period[100] */
/* Outputs: linreg(ohlcv) */
#define TI_INDICATOR_LINREG_INDEX 55
int ti_linreg_start(TI_REAL const *options);
int ti_linreg(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Linear Regression Intercept */
/* Type: indicator */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: linregintercept */
#define TI_INDICATOR_LINREGINTERCEPT_INDEX 56
int ti_linregintercept_start(TI_REAL const *options);
int ti_linregintercept(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Linear Regression Slope */
/* Type: indicator */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: linregslope */
#define TI_INDICATOR_LINREGSLOPE_INDEX 57
int ti_linregslope_start(TI_REAL const *options);
int ti_linregslope(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Vector Natural Log */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: ln */
#define TI_INDICATOR_LN_INDEX 58
int ti_ln_start(TI_REAL const *options);
int ti_ln(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Vector Base-10 Log */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: log10 */
#define TI_INDICATOR_LOG10_INDEX 59
int ti_log10_start(TI_REAL const *options);
int ti_log10(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Moving Average Convergence/Divergence */
/* Type: indicator */
/* Input arrays: 1    Options: 3    Output arrays: 3 */
/* Inputs: real */
/* Options: short_period[12], long_period[26], signal_period[9] */
/* Outputs: macd, macd_signal, ?macd_histogram */
#define TI_INDICATOR_MACD_INDEX 60
int ti_macd_start(TI_REAL const *options);
int ti_macd(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* MACD Fastline Divergence */
/* Type: overlay */
/* Input arrays: 3    Options: 3    Output arrays: 2 */
/* Inputs: high, low, close */
/* Options: fast_length[12], slow_length[26], signal_length[9] */
/* Outputs: bull, bear */
#define TI_INDICATOR_MACD_FASTLINE_DIVERGENCE_INDEX 61
int ti_macd_fastline_divergence_start(TI_REAL const *options);
int ti_macd_fastline_divergence(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* MACD Hist Divergence */
/* Type: overlay */
/* Input arrays: 3    Options: 3    Output arrays: 2 */
/* Inputs: high, low, close */
/* Options: fast_length[12], slow_length[26], signal_length[9] */
/* Outputs: bull, bear */
#define TI_INDICATOR_MACD_HIST_DIVERGENCE_INDEX 62
int ti_macd_hist_divergence_start(TI_REAL const *options);
int ti_macd_hist_divergence(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Market Facilitation Index */
/* Type: indicator */
/* Input arrays: 3    Options: 0    Output arrays: 1 */
/* Inputs: high, low, volume */
/* Options: none */
/* Outputs: marketfi */
#define TI_INDICATOR_MARKETFI_INDEX 63
int ti_marketfi_start(TI_REAL const *options);
int ti_marketfi(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Mass Index */
/* Type: indicator */
/* Input arrays: 2    Options: 1    Output arrays: 1 */
/* Inputs: high, low */
/* Options: period */
/* Outputs: mass */
#define TI_INDICATOR_MASS_INDEX 64
int ti_mass_start(TI_REAL const *options);
int ti_mass(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Maximum In Period */
/* Type: math */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: max */
#define TI_INDICATOR_MAX_INDEX 65
int ti_max_start(TI_REAL const *options);
int ti_max(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
int ti_max_ref(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Mean Deviation Over Period */
/* Type: math */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: md */
#define TI_INDICATOR_MD_INDEX 66
int ti_md_start(TI_REAL const *options);
int ti_md(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Median Price */
/* Type: overlay */
/* Input arrays: 2    Options: 0    Output arrays: 1 */
/* Inputs: high, low */
/* Options: none */
/* Outputs: medprice */
#define TI_INDICATOR_MEDPRICE_INDEX 67
int ti_medprice_start(TI_REAL const *options);
int ti_medprice(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Money Flow Index */
/* Type: indicator */
/* Input arrays: 4    Options: 1    Output arrays: 1 */
/* Inputs: high, low, close, volume */
/* Options: period[14] */
/* Outputs: mfi */
#define TI_INDICATOR_MFI_INDEX 68
int ti_mfi_start(TI_REAL const *options);
int ti_mfi(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Minimum In Period */
/* Type: math */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: min */
#define TI_INDICATOR_MIN_INDEX 69
int ti_min_start(TI_REAL const *options);
int ti_min(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
int ti_min_ref(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Mobo Band */
/* Type: overlay */
/* Input arrays: 2    Options: 4    Output arrays: 1 */
/* Inputs: high, low */
/* Options: dpo_length[13], mobo_length[10], num_dev_down[-0.8], num_dev_up[0.8] */
/* Outputs: buy_sell_signal */
#define TI_INDICATOR_MOBO_BAND_INDEX 70
int ti_mobo_band_start(TI_REAL const *options);
int ti_mobo_band(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Momentum */
/* Type: indicator */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: mom */
#define TI_INDICATOR_MOM_INDEX 71
int ti_mom_start(TI_REAL const *options);
int ti_mom(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Vector Multiplication */
/* Type: simple */
/* Input arrays: 2    Options: 0    Output arrays: 1 */
/* Inputs: value_one, value_two */
/* Options: none */
/* Outputs: mul */
#define TI_INDICATOR_MUL_INDEX 72
int ti_mul_start(TI_REAL const *options);
int ti_mul(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Normalized Average True Range */
/* Type: indicator */
/* Input arrays: 3    Options: 1    Output arrays: 1 */
/* Inputs: high, low, close */
/* Options: period[14] */
/* Outputs: natr */
#define TI_INDICATOR_NATR_INDEX 73
int ti_natr_start(TI_REAL const *options);
int ti_natr(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Compare Price */
/* Type: indicator */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: value(ohlc) */
/* Options: none */
/* Outputs: price */
#define TI_INDICATOR_PRICE_INDEX 74
int ti_price_start(TI_REAL const *options);
int ti_price(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* PSAR */
/* Type: indicator */
/* Input arrays: 3    Options: 3    Output arrays: 1 */
/* Inputs: high, low, close */
/* Options: accel_start[0.02], accel_step[0.02], accel_max[0.2] */
/* Outputs: psar(ohlc) */
#define TI_INDICATOR_PSAR_INDEX 75
int ti_psar_start(TI_REAL const *options);
int ti_psar(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* QQE Mod */
/* Type: overlay */
/* Input arrays: 1    Options: 10    Output arrays: 2 */
/* Inputs: close */
/* Options: rsi_length_one[6], rsi_smoothing_one[5], qqe_factor_one[3], threshold_one[3], rsi_length_two[6], rsi_smoothing_two[5], qqe_factor_two[1.61], threshold_two[3], bollinger_length[50], qqe_multiplier[0.35] */
/* Outputs: bar_color_one, bar_color_two */
#define TI_INDICATOR_QQE_MOD_INDEX 76
int ti_qqe_mod_start(TI_REAL const *options);
int ti_qqe_mod(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Rate of Change */
/* Type: indicator */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: roc */
#define TI_INDICATOR_ROC_INDEX 77
int ti_roc_start(TI_REAL const *options);
int ti_roc(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Rate of Change Ratio */
/* Type: indicator */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: rocr */
#define TI_INDICATOR_ROCR_INDEX 78
int ti_rocr_start(TI_REAL const *options);
int ti_rocr(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Vector Round */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: round */
#define TI_INDICATOR_ROUND_INDEX 79
int ti_round_start(TI_REAL const *options);
int ti_round(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Relative Strength Index */
/* Type: indicator */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period[14] */
/* Outputs: rsi */
#define TI_INDICATOR_RSI_INDEX 80
int ti_rsi_start(TI_REAL const *options);
int ti_rsi(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Relative Strength Index Divergence */
/* Type: overlay */
/* Input arrays: 3    Options: 3    Output arrays: 2 */
/* Inputs: high, low, close */
/* Options: left_bar[6], right_bar[2], rsi_length[14] */
/* Outputs: bull, bear */
#define TI_INDICATOR_RSI_DIVERGENCE_INDEX 81
int ti_rsi_divergence_start(TI_REAL const *options);
int ti_rsi_divergence(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Relative Volatility Index */
/* Type: overlay */
/* Input arrays: 1    Options: 2    Output arrays: 1 */
/* Inputs: close */
/* Options: std_length[10], ema_length[14] */
/* Outputs: rvi */
#define TI_INDICATOR_RVI_INDEX 82
int ti_rvi_start(TI_REAL const *options);
int ti_rvi(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Relative Volatility Index Divergence */
/* Type: overlay */
/* Input arrays: 3    Options: 4    Output arrays: 2 */
/* Inputs: high, low, close */
/* Options: left_bar[6], right_bar[2], std_length[12], ema_length[14] */
/* Outputs: bull, bear */
#define TI_INDICATOR_RVI_DIVERGENCE_INDEX 83
int ti_rvi_divergence_start(TI_REAL const *options);
int ti_rvi_divergence(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Vector Sine */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: sin */
#define TI_INDICATOR_SIN_INDEX 84
int ti_sin_start(TI_REAL const *options);
int ti_sin(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Vector Hyperbolic Sine */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: sinh */
#define TI_INDICATOR_SINH_INDEX 85
int ti_sinh_start(TI_REAL const *options);
int ti_sinh(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Simple Moving Average */
/* Type: overlay */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period[7] */
/* Outputs: sma(ohlcv) */
#define TI_INDICATOR_SMA_INDEX 86
int ti_sma_start(TI_REAL const *options);
int ti_sma(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
int ti_sma_stream_new(TI_REAL const *options, ti_stream **stream);
int ti_sma_stream_run(ti_stream *stream, int size, TI_REAL const *const *inputs, TI_REAL *const *outputs);
void ti_sma_stream_free(ti_stream *stream);
/* Vector Square Root */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: sqrt */
#define TI_INDICATOR_SQRT_INDEX 87
int ti_sqrt_start(TI_REAL const *options);
int ti_sqrt(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* SSL */
/* Type: overlay */
/* Input arrays: 3    Options: 2    Output arrays: 6 */
/* Inputs: high, low, close */
/* Options: ma_length[60], ssl3_length[15] */
/* Outputs: ?bbmc(ohlc), bar_color, ?up_erk(ohlc), ?low_erk(ohlc), ?cross_long, ?cross_short */
#define TI_INDICATOR_SSL_INDEX 88
int ti_ssl_start(TI_REAL const *options);
int ti_ssl(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* STC */
/* Type: overlay */
/* Input arrays: 1    Options: 4    Output arrays: 2 */
/* Inputs: close */
/* Options: length[12], fast_length[26], slow_length[50], aaa[0.5] */
/* Outputs: ?stc, bar_color */
#define TI_INDICATOR_STC_INDEX 89
int ti_stc_start(TI_REAL const *options);
int ti_stc(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Standard Deviation Over Period */
/* Type: math */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: stddev */
#define TI_INDICATOR_STDDEV_INDEX 90
int ti_stddev_start(TI_REAL const *options);
int ti_stddev(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Standard Error Over Period */
/* Type: math */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: stderr */
#define TI_INDICATOR_STDERR_INDEX 91
int ti_stderr_start(TI_REAL const *options);
int ti_stderr(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Stochastic Oscillator */
/* Type: indicator */
/* Input arrays: 3    Options: 3    Output arrays: 2 */
/* Inputs: high, low, close */
/* Options: k_period[14], k_slowing_period[1], d_period[3] */
/* Outputs: stoch_k, stoch_d */
#define TI_INDICATOR_STOCH_INDEX 92
int ti_stoch_start(TI_REAL const *options);
int ti_stoch(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Stochastic Divergence */
/* Type: overlay */
/* Input arrays: 3    Options: 5    Output arrays: 2 */
/* Inputs: high, low, close */
/* Options: left_bar[6], right_bar[2], stk_length[14], smooth_length[3], sma_length[3] */
/* Outputs: bull, bear */
#define TI_INDICATOR_STOCH_DIVERGENCE_INDEX 93
int ti_stoch_divergence_start(TI_REAL const *options);
int ti_stoch_divergence(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Stoch Rsi */
/* Type: overlay */
/* Input arrays: 1    Options: 4    Output arrays: 2 */
/* Inputs: close */
/* Options: smoothk[3], smoothd[3], rsi_period[14], stoch_period[14] */
/* Outputs: stoch_k, stoch_d */
#define TI_INDICATOR_STOCH_RSI_INDEX 94
int ti_stoch_rsi_start(TI_REAL const *options);
int ti_stoch_rsi(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Stochastic RSI */
/* Type: indicator */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period[14] */
/* Outputs: stochrsi */
#define TI_INDICATOR_STOCHRSI_INDEX 95
int ti_stochrsi_start(TI_REAL const *options);
int ti_stochrsi(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Vector Subtraction */
/* Type: simple */
/* Input arrays: 2    Options: 0    Output arrays: 1 */
/* Inputs: value_one, value_two */
/* Options: none */
/* Outputs: sub */
#define TI_INDICATOR_SUB_INDEX 96
int ti_sub_start(TI_REAL const *options);
int ti_sub(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Sum Over Period */
/* Type: math */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: sum */
#define TI_INDICATOR_SUM_INDEX 97
int ti_sum_start(TI_REAL const *options);
int ti_sum(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Support and Resistance */
/* Type: overlay */
/* Input arrays: 1    Options: 4    Output arrays: 16 */
/* Inputs: close */
/* Options: left_bar[200], right_bar_one[20], right_bar_two[5], hma_length[9] */
/* Outputs: buy_one, buy_two, buy_three, buy_four, buy_five, buy_six, buy_seven, buy_eight, sell_one, sell_two, sell_three, sell_four, sell_five, sell_six, sell_seven, sell_eight */
#define TI_INDICATOR_SUP_AND_RES_INDEX 98
int ti_sup_and_res_start(TI_REAL const *options);
int ti_sup_and_res(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Supertrend */
/* Type: overlay */
/* Input arrays: 3    Options: 2    Output arrays: 4 */
/* Inputs: high, low, close */
/* Options: period[34], factor[3] */
/* Outputs: ?supertrend(ohlc), ?direction, bar_color, buy_sell_signal */
#define TI_INDICATOR_SUPERTREND_INDEX 99
int ti_supertrend_start(TI_REAL const *options);
int ti_supertrend(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Vector Tangent */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: tan */
#define TI_INDICATOR_TAN_INDEX 100
int ti_tan_start(TI_REAL const *options);
int ti_tan(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Vector Hyperbolic Tangent */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: tanh */
#define TI_INDICATOR_TANH_INDEX 101
int ti_tanh_start(TI_REAL const *options);
int ti_tanh(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Triple Exponential Moving Average */
/* Type: overlay */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period[9] */
/* Outputs: tema(ohlcv) */
#define TI_INDICATOR_TEMA_INDEX 102
int ti_tema_start(TI_REAL const *options);
int ti_tema(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Vector Degree Conversion */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: degrees */
#define TI_INDICATOR_TODEG_INDEX 103
int ti_todeg_start(TI_REAL const *options);
int ti_todeg(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Vector Radian Conversion */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: radians */
#define TI_INDICATOR_TORAD_INDEX 104
int ti_torad_start(TI_REAL const *options);
int ti_torad(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* True Range */
/* Type: indicator */
/* Input arrays: 3    Options: 0    Output arrays: 1 */
/* Inputs: high, low, close */
/* Options: none */
/* Outputs: tr */
#define TI_INDICATOR_TR_INDEX 105
int ti_tr_start(TI_REAL const *options);
int ti_tr(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Triangular Moving Average */
/* Type: overlay */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period[20] */
/* Outputs: trima(ohlcv) */
#define TI_INDICATOR_TRIMA_INDEX 106
int ti_trima_start(TI_REAL const *options);
int ti_trima(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Trix */
/* Type: indicator */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: trix */
#define TI_INDICATOR_TRIX_INDEX 107
int ti_trix_start(TI_REAL const *options);
int ti_trix(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Vector Truncate */
/* Type: simple */
/* Input arrays: 1    Options: 0    Output arrays: 1 */
/* Inputs: real */
/* Options: none */
/* Outputs: trunc */
#define TI_INDICATOR_TRUNC_INDEX 108
int ti_trunc_start(TI_REAL const *options);
int ti_trunc(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Time Series Forecast */
/* Type: overlay */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: tsf */
#define TI_INDICATOR_TSF_INDEX 109
int ti_tsf_start(TI_REAL const *options);
int ti_tsf(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Typical Price */
/* Type: overlay */
/* Input arrays: 3    Options: 0    Output arrays: 1 */
/* Inputs: high, low, close */
/* Options: none */
/* Outputs: typprice */
#define TI_INDICATOR_TYPPRICE_INDEX 110
int ti_typprice_start(TI_REAL const *options);
int ti_typprice(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Ultimate Oscillator */
/* Type: indicator */
/* Input arrays: 3    Options: 3    Output arrays: 1 */
/* Inputs: high, low, close */
/* Options: short_period, medium_period, long_period */
/* Outputs: ultosc */
#define TI_INDICATOR_ULTOSC_INDEX 111
int ti_ultosc_start(TI_REAL const *options);
int ti_ultosc(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Unshift */
/* Type: simple */
/* Input arrays: 1    Options: 2    Output arrays: 1 */
/* Inputs: value */
/* Options: default_value, length */
/* Outputs: unshifted_value */
#define TI_INDICATOR_UNSHIFT_INDEX 112
int ti_unshift_start(TI_REAL const *options);
int ti_unshift(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* UT Bot Alert */
/* Type: overlay */
/* Input arrays: 3    Options: 2    Output arrays: 1 */
/* Inputs: high, low, close */
/* Options: atr_period[10], sensitivity[1] */
/* Outputs: buy_sell_signal */
#define TI_INDICATOR_UT_BOT_INDEX 113
int ti_ut_bot_start(TI_REAL const *options);
int ti_ut_bot(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Variance Over Period */
/* Type: math */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: var */
#define TI_INDICATOR_VAR_INDEX 114
int ti_var_start(TI_REAL const *options);
int ti_var(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Vertical Horizontal Filter */
/* Type: indicator */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: vhf */
#define TI_INDICATOR_VHF_INDEX 115
int ti_vhf_start(TI_REAL const *options);
int ti_vhf(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Annualized Historical Volatility */
/* Type: indicator */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: volatility */
#define TI_INDICATOR_VOLATILITY_INDEX 116
int ti_volatility_start(TI_REAL const *options);
int ti_volatility(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Volatility Oscillator */
/* Type: overlay */
/* Input arrays: 2    Options: 1    Output arrays: 3 */
/* Inputs: open, close */
/* Options: length[100] */
/* Outputs: spike_line, upper_line, lower_line */
#define TI_INDICATOR_VOLATILITY_OSCILLATOR_INDEX 117
int ti_volatility_oscillator_start(TI_REAL const *options);
int ti_volatility_oscillator(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Volume Oscillator */
/* Type: indicator */
/* Input arrays: 1    Options: 2    Output arrays: 1 */
/* Inputs: volume */
/* Options: short_period, long_period */
/* Outputs: vosc */
#define TI_INDICATOR_VOSC_INDEX 118
int ti_vosc_start(TI_REAL const *options);
int ti_vosc(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* VU Man Chu Swing */
/* Type: overlay */
/* Input arrays: 1    Options: 2    Output arrays: 2 */
/* Inputs: close */
/* Options: swing_period[20], swing_multiplier[3.5] */
/* Outputs: buy_sell_signal_long, buy_sell_signal_short */
#define TI_INDICATOR_VU_MAN_CHU_SWING_INDEX 119
int ti_vu_man_chu_swing_start(TI_REAL const *options);
int ti_vu_man_chu_swing(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Volume Weighted Moving Average */
/* Type: overlay */
/* Input arrays: 2    Options: 1    Output arrays: 1 */
/* Inputs: close, volume */
/* Options: period[20] */
/* Outputs: vwma(v) */
#define TI_INDICATOR_VWMA_INDEX 120
int ti_vwma_start(TI_REAL const *options);
int ti_vwma(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Williams Accumulation/Distribution */
/* Type: indicator */
/* Input arrays: 3    Options: 0    Output arrays: 1 */
/* Inputs: high, low, close */
/* Options: none */
/* Outputs: wad */
#define TI_INDICATOR_WAD_INDEX 121
int ti_wad_start(TI_REAL const *options);
int ti_wad(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Waddah */
/* Type: overlay */
/* Input arrays: 1    Options: 6    Output arrays: 4 */
/* Inputs: close */
/* Options: fast_length[20], slow_length[40], signal_length[9], bb_length[20], multiplier[2], sensitivity[150] */
/* Outputs: ?t, e, trend_up, trend_down */
#define TI_INDICATOR_WADDAH_INDEX 122
int ti_waddah_start(TI_REAL const *options);
int ti_waddah(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Wavetrend */
/* Type: overlay */
/* Input arrays: 3    Options: 2    Output arrays: 2 */
/* Inputs: high, low, close */
/* Options: period_one[9], period_two[12] */
/* Outputs: wavetrend_one, wavetrend_two */
#define TI_INDICATOR_WAVETREND_INDEX 123
int ti_wavetrend_start(TI_REAL const *options);
int ti_wavetrend(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Weighted Close Price */
/* Type: overlay */
/* Input arrays: 3    Options: 0    Output arrays: 1 */
/* Inputs: high, low, close */
/* Options: none */
/* Outputs: wcprice */
#define TI_INDICATOR_WCPRICE_INDEX 124
int ti_wcprice_start(TI_REAL const *options);
int ti_wcprice(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Wilders Smoothing */
/* Type: overlay */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: wilders */
#define TI_INDICATOR_WILDERS_INDEX 125
int ti_wilders_start(TI_REAL const *options);
int ti_wilders(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Williams %R */
/* Type: indicator */
/* Input arrays: 3    Options: 1    Output arrays: 1 */
/* Inputs: high, low, close */
/* Options: period */
/* Outputs: willr */
#define TI_INDICATOR_WILLR_INDEX 126
int ti_willr_start(TI_REAL const *options);
int ti_willr(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Weighted Moving Average */
/* Type: overlay */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period[9] */
/* Outputs: wma(ohlcv) */
#define TI_INDICATOR_WMA_INDEX 127
int ti_wma_start(TI_REAL const *options);
int ti_wma(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);
/* Zero-Lag Exponential Moving Average */
/* Type: overlay */
/* Input arrays: 1    Options: 1    Output arrays: 1 */
/* Inputs: real */
/* Options: period */
/* Outputs: zlema(ohlcv) */
#define TI_INDICATOR_ZLEMA_INDEX 128
int ti_zlema_start(TI_REAL const *options);
int ti_zlema(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs);


#ifdef __cplusplus
}
#endif

#endif /*__TI_INDICATORS_H__*/

/*
 * Tulip Indicators
 * https://tulipindicators.org/
 * Copyright (c) 2010-2020 Tulip Charts LLC
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


#ifndef __TC_CANDLES_H__
#define __TC_CANDLES_H__



/*
 *
 * Version 0.9.2
 * Header Build 1688954421
 *
 */

/*
 *
 * This file is generated. Do not modify directly.
 *
 */




#define TC_VERSION "0.9.2"
#define TC_BUILD 1688954421




#ifndef TI_SKIP_SYSTEM_HEADERS
#include <stdint.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif


const char* tc_version(void);
long int tc_build(void);
int tc_candle_count(void);

#define TC_OKAY 0
#define TC_INVALID_OPTION 1
#define TC_OUT_OF_MEMORY 2

typedef double TC_REAL;
typedef struct tc_result tc_result;

typedef uint64_t tc_set; /* Stores a set of candles. */
#define TC_SET_CLEAR(x) do {x = 0;} while (0)
#define TC_SET_ADD(x, c) do {x |= c;} while (0)
#define TC_SET_CHECK(x, c) (x & c)
#define TC_SET_REMOVE(x, c) (x & (~c))
#define TC_SET_NEXT(x) (x &= (x-1))




#define TC_CANDLE_COUNT 26 /* Total number of recognized candle patterns. */

#define TC_NONE (0)
#define TC_ALL ((1L<<26)-1)

#define TC_ABANDONED_BABY_BEAR (1L<<0)
#define TC_ABANDONED_BABY_BULL (1L<<1)
#define TC_BIG_BLACK_CANDLE (1L<<2)
#define TC_BIG_WHITE_CANDLE (1L<<3)
#define TC_BLACK_MARUBOZU (1L<<4)
#define TC_DOJI (1L<<5)
#define TC_DRAGONFLY_DOJI (1L<<6)
#define TC_ENGULFING_BEAR (1L<<7)
#define TC_ENGULFING_BULL (1L<<8)
#define TC_EVENING_DOJI_STAR (1L<<9)
#define TC_EVENING_STAR (1L<<10)
#define TC_FOUR_PRICE_DOJI (1L<<11)
#define TC_GRAVESTONE_DOJI (1L<<12)
#define TC_HAMMER (1L<<13)
#define TC_HANGING_MAN (1L<<14)
#define TC_INVERTED_HAMMER (1L<<15)
#define TC_LONG_LEGGED_DOJI (1L<<16)
#define TC_MARUBOZU (1L<<17)
#define TC_MORNING_DOJI_STAR (1L<<18)
#define TC_MORNING_STAR (1L<<19)
#define TC_SHOOTING_STAR (1L<<20)
#define TC_SPINNING_TOP (1L<<21)
#define TC_STAR (1L<<22)
#define TC_THREE_BLACK_CROWS (1L<<23)
#define TC_THREE_WHITE_SOLDIERS (1L<<24)
#define TC_WHITE_MARUBOZU (1L<<25)




/* tc_config holds configuration settings for candle pattern recognition. */
typedef struct tc_config {
    int period; /* Window length over which all averages are calculated. */

    TC_REAL body_none; /* Bodies <= this * High-Low average are considered to be no body (doji). */
    TC_REAL body_short; /* Bodies <= this * Open-Close average are considered to be short body. */
    TC_REAL body_long; /* Bodies >= this * Open-Close average are considered to be long. */

    TC_REAL wick_none; /* Wicks <= this * High-Low average are considered to be no wick. */
    TC_REAL wick_long; /* Wicks >= this * Open-Close average are considered to be long wick. */

    TC_REAL near; /* Price differences <= this * High-Low range are considered to be near each other. */

} tc_config;


/* tc_hit stores an index and pattern set to represent all patterns found on one input bar. */
typedef struct tc_hit {
    int index; /* Which bar the candle patterns were found on. */
    tc_set patterns; /* Which candle patterns were found. */
} tc_hit;


/* All single-pattern candle functions have this signature. */
typedef int (*tc_candle_function)(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);


/* tc_candle_info stores info about each candle pattern supported by this library. */
typedef struct tc_candle_info {
    const char *name;
    const char *full_name;
    tc_set pattern;
    tc_candle_function candle;
} tc_candle_info;


/* Complete array of all candles. Last element is 0,0,0,0... */
extern tc_candle_info tc_candles[];

/* Find candle pattern info by name. Returns 0 if not found. */
const tc_candle_info *tc_find_candle(const char *name);

/* Find candle pattern info from tc_set. Returns 0 if not found. */
const tc_candle_info *tc_get_info(tc_set pattern);


tc_config const *tc_config_default(); /* Get default configuration. */
void tc_config_set_to_default(tc_config *config); /* Initializes a configuration to the default values. */


tc_result *tc_result_new(); /* Create new result container. */
void tc_result_free(tc_result *result); /* Free result container. */
int tc_result_count(const tc_result *result); /* Return number of bars with one or more patterns. */
int tc_result_pattern_count(const tc_result *result); /* Return total number of patterns found. */

tc_hit tc_result_get(const tc_result *result, int index); /* Return the Nth pattern found. */
tc_set tc_result_at(const tc_result *result, int index); /* Return all found patterns for input index. */



/* Scan input for candle patterns. May call once or repeatedly with new inputs. */
int tc_run(tc_set patterns, int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);



/*
 *
 *
 *
 *
 *
 *        All candle patterns below, sorted alphabetically.
 *
 *
 *
 *
 *
 */



int tc_abandoned_baby_bear(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);
int tc_abandoned_baby_bull(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);
int tc_big_black_candle(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);
int tc_big_white_candle(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);
int tc_black_marubozu(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);
int tc_doji(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);
int tc_dragonfly_doji(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);
int tc_engulfing_bear(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);
int tc_engulfing_bull(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);
int tc_evening_doji_star(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);
int tc_evening_star(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);
int tc_four_price_doji(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);
int tc_gravestone_doji(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);
int tc_hammer(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);
int tc_hanging_man(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);
int tc_inverted_hammer(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);
int tc_long_legged_doji(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);
int tc_marubozu(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);
int tc_morning_doji_star(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);
int tc_morning_star(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);
int tc_shooting_star(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);
int tc_spinning_top(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);
int tc_star(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);
int tc_three_black_crows(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);
int tc_three_white_soldiers(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);
int tc_white_marubozu(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output);




#ifdef __cplusplus
}
#endif

#endif /*__TC_CANDLES_H__*/

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

#ifndef __BUFFER_H__
#define __BUFFER_H__


typedef struct {
    int size, pushes, index;
    TI_REAL sum;
    TI_REAL vals[1];
} ti_buffer;


ti_buffer *ti_buffer_new(int size);
void ti_buffer_free(ti_buffer *buffer);

/* Pushes a new value, plus updates sum. */
#define ti_buffer_push(BUFFER, VAL) \
do { \
    if ((BUFFER)->pushes >= (BUFFER)->size) { \
        (BUFFER)->sum -= (BUFFER)->vals[(BUFFER)->index]; \
    } \
\
    (BUFFER)->sum += (VAL); \
    (BUFFER)->vals[(BUFFER)->index] = (VAL); \
    (BUFFER)->pushes += 1; \
    (BUFFER)->index = ((BUFFER)->index + 1); \
    if ((BUFFER)->index >= (BUFFER)->size) (BUFFER)->index = 0; \
} while (0)


/* Pushes a new value, skips updating sum. */
#define ti_buffer_qpush(BUFFER, VAL) \
do { \
    (BUFFER)->vals[(BUFFER)->index] = (VAL); \
    (BUFFER)->index = ((BUFFER)->index + 1); \
    if ((BUFFER)->index >= (BUFFER)->size) (BUFFER)->index = 0; \
} while (0)


/* With get, 0 = last value pushed, -1 = value before last, etc. */
#define ti_buffer_get(BUFFER, VAL) ((BUFFER)->vals[((BUFFER)->index + (BUFFER)->size - 1 + (VAL)) % (BUFFER)->size])


#endif /*__BUFFER_H__*/
/*
 * Tulip Indicators
 * https://tulipindicators.org/
 * Copyright (c) 2010-2020 Tulip Charts LLC
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


#ifndef __LOCALBUFFER_H__
#define __LOCALBUFFER_H__


/* IMPORTANT USAGE NOTICE:
 *  1. BUFFERS must go in the very end of the struct
 *  2. BUFFER_INIT must go in the order of declaration
 *  3. the zero[3] array must be initialized to zero, e.g. with help of calloc
 *  4. it is ASSUMED that sizeof(double) = 2*sizeof(int)
 */

/* This set of macros implements ring buffer functionality.
 * It was designed with data locality in mind: as opposed to
 * its predecessor buffer.h, it allows the user to manage
 * multiple buffers along with other data as a single chunk
 * of memory, which comes particularly handy when implementing
 * streaming versions of indicators.
 */

/* Example usage:
 * > struct ti_stream {
 * >     int index;
 * >     int progress;
 * >
 * >     BUFFERS(
 * >         BUFFER(a)
 * >         BUFFER(b)
 * >         BUFFER(c)
 * >     )
 * > };
 * >
 * > int ti_xxx_stream_new(TI_REAL const *options, ti_stream **stream) {
 * >     *stream = calloc(1, sizeof(ti_stream));
 * >
 * >     BUFFER_INIT(*stream, a, 5);
 * >     BUFFER_INIT(*stream, b, 8);
 * >     BUFFER_INIT(*stream, c, 13);
 * >
 * >     int size = BUFFERS_SIZE(*stream);
 * >     *stream = realloc(*stream, sizeof(ti_stream) + sizeof(TI_REAL[size]));
 * > }
 */

#define BUFFERS(buffers) struct { double padding; int zero[4]; buffers } buf_info;
#define BUFFER(name) int offset_##name; int size_##name; int index_##name; int padding_##name;
#define BUFFER_INIT(ptr, name, size) do { \
    ((ptr)->buf_info).offset_##name = *(&((ptr)->buf_info).offset_##name-3) + *(&((ptr)->buf_info).offset_##name-4); \
    ((ptr)->buf_info).size_##name = size; \
    ((ptr)->buf_info).index_##name = -1; \
} while (0)
#define BUFFERS_SIZE(ptr) (*((int*)(&((ptr)->buf_info)+1)-3) + *((int*)(&((ptr)->buf_info)+1)-4))
#define BUFFER_AT(result, ptr, name, delta) do { \
    int idx = ((ptr)->buf_info).index_##name + delta; \
    while (idx >= ((ptr)->buf_info).size_##name) { idx -= ((ptr)->buf_info).size_##name; } \
    while (idx < 0) { idx += ((ptr)->buf_info).size_##name; } \
    result = *((TI_REAL*)(&((ptr)->buf_info) + 1) + ((ptr)->buf_info).offset_##name + idx); \
} while (0)
#define BUFFER_PUSH(ptr, name, value) do { \
    int idx = ((ptr)->buf_info).index_##name + 1; \
    if (idx == ((ptr)->buf_info).size_##name) { idx = 0; } \
    *((TI_REAL*)(&((ptr)->buf_info) + 1) + ((ptr)->buf_info).offset_##name + idx) = value; \
    ((ptr)->buf_info).index_##name = idx; \
} while (0)


#endif /*__LOCALBUFFER_H__*/
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


#ifndef __MINMAX_H__
#define __MINMAX_H__


#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))


#endif /*__MINMAX_H__*/
int ti_abs_start(TI_REAL const *options) { (void)options; return 0; } int ti_abs(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (fabs(in1[i])); } return TI_OKAY; }
int ti_acos_start(TI_REAL const *options) { (void)options; return 0; } int ti_acos(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (acos(in1[i])); } return TI_OKAY; }
int ti_ad_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_ad(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    const TI_REAL *volume = inputs[3];
    (void)options;
    TI_REAL *output = outputs[0];
    TI_REAL sum = 0;
    int i;
    for (i = 0; i < size; ++i) {
        const TI_REAL hl = (high[i] - low[i]);
        if (hl != 0.0) {
            sum += (close[i] - low[i] - high[i] + close[i]) / hl * volume[i];
        }
        output[i] = sum;
    }
    return TI_OKAY;
}
int ti_add_start(TI_REAL const *options) { (void)options; return 0; } int ti_add(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; const TI_REAL *in2 = inputs[1]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (in1[i] + in2[i]); } return TI_OKAY; }
int ti_adosc_start(TI_REAL const *options) {
    return (int)(options[1])-1;
}
int ti_adosc(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    const TI_REAL *volume = inputs[3];
    const int short_period = (int)options[0];
    const int long_period = (int)options[1];
    const int start = long_period - 1;
    if (short_period < 1) return TI_INVALID_OPTION;
    if (long_period < short_period) return TI_INVALID_OPTION;
    if (size <= ti_adosc_start(options)) return TI_OKAY;
    const TI_REAL short_per = 2 / ((TI_REAL)short_period + 1);
    const TI_REAL long_per = 2 / ((TI_REAL)long_period + 1);
    TI_REAL *output = outputs[0];
    TI_REAL sum = 0, short_ema = 0, long_ema = 0;
    int i;
    for (i = 0; i < size; ++i) {
        const TI_REAL hl = (high[i] - low[i]);
        if (hl != 0.0) {
            sum += (close[i] - low[i] - high[i] + close[i]) / hl * volume[i];
        }
        if (i == 0) {
            short_ema = sum;
            long_ema = sum;
        } else {
            short_ema = (sum-short_ema) * short_per + short_ema;
            long_ema = (sum-long_ema) * long_per + long_ema;
        }
        if (i >= start) {
            *output++ = short_ema - long_ema;
        }
    }
    assert(output - outputs[0] == size - ti_adosc_start(options));
    return TI_OKAY;
}
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

int ti_adx_start(TI_REAL const *options)
{
  (void)(options);
  return 0;
}
int ti_adx(int size, TI_REAL const *const *inputs, TI_REAL const *options,
           TI_REAL *const *outputs)
{
  const TI_REAL *high = inputs[0];
  const TI_REAL *low = inputs[1];
  const int period = (int)options[0];
  TI_REAL *output = outputs[0];
  if (period < 1)
    return TI_INVALID_OPTION;
  if (size <= ti_adx_start(options))
    return TI_OKAY;
  const double nz_DX_options[] = {period};
  double *nz_DX_data = (double *)calloc((unsigned long)size, sizeof(double));
  const double *nz_DX_inputs[] = {high, low};
  double *nz_DX_outputs[] = {nz_DX_data};
  int error = ti_dx(size, nz_DX_inputs, nz_DX_options, nz_DX_outputs);
  assert(error == TI_OKAY);
  double *DX = (double *)calloc((unsigned long)size, sizeof(double));
  const double *DX_inputs[] = {nz_DX_data};
  double *DX_outputs[] = {DX};
  int range = period - 1;
  double value = 0;
  const double DX_options[] = {value, range};
  int error1 = ti_unshift(size, DX_inputs, DX_options, DX_outputs);
  assert(error1 == TI_OKAY);
  const double nz_adx_options[] = {period};
  double *nz_adx_data = (double *)calloc((unsigned long)size, sizeof(double));
  const double *nz_adx_inputs[] = {DX};
  double *nz_adx_outputs[] = {nz_adx_data};
  int error2 = ti_sma(size, nz_adx_inputs, nz_adx_options, nz_adx_outputs);
  assert(error2 == TI_OKAY);
  const double *ADX_inputs[] = {nz_adx_data};
  double *ADX_outputs[] = {output};
  int range1 = period - 1;
  const double ADX_options[] = {value, range1};
  int error3 = ti_unshift(size, ADX_inputs, ADX_options, ADX_outputs);
  assert(error3 == TI_OKAY);
  free(nz_DX_data);
  free(DX);
  free(nz_adx_data);
  return TI_OKAY;
}
int ti_adxr_start(TI_REAL const *options) {
    return ((int)options[0]-1) * 3;
}
int ti_adxr(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 2) return TI_INVALID_OPTION;
    if (size <= ti_adxr_start(options)) return TI_OKAY;
    const TI_REAL per = ((TI_REAL)period-1) / ((TI_REAL)period);
    const TI_REAL invper = 1.0 / ((TI_REAL)period);
    TI_REAL dmup = 0;
    TI_REAL dmdown = 0;
    int i;
    for (i = 1; i < period; ++i) {
        TI_REAL dp, dm;
        do { dp = high[i] - high[i-1]; dm = low[i-1] - low[i]; if (dp < 0) dp = 0; else if (dp > dm) dm = 0; if (dm < 0) dm = 0; else if (dm > dp) dp = 0;} while (0);
        dmup += dp;
        dmdown += dm;
    }
    TI_REAL adx = 0.0;
    {
        TI_REAL di_up = dmup;
        TI_REAL di_down = dmdown;
        TI_REAL dm_diff = fabs(di_up - di_down);
        TI_REAL dm_sum = di_up + di_down;
        TI_REAL dx = dm_diff / dm_sum * 100;
        adx += dx;
    }
    ti_buffer *adxr = ti_buffer_new(period-1);
    const int first_adxr = ti_adxr_start(options);
    for (i = period; i < size; ++i) {
        TI_REAL dp, dm;
        do { dp = high[i] - high[i-1]; dm = low[i-1] - low[i]; if (dp < 0) dp = 0; else if (dp > dm) dm = 0; if (dm < 0) dm = 0; else if (dm > dp) dp = 0;} while (0);
        dmup = dmup * per + dp;
        dmdown = dmdown * per + dm;
        TI_REAL di_up = dmup;
        TI_REAL di_down = dmdown;
        TI_REAL dm_diff = fabs(di_up - di_down);
        TI_REAL dm_sum = di_up + di_down;
        TI_REAL dx = dm_diff / dm_sum * 100;
        if (i-period < period-2) {
            adx += dx;
        } else if (i-period == period-2) {
            adx += dx;
            ti_buffer_qpush(adxr, adx * invper);
        } else {
            adx = adx * per + dx;
            if (i >= first_adxr) {
                *output++ = 0.5 * (adx * invper + ti_buffer_get(adxr, 1));
            }
            ti_buffer_qpush(adxr, adx * invper);
        }
    }
    ti_buffer_free(adxr);
    assert(output - outputs[0] == size - ti_adxr_start(options));
    return TI_OKAY;
}
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

int ti_andean_osc_start(TI_REAL const *options)
{
  (void)(options);
  return 0;
}
int ti_andean_osc(int size, TI_REAL const *const *inputs,
                  TI_REAL const *options, TI_REAL *const *outputs)
{
  const TI_REAL *open = inputs[0];
  const TI_REAL *close = inputs[1];
  TI_REAL *bull = outputs[0];
  TI_REAL *bear = outputs[1];
  TI_REAL *signal = outputs[2];
  const int period1 = (int)options[0];
  const int signal_length = (int)options[1];
  if (period1 < 1 || signal_length < 1)
    return TI_INVALID_OPTION;
  double alpha = (float)2 / (float)(period1 + 1);
  double *up1 = (double *)calloc((size_t)size, sizeof(double));
  double *up2 = (double *)calloc((size_t)size, sizeof(double));
  double *dn1 = (double *)calloc((size_t)size, sizeof(double));
  double *dn2 = (double *)calloc((size_t)size, sizeof(double));
  double *max_data = (double *)calloc((size_t)size, sizeof(double));
  for (int i = 1; i < size; i++)
  {
    double double_close = close[i] * close[i];
    double double_open = open[i] * open[i];
    double temp_up1 = up1[i - 1] - ((up1[i - 1] - close[i]) * alpha);
    double temp_arr_up1[3] = {close[i], open[i], temp_up1};
    double max_value1 = max_value(temp_arr_up1, 3);
    up1[i] = isnan(max_value1) ? close[i] : max_value1;
    double temp_up2 = (up2[i - 1] - ((up2[i - 1] - double_close) * alpha));
    double temp_arr_up2[3] = {double_close, double_open, temp_up2};
    double max_value2 = max_value(temp_arr_up2, 3);
    up2[i] = isnan(max_value2) ? double_close : max_value2;
    double temp_dn1 = dn1[i - 1] + ((close[i] - dn1[i - 1]) * alpha);
    double temp_arr_dn1[3] = {close[i], open[i], temp_dn1};
    double min_value3 = min_value(temp_arr_dn1, 3);
    dn1[i] = isnan(min_value3) ? close[i] : min_value3;
    double temp_dn2 = dn2[i - 1] + ((double_close - dn2[i - 1]) * alpha);
    double temp_arr_dn2[3] = {double_close, double_open, temp_dn2};
    double min_value4 = min_value(temp_arr_dn2, 3);
    dn2[i] = isnan(min_value4) ? double_close : min_value4;
  }
  for (int i = 0; i < size; i++)
  {
    bull[i] = sqrt(dn2[i] - (dn1[i] * dn1[i]));
    bear[i] = sqrt(up2[i] - (up1[i] * up1[i]));
  }
  for (int i = 0; i < size; i++)
    max_data[i] = fmax(bull[i], bear[i]);
  const double signal_options[] = {signal_length};
  const double *signal_inputs[] = {max_data};
  double *signal_outputs[] = {signal};
  int error2 = ti_ema(size, signal_inputs, signal_options, signal_outputs);
  assert(error2 == TI_OKAY);
  free(up1);
  free(up2);
  free(dn1);
  free(dn2);
  free(max_data);
  return TI_OKAY;
}
int ti_ao_start(TI_REAL const *options) {
    (void)options;
    return 33;
}
int ti_ao(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const int period = 34;
    TI_REAL *output = outputs[0];
    if (size <= ti_ao_start(options)) return TI_OKAY;
    TI_REAL sum34 = 0;
    TI_REAL sum5 = 0;
    const TI_REAL per34 = 1.0 / 34.0;
    const TI_REAL per5 = 1.0 / 5.0;
    int i;
    for (i = 0; i < 34; ++i) {
        TI_REAL hl = 0.5 * (high[i] + low[i]);
        sum34 += hl;
        if (i >= 29) sum5 += hl;
    }
    *output++ = (per5 * sum5 - per34 * sum34);
    for (i = period; i < size; ++i) {
        TI_REAL hl = 0.5 * (high[i] + low[i]);
        sum34 += hl;
        sum5 += hl;
        sum34 -= 0.5 * (high[i-34] + low[i-34]);
        sum5 -= 0.5 * (high[i-5] + low[i-5]);
        *output++ = (per5 * sum5 - per34 * sum34);
    }
    assert(output - outputs[0] == size - ti_ao_start(options));
    return TI_OKAY;
}
int ti_apo_start(TI_REAL const *options) {
    (void)options;
    return 1;
}
int ti_apo(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    TI_REAL *apo = outputs[0];
    const int short_period = (int)options[0];
    const int long_period = (int)options[1];
    if (short_period < 1) return TI_INVALID_OPTION;
    if (long_period < 2) return TI_INVALID_OPTION;
    if (long_period < short_period) return TI_INVALID_OPTION;
    if (size <= ti_apo_start(options)) return TI_OKAY;
    TI_REAL short_per = 2 / ((TI_REAL)short_period + 1);
    TI_REAL long_per = 2 / ((TI_REAL)long_period + 1);
    TI_REAL short_ema = input[0];
    TI_REAL long_ema = input[0];
    int i;
    for (i = 1; i < size; ++i) {
        short_ema = (input[i]-short_ema) * short_per + short_ema;
        long_ema = (input[i]-long_ema) * long_per + long_ema;
        const TI_REAL out = short_ema - long_ema;
        *apo++ = out;
    }
    assert(apo - outputs[0] == size - ti_apo_start(options));
    return TI_OKAY;
}
int ti_aroon_start(TI_REAL const *options) {
    return (int)options[0];
}
int ti_aroon(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    TI_REAL *adown = outputs[0];
    TI_REAL *aup = outputs[1];
    const int period = (int)options[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_aroon_start(options)) return TI_OKAY;
    const TI_REAL scale = 100.0 / period;
    int trail = 0, maxi = -1, mini = -1;
    TI_REAL max = high[0];
    TI_REAL min = low[0];
    TI_REAL bar;
    int i, j;
    for (i = period; i < size; ++i, ++trail) {
        bar = high[i];
        if (maxi < trail) {
            maxi = trail;
            max = high[maxi];
            j = trail;
            while(++j <= i) {
                bar = high[j];
                if (bar >= max) {
                    max = bar;
                    maxi = j;
                }
            }
        } else if (bar >= max) {
            maxi = i;
            max = bar;
        }
        bar = low[i];
        if (mini < trail) {
            mini = trail;
            min = low[mini];
            j = trail;
            while(++j <= i) {
                bar = low[j];
                if (bar <= min) {
                    min = bar;
                    mini = j;
                }
            }
        } else if (bar <= min) {
            mini = i;
            min = bar;
        }
        *adown++ = ((TI_REAL)period - (i-mini)) * scale;
        *aup++ = ((TI_REAL)period - (i-maxi)) * scale;
    }
    assert(adown - outputs[0] == size - ti_aroon_start(options));
    assert(aup - outputs[1] == size - ti_aroon_start(options));
    return TI_OKAY;
}
int ti_aroonosc_start(TI_REAL const *options) {
    return (int)options[0];
}
int ti_aroonosc(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    TI_REAL *output = outputs[0];
    const int period = (int)options[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_aroon_start(options)) return TI_OKAY;
    const TI_REAL scale = 100.0 / period;
    int trail = 0, maxi = -1, mini = -1;
    TI_REAL max = high[0];
    TI_REAL min = low[0];
    int i, j;
    for (i = period; i < size; ++i, ++trail) {
        TI_REAL bar = high[i];
        if (maxi < trail) {
            maxi = trail;
            max = high[maxi];
            j = trail;
            while(++j <= i) {
                bar = high[j];
                if (bar >= max) {
                    max = bar;
                    maxi = j;
                }
            }
        } else if (bar >= max) {
            maxi = i;
            max = bar;
        }
        bar = low[i];
        if (mini < trail) {
            mini = trail;
            min = low[mini];
            j = trail;
            while(++j <= i) {
                bar = low[j];
                if (bar <= min) {
                    min = bar;
                    mini = j;
                }
            }
        } else if (bar <= min) {
            mini = i;
            min = bar;
        }
        *output++ = (maxi-mini) * scale;
    }
    assert(output - outputs[0] == size - ti_aroonosc_start(options));
    return TI_OKAY;
}
int ti_asin_start(TI_REAL const *options) { (void)options; return 0; } int ti_asin(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (asin(in1[i])); } return TI_OKAY; }
int ti_atan_start(TI_REAL const *options) { (void)options; return 0; } int ti_atan(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (atan(in1[i])); } return TI_OKAY; }

int ti_atr_start(TI_REAL const *options)
{
    return (int)options[0] - 1;
}
int ti_atr(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs)
{
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1)
        return TI_INVALID_OPTION;
    if (size <= ti_atr_start(options))
        return TI_OKAY;
    const TI_REAL per = 1.0 / ((TI_REAL)period);
    TI_REAL sum = 0;
    TI_REAL truerange;
    sum += high[0] - low[0];
    int i;
    for (i = 1; i < period; ++i)
    {
        do{ const TI_REAL l = low[i]; const TI_REAL h = high[i]; const TI_REAL c = close[i-1]; const TI_REAL ych = fabs(h - c); const TI_REAL ycl = fabs(l - c); TI_REAL v = h - l; if (ych > v) v = ych; if (ycl > v) v = ycl; truerange = v;}while(0);
        sum += truerange;
    }
    TI_REAL val = sum / period;
    *output++ = val;
    for (i = period; i < size; ++i)
    {
        do{ const TI_REAL l = low[i]; const TI_REAL h = high[i]; const TI_REAL c = close[i-1]; const TI_REAL ych = fabs(h - c); const TI_REAL ycl = fabs(l - c); TI_REAL v = h - l; if (ych > v) v = ych; if (ycl > v) v = ycl; truerange = v;}while(0);
        val = (truerange - val) * per + val;
        *output++ = val;
    }
    assert(output - outputs[0] == size - ti_atr_start(options));
    return TI_OKAY;
}
int ti_atr_ref(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs)
{
    const int period = (int)options[0];
    if (period < 1)
        return TI_INVALID_OPTION;
    if (size <= ti_atr_start(options))
        return TI_OKAY;
    const int tr_start = ti_tr_start(options);
    const int tr_size = size - tr_start;
    TI_REAL *truerange = malloc((unsigned int)tr_size * sizeof(TI_REAL));
    if (!truerange)
        return TI_OUT_OF_MEMORY;
    TI_REAL *tr_outputs[1] = {truerange};
    const int tr_ret = ti_tr(size, inputs, 0, tr_outputs);
    if (tr_ret != TI_OKAY)
    {
        free(truerange);
        return tr_ret;
    }
    const TI_REAL *wilders_inputs[1] = {truerange};
    const int wilders_ret = ti_wilders(tr_size, wilders_inputs, options, outputs);
    free(truerange);
    assert(size - ti_atr_start(options) == size - ti_wilders_start(options));
    return wilders_ret;
}
typedef struct ti_stream_atr
{
    int index;
    int progress;
    int period;
    TI_REAL sum;
    TI_REAL last;
    TI_REAL last_close;
} ti_stream_atr;
int ti_atr_stream_new(TI_REAL const *options, ti_stream **stream_in)
{
    ti_stream_atr **stream = (ti_stream_atr **)stream_in;
    const int period = (int)options[0];
    if (period < 1)
        return TI_INVALID_OPTION;
    *stream = malloc(sizeof(ti_stream_atr));
    if (!*stream)
        return TI_OUT_OF_MEMORY;
    (*stream)->index = TI_INDICATOR_ATR_INDEX;
    (*stream)->progress = -ti_atr_start(options);
    (*stream)->period = period;
    (*stream)->sum = 0.0;
    return TI_OKAY;
}
int ti_atr_stream_run(ti_stream *stream_in, int size, TI_REAL const *const *inputs, TI_REAL *const *outputs)
{
    ti_stream_atr *stream = (ti_stream_atr *)stream_in;
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    TI_REAL *output = outputs[0];
    const TI_REAL per = 1.0 / ((TI_REAL)stream->period);
    const int start = -(stream->period - 1);
    int i = 0;
    if (stream->progress < 1)
    {
        if (stream->progress == start)
        {
            stream->sum = high[0] - low[0];
            stream->last_close = close[0];
            ++stream->progress;
            ++i;
        }
        while (stream->progress <= 0 && i < size)
        {
            TI_REAL truerange;
            do { const TI_REAL ych = fabs((high[i]) - (stream->last_close)); const TI_REAL ycl = fabs((low[i]) - (stream->last_close)); TI_REAL v = (high[i]) - (low[i]); if (ych > v) v = ych; if (ycl > v) v = ycl; truerange = v; } while (0);
            stream->sum += truerange;
            stream->last_close = close[i];
            ++stream->progress;
            ++i;
        }
        if (stream->progress == 1)
        {
            const TI_REAL val = stream->sum * per;
            stream->last = val;
            *output++ = val;
        }
    }
    if (stream->progress >= 1)
    {
        TI_REAL val = stream->last;
        while (i < size)
        {
            TI_REAL truerange;
            do { const TI_REAL ych = fabs((high[i]) - (stream->last_close)); const TI_REAL ycl = fabs((low[i]) - (stream->last_close)); TI_REAL v = (high[i]) - (low[i]); if (ych > v) v = ych; if (ycl > v) v = ycl; truerange = v; } while (0);
            val = (truerange - val) * per + val;
            *output++ = val;
            stream->last_close = close[i];
            ++stream->progress;
            ++i;
        }
        stream->last = val;
    }
    return TI_OKAY;
}
void ti_atr_stream_free(ti_stream *stream)
{
    free(stream);
}
int ti_avgprice_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_avgprice(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *open = inputs[0];
    const TI_REAL *high = inputs[1];
    const TI_REAL *low = inputs[2];
    const TI_REAL *close = inputs[3];
    (void)options;
    TI_REAL *output = outputs[0];
    int i;
    for (i = 0; i < size; ++i) {
        output[i] = (open[i] + high[i] + low[i] + close[i]) * 0.25;
    }
    return TI_OKAY;
}
int ti_bbands_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_bbands(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    TI_REAL *lower = outputs[0];
    TI_REAL *middle = outputs[1];
    TI_REAL *upper = outputs[2];
    const int period = (int)options[0];
    const TI_REAL stddev = options[1];
    const TI_REAL scale = 1.0 / period;
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_bbands_start(options)) return TI_OKAY;
    TI_REAL sum = 0;
    TI_REAL sum2 = 0;
    int i;
    for (i = 0; i < period; ++i) {
        sum += input[i];
        sum2 += input[i] * input[i];
    }
    TI_REAL sd = sqrt(sum2 * scale - (sum * scale) * (sum * scale));
    *middle = sum * scale;
    *lower++ = *middle - stddev * sd;
    *upper++ = *middle + stddev * sd;
    ++middle;
    for (i = period; i < size; ++i) {
        sum += input[i];
        sum2 += input[i] * input[i];
        sum -= input[i-period];
        sum2 -= input[i-period] * input[i-period];
        sd = sqrt(sum2 * scale - (sum * scale) * (sum * scale));
        *middle = sum * scale;
        *upper++ = *middle + stddev * sd;
        *lower++ = *middle - stddev * sd;
        ++middle;
    }
    assert(lower - outputs[0] == size - ti_bbands_start(options));
    assert(middle - outputs[1] == size - ti_bbands_start(options));
    assert(upper - outputs[2] == size - ti_bbands_start(options));
    return TI_OKAY;
}
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

int ti_boom_pro_start(TI_REAL const *options)
{
  (void)(options);
  return 0;
}
int ti_boom_pro(int size, TI_REAL const *const *inputs, TI_REAL const *options,
                TI_REAL *const *outputs)
{
  const TI_REAL *close = inputs[0];
  double *trigger = outputs[0];
  double *q4 = outputs[1];
  const int LPPeriod = (int)options[0];
  const double K1_quotient = (double)options[1];
  const int trigno = (int)options[2];
  const int LPPeriod2 = (int)options[3];
  const double K22_eot = (double)options[4];
  if (LPPeriod < 1 || LPPeriod2 < 1)
    return TI_INVALID_OPTION;
  double *alpha1 = (double *)calloc((unsigned long)size, sizeof(double));
  double *HP = (double *)calloc((unsigned long)size, sizeof(double));
  double *a1 = (double *)calloc((unsigned long)size, sizeof(double));
  double *b1 = (double *)calloc((unsigned long)size, sizeof(double));
  double *c1 = (double *)calloc((unsigned long)size, sizeof(double));
  double *c2 = (double *)calloc((unsigned long)size, sizeof(double));
  double *c3 = (double *)calloc((unsigned long)size, sizeof(double));
  double *Filt = (double *)calloc((unsigned long)size, sizeof(double));
  double *Peak = (double *)calloc((unsigned long)size, sizeof(double));
  double *a12 = (double *)calloc((unsigned long)size, sizeof(double));
  double *b12 = (double *)calloc((unsigned long)size, sizeof(double));
  double *c12 = (double *)calloc((unsigned long)size, sizeof(double));
  double *c22 = (double *)calloc((unsigned long)size, sizeof(double));
  double *c32 = (double *)calloc((unsigned long)size, sizeof(double));
  double *Filt2 = (double *)calloc((unsigned long)size, sizeof(double));
  double *Peak2 = (double *)calloc((unsigned long)size, sizeof(double));
  double *X = (double *)calloc((unsigned long)size, sizeof(double));
  double *Quotient1 = (double *)calloc((unsigned long)size, sizeof(double));
  double *X2 = (double *)calloc((unsigned long)size, sizeof(double));
  double *Quotient4 = (double *)calloc((unsigned long)size, sizeof(double));
  double *q1 = (double *)calloc((unsigned long)size, sizeof(double));
  double esize = 60;
  double ey = 50;
  double pi = (double)2 * asin((double)1);
  for (int i = 2; i < size; i++)
  {
    alpha1[i] =
        (float)(cos(0.707 * 2 * pi / 100) + sin(0.707 * 2 * pi / 100) - 1) /
        cos(0.707 * 2 * pi / 100);
    HP[i] = ((1 - (float)alpha1[i] / 2) * (1 - (float)alpha1[i] / 2) *
             (close[i] - (2 * close[i - 1]) + close[i - 2])) +
            (2 * (1 - alpha1[i]) * not_zero(HP[i - 1], 0)) -
            ((1 - alpha1[i]) * (1 - alpha1[i]) * not_zero(HP[i - 2], 0));
    a1[i] = exp(-1.414 * pi / LPPeriod);
    b1[i] = 2 * a1[i] * cos(1.414 * pi / LPPeriod);
    c2[i] = b1[i];
    c3[i] = -1 * a1[i] * a1[i];
    c1[i] = 1 - c2[i] - c3[i];
    Filt[i] = (c1[i] * (HP[i] + not_zero(HP[i - 1], 0)) / 2) +
              (c2[i] * not_zero(Filt[i - 1], 0)) +
              (c3[i] * not_zero(Filt[i - 2], 0));
    Peak[i] = 0.991 * not_zero(Peak[i - 1], 0);
    if (fabs(Filt[i]) > Peak[i])
      Peak[i] = fabs(Filt[i]);
    if (Peak[i] != 0)
      X[i] = Filt[i] / Peak[i];
    Quotient1[i] = (X[i] + K1_quotient) / (K1_quotient * X[i] + 1);
    a12[i] = exp(-1.414 * pi / LPPeriod2);
    b12[i] = 2 * a12[i] * cos(1.414 * pi / LPPeriod2);
    c22[i] = b12[i];
    c32[i] = -a12[i] * a12[i];
    c12[i] = 1 - c22[i] - c32[i];
    Filt2[i] = (c12[i] * (HP[i] + not_zero(HP[i - 1], 0)) / 2) +
               (c22[i] * not_zero(Filt2[i - 1], 0)) +
               (c32[i] * not_zero(Filt2[i - 2], 0));
    Peak2[i] = 0.991 * not_zero(Peak2[i - 1], 0);
    if (fabs(Filt2[i]) > Peak2[i])
      Peak2[i] = fabs(Filt2[i]);
    if (Peak2[i] != 0)
      X2[i] = Filt2[i] / Peak2[i];
    Quotient4[i] = (X2[i] + K22_eot) / (K22_eot * X2[i] + 1);
    q4[i] = Quotient4[i] * esize + ey;
    q1[i] = Quotient1[i] * esize + ey;
  }
  const double nz_trigger_options[] = {trigno};
  double *nz_trigger = (double *)calloc((unsigned long)size, sizeof(double));
  const double *nz_trigger_inputs[] = {q1};
  double *nz_trigger_outputs[] = {nz_trigger};
  int error8 =
      ti_sma(size, nz_trigger_inputs, nz_trigger_options, nz_trigger_outputs);
  assert(error8 == TI_OKAY);
  const double *trigger_inputs[] = {nz_trigger};
  double *trigger_outputs[] = {trigger};
  int range101 = trigno - 1;
  double value101 = 0;
  const double trigger_options[] = {value101, range101};
  int error101 =
      ti_unshift(size, trigger_inputs, trigger_options, trigger_outputs);
  assert(error101 == TI_OKAY);
  free(alpha1);
  free(HP);
  free(a1);
  free(b1);
  free(c1);
  free(c2);
  free(c3);
  free(Filt);
  free(Peak);
  free(a12);
  free(b12);
  free(c12);
  free(c22);
  free(c32);
  free(Filt2);
  free(Peak2);
  free(X);
  free(Quotient1);
  free(X2);
  free(Quotient4);
  free(q1);
  free(nz_trigger);
  return TI_OKAY;
}
int ti_bop_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_bop(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *open = inputs[0];
    const TI_REAL *high = inputs[1];
    const TI_REAL *low = inputs[2];
    const TI_REAL *close = inputs[3];
    (void)options;
    TI_REAL *output = outputs[0];
    int i;
    for (i = 0; i < size; ++i) {
        TI_REAL hl = high[i] - low[i];
        if (hl <= 0.0) {
            output[i] = 0;
        } else {
            output[i] = (close[i] - open[i]) / hl;
        }
    }
    return TI_OKAY;
}
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

int ti_braid_filter_start(TI_REAL const *options)
{
  (void)(options);
  return 0;
}
int ti_braid_filter(int size, TI_REAL const *const *inputs,
                    TI_REAL const *options,
                    TI_REAL *const *outputs)
{
  const TI_REAL *open = inputs[0];
  const TI_REAL *high = inputs[1];
  const TI_REAL *low = inputs[2];
  const TI_REAL *close = inputs[3];
  TI_REAL *dif = outputs[0];
  TI_REAL *atr_filter = outputs[1];
  TI_REAL *braid_color = outputs[2];
  const int ma01_length = (int)options[0];
  const int ma02_length = (int)options[1];
  const int ma03_length = (int)options[2];
  const int atr_length = (int)14;
  const double PipsMinSepPercent = (float)options[3];
  if (ma01_length < 1 || ma02_length < 1 || ma03_length < 1)
    return TI_INVALID_OPTION;
  double *max = (double *)calloc((unsigned long)size, sizeof(double));
  double *min = (double *)calloc((unsigned long)size, sizeof(double));
  const double ma01_options[] = {ma01_length};
  double *ma01 = (double *)calloc((unsigned long)size, sizeof(double));
  const double *ma01_inputs[] = {close};
  double *ma01_outputs[] = {ma01};
  int error2 = ti_ema(size, ma01_inputs, ma01_options, ma01_outputs);
  assert(error2 == TI_OKAY);
  const double ma02_options[] = {ma02_length};
  double *ma02 = (double *)calloc((unsigned long)size, sizeof(double));
  const double *ma02_inputs[] = {open};
  double *ma02_outputs[] = {ma02};
  int error3 = ti_ema(size, ma02_inputs, ma02_options, ma02_outputs);
  assert(error3 == TI_OKAY);
  const double ma03_options[] = {ma03_length};
  double *ma03 = (double *)calloc((unsigned long)size, sizeof(double));
  const double *ma03_inputs[] = {close};
  double *ma03_outputs[] = {ma03};
  int error4 = ti_ema(size, ma03_inputs, ma03_options, ma03_outputs);
  assert(error4 == TI_OKAY);
  const double nz_atr_options[] = {atr_length};
  double *nz_atr = malloc((unsigned int)size * sizeof(double));
  assert(nz_atr != 0);
  const double *nz_atr_inputs[] = {high, low, close};
  double *nz_atr_outputs[] = {nz_atr};
  int error = ti_atr(size, nz_atr_inputs, nz_atr_options, nz_atr_outputs);
  assert(error == TI_OKAY);
  double *atr = (double *)calloc((unsigned long)size, sizeof(double));
  const double *atr_inputs[] = {nz_atr};
  double *atr_outputs[] = {atr};
  int range = atr_length - 1;
  double value = 0;
  const double atr_options[] = {value, range};
  int error1 = ti_unshift(size, atr_inputs, atr_options, atr_outputs);
  assert(error1 == TI_OKAY);
  for (int i = 0; i < size; i++)
  {
    double temp_ma_arr[3] = {ma01[i], ma02[i], ma03[i]};
    max[i] = max_value(temp_ma_arr, 3);
    min[i] = min_value(temp_ma_arr, 3);
    dif[i] = max[i] - min[i];
    atr_filter[i] = atr[i] * PipsMinSepPercent / 100;
  }
  for (int i = 0; i < size; i++)
    if (ma01[i] > ma02[i] && dif[i] > atr_filter[i])
      braid_color[i] = TI_GREEN;
    else if (ma02[i] > ma01[i] && dif[i] > atr_filter[i])
      braid_color[i] = TI_RED;
    else
      braid_color[i] = TI_NOTHING;
  free(max);
  free(min);
  free(ma01);
  free(ma02);
  free(ma03);
  free(nz_atr);
  free(atr);
  return TI_OKAY;
}
int ti_cci_start(TI_REAL const *options) {
    const int period = (int)options[0];
    return (period-1) * 2;
}
int ti_cci(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    const int period = (int)options[0];
    const TI_REAL scale = 1.0 / period;
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_cci_start(options)) return TI_OKAY;
    TI_REAL *output = outputs[0];
    ti_buffer *sum = ti_buffer_new(period);
    int i, j;
    for (i = 0; i < size; ++i) {
        const TI_REAL today = ((high[(i)] + low[(i)] + close[(i)]) * (1.0/3.0));
        ti_buffer_push(sum, today);
        const TI_REAL avg = sum->sum * scale;
        if (i >= period * 2 - 2) {
            TI_REAL acc = 0;
            for (j = 0; j < period; ++j) {
                acc += fabs(avg - sum->vals[j]);
            }
            TI_REAL cci = acc * scale;
            cci *= .015;
            cci = (today-avg)/cci;
            *output++ = cci;
        }
    }
    ti_buffer_free(sum);
    assert(output - outputs[0] == size - ti_cci_start(options));
    return TI_OKAY;
}
int ti_ceil_start(TI_REAL const *options) { (void)options; return 0; } int ti_ceil(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (ceil(in1[i])); } return TI_OKAY; }
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

int ti_chaikin_vol_start(TI_REAL const *options)
{
    (void)(options);
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
    const double ema_options[] = {ema_period};
    double *ema = malloc((unsigned int)size * sizeof(double));
    assert(ema != 0);
    const double *ema_inputs[] = {diff};
    double *ema_outputs[] = {ema};
    int error = ti_ema(size, ema_inputs, ema_options, ema_outputs);
    assert(error == TI_OKAY);
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

int ti_chandelier_exit_start(TI_REAL const *options)
{
  (void)(options);
  return 0;
}
int ti_chandelier_exit(int size, TI_REAL const *const *inputs,
                       TI_REAL const *options, TI_REAL *const *outputs)
{
  const TI_REAL *high = inputs[0];
  const TI_REAL *low = inputs[1];
  const TI_REAL *close = inputs[2];
  TI_REAL *ce_signal = outputs[0];
  const int period = (int)options[0];
  const double atr_multiplier = (double)options[1];
  if (period < 1)
    return TI_INVALID_OPTION;
  const double nz_atr_options[] = {options[0]};
  double *nz_atr = malloc((unsigned int)size * sizeof(double));
  assert(nz_atr != 0);
  const double *nz_atr_inputs[] = {high, low, close};
  double *nz_atr_outputs[] = {nz_atr};
  int error = ti_atr(size, nz_atr_inputs, nz_atr_options, nz_atr_outputs);
  assert(error == TI_OKAY);
  double *atr = (double *)calloc((size_t)size, sizeof(double));
  const double *atr_inputs[] = {nz_atr};
  double *atr_outputs[] = {atr};
  int range = period - 1;
  double value = 0;
  const double atr_options[] = {value, range};
  int error1 = ti_unshift(size, atr_inputs, atr_options, atr_outputs);
  assert(error1 == TI_OKAY);
  double *longstop_new = (double *)calloc((size_t)size, sizeof(double));
  double *shortstop_new = (double *)calloc((size_t)size, sizeof(double));
  double *direc = (double *)calloc((size_t)size, sizeof(double));
  double *longstop = (double *)calloc((size_t)size, sizeof(double));
  double *shortstop = (double *)calloc((size_t)size, sizeof(double));
  for (int i = 0; i < size; i++)
    ce_signal[i] = TI_NOTHING;
  for (int i = 0; i < size; i++)
  {
    longstop[i] = high[i] - (atr_multiplier * atr[i]);
    shortstop[i] = low[i] + (atr_multiplier * atr[i]);
  }
  for (int i = 1; i < size; i++)
  {
    if (close[i - 1] > longstop_new[i - 1])
      longstop_new[i] = fmax(longstop[i], longstop_new[i - 1]);
    else
      longstop_new[i] = longstop[i];
    if (close[i - 1] < shortstop_new[i - 1])
      shortstop_new[i] = fmin(shortstop[i], shortstop_new[i - 1]);
    else
      shortstop_new[i] = shortstop[i];
  }
  for (int i = 1; i < size; i++)
  {
    if (close[i] > shortstop_new[i - 1])
      direc[i] = 1;
    else if (close[i] < longstop_new[i - 1])
      direc[i] = -1;
    else
      direc[i] = direc[i - 1];
  }
  for (int i = 1; i < size; i++)
  {
    if (direc[i] == 1 && direc[i - 1] == -1)
      ce_signal[i] = TI_BUY;
    else if (direc[i] == -1 && direc[i - 1] == 1)
      ce_signal[i] = TI_SELL;
    else
      ce_signal[i] = TI_NOTHING;
  }
  free(nz_atr);
  free(atr);
  free(longstop_new);
  free(shortstop_new);
  free(direc);
  free(longstop);
  free(shortstop);
  return TI_OKAY;
}
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

int ti_cm_ema_trendbars_start(TI_REAL const *options)
{
  (void)(options);
  return 0;
}
int ti_cm_ema_trendbars(int size, TI_REAL const *const *inputs,
                        TI_REAL const *options, TI_REAL *const *outputs)
{
  (void)(options);
  const TI_REAL *high = inputs[0];
  const TI_REAL *low = inputs[1];
  const TI_REAL *close = inputs[2];
  TI_REAL *usedema = outputs[0];
  TI_REAL *bar_color = outputs[1];
  const int ema_length = (int)options[0];
  if (ema_length < 1)
    return TI_INVALID_OPTION;
  double *hlc3 = (double *)calloc((size_t)size, sizeof(double));
  const double ema_options[] = {ema_length};
  const double *ema_inputs[] = {close};
  double *ema_outputs[] = {usedema};
  int error2 = ti_ema(size, ema_inputs, ema_options, ema_outputs);
  assert(error2 == TI_OKAY);
  const double hlc3_options[] = {0};
  const double *hlc3_inputs[] = {high, low, close};
  double *hlc3_outputs[] = {hlc3};
  int error3 = ti_hlc3(size, hlc3_inputs, hlc3_options, hlc3_outputs);
  assert(error3 == TI_OKAY);
  for (int i = 0; i < size; i++)
    if (hlc3[i] >= not_zero(usedema[i], (double)0))
      bar_color[i] = TI_BUY;
    else if (hlc3[i] < not_zero(usedema[i], (double)0))
      bar_color[i] = TI_SELL;
    else
      bar_color[i] = TI_NOTHING;
  free(hlc3);
  return TI_OKAY;
}
int ti_cmo_start(TI_REAL const *options) {
    return (int)options[0];
}
int ti_cmo(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    TI_REAL *output = outputs[0];
    const int period = (int)options[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_cmo_start(options)) return TI_OKAY;
    TI_REAL up_sum = 0, down_sum = 0;
    int i;
    for (i = 1; i <= period; ++i) {
        up_sum += (input[(i)] > input[(i)-1] ? input[(i)] - input[(i)-1] : 0);
        down_sum += (input[(i)] < input[(i)-1] ? input[(i)-1] - input[(i)] : 0);
    }
    *output++ = 100 * (up_sum - down_sum) / (up_sum + down_sum);
    for (i = period+1; i < size; ++i) {
        up_sum -= (input[(i-period)] > input[(i-period)-1] ? input[(i-period)] - input[(i-period)-1] : 0);
        down_sum -= (input[(i-period)] < input[(i-period)-1] ? input[(i-period)-1] - input[(i-period)] : 0);
        up_sum += (input[(i)] > input[(i)-1] ? input[(i)] - input[(i)-1] : 0);
        down_sum += (input[(i)] < input[(i)-1] ? input[(i)-1] - input[(i)] : 0);
        *output++ = 100 * (up_sum - down_sum) / (up_sum + down_sum);
    }
    assert(output - outputs[0] == size - ti_cmo_start(options));
    return TI_OKAY;
}
int ti_cos_start(TI_REAL const *options) { (void)options; return 0; } int ti_cos(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (cos(in1[i])); } return TI_OKAY; }
int ti_cosh_start(TI_REAL const *options) { (void)options; return 0; } int ti_cosh(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (cosh(in1[i])); } return TI_OKAY; }
int ti_crossany_start(TI_REAL const *options) {
    (void)options;
    return 1;
}
int ti_crossany(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *a = inputs[0];
    const TI_REAL *b = inputs[1];
    (void)options;
    TI_REAL *output = outputs[0];
    int i;
    for (i = 1; i < size; ++i) {
        *output++ = (a[i] > b[i] && a[i-1] <= b[i-1])
                 || (a[i] < b[i] && a[i-1] >= b[i-1]);
    }
    return TI_OKAY;
}
int ti_crossover_start(TI_REAL const *options) {
    (void)options;
    return 1;
}
int ti_crossover(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *a = inputs[0];
    const TI_REAL *b = inputs[1];
    (void)options;
    TI_REAL *output = outputs[0];
    int i;
    for (i = 1; i < size; ++i) {
        *output++ = a[i] > b[i] && a[i-1] <= b[i-1];
    }
    return TI_OKAY;
}
int ti_cvi_start(TI_REAL const *options) {
    const int n = (int)options[0];
    return n*2-1;
}
int ti_cvi(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_cvi_start(options)) return TI_OKAY;
    const TI_REAL per = 2 / ((TI_REAL)period + 1);
    ti_buffer *lag = ti_buffer_new(period);
    TI_REAL val = high[0]-low[0];
    int i;
    for (i = 1; i < period*2-1; ++i) {
        val = ((high[i]-low[i])-val) * per + val;
        ti_buffer_qpush(lag, val);
    }
    for (i = period*2-1; i < size; ++i) {
        val = ((high[i]-low[i])-val) * per + val;
        const TI_REAL old = lag->vals[lag->index];
        *output++ = 100.0 * (val - old) / old;
        ti_buffer_qpush(lag, val);
    }
    ti_buffer_free(lag);
    assert(output - outputs[0] == size - ti_cvi_start(options));
    return TI_OKAY;
}
int ti_decay_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_decay(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    TI_REAL *output = outputs[0];
    const int period = (int)options[0];
    const TI_REAL scale = 1.0 / period;
    *output++ = input[0];
    int i;
    for (i = 1; i < size; ++i) {
        TI_REAL d = output[-1] - scale;
        *output++ = input[i] > d ? input[i] : d;
    }
    return TI_OKAY;
}
int ti_dema_start(TI_REAL const *options) {
    const int period = (int)options[0];
    return (period-1) * 2;
}
int ti_dema(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_dema_start(options)) return TI_OKAY;
    const TI_REAL per = 2 / ((TI_REAL)period + 1);
    const TI_REAL per1 = 1.0 - per;
    TI_REAL ema = input[0];
    TI_REAL ema2 = ema;
    int i;
    for (i = 0; i < size; ++i) {
        ema = ema * per1 + input[i] * per;
        if (i == period-1) {
            ema2 = ema;
        }
        if (i >= period-1) {
            ema2 = ema2 * per1 + ema * per;
            if (i >= (period-1) * 2) {
                *output = ema * 2 - ema2;
                ++output;
            }
        }
    }
    assert(output - outputs[0] == size - ti_dema_start(options));
    return TI_OKAY;
}
int ti_di_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_di(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    const int period = (int)options[0];
    TI_REAL *plus_di = outputs[0];
    TI_REAL *minus_di = outputs[1];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_di_start(options)) return TI_OKAY;
    const TI_REAL per = ((TI_REAL)period-1) / ((TI_REAL)period);
    TI_REAL atr = 0;
    TI_REAL dmup = 0;
    TI_REAL dmdown = 0;
    int i;
    for (i = 1; i < period; ++i) {
        TI_REAL truerange;
        do{ const TI_REAL l = low[i]; const TI_REAL h = high[i]; const TI_REAL c = close[i-1]; const TI_REAL ych = fabs(h - c); const TI_REAL ycl = fabs(l - c); TI_REAL v = h - l; if (ych > v) v = ych; if (ycl > v) v = ycl; truerange = v;}while(0);
        atr += truerange;
        TI_REAL dp, dm;
        do { dp = high[i] - high[i-1]; dm = low[i-1] - low[i]; if (dp < 0) dp = 0; else if (dp > dm) dm = 0; if (dm < 0) dm = 0; else if (dm > dp) dp = 0;} while (0);
        dmup += dp;
        dmdown += dm;
    }
    *plus_di++ = 100.0 * dmup / atr;
    *minus_di++ = 100.0 * dmdown / atr;
    for (i = period; i < size; ++i) {
        TI_REAL truerange;
        do{ const TI_REAL l = low[i]; const TI_REAL h = high[i]; const TI_REAL c = close[i-1]; const TI_REAL ych = fabs(h - c); const TI_REAL ycl = fabs(l - c); TI_REAL v = h - l; if (ych > v) v = ych; if (ycl > v) v = ycl; truerange = v;}while(0);
        atr = atr * per + truerange;
        TI_REAL dp, dm;
        do { dp = high[i] - high[i-1]; dm = low[i-1] - low[i]; if (dp < 0) dp = 0; else if (dp > dm) dm = 0; if (dm < 0) dm = 0; else if (dm > dp) dp = 0;} while (0);
        dmup = dmup * per + dp;
        dmdown = dmdown * per + dm;
        *plus_di++ = 100.0 * dmup / atr;
        *minus_di++ = 100.0 * dmdown / atr;
    }
    assert(plus_di - outputs[0] == size - ti_di_start(options));
    assert(minus_di - outputs[1] == size - ti_di_start(options));
    return TI_OKAY;
}
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

int ti_di_dx_start(TI_REAL const *options)
{
    (void)(options);
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
int ti_div_start(TI_REAL const *options) { (void)options; return 0; } int ti_div(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; const TI_REAL *in2 = inputs[1]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (in1[i] / in2[i]); } return TI_OKAY; }
int ti_dm_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_dm(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const int period = (int)options[0];
    TI_REAL *plus_dm = outputs[0];
    TI_REAL *minus_dm = outputs[1];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_dm_start(options)) return TI_OKAY;
    const TI_REAL per = ((TI_REAL)period-1) / ((TI_REAL)period);
    TI_REAL dmup = 0;
    TI_REAL dmdown = 0;
    int i;
    for (i = 1; i < period; ++i) {
        TI_REAL dp, dm;
        do { dp = high[i] - high[i-1]; dm = low[i-1] - low[i]; if (dp < 0) dp = 0; else if (dp > dm) dm = 0; if (dm < 0) dm = 0; else if (dm > dp) dp = 0;} while (0);
        dmup += dp;
        dmdown += dm;
    }
    *plus_dm++ = dmup;
    *minus_dm++ = dmdown;
    for (i = period; i < size; ++i) {
        TI_REAL dp, dm;
        do { dp = high[i] - high[i-1]; dm = low[i-1] - low[i]; if (dp < 0) dp = 0; else if (dp > dm) dm = 0; if (dm < 0) dm = 0; else if (dm > dp) dp = 0;} while (0);
        dmup = dmup * per + dp;
        dmdown = dmdown * per + dm;
        *plus_dm++ = dmup;
        *minus_dm++ = dmdown;
    }
    assert(plus_dm - outputs[0] == size - ti_dm_start(options));
    assert(minus_dm - outputs[1] == size - ti_dm_start(options));
    return TI_OKAY;
}
int ti_dpo_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_dpo(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    const int back = period / 2 + 1;
    TI_REAL *output = outputs[0];
    const TI_REAL scale = 1.0 / period;
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_dpo_start(options)) return TI_OKAY;
    TI_REAL sum = 0;
    int i;
    for (i = 0; i < period; ++i) {
        sum += input[i];
    }
    *output++ = input[period-1-back] - (sum * scale);
    for (i = period; i < size; ++i) {
        sum += input[i];
        sum -= input[i-period];
        *output++ = input[i-back] - (sum * scale);
    }
    assert(output - outputs[0] == size - ti_dpo_start(options));
    return TI_OKAY;
}
int ti_dx_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_dx(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_dx_start(options)) return TI_OKAY;
    const TI_REAL per = ((TI_REAL)period-1) / ((TI_REAL)period);
    TI_REAL dmup = 0;
    TI_REAL dmdown = 0;
    int i;
    for (i = 1; i < period; ++i) {
        TI_REAL dp, dm;
        do { dp = high[i] - high[i-1]; dm = low[i-1] - low[i]; if (dp < 0) dp = 0; else if (dp > dm) dm = 0; if (dm < 0) dm = 0; else if (dm > dp) dp = 0;} while (0);
        dmup += dp;
        dmdown += dm;
    }
    {
        TI_REAL di_up = dmup;
        TI_REAL di_down = dmdown;
        TI_REAL dm_diff = fabs(di_up - di_down);
        TI_REAL dm_sum = di_up + di_down;
        TI_REAL dx = dm_diff / dm_sum * 100;
        *output++ = dx;
    }
    for (i = period; i < size; ++i) {
        TI_REAL dp, dm;
        do { dp = high[i] - high[i-1]; dm = low[i-1] - low[i]; if (dp < 0) dp = 0; else if (dp > dm) dm = 0; if (dm < 0) dm = 0; else if (dm > dp) dp = 0;} while (0);
        dmup = dmup * per + dp;
        dmdown = dmdown * per + dm;
        TI_REAL di_up = dmup;
        TI_REAL di_down = dmdown;
        TI_REAL dm_diff = fabs(di_up - di_down);
        TI_REAL dm_sum = di_up + di_down;
        TI_REAL dx = dm_diff / dm_sum * 100;
        *output++ = dx;
    }
    assert(output - outputs[0] == size - ti_dx_start(options));
    return TI_OKAY;
}
int ti_edecay_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_edecay(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    const TI_REAL scale = 1.0 - 1.0 / period;
    *output++ = input[0];
    int i;
    for (i = 1; i < size; ++i) {
        TI_REAL d = output[-1] * scale;
        *output++ = input[i] > d ? input[i] : d;
    }
    return TI_OKAY;
}
int ti_ema_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_ema(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_ema_start(options)) return TI_OKAY;
    const TI_REAL per = 2 / ((TI_REAL)period + 1);
    TI_REAL val = input[0];
    *output++ = val;
    int i;
    for (i = 1; i < size; ++i) {
        val = (input[i]-val) * per + val;
        *output++ = val;
    }
    assert(output - outputs[0] == size - ti_ema_start(options));
    return TI_OKAY;
}
int ti_emv_start(TI_REAL const *options) {
    (void)options;
    return 1;
}
int ti_emv(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *volume = inputs[2];
    (void)options;
    TI_REAL *output = outputs[0];
    if (size <= ti_emv_start(options)) return TI_OKAY;
    TI_REAL last = (high[0] + low[0]) * 0.5;
    int i;
    for (i = 1; i < size; ++i) {
        TI_REAL hl = (high[i] + low[i]) * 0.5;
        TI_REAL br = volume[i] / 10000.0 / (high[i] - low[i]);
        *output++ = (hl - last) / br;
        last = hl;
    }
    assert(output - outputs[0] == size - ti_emv_start(options));
    return TI_OKAY;
}
int ti_exp_start(TI_REAL const *options) { (void)options; return 0; } int ti_exp(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (exp(in1[i])); } return TI_OKAY; }
int ti_fisher_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_fisher(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    TI_REAL *fisher = outputs[0];
    TI_REAL *signal = outputs[1];
    const int period = (int)options[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_fisher_start(options)) return TI_OKAY;
    int trail = 0, maxi = -1, mini = -1;
    TI_REAL max = (0.5 * (high[(0)] + low[(0)]));
    TI_REAL min = (0.5 * (high[(0)] + low[(0)]));
    TI_REAL val1 = 0.0;
    TI_REAL bar;
    TI_REAL fish = 0.0;
    int i, j;
    for (i = period-1; i < size; ++i, ++trail) {
        bar = (0.5 * (high[(i)] + low[(i)]));
        if (maxi < trail) {
            maxi = trail;
            max = (0.5 * (high[(maxi)] + low[(maxi)]));
            j = trail;
            while(++j <= i) {
                bar = (0.5 * (high[(j)] + low[(j)]));
                if (bar >= max) {
                    max = bar;
                    maxi = j;
                }
            }
        } else if (bar >= max) {
            maxi = i;
            max = bar;
        }
        bar = (0.5 * (high[(i)] + low[(i)]));
        if (mini < trail) {
            mini = trail;
            min = (0.5 * (high[(mini)] + low[(mini)]));
            j = trail;
            while(++j <= i) {
                bar = (0.5 * (high[(j)] + low[(j)]));
                if (bar <= min) {
                    min = bar;
                    mini = j;
                }
            }
        } else if (bar <= min) {
            mini = i;
            min = bar;
        }
        TI_REAL mm = max - min;
        if (mm == 0.0) mm = 0.001;
        val1 = 0.33 * 2.0 * ( ((0.5 * (high[(i)] + low[(i)]))-min) / (mm) - 0.5) + 0.67 * val1;
        if (val1 > 0.99) val1 = .999;
        if (val1 < -0.99) val1 = -.999;
        *signal++ = fish;
        fish = 0.5 * log((1.0+val1)/(1.0-val1)) + 0.5 * fish;
        *fisher++ = fish;
    }
    assert(fisher - outputs[0] == size - ti_fisher_start(options));
    assert(signal - outputs[1] == size - ti_fisher_start(options));
    return TI_OKAY;
}
int ti_floor_start(TI_REAL const *options) { (void)options; return 0; } int ti_floor(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (floor(in1[i])); } return TI_OKAY; }
int ti_fosc_start(TI_REAL const *options) {
    return (int)options[0];
}
int ti_fosc(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_fosc_start(options)) return TI_OKAY;
    do { TI_REAL x = 0; TI_REAL x2 = 0; TI_REAL y = 0; TI_REAL xy = 0; const TI_REAL p = (1.0 / (period)); TI_REAL tsf = 0;; int i; for (i = 0; i < (period)-1; ++i) { x += i+1; x2 += (i+1)*(i+1); xy += (input)[i] * (i+1); y += (input)[i]; } x += (period); x2 += (period) * (period); const TI_REAL bd = 1.0 / ((period) * x2 - x * x); for (i = (period)-1; i < (size); ++i) { xy += (input)[i] * (period); y += (input)[i]; const TI_REAL b = ((period) * xy - x * y) * bd; do { const TI_REAL a = (y - b * x) * p; if (i >= (period)) {*output++ = 100 * (input[i] - tsf) / input[i];} tsf = (a + b * ((period+1))); } while (0); xy -= y; y -= (input)[i-(period)+1]; } } while (0);
    assert(output - outputs[0] == size - ti_fosc_start(options));
    return TI_OKAY;
}
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

int ti_ha_start(TI_REAL const *options) {
  (void)(options);
  return 0;
}
int ti_ha(int size, TI_REAL const *const *inputs, TI_REAL const *options,
          TI_REAL *const *outputs) {
  (void)(options);
  const TI_REAL *open = inputs[0];
  const TI_REAL *high = inputs[1];
  const TI_REAL *low = inputs[2];
  const TI_REAL *close = inputs[3];
  TI_REAL *HA_open = outputs[0];
  TI_REAL *HA_high = outputs[1];
  TI_REAL *HA_low = outputs[2];
  TI_REAL *HA_close = outputs[3];
  for (int i = 0; i < size; i++)
    HA_close[i] = (open[i] + high[i] + low[i] + close[i]) / 4;
  HA_open[0] = (open[0] + HA_close[0]) / 2;
  for (int j = 1; j < size; j++)
    HA_open[j] = (HA_open[j - 1] + HA_close[j - 1]) / 2;
  for (int z = 0; z < size; z++) {
    double temp_arr1[3] = {high[z], HA_close[z], HA_open[z]};
    double max_data = max_value(temp_arr1, 3);
    HA_high[z] = max_data;
    double temp_arr2[3] = {low[z], HA_close[z], HA_open[z]};
    double min_data = min_value(temp_arr2, 3);
    HA_low[z] = min_data;
  }
  return TI_OKAY;
}
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

int ti_half_trend_start(TI_REAL const *options)
{
  (void)(options);
  return 0;
}
int ti_half_trend(int size, TI_REAL const *const *inputs,
                  TI_REAL const *options, TI_REAL *const *outputs)
{
  const TI_REAL *high = inputs[0];
  const TI_REAL *low = inputs[1];
  const TI_REAL *close = inputs[2];
  double *ht = outputs[0];
  double *ht_color = outputs[1];
  const int amplitude = (int)options[0];
  const double channelDeviation = (double)options[1];
  const int atr_length = (int)options[2];
  if (amplitude < 0 || channelDeviation < 0)
    return TI_INVALID_OPTION;
  const double nz_atr_options[] = {atr_length};
  double *nz_atr = malloc((unsigned int)size * sizeof(double));
  assert(nz_atr != 0);
  const double *nz_atr_inputs[] = {high, low, close};
  double *nz_atr_outputs[] = {nz_atr};
  int error = ti_atr(size, nz_atr_inputs, nz_atr_options, nz_atr_outputs);
  assert(error == TI_OKAY);
  double *atr = (double *)calloc((size_t)size, sizeof(double));
  const double *atr_inputs[] = {nz_atr};
  double *atr_outputs[] = {atr};
  int range1 = atr_length - 1;
  double value1 = 0;
  const double atr_options[] = {value1, range1};
  int error1 = ti_unshift(size, atr_inputs, atr_options, atr_outputs);
  assert(error1 == TI_OKAY);
  double *dev = (double *)calloc((size_t)size, sizeof(double));
  for (int i = 0; i < size; i++)
    dev[i] = (float)atr[i] / 2 * channelDeviation;
  const double nz_highma_options[] = {amplitude};
  double *nz_highma = (double *)calloc((size_t)size, sizeof(double));
  const double *nz_highma_inputs[] = {high};
  double *nz_highma_outputs[] = {nz_highma};
  int error9 =
      ti_sma(size, nz_highma_inputs, nz_highma_options, nz_highma_outputs);
  assert(error9 == TI_OKAY);
  double *highma = (double *)calloc((size_t)size, sizeof(double));
  const double *highma_inputs[] = {nz_highma};
  double *highma_outputs[] = {highma};
  int range10 = amplitude - 1;
  double value10 = 0;
  const double highma_options[] = {value10, range10};
  int error10 = ti_unshift(size, highma_inputs, highma_options, highma_outputs);
  assert(error10 == TI_OKAY);
  const double nz_lowma_options[] = {amplitude};
  double *nz_lowma = (double *)calloc((size_t)size, sizeof(double));
  const double *nz_lowma_inputs[] = {low};
  double *nz_lowma_outputs[] = {nz_lowma};
  int error8 =
      ti_sma(size, nz_lowma_inputs, nz_lowma_options, nz_lowma_outputs);
  assert(error8 == TI_OKAY);
  double *lowma = (double *)calloc((size_t)size, sizeof(double));
  const double *lowma_inputs[] = {nz_lowma};
  double *lowma_outputs[] = {lowma};
  int range101 = amplitude - 1;
  double value101 = 0;
  const double lowma_options[] = {value101, range101};
  int error101 = ti_unshift(size, lowma_inputs, lowma_options, lowma_outputs);
  assert(error101 == TI_OKAY);
  double *trend = (double *)calloc((size_t)size, sizeof(double));
  double *nextTrend = (double *)calloc((size_t)size, sizeof(double));
  double *maxLowPrice = (double *)calloc((size_t)size, sizeof(double));
  double *minHighPrice = (double *)calloc((size_t)size, sizeof(double));
  double *up = (double *)calloc((size_t)size, sizeof(double));
  double *down = (double *)calloc((size_t)size, sizeof(double));
  double *atrHigh = (double *)calloc((size_t)size, sizeof(double));
  double *atrLow = (double *)calloc((size_t)size, sizeof(double));
  maxLowPrice[0] = low[0];
  minHighPrice[0] = high[0];
  const double nz_highPrice_options[] = {amplitude};
  double *nz_highPrice = malloc((unsigned int)size * sizeof(double));
  assert(nz_highPrice != 0);
  const double *nz_highPrice_inputs[] = {high};
  double *nz_highPrice_outputs[] = {nz_highPrice};
  int error44 = ti_max(size, nz_highPrice_inputs, nz_highPrice_options,
                       nz_highPrice_outputs);
  assert(error44 == TI_OKAY);
  double *highPrice = (double *)calloc((size_t)size, sizeof(double));
  const double *highPrice_inputs[] = {nz_highPrice};
  double *highPrice_outputs[] = {highPrice};
  int range16 = amplitude - 1;
  double value16 = 0;
  const double highPrice_options[] = {value16, range16};
  int error56 =
      ti_unshift(size, highPrice_inputs, highPrice_options, highPrice_outputs);
  assert(error56 == TI_OKAY);
  const double nz_lowPrice_options[] = {amplitude};
  double *nz_lowPrice = malloc((unsigned int)size * sizeof(double));
  assert(nz_lowPrice != 0);
  const double *nz_lowPrice_inputs[] = {low};
  double *nz_lowPrice_outputs[] = {nz_lowPrice};
  int error66 = ti_min(size, nz_lowPrice_inputs, nz_lowPrice_options,
                       nz_lowPrice_outputs);
  assert(error66 == TI_OKAY);
  double *lowPrice = (double *)calloc((size_t)size, sizeof(double));
  const double *lowPrice_inputs[] = {nz_lowPrice};
  double *lowPrice_outputs[] = {lowPrice};
  int range33 = amplitude - 1;
  double value33 = 0;
  const double lowPrice_options[] = {value33, range33};
  int error73 =
      ti_unshift(size, lowPrice_inputs, lowPrice_options, lowPrice_outputs);
  assert(error73 == TI_OKAY);
  for (int i = 1; i < size; i++)
  {
    if (nextTrend[i - 1] == 1)
    {
      maxLowPrice[i] = fmax(lowPrice[i], maxLowPrice[i - 1]);
      if (highma[i] < maxLowPrice[i] &&
          close[i] < not_zero(low[i - 1], low[i]))
      {
        trend[i] = 1;
        nextTrend[i] = 0;
        minHighPrice[i] = highPrice[i];
      }
      else
      {
        trend[i] = trend[i - 1];
        nextTrend[i] = nextTrend[i - 1];
        minHighPrice[i] = minHighPrice[i - 1];
      }
    }
    else
    {
      minHighPrice[i] = fmin(highPrice[i], minHighPrice[i - 1]);
      if (lowma[i] > minHighPrice[i] &&
          close[i] > not_zero(high[i - 1], high[i]))
      {
        trend[i] = 0;
        nextTrend[i] = 1;
        maxLowPrice[i] = lowPrice[i];
      }
      else
      {
        trend[i] = trend[i - 1];
        nextTrend[i] = nextTrend[i - 1];
        maxLowPrice[i] = maxLowPrice[i - 1];
      }
    }
    if (trend[i] == 0)
    {
      if (trend[i - 1] != 0)
        up[i] = down[i - 1];
      else
        up[i] = fmax(maxLowPrice[i], up[i - 1]);
      atrHigh[i] = up[i] + dev[i];
      atrLow[i] = up[i] - dev[i];
    }
    else
    {
      if (trend[i - 1] != 1)
        down[i] = up[i - 1];
      else
        down[i] = fmin(minHighPrice[i], down[i - 1]);
      atrHigh[i] = down[i] + dev[i];
      atrLow[i] = down[i] - dev[i];
    }
  }
  for (int i = 0; i < size; i++)
  {
    if (trend == 0)
    {
      ht[i] = up[i];
      ht_color[i] = TI_GREEN;
    }
    else
    {
      ht[i] = down[i];
      ht_color[i] = TI_RED;
    }
  }
  free(nz_atr);
  free(atr);
  free(dev);
  free(nz_highma);
  free(highma);
  free(nz_lowma);
  free(lowma);
  free(trend);
  free(nextTrend);
  free(maxLowPrice);
  free(minHighPrice);
  free(up);
  free(down);
  free(atrHigh);
  free(atrLow);
  free(nz_highPrice);
  free(highPrice);
  free(nz_lowPrice);
  free(lowPrice);
  return TI_OKAY;
}
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

int ti_heatmap_vol_start(TI_REAL const *options)
{
  (void)(options);
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

int ti_hlc3_start(TI_REAL const *options) {
  (void)(options);
  return 0;
}
int ti_hlc3(int size, TI_REAL const *const *inputs, TI_REAL const *options,
            TI_REAL *const *outputs) {
  (void)(options);
  const TI_REAL *high = inputs[0];
  const TI_REAL *low = inputs[1];
  const TI_REAL *close = inputs[2];
  TI_REAL *output = outputs[0];
  for (int i = 0; i < size; i++)
    *output++ = (high[i] + low[i] + close[i]) / 3;
  return TI_OKAY;
}
int ti_hma_start(TI_REAL const *options) {
    const int period = (int)options[0];
    const int periodsqrt = (int)(sqrt(period));
    return period + periodsqrt - 2;
}
int ti_hma(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_hma_start(options)) return TI_OKAY;
    const int period2 = (int)(period / 2);
    const int periodsqrt = (int)(sqrt(period));
    const TI_REAL weights = period * (period+1) / 2;
    const TI_REAL weights2 = period2 * (period2+1) / 2;
    const TI_REAL weightssqrt = periodsqrt * (periodsqrt+1) / 2;
    TI_REAL sum = 0;
    TI_REAL weight_sum = 0;
    TI_REAL sum2 = 0;
    TI_REAL weight_sum2 = 0;
    TI_REAL sumsqrt = 0;
    TI_REAL weight_sumsqrt = 0;
    int i;
    for (i = 0; i < period-1; ++i) {
        weight_sum += input[i] * (i+1);
        sum += input[i];
        if (i >= period - period2) {
            weight_sum2 += input[i] * (i+1-(period-period2));
            sum2 += input[i];
        }
    }
    ti_buffer *buff = ti_buffer_new(periodsqrt);
    for (i = period-1; i < size; ++i) {
        weight_sum += input[i] * period;
        sum += input[i];
        weight_sum2 += input[i] * period2;
        sum2 += input[i];
        const TI_REAL wma = weight_sum / weights;
        const TI_REAL wma2 = weight_sum2 / weights2;
        const TI_REAL diff = 2 * wma2 - wma;
        weight_sumsqrt += diff * periodsqrt;
        sumsqrt += diff;
        ti_buffer_qpush(buff, diff);
        if (i >= (period-1) + (periodsqrt-1)) {
            *output++ = weight_sumsqrt / weightssqrt;
            weight_sumsqrt -= sumsqrt;
            sumsqrt -= ti_buffer_get(buff, 1);
        } else {
            weight_sumsqrt -= sumsqrt;
        }
        weight_sum -= sum;
        sum -= input[i-period+1];
        weight_sum2 -= sum2;
        sum2 -= input[i-period2+1];
    }
    ti_buffer_free(buff);
    assert(output - outputs[0] == size - ti_hma_start(options));
    return TI_OKAY;
}
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

int ti_hull_suite_start(TI_REAL const *options)
{
  (void)(options);
  return 0;
}
int ti_hull_suite(int size, TI_REAL const *const *inputs,
                  TI_REAL const *options, TI_REAL *const *outputs)
{
  const TI_REAL *close = inputs[0];
  double *bar_color = outputs[0];
  const int hma_length = (int)options[0];
  if (hma_length < 1)
    return TI_INVALID_OPTION;
  double *SHULL = (double *)calloc((size_t)size, sizeof(double));
  const double nz_hma_options[] = {options[0]};
  double *nz_hma = malloc((unsigned int)size * sizeof(double));
  assert(nz_hma != 0);
  const double *nz_hma_inputs[] = {close};
  double *nz_hma_outputs[] = {nz_hma};
  int error = ti_hma(size, nz_hma_inputs, nz_hma_options, nz_hma_outputs);
  assert(error == TI_OKAY);
  double *hma = (double *)calloc((size_t)size, sizeof(double));
  const double *hma_inputs[] = {nz_hma};
  double *hma_outputs[] = {hma};
  int range = hma_length - 2 + (int)floor(sqrt(hma_length));
  double value = 0;
  const double hma_options[] = {value, range};
  int error1 = ti_unshift(size, hma_inputs, hma_options, hma_outputs);
  assert(error1 == TI_OKAY);
  for (int i = 2; i < size; i++)
    SHULL[i] = hma[i - 2];
  for (int i = 0; i < size; i++)
    if (hma[i] > SHULL[i])
      bar_color[i] = TI_GREEN;
    else
      bar_color[i] = TI_RED;
  free(SHULL);
  free(nz_hma);
  free(hma);
  return TI_OKAY;
}
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

int ti_insidebar_start(TI_REAL const *options)
{
  (void)(options);
  return 0;
}
int ti_insidebar(int size, TI_REAL const *const *inputs, TI_REAL const *options,
                 TI_REAL *const *outputs)
{
  (void)(options);
  const TI_REAL *open = inputs[0];
  const TI_REAL *high = inputs[1];
  const TI_REAL *low = inputs[2];
  const TI_REAL *close = inputs[3];
  double *bar_color = outputs[0];
  double *bodyStatus = (double *)calloc((size_t)size, sizeof(double));
  double *isInsidePattern = (double *)calloc((size_t)size, sizeof(double));
  int bullishBar = 1;
  int bearishBar = -1;
  for (int i = 0; i < size; i++)
    if (close[i] >= open[i])
      bodyStatus[i] = bullishBar;
    else
      bodyStatus[i] = bearishBar;
  for (int i = 1; i < size; i++)
    if (high[i] < high[i - 1] && low[i] > low[i - 1])
      isInsidePattern[i] = bodyStatus[i];
    else
      isInsidePattern[i] = 0;
  for (int i = 0; i < size; i++)
    if (isInsidePattern[i] == 1)
      bar_color[i] = TI_BUY;
    else if (isInsidePattern[i] == -1)
      bar_color[i] = TI_SELL;
    else
      bar_color[i] = TI_NOTHING;
  free(bodyStatus);
  free(isInsidePattern);
  return TI_OKAY;
}
int ti_kama_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_kama(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_kama_start(options)) return TI_OKAY;
    const TI_REAL short_per = 2 / (2.0 + 1);
    const TI_REAL long_per = 2 / (30.0 + 1);
    TI_REAL sum = 0;
    int i;
    for (i = 1; i < period; ++i) {
        sum += fabs(input[i] - input[i-1]);
    }
    TI_REAL kama = input[period-1];
    *output++ = kama;
    TI_REAL er, sc;
    for (i = period; i < size; ++i) {
        sum += fabs(input[i] - input[i-1]);
        if (i > period) {
            sum -= fabs(input[i-period] - input[i-period-1]);
        }
        if (sum != 0.0) {
            er = fabs(input[i] - input[i-period]) / sum;
        } else {
            er = 1.0;
        }
        sc = pow(er * (short_per - long_per) + long_per, 2);
        kama = kama + sc * (input[i] - kama);
        *output++ = kama;
    }
    assert(output - outputs[0] == size - ti_kama_start(options));
    return TI_OKAY;
}
int ti_kvo_start(TI_REAL const *options) {
    (void)options;
    return 1;
}
int ti_kvo(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    const TI_REAL *volume = inputs[3];
    const int short_period = (int)options[0];
    const int long_period = (int)options[1];
    if (short_period < 1) return TI_INVALID_OPTION;
    if (long_period < short_period) return TI_INVALID_OPTION;
    if (size <= ti_kvo_start(options)) return TI_OKAY;
    const TI_REAL short_per = 2 / ((TI_REAL)short_period + 1);
    const TI_REAL long_per = 2 / ((TI_REAL)long_period + 1);
    TI_REAL *output = outputs[0];
    TI_REAL cm = 0;
    TI_REAL prev_hlc = high[0] + low[0] + close[0];
    int trend = -1;
    TI_REAL short_ema = 0, long_ema = 0;
    int i;
    for (i = 1; i < size; ++i) {
        const TI_REAL hlc = high[i] + low[i] + close[i];
        const TI_REAL dm = high[i] - low[i];
        if (hlc > prev_hlc && trend != 1) {
            trend = 1;
            cm = high[i-1] - low[i-1];
        } else if (hlc < prev_hlc && trend != 0) {
            trend = 0;
            cm = high[i-1] - low[i-1];
        }
        cm += dm;
        const TI_REAL vf = volume[i] * fabs(dm / cm * 2 - 1) * 100 * (trend ? 1.0 : -1.0);
        if (i == 1) {
            short_ema = vf;
            long_ema = vf;
        } else {
            short_ema = (vf-short_ema) * short_per + short_ema;
            long_ema = (vf-long_ema) * long_per + long_ema;
        }
        *output++ = short_ema - long_ema;
        prev_hlc = hlc;
    }
    assert(output - outputs[0] == size - ti_kvo_start(options));
    return TI_OKAY;
}
int ti_lag_start(TI_REAL const *options) {
    return (int)options[0];
}
int ti_lag(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 0) return TI_INVALID_OPTION;
    if (size <= ti_lag_start(options)) return TI_OKAY;
    int i;
    for (i = period; i < size; ++i) {
        *output++ = input[i-period];
    }
    assert(output - outputs[0] == size - ti_lag_start(options));
    return TI_OKAY;
}
int ti_linreg_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_linreg(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_linreg_start(options)) return TI_OKAY;
    do { TI_REAL x = 0; TI_REAL x2 = 0; TI_REAL y = 0; TI_REAL xy = 0; const TI_REAL p = (1.0 / (period)); int i; for (i = 0; i < (period)-1; ++i) { x += i+1; x2 += (i+1)*(i+1); xy += (input)[i] * (i+1); y += (input)[i]; } x += (period); x2 += (period) * (period); const TI_REAL bd = 1.0 / ((period) * x2 - x * x); for (i = (period)-1; i < (size); ++i) { xy += (input)[i] * (period); y += (input)[i]; const TI_REAL b = ((period) * xy - x * y) * bd; do { const TI_REAL a = (y - b * x) * p; *output++ = (a + b * ((period))); } while (0); xy -= y; y -= (input)[i-(period)+1]; } } while (0);
    assert(output - outputs[0] == size - ti_linreg_start(options));
    return TI_OKAY;
}
int ti_linregintercept_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_linregintercept(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_linregintercept_start(options)) return TI_OKAY;
    do { TI_REAL x = 0; TI_REAL x2 = 0; TI_REAL y = 0; TI_REAL xy = 0; const TI_REAL p = (1.0 / (period)); int i; for (i = 0; i < (period)-1; ++i) { x += i+1; x2 += (i+1)*(i+1); xy += (input)[i] * (i+1); y += (input)[i]; } x += (period); x2 += (period) * (period); const TI_REAL bd = 1.0 / ((period) * x2 - x * x); for (i = (period)-1; i < (size); ++i) { xy += (input)[i] * (period); y += (input)[i]; const TI_REAL b = ((period) * xy - x * y) * bd; do { const TI_REAL a = (y - b * x) * p; *output++ = (a + b * ((1))); } while (0); xy -= y; y -= (input)[i-(period)+1]; } } while (0);
    assert(output - outputs[0] == size - ti_linregintercept_start(options));
    return TI_OKAY;
}
int ti_linregslope_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_linregslope(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_linregslope_start(options)) return TI_OKAY;
    do { TI_REAL x = 0; TI_REAL x2 = 0; TI_REAL y = 0; TI_REAL xy = 0; do{}while(0); int i; for (i = 0; i < (period)-1; ++i) { x += i+1; x2 += (i+1)*(i+1); xy += (input)[i] * (i+1); y += (input)[i]; } x += (period); x2 += (period) * (period); const TI_REAL bd = 1.0 / ((period) * x2 - x * x); for (i = (period)-1; i < (size); ++i) { xy += (input)[i] * (period); y += (input)[i]; const TI_REAL b = ((period) * xy - x * y) * bd; do { *output++ = b; } while (0); xy -= y; y -= (input)[i-(period)+1]; } } while (0);
    assert(output - outputs[0] == size - ti_linregslope_start(options));
    return TI_OKAY;
}
int ti_ln_start(TI_REAL const *options) { (void)options; return 0; } int ti_ln(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (log(in1[i])); } return TI_OKAY; }
int ti_log10_start(TI_REAL const *options) { (void)options; return 0; } int ti_log10(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (log10(in1[i])); } return TI_OKAY; }
int ti_macd_start(TI_REAL const *options) {
    const int long_period = (int)options[1];
    return (long_period-1);
}
int ti_macd(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    TI_REAL *macd = outputs[0];
    TI_REAL *signal = outputs[1];
    TI_REAL *hist = outputs[2];
    const int short_period = (int)options[0];
    const int long_period = (int)options[1];
    const int signal_period = (int)options[2];
    if (short_period < 1) return TI_INVALID_OPTION;
    if (long_period < 2) return TI_INVALID_OPTION;
    if (long_period < short_period) return TI_INVALID_OPTION;
    if (signal_period < 1) return TI_INVALID_OPTION;
    if (size <= ti_macd_start(options)) return TI_OKAY;
    TI_REAL short_per = 2 / ((TI_REAL)short_period + 1);
    TI_REAL long_per = 2 / ((TI_REAL)long_period + 1);
    TI_REAL signal_per = 2 / ((TI_REAL)signal_period + 1);
    if (short_period == 12 && long_period == 26) {
        short_per = 0.15;
        long_per = 0.075;
    }
    TI_REAL short_ema = input[0];
    TI_REAL long_ema = input[0];
    TI_REAL signal_ema = 0;
    int i;
    for (i = 1; i < size; ++i) {
        short_ema = (input[i]-short_ema) * short_per + short_ema;
        long_ema = (input[i]-long_ema) * long_per + long_ema;
        const TI_REAL out = short_ema - long_ema;
        if (i == long_period-1) {
            signal_ema = out;
        }
        if (i >= long_period-1) {
            signal_ema = (out-signal_ema) * signal_per + signal_ema;
            *macd++ = out;
            *signal++ = signal_ema;
            *hist++ = out - signal_ema;
        }
    }
    assert(macd - outputs[0] == size - ti_macd_start(options));
    assert(signal - outputs[1] == size - ti_macd_start(options));
    assert(hist - outputs[2] == size - ti_macd_start(options));
    return TI_OKAY;
}
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

int ti_macd_fastline_divergence_start(TI_REAL const *options)
{
  (void)(options);
  return 0;
}
int ti_macd_fastline_divergence(int size, TI_REAL const *const *inputs,
                                TI_REAL const *options,
                                TI_REAL *const *outputs)
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
  double *fastline = malloc((unsigned int)size * sizeof(double));
  const double *hist_inputs[] = {nz_hist};
  double *hist_outputs[] = {fastline};
  int range = slow_length - 1;
  double value = 0;
  const double fastline_options[] = {value, range};
  int error1 = ti_unshift(size, hist_inputs, fastline_options, hist_outputs);
  assert(error1 == TI_OKAY);
  int *ph_index = (int *)calloc((size_t)size, sizeof(int));
  int *pl_index = (int *)calloc((size_t)size, sizeof(double));
  int pl_count = 1;
  int ph_count = 1;
  int x = 1;
  int y = 1;
  for (int i = 2; i < size; i++)
  {
    if (fastline[i] < 0 && fastline[i - 1] < 0 && fastline[i - 2] < 0 &&
        fastline[i - 2] > fastline[i - 1] && fastline[i - 1] < fastline[i])
    {
      pl_index[x++] = i - 1;
      pl_count += 1;
    }
    else if (fastline[i] > 0 && fastline[i - 1] > 0 && fastline[i - 2] > 0 &&
             fastline[i - 2] < fastline[i - 1] &&
             fastline[i - 1] > fastline[i])
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
        prev_hist = fastline[temp_arr[0]];
        prev_low = low[temp_arr[0]];
        if (fastline[prev_index] < fastline[cur_index] &&
            low[prev_index] > low[cur_index])
          bull[cur_index] = TI_BULL;
        else if (prev_hist != 0 && prev_low != 0)
          if (prev_hist < fastline[cur_index] && prev_low > low[cur_index])
            bull[cur_index] = TI_BULL;
      }
    }
    if (i == ph_count - 1)
    {
      int _start_index = ph_index[i];
      int _end_index = size - 1;
      int *_temp_arr = calloc((size_t)size, sizeof(int));
      int *_temp_arr_size = calloc((size_t)1, sizeof(int));
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
          _prev_hist = fastline[_temp_arr[0]];
          _prev_low = low[_temp_arr[0]];
          if (fastline[_prev_index] < fastline[cur_index] &&
              low[_prev_index] > low[cur_index])
            bull[cur_index] = TI_BULL;
          else if (_prev_hist != 0 && _prev_low != 0)
            if (_prev_hist < fastline[cur_index] &&
                _prev_low > low[cur_index])
              bull[cur_index] = TI_BULL;
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
    int *temp_arr = calloc((size_t)size, sizeof(int));
    int *temp_arr_size = calloc((size_t)1, sizeof(int));
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
        prev_hist = fastline[temp_arr[0]];
        prev_high = high[temp_arr[0]];
        if (fastline[prev_index] > fastline[cur_index] &&
            high[prev_index] < high[cur_index])
          bear[cur_index] = TI_BEAR;
        else if (prev_hist != 0 && prev_high != 0)
          if (prev_hist > fastline[cur_index] && prev_high < high[cur_index])
            bear[cur_index] = TI_BEAR;
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
          _prev_hist = fastline[_temp_arr[0]];
          _prev_high = high[_temp_arr[0]];
          if (fastline[_prev_index] > fastline[cur_index] &&
              high[_prev_index] < high[cur_index])
            bear[cur_index] = TI_BEAR;
          else if (_prev_hist != 0 && prev_high != 0)
            if (_prev_hist > fastline[cur_index] &&
                _prev_high < high[cur_index])
              bear[cur_index] = TI_BEAR;
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
  free(fastline);
  free(ph_index);
  free(pl_index);
  return TI_OKAY;
}
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

int ti_macd_hist_divergence_start(TI_REAL const *options)
{
  (void)(options);
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
int ti_marketfi_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_marketfi(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *volume = inputs[2];
    (void)options;
    TI_REAL *output = outputs[0];
    if (size <= ti_marketfi_start(options)) return TI_OKAY;
    int i;
    for (i = 0; i < size; ++i) {
        *output++ = (high[i] - low[i]) / volume[i];
    }
    assert(output - outputs[0] == size - ti_marketfi_start(options));
    return TI_OKAY;
}
int ti_mass_start(TI_REAL const *options) {
    int sum_p = (int)options[0]-1;
    return 16 + sum_p;
}
int ti_mass(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_mass_start(options)) return TI_OKAY;
    const TI_REAL per = 2 / (9.0 + 1);
    const TI_REAL per1 = 1.0 - per;
    TI_REAL ema = high[0] - low[0];
    TI_REAL ema2 = ema;
    ti_buffer *sum = ti_buffer_new(period);
    int i;
    for (i = 0; i < size; ++i) {
        TI_REAL hl = high[i] - low[i];
        ema = ema * per1 + hl * per;
        if (i == 8) {
            ema2 = ema;
        }
        if (i >= 8) {
            ema2 = ema2 * per1 + ema * per;
            if (i >= 16) {
                ti_buffer_push(sum, ema/ema2);
                if (i >= 16 + period - 1) {
                    *output++ = sum->sum;
                }
            }
        }
    }
    ti_buffer_free(sum);
    assert(output - outputs[0] == size - ti_mass_start(options));
    return TI_OKAY;
}
int ti_max_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_max(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_max_start(options)) return TI_OKAY;
    int trail = 0, maxi = -1;
    TI_REAL max = input[0];
    int i, j;
    for (i = period-1; i < size; ++i, ++trail) {
        TI_REAL bar = input[i];
        if (maxi < trail) {
            maxi = trail;
            max = input[maxi];
            j = trail;
            while(++j <= i) {
                bar = input[j];
                if (bar >= max) {
                    max = bar;
                    maxi = j;
                }
            }
        } else if (bar >= max) {
            maxi = i;
            max = bar;
        }
        *output++ = max;
    }
    assert(output - outputs[0] == size - ti_max_start(options));
    return TI_OKAY;
}
int ti_max_ref(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_max_start(options)) return TI_OKAY;
    for (int i = period-1; i < size; ++i) {
        TI_REAL max = input[i-period+1];
        for (int j = i-period+2; j <= i; ++j) {
            max = ((max) > (input[j]) ? (max) : (input[j]));
        }
        *output++ = max;
    }
    return TI_OKAY;
}
int ti_md_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_md(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    const TI_REAL scale = 1.0 / period;
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_md_start(options)) return TI_OKAY;
    TI_REAL sum = 0;
    int i, j;
    for (i = 0; i < size; ++i) {
        const TI_REAL today = input[i];
        sum += today;
        if (i >= period) sum -= input[i-period];
        const TI_REAL avg = sum * scale;
        if (i >= period - 1) {
            TI_REAL acc = 0;
            for (j = 0; j < period; ++j) {
                acc += fabs(avg - input[i-j]);
            }
            *output++ = acc * scale;
        }
    }
    assert(output - outputs[0] == size - ti_md_start(options));
    return TI_OKAY;
}
int ti_medprice_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_medprice(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    (void)options;
    TI_REAL *output = outputs[0];
    int i;
    for (i = 0; i < size; ++i) {
        output[i] = (high[i] + low[i]) * 0.5;
    }
    return TI_OKAY;
}
int ti_mfi_start(TI_REAL const *options) {
    return (int)options[0];
}
int ti_mfi(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    const TI_REAL *volume = inputs[3];
    const int period = (int)options[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_mfi_start(options)) return TI_OKAY;
    TI_REAL *output = outputs[0];
    TI_REAL ytyp = ((high[(0)] + low[(0)] + close[(0)]) * (1.0/3.0));
    int i;
    ti_buffer *up = ti_buffer_new(period);
    ti_buffer *down = ti_buffer_new(period);
    for (i = 1; i < size; ++i) {
        const TI_REAL typ = ((high[(i)] + low[(i)] + close[(i)]) * (1.0/3.0));
        const TI_REAL bar = typ * volume[i];
        if (typ > ytyp) {
            ti_buffer_push(up, bar);
            ti_buffer_push(down, 0.0);
        } else if (typ < ytyp) {
            ti_buffer_push(down, bar);
            ti_buffer_push(up, 0.0);
        } else {
            ti_buffer_push(up, 0.0);
            ti_buffer_push(down, 0.0);
        }
        ytyp = typ;
        if (i >= period) {
            *output++ = up->sum / (up->sum + down->sum) * 100.0;
        }
    }
    ti_buffer_free(up);
    ti_buffer_free(down);
    assert(output - outputs[0] == size - ti_mfi_start(options));
    return TI_OKAY;
}
int ti_min_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_min(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_min_start(options)) return TI_OKAY;
    int trail = 0, mini = -1;
    TI_REAL min = input[0];
    int i, j;
    for (i = period-1; i < size; ++i, ++trail) {
        TI_REAL bar = input[i];
        if (mini < trail) {
            mini = trail;
            min = input[mini];
            j = trail;
            while(++j <= i) {
                bar = input[j];
                if (bar <= min) {
                    min = bar;
                    mini = j;
                }
            }
        } else if (bar <= min) {
            mini = i;
            min = bar;
        }
        *output++ = min;
    }
    assert(output - outputs[0] == size - ti_min_start(options));
    return TI_OKAY;
}
int ti_min_ref(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_min_start(options)) return TI_OKAY;
    for (int i = period-1; i < size; ++i) {
        TI_REAL min = input[i-period+1];
        for (int j = i-period+2; j <= i; ++j) {
            min = ((min) < (input[j]) ? (min) : (input[j]));
        }
        *output++ = min;
    }
    assert(output - outputs[0] == size - ti_min_start(options));
    return TI_OKAY;
}
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

int ti_mobo_band_start(TI_REAL const *options)
{
  (void)(options);
  return 0;
}
int ti_mobo_band(int size, TI_REAL const *const *inputs, TI_REAL const *options,
                 TI_REAL *const *outputs)
{
  const TI_REAL *high = inputs[0];
  const TI_REAL *low = inputs[1];
  TI_REAL *final_signal = outputs[0];
  const int dpolength = (int)options[0];
  const int mobolength = (int)options[1];
  const double numDevDn = (double)options[2];
  const double numDevUp = (double)options[3];
  if (dpolength < 1 || mobolength < 1)
    return TI_INVALID_OPTION;
  double *price1 = (double *)calloc((size_t)size, sizeof(double));
  double *hl2 = (double *)calloc((size_t)size, sizeof(double));
  for (int i = 0; i < size; i++)
    hl2[i] = (float)(high[i] + low[i]) / 2;
  int start_index = (int)floor((float)dpolength / 2 + 1);
  for (int i = start_index; i < size; i++)
    price1[i] = hl2[i - start_index];
  const double nz_xsma_options[] = {dpolength};
  double *nz_xsma = malloc((unsigned int)size * sizeof(double));
  assert(nz_xsma != 0);
  const double *nz_xsma_inputs[] = {price1};
  double *nz_xsma_outputs[] = {nz_xsma};
  int error = ti_sma(size, nz_xsma_inputs, nz_xsma_options, nz_xsma_outputs);
  assert(error == TI_OKAY);
  double *xsma = (double *)calloc((size_t)size, sizeof(double));
  const double *xsma_inputs[] = {nz_xsma};
  double *xsma_outputs[] = {xsma};
  int range1 = dpolength - 1;
  double value1 = 0;
  const double xsma_options[] = {value1, range1};
  int error1 = ti_unshift(size, xsma_inputs, xsma_options, xsma_outputs);
  assert(error1 == TI_OKAY);
  double *DPO = (double *)calloc((size_t)size, sizeof(double));
  for (int i = 0; i < size; i++)
  {
    DPO[i] = hl2[i] - xsma[i];
  }
  const double nz_Midline_options[] = {mobolength};
  double *nz_Midline = malloc((unsigned int)size * sizeof(double));
  assert(nz_Midline != 0);
  const double *nz_Midline_inputs[] = {DPO};
  double *nz_Midline_outputs[] = {nz_Midline};
  int error2 =
      ti_sma(size, nz_Midline_inputs, nz_Midline_options, nz_Midline_outputs);
  assert(error2 == TI_OKAY);
  double *Midline = (double *)calloc((size_t)size, sizeof(double));
  const double *Midline_inputs[] = {nz_Midline};
  double *Midline_outputs[] = {Midline};
  int range2 = dpolength - 1;
  double value2 = 0;
  const double midline_options[] = {value2, range2};
  int error3 =
      ti_unshift(size, Midline_inputs, midline_options, Midline_outputs);
  assert(error3 == TI_OKAY);
  const double nz_sDev_options[] = {mobolength};
  double *nz_sDev = malloc((unsigned int)size * sizeof(double));
  assert(nz_sDev != 0);
  const double *nz_sDev_inputs[] = {DPO};
  double *nz_sDev_outputs[] = {nz_sDev};
  int error4 =
      ti_stddev(size, nz_sDev_inputs, nz_sDev_options, nz_sDev_outputs);
  assert(error4 == TI_OKAY);
  double *sDev = (double *)calloc((size_t)size, sizeof(double));
  const double *sDev_inputs[] = {nz_sDev};
  double *sDev_outputs[] = {sDev};
  int range3 = dpolength - 1;
  double value3 = 0;
  const double sdev_options[] = {value3, range3};
  int error5 = ti_unshift(size, sDev_inputs, sdev_options, sDev_outputs);
  assert(error5 == TI_OKAY);
  double *LowerBand = (double *)calloc((size_t)size, sizeof(double));
  double *UpperBand = (double *)calloc((size_t)size, sizeof(double));
  double *Signal1 = (double *)calloc((size_t)size, sizeof(double));
  double *Signal2 = (double *)calloc((size_t)size, sizeof(double));
  double *wasUp = (double *)calloc((size_t)size, sizeof(double));
  double *wasDn = (double *)calloc((size_t)size, sizeof(double));
  for (int i = 0; i < size; i++)
  {
    LowerBand[i] = Midline[i] + (numDevDn * sDev[i]);
    UpperBand[i] = Midline[i] + (numDevUp * sDev[i]);
  }
  for (int i = 1; i < size; i++)
  {
    double last_DPO = DPO[i];
    double last_second_DPO = DPO[i - 1];
    double last_upper = UpperBand[i];
    double last_second_upper = UpperBand[i - 1];
    double last_lower = LowerBand[i];
    double last_second_lower = LowerBand[i - 1];
    if (last_DPO > last_upper && last_second_DPO < last_second_upper)
    {
      Signal1[i] = 1;
      Signal2[i] = 0;
    }
    else if (last_DPO < last_lower && last_second_DPO > last_second_lower)
    {
      Signal1[i] = 0;
      Signal2[i] = 1;
    }
    else
    {
      Signal1[i] = 0;
      Signal2[i] = 0;
    }
  }
  for (int i = 1; i < size; i++)
  {
    if (Signal1[i] == 1)
    {
      wasUp[i] = 1;
      wasDn[i] = 0;
    }
    else if (Signal2[i] == 1)
    {
      wasUp[i] = 0;
      wasDn[i] = 1;
    }
    else
    {
      wasUp[i] = wasUp[i - 1];
      wasDn[i] = wasDn[i - 1];
    }
  }
  for (int i = 1; i < size; i++)
    if (Signal1[i] == 1 && wasDn[i - 1] == 1)
      final_signal[i] = 1;
    else if (Signal2[i] == 1 && wasUp[i - 1] == 1)
      final_signal[i] = -1;
    else
      final_signal[i] = 0;
  free(price1);
  free(hl2);
  free(nz_xsma);
  free(xsma);
  free(DPO);
  free(nz_Midline);
  free(Midline);
  free(nz_sDev);
  free(sDev);
  free(LowerBand);
  free(UpperBand);
  free(Signal1);
  free(Signal2);
  free(wasUp);
  free(wasDn);
  return TI_OKAY;
}
int ti_mom_start(TI_REAL const *options) {
    return (int)options[0];
}
int ti_mom(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_mom_start(options)) return TI_OKAY;
    int i;
    for (i = period; i < size; ++i) {
        *output++ = input[i] - input[i-period];
    }
    assert(output - outputs[0] == size - ti_mom_start(options));
    return TI_OKAY;
}
int ti_msw_start(TI_REAL const *options) {
    return (int)options[0];
}
int ti_msw(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    TI_REAL *sine = outputs[0];
    TI_REAL *lead = outputs[1];
    const int period = (int)options[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_msw_start(options)) return TI_OKAY;
    const TI_REAL pi = 3.1415926;
    const TI_REAL tpi = 2 * pi;
    TI_REAL weight = 0, phase;
    TI_REAL rp, ip;
    int i, j;
    for (i = period; i < size; ++i) {
        rp = 0;
        ip = 0;
        for (j = 0; j < period; ++j) {
            weight = input[i-j];
            rp = rp + cos(tpi * j / period) * weight;
            ip = ip + sin(tpi * j / period) * weight;
        }
        if (fabs(rp) > .001) {
            phase = atan(ip/rp);
        } else {
            phase = tpi / 2.0 * (ip < 0 ? -1.0 : 1.0);
        }
        if (rp < 0.0) phase += pi;
        phase += pi/2.0;
        if (phase < 0.0) phase += tpi;
        if (phase > tpi) phase -= tpi;
        *sine++ = sin(phase);
        *lead++ = sin(phase + pi/4.0);
    }
    assert(sine - outputs[0] == size - ti_msw_start(options));
    assert(lead - outputs[1] == size - ti_msw_start(options));
    return TI_OKAY;
}
int ti_mul_start(TI_REAL const *options) { (void)options; return 0; } int ti_mul(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; const TI_REAL *in2 = inputs[1]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (in1[i] * in2[i]); } return TI_OKAY; }
int ti_natr_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_natr(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_natr_start(options)) return TI_OKAY;
    const TI_REAL per = 1.0 / ((TI_REAL)period);
    TI_REAL sum = 0;
    TI_REAL truerange;
    sum += high[0] - low[0];
    int i;
    for (i = 1; i < period; ++i) {
        do{ const TI_REAL l = low[i]; const TI_REAL h = high[i]; const TI_REAL c = close[i-1]; const TI_REAL ych = fabs(h - c); const TI_REAL ycl = fabs(l - c); TI_REAL v = h - l; if (ych > v) v = ych; if (ycl > v) v = ycl; truerange = v;}while(0);
        sum += truerange;
    }
    TI_REAL val = sum / period;
    *output++ = 100 * (val) / close[period-1];
    for (i = period; i < size; ++i) {
        do{ const TI_REAL l = low[i]; const TI_REAL h = high[i]; const TI_REAL c = close[i-1]; const TI_REAL ych = fabs(h - c); const TI_REAL ycl = fabs(l - c); TI_REAL v = h - l; if (ych > v) v = ych; if (ycl > v) v = ycl; truerange = v;}while(0);
        val = (truerange-val) * per + val;
        *output++ = 100 * (val) / close[i];
    }
    assert(output - outputs[0] == size - ti_natr_start(options));
    return TI_OKAY;
}
int ti_nvi_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_nvi(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *close = inputs[0];
    const TI_REAL *volume = inputs[1];
    (void)options;
    TI_REAL *output = outputs[0];
    if (size <= ti_nvi_start(options)) return TI_OKAY;
    TI_REAL nvi = 1000;
    *output++ = nvi;
    int i;
    for (i = 1; i < size; ++i) {
        if (volume[i] < volume[i-1]) {
            nvi += ((close[i] - close[i-1])/close[i-1]) * nvi;
        }
        *output++ = nvi;
    }
    assert(output - outputs[0] == size - ti_nvi_start(options));
    return TI_OKAY;
}
int ti_obv_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_obv(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *close = inputs[0];
    const TI_REAL *volume = inputs[1];
    (void)options;
    TI_REAL *output = outputs[0];
    TI_REAL sum = 0;
    *output++ = sum;
    TI_REAL prev = close[0];
    int i;
    for (i = 1; i < size; ++i) {
        if (close[i] > prev) {
            sum += volume[i];
        } else if (close[i] < prev) {
            sum -= volume[i];
        } else {
        }
        prev = close[i];
        *output++ = sum;
    }
    return TI_OKAY;
}
int ti_ppo_start(TI_REAL const *options) {
    (void)options;
    return 1;
}
int ti_ppo(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    TI_REAL *ppo = outputs[0];
    const int short_period = (int)options[0];
    const int long_period = (int)options[1];
    if (short_period < 1) return TI_INVALID_OPTION;
    if (long_period < 2) return TI_INVALID_OPTION;
    if (long_period < short_period) return TI_INVALID_OPTION;
    if (size <= ti_ppo_start(options)) return TI_OKAY;
    TI_REAL short_per = 2 / ((TI_REAL)short_period + 1);
    TI_REAL long_per = 2 / ((TI_REAL)long_period + 1);
    TI_REAL short_ema = input[0];
    TI_REAL long_ema = input[0];
    int i;
    for (i = 1; i < size; ++i) {
        short_ema = (input[i]-short_ema) * short_per + short_ema;
        long_ema = (input[i]-long_ema) * long_per + long_ema;
        const TI_REAL out = 100.0 * (short_ema - long_ema) / long_ema;
        *ppo++ = out;
    }
    assert(ppo - outputs[0] == size - ti_ppo_start(options));
    return TI_OKAY;
}
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

int ti_price_start(TI_REAL const *options)
{
    (void)(options);
    return 0;
}
int ti_price(int size, TI_REAL const *const *inputs, TI_REAL const *options,
                     TI_REAL *const *outputs)
{
    (void)(options);
    const TI_REAL *input = inputs[0];
    TI_REAL *output = outputs[0];
    for (int i = 0; i < size; i++)
    {
        output[i] = input[i];
    }
    return TI_OKAY;
}

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
    _Bool bull = 1;
    double af = accel_start;
    for (int i = 2; i < size; i++)
    {
        if (bull == 1)
        {
            psar[i] = psar[i - 1] + af * (hp - psar[i - 1]);
        }
        else
        {
            psar[i] = psar[i - 1] + af * (lp - psar[i - 1]);
        }
        _Bool reverse = 0;
        if (bull == 1)
        {
            if (low[i] < psar[i])
            {
                bull = 0;
                reverse = 1;
                psar[i] = hp;
                lp = low[i];
                af = accel_start;
            }
        }
        else
        {
            if (high[i] > psar[i])
            {
                bull = 1;
                reverse = 1;
                psar[i] = lp;
                hp = high[i];
                af = accel_start;
            }
        }
        if (reverse == 0)
        {
            if (bull == 1)
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
int ti_pvi_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_pvi(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *close = inputs[0];
    const TI_REAL *volume = inputs[1];
    (void)options;
    TI_REAL *output = outputs[0];
    if (size <= ti_pvi_start(options)) return TI_OKAY;
    TI_REAL pvi = 1000;
    *output++ = pvi;
    int i;
    for (i = 1; i < size; ++i) {
        if (volume[i] > volume[i-1]) {
            pvi += ((close[i] - close[i-1])/close[i-1]) * pvi;
        }
        *output++ = pvi;
    }
    assert(output - outputs[0] == size - ti_pvi_start(options));
    return TI_OKAY;
}
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

int ti_qqe_mod_start(TI_REAL const *options)
{
  (void)(options);
  return 0;
}
int ti_qqe_mod(int size, TI_REAL const *const *inputs, TI_REAL const *options,
               TI_REAL *const *outputs)
{
  const TI_REAL *close = inputs[0];
  double *qqeGreenbar = outputs[0];
  double *qqeRedbar = outputs[1];
  const int rsi_length1 = (int)options[0];
  const int rsi_smoothing1 = (int)options[1];
  const double QQE_factor1 = (double)options[2];
  const int threshold1 = (int)options[3];
  const int rsi_length2 = (int)options[4];
  const int rsi_smoothing2 = (int)options[5];
  const double QQE_factor2 = (double)options[6];
  const int threshold2 = (int)options[7];
  const int bollinger_length = (int)options[8];
  const double QQE_multiplier = (double)options[9];
  if (rsi_length1 < 1 || rsi_smoothing1 < 1 || rsi_length2 < 1 ||
      rsi_smoothing2 < 1 || QQE_factor1 < 1 || threshold1 < 1 ||
      QQE_factor2 < 1 || threshold2 < 1 || bollinger_length < 1 ||
      QQE_multiplier < 0)
    return TI_INVALID_OPTION;
  double Wilders_Period1 = rsi_length1 * 2 - 1;
  const double nz_rsi1_options[] = {rsi_length1};
  double *nz_rsi1 = malloc((unsigned int)size * sizeof(double));
  assert(nz_rsi1 != 0);
  const double *nz_rsi1_inputs[] = {close};
  double *nz_rsi1_outputs[] = {nz_rsi1};
  int error = ti_rsi(size, nz_rsi1_inputs, nz_rsi1_options, nz_rsi1_outputs);
  assert(error == TI_OKAY);
  double *rsi1 = malloc((unsigned int)size * sizeof(double));
  const double *rsi1_inputs[] = {nz_rsi1};
  double *rsi1_outputs[] = {rsi1};
  int range = rsi_length1;
  double value = 0;
  const double rsi1_options[] = {value, range};
  int error1 = ti_unshift(size, rsi1_inputs, rsi1_options, rsi1_outputs);
  assert(error1 == TI_OKAY);
  const double nz_rsi2_options[] = {rsi_length2};
  double *nz_rsi2 = malloc((unsigned int)size * sizeof(double));
  assert(nz_rsi2 != 0);
  const double *nz_rsi2_inputs[] = {close};
  double *nz_rsi2_outputs[] = {nz_rsi2};
  int error2 = ti_rsi(size, nz_rsi2_inputs, nz_rsi2_options, nz_rsi2_outputs);
  assert(error2 == TI_OKAY);
  double *rsi2 = malloc((unsigned int)size * sizeof(double));
  const double *rsi2_inputs[] = {nz_rsi2};
  double *rsi2_outputs[] = {rsi2};
  int range1 = rsi_length2;
  double value1 = 0;
  const double rsi2_options[] = {value1, range1};
  int error3 = ti_unshift(size, rsi2_inputs, rsi2_options, rsi2_outputs);
  assert(error3 == TI_OKAY);
  const double rsima1_options[] = {rsi_smoothing1};
  double *rsima1 = malloc((unsigned int)size * sizeof(double));
  assert(rsima1 != 0);
  const double *rsima1_inputs[] = {rsi1};
  double *rsima1_outputs[] = {rsima1};
  int error4 = ti_ema(size, rsima1_inputs, rsima1_options, rsima1_outputs);
  assert(error4 == TI_OKAY);
  const double rsima2_options[] = {rsi_smoothing2};
  double *rsima2 = malloc((unsigned int)size * sizeof(double));
  assert(rsima2 != 0);
  const double *rsima2_inputs[] = {rsi2};
  double *rsima2_outputs[] = {rsima2};
  int error5 = ti_ema(size, rsima2_inputs, rsima2_options, rsima2_outputs);
  assert(error5 == TI_OKAY);
  double *atr_rsi1 = (double *)calloc((size_t)size, sizeof(double));
  for (int i = 1; i < size; i++)
  {
    atr_rsi1[i] = fabs(rsima1[i] - rsima1[i - 1]);
  }
  const double Ma_atrRsi1_options[] = {Wilders_Period1};
  double *Ma_atrRsi1 = malloc((unsigned int)size * sizeof(double));
  assert(Ma_atrRsi1 != 0);
  const double *Ma_atrRsi1_inputs[] = {atr_rsi1};
  double *Ma_atrRsi1_outputs[] = {Ma_atrRsi1};
  int error6 =
      ti_ema(size, Ma_atrRsi1_inputs, Ma_atrRsi1_options, Ma_atrRsi1_outputs);
  assert(error6 == TI_OKAY);
  const double dar1_options[] = {Wilders_Period1};
  double *dar1 = malloc((unsigned int)size * sizeof(double));
  assert(dar1 != 0);
  const double *dar1_inputs[] = {Ma_atrRsi1};
  double *dar1_outputs[] = {dar1};
  int error7 = ti_ema(size, dar1_inputs, dar1_options, dar1_outputs);
  assert(error7 == TI_OKAY);
  double *newshortband = (double *)calloc((size_t)size, sizeof(double));
  double *newlongband = (double *)calloc((size_t)size, sizeof(double));
  double *longband = (double *)calloc((size_t)size, sizeof(double));
  double *shortband = (double *)calloc((size_t)size, sizeof(double));
  double *trend = (double *)calloc((size_t)size, sizeof(double));
  double *FastAtrRsiTL = (double *)calloc((size_t)size, sizeof(double));
  double *upper = (double *)calloc((size_t)size, sizeof(double));
  double *lower = (double *)calloc((size_t)size, sizeof(double));
  for (int i = 0; i < size; i++)
  {
    newlongband[i] = rsima1[i] - dar1[i] * QQE_factor1;
    newshortband[i] = rsima1[i] + dar1[i] * QQE_factor1;
  }
  for (int i = 1; i < size; i++)
  {
    if (rsima1[i - 1] > longband[i - 1] && rsima1[i] > longband[i - 1])
    {
      longband[i] = fmax(longband[i - 1], newlongband[i]);
    }
    else
    {
      longband[i] = newlongband[i];
    }
    if (rsima1[i - 1] < shortband[i - 1] && rsima1[i] < shortband[i - 1])
    {
      shortband[i] = fmin(shortband[i - 1], newshortband[i]);
    }
    else
    {
      shortband[i] = newshortband[i];
    }
  }
  double *longband_prev = (double *)calloc((size_t)size, sizeof(double));
  double *shortband_prev = (double *)calloc((size_t)size, sizeof(double));
  for (int i = 1; i < size; i++)
  {
    longband_prev[i] = longband[i - 1];
    shortband_prev[i] = shortband[i - 1];
  }
  const double nz_cross_1_options[] = {0};
  double *nz_cross_1 = (double *)calloc((size_t)size, sizeof(double));
  const double *nz_cross_1_inputs[] = {longband_prev, rsima1};
  double *nz_cross_1_outputs[] = {nz_cross_1};
  int error9 = ti_crossany(size, nz_cross_1_inputs, nz_cross_1_options,
                           nz_cross_1_outputs);
  assert(error9 == TI_OKAY);
  double *cross_1 = (double *)calloc((size_t)size, sizeof(double));
  const double *cross_1_inputs[] = {nz_cross_1};
  double *cross_1_outputs[] = {cross_1};
  int range101 = 1;
  double value101 = 0;
  const double cross1_options[] = {value101, range101};
  int error101 =
      ti_unshift(size, cross_1_inputs, cross1_options, cross_1_outputs);
  assert(error101 == TI_OKAY);
  const double nz_cross_2_options[] = {0};
  double *nz_cross_2 = (double *)calloc((size_t)size, sizeof(double));
  const double *nz_cross_2_inputs[] = {rsima1, shortband_prev};
  double *nz_cross_2_outputs[] = {nz_cross_2};
  int error8 = ti_crossany(size, nz_cross_2_inputs, nz_cross_2_options,
                           nz_cross_2_outputs);
  assert(error8 == TI_OKAY);
  double *cross_2 = (double *)calloc((size_t)size, sizeof(double));
  const double *cross_2_inputs[] = {nz_cross_2};
  double *cross_2_outputs[] = {cross_2};
  int range105 = 1;
  double value105 = 0;
  const double cross2_options[] = {value105, range105};
  int error105 =
      ti_unshift(size, cross_2_inputs, cross2_options, cross_2_outputs);
  assert(error105 == TI_OKAY);
  for (int i = 1; i < size; i++)
  {
    if (cross_2[i] == 1)
      trend[i] = 1;
    else if (cross_1[i] == 1)
      trend[i] = -1;
    else
      trend[i] = not_zero(trend[i - 1], 1);
    if (trend[i] == 1)
      FastAtrRsiTL[i] = longband[i] - 50;
    else
      FastAtrRsiTL[i] = shortband[i] - 50;
  }
  const double nz_basis_options[] = {bollinger_length};
  double *nz_basis = malloc((unsigned int)size * sizeof(double));
  assert(nz_basis != 0);
  const double *nz_basis_inputs[] = {FastAtrRsiTL};
  double *nz_basis_outputs[] = {nz_basis};
  int error10 =
      ti_sma(size, nz_basis_inputs, nz_basis_options, nz_basis_outputs);
  assert(error10 == TI_OKAY);
  double *basis = (double *)calloc((size_t)size, sizeof(double));
  const double *basis_inputs[] = {nz_basis};
  double *basis_outputs[] = {basis};
  int range2 = bollinger_length - 1;
  double value2 = 0;
  const double basis_options[] = {value2, range2};
  int error11 = ti_unshift(size, basis_inputs, basis_options, basis_outputs);
  assert(error11 == TI_OKAY);
  const double nz_dev_options[] = {bollinger_length};
  double *nz_dev = malloc((unsigned int)size * sizeof(double));
  assert(nz_dev != 0);
  const double *nz_dev_inputs[] = {FastAtrRsiTL};
  double *nz_dev_outputs[] = {nz_dev};
  int error12 = ti_stddev(size, nz_dev_inputs, nz_dev_options, nz_dev_outputs);
  assert(error12 == TI_OKAY);
  double *dev = (double *)calloc((size_t)size, sizeof(double));
  const double *dev_inputs[] = {nz_dev};
  double *dev_outputs[] = {dev};
  int range3 = bollinger_length - 1;
  double value3 = 0;
  const double dev_options[] = {value3, range3};
  int error13 = ti_unshift(size, dev_inputs, dev_options, dev_outputs);
  assert(error13 == TI_OKAY);
  for (int i = 0; i < size; i++)
  {
    dev[i] = dev[i] * QQE_multiplier;
    upper[i] = basis[i] + dev[i];
    lower[i] = basis[i] - dev[i];
  }
  double *Greenbar1 = (double *)calloc((size_t)size, sizeof(double));
  double *Greenbar2 = (double *)calloc((size_t)size, sizeof(double));
  double *Redbar1 = (double *)calloc((size_t)size, sizeof(double));
  double *Redbar2 = (double *)calloc((size_t)size, sizeof(double));
  for (int z = 0; z < size; z++)
  {
    if (rsima1[z] - 50 > upper[z])
      Greenbar2[z] = 1;
    else
      Greenbar2[z] = 0;
    if (rsima1[z] - 50 < lower[z])
      Redbar2[z] = 1;
    else
      Redbar2[z] = 0;
  }
  for (int z = 0; z < size; z++)
  {
    if (rsima2[z] - 50 > threshold2)
      Greenbar1[z] = 1;
    else
      Greenbar1[z] = 0;
    if (rsima2[z] - 50 < 0 - threshold2)
      Redbar1[z] = 1;
    else
      Redbar1[z] = 0;
  }
  for (int i = 0; i < size; i++)
  {
    if (Greenbar1[i] == 1 && Greenbar2[i] == 1)
      qqeGreenbar[i] = TI_GREEN;
    else
      qqeGreenbar[i] = TI_NOTHING;
    if (Redbar1[i] == 1 && Redbar2[i] == 1)
      qqeRedbar[i] = TI_RED;
    else
      qqeRedbar[i] = TI_NOTHING;
  }
  free(nz_rsi1);
  free(rsi1);
  free(nz_rsi2);
  free(rsi2);
  free(rsima1);
  free(rsima2);
  free(atr_rsi1);
  free(Ma_atrRsi1);
  free(dar1);
  free(newshortband);
  free(newlongband);
  free(longband);
  free(shortband);
  free(trend);
  free(FastAtrRsiTL);
  free(upper);
  free(lower);
  free(longband_prev);
  free(shortband_prev);
  free(nz_cross_1);
  free(cross_1);
  free(nz_cross_2);
  free(cross_2);
  free(nz_basis);
  free(basis);
  free(nz_dev);
  free(dev);
  free(Greenbar1);
  free(Greenbar2);
  free(Redbar1);
  free(Redbar2);
  return TI_OKAY;
}
int ti_qstick_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_qstick(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *open = inputs[0];
    const TI_REAL *close = inputs[1];
    TI_REAL *output = outputs[0];
    const int period = (int)options[0];
    const TI_REAL scale = 1.0 / period;
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_qstick_start(options)) return TI_OKAY;
    TI_REAL sum = 0;
    int i;
    for (i = 0; i < period; ++i) {
        sum += close[i] - open[i];
    }
    *output++ = sum * scale;
    for (i = period; i < size; ++i) {
        sum += close[i] - open[i];
        sum -= close[i-period] - open[i-period];
        *output++ = sum * scale;
    }
    assert(output - outputs[0] == size - ti_qstick_start(options));
    return TI_OKAY;
}
int ti_roc_start(TI_REAL const *options) {
    return (int)options[0];
}
int ti_roc(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_roc_start(options)) return TI_OKAY;
    int i;
    for (i = period; i < size; ++i) {
        *output++ = (input[i] - input[i-period]) / input[i-period];
    }
    assert(output - outputs[0] == size - ti_roc_start(options));
    return TI_OKAY;
}
int ti_rocr_start(TI_REAL const *options) {
    return (int)options[0];
}
int ti_rocr(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_rocr_start(options)) return TI_OKAY;
    int i;
    for (i = period; i < size; ++i) {
        *output++ = input[i] / input[i-period];
    }
    assert(output - outputs[0] == size - ti_rocr_start(options));
    return TI_OKAY;
}
int ti_round_start(TI_REAL const *options) { (void)options; return 0; } int ti_round(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (floor(in1[i] + 0.5)); } return TI_OKAY; }
int ti_rsi_start(TI_REAL const *options) {
    return (int)options[0];
}
int ti_rsi(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    const TI_REAL per = 1.0 / ((TI_REAL)period);
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_rsi_start(options)) return TI_OKAY;
    TI_REAL smooth_up = 0, smooth_down = 0;
    int i;
    for (i = 1; i <= period; ++i) {
        const TI_REAL upward = input[i] > input[i-1] ? input[i] - input[i-1] : 0;
        const TI_REAL downward = input[i] < input[i-1] ? input[i-1] - input[i] : 0;
        smooth_up += upward;
        smooth_down += downward;
    }
    smooth_up /= period;
    smooth_down /= period;
    *output++ = 100.0 * (smooth_up / (smooth_up + smooth_down));
    for (i = period+1; i < size; ++i) {
        const TI_REAL upward = input[i] > input[i-1] ? input[i] - input[i-1] : 0;
        const TI_REAL downward = input[i] < input[i-1] ? input[i-1] - input[i] : 0;
        smooth_up = (upward-smooth_up) * per + smooth_up;
        smooth_down = (downward-smooth_down) * per + smooth_down;
        *output++ = 100.0 * (smooth_up / (smooth_up + smooth_down));
    }
    assert(output - outputs[0] == size - ti_rsi_start(options));
    return TI_OKAY;
}
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

int ti_rsi_divergence_start(TI_REAL const *options)
{
  (void)(options);
  return 0;
}
int ti_rsi_divergence(int size, TI_REAL const *const *inputs,
                      TI_REAL const *options, TI_REAL *const *outputs)
{
  const TI_REAL *high = inputs[0];
  const TI_REAL *low = inputs[1];
  const TI_REAL *close = inputs[2];
  double *bull = outputs[0];
  double *bear = outputs[1];
  const int left_bar = (int)options[0];
  const int right_bar = (int)options[1];
  const int rsi_length = (int)options[2];
  if (rsi_length < 1 || left_bar < 0 || right_bar < 0)
    return TI_INVALID_OPTION;
  for (int i = 0; i < size; i++)
  {
    bull[i] = TI_NOTHING;
    bear[i] = TI_NOTHING;
  }
  const double nz_rsi_options[] = {rsi_length};
  double *nz_rsi = malloc((unsigned int)size * sizeof(double));
  assert(nz_rsi != 0);
  const double *nz_rsi_inputs[] = {close};
  double *nz_rsi_outputs[] = {nz_rsi};
  int error = ti_rsi(size, nz_rsi_inputs, nz_rsi_options, nz_rsi_outputs);
  assert(error == TI_OKAY);
  double *rsi = malloc((unsigned int)size * sizeof(double));
  const double *rsi_inputs[] = {nz_rsi};
  double *rsi_outputs[] = {rsi};
  int range = rsi_length;
  double value = 0;
  const double rsi_options[] = {value, range};
  int error1 = ti_unshift(size, rsi_inputs, rsi_options, rsi_outputs);
  assert(error1 == TI_OKAY);
  double *ph_index = (double *)calloc((size_t)size, sizeof(double));
  double *ph_div_data = (double *)calloc((size_t)size, sizeof(double));
  double *ph_high = (double *)calloc((size_t)size, sizeof(double));
  double *ph_size = (double *)calloc((size_t)size, sizeof(double));
  double *pl_index = (double *)calloc((size_t)size, sizeof(double));
  double *pl_div_data = (double *)calloc((size_t)size, sizeof(double));
  double *pl_low = (double *)calloc((size_t)size, sizeof(double));
  double *pl_size = (double *)calloc((size_t)size, sizeof(double));
  const double *ph_inputs[] = {high, rsi};
  double *ph_outputs[] = {ph_index, ph_div_data, ph_high, ph_size};
  get_diver_pivot_high(ph_inputs, size, left_bar, right_bar, ph_outputs);
  const double *pl_inputs[] = {low, rsi};
  double *pl_outputs[] = {pl_index, pl_div_data, pl_low, pl_size};
  get_diver_pivot_low(pl_inputs, size, left_bar, right_bar, pl_outputs);
  int ph_count = (int)ph_size[0];
  int pl_count = (int)pl_size[0];
  double *filter_ph_index = (double *)calloc((size_t)ph_count, sizeof(double));
  double *filter_ph_div_data =
      (double *)calloc((size_t)ph_count, sizeof(double));
  double *filter_ph_high = (double *)calloc((size_t)ph_count, sizeof(double));
  double *filter_pl_index = (double *)calloc((size_t)pl_count, sizeof(double));
  double *filter_pl_div_data =
      (double *)calloc((size_t)pl_count, sizeof(double));
  double *filter_pl_low = (double *)calloc((size_t)pl_count, sizeof(double));
  const double *filter_ph_inputs[] = {ph_index, ph_div_data, ph_high};
  double *filter_ph_outputs[] = {filter_ph_index, filter_ph_div_data,
                                 filter_ph_high};
  filter_array(filter_ph_inputs, size, filter_ph_outputs);
  const double *filter_pl_inputs[] = {pl_index, pl_div_data, pl_low};
  double *filter_pl_outputs[] = {filter_pl_index, filter_pl_div_data,
                                 filter_pl_low};
  filter_array(filter_pl_inputs, size, filter_pl_outputs);
  for (int i = 1; i < pl_count; i++)
  {
    int prev_index = (int)filter_pl_index[i - 1];
    double prev_rsi = filter_pl_div_data[i - 1];
    double prev_low = filter_pl_low[i - 1];
    int index = (int)filter_pl_index[i];
    double _rsi = filter_pl_div_data[i];
    double _low = filter_pl_low[i];
    if (_rsi > prev_rsi && _low < prev_low && index - prev_index >= 6 &&
        index - prev_index <= 60)
    {
      bull[index] = TI_BULL;
    }
  }
  for (int i = 1; i < ph_count; i++)
  {
    int prev_index = (int)filter_ph_index[i - 1];
    double prev_rsi = filter_ph_div_data[i - 1];
    double prev_high = filter_ph_high[i - 1];
    int index = (int)filter_ph_index[i];
    double _rsi = filter_ph_div_data[i];
    double _high = filter_ph_high[i];
    if (_rsi < prev_rsi && _high > prev_high && index - prev_index >= 6 &&
        index - prev_index <= 60)
    {
      bear[index] = TI_BEAR;
    }
  }
  free(nz_rsi);
  free(rsi);
  free(ph_index);
  free(ph_div_data);
  free(ph_high);
  free(ph_size);
  free(pl_index);
  free(pl_div_data);
  free(pl_low);
  free(pl_size);
  free(filter_ph_index);
  free(filter_ph_div_data);
  free(filter_pl_index);
  free(filter_pl_div_data);
  return TI_OKAY;
}
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

int ti_rvi_start(TI_REAL const *options)
{
  (void)(options);
  return 0;
}
int ti_rvi(int size, TI_REAL const *const *inputs, TI_REAL const *options,
           TI_REAL *const *outputs)
{
  const TI_REAL *close = inputs[0];
  TI_REAL *rvi = outputs[0];
  const int std_length = (int)options[0];
  const int ema_length = (int)options[1];
  if (std_length < 1 || ema_length < 1)
    return TI_INVALID_OPTION;
  const double nz_std_options[] = {std_length};
  double *nz_std_data = (double *)calloc((size_t)size, sizeof(double));
  const double *nz_std_inputs[] = {close};
  double *nz_std_outputs[] = {nz_std_data};
  int error = ti_stddev(size, nz_std_inputs, nz_std_options, nz_std_outputs);
  assert(error == TI_OKAY);
  double *std = (double *)calloc((size_t)size, sizeof(double));
  const double *std_inputs[] = {nz_std_data};
  double *std_outputs[] = {std};
  int range = std_length - 1;
  double value = 0;
  const double std_options[] = {value, range};
  int error1 = ti_unshift(size, std_inputs, std_options, std_outputs);
  assert(error1 == TI_OKAY);
  double *diff = (double *)calloc((size_t)size, sizeof(double));
  double *upper_arr = (double *)calloc((size_t)size, sizeof(double));
  double *lower_arr = (double *)calloc((size_t)size, sizeof(double));
  for (int i = 1; i < size; i++)
    diff[i] = close[i] - close[i - 1];
  for (int i = 0; i < size; i++)
  {
    if (diff[i] <= 0)
      upper_arr[i] = 0;
    else
      upper_arr[i] = std[i];
    if (diff[i] > 0)
      lower_arr[i] = 0;
    else
      lower_arr[i] = std[i];
  }
  const double upper_options[] = {ema_length};
  double *upper = (double *)calloc((size_t)size, sizeof(double));
  const double *upper_inputs[] = {upper_arr};
  double *upper_outputs[] = {upper};
  int error2 = ti_ema(size, upper_inputs, upper_options, upper_outputs);
  assert(error2 == TI_OKAY);
  const double lower_options[] = {ema_length};
  double *lower = (double *)calloc((size_t)size, sizeof(double));
  const double *lower_inputs[] = {lower_arr};
  double *lower_outputs[] = {lower};
  int error3 = ti_ema(size, lower_inputs, lower_options, lower_outputs);
  assert(error3 == TI_OKAY);
  for (int i = 0; i < size; i++)
    rvi[i] = upper[i] / (upper[i] + lower[i]) * 100;
  free(nz_std_data);
  free(std);
  free(diff);
  free(upper_arr);
  free(lower_arr);
  free(upper);
  free(lower);
  return TI_OKAY;
}
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

int ti_rvi_divergence_start(TI_REAL const *options)
{
  (void)(options);
  return 0;
}
int ti_rvi_divergence(int size, TI_REAL const *const *inputs,
                      TI_REAL const *options, TI_REAL *const *outputs)
{
  const TI_REAL *high = inputs[0];
  const TI_REAL *low = inputs[1];
  const TI_REAL *close = inputs[2];
  double *bull = outputs[0];
  double *bear = outputs[1];
  const int left_bar = (int)options[0];
  const int right_bar = (int)options[1];
  const int stdev_length = (int)options[2];
  const int ema_length = (int)options[3];
  if (stdev_length < 1 || ema_length < 1 || left_bar < 0 || right_bar < 0)
    return TI_INVALID_OPTION;
  for (int i = 0; i < size; i++)
  {
    bull[i] = TI_NOTHING;
    bear[i] = TI_NOTHING;
  }
  const double rvi_options[] = {stdev_length, ema_length};
  double *rvi = malloc((unsigned int)size * sizeof(double));
  assert(rvi != 0);
  const double *rvi_inputs[] = {close};
  double *rvi_outputs[] = {rvi};
  int error = ti_rvi(size, rvi_inputs, rvi_options, rvi_outputs);
  assert(error == TI_OKAY);
  double *ph_index = (double *)calloc((size_t)size, sizeof(double));
  double *ph_div_data = (double *)calloc((size_t)size, sizeof(double));
  double *ph_high = (double *)calloc((size_t)size, sizeof(double));
  double *ph_size = (double *)calloc((size_t)size, sizeof(double));
  double *pl_index = (double *)calloc((size_t)size, sizeof(double));
  double *pl_div_data = (double *)calloc((size_t)size, sizeof(double));
  double *pl_low = (double *)calloc((size_t)size, sizeof(double));
  double *pl_size = (double *)calloc((size_t)size, sizeof(double));
  const double *ph_inputs[] = {high, rvi};
  double *ph_outputs[] = {ph_index, ph_div_data, ph_high, ph_size};
  get_diver_pivot_high(ph_inputs, size, left_bar, right_bar, ph_outputs);
  const double *pl_inputs[] = {low, rvi};
  double *pl_outputs[] = {pl_index, pl_div_data, pl_low, pl_size};
  get_diver_pivot_low(pl_inputs, size, left_bar, right_bar, pl_outputs);
  int ph_count = (int)ph_size[0];
  int pl_count = (int)pl_size[0];
  double *filter_ph_index = (double *)calloc((size_t)ph_count, sizeof(double));
  double *filter_ph_div_data =
      (double *)calloc((size_t)ph_count, sizeof(double));
  double *filter_ph_high = (double *)calloc((size_t)ph_count, sizeof(double));
  double *filter_pl_index = (double *)calloc((size_t)pl_count, sizeof(double));
  double *filter_pl_div_data =
      (double *)calloc((size_t)pl_count, sizeof(double));
  double *filter_pl_low = (double *)calloc((size_t)pl_count, sizeof(double));
  const double *filter_ph_inputs[] = {ph_index, ph_div_data, ph_high};
  double *filter_ph_outputs[] = {filter_ph_index, filter_ph_div_data,
                                 filter_ph_high};
  filter_array(filter_ph_inputs, size, filter_ph_outputs);
  const double *filter_pl_inputs[] = {pl_index, pl_div_data, pl_low};
  double *filter_pl_outputs[] = {filter_pl_index, filter_pl_div_data,
                                 filter_pl_low};
  filter_array(filter_pl_inputs, size, filter_pl_outputs);
  for (int i = 1; i < pl_count; i++)
  {
    int prev_index = (int)filter_pl_index[i - 1];
    double prev_rvi = filter_pl_div_data[i - 1];
    double prev_low = filter_pl_low[i - 1];
    int index = (int)filter_pl_index[i];
    double _rvi = filter_pl_div_data[i];
    double _low = filter_pl_low[i];
    if (_rvi > prev_rvi && _low < prev_low && index - prev_index >= 6 &&
        index - prev_index <= 60)
    {
      bull[index] = TI_BULL;
    }
  }
  for (int i = 1; i < ph_count; i++)
  {
    int prev_index = (int)filter_ph_index[i - 1];
    double prev_rvi = filter_ph_div_data[i - 1];
    double prev_high = filter_ph_high[i - 1];
    int index = (int)filter_ph_index[i];
    double _rvi = filter_ph_div_data[i];
    double _high = filter_ph_high[i];
    if (_rvi < prev_rvi && _high > prev_high && index - prev_index >= 6 &&
        index - prev_index <= 60)
    {
      bear[index] = TI_BEAR;
    }
  }
  free(rvi);
  free(ph_index);
  free(ph_div_data);
  free(ph_high);
  free(ph_size);
  free(pl_index);
  free(pl_div_data);
  free(pl_low);
  free(pl_size);
  free(filter_ph_index);
  free(filter_ph_div_data);
  free(filter_pl_index);
  free(filter_pl_div_data);
  return TI_OKAY;
}
int ti_sin_start(TI_REAL const *options) { (void)options; return 0; } int ti_sin(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (sin(in1[i])); } return TI_OKAY; }
int ti_sinh_start(TI_REAL const *options) { (void)options; return 0; } int ti_sinh(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (sinh(in1[i])); } return TI_OKAY; }
int ti_sma_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_sma(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    const TI_REAL scale = 1.0 / period;
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_sma_start(options)) return TI_OKAY;
    TI_REAL sum = 0;
    int i;
    for (i = 0; i < period; ++i) {
        sum += input[i];
    }
    *output++ = sum * scale;
    for (i = period; i < size; ++i) {
        sum += input[i];
        sum -= input[i-period];
        *output++ = sum * scale;
    }
    assert(output - outputs[0] == size - ti_sma_start(options));
    return TI_OKAY;
}
typedef struct ti_stream_sma {
    int index;
    int progress;
    int period;
    TI_REAL per;
    TI_REAL sum;
    int buffer_idx;
    TI_REAL buffer[];
} ti_stream_sma;
int ti_sma_stream_new(TI_REAL const *options, ti_stream **stream_in) {
    ti_stream_sma **stream = (ti_stream_sma**)stream_in;
    int period = (int)options[0];
    if (period < 1) return TI_INVALID_OPTION;
    *stream = malloc(sizeof(ti_stream_sma) + sizeof(TI_REAL[period]));
    if (!stream) {
        return TI_OUT_OF_MEMORY;
    }
    (*stream)->index = TI_INDICATOR_SMA_INDEX;
    (*stream)->progress = -ti_sma_start(options);
    (*stream)->period = period;
    (*stream)->per = 1. / period;
    (*stream)->sum = 0.;
    (*stream)->buffer_idx = -1;
    return TI_OKAY;
}
int ti_sma_stream_run(ti_stream *stream_in, int size, TI_REAL const *const *inputs, TI_REAL *const *outputs) {
    ti_stream_sma *stream = (ti_stream_sma*)stream_in;
    int progress = stream->progress;
    const TI_REAL *real = inputs[0];
    int period = stream->period;
    TI_REAL *sma = outputs[0];
    TI_REAL per = stream->per;
    TI_REAL sum = stream->sum;
    int buffer_idx = stream->buffer_idx;
    TI_REAL *buffer = stream->buffer;
    if (progress == -period + 1) {} else {}
    int i;
    for (i = 0; progress < 1 && i < size; ++i, ++progress) {
        { ++buffer_idx; sum += buffer[buffer_idx] = real[i] * per; };
    }
    if (i > 0 && progress == 1) {
        *sma++ = sum;
    }
    for (; i < size; ++i, ++progress) {
        { ++buffer_idx; if (buffer_idx == period) { buffer_idx = 0; } sum -= buffer[buffer_idx]; sum += buffer[buffer_idx] = real[i] * per; };
        *sma++ = sum;
    }
    stream->progress = progress;
    stream->sum = sum;
    stream->buffer_idx = buffer_idx;
    return TI_OKAY;
}
void ti_sma_stream_free(ti_stream *stream) {
    free(stream);
}
int ti_sqrt_start(TI_REAL const *options) { (void)options; return 0; } int ti_sqrt(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (sqrt(in1[i])); } return TI_OKAY; }
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

int ti_ssl_start(TI_REAL const *options)
{
  (void)(options);
  return 0;
}
int ti_ssl(int size, TI_REAL const *const *inputs, TI_REAL const *options,
           TI_REAL *const *outputs)
{
  const TI_REAL *high = inputs[0];
  const TI_REAL *low = inputs[1];
  const TI_REAL *close = inputs[2];
  TI_REAL *BBMC = outputs[0];
  TI_REAL *color_bar = outputs[1];
  TI_REAL *upperk = outputs[2];
  TI_REAL *lowerk = outputs[3];
  TI_REAL *base_cross_Long = outputs[4];
  TI_REAL *base_cross_Short = outputs[5];
  const int ma_length = (int)options[0];
  const int ssl3_length = (int)options[1];
  if (ma_length < 1 || ssl3_length < 1)
    return TI_INVALID_OPTION;
  const double nz_hma_options[] = {ma_length};
  double *nz_hma = malloc((unsigned int)size * sizeof(double));
  assert(nz_hma != 0);
  const double *nz_hma_inputs[] = {close};
  double *nz_hma_outputs[] = {nz_hma};
  int error = ti_hma(size, nz_hma_inputs, nz_hma_options, nz_hma_outputs);
  assert(error == TI_OKAY);
  const double *hma_inputs[] = {nz_hma};
  double *hma_outputs[] = {BBMC};
  int range = ma_length - 2 + (int)floor(sqrt(ma_length));
  double value = 0;
  const double hma_options[] = {value, range};
  int error1 = ti_unshift(size, hma_inputs, hma_options, hma_outputs);
  assert(error1 == TI_OKAY);
  double *true_range = (double *)calloc((size_t)size, sizeof(double));
  for (int i = 1; i < size; i++)
  {
    true_range[i] =
        fmax(fmax(high[i] - low[i], fabs(high[i] - not_zero(close[i - 1], 0))),
             fabs(low[i] - not_zero(close[i - 1], 0)));
  }
  double *rangema = (double *)calloc((size_t)size, sizeof(double));
  const double ema_options[] = {ma_length};
  const double *ema_inputs[] = {true_range};
  double *ema_outputs[] = {rangema};
  int error2 = ti_ema(size, ema_inputs, ema_options, ema_outputs);
  assert(error2 == TI_OKAY);
  for (int i = 0; i < size; i++)
  {
    upperk[i] = BBMC[i] + (rangema[i] * 0.2);
    lowerk[i] = BBMC[i] - (rangema[i] * 0.2);
    double colour_bar;
    if (close[i] > upperk[i])
    {
      colour_bar = 1;
    }
    else if (close[i] < lowerk[i])
    {
      colour_bar = -1;
    }
    else
    {
      colour_bar = 0;
    }
    color_bar[i] = colour_bar;
  }
  double *Hlv3 = (double *)calloc((size_t)size, sizeof(double));
  double *sslExit = (double *)calloc((size_t)size, sizeof(double));
  const double nz_ExitHigh_options[] = {ssl3_length};
  double *nz_ExitHigh = malloc((unsigned int)size * sizeof(double));
  assert(nz_ExitHigh != 0);
  const double *nz_ExitHigh_inputs[] = {high};
  double *nz_ExitHigh_outputs[] = {nz_ExitHigh};
  int error3 = ti_hma(size, nz_ExitHigh_inputs, nz_ExitHigh_options,
                      nz_ExitHigh_outputs);
  assert(error3 == TI_OKAY);
  double *ExitHigh = (double *)calloc((size_t)size, sizeof(double));
  const double *ExitHigh_inputs[] = {nz_ExitHigh};
  double *ExitHigh_outputs[] = {ExitHigh};
  int range1 = ssl3_length - 2 + (int)floor(sqrt(ssl3_length));
  double value1 = 0;
  const double exithigh_options[] = {value1, range1};
  int error4 =
      ti_unshift(size, ExitHigh_inputs, exithigh_options, ExitHigh_outputs);
  assert(error4 == TI_OKAY);
  const double nz_ExitLow_options[] = {ssl3_length};
  double *nz_ExitLow = malloc((unsigned int)size * sizeof(double));
  assert(nz_ExitLow != 0);
  const double *nz_ExitLow_inputs[] = {low};
  double *nz_ExitLow_outputs[] = {nz_ExitLow};
  int error5 =
      ti_hma(size, nz_ExitLow_inputs, nz_ExitLow_options, nz_ExitLow_outputs);
  assert(error5 == TI_OKAY);
  double *ExitLow = (double *)calloc((size_t)size, sizeof(double));
  const double *ExitLow_inputs[] = {nz_ExitLow};
  double *ExitLow_outputs[] = {ExitLow};
  int range2 = ssl3_length - 2 + (int)floor(sqrt(ssl3_length));
  double value2 = 0;
  const double exitlow_options[] = {value2, range2};
  int error6 =
      ti_unshift(size, ExitLow_inputs, exitlow_options, ExitLow_outputs);
  assert(error6 == TI_OKAY);
  for (int i = 1; i < size; i++)
    if (close[i] > ExitHigh[i])
      Hlv3[i] = 1;
    else if (close[i] < ExitLow[i])
      Hlv3[i] = -1;
    else
      Hlv3[i] = Hlv3[i - 1];
  for (int i = 0; i < size; i++)
    if (Hlv3[i] < 0)
      sslExit[i] = ExitHigh[i];
    else
      sslExit[i] = ExitLow[i];
  double *nz_base_cross_Long = (double *)calloc((size_t)size, sizeof(double));
  const double nz_base_cross_Long_options[] = {0};
  const double *nz_base_cross_Long_inputs[] = {close, sslExit};
  double *nz_base_cross_Long_outputs[] = {nz_base_cross_Long};
  int error7 =
      ti_crossover(size, nz_base_cross_Long_inputs, nz_base_cross_Long_options,
                   nz_base_cross_Long_outputs);
  assert(error7 == TI_OKAY);
  const double *base_cross_Long_inputs[] = {nz_base_cross_Long};
  double *base_cross_Long_outputs[] = {base_cross_Long};
  int range105 = 1;
  double value105 = 0;
  const double base_cross_Long_options[] = {value105, range105};
  int error105 = ti_unshift(size, base_cross_Long_inputs,
                            base_cross_Long_options, base_cross_Long_outputs);
  assert(error105 == TI_OKAY);
  double *nz_base_cross_Short = (double *)calloc((size_t)size, sizeof(double));
  const double nz_base_cross_Short_options[] = {0};
  const double *nz_base_cross_Short_inputs[] = {sslExit, close};
  double *nz_base_cross_Short_outputs[] = {nz_base_cross_Short};
  int error8 =
      ti_crossover(size, nz_base_cross_Short_inputs,
                   nz_base_cross_Short_options, nz_base_cross_Short_outputs);
  assert(error8 == TI_OKAY);
  const double *base_cross_Short_inputs[] = {nz_base_cross_Short};
  double *base_cross_Short_outputs[] = {base_cross_Short};
  int range200 = 1;
  double value200 = 0;
  const double base_cross_Short_options[] = {value200, range200};
  int error200 = ti_unshift(size, base_cross_Short_inputs,
                            base_cross_Short_options, base_cross_Short_outputs);
  assert(error200 == TI_OKAY);
  free(nz_hma);
  free(true_range);
  free(rangema);
  free(Hlv3);
  free(sslExit);
  free(nz_ExitHigh);
  free(ExitHigh);
  free(nz_ExitLow);
  free(ExitLow);
  free(nz_base_cross_Long);
  free(nz_base_cross_Short);
  return TI_OKAY;
}
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

int ti_stc_start(TI_REAL const *options)
{
  (void)(options);
  return 0;
}
int ti_stc(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs)
{
  const TI_REAL *close = inputs[0];
  TI_REAL *stc = outputs[0];
  TI_REAL *stc_color = outputs[1];
  const int length = (int)options[0];
  const int fast_length = (int)options[1];
  const int slow_length = (int)options[2];
  const double aaa = (double)options[3];
  if (length < 1 || fast_length < 1 || slow_length < 1 || aaa < 0)
    return TI_INVALID_OPTION;
  double *ema_diff = (double *)calloc((size_t)size, sizeof(double));
  double *fastema = (double *)calloc((size_t)size, sizeof(double));
  const double fastema_options[] = {fast_length};
  const double *fastema_inputs[] = {close};
  double *fastema_outputs[] = {fastema};
  int error = ti_ema(size, fastema_inputs, fastema_options, fastema_outputs);
  assert(error == TI_OKAY);
  double *slowema = (double *)calloc((size_t)size, sizeof(double));
  const double slowema_options[] = {slow_length};
  const double *slowema_inputs[] = {close};
  double *slowema_outputs[] = {slowema};
  int error3 = ti_ema(size, slowema_inputs, slowema_options, slowema_outputs);
  assert(error3 == TI_OKAY);
  for (int i = 0; i < size; i++)
  {
    ema_diff[i] = fastema[i] - slowema[i];
  }
  const double nz_CCC_options[] = {length};
  double *nz_CCC = malloc((unsigned int)size * sizeof(double));
  assert(nz_CCC != 0);
  const double *nz_CCC_inputs[] = {ema_diff};
  double *nz_CCC_outputs[] = {nz_CCC};
  int error4 = ti_min(size, nz_CCC_inputs, nz_CCC_options, nz_CCC_outputs);
  assert(error4 == TI_OKAY);
  double *CCC = (double *)calloc((size_t)size, sizeof(double));
  const double *CCC_inputs[] = {nz_CCC};
  double *CCC_outputs[] = {CCC};
  int range1 = length - 1;
  double value1 = 0;
  const double ccc_options[] = {value1, range1};
  int error5 = ti_unshift(size, CCC_inputs, ccc_options, CCC_outputs);
  assert(error5 == TI_OKAY);
  const double nz_CCCC_options[] = {length};
  double *nz_CCCC = malloc((unsigned int)size * sizeof(double));
  assert(nz_CCCC != 0);
  const double *nz_CCCC_inputs[] = {ema_diff};
  double *nz_CCCC_outputs[] = {nz_CCCC};
  int error6 = ti_max(size, nz_CCCC_inputs, nz_CCCC_options, nz_CCCC_outputs);
  assert(error6 == TI_OKAY);
  double *CCCC = (double *)calloc((size_t)size, sizeof(double));
  const double *CCCC_inputs[] = {nz_CCCC};
  double *CCCC_outputs[] = {CCCC};
  int range3 = length - 1;
  double value3 = 0;
  const double cccc_options[] = {value3, range3};
  int error7 = ti_unshift(size, CCCC_inputs, cccc_options, CCCC_outputs);
  assert(error7 == TI_OKAY);
  double *CCCCC = (double *)calloc((size_t)size, sizeof(double));
  double *DDD = (double *)calloc((size_t)size, sizeof(double));
  for (int i = 0; i < size; i++)
    CCCC[i] = CCCC[i] - CCC[i];
  for (int i = 1; i < size; i++)
    if (CCCC[i] > 0)
      CCCCC[i] = (float)(ema_diff[i] - CCC[i]) / CCCC[i] * 100;
    else
      CCCCC[i] = not_zero(CCCCC[i - 1], 0);
  DDD[0] = CCCCC[0];
  for (int i = 1; i < size; i++)
  {
    DDD[i] = DDD[i - 1] + aaa * (CCCCC[i] - DDD[i - 1]);
  }
  const double nz_DDDD_options[] = {length};
  double *nz_DDDD = malloc((unsigned int)size * sizeof(double));
  assert(nz_DDDD != 0);
  const double *nz_DDDD_inputs[] = {DDD};
  double *nz_DDDD_outputs[] = {nz_DDDD};
  int error8 = ti_min(size, nz_DDDD_inputs, nz_DDDD_options, nz_DDDD_outputs);
  assert(error8 == TI_OKAY);
  double *DDDD = (double *)calloc((size_t)size, sizeof(double));
  const double *DDDD_inputs[] = {nz_DDDD};
  double *DDDD_outputs[] = {DDDD};
  int range2 = length - 1;
  double value2 = 0;
  const double dddd_options[] = {value2, range2};
  int error9 = ti_unshift(size, DDDD_inputs, dddd_options, DDDD_outputs);
  assert(error9 == TI_OKAY);
  const double nz_DDDDD_options[] = {length};
  double *nz_DDDDD = malloc((unsigned int)size * sizeof(double));
  assert(nz_DDDDD != 0);
  const double *nz_DDDDD_inputs[] = {DDD};
  double *nz_DDDDD_outputs[] = {nz_DDDDD};
  int error10 =
      ti_max(size, nz_DDDDD_inputs, nz_DDDDD_options, nz_DDDDD_outputs);
  assert(error10 == TI_OKAY);
  double *DDDDD = (double *)calloc((size_t)size, sizeof(double));
  const double *DDDDD_inputs[] = {nz_DDDDD};
  double *DDDDD_outputs[] = {DDDDD};
  int range5 = length - 1;
  double value5 = 0;
  const double ddddd_options[] = {value5, range5};
  int error11 = ti_unshift(size, DDDDD_inputs, ddddd_options, DDDDD_outputs);
  assert(error11 == TI_OKAY);
  for (int i = 0; i < size; i++)
    DDDDD[i] = DDDDD[i] - DDDD[i];
  double *DDDDDD = (double *)calloc((size_t)size, sizeof(double));
  for (int i = 1; i < size; i++)
  {
    if (DDDDD[i] > 0)
    {
      DDDDDD[i] = (float)(DDD[i] - DDDD[i]) / DDDDD[i] * 100;
    }
    else
    {
      DDDDDD[i] = not_zero(DDDDDD[i - 1], 0);
    }
  }
  stc[0] = DDDDDD[0];
  for (int i = 1; i < size; i++)
  {
    stc[i] = stc[i - 1] + aaa * (DDDDDD[i] - stc[i - 1]);
  }
  stc_color[0] = TI_NOTHING;
  for (int i = 1; i < size; i++)
    if (stc[i] > stc[i - 1])
      stc_color[i] = TI_GREEN;
    else
      stc_color[i] = TI_RED;
  free(ema_diff);
  free(fastema);
  free(slowema);
  free(nz_CCC);
  free(CCC);
  free(nz_CCCC);
  free(CCCC);
  free(CCCCC);
  free(DDD);
  free(nz_DDDD);
  free(DDDD);
  free(nz_DDDDD);
  free(DDDDD);
  free(DDDDDD);
  return TI_OKAY;
}
int ti_stddev_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_stddev(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    const TI_REAL scale = 1.0 / period;
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_stddev_start(options)) return TI_OKAY;
    TI_REAL sum = 0;
    TI_REAL sum2 = 0;
    int i;
    for (i = 0; i < period; ++i) {
        sum += input[i];
        sum2 += input[i] * input[i];
    }
    {
        TI_REAL s2s2 = (sum2 * scale - (sum * scale) * (sum * scale));
        if (s2s2 > 0.0) s2s2 = sqrt(s2s2);
        *output++ = s2s2;
    }
    for (i = period; i < size; ++i) {
        sum += input[i];
        sum2 += input[i] * input[i];
        sum -= input[i-period];
        sum2 -= input[i-period] * input[i-period];
        TI_REAL s2s2 = (sum2 * scale - (sum * scale) * (sum * scale));
        if (s2s2 > 0.0) s2s2 = sqrt(s2s2);
        *output++ = s2s2;
    }
    assert(output - outputs[0] == size - ti_stddev_start(options));
    return TI_OKAY;
}
int ti_stderr_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_stderr(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    const TI_REAL scale = 1.0 / period;
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_stderr_start(options)) return TI_OKAY;
    TI_REAL sum = 0;
    TI_REAL sum2 = 0;
    const TI_REAL mul = 1.0 / sqrt(period);
    int i;
    for (i = 0; i < period; ++i) {
        sum += input[i];
        sum2 += input[i] * input[i];
    }
    {
        TI_REAL s2s2 = (sum2 * scale - (sum * scale) * (sum * scale));
        if (s2s2 > 0.0) s2s2 = sqrt(s2s2);
        *output++ = mul * s2s2;
    }
    for (i = period; i < size; ++i) {
        sum += input[i];
        sum2 += input[i] * input[i];
        sum -= input[i-period];
        sum2 -= input[i-period] * input[i-period];
        TI_REAL s2s2 = (sum2 * scale - (sum * scale) * (sum * scale));
        if (s2s2 > 0.0) s2s2 = sqrt(s2s2);
        *output++ = mul * s2s2;
    }
    assert(output - outputs[0] == size - ti_stderr_start(options));
    return TI_OKAY;
}
int ti_stoch_start(TI_REAL const *options) {
    const int kperiod = (int)options[0];
    const int kslow = (int)options[1];
    const int dperiod = (int)options[2];
    return kperiod + kslow + dperiod - 3;
}
int ti_stoch(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    const int kperiod = (int)options[0];
    const int kslow = (int)options[1];
    const int dperiod = (int)options[2];
    const TI_REAL kper = 1.0 / kslow;
    const TI_REAL dper = 1.0 / dperiod;
    TI_REAL *stoch = outputs[0];
    TI_REAL *stoch_ma = outputs[1];
    if (kperiod < 1) return TI_INVALID_OPTION;
    if (kslow < 1) return TI_INVALID_OPTION;
    if (dperiod < 1) return TI_INVALID_OPTION;
    if (size <= ti_stoch_start(options)) return TI_OKAY;
    int trail = 0, maxi = -1, mini = -1;
    TI_REAL max = high[0];
    TI_REAL min = low[0];
    TI_REAL bar;
    ti_buffer *k_sum = ti_buffer_new(kslow);
    ti_buffer *d_sum = ti_buffer_new(dperiod);
    int i, j;
    for (i = 0; i < size; ++i) {
        if (i >= kperiod) ++trail;
        bar = high[i];
        if (maxi < trail) {
            maxi = trail;
            max = high[maxi];
            j = trail;
            while(++j <= i) {
                bar = high[j];
                if (bar >= max) {
                    max = bar;
                    maxi = j;
                }
            }
        } else if (bar >= max) {
            maxi = i;
            max = bar;
        }
        bar = low[i];
        if (mini < trail) {
            mini = trail;
            min = low[mini];
            j = trail;
            while(++j <= i) {
                bar = low[j];
                if (bar <= min) {
                    min = bar;
                    mini = j;
                }
            }
        } else if (bar <= min) {
            mini = i;
            min = bar;
        }
        const TI_REAL kdiff = (max - min);
        const TI_REAL kfast = kdiff == 0.0 ? 0.0 : 100 * ((close[i] - min) / kdiff);
        ti_buffer_push(k_sum, kfast);
        if (i >= kperiod-1 + kslow-1) {
            const TI_REAL k = k_sum->sum * kper;
            ti_buffer_push(d_sum, k);
            if (i >= kperiod-1 + kslow-1 + dperiod-1) {
                *stoch++ = k;
                *stoch_ma++ = d_sum->sum * dper;
            }
        }
    }
    ti_buffer_free(k_sum);
    ti_buffer_free(d_sum);
    assert(stoch - outputs[0] == size - ti_stoch_start(options));
    assert(stoch_ma - outputs[1] == size - ti_stoch_start(options));
    return TI_OKAY;
}
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

int ti_stoch_divergence_start(TI_REAL const *options)
{
  (void)(options);
  return 0;
}
int ti_stoch_divergence(int size, TI_REAL const *const *inputs,
                        TI_REAL const *options, TI_REAL *const *outputs)
{
  const TI_REAL *high = inputs[0];
  const TI_REAL *low = inputs[1];
  const TI_REAL *close = inputs[2];
  double *bull = outputs[0];
  double *bear = outputs[1];
  const int left_bar = (int)options[0];
  const int right_bar = (int)options[1];
  const int stk_length = (int)options[2];
  const int smooth_length = (int)options[3];
  const int sma_length = (int)options[4];
  if (stk_length < 1 || smooth_length < 1 || sma_length < 1 || left_bar < 0 ||
      right_bar < 0)
    return TI_INVALID_OPTION;
  for (int i = 0; i < size; i++)
  {
    bull[i] = TI_NOTHING;
    bear[i] = TI_NOTHING;
  }
  const double nz_stoch_options[] = {stk_length, smooth_length, sma_length};
  double *nz_stoch1 = malloc((unsigned int)size * sizeof(double));
  double *nz_stoch2 = malloc((unsigned int)size * sizeof(double));
  assert(nz_stoch1 != 0);
  const double *nz_stoch_inputs[] = {high, low, close};
  double *nz_stoch_outputs[] = {nz_stoch1, nz_stoch2};
  int error =
      ti_stoch(size, nz_stoch_inputs, nz_stoch_options, nz_stoch_outputs);
  assert(error == TI_OKAY);
  double *stk1 = malloc((unsigned int)size * sizeof(double));
  const double *stk1_inputs[] = {nz_stoch1};
  double *stk1_outputs[] = {stk1};
  int range = stk_length + sma_length;
  double value = 0;
  const double stk1_options[] = {value, range};
  int error1 = ti_unshift(size, stk1_inputs, stk1_options, stk1_outputs);
  assert(error1 == TI_OKAY);
  double *ph_index = (double *)calloc((size_t)size, sizeof(double));
  double *ph_div_data = (double *)calloc((size_t)size, sizeof(double));
  double *ph_high = (double *)calloc((size_t)size, sizeof(double));
  double *ph_size = (double *)calloc((size_t)size, sizeof(double));
  double *pl_index = (double *)calloc((size_t)size, sizeof(double));
  double *pl_div_data = (double *)calloc((size_t)size, sizeof(double));
  double *pl_low = (double *)calloc((size_t)size, sizeof(double));
  double *pl_size = (double *)calloc((size_t)size, sizeof(double));
  const double *ph_inputs[] = {high, stk1};
  double *ph_outputs[] = {ph_index, ph_div_data, ph_high, ph_size};
  get_diver_pivot_high(ph_inputs, size, left_bar, right_bar, ph_outputs);
  const double *pl_inputs[] = {low, stk1};
  double *pl_outputs[] = {pl_index, pl_div_data, pl_low, pl_size};
  get_diver_pivot_low(pl_inputs, size, left_bar, right_bar, pl_outputs);
  int ph_count = (int)ph_size[0];
  int pl_count = (int)pl_size[0];
  double *filter_ph_index = (double *)calloc((size_t)ph_count, sizeof(double));
  double *filter_ph_div_data =
      (double *)calloc((size_t)ph_count, sizeof(double));
  double *filter_ph_high = (double *)calloc((size_t)ph_count, sizeof(double));
  double *filter_pl_index = (double *)calloc((size_t)pl_count, sizeof(double));
  double *filter_pl_div_data =
      (double *)calloc((size_t)pl_count, sizeof(double));
  double *filter_pl_low = (double *)calloc((size_t)pl_count, sizeof(double));
  const double *filter_ph_inputs[] = {ph_index, ph_div_data, ph_high};
  double *filter_ph_outputs[] = {filter_ph_index, filter_ph_div_data,
                                 filter_ph_high};
  filter_array(filter_ph_inputs, size, filter_ph_outputs);
  const double *filter_pl_inputs[] = {pl_index, pl_div_data, pl_low};
  double *filter_pl_outputs[] = {filter_pl_index, filter_pl_div_data,
                                 filter_pl_low};
  filter_array(filter_pl_inputs, size, filter_pl_outputs);
  for (int i = 1; i < pl_count; i++)
  {
    int prev_index = (int)filter_pl_index[i - 1];
    double prev_stk1 = filter_pl_div_data[i - 1];
    double prev_low = filter_pl_low[i - 1];
    int index = (int)filter_pl_index[i];
    double _stk1 = filter_pl_div_data[i];
    double _low = filter_pl_low[i];
    if (_stk1 > prev_stk1 && _low < prev_low && index - prev_index >= 6 &&
        index - prev_index <= 60)
    {
      bull[index] = TI_BULL;
    }
  }
  for (int i = 1; i < ph_count; i++)
  {
    int prev_index = (int)filter_ph_index[i - 1];
    double prev_stk1 = filter_ph_div_data[i - 1];
    double prev_high = filter_ph_high[i - 1];
    int index = (int)filter_ph_index[i];
    double _stk1 = filter_ph_div_data[i];
    double _high = filter_ph_high[i];
    if (_stk1 < prev_stk1 && _high > prev_high && index - prev_index >= 6 &&
        index - prev_index <= 60)
    {
      bear[index] = TI_BEAR;
    }
  }
  free(nz_stoch1);
  free(nz_stoch2);
  free(stk1);
  free(ph_index);
  free(ph_div_data);
  free(ph_high);
  free(ph_size);
  free(pl_index);
  free(pl_div_data);
  free(pl_low);
  free(pl_size);
  free(filter_ph_index);
  free(filter_ph_div_data);
  free(filter_pl_index);
  free(filter_pl_div_data);
  return TI_OKAY;
}
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

int ti_stoch_rsi_start(TI_REAL const *options)
{
    (void)(options);
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

int ti_stochrsi_start(TI_REAL const *options) {
    return ((int)options[0]) * 2 - 1;
}
int ti_stochrsi(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    const TI_REAL per = 1.0 / ((TI_REAL)period);
    if (period < 2) return TI_INVALID_OPTION;
    if (size <= ti_stochrsi_start(options)) return TI_OKAY;
    ti_buffer *rsi = ti_buffer_new(period);
    TI_REAL smooth_up = 0, smooth_down = 0;
    int i;
    for (i = 1; i <= period; ++i) {
        const TI_REAL upward = input[i] > input[i-1] ? input[i] - input[i-1] : 0;
        const TI_REAL downward = input[i] < input[i-1] ? input[i-1] - input[i] : 0;
        smooth_up += upward;
        smooth_down += downward;
    }
    smooth_up /= period;
    smooth_down /= period;
    TI_REAL r = 100.0 * (smooth_up / (smooth_up + smooth_down));
    ti_buffer_push(rsi, r);
    TI_REAL min = r;
    TI_REAL max = r;
    int mini = 0;
    int maxi = 0;
    for (i = period+1; i < size; ++i) {
        const TI_REAL upward = input[i] > input[i-1] ? input[i] - input[i-1] : 0;
        const TI_REAL downward = input[i] < input[i-1] ? input[i-1] - input[i] : 0;
        smooth_up = (upward-smooth_up) * per + smooth_up;
        smooth_down = (downward-smooth_down) * per + smooth_down;
        r = 100.0 * (smooth_up / (smooth_up + smooth_down));
        if (r > max) {
            max = r;
            maxi = rsi->index;
        } else if (maxi == rsi->index) {
            max = r;
            int j;
            for (j = 0; j < rsi->size; ++j) {
                if (j == rsi->index) continue;
                if (rsi->vals[j] > max) {
                    max = rsi->vals[j];
                    maxi = j;
                }
            }
        }
        if (r < min) {
            min = r;
            mini = rsi->index;
        } else if (mini == rsi->index) {
            min = r;
            int j;
            for (j = 0; j < rsi->size; ++j) {
                if (j == rsi->index) continue;
                if (rsi->vals[j] < min) {
                    min = rsi->vals[j];
                    mini = j;
                }
            }
        }
        ti_buffer_qpush(rsi, r);
        if (i > period*2 - 2) {
            const TI_REAL diff = max - min;
            if (diff == 0.0) {
                *output++ = 0.0;
            } else {
                *output++ = (r - min) / (diff);
            }
        }
    }
    ti_buffer_free(rsi);
    assert(output - outputs[0] == size - ti_stochrsi_start(options));
    return TI_OKAY;
}
int ti_sub_start(TI_REAL const *options) { (void)options; return 0; } int ti_sub(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; const TI_REAL *in2 = inputs[1]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (in1[i] - in2[i]); } return TI_OKAY; }
int ti_sum_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_sum(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_sum_start(options)) return TI_OKAY;
    TI_REAL sum = 0;
    int i;
    for (i = 0; i < period; ++i) {
        sum += input[i];
    }
    *output++ = sum;
    for (i = period; i < size; ++i) {
        sum += input[i];
        sum -= input[i-period];
        *output++ = sum;
    }
    assert(output - outputs[0] == size - ti_sum_start(options));
    return TI_OKAY;
}
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

int ti_sup_and_res_start(TI_REAL const *options)
{
  (void)(options);
  return 0;
}
double get_pivothigh_close(TI_REAL const *const *inputs, int size, int left_bar,
                           int right_bar, int index)
{
  const TI_REAL *close = inputs[0];
  double middle_point = close[index - right_bar];
  int start_index = index - (left_bar + right_bar);
  int end_index = index;
  int temp_size = end_index - start_index + 1;
  double *temp_arr = (double *)calloc((size_t)temp_size, sizeof(double));
  const double *slice_array_inputs[] = {close};
  double *slice_array_outputs[] = {temp_arr};
  slice_array(slice_array_inputs, start_index, end_index, size,
              slice_array_outputs);
  double max_temp_arr = max_value(temp_arr, temp_size);
  free(temp_arr);
  if (max_temp_arr == middle_point)
    return middle_point;
  else
    return (double)0;
}
double get_pivotlow_close(TI_REAL const *const *inputs, int size, int left_bar,
                          int right_bar, int index)
{
  const TI_REAL *close = inputs[0];
  double middle_point = close[index - right_bar];
  int start_index = index - (left_bar + right_bar);
  int end_index = index;
  int temp_size = end_index - start_index + 1;
  double *temp_arr = (double *)calloc((size_t)temp_size, sizeof(double));
  const double *slice_array_inputs[] = {close};
  double *slice_array_outputs[] = {temp_arr};
  slice_array(slice_array_inputs, start_index, end_index, size,
              slice_array_outputs);
  double max_temp_arr = min_value(temp_arr, temp_size);
  free(temp_arr);
  if (max_temp_arr == middle_point)
    return middle_point;
  else
    return (double)0;
}
int ti_sup_and_res(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs)
{
  const TI_REAL *close = inputs[0];
  TI_REAL *buy1 = outputs[0];
  TI_REAL *buy2 = outputs[1];
  TI_REAL *buy3 = outputs[2];
  TI_REAL *buy4 = outputs[3];
  TI_REAL *buy5 = outputs[4];
  TI_REAL *buy6 = outputs[5];
  TI_REAL *buy7 = outputs[6];
  TI_REAL *buy8 = outputs[7];
  TI_REAL *sell1 = outputs[8];
  TI_REAL *sell2 = outputs[9];
  TI_REAL *sell3 = outputs[10];
  TI_REAL *sell4 = outputs[11];
  TI_REAL *sell5 = outputs[12];
  TI_REAL *sell6 = outputs[13];
  TI_REAL *sell7 = outputs[14];
  TI_REAL *sell8 = outputs[15];
  const int left_bar = (int)options[0];
  const int right_bar1 = (int)options[1];
  const int right_bar2 = (int)options[2];
  const int hma_length = (int)options[3];
  if (hma_length < 1)
    return TI_INVALID_OPTION;
  const double nz_hma_options[] = {hma_length};
  double *nz_hma = malloc((unsigned int)size * sizeof(double));
  assert(nz_hma != 0);
  const double *nz_hma_inputs[] = {close};
  double *nz_hma_outputs[] = {nz_hma};
  int error = ti_hma(size, nz_hma_inputs, nz_hma_options, nz_hma_outputs);
  assert(error == TI_OKAY);
  double *hma = (double *)calloc((size_t)size, sizeof(double));
  const double *hma_inputs[] = {nz_hma};
  double *hma_outputs[] = {hma};
  int range = hma_length - 2 + (int)floor(sqrt(hma_length));
  double value = 0;
  const double hma_options[] = {value, range};
  int error1 = ti_unshift(size, hma_inputs, hma_options, hma_outputs);
  assert(error1 == TI_OKAY);
  double *level1 = (double *)calloc((size_t)size, sizeof(double));
  double *level2 = (double *)calloc((size_t)size, sizeof(double));
  double *level3 = (double *)calloc((size_t)size, sizeof(double));
  double *level4 = (double *)calloc((size_t)size, sizeof(double));
  double *level5 = (double *)calloc((size_t)size, sizeof(double));
  double *level6 = (double *)calloc((size_t)size, sizeof(double));
  double *level7 = (double *)calloc((size_t)size, sizeof(double));
  double *level8 = (double *)calloc((size_t)size, sizeof(double));
  for (int i = left_bar + right_bar1; i < size; i++)
  {
    const double *pivot_inputs[] = {close};
    double pivothigh =
        get_pivothigh_close(pivot_inputs, size, left_bar, right_bar1, i);
    double pivotlow =
        get_pivotlow_close(pivot_inputs, size, left_bar, right_bar1, i);
    if (pivothigh != 0)
    {
      level3[i] = pivothigh;
      level5[i] = pivothigh;
      level7[i] = pivothigh;
    }
    else
    {
      level3[i] = level3[i - 1];
      level5[i] = level5[i - 2];
      level7[i] = level7[i - 3];
    }
    if (pivotlow != 0)
    {
      level4[i] = pivotlow;
      level6[i] = pivotlow;
      level8[i] = pivotlow;
    }
    else
    {
      level4[i] = level4[i - 1];
      level6[i] = level6[i - 2];
      level8[i] = level8[i - 3];
    }
  }
  for (int i = left_bar + right_bar2; i < size; i++)
  {
    const double *pivot_inputs[] = {close};
    double pivothigh_quick =
        get_pivothigh_close(pivot_inputs, size, left_bar, right_bar2, i);
    double pivotlow_quick =
        get_pivotlow_close(pivot_inputs, size, left_bar, right_bar2, i);
    if (pivothigh_quick != 0)
    {
      level1[i] = pivothigh_quick;
    }
    else
    {
      level1[i] = level1[i - 1];
    }
    if (pivotlow_quick != 0)
    {
      level2[i] = pivotlow_quick;
    }
    else
    {
      level2[i] = level2[i - 1];
    }
  }
  for (int z = 2; z < size; z++)
  {
    buy1[z] = hma[z] > level1[z] && hma[z - 1] < level1[z - 1] &&
                      close[z] > close[z - 2]
                  ? 1
                  : -1;
    buy2[z] = hma[z] > level2[z] && hma[z - 1] < level2[z - 1] &&
                      close[z] > close[z - 2]
                  ? 1
                  : -1;
    buy3[z] = hma[z] > level3[z] && hma[z - 1] < level3[z - 1] &&
                      close[z] > close[z - 2]
                  ? 1
                  : -1;
    buy4[z] = hma[z] > level4[z] && hma[z - 1] < level4[z - 1] &&
                      close[z] > close[z - 2]
                  ? 1
                  : -1;
    buy5[z] = hma[z] > level5[z] && hma[z - 1] < level5[z - 1] &&
                      close[z] > close[z - 2]
                  ? 1
                  : -1;
    buy6[z] = hma[z] > level6[z] && hma[z - 1] < level6[z - 1] &&
                      close[z] > close[z - 2]
                  ? 1
                  : -1;
    buy7[z] = hma[z] > level7[z] && hma[z - 1] < level7[z - 1] &&
                      close[z] > close[z - 2]
                  ? 1
                  : -1;
    buy8[z] = hma[z] > level8[z] && hma[z - 1] < level8[z - 1] &&
                      close[z] > close[z - 2]
                  ? 1
                  : -1;
    sell1[z] = hma[z] < level1[z] && hma[z - 1] > level1[z - 1] &&
                       close[z] < close[z - 2]
                   ? 1
                   : -1;
    sell2[z] = hma[z] < level2[z] && hma[z - 1] > level2[z - 1] &&
                       close[z] < close[z - 2]
                   ? 1
                   : -1;
    sell3[z] = hma[z] < level3[z] && hma[z - 1] > level3[z - 1] &&
                       close[z] < close[z - 2]
                   ? 1
                   : -1;
    sell4[z] = hma[z] < level4[z] && hma[z - 1] > level4[z - 1] &&
                       close[z] < close[z - 2]
                   ? 1
                   : -1;
    sell5[z] = hma[z] < level5[z] && hma[z - 1] > level5[z - 1] &&
                       close[z] < close[z - 2]
                   ? 1
                   : -1;
    sell6[z] = hma[z] < level6[z] && hma[z - 1] > level6[z - 1] &&
                       close[z] < close[z - 2]
                   ? 1
                   : -1;
    sell7[z] = hma[z] < level7[z] && hma[z - 1] > level7[z - 1] &&
                       close[z] < close[z - 2]
                   ? 1
                   : -1;
    sell8[z] = hma[z] < level8[z] && hma[z - 1] > level8[z - 1] &&
                       close[z] < close[z - 2]
                   ? 1
                   : -1;
  }
  free(nz_hma);
  free(hma);
  free(level1);
  free(level2);
  free(level3);
  free(level4);
  free(level5);
  free(level6);
  free(level7);
  free(level8);
  return TI_OKAY;
}
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

int ti_supertrend_start(TI_REAL const *options)
{
  (void)(options);
  return 0;
}
int ti_supertrend(int size, TI_REAL const *const *inputs,
                  TI_REAL const *options, TI_REAL *const *outputs)
{
  const TI_REAL *high = inputs[0];
  const TI_REAL *low = inputs[1];
  const TI_REAL *close = inputs[2];
  TI_REAL *superTrend = outputs[0];
  TI_REAL *direction = outputs[1];
  double *color = outputs[2];
  double *signal = outputs[3];
  const int period = (int)options[0];
  const int factor = (int)options[1];
  if (period < 1)
    return TI_INVALID_OPTION;
  for (int i = 0; i < size; i++)
  {
    superTrend[i] = 0;
    direction[i] = 0;
    color[i] = 0;
    signal[i] = 0;
  }
  const double nz_atr_options[] = {options[0]};
  double *nz_atr = malloc((unsigned int)size * sizeof(double));
  assert(nz_atr != 0);
  const double *nz_atr_inputs[] = {high, low, close};
  double *nz_atr_outputs[] = {nz_atr};
  int error = ti_atr(size, nz_atr_inputs, nz_atr_options, nz_atr_outputs);
  assert(error == TI_OKAY);
  double *atr = (double *)calloc((size_t)size, sizeof(double));
  const double *atr_inputs[] = {nz_atr};
  double *atr_outputs[] = {atr};
  int range = period - 1;
  double value = 0;
  const double atr_options[] = {value, range};
  int error1 = ti_unshift(size, atr_inputs, atr_options, atr_outputs);
  assert(error1 == TI_OKAY);
  double *upperBand = (double *)calloc((size_t)size, sizeof(double));
  double *lowerBand = (double *)calloc((size_t)size, sizeof(double));
  for (int i = 0; i < size; i++)
  {
    upperBand[i] = ((high[i] + low[i]) / 2) + (factor * atr[i]);
    lowerBand[i] = ((high[i] + low[i]) / 2) - (factor * atr[i]);
  }
  for (int j = 1; j < size; j++)
  {
    if (lowerBand[j] > lowerBand[j - 1] || close[j - 1] < lowerBand[j - 1])
      lowerBand[j] = lowerBand[j];
    else
      lowerBand[j] = lowerBand[j - 1];
    if (upperBand[j] < upperBand[j - 1] || close[j - 1] > upperBand[j - 1])
      upperBand[j] = upperBand[j];
    else
      upperBand[j] = upperBand[j - 1];
  }
  for (int i = 1; i < size; i++)
  {
    if (superTrend[i - 1] == upperBand[i - 1])
    {
      if (close[i] > upperBand[i])
        direction[i] = -1;
      else
        direction[i] = 1;
    }
    else
    {
      if (close[i] < lowerBand[i])
        direction[i] = 1;
      else
        direction[i] = -1;
    }
    if (direction[i] == -1)
      superTrend[i] = lowerBand[i];
    else
      superTrend[i] = upperBand[i];
    signal[0] = TI_NOTHING;
  }
  for (int i = 1; i < size; i++)
    if (direction[i] == 1 && direction[i - 1] == -1)
      signal[i] = TI_SELL;
    else if (direction[i] == -1 && direction[i - 1] == 1)
      signal[i] = TI_BUY;
    else
      signal[i] = TI_NOTHING;
  for (int i = 0; i < size; i++)
    if (direction[i] == -1)
      color[i] = TI_GREEN;
    else
      color[i] = TI_RED;
  free(nz_atr);
  free(atr);
  free(upperBand);
  free(lowerBand);
  return TI_OKAY;
}
int ti_tan_start(TI_REAL const *options) { (void)options; return 0; } int ti_tan(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (tan(in1[i])); } return TI_OKAY; }
int ti_tanh_start(TI_REAL const *options) { (void)options; return 0; } int ti_tanh(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = (tanh(in1[i])); } return TI_OKAY; }
int ti_tema_start(TI_REAL const *options) {
    const int period = (int)options[0];
    return (period-1) * 3;
}
int ti_tema(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_tema_start(options)) return TI_OKAY;
    const TI_REAL per = 2 / ((TI_REAL)period + 1);
    const TI_REAL per1 = 1.0 - per;
    TI_REAL ema = input[0];
    TI_REAL ema2 = 0;
    TI_REAL ema3 = 0;
    int i;
    for (i = 0; i < size; ++i) {
        ema = ema * per1 + input[i] * per;
        if (i == period-1) {
            ema2 = ema;
        }
        if (i >= period-1) {
            ema2 = ema2 * per1 + ema * per;
            if (i == (period-1) * 2) {
                ema3 = ema2;
            }
            if (i >= (period-1) * 2) {
                ema3 = ema3 * per1 + ema2 * per;
                if (i >= (period-1) * 3) {
                    *output = 3 * ema - 3 * ema2 + ema3;
                    ++output;
                }
            }
        }
    }
    assert(output - outputs[0] == size - ti_tema_start(options));
    return TI_OKAY;
}
int ti_todeg_start(TI_REAL const *options) { (void)options; return 0; } int ti_todeg(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = ((in1[i] * (180.0 / 3.14159265358979323846))); } return TI_OKAY; }
int ti_torad_start(TI_REAL const *options) { (void)options; return 0; } int ti_torad(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = ((in1[i] * (3.14159265358979323846 / 180.0))); } return TI_OKAY; }
int ti_tr_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_tr(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    (void)options;
    TI_REAL *output = outputs[0];
    TI_REAL truerange;
    output[0] = high[0] - low[0];
    int i;
    for (i = 1; i < size; ++i) {
        do{ const TI_REAL l = low[i]; const TI_REAL h = high[i]; const TI_REAL c = close[i-1]; const TI_REAL ych = fabs(h - c); const TI_REAL ycl = fabs(l - c); TI_REAL v = h - l; if (ych > v) v = ych; if (ycl > v) v = ycl; truerange = v;}while(0);
        output[i] = truerange;
    }
    return TI_OKAY;
}
int ti_trima_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_trima(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_trima_start(options)) return TI_OKAY;
    if (period <= 2) return ti_sma(size, inputs, options, outputs);
    TI_REAL weights = 1 / (TI_REAL) ((period%2) ?
        ((period/2+1) * (period/2+1)):
        ((period/2+1) * (period/2)));
    TI_REAL weight_sum = 0;
    TI_REAL lead_sum = 0;
    TI_REAL trail_sum = 0;
    const int lead_period = period%2 ? period/2 : period/2-1;
    const int trail_period = lead_period + 1;
    int i, w = 1;
    for (i = 0; i < period-1; ++i) {
        weight_sum += input[i] * w;
        if (i+1 > period-lead_period) lead_sum += input[i];
        if (i+1 <= trail_period) trail_sum += input[i];
        if (i+1 < trail_period) ++w;
        if (i+1 >= period-lead_period) --w;
    }
    int lsi = (period-1)-lead_period+1;
    int tsi1 = (period-1)-period+1+trail_period;
    int tsi2 = (period-1)-period+1;
    for (i = period-1; i < size; ++i) {
        weight_sum += input[i];
        *output++ = weight_sum * weights;
        lead_sum += input[i];
        weight_sum += lead_sum;
        weight_sum -= trail_sum;
        lead_sum -= input[lsi++];
        trail_sum += input[tsi1++];
        trail_sum -= input[tsi2++];
    }
    assert(output - outputs[0] == size - ti_trima_start(options));
    return TI_OKAY;
}
int ti_trix_start(TI_REAL const *options) {
    const int period = (int)options[0];
    return ((period-1)*3)+1;
}
int ti_trix(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_trix_start(options)) return TI_OKAY;
    const int start = (period*3)-2;
    assert(start == ti_trix_start(options));
    const TI_REAL per = 2 / ((TI_REAL)period + 1);
    TI_REAL ema1 = input[0];
    TI_REAL ema2 = 0, ema3 = 0;
    int i;
    for (i = 1; i < start; ++i) {
        ema1 = (input[i]-ema1) * per + ema1;
        if (i == period-1) {
            ema2 = ema1;
        } else if (i > period-1) {
            ema2 = (ema1-ema2) * per + ema2;
            if (i == period * 2 - 2) {
                ema3 = ema2;
            } else if (i > period * 2 - 2) {
                ema3 = (ema2-ema3) * per + ema3;
            }
        }
    }
    for (i = start; i < size; ++i) {
        ema1 = (input[i]-ema1) * per + ema1;
        ema2 = (ema1-ema2) * per + ema2;
        const TI_REAL last = ema3;
        ema3 = (ema2-ema3) * per + ema3;
        *output++ = (ema3-last)/ema3 * 100.0;
    }
    assert(output - outputs[0] == size - ti_trix_start(options));
    return TI_OKAY;
}
int ti_trunc_start(TI_REAL const *options) { (void)options; return 0; } int ti_trunc(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) { const TI_REAL *in1 = inputs[0]; (void)options; TI_REAL *output = outputs[0]; int i; for (i = 0; i < size; ++i) { output[i] = ((int)(in1[i])); } return TI_OKAY; }
int ti_tsf_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_tsf(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_tsf_start(options)) return TI_OKAY;
    do { TI_REAL x = 0; TI_REAL x2 = 0; TI_REAL y = 0; TI_REAL xy = 0; const TI_REAL p = (1.0 / (period)); int i; for (i = 0; i < (period)-1; ++i) { x += i+1; x2 += (i+1)*(i+1); xy += (input)[i] * (i+1); y += (input)[i]; } x += (period); x2 += (period) * (period); const TI_REAL bd = 1.0 / ((period) * x2 - x * x); for (i = (period)-1; i < (size); ++i) { xy += (input)[i] * (period); y += (input)[i]; const TI_REAL b = ((period) * xy - x * y) * bd; do { const TI_REAL a = (y - b * x) * p; *output++ = (a + b * ((period+1))); } while (0); xy -= y; y -= (input)[i-(period)+1]; } } while (0);
    assert(output - outputs[0] == size - ti_tsf_start(options));
    return TI_OKAY;
}
int ti_typprice_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_typprice(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    (void)options;
    TI_REAL *output = outputs[0];
    int i;
    for (i = 0; i < size; ++i) {
        output[i] = (high[i] + low[i] + close[i]) * (1.0/3.0);
    }
    return TI_OKAY;
}
int ti_ultosc_start(TI_REAL const *options) {
    return (int)options[2];
}
int ti_ultosc(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    const int short_period = (int)options[0];
    const int medium_period = (int)options[1];
    const int long_period = (int)options[2];
    TI_REAL *output = outputs[0];
    if (short_period < 1) return TI_INVALID_OPTION;
    if (medium_period < short_period) return TI_INVALID_OPTION;
    if (long_period < medium_period) return TI_INVALID_OPTION;
    if (size <= ti_ultosc_start(options)) return TI_OKAY;
    ti_buffer *bp_buf = ti_buffer_new(long_period);
    ti_buffer *r_buf = ti_buffer_new(long_period);
    TI_REAL bp_short_sum = 0, bp_medium_sum = 0;
    TI_REAL r_short_sum = 0, r_medium_sum = 0;
    int i;
    for (i = 1; i < size; ++i) {
        const TI_REAL true_low = MIN(low[i], close[i-1]);
        const TI_REAL true_high = MAX(high[i], close[i-1]);
        const TI_REAL bp = close[i] - true_low;
        const TI_REAL r = true_high - true_low;
        bp_short_sum += bp;
        bp_medium_sum += bp;
        r_short_sum += r;
        r_medium_sum += r;
        ti_buffer_push(bp_buf, bp);
        ti_buffer_push(r_buf, r);
        if (i > short_period) {
            int short_index = bp_buf->index - short_period - 1;
            if (short_index < 0) short_index += long_period;
            bp_short_sum -= bp_buf->vals[short_index];
            r_short_sum -= r_buf->vals[short_index];
            if (i > medium_period) {
                int medium_index = bp_buf->index - medium_period - 1;
                if (medium_index < 0) medium_index += long_period;
                bp_medium_sum -= bp_buf->vals[medium_index];
                r_medium_sum -= r_buf->vals[medium_index];
            }
        }
        if (i >= long_period) {
            const TI_REAL first = 4 * bp_short_sum / r_short_sum;
            const TI_REAL second = 2 * bp_medium_sum / r_medium_sum;
            const TI_REAL third = 1 * bp_buf->sum / r_buf->sum;
            const TI_REAL ult = (first + second + third) * 100.0 / 7.0;
            *output++ = ult;
        }
    }
    ti_buffer_free(bp_buf);
    ti_buffer_free(r_buf);
    assert(output - outputs[0] == size - ti_ultosc_start(options));
    return TI_OKAY;
}
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

int ti_unshift_start(TI_REAL const *options) {
  (void)(options);
  return 0;
}
int ti_unshift(int size, TI_REAL const *const *inputs, TI_REAL const *options,
               TI_REAL *const *outputs) {
  const TI_REAL *new_arr = inputs[0];
  TI_REAL *output = outputs[0];
  const int n = (int)options[0];
  const int length = (int)options[1];
  for (int i = 0; i < length; i++)
    output[i] = n;
  for (int i = length; i < size; i++)
    output[i] = new_arr[i - length];
  return 0;
}
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

int ti_ut_bot_start(TI_REAL const *options)
{
  (void)(options);
  return 0;
}
int ti_ut_bot(int size, TI_REAL const *const *inputs, TI_REAL const *options,
              TI_REAL *const *outputs)
{
  const TI_REAL *high = inputs[0];
  const TI_REAL *low = inputs[1];
  const TI_REAL *close = inputs[2];
  double *signal = outputs[0];
  const int atr_period = (int)options[0];
  const double sensitivity = (double)options[1];
  if (atr_period < 1 || sensitivity < 0)
    return TI_INVALID_OPTION;
  const double nz_xATR_options[] = {atr_period};
  double *nz_xATR = malloc((unsigned int)size * sizeof(double));
  assert(nz_xATR != 0);
  const double *nz_xATR_inputs[] = {high, low, close};
  double *nz_xATR_outputs[] = {nz_xATR};
  int error = ti_atr(size, nz_xATR_inputs, nz_xATR_options, nz_xATR_outputs);
  assert(error == TI_OKAY);
  double *xATR = (double *)calloc((size_t)size, sizeof(double));
  const double *xATR_inputs[] = {nz_xATR};
  double *xATR_outputs[] = {xATR};
  int range1 = atr_period - 1;
  double value1 = 0;
  const double xATR_options[] = {value1, range1};
  int error1 = ti_unshift(size, xATR_inputs, xATR_options, xATR_outputs);
  assert(error1 == TI_OKAY);
  for (int i = 0; i < size; i++)
    xATR[i] = xATR[i] * sensitivity;
  double *xATRTrailingStop = (double *)calloc((size_t)size, sizeof(double));
  double *ema = (double *)calloc((size_t)size, sizeof(double));
  const double ema_options[] = {1};
  const double *ema_inputs[] = {close};
  double *ema_outputs[] = {ema};
  int error2 = ti_ema(size, ema_inputs, ema_options, ema_outputs);
  assert(error2 == TI_OKAY);
  for (int i = 1; i < size; i++)
  {
    if (close[i] > not_zero(xATRTrailingStop[i - 1], 0) &&
        close[i - 1] > not_zero(xATRTrailingStop[i - 1], 0))
      xATRTrailingStop[i] =
          fmax(not_zero(xATRTrailingStop[i - 1], 0), close[i] - xATR[i]);
    else if (close[i] < not_zero(xATRTrailingStop[i - 1], 0) &&
             close[i - 1] < not_zero(xATRTrailingStop[i - 1], 0))
      xATRTrailingStop[i] =
          fmin(not_zero(xATRTrailingStop[i - 1], 0), close[i] + xATR[i]);
    else if (close[i] > not_zero(xATRTrailingStop[i - 1], 0))
      xATRTrailingStop[i] = close[i] - xATR[i];
    else
      xATRTrailingStop[i] = close[i] + xATR[i];
  }
  const double nz_above_options[] = {0};
  double *nz_above = (double *)calloc((size_t)size, sizeof(double));
  const double *nz_above_inputs[] = {ema, xATRTrailingStop};
  double *nz_above_outputs[] = {nz_above};
  int error9 =
      ti_crossover(size, nz_above_inputs, nz_above_options, nz_above_outputs);
  assert(error9 == TI_OKAY);
  double *above = (double *)calloc((size_t)size, sizeof(double));
  const double *above_inputs[] = {nz_above};
  double *above_outputs[] = {above};
  int range10 = 1;
  double value10 = 0;
  const double above_options[] = {value10, range10};
  int error10 = ti_unshift(size, above_inputs, above_options, above_outputs);
  assert(error10 == TI_OKAY);
  const double nz_below_options[] = {0};
  double *nz_below = (double *)calloc((size_t)size, sizeof(double));
  const double *nz_below_inputs[] = {xATRTrailingStop, ema};
  double *nz_below_outputs[] = {nz_below};
  int error8 =
      ti_crossover(size, nz_below_inputs, nz_below_options, nz_below_outputs);
  assert(error8 == TI_OKAY);
  double *below = (double *)calloc((size_t)size, sizeof(double));
  const double *below_inputs[] = {nz_below};
  double *below_outputs[] = {below};
  int range101 = 1;
  double value101 = 0;
  const double below_options[] = {value101, range101};
  int error101 = ti_unshift(size, below_inputs, below_options, below_outputs);
  assert(error101 == TI_OKAY);
  for (int i = 0; i < size; i++)
  {
    if (close[i] > xATRTrailingStop[i] && above[i] == 1)
      signal[i] = TI_BUY;
    else if (close[i] < xATRTrailingStop[i] && below[i] == 1)
      signal[i] = TI_SELL;
    else
      signal[i] = TI_NOTHING;
  }
  free(below);
  free(nz_below);
  free(above);
  free(nz_above);
  free(ema);
  free(xATR);
  free(xATRTrailingStop);
  free(nz_xATR);
  return TI_OKAY;
}
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

double max_value(double arr[], int n)
{
  int i;
  double max_value = arr[0];
  for (i = 1; i < n; i++)
    if (arr[i] > max_value)
      max_value = arr[i];
  return max_value;
}
double min_value(double arr[], int n)
{
  int i;
  double min_value = arr[0];
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
int ti_var_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_var(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    const TI_REAL scale = 1.0 / period;
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_var_start(options)) return TI_OKAY;
    TI_REAL sum = 0;
    TI_REAL sum2 = 0;
    int i;
    for (i = 0; i < period; ++i) {
        sum += input[i];
        sum2 += input[i] * input[i];
    }
    *output++ = sum2 * scale - (sum * scale) * (sum * scale);
    for (i = period; i < size; ++i) {
        sum += input[i];
        sum2 += input[i] * input[i];
        sum -= input[i-period];
        sum2 -= input[i-period] * input[i-period];
        *output++ = sum2 * scale - (sum * scale) * (sum * scale);
    }
    assert(output - outputs[0] == size - ti_var_start(options));
    return TI_OKAY;
}
int ti_vhf_start(TI_REAL const *options) {
    return (int)options[0];
}
int ti_vhf(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *in = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_vhf_start(options)) return TI_OKAY;
    int trail = 1, maxi = -1, mini = -1;
    TI_REAL max = in[0], min = in[0];
    TI_REAL bar;
    TI_REAL sum = 0;
    int i, j;
    TI_REAL yc = in[0];
    TI_REAL c;
    for (i = 1; i < period; ++i) {
        c = in[i];
        sum += fabs(c - yc);
        yc = c;
    }
    for (i = period; i < size; ++i, ++trail) {
        c = in[i];
        sum += fabs(c - yc);
        yc = c;
        if (i > period) {
            sum -= fabs(in[i-period] - in[i-period-1]);
        }
        bar = c;
        if (maxi < trail) {
            maxi = trail;
            max = in[maxi];
            j = trail;
            while(++j <= i) {
                bar = in[j];
                if (bar >= max) {
                    max = bar;
                    maxi = j;
                }
            }
        } else if (bar >= max) {
            maxi = i;
            max = bar;
        }
        bar = c;
        if (mini < trail) {
            mini = trail;
            min = in[mini];
            j = trail;
            while(++j <= i) {
                bar = in[j];
                if (bar <= min) {
                    min = bar;
                    mini = j;
                }
            }
        } else if (bar <= min) {
            mini = i;
            min = bar;
        }
        *output++ = fabs(max - min) / sum;
    }
    assert(output - outputs[0] == size - ti_vhf_start(options));
    return TI_OKAY;
}
int ti_vidya_start(TI_REAL const *options) {
    return ((int)(options[1])) - 2;
}
int ti_vidya(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int short_period = (int)options[0];
    const int long_period = (int)options[1];
    const TI_REAL alpha = options[2];
    TI_REAL *output = outputs[0];
    const TI_REAL short_div = 1.0 / short_period;
    const TI_REAL long_div = 1.0 / long_period;
    if (short_period < 1) return TI_INVALID_OPTION;
    if (long_period < short_period) return TI_INVALID_OPTION;
    if (long_period < 2) return TI_INVALID_OPTION;
    if (alpha < 0.0 || alpha > 1.0) return TI_INVALID_OPTION;
    if (size <= ti_vidya_start(options)) return TI_OKAY;
    TI_REAL short_sum = 0;
    TI_REAL short_sum2 = 0;
    TI_REAL long_sum = 0;
    TI_REAL long_sum2 = 0;
    int i;
    for (i = 0; i < long_period; ++i) {
        long_sum += input[i];
        long_sum2 += input[i] * input[i];
        if (i >= long_period - short_period) {
            short_sum += input[i];
            short_sum2 += input[i] * input[i];
        }
    }
    TI_REAL val = input[long_period-2];
    *output++ = val;
    if (long_period - 1 < size) {
        TI_REAL short_stddev = sqrt(short_sum2 * short_div - (short_sum * short_div) * (short_sum * short_div));
        TI_REAL long_stddev = sqrt(long_sum2 * long_div - (long_sum * long_div) * (long_sum * long_div));
        TI_REAL k = short_stddev / long_stddev;
        if (k != k) k = 0;
        k *= alpha;
        val = (input[long_period-1]-val) * k + val;
        *output++ = val;
    }
    for (i = long_period; i < size; ++i) {
        long_sum += input[i];
        long_sum2 += input[i] * input[i];
        short_sum += input[i];
        short_sum2 += input[i] * input[i];
        long_sum -= input[i-long_period];
        long_sum2 -= input[i-long_period] * input[i-long_period];
        short_sum -= input[i-short_period];
        short_sum2 -= input[i-short_period] * input[i-short_period];
        {
            TI_REAL short_stddev = sqrt(short_sum2 * short_div - (short_sum * short_div) * (short_sum * short_div));
            TI_REAL long_stddev = sqrt(long_sum2 * long_div - (long_sum * long_div) * (long_sum * long_div));
            TI_REAL k = short_stddev / long_stddev;
            if (k != k) k = 0;
            k *= alpha;
            val = (input[i]-val) * k + val;
            *output++ = val;
        }
    }
    assert(output - outputs[0] == size - ti_vidya_start(options));
    return TI_OKAY;
}
int ti_volatility_start(TI_REAL const *options) {
    return (int)options[0];
}
int ti_volatility(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    TI_REAL *output = outputs[0];
    const int period = (int)options[0];
    const TI_REAL scale = 1.0 / period;
    const TI_REAL annual = sqrt(252);
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_volatility_start(options)) return TI_OKAY;
    TI_REAL sum = 0;
    TI_REAL sum2 = 0;
    int i;
    for (i = 1; i <= period; ++i) {
        const TI_REAL c = (input[i]/input[i-1]-1.0);
        sum += c;
        sum2 += c * c;
    }
    *output++ = sqrt(sum2 * scale - (sum * scale) * (sum * scale)) * annual;
    for (i = period+1; i < size; ++i) {
        const TI_REAL c = (input[i]/input[i-1]-1.0);
        sum += c;
        sum2 += c * c;
        const TI_REAL cp = (input[i-period]/input[i-period-1]-1.0);
        sum -= cp;
        sum2 -= cp * cp;
        *output++ = sqrt(sum2 * scale - (sum * scale) * (sum * scale)) * annual;
    }
    assert(output - outputs[0] == size - ti_volatility_start(options));
    return TI_OKAY;
}
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

int ti_volatility_oscillator_start(TI_REAL const *options)
{
  (void)(options);
  return 0;
}
int ti_volatility_oscillator(int size, TI_REAL const *const *inputs,
                             TI_REAL const *options, TI_REAL *const *outputs)
{
  const TI_REAL *open = inputs[0];
  const TI_REAL *close = inputs[1];
  TI_REAL *spike = outputs[0];
  TI_REAL *upper_line = outputs[1];
  TI_REAL *lower_line = outputs[2];
  const int length = (int)options[0];
  if (length < 1)
    return TI_INVALID_OPTION;
  double *nz_lower = (double *)calloc((size_t)size, sizeof(double));
  double *nz_upper = (double *)calloc((size_t)size, sizeof(double));
  for (int i = 0; i < size; i++)
  {
    spike[i] = close[i] - open[i];
  }
  const double nz_upper_options[] = {length};
  const double *nz_upper_inputs[] = {spike};
  double *nz_upper_outputs[] = {nz_upper};
  int error =
      ti_stddev(size, nz_upper_inputs, nz_upper_options, nz_upper_outputs);
  assert(error == TI_OKAY);
  const double *upper_inputs[] = {nz_upper};
  double *upper_outputs[] = {upper_line};
  int range = length - 1;
  double value = 0;
  const double upper_options[] = {value, range};
  int error1 = ti_unshift(size, upper_inputs, upper_options, upper_outputs);
  assert(error1 == TI_OKAY);
  const double nz_lower_options[] = {length};
  const double *nz_lower_inputs[] = {spike};
  double *nz_lower_outputs[] = {nz_lower};
  int error3 =
      ti_stddev(size, nz_lower_inputs, nz_lower_options, nz_lower_outputs);
  assert(error3 == TI_OKAY);
  const double *lower_inputs[] = {nz_lower};
  double *lower_outputs[] = {lower_line};
  int range1 = length - 1;
  double value1 = 0;
  const double lower_options[] = {value1, range1};
  int error2 = ti_unshift(size, lower_inputs, lower_options, lower_outputs);
  assert(error2 == TI_OKAY);
  for (int i = 0; i < size; i++)
  {
    lower_line[i] = lower_line[i] * -1;
  }
  free(nz_lower);
  free(nz_upper);
  return TI_OKAY;
}
int ti_vosc_start(TI_REAL const *options) {
    return (int)options[1]-1;
}
int ti_vosc(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    TI_REAL *output = outputs[0];
    const int short_period = (int)options[0];
    const int long_period = (int)options[1];
    const TI_REAL short_div = 1.0 / short_period;
    const TI_REAL long_div = 1.0 / long_period;
    if (short_period < 1) return TI_INVALID_OPTION;
    if (long_period < short_period) return TI_INVALID_OPTION;
    if (size <= ti_vosc_start(options)) return TI_OKAY;
    TI_REAL short_sum = 0;
    TI_REAL long_sum = 0;
    int i;
    for (i = 0; i < long_period; ++i) {
        if (i >= (long_period - short_period)) {
            short_sum += input[i];
        }
        long_sum += input[i];
    }
    {
        const TI_REAL savg = short_sum * short_div;
        const TI_REAL lavg = long_sum * long_div;
        *output++ = 100.0 * (savg - lavg) / lavg;
    }
    for (i = long_period; i < size; ++i) {
        short_sum += input[i];
        short_sum -= input[i-short_period];
        long_sum += input[i];
        long_sum -= input[i-long_period];
        const TI_REAL savg = short_sum * short_div;
        const TI_REAL lavg = long_sum * long_div;
        *output++ = 100.0 * (savg - lavg) / lavg;
    }
    assert(output - outputs[0] == size - ti_vosc_start(options));
    return TI_OKAY;
}
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

int ti_vu_man_chu_swing_start(TI_REAL const *options)
{
  (void)(options);
  return 0;
}
int ti_vu_man_chu_swing(int size, TI_REAL const *const *inputs,
                        TI_REAL const *options, TI_REAL *const *outputs)
{
  const TI_REAL *close = inputs[0];
  TI_REAL *longCondition = outputs[0];
  TI_REAL *shortCondition = outputs[1];
  const int swing_period = (int)options[0];
  const int swing_multiplier = (int)options[1];
  if (swing_period < 1 || swing_multiplier < 1)
    return TI_INVALID_OPTION;
  for (int i = 0; i < size; i++)
  {
    longCondition[i] = 0;
    shortCondition[i] = 0;
  }
  double *rng_ = (double *)calloc((size_t)size, sizeof(double));
  double *dif_x = (double *)calloc((size_t)size, sizeof(double));
  int wper = swing_period * 2 - 1;
  for (int i = 1; i < size; i++)
  {
    dif_x[i] = fabs(close[i] - close[i - 1]);
  }
  const double avrng_options[] = {swing_period};
  double *avrng = (double *)calloc((size_t)size, sizeof(double));
  const double *avrng_inputs[] = {dif_x};
  double *avrng_outputs[] = {avrng};
  int error1 = ti_ema(size, avrng_inputs, avrng_options, avrng_outputs);
  assert(error1 == TI_OKAY);
  const double ac1_options[] = {wper};
  double *ac1 = (double *)calloc((size_t)size, sizeof(double));
  const double *ac1_inputs[] = {avrng};
  double *ac1_outputs[] = {ac1};
  int error2 = ti_ema(size, ac1_inputs, ac1_options, ac1_outputs);
  assert(error2 == TI_OKAY);
  for (int i = 0; i < size; i++)
  {
    rng_[i] = ac1[i] * swing_multiplier;
  }
  double *rfilt = (double *)calloc((size_t)size, sizeof(double));
  rfilt[0] = close[0];
  double *hi_band = (double *)calloc((size_t)size, sizeof(double));
  double *lo_band = (double *)calloc((size_t)size, sizeof(double));
  double *fdir = (double *)calloc((size_t)size, sizeof(double));
  double *upward = (double *)calloc((size_t)size, sizeof(double));
  double *downward = (double *)calloc((size_t)size, sizeof(double));
  double *longCond = (double *)calloc((size_t)size, sizeof(double));
  double *shortCond = (double *)calloc((size_t)size, sizeof(double));
  double *CondIni = (double *)calloc((size_t)size, sizeof(double));
  for (int i = 1; i < size; i++)
  {
    if (close[i] - rng_[i] > rfilt[i - 1])
    {
      rfilt[i] = close[i] - rng_[i];
    }
    else if (close[i] + rng_[i] < rfilt[i - 1])
    {
      rfilt[i] = close[i] + rng_[i];
    }
    else
    {
      rfilt[i] = rfilt[i - 1];
    }
    hi_band[i] = rfilt[i - 1] + rng_[i];
    lo_band[i] = rfilt[i - 1] - rng_[i];
  }
  for (int i = 1; i < size; i++)
  {
    if (rfilt[i] > rfilt[i - 1])
    {
      fdir[i] = 1;
    }
    else if (rfilt[i] < rfilt[i - 1])
    {
      fdir[i] = -1;
    }
    else
    {
      fdir[i] = fdir[i - 1];
    }
  }
  for (int i = 0; i < size; i++)
  {
    if (fdir[i] == 1)
    {
      upward[i] = 1;
      downward[i] = 0;
    }
    else if (fdir[i] == -1)
    {
      upward[i] = 0;
      downward[i] = 1;
    }
    else
    {
      upward[i] = 0;
      downward[i] = 0;
    }
  }
  for (int i = 1; i < size; i++)
  {
    if (close[i] > rfilt[i] && upward[i] == 1 &&
        (close[i] > close[i - 1] || close[i] < close[i - 1]))
    {
      longCond[i] = 1;
      shortCond[i] = 0;
    }
    else if (close[i] < rfilt[i] && downward[i] == 1 &&
             (close[i] > close[i - 1] || close[i] < close[i - 1]))
    {
      longCond[i] = 0;
      shortCond[i] = 1;
    }
    else
    {
      longCond[i] = 0;
      shortCond[i] = 0;
    }
  }
  for (int i = 1; i < size; i++)
  {
    if (longCond[i] == 1)
    {
      CondIni[i] = 1;
    }
    else if (shortCond[i] == 1)
    {
      CondIni[i] = -1;
    }
    else
    {
      CondIni[i] = CondIni[i - 1];
    }
  }
  for (int i = 1; i < size; i++)
  {
    if (longCond[i] == 1 && CondIni[i - 1] == -1)
    {
      longCondition[i] = 1;
      shortCondition[i] = 0;
    }
    else if (shortCond[i] == 1 && CondIni[i - 1] == 1)
    {
      longCondition[i] = 0;
      shortCondition[i] = -1;
    }
    else
    {
      longCondition[i] = 0;
      shortCondition[i] = 0;
    }
  }
  free(rng_);
  free(dif_x);
  free(avrng);
  free(ac1);
  free(rfilt);
  free(hi_band);
  free(lo_band);
  free(fdir);
  free(upward);
  free(downward);
  free(longCond);
  free(shortCond);
  free(CondIni);
  return TI_OKAY;
}
int ti_vwma_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_vwma(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const TI_REAL *volume = inputs[1];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_vwma_start(options)) return TI_OKAY;
    TI_REAL sum = 0;
    TI_REAL vsum = 0;
    int i;
    for (i = 0; i < period; ++i) {
        sum += input[i] * volume[i];
        vsum += volume[i];
    }
    *output++ = sum / vsum;
    for (i = period; i < size; ++i) {
        sum += input[i] * volume[i];
        sum -= input[i-period] * volume[i-period];
        vsum += volume[i];
        vsum -= volume[i-period];
        *output++ = sum / vsum;
    }
    assert(output - outputs[0] == size - ti_vwma_start(options));
    return TI_OKAY;
}
int ti_wad_start(TI_REAL const *options) {
    (void)options;
    return 1;
}
int ti_wad(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    (void)options;
    if (size <= ti_wad_start(options)) return TI_OKAY;
    TI_REAL *output = outputs[0];
    TI_REAL sum = 0;
    TI_REAL yc = close[0];
    int i;
    for (i = 1; i < size; ++i) {
        const TI_REAL c = close[i];
        if (c > yc) {
            sum += c - MIN(yc, low[i]);
        } else if (c < yc) {
            sum += c - MAX(yc, high[i]);
        } else {
        }
        *output++ = sum;
        yc = close[i];
    }
    assert(output - outputs[0] == size - ti_wad_start(options));
    return TI_OKAY;
}
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

int ti_waddah_start(TI_REAL const *options)
{
  (void)(options);
  return 0;
}
int ti_waddah(int size, TI_REAL const *const *inputs, TI_REAL const *options,
              TI_REAL *const *outputs)
{
  const TI_REAL *close = inputs[0];
  TI_REAL *t1 = outputs[0];
  TI_REAL *e1 = outputs[1];
  TI_REAL *trendUp = outputs[2];
  TI_REAL *trendDown = outputs[3];
  const int fast_length = (int)options[0];
  const int slow_length = (int)options[1];
  const int signal_length = (int)options[2];
  const int BB_length = (int)options[3];
  const int multiplier = (int)options[4];
  const int sensitivity = (int)options[5];
  if (fast_length < 1 || slow_length < 1 || signal_length < 1 || BB_length < 1)
    return TI_INVALID_OPTION;
  for (int i = 0; i < size; i++)
  {
    t1[i] = 0;
    e1[i] = 0;
    trendUp[i] = 0;
    trendDown[i] = 0;
  }
  const double nz_macd_options[] = {fast_length, slow_length, signal_length};
  double *nz_macd = malloc((size_t)size * sizeof(double));
  double *nz_signal = malloc((size_t)size * sizeof(double));
  double *nz_hist = malloc((size_t)size * sizeof(double));
  assert(nz_macd != 0);
  const double *nz_macd_inputs[] = {close};
  double *nz_macd_outputs[] = {nz_macd, nz_signal, nz_hist};
  int error = ti_macd(size, nz_macd_inputs, nz_macd_options, nz_macd_outputs);
  assert(error == TI_OKAY);
  double *macd_line = malloc((unsigned int)size * sizeof(double));
  const double *macd_inputs[] = {nz_macd};
  double *macd_outputs[] = {macd_line};
  int range = slow_length - 1;
  double value = 0;
  const double macdline_option[] = {value, range};
  int error1 = ti_unshift(size, macd_inputs, macdline_option, macd_outputs);
  assert(error1 == TI_OKAY);
  const double nz_bb_bands_options[] = {BB_length, multiplier};
  double *nz_bbands_lower = malloc((unsigned int)size * sizeof(double));
  double *nz_bbands_middle = malloc((unsigned int)size * sizeof(double));
  double *nz_bbands_upper = malloc((unsigned int)size * sizeof(double));
  assert(nz_bbands_lower != 0);
  const double *nz_bb_bands_inputs[] = {close};
  double *nz_bb_bands_outputs[] = {nz_bbands_lower, nz_bbands_middle,
                                   nz_bbands_upper};
  int error2 = ti_bbands(size, nz_bb_bands_inputs, nz_bb_bands_options,
                         nz_bb_bands_outputs);
  assert(error2 == TI_OKAY);
  double *bbands_upper = malloc((unsigned int)size * sizeof(double));
  const double *bbands_upper_inputs[] = {nz_bbands_upper};
  double *bbands_upper_outputs[] = {bbands_upper};
  int range1 = BB_length - 1;
  double value1 = 0;
  const double bbupper_option[] = {value1, range1};
  int error3 = ti_unshift(size, bbands_upper_inputs, bbupper_option,
                          bbands_upper_outputs);
  assert(error3 == TI_OKAY);
  double *bbands_lower = malloc((unsigned int)size * sizeof(double));
  const double *bbands_lower_inputs[] = {nz_bbands_lower};
  double *bbands_lower_outputs[] = {bbands_lower};
  int range2 = BB_length - 1;
  double value2 = 0;
  const double bblower_option[] = {value2, range2};
  int error4 = ti_unshift(size, bbands_lower_inputs, bblower_option,
                          bbands_lower_outputs);
  assert(error4 == TI_OKAY);
  for (int i = 0; i < size; i++)
  {
    e1[i] = bbands_upper[i] - bbands_lower[i];
  }
  for (int i = 1; i < size; i++)
  {
    t1[i] = (macd_line[i] - macd_line[i - 1]) * sensitivity;
  }
  for (int i = 0; i < size; i++)
  {
    if (t1[i] >= 0)
    {
      trendUp[i] = t1[i];
      trendDown[i] = 0;
    }
    else if (t1[i] < 0)
    {
      trendDown[i] = -1 * t1[i];
      trendUp[i] = 0;
    }
    else
    {
      trendDown[i] = 0;
      trendUp[i] = 0;
    }
  }
  free(nz_macd);
  free(nz_signal);
  free(nz_hist);
  free(macd_line);
  free(nz_bbands_lower);
  free(nz_bbands_middle);
  free(nz_bbands_upper);
  free(bbands_upper);
  free(bbands_lower);
  return TI_OKAY;
}
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

int ti_wavetrend_start(TI_REAL const *options)
{
  (void)(options);
  return 0;
}
int ti_wavetrend(int size, TI_REAL const *const *inputs, TI_REAL const *options,
                 TI_REAL *const *outputs)
{
  const TI_REAL *high = inputs[0];
  const TI_REAL *low = inputs[1];
  const TI_REAL *close = inputs[2];
  TI_REAL *wt1 = outputs[0];
  TI_REAL *wt2 = outputs[1];
  const int period1 = (int)options[0];
  const int period2 = (int)options[1];
  if (period1 < 1 || period2 < 1)
    return TI_INVALID_OPTION;
  const double hlc3_options[] = {0};
  double *hlc3 = malloc((size_t)size * sizeof(double));
  assert(hlc3 != 0);
  const double *hlc3_inputs[] = {high, low, close};
  double *hlc3_outputs[] = {hlc3};
  int error = ti_hlc3(size, hlc3_inputs, hlc3_options, hlc3_outputs);
  assert(error == TI_OKAY);
  const double esa_options[] = {period1};
  double *esa = (double *)calloc((size_t)size, sizeof(double));
  const double *esa_inputs[] = {hlc3};
  double *esa_outputs[] = {esa};
  int error1 = ti_ema(size, esa_inputs, esa_options, esa_outputs);
  assert(error1 == TI_OKAY);
  double *d1_data = (double *)calloc((size_t)size, sizeof(double));
  for (int i = 0; i < size; i++)
  {
    d1_data[i] = fabs(hlc3[i] - esa[i]);
  }
  const double d1_options[] = {period1};
  double *d1 = (double *)calloc((size_t)size, sizeof(double));
  const double *d1_inputs[] = {d1_data};
  double *d1_outputs[] = {d1};
  int error2 = ti_ema(size, d1_inputs, d1_options, d1_outputs);
  assert(error2 == TI_OKAY);
  double *ci_data = (double *)calloc((size_t)size, sizeof(double));
  for (int i = 0; i < size; i++)
  {
    double ci_data1 = (hlc3[i] - esa[i]) / (0.015 * d1[i]);
    double ci_data2 = isnan(ci_data1) ? 0 : ci_data1;
    ci_data[i] = ci_data2;
  }
  const double wt1_options[] = {period2};
  const double *wt1_inputs[] = {ci_data};
  double *wt1_outputs[] = {wt1};
  int error3 = ti_ema(size, wt1_inputs, wt1_options, wt1_outputs);
  assert(error3 == TI_OKAY);
  double *wt2_data = (double *)calloc((size_t)size, sizeof(double));
  const double wt2_options[] = {4};
  const double *wt2_inputs[] = {wt1};
  double *wt2_outputs[] = {wt2_data};
  int error4 = ti_sma(size, wt2_inputs, wt2_options, wt2_outputs);
  assert(error4 == TI_OKAY);
  const double *wt2_data_inputs[] = {wt2_data};
  double *wt2_data_outputs[] = {wt2};
  int range = 4 - 1;
  double value = 0;
  const double unshift_options[] = {value, range};
  int error5 =
      ti_unshift(size, wt2_data_inputs, unshift_options, wt2_data_outputs);
  assert(error5 == TI_OKAY);
  free(hlc3);
  free(esa);
  free(d1_data);
  free(d1);
  free(ci_data);
  free(wt2_data);
  return TI_OKAY;
}
int ti_wcprice_start(TI_REAL const *options) {
    (void)options;
    return 0;
}
int ti_wcprice(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    (void)options;
    TI_REAL *output = outputs[0];
    int i;
    for (i = 0; i < size; ++i) {
        output[i] = (high[i] + low[i] + close[i] + close[i]) * 0.25;
    }
    return TI_OKAY;
}
int ti_wilders_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_wilders(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_wilders_start(options)) return TI_OKAY;
    const TI_REAL per = 1.0 / ((TI_REAL)period);
    TI_REAL sum = 0;
    int i;
    for (i = 0; i < period; ++i) {
        sum += input[i];
    }
    TI_REAL val = sum / period;
    *output++ = val;
    for (i = period; i < size; ++i) {
        val = (input[i]-val) * per + val;
        *output++ = val;
    }
    assert(output - outputs[0] == size - ti_wilders_start(options));
    return TI_OKAY;
}
int ti_willr_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_willr(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *high = inputs[0];
    const TI_REAL *low = inputs[1];
    const TI_REAL *close = inputs[2];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_willr_start(options)) return TI_OKAY;
    int trail = 0, maxi = -1, mini = -1;
    TI_REAL max = high[0];
    TI_REAL min = low[0];
    TI_REAL bar;
    int i, j;
    for (i = period-1; i < size; ++i, ++trail) {
        bar = high[i];
        if (maxi < trail) {
            maxi = trail;
            max = high[maxi];
            j = trail;
            while(++j <= i) {
                bar = high[j];
                if (bar >= max) {
                    max = bar;
                    maxi = j;
                }
            }
        } else if (bar >= max) {
            maxi = i;
            max = bar;
        }
        bar = low[i];
        if (mini < trail) {
            mini = trail;
            min = low[mini];
            j = trail;
            while(++j <= i) {
                bar = low[j];
                if (bar <= min) {
                    min = bar;
                    mini = j;
                }
            }
        } else if (bar <= min) {
            mini = i;
            min = bar;
        }
        const TI_REAL highlow = (max - min);
        const TI_REAL r = highlow == 0.0 ? 0.0 : -100 * ((max - close[i]) / highlow);
        *output++ = r;
    }
    assert(output - outputs[0] == size - ti_willr_start(options));
    return TI_OKAY;
}
int ti_wma_start(TI_REAL const *options) {
    return (int)options[0]-1;
}
int ti_wma(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_wma_start(options)) return TI_OKAY;
    const TI_REAL weights = period * (period+1) / 2;
    TI_REAL sum = 0;
    TI_REAL weight_sum = 0;
    int i;
    for (i = 0; i < period-1; ++i) {
        weight_sum += input[i] * (i+1);
        sum += input[i];
    }
    for (i = period-1; i < size; ++i) {
        weight_sum += input[i] * period;
        sum += input[i];
        *output++ = weight_sum / weights;
        weight_sum -= sum;
        sum -= input[i-period+1];
    }
    assert(output - outputs[0] == size - ti_wma_start(options));
    return TI_OKAY;
}
int ti_zlema_start(TI_REAL const *options) {
    return ((int)options[0] - 1) / 2 - 1;
}
int ti_zlema(int size, TI_REAL const *const *inputs, TI_REAL const *options, TI_REAL *const *outputs) {
    const TI_REAL *input = inputs[0];
    const int period = (int)options[0];
    const int lag = (period - 1) / 2;
    TI_REAL *output = outputs[0];
    if (period < 1) return TI_INVALID_OPTION;
    if (size <= ti_zlema_start(options)) return TI_OKAY;
    const TI_REAL per = 2 / ((TI_REAL)period + 1);
    TI_REAL val = input[lag-1];
    *output++ = val;
    int i;
    for (i = lag; i < size; ++i) {
        TI_REAL c = input[i];
        TI_REAL l = input[i-lag];
        val = ((c + (c-l))-val) * per + val;
        *output++ = val;
    }
    assert(output - outputs[0] == size - ti_zlema_start(options));
    return TI_OKAY;
}
ti_buffer *ti_buffer_new(int size) {
    const int s = (int)sizeof(ti_buffer) + (size-1) * (int)sizeof(TI_REAL);
    ti_buffer *ret = (ti_buffer*)malloc((unsigned int)s);
    ret->size = size;
    ret->pushes = 0;
    ret->index = 0;
    ret->sum = 0;
    return ret;
}
void ti_buffer_free(ti_buffer *buffer) {
    free(buffer);
}
const char* ti_version(void) {return TI_VERSION;}
long int ti_build(void) {return TI_BUILD;}
int ti_indicator_count(void) {return TI_INDICATOR_COUNT;}
struct ti_indicator_info ti_indicators[] = { {"abs", "Vector Absolute Value", ti_abs_start, ti_abs, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"abs",0}, 0, 0, 0}, {"acos", "Vector Arccosine", ti_acos_start, ti_acos, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"acos",0}, 0, 0, 0}, {"ad", "Accumulation/Distribution Line", ti_ad_start, ti_ad, 0, TI_TYPE_INDICATOR, 4, 0, 1, {"high","low","close","volume",0}, {"",0}, {"ad",0}, 0, 0, 0}, {"add", "Vector Addition", ti_add_start, ti_add, 0, TI_TYPE_SIMPLE, 2, 0, 1, {"value_one","value_two",0}, {"",0}, {"add",0}, 0, 0, 0}, {"adosc", "Accumulation/Distribution Oscillator", ti_adosc_start, ti_adosc, 0, TI_TYPE_INDICATOR, 4, 2, 1, {"high","low","close","volume",0}, {"short_period","long_period",0}, {"adosc",0}, 0, 0, 0}, {"adx", "Average Directional Movement Index", ti_adx_start, ti_adx, 0, TI_TYPE_INDICATOR, 2, 1, 1, {"high","low",0}, {"period[14]",0}, {"adx",0}, 0, 0, 0}, {"adxr", "Average Directional Movement Rating", ti_adxr_start, ti_adxr, 0, TI_TYPE_INDICATOR, 2, 1, 1, {"high","low",0}, {"period",0}, {"adxr",0}, 0, 0, 0}, {"andean_osc", "Andean Osc", ti_andean_osc_start, ti_andean_osc, 0, TI_TYPE_OVERLAY, 2, 2, 3, {"open","close",0}, {"period[50]","signal_length[9]",0}, {"?bull_data","?bear_data","ao_data",0}, 0, 0, 0}, {"ao", "Awesome Oscillator", ti_ao_start, ti_ao, 0, TI_TYPE_INDICATOR, 2, 0, 1, {"high","low",0}, {"",0}, {"ao",0}, 0, 0, 0}, {"apo", "Absolute Price Oscillator", ti_apo_start, ti_apo, 0, TI_TYPE_INDICATOR, 1, 2, 1, {"real",0}, {"short_period","long_period",0}, {"apo",0}, 0, 0, 0}, {"aroon", "Aroon", ti_aroon_start, ti_aroon, 0, TI_TYPE_INDICATOR, 2, 1, 2, {"high","low",0}, {"period",0}, {"aroon_down","aroon_up",0}, 0, 0, 0}, {"aroonosc", "Aroon Oscillator", ti_aroonosc_start, ti_aroonosc, 0, TI_TYPE_INDICATOR, 2, 1, 1, {"high","low",0}, {"period",0}, {"aroonosc",0}, 0, 0, 0}, {"asin", "Vector Arcsine", ti_asin_start, ti_asin, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"asin",0}, 0, 0, 0}, {"atan", "Vector Arctangent", ti_atan_start, ti_atan, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"atan",0}, 0, 0, 0}, {"atr", "Average True Range", ti_atr_start, ti_atr, ti_atr_ref, TI_TYPE_INDICATOR, 3, 1, 1, {"high","low","close",0}, {"period[14]",0}, {"atr",0}, ti_atr_stream_new, ti_atr_stream_run, ti_atr_stream_free}, {"avgprice", "Average Price", ti_avgprice_start, ti_avgprice, 0, TI_TYPE_OVERLAY, 4, 0, 1, {"open","high","low","close",0}, {"",0}, {"avgprice",0}, 0, 0, 0}, {"bbands", "Bollinger Bands", ti_bbands_start, ti_bbands, 0, TI_TYPE_OVERLAY, 1, 2, 3, {"real",0}, {"period[20]","stddev[2]",0}, {"bbands_lower(ohlcv)","bbands_middle(ohlcv)","bbands_upper(ohlcv)",0}, 0, 0, 0}, {"boom_pro", "Boom Pro", ti_boom_pro_start, ti_boom_pro, 0, TI_TYPE_OVERLAY, 1, 5, 2, {"close",0}, {"lp_period_one[6]","k1_quotient[0]","trig_no[2]","lp_period_two[27]","k22_eot[0.3]",0}, {"trigger(ohlc)","q4(ohlc)",0}, 0, 0, 0}, {"bop", "Balance of Power", ti_bop_start, ti_bop, 0, TI_TYPE_INDICATOR, 4, 0, 1, {"open","high","low","close",0}, {"",0}, {"bop",0}, 0, 0, 0}, {"braid_filter", "Braid Filter", ti_braid_filter_start, ti_braid_filter, 0, TI_TYPE_OVERLAY, 4, 4, 3, {"open","high","low","close",0}, {"ma01_length[3]","ma02_length[7]","ma03_length[14]","pips_min_sep_percent[40]",0}, {"?dif","?atr_filter","bar_color",0}, 0, 0, 0}, {"cci", "Commodity Channel Index", ti_cci_start, ti_cci, 0, TI_TYPE_INDICATOR, 3, 1, 1, {"high","low","close",0}, {"period[20]",0}, {"cci",0}, 0, 0, 0}, {"ceil", "Vector Ceiling", ti_ceil_start, ti_ceil, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"ceil",0}, 0, 0, 0}, {"chaikin_vol", "Chaikin Volatility", ti_chaikin_vol_start, ti_chaikin_vol, 0, TI_TYPE_OVERLAY, 2, 2, 1, {"high","low",0}, {"ema_period[7]","roc_period[14]",0}, {"cvi",0}, 0, 0, 0}, {"chandelier_exit", "Chandelier Exit", ti_chandelier_exit_start, ti_chandelier_exit, 0, TI_TYPE_OVERLAY, 3, 2, 1, {"high","low","close",0}, {"period[22]","atr_multiplier[3]",0}, {"buy_sell_signal",0}, 0, 0, 0}, {"cm_ema_trendbars", "CM EMA TRENDBARS", ti_cm_ema_trendbars_start, ti_cm_ema_trendbars, 0, TI_TYPE_OVERLAY, 3, 1, 2, {"high","low","close",0}, {"ema_length[34]",0}, {"?usdema(ohlc)","bar_color",0}, 0, 0, 0}, {"cmo", "Chande Momentum Oscillator", ti_cmo_start, ti_cmo, 0, TI_TYPE_INDICATOR, 1, 1, 1, {"real",0}, {"period",0}, {"cmo",0}, 0, 0, 0}, {"cos", "Vector Cosine", ti_cos_start, ti_cos, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"cos",0}, 0, 0, 0}, {"cosh", "Vector Hyperbolic Cosine", ti_cosh_start, ti_cosh, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"cosh",0}, 0, 0, 0}, {"crossany", "Crossany", ti_crossany_start, ti_crossany, 0, TI_TYPE_MATH, 2, 0, 1, {"value_one","value_two",0}, {"",0}, {"crossany",0}, 0, 0, 0}, {"crossover", "Crossover", ti_crossover_start, ti_crossover, 0, TI_TYPE_MATH, 2, 0, 1, {"value_one","value_two",0}, {"",0}, {"crossover",0}, 0, 0, 0}, {"cvi", "Chaikins Volatility", ti_cvi_start, ti_cvi, 0, TI_TYPE_INDICATOR, 2, 1, 1, {"high","low",0}, {"period",0}, {"cvi",0}, 0, 0, 0}, {"decay", "Linear Decay", ti_decay_start, ti_decay, 0, TI_TYPE_MATH, 1, 1, 1, {"real",0}, {"period",0}, {"decay",0}, 0, 0, 0}, {"dema", "Double Exponential Moving Average", ti_dema_start, ti_dema, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"real",0}, {"period[9]",0}, {"dema(ohlcv)",0}, 0, 0, 0}, {"di", "Directional Indicator", ti_di_start, ti_di, 0, TI_TYPE_INDICATOR, 3, 1, 2, {"high","low","close",0}, {"period",0}, {"plus_di","minus_di",0}, 0, 0, 0}, {"di_dx", "DI-DX", ti_di_dx_start, ti_di_dx, 0, TI_TYPE_INDICATOR, 3, 1, 3, {"high","low","close",0}, {"period[14]",0}, {"?dx","di_plus","di_minus",0}, 0, 0, 0}, {"div", "Vector Division", ti_div_start, ti_div, 0, TI_TYPE_SIMPLE, 2, 0, 1, {"value_one","value_two",0}, {"",0}, {"div",0}, 0, 0, 0}, {"dm", "Directional Movement", ti_dm_start, ti_dm, 0, TI_TYPE_INDICATOR, 2, 1, 2, {"high","low",0}, {"period",0}, {"plus_dm","minus_dm",0}, 0, 0, 0}, {"dpo", "Detrended Price Oscillator", ti_dpo_start, ti_dpo, 0, TI_TYPE_INDICATOR, 1, 1, 1, {"real",0}, {"period",0}, {"dpo",0}, 0, 0, 0}, {"dx", "Directional Movement Index", ti_dx_start, ti_dx, 0, TI_TYPE_INDICATOR, 2, 1, 1, {"high","low",0}, {"period[14]",0}, {"dx",0}, 0, 0, 0}, {"edecay", "Exponential Decay", ti_edecay_start, ti_edecay, 0, TI_TYPE_MATH, 1, 1, 1, {"real",0}, {"period",0}, {"edecay",0}, 0, 0, 0}, {"ema", "Exponential Moving Average", ti_ema_start, ti_ema, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"real",0}, {"period[9]",0}, {"ema(ohlcv)",0}, 0, 0, 0}, {"emv", "Ease of Movement", ti_emv_start, ti_emv, 0, TI_TYPE_INDICATOR, 3, 0, 1, {"high","low","volume",0}, {"",0}, {"emv",0}, 0, 0, 0}, {"exp", "Vector Exponential", ti_exp_start, ti_exp, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"exp",0}, 0, 0, 0}, {"floor", "Vector Floor", ti_floor_start, ti_floor, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"floor",0}, 0, 0, 0}, {"fosc", "Forecast Oscillator", ti_fosc_start, ti_fosc, 0, TI_TYPE_INDICATOR, 1, 1, 1, {"real",0}, {"period",0}, {"fosc",0}, 0, 0, 0}, {"ha", "Heikin-Ashi", ti_ha_start, ti_ha, 0, TI_TYPE_SIMPLE, 4, 0, 4, {"open","high","low","close",0}, {"",0}, {"ha_open","ha_high","ha_low","ha_close",0}, 0, 0, 0}, {"half_trend", "Half Trend", ti_half_trend_start, ti_half_trend, 0, TI_TYPE_OVERLAY, 3, 3, 2, {"high","low","close",0}, {"amplitude[2]","channel_deviation[2]","atr_length[100]",0}, {"?ht(ohlc)","bar_color",0}, 0, 0, 0}, {"heatmap_vol", "Heatmap Volume", ti_heatmap_vol_start, ti_heatmap_vol, 0, TI_TYPE_OVERLAY, 1, 6, 1, {"volume",0}, {"length[610]","std_length[610]","threshold_extra_high[4]","threshold_high[2.5]","threshold_medium[1]","threshold_normal[-0.5]",0}, {"heatmap_level",0}, 0, 0, 0}, {"hlc3", "HLC3", ti_hlc3_start, ti_hlc3, 0, TI_TYPE_MATH, 3, 0, 1, {"high","low","close",0}, {"",0}, {"hlc3_data",0}, 0, 0, 0}, {"hma", "Hull Moving Average", ti_hma_start, ti_hma, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"real",0}, {"period[9]",0}, {"hma(ohlcv)",0}, 0, 0, 0}, {"hull_suite", "Hull Suite", ti_hull_suite_start, ti_hull_suite, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"close",0}, {"hma_length[55]",0}, {"bar_color",0}, 0, 0, 0}, {"insidebar", "Inside Bar", ti_insidebar_start, ti_insidebar, 0, TI_TYPE_INDICATOR, 4, 0, 1, {"open","high","low","close",0}, {"",0}, {"buy_sell_signal",0}, 0, 0, 0}, {"kama", "Kaufman Adaptive Moving Average", ti_kama_start, ti_kama, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"real",0}, {"period",0}, {"kama",0}, 0, 0, 0}, {"kvo", "Klinger Volume Oscillator", ti_kvo_start, ti_kvo, 0, TI_TYPE_INDICATOR, 4, 2, 1, {"high","low","close","volume",0}, {"short_period","long_period",0}, {"kvo",0}, 0, 0, 0}, {"lag", "Lag", ti_lag_start, ti_lag, 0, TI_TYPE_MATH, 1, 1, 1, {"real",0}, {"period",0}, {"lag",0}, 0, 0, 0}, {"linreg", "Linear Regression", ti_linreg_start, ti_linreg, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"real",0}, {"period[100]",0}, {"linreg(ohlcv)",0}, 0, 0, 0}, {"linregintercept", "Linear Regression Intercept", ti_linregintercept_start, ti_linregintercept, 0, TI_TYPE_INDICATOR, 1, 1, 1, {"real",0}, {"period",0}, {"linregintercept",0}, 0, 0, 0}, {"linregslope", "Linear Regression Slope", ti_linregslope_start, ti_linregslope, 0, TI_TYPE_INDICATOR, 1, 1, 1, {"real",0}, {"period",0}, {"linregslope",0}, 0, 0, 0}, {"ln", "Vector Natural Log", ti_ln_start, ti_ln, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"ln",0}, 0, 0, 0}, {"log10", "Vector Base-10 Log", ti_log10_start, ti_log10, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"log10",0}, 0, 0, 0}, {"macd", "Moving Average Convergence/Divergence", ti_macd_start, ti_macd, 0, TI_TYPE_INDICATOR, 1, 3, 3, {"real",0}, {"short_period[12]","long_period[26]","signal_period[9]",0}, {"macd","macd_signal","?macd_histogram",0}, 0, 0, 0}, {"macd_fastline_divergence", "MACD Fastline Divergence", ti_macd_fastline_divergence_start, ti_macd_fastline_divergence, 0, TI_TYPE_OVERLAY, 3, 3, 2, {"high","low","close",0}, {"fast_length[12]","slow_length[26]","signal_length[9]",0}, {"bull","bear",0}, 0, 0, 0}, {"macd_hist_divergence", "MACD Hist Divergence", ti_macd_hist_divergence_start, ti_macd_hist_divergence, 0, TI_TYPE_OVERLAY, 3, 3, 2, {"high","low","close",0}, {"fast_length[12]","slow_length[26]","signal_length[9]",0}, {"bull","bear",0}, 0, 0, 0}, {"marketfi", "Market Facilitation Index", ti_marketfi_start, ti_marketfi, 0, TI_TYPE_INDICATOR, 3, 0, 1, {"high","low","volume",0}, {"",0}, {"marketfi",0}, 0, 0, 0}, {"mass", "Mass Index", ti_mass_start, ti_mass, 0, TI_TYPE_INDICATOR, 2, 1, 1, {"high","low",0}, {"period",0}, {"mass",0}, 0, 0, 0}, {"max", "Maximum In Period", ti_max_start, ti_max, ti_max_ref, TI_TYPE_MATH, 1, 1, 1, {"real",0}, {"period",0}, {"max",0}, 0, 0, 0}, {"md", "Mean Deviation Over Period", ti_md_start, ti_md, 0, TI_TYPE_MATH, 1, 1, 1, {"real",0}, {"period",0}, {"md",0}, 0, 0, 0}, {"medprice", "Median Price", ti_medprice_start, ti_medprice, 0, TI_TYPE_OVERLAY, 2, 0, 1, {"high","low",0}, {"",0}, {"medprice",0}, 0, 0, 0}, {"mfi", "Money Flow Index", ti_mfi_start, ti_mfi, 0, TI_TYPE_INDICATOR, 4, 1, 1, {"high","low","close","volume",0}, {"period[14]",0}, {"mfi",0}, 0, 0, 0}, {"min", "Minimum In Period", ti_min_start, ti_min, ti_min_ref, TI_TYPE_MATH, 1, 1, 1, {"real",0}, {"period",0}, {"min",0}, 0, 0, 0}, {"mobo_band", "Mobo Band", ti_mobo_band_start, ti_mobo_band, 0, TI_TYPE_OVERLAY, 2, 4, 1, {"high","low",0}, {"dpo_length[13]","mobo_length[10]","num_dev_down[-0.8]","num_dev_up[0.8]",0}, {"buy_sell_signal",0}, 0, 0, 0}, {"mom", "Momentum", ti_mom_start, ti_mom, 0, TI_TYPE_INDICATOR, 1, 1, 1, {"real",0}, {"period",0}, {"mom",0}, 0, 0, 0}, {"mul", "Vector Multiplication", ti_mul_start, ti_mul, 0, TI_TYPE_SIMPLE, 2, 0, 1, {"value_one","value_two",0}, {"",0}, {"mul",0}, 0, 0, 0}, {"natr", "Normalized Average True Range", ti_natr_start, ti_natr, 0, TI_TYPE_INDICATOR, 3, 1, 1, {"high","low","close",0}, {"period[14]",0}, {"natr",0}, 0, 0, 0}, {"price", "Compare Price", ti_price_start, ti_price, 0, TI_TYPE_INDICATOR, 1, 0, 1, {"value(ohlc)",0}, {"",0}, {"price",0}, 0, 0, 0}, {"psar", "PSAR", ti_psar_start, ti_psar, 0, TI_TYPE_INDICATOR, 3, 3, 1, {"high","low","close",0}, {"accel_start[0.02]","accel_step[0.02]","accel_max[0.2]",0}, {"psar(ohlc)",0}, 0, 0, 0}, {"qqe_mod", "QQE Mod", ti_qqe_mod_start, ti_qqe_mod, 0, TI_TYPE_OVERLAY, 1, 10, 2, {"close",0}, {"rsi_length_one[6]","rsi_smoothing_one[5]","qqe_factor_one[3]","threshold_one[3]","rsi_length_two[6]","rsi_smoothing_two[5]","qqe_factor_two[1.61]","threshold_two[3]","bollinger_length[50]","qqe_multiplier[0.35]",0}, {"bar_color_one","bar_color_two",0}, 0, 0, 0}, {"roc", "Rate of Change", ti_roc_start, ti_roc, 0, TI_TYPE_INDICATOR, 1, 1, 1, {"real",0}, {"period",0}, {"roc",0}, 0, 0, 0}, {"rocr", "Rate of Change Ratio", ti_rocr_start, ti_rocr, 0, TI_TYPE_INDICATOR, 1, 1, 1, {"real",0}, {"period",0}, {"rocr",0}, 0, 0, 0}, {"round", "Vector Round", ti_round_start, ti_round, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"round",0}, 0, 0, 0}, {"rsi", "Relative Strength Index", ti_rsi_start, ti_rsi, 0, TI_TYPE_INDICATOR, 1, 1, 1, {"real",0}, {"period[14]",0}, {"rsi",0}, 0, 0, 0}, {"rsi_divergence", "Relative Strength Index Divergence", ti_rsi_divergence_start, ti_rsi_divergence, 0, TI_TYPE_OVERLAY, 3, 3, 2, {"high","low","close",0}, {"left_bar[6]","right_bar[2]","rsi_length[14]",0}, {"bull","bear",0}, 0, 0, 0}, {"rvi", "Relative Volatility Index", ti_rvi_start, ti_rvi, 0, TI_TYPE_OVERLAY, 1, 2, 1, {"close",0}, {"std_length[10]","ema_length[14]",0}, {"rvi",0}, 0, 0, 0}, {"rvi_divergence", "Relative Volatility Index Divergence", ti_rvi_divergence_start, ti_rvi_divergence, 0, TI_TYPE_OVERLAY, 3, 4, 2, {"high","low","close",0}, {"left_bar[6]","right_bar[2]","std_length[12]","ema_length[14]",0}, {"bull","bear",0}, 0, 0, 0}, {"sin", "Vector Sine", ti_sin_start, ti_sin, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"sin",0}, 0, 0, 0}, {"sinh", "Vector Hyperbolic Sine", ti_sinh_start, ti_sinh, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"sinh",0}, 0, 0, 0}, {"sma", "Simple Moving Average", ti_sma_start, ti_sma, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"real",0}, {"period[7]",0}, {"sma(ohlcv)",0}, ti_sma_stream_new, ti_sma_stream_run, ti_sma_stream_free}, {"sqrt", "Vector Square Root", ti_sqrt_start, ti_sqrt, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"sqrt",0}, 0, 0, 0}, {"ssl", "SSL", ti_ssl_start, ti_ssl, 0, TI_TYPE_OVERLAY, 3, 2, 6, {"high","low","close",0}, {"ma_length[60]","ssl3_length[15]",0}, {"?bbmc(ohlc)","bar_color","?up_erk(ohlc)","?low_erk(ohlc)","?cross_long","?cross_short",0}, 0, 0, 0}, {"stc", "STC", ti_stc_start, ti_stc, 0, TI_TYPE_OVERLAY, 1, 4, 2, {"close",0}, {"length[12]","fast_length[26]","slow_length[50]","aaa[0.5]",0}, {"?stc","bar_color",0}, 0, 0, 0}, {"stddev", "Standard Deviation Over Period", ti_stddev_start, ti_stddev, 0, TI_TYPE_MATH, 1, 1, 1, {"real",0}, {"period",0}, {"stddev",0}, 0, 0, 0}, {"stderr", "Standard Error Over Period", ti_stderr_start, ti_stderr, 0, TI_TYPE_MATH, 1, 1, 1, {"real",0}, {"period",0}, {"stderr",0}, 0, 0, 0}, {"stoch", "Stochastic Oscillator", ti_stoch_start, ti_stoch, 0, TI_TYPE_INDICATOR, 3, 3, 2, {"high","low","close",0}, {"k_period[14]","k_slowing_period[1]","d_period[3]",0}, {"stoch_k","stoch_d",0}, 0, 0, 0}, {"stoch_divergence", "Stochastic Divergence", ti_stoch_divergence_start, ti_stoch_divergence, 0, TI_TYPE_OVERLAY, 3, 5, 2, {"high","low","close",0}, {"left_bar[6]","right_bar[2]","stk_length[14]","smooth_length[3]","sma_length[3]",0}, {"bull","bear",0}, 0, 0, 0}, {"stoch_rsi", "Stoch Rsi", ti_stoch_rsi_start, ti_stoch_rsi, 0, TI_TYPE_OVERLAY, 1, 4, 2, {"close",0}, {"smoothk[3]","smoothd[3]","rsi_period[14]","stoch_period[14]",0}, {"stoch_k","stoch_d",0}, 0, 0, 0}, {"stochrsi", "Stochastic RSI", ti_stochrsi_start, ti_stochrsi, 0, TI_TYPE_INDICATOR, 1, 1, 1, {"real",0}, {"period[14]",0}, {"stochrsi",0}, 0, 0, 0}, {"sub", "Vector Subtraction", ti_sub_start, ti_sub, 0, TI_TYPE_SIMPLE, 2, 0, 1, {"value_one","value_two",0}, {"",0}, {"sub",0}, 0, 0, 0}, {"sum", "Sum Over Period", ti_sum_start, ti_sum, 0, TI_TYPE_MATH, 1, 1, 1, {"real",0}, {"period",0}, {"sum",0}, 0, 0, 0}, {"sup_and_res", "Support and Resistance", ti_sup_and_res_start, ti_sup_and_res, 0, TI_TYPE_OVERLAY, 1, 4, 16, {"close",0}, {"left_bar[200]","right_bar_one[20]","right_bar_two[5]","hma_length[9]",0}, {"buy_one","buy_two","buy_three","buy_four","buy_five","buy_six","buy_seven","buy_eight","sell_one","sell_two","sell_three","sell_four","sell_five","sell_six","sell_seven","sell_eight",0}, 0, 0, 0}, {"supertrend", "Supertrend", ti_supertrend_start, ti_supertrend, 0, TI_TYPE_OVERLAY, 3, 2, 4, {"high","low","close",0}, {"period[34]","factor[3]",0}, {"?supertrend(ohlc)","?direction","bar_color","buy_sell_signal",0}, 0, 0, 0}, {"tan", "Vector Tangent", ti_tan_start, ti_tan, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"tan",0}, 0, 0, 0}, {"tanh", "Vector Hyperbolic Tangent", ti_tanh_start, ti_tanh, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"tanh",0}, 0, 0, 0}, {"tema", "Triple Exponential Moving Average", ti_tema_start, ti_tema, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"real",0}, {"period[9]",0}, {"tema(ohlcv)",0}, 0, 0, 0}, {"todeg", "Vector Degree Conversion", ti_todeg_start, ti_todeg, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"degrees",0}, 0, 0, 0}, {"torad", "Vector Radian Conversion", ti_torad_start, ti_torad, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"radians",0}, 0, 0, 0}, {"tr", "True Range", ti_tr_start, ti_tr, 0, TI_TYPE_INDICATOR, 3, 0, 1, {"high","low","close",0}, {"",0}, {"tr",0}, 0, 0, 0}, {"trima", "Triangular Moving Average", ti_trima_start, ti_trima, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"real",0}, {"period[20]",0}, {"trima(ohlcv)",0}, 0, 0, 0}, {"trix", "Trix", ti_trix_start, ti_trix, 0, TI_TYPE_INDICATOR, 1, 1, 1, {"real",0}, {"period",0}, {"trix",0}, 0, 0, 0}, {"trunc", "Vector Truncate", ti_trunc_start, ti_trunc, 0, TI_TYPE_SIMPLE, 1, 0, 1, {"real",0}, {"",0}, {"trunc",0}, 0, 0, 0}, {"tsf", "Time Series Forecast", ti_tsf_start, ti_tsf, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"real",0}, {"period",0}, {"tsf",0}, 0, 0, 0}, {"typprice", "Typical Price", ti_typprice_start, ti_typprice, 0, TI_TYPE_OVERLAY, 3, 0, 1, {"high","low","close",0}, {"",0}, {"typprice",0}, 0, 0, 0}, {"ultosc", "Ultimate Oscillator", ti_ultosc_start, ti_ultosc, 0, TI_TYPE_INDICATOR, 3, 3, 1, {"high","low","close",0}, {"short_period","medium_period","long_period",0}, {"ultosc",0}, 0, 0, 0}, {"unshift", "Unshift", ti_unshift_start, ti_unshift, 0, TI_TYPE_SIMPLE, 1, 2, 1, {"value",0}, {"default_value","length",0}, {"unshifted_value",0}, 0, 0, 0}, {"ut_bot", "UT Bot Alert", ti_ut_bot_start, ti_ut_bot, 0, TI_TYPE_OVERLAY, 3, 2, 1, {"high","low","close",0}, {"atr_period[10]","sensitivity[1]",0}, {"buy_sell_signal",0}, 0, 0, 0}, {"var", "Variance Over Period", ti_var_start, ti_var, 0, TI_TYPE_MATH, 1, 1, 1, {"real",0}, {"period",0}, {"var",0}, 0, 0, 0}, {"vhf", "Vertical Horizontal Filter", ti_vhf_start, ti_vhf, 0, TI_TYPE_INDICATOR, 1, 1, 1, {"real",0}, {"period",0}, {"vhf",0}, 0, 0, 0}, {"volatility", "Annualized Historical Volatility", ti_volatility_start, ti_volatility, 0, TI_TYPE_INDICATOR, 1, 1, 1, {"real",0}, {"period",0}, {"volatility",0}, 0, 0, 0}, {"volatility_oscillator", "Volatility Oscillator", ti_volatility_oscillator_start, ti_volatility_oscillator, 0, TI_TYPE_OVERLAY, 2, 1, 3, {"open","close",0}, {"length[100]",0}, {"spike_line","upper_line","lower_line",0}, 0, 0, 0}, {"vosc", "Volume Oscillator", ti_vosc_start, ti_vosc, 0, TI_TYPE_INDICATOR, 1, 2, 1, {"volume",0}, {"short_period","long_period",0}, {"vosc",0}, 0, 0, 0}, {"vu_man_chu_swing", "VU Man Chu Swing", ti_vu_man_chu_swing_start, ti_vu_man_chu_swing, 0, TI_TYPE_OVERLAY, 1, 2, 2, {"close",0}, {"swing_period[20]","swing_multiplier[3.5]",0}, {"buy_sell_signal_long","buy_sell_signal_short",0}, 0, 0, 0}, {"vwma", "Volume Weighted Moving Average", ti_vwma_start, ti_vwma, 0, TI_TYPE_OVERLAY, 2, 1, 1, {"close","volume",0}, {"period[20]",0}, {"vwma(v)",0}, 0, 0, 0}, {"wad", "Williams Accumulation/Distribution", ti_wad_start, ti_wad, 0, TI_TYPE_INDICATOR, 3, 0, 1, {"high","low","close",0}, {"",0}, {"wad",0}, 0, 0, 0}, {"waddah", "Waddah", ti_waddah_start, ti_waddah, 0, TI_TYPE_OVERLAY, 1, 6, 4, {"close",0}, {"fast_length[20]","slow_length[40]","signal_length[9]","bb_length[20]","multiplier[2]","sensitivity[150]",0}, {"?t","e","trend_up","trend_down",0}, 0, 0, 0}, {"wavetrend", "Wavetrend", ti_wavetrend_start, ti_wavetrend, 0, TI_TYPE_OVERLAY, 3, 2, 2, {"high","low","close",0}, {"period_one[9]","period_two[12]",0}, {"wavetrend_one","wavetrend_two",0}, 0, 0, 0}, {"wcprice", "Weighted Close Price", ti_wcprice_start, ti_wcprice, 0, TI_TYPE_OVERLAY, 3, 0, 1, {"high","low","close",0}, {"",0}, {"wcprice",0}, 0, 0, 0}, {"wilders", "Wilders Smoothing", ti_wilders_start, ti_wilders, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"real",0}, {"period",0}, {"wilders",0}, 0, 0, 0}, {"willr", "Williams %R", ti_willr_start, ti_willr, 0, TI_TYPE_INDICATOR, 3, 1, 1, {"high","low","close",0}, {"period",0}, {"willr",0}, 0, 0, 0}, {"wma", "Weighted Moving Average", ti_wma_start, ti_wma, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"real",0}, {"period[9]",0}, {"wma(ohlcv)",0}, 0, 0, 0}, {"zlema", "Zero-Lag Exponential Moving Average", ti_zlema_start, ti_zlema, 0, TI_TYPE_OVERLAY, 1, 1, 1, {"real",0}, {"period",0}, {"zlema(ohlcv)",0}, 0, 0, 0}, {0,0,0,0,0,0,0,0,0,{0,0},{0,0},{0,0},0,0,0}};
struct ti_stream {
    int index;
    int progress;
};
int ti_stream_run(ti_stream *stream, int size, TI_REAL const *const *inputs, TI_REAL *const *outputs) {
    return ti_indicators[stream->index].stream_run(stream, size, inputs, outputs);
}
ti_indicator_info *ti_stream_get_info(ti_stream *stream) {
    return ti_indicators + stream->index;
}
int ti_stream_get_progress(ti_stream *stream) {
    return stream->progress;
}
void ti_stream_free(ti_stream *stream) {
    ti_indicators[stream->index].stream_free(stream);
}
const ti_indicator_info *ti_find_indicator(const char *name) {
    int imin = 0;
    int imax = sizeof(ti_indicators) / sizeof(ti_indicator_info) - 2;
    while (imax >= imin) {
        const int i = (imin + ((imax-imin)/2));
        const int c = strcmp(name, ti_indicators[i].name);
        if (c == 0) {
            return ti_indicators + i;
        } else if (c > 0) {
            imin = i + 1;
        } else {
            imax = i - 1;
        }
    }
    return 0;
}
const char* tc_version(void) {return TC_VERSION;}
long int tc_build(void) {return TC_BUILD;}
int tc_candle_count(void) {return TC_CANDLE_COUNT;}
struct tc_result {
    int progress;
    int space;
    int count;
    int pattern_count;
    tc_hit *hits;
};
tc_config const *tc_config_default() {
    static tc_config default_config = {
        .period = 10,
        .body_none = 0.05,
        .body_short = 0.5,
        .body_long = 1.4,
        .wick_none = 0.05,
        .wick_long = 0.6,
        .near = 0.3
    };
    return &default_config;
}
tc_candle_info tc_candles[] = {
{"abandoned_baby_bear", "Abandoned Baby Bear", TC_ABANDONED_BABY_BEAR, tc_abandoned_baby_bear},
{"abandoned_baby_bull", "Abandoned Baby Bull", TC_ABANDONED_BABY_BULL, tc_abandoned_baby_bull},
{"big_black_candle", "Big Black Candle", TC_BIG_BLACK_CANDLE, tc_big_black_candle},
{"big_white_candle", "Big White Candle", TC_BIG_WHITE_CANDLE, tc_big_white_candle},
{"black_marubozu", "Black Marubozu", TC_BLACK_MARUBOZU, tc_black_marubozu},
{"doji", "Doji", TC_DOJI, tc_doji},
{"dragonfly_doji", "Dragonfly Doji", TC_DRAGONFLY_DOJI, tc_dragonfly_doji},
{"engulfing_bear", "Engulfing Bear", TC_ENGULFING_BEAR, tc_engulfing_bear},
{"engulfing_bull", "Engulfing Bull", TC_ENGULFING_BULL, tc_engulfing_bull},
{"evening_doji_star", "Evening Doji Star", TC_EVENING_DOJI_STAR, tc_evening_doji_star},
{"evening_star", "Evening Star", TC_EVENING_STAR, tc_evening_star},
{"four_price_doji", "Four Price Doji", TC_FOUR_PRICE_DOJI, tc_four_price_doji},
{"gravestone_doji", "Gravestone Doji", TC_GRAVESTONE_DOJI, tc_gravestone_doji},
{"hammer", "Hammer", TC_HAMMER, tc_hammer},
{"hanging_man", "Hanging Man", TC_HANGING_MAN, tc_hanging_man},
{"inverted_hammer", "Inverted Hammer", TC_INVERTED_HAMMER, tc_inverted_hammer},
{"long_legged_doji", "Long Legged Doji", TC_LONG_LEGGED_DOJI, tc_long_legged_doji},
{"marubozu", "Marubozu", TC_MARUBOZU, tc_marubozu},
{"morning_doji_star", "Morning Doji Star", TC_MORNING_DOJI_STAR, tc_morning_doji_star},
{"morning_star", "Morning Star", TC_MORNING_STAR, tc_morning_star},
{"shooting_star", "Shooting Star", TC_SHOOTING_STAR, tc_shooting_star},
{"spinning_top", "Spinning Top", TC_SPINNING_TOP, tc_spinning_top},
{"star", "Star", TC_STAR, tc_star},
{"three_black_crows", "Three Black Crows", TC_THREE_BLACK_CROWS, tc_three_black_crows},
{"three_white_soldiers", "Three White Soldiers", TC_THREE_WHITE_SOLDIERS, tc_three_white_soldiers},
{"white_marubozu", "White Marubozu", TC_WHITE_MARUBOZU, tc_white_marubozu},
{0,0,0,0}
};
const tc_candle_info *tc_find_candle(const char *name) {
    int imin = 0;
    int imax = sizeof(tc_candles) / sizeof(tc_candle_info) - 2;
    while (imax >= imin) {
        const int i = (imin + ((imax-imin)/2));
        const int c = strcmp(name, tc_candles[i].name);
        if (c == 0) {
            return tc_candles + i;
        } else if (c > 0) {
            imin = i + 1;
        } else {
            imax = i - 1;
        }
    }
    return 0;
}
const tc_candle_info *tc_get_info(tc_set pattern) {
    if (!pattern) return 0;
    tc_set k = pattern & ~(pattern-1);
    int imin = 0;
    int imax = sizeof(tc_candles) / sizeof(tc_candle_info) - 2;
    while (imax >= imin) {
        const int i = (imin + ((imax-imin)/2));
        if (k == tc_candles[i].pattern) {
            return tc_candles + i;
        } else if (k > tc_candles[i].pattern) {
            imin = i + 1;
        } else {
            imax = i - 1;
        }
    }
    return 0;
}
void tc_config_set_to_default(tc_config *config) {
    memcpy(config, tc_config_default(), sizeof(tc_config));
}
tc_result *tc_result_new() {
    tc_result *k = malloc(sizeof(tc_result));
    if (!k) return 0;
    memset(k, 0, sizeof(tc_result));
    return k;
}
static void tc_result_reset(tc_result *result) {
    result->progress = 0;
    result->count = 0;
    result->pattern_count = 0;
}
void tc_result_free(tc_result *result) {
    if (!result) return;
    free(result->hits);
    free(result);
}
int tc_result_count(const tc_result *result) {
    return result->count;
}
int tc_result_pattern_count(const tc_result *result) {
    return result->pattern_count;
}
tc_hit tc_result_get(const tc_result *result, int index) {
    if (index < result->count) {
        return result->hits[index];
    }
    tc_hit hit = {0};
    return hit;
}
tc_set tc_result_at(const tc_result *result, int index) {
    int imin = 0;
    int imax = result->count - 1;
    if (!imax) return 0;
    while (imax >= imin) {
        const int i = (imin + ((imax-imin)/2));
        assert(i >= 0);
        assert(i < result->count);
        if (index == result->hits[i].index) {
            return result->hits[i].patterns;
        } else if (index > result->hits[i].index) {
            imin = i + 1;
        } else {
            imax = i - 1;
        }
    }
    return 0;
}
static int tc_result_add(tc_result *result, tc_hit hit) {
    ++result->pattern_count;
    if (result->count > 0) {
        if (result->hits[result->count-1].index == hit.index) {
            TC_SET_ADD(result->hits[result->count-1].patterns, hit.patterns);
            return TC_OKAY;
        }
    }
    if (result->space == 0) {
        result->space = 2048;
        result->count = 0;
        result->hits = malloc(sizeof(tc_hit) * (unsigned int)result->space);
    } else if (result->space == result->count) {
        result->space *= 2;
        tc_hit *hits = realloc(result->hits, sizeof(tc_hit) * (unsigned int)result->space);
        if (!hits) {
            return TC_OUT_OF_MEMORY;
        }
        result->hits = hits;
    }
    result->hits[result->count] = hit;
    ++result->count;
    return TC_OKAY;
}
int tc_run(tc_set patterns, int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output) {
    tc_result_reset(output);
    {
        if ((patterns & (patterns-1)) == 0) {
if (patterns == TC_ABANDONED_BABY_BEAR) return tc_abandoned_baby_bear(size, inputs, options, output);
if (patterns == TC_ABANDONED_BABY_BULL) return tc_abandoned_baby_bull(size, inputs, options, output);
if (patterns == TC_BIG_BLACK_CANDLE) return tc_big_black_candle(size, inputs, options, output);
if (patterns == TC_BIG_WHITE_CANDLE) return tc_big_white_candle(size, inputs, options, output);
if (patterns == TC_BLACK_MARUBOZU) return tc_black_marubozu(size, inputs, options, output);
if (patterns == TC_DOJI) return tc_doji(size, inputs, options, output);
if (patterns == TC_DRAGONFLY_DOJI) return tc_dragonfly_doji(size, inputs, options, output);
if (patterns == TC_ENGULFING_BEAR) return tc_engulfing_bear(size, inputs, options, output);
if (patterns == TC_ENGULFING_BULL) return tc_engulfing_bull(size, inputs, options, output);
if (patterns == TC_EVENING_DOJI_STAR) return tc_evening_doji_star(size, inputs, options, output);
if (patterns == TC_EVENING_STAR) return tc_evening_star(size, inputs, options, output);
if (patterns == TC_FOUR_PRICE_DOJI) return tc_four_price_doji(size, inputs, options, output);
if (patterns == TC_GRAVESTONE_DOJI) return tc_gravestone_doji(size, inputs, options, output);
if (patterns == TC_HAMMER) return tc_hammer(size, inputs, options, output);
if (patterns == TC_HANGING_MAN) return tc_hanging_man(size, inputs, options, output);
if (patterns == TC_INVERTED_HAMMER) return tc_inverted_hammer(size, inputs, options, output);
if (patterns == TC_LONG_LEGGED_DOJI) return tc_long_legged_doji(size, inputs, options, output);
if (patterns == TC_MARUBOZU) return tc_marubozu(size, inputs, options, output);
if (patterns == TC_MORNING_DOJI_STAR) return tc_morning_doji_star(size, inputs, options, output);
if (patterns == TC_MORNING_STAR) return tc_morning_star(size, inputs, options, output);
if (patterns == TC_SHOOTING_STAR) return tc_shooting_star(size, inputs, options, output);
if (patterns == TC_SPINNING_TOP) return tc_spinning_top(size, inputs, options, output);
if (patterns == TC_STAR) return tc_star(size, inputs, options, output);
if (patterns == TC_THREE_BLACK_CROWS) return tc_three_black_crows(size, inputs, options, output);
if (patterns == TC_THREE_WHITE_SOLDIERS) return tc_three_white_soldiers(size, inputs, options, output);
if (patterns == TC_WHITE_MARUBOZU) return tc_white_marubozu(size, inputs, options, output);
        }
    }
    const TC_REAL *open = inputs[0]; const TC_REAL *high = inputs[1]; const TC_REAL *low = inputs[2]; const TC_REAL *close = inputs[3]; const int period = options->period; const TC_REAL div = 1.0 / period; TC_REAL avg_body_sum = 0; TC_REAL avg_total_sum = 0; if (period < 1) return TC_INVALID_OPTION; if (size < period) return TC_OKAY; int i; for (i = 0; i < period; ++i) { avg_body_sum += (fabs(open[(i)] - close[(i)])); avg_total_sum += (high[(i)] - low[(i)]); }
    while(i < size) { const TC_REAL top = (open[(i)] > close[(i)] ? open[(i)] : close[(i)]); const TC_REAL bottom = (open[(i)] < close[(i)] ? open[(i)] : close[(i)]); const TC_REAL body = (fabs(open[(i)] - close[(i)])); const TC_REAL total = (high[(i)] - low[(i)]); const TC_REAL upper = (high[(i)] - top); const TC_REAL lower = (bottom - low[(i)]); const TC_REAL avg_body = avg_body_sum * div; const TC_REAL avg_total = avg_total_sum * div; (void)top;(void)bottom;(void)body;(void)total; (void)upper;(void)lower;(void)avg_body;(void)avg_total; if ((TC_ABANDONED_BABY_BEAR & patterns) && i>=2 && (open[i-2]<close[i-2]) && ((fabs(open[(i-2)] - close[(i-2)])) > (options->body_long * avg_body)) && (low[i-1] >= high[(i-1)-1]) && ((fabs(open[(i-1)] - close[(i-1)])) < (options->body_none * avg_total)) && (open[i]>close[i]) && (high[i] <= low[(i)-1]) && (close[i] <= close[i-2])) { do { const tc_hit hit = {i, TC_ABANDONED_BABY_BEAR}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } if ((TC_ABANDONED_BABY_BULL & patterns) && i>=2 && (open[i-2]>close[i-2]) && ((fabs(open[(i-2)] - close[(i-2)])) > (options->body_long * avg_body)) && (high[i-1] <= low[(i-1)-1]) && ((fabs(open[(i-1)] - close[(i-1)])) < (options->body_none * avg_total)) && (open[i]<close[i]) && (low[i] >= high[(i)-1]) && (close[i] >= close[i-2])) { do { const tc_hit hit = {i, TC_ABANDONED_BABY_BULL}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } if ((TC_BIG_BLACK_CANDLE & patterns) && (open[i]>close[i]) && ((fabs(open[(i)] - close[(i)])) > (options->body_long * avg_body))) { do { const tc_hit hit = {i, TC_BIG_BLACK_CANDLE}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } if ((TC_BIG_WHITE_CANDLE & patterns) && (open[i]<close[i]) && ((fabs(open[(i)] - close[(i)])) > (options->body_long * avg_body))) { do { const tc_hit hit = {i, TC_BIG_WHITE_CANDLE}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } if ((TC_BLACK_MARUBOZU & patterns) && ((fabs(open[(i)] - close[(i)])) > (options->body_long * avg_body)) && ((high[(i)] - top) < (options->wick_none * avg_total)) && ((bottom - low[(i)]) < (options->wick_none * avg_total)) && (open[i]>close[i])) { do { const tc_hit hit = {i, TC_BLACK_MARUBOZU}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } if ((TC_DOJI & patterns) && ((fabs(open[(i)] - close[(i)])) < (options->body_none * avg_total))) { do { const tc_hit hit = {i, TC_DOJI}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } if ((TC_DRAGONFLY_DOJI & patterns) && ((fabs(open[(i)] - close[(i)])) < (options->body_none * avg_total)) && ((high[(i)] - top) < (options->wick_none * avg_total)) && ((bottom - low[(i)]) > (options->wick_long * avg_body))) { do { const tc_hit hit = {i, TC_DRAGONFLY_DOJI}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } if ((TC_ENGULFING_BEAR & patterns) && i>=1 && (open[i]>close[i]) && (open[i-1]<close[i-1]) && close[i] < open[i-1] && open[i] > close[i-1]) { do { const tc_hit hit = {i, TC_ENGULFING_BEAR}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } if ((TC_ENGULFING_BULL & patterns) && i>=1 && (open[i]<close[i]) && (open[i-1]>close[i-1]) && close[i] > open[i-1] && open[i] < close[i-1]) { do { const tc_hit hit = {i, TC_ENGULFING_BULL}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } if ((TC_EVENING_DOJI_STAR & patterns) && i>=2 && (open[i-2]<close[i-2]) && ((fabs(open[(i-2)] - close[(i-2)])) > (options->body_long * avg_body)) && ((open[(i-1)] < close[(i-1)] ? open[(i-1)] : close[(i-1)]) >= (open[((i-1)-1)] > close[((i-1)-1)] ? open[((i-1)-1)] : close[((i-1)-1)])) && ((fabs(open[(i-1)] - close[(i-1)])) < (options->body_none * avg_total)) && (open[i]>close[i]) && ((open[(i)] > close[(i)] ? open[(i)] : close[(i)]) <= (open[((i)-1)] < close[((i)-1)] ? open[((i)-1)] : close[((i)-1)])) && (close[i] <= close[i-2])) { do { const tc_hit hit = {i, TC_EVENING_DOJI_STAR}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } if ((TC_EVENING_STAR & patterns) && i>=2 && (open[i-2]<close[i-2]) && ((fabs(open[(i-2)] - close[(i-2)])) > (options->body_long * avg_body)) && ((open[(i-1)] < close[(i-1)] ? open[(i-1)] : close[(i-1)]) >= (open[((i-1)-1)] > close[((i-1)-1)] ? open[((i-1)-1)] : close[((i-1)-1)])) && ((fabs(open[(i-1)] - close[(i-1)])) < (options->body_short * avg_body)) && (open[i]>close[i]) && ((open[(i)] > close[(i)] ? open[(i)] : close[(i)]) <= (open[((i)-1)] < close[((i)-1)] ? open[((i)-1)] : close[((i)-1)])) && (close[i] <= close[i-2])) { do { const tc_hit hit = {i, TC_EVENING_STAR}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } if ((TC_FOUR_PRICE_DOJI & patterns) && ((fabs(open[(i)] - close[(i)])) < (options->body_none * avg_total)) && ((high[(i)] - top) < (options->wick_none * avg_total)) && ((bottom - low[(i)]) < (options->wick_none * avg_total))) { do { const tc_hit hit = {i, TC_FOUR_PRICE_DOJI}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } if ((TC_GRAVESTONE_DOJI & patterns) && ((fabs(open[(i)] - close[(i)])) < (options->body_none * avg_total)) && ((high[(i)] - top) > (options->wick_long * avg_body)) && ((bottom - low[(i)]) < (options->wick_none * avg_total))) { do { const tc_hit hit = {i, TC_GRAVESTONE_DOJI}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } if ((TC_HAMMER & patterns) && i>=1 && ((fabs(open[(i)] - close[(i)])) < (options->body_short * avg_body)) && ((high[(i)] - top) < (options->wick_none * avg_total)) && ((bottom - low[(i)]) > (options->wick_long * avg_body)) && (open[(i)] < close[(i)] ? open[(i)] : close[(i)]) <= low[i-1] + (options->near * avg_total)) { do { const tc_hit hit = {i, TC_HAMMER}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } if ((TC_HANGING_MAN & patterns) && i>=1 && ((fabs(open[(i)] - close[(i)])) < (options->body_short * avg_body)) && ((high[(i)] - top) < (options->wick_none * avg_total)) && ((bottom - low[(i)]) > (options->wick_long * avg_body)) && (open[(i)] < close[(i)] ? open[(i)] : close[(i)]) >= high[i-1] - (options->near * avg_total)) { do { const tc_hit hit = {i, TC_HANGING_MAN}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } if ((TC_INVERTED_HAMMER & patterns) && i>=1 && ((fabs(open[(i)] - close[(i)])) < (options->body_short * avg_body)) && ((high[(i)] - top) > (options->wick_long * avg_body)) && ((bottom - low[(i)]) < (options->wick_none * avg_total)) && ((open[(i)] > close[(i)] ? open[(i)] : close[(i)]) <= (open[((i)-1)] < close[((i)-1)] ? open[((i)-1)] : close[((i)-1)]))) { do { const tc_hit hit = {i, TC_INVERTED_HAMMER}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } if ((TC_LONG_LEGGED_DOJI & patterns) && ((fabs(open[(i)] - close[(i)])) < (options->body_none * avg_total)) && ((high[(i)] - top) > (options->wick_long * avg_body)) && ((bottom - low[(i)]) > (options->wick_long * avg_body))) { do { const tc_hit hit = {i, TC_LONG_LEGGED_DOJI}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } if ((TC_MARUBOZU & patterns) && ((fabs(open[(i)] - close[(i)])) > (options->body_long * avg_body)) && ((high[(i)] - top) < (options->wick_none * avg_total)) && ((bottom - low[(i)]) < (options->wick_none * avg_total))) { do { const tc_hit hit = {i, TC_MARUBOZU}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } if ((TC_MORNING_DOJI_STAR & patterns) && i>=2 && (open[i-2]>close[i-2]) && ((fabs(open[(i-2)] - close[(i-2)])) > (options->body_long * avg_body)) && ((open[(i-1)] > close[(i-1)] ? open[(i-1)] : close[(i-1)]) <= (open[((i-1)-1)] < close[((i-1)-1)] ? open[((i-1)-1)] : close[((i-1)-1)])) && ((fabs(open[(i-1)] - close[(i-1)])) < (options->body_none * avg_total)) && (open[i]<close[i]) && ((open[(i)] < close[(i)] ? open[(i)] : close[(i)]) >= (open[((i)-1)] > close[((i)-1)] ? open[((i)-1)] : close[((i)-1)])) && (close[i] >= close[i-2])) { do { const tc_hit hit = {i, TC_MORNING_DOJI_STAR}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } if ((TC_MORNING_STAR & patterns) && i>=2 && (open[i-2]>close[i-2]) && ((fabs(open[(i-2)] - close[(i-2)])) > (options->body_long * avg_body)) && ((open[(i-1)] > close[(i-1)] ? open[(i-1)] : close[(i-1)]) <= (open[((i-1)-1)] < close[((i-1)-1)] ? open[((i-1)-1)] : close[((i-1)-1)])) && ((fabs(open[(i-1)] - close[(i-1)])) < (options->body_short * avg_body)) && (open[i]<close[i]) && ((open[(i)] < close[(i)] ? open[(i)] : close[(i)]) >= (open[((i)-1)] > close[((i)-1)] ? open[((i)-1)] : close[((i)-1)])) && (close[i] >= close[i-2])) { do { const tc_hit hit = {i, TC_MORNING_STAR}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } if ((TC_SHOOTING_STAR & patterns) && i>=1 && ((fabs(open[(i)] - close[(i)])) < (options->body_short * avg_body)) && ((high[(i)] - top) > (options->wick_long * avg_body)) && ((bottom - low[(i)]) < (options->wick_none * avg_total)) && ((open[(i)] < close[(i)] ? open[(i)] : close[(i)]) >= (open[((i)-1)] > close[((i)-1)] ? open[((i)-1)] : close[((i)-1)]))) { do { const tc_hit hit = {i, TC_SHOOTING_STAR}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } if ((TC_SPINNING_TOP & patterns) && ((fabs(open[(i)] - close[(i)])) < (options->body_short * avg_body)) && ((high[(i)] - top) > (fabs(open[(i)] - close[(i)]))) && ((bottom - low[(i)]) > (fabs(open[(i)] - close[(i)])))) { do { const tc_hit hit = {i, TC_SPINNING_TOP}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } if ((TC_STAR & patterns) && i>=1 && ((low[i] >= high[(i)-1]) || (high[i] <= low[(i)-1]))) { do { const tc_hit hit = {i, TC_STAR}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } if ((TC_THREE_BLACK_CROWS & patterns) && i>=2 && (open[i-2]>close[i-2]) && (open[i-1]>close[i-1]) && (open[i]>close[i]) && (open[i-1] < (open[((i-1)-1)] > close[((i-1)-1)] ? open[((i-1)-1)] : close[((i-1)-1)]) && open[i-1] > (open[((i-1)-1)] < close[((i-1)-1)] ? open[((i-1)-1)] : close[((i-1)-1)])) && (open[i] < (open[((i)-1)] > close[((i)-1)] ? open[((i)-1)] : close[((i)-1)]) && open[i] > (open[((i)-1)] < close[((i)-1)] ? open[((i)-1)] : close[((i)-1)]))) { do { const tc_hit hit = {i, TC_THREE_BLACK_CROWS}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } if ((TC_THREE_WHITE_SOLDIERS & patterns) && i>=2 && (open[i-2]<close[i-2]) && (open[i-1]<close[i-1]) && (open[i]<close[i]) && (open[i-1] < (open[((i-1)-1)] > close[((i-1)-1)] ? open[((i-1)-1)] : close[((i-1)-1)]) && open[i-1] > (open[((i-1)-1)] < close[((i-1)-1)] ? open[((i-1)-1)] : close[((i-1)-1)])) && (open[i] < (open[((i)-1)] > close[((i)-1)] ? open[((i)-1)] : close[((i)-1)]) && open[i] > (open[((i)-1)] < close[((i)-1)] ? open[((i)-1)] : close[((i)-1)]))) { do { const tc_hit hit = {i, TC_THREE_WHITE_SOLDIERS}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } if ((TC_WHITE_MARUBOZU & patterns) && ((fabs(open[(i)] - close[(i)])) > (options->body_long * avg_body)) && ((high[(i)] - top) < (options->wick_none * avg_total)) && ((bottom - low[(i)]) < (options->wick_none * avg_total)) && (open[i]<close[i])) { do { const tc_hit hit = {i, TC_WHITE_MARUBOZU}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } avg_body_sum += body; avg_body_sum -= (fabs(open[(i-period)] - close[(i-period)])); avg_total_sum += total; avg_total_sum -= (high[(i-period)] - low[(i-period)]); ++i; };
    return TC_OKAY;
}
int tc_abandoned_baby_bear(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output) {
        const TC_REAL *open = inputs[0]; const TC_REAL *high = inputs[1]; const TC_REAL *low = inputs[2]; const TC_REAL *close = inputs[3]; const int period = options->period; const TC_REAL div = 1.0 / period; TC_REAL avg_body_sum = 0; TC_REAL avg_total_sum = 0; if (period < 1) return TC_INVALID_OPTION; if (size < period) return TC_OKAY; int i; for (i = 0; i < period; ++i) { avg_body_sum += (fabs(open[(i)] - close[(i)])); avg_total_sum += (high[(i)] - low[(i)]); }
        while(i < size) { const TC_REAL top = (open[(i)] > close[(i)] ? open[(i)] : close[(i)]); const TC_REAL bottom = (open[(i)] < close[(i)] ? open[(i)] : close[(i)]); const TC_REAL body = (fabs(open[(i)] - close[(i)])); const TC_REAL total = (high[(i)] - low[(i)]); const TC_REAL upper = (high[(i)] - top); const TC_REAL lower = (bottom - low[(i)]); const TC_REAL avg_body = avg_body_sum * div; const TC_REAL avg_total = avg_total_sum * div; (void)top;(void)bottom;(void)body;(void)total; (void)upper;(void)lower;(void)avg_body;(void)avg_total; if (i>=2 && (open[i-2]<close[i-2]) && ((fabs(open[(i-2)] - close[(i-2)])) > (options->body_long * avg_body)) && (low[i-1] >= high[(i-1)-1]) && ((fabs(open[(i-1)] - close[(i-1)])) < (options->body_none * avg_total)) && (open[i]>close[i]) && (high[i] <= low[(i)-1]) && (close[i] <= close[i-2])) { do { const tc_hit hit = {i, TC_ABANDONED_BABY_BEAR}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } avg_body_sum += body; avg_body_sum -= (fabs(open[(i-period)] - close[(i-period)])); avg_total_sum += total; avg_total_sum -= (high[(i-period)] - low[(i-period)]); ++i; };
        return TC_OKAY;
    }
int tc_abandoned_baby_bull(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output) {
        const TC_REAL *open = inputs[0]; const TC_REAL *high = inputs[1]; const TC_REAL *low = inputs[2]; const TC_REAL *close = inputs[3]; const int period = options->period; const TC_REAL div = 1.0 / period; TC_REAL avg_body_sum = 0; TC_REAL avg_total_sum = 0; if (period < 1) return TC_INVALID_OPTION; if (size < period) return TC_OKAY; int i; for (i = 0; i < period; ++i) { avg_body_sum += (fabs(open[(i)] - close[(i)])); avg_total_sum += (high[(i)] - low[(i)]); }
        while(i < size) { const TC_REAL top = (open[(i)] > close[(i)] ? open[(i)] : close[(i)]); const TC_REAL bottom = (open[(i)] < close[(i)] ? open[(i)] : close[(i)]); const TC_REAL body = (fabs(open[(i)] - close[(i)])); const TC_REAL total = (high[(i)] - low[(i)]); const TC_REAL upper = (high[(i)] - top); const TC_REAL lower = (bottom - low[(i)]); const TC_REAL avg_body = avg_body_sum * div; const TC_REAL avg_total = avg_total_sum * div; (void)top;(void)bottom;(void)body;(void)total; (void)upper;(void)lower;(void)avg_body;(void)avg_total; if (i>=2 && (open[i-2]>close[i-2]) && ((fabs(open[(i-2)] - close[(i-2)])) > (options->body_long * avg_body)) && (high[i-1] <= low[(i-1)-1]) && ((fabs(open[(i-1)] - close[(i-1)])) < (options->body_none * avg_total)) && (open[i]<close[i]) && (low[i] >= high[(i)-1]) && (close[i] >= close[i-2])) { do { const tc_hit hit = {i, TC_ABANDONED_BABY_BULL}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } avg_body_sum += body; avg_body_sum -= (fabs(open[(i-period)] - close[(i-period)])); avg_total_sum += total; avg_total_sum -= (high[(i-period)] - low[(i-period)]); ++i; };
        return TC_OKAY;
    }
int tc_big_black_candle(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output) {
        const TC_REAL *open = inputs[0]; const TC_REAL *high = inputs[1]; const TC_REAL *low = inputs[2]; const TC_REAL *close = inputs[3]; const int period = options->period; const TC_REAL div = 1.0 / period; TC_REAL avg_body_sum = 0; TC_REAL avg_total_sum = 0; if (period < 1) return TC_INVALID_OPTION; if (size < period) return TC_OKAY; int i; for (i = 0; i < period; ++i) { avg_body_sum += (fabs(open[(i)] - close[(i)])); avg_total_sum += (high[(i)] - low[(i)]); }
        while(i < size) { const TC_REAL top = (open[(i)] > close[(i)] ? open[(i)] : close[(i)]); const TC_REAL bottom = (open[(i)] < close[(i)] ? open[(i)] : close[(i)]); const TC_REAL body = (fabs(open[(i)] - close[(i)])); const TC_REAL total = (high[(i)] - low[(i)]); const TC_REAL upper = (high[(i)] - top); const TC_REAL lower = (bottom - low[(i)]); const TC_REAL avg_body = avg_body_sum * div; const TC_REAL avg_total = avg_total_sum * div; (void)top;(void)bottom;(void)body;(void)total; (void)upper;(void)lower;(void)avg_body;(void)avg_total; if ((open[i]>close[i]) && ((fabs(open[(i)] - close[(i)])) > (options->body_long * avg_body))) { do { const tc_hit hit = {i, TC_BIG_BLACK_CANDLE}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } avg_body_sum += body; avg_body_sum -= (fabs(open[(i-period)] - close[(i-period)])); avg_total_sum += total; avg_total_sum -= (high[(i-period)] - low[(i-period)]); ++i; };
        return TC_OKAY;
    }
int tc_big_white_candle(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output) {
        const TC_REAL *open = inputs[0]; const TC_REAL *high = inputs[1]; const TC_REAL *low = inputs[2]; const TC_REAL *close = inputs[3]; const int period = options->period; const TC_REAL div = 1.0 / period; TC_REAL avg_body_sum = 0; TC_REAL avg_total_sum = 0; if (period < 1) return TC_INVALID_OPTION; if (size < period) return TC_OKAY; int i; for (i = 0; i < period; ++i) { avg_body_sum += (fabs(open[(i)] - close[(i)])); avg_total_sum += (high[(i)] - low[(i)]); }
        while(i < size) { const TC_REAL top = (open[(i)] > close[(i)] ? open[(i)] : close[(i)]); const TC_REAL bottom = (open[(i)] < close[(i)] ? open[(i)] : close[(i)]); const TC_REAL body = (fabs(open[(i)] - close[(i)])); const TC_REAL total = (high[(i)] - low[(i)]); const TC_REAL upper = (high[(i)] - top); const TC_REAL lower = (bottom - low[(i)]); const TC_REAL avg_body = avg_body_sum * div; const TC_REAL avg_total = avg_total_sum * div; (void)top;(void)bottom;(void)body;(void)total; (void)upper;(void)lower;(void)avg_body;(void)avg_total; if ((open[i]<close[i]) && ((fabs(open[(i)] - close[(i)])) > (options->body_long * avg_body))) { do { const tc_hit hit = {i, TC_BIG_WHITE_CANDLE}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } avg_body_sum += body; avg_body_sum -= (fabs(open[(i-period)] - close[(i-period)])); avg_total_sum += total; avg_total_sum -= (high[(i-period)] - low[(i-period)]); ++i; };
        return TC_OKAY;
    }
int tc_black_marubozu(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output) {
        const TC_REAL *open = inputs[0]; const TC_REAL *high = inputs[1]; const TC_REAL *low = inputs[2]; const TC_REAL *close = inputs[3]; const int period = options->period; const TC_REAL div = 1.0 / period; TC_REAL avg_body_sum = 0; TC_REAL avg_total_sum = 0; if (period < 1) return TC_INVALID_OPTION; if (size < period) return TC_OKAY; int i; for (i = 0; i < period; ++i) { avg_body_sum += (fabs(open[(i)] - close[(i)])); avg_total_sum += (high[(i)] - low[(i)]); }
        while(i < size) { const TC_REAL top = (open[(i)] > close[(i)] ? open[(i)] : close[(i)]); const TC_REAL bottom = (open[(i)] < close[(i)] ? open[(i)] : close[(i)]); const TC_REAL body = (fabs(open[(i)] - close[(i)])); const TC_REAL total = (high[(i)] - low[(i)]); const TC_REAL upper = (high[(i)] - top); const TC_REAL lower = (bottom - low[(i)]); const TC_REAL avg_body = avg_body_sum * div; const TC_REAL avg_total = avg_total_sum * div; (void)top;(void)bottom;(void)body;(void)total; (void)upper;(void)lower;(void)avg_body;(void)avg_total; if (((fabs(open[(i)] - close[(i)])) > (options->body_long * avg_body)) && ((high[(i)] - top) < (options->wick_none * avg_total)) && ((bottom - low[(i)]) < (options->wick_none * avg_total)) && (open[i]>close[i])) { do { const tc_hit hit = {i, TC_BLACK_MARUBOZU}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } avg_body_sum += body; avg_body_sum -= (fabs(open[(i-period)] - close[(i-period)])); avg_total_sum += total; avg_total_sum -= (high[(i-period)] - low[(i-period)]); ++i; };
        return TC_OKAY;
    }
int tc_doji(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output) {
        const TC_REAL *open = inputs[0]; const TC_REAL *high = inputs[1]; const TC_REAL *low = inputs[2]; const TC_REAL *close = inputs[3]; const int period = options->period; const TC_REAL div = 1.0 / period; TC_REAL avg_body_sum = 0; TC_REAL avg_total_sum = 0; if (period < 1) return TC_INVALID_OPTION; if (size < period) return TC_OKAY; int i; for (i = 0; i < period; ++i) { avg_body_sum += (fabs(open[(i)] - close[(i)])); avg_total_sum += (high[(i)] - low[(i)]); }
        while(i < size) { const TC_REAL top = (open[(i)] > close[(i)] ? open[(i)] : close[(i)]); const TC_REAL bottom = (open[(i)] < close[(i)] ? open[(i)] : close[(i)]); const TC_REAL body = (fabs(open[(i)] - close[(i)])); const TC_REAL total = (high[(i)] - low[(i)]); const TC_REAL upper = (high[(i)] - top); const TC_REAL lower = (bottom - low[(i)]); const TC_REAL avg_body = avg_body_sum * div; const TC_REAL avg_total = avg_total_sum * div; (void)top;(void)bottom;(void)body;(void)total; (void)upper;(void)lower;(void)avg_body;(void)avg_total; if (((fabs(open[(i)] - close[(i)])) < (options->body_none * avg_total))) { do { const tc_hit hit = {i, TC_DOJI}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } avg_body_sum += body; avg_body_sum -= (fabs(open[(i-period)] - close[(i-period)])); avg_total_sum += total; avg_total_sum -= (high[(i-period)] - low[(i-period)]); ++i; };
        return TC_OKAY;
    }
int tc_dragonfly_doji(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output) {
        const TC_REAL *open = inputs[0]; const TC_REAL *high = inputs[1]; const TC_REAL *low = inputs[2]; const TC_REAL *close = inputs[3]; const int period = options->period; const TC_REAL div = 1.0 / period; TC_REAL avg_body_sum = 0; TC_REAL avg_total_sum = 0; if (period < 1) return TC_INVALID_OPTION; if (size < period) return TC_OKAY; int i; for (i = 0; i < period; ++i) { avg_body_sum += (fabs(open[(i)] - close[(i)])); avg_total_sum += (high[(i)] - low[(i)]); }
        while(i < size) { const TC_REAL top = (open[(i)] > close[(i)] ? open[(i)] : close[(i)]); const TC_REAL bottom = (open[(i)] < close[(i)] ? open[(i)] : close[(i)]); const TC_REAL body = (fabs(open[(i)] - close[(i)])); const TC_REAL total = (high[(i)] - low[(i)]); const TC_REAL upper = (high[(i)] - top); const TC_REAL lower = (bottom - low[(i)]); const TC_REAL avg_body = avg_body_sum * div; const TC_REAL avg_total = avg_total_sum * div; (void)top;(void)bottom;(void)body;(void)total; (void)upper;(void)lower;(void)avg_body;(void)avg_total; if (((fabs(open[(i)] - close[(i)])) < (options->body_none * avg_total)) && ((high[(i)] - top) < (options->wick_none * avg_total)) && ((bottom - low[(i)]) > (options->wick_long * avg_body))) { do { const tc_hit hit = {i, TC_DRAGONFLY_DOJI}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } avg_body_sum += body; avg_body_sum -= (fabs(open[(i-period)] - close[(i-period)])); avg_total_sum += total; avg_total_sum -= (high[(i-period)] - low[(i-period)]); ++i; };
        return TC_OKAY;
    }
int tc_engulfing_bear(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output) {
        const TC_REAL *open = inputs[0]; const TC_REAL *high = inputs[1]; const TC_REAL *low = inputs[2]; const TC_REAL *close = inputs[3]; const int period = options->period; const TC_REAL div = 1.0 / period; TC_REAL avg_body_sum = 0; TC_REAL avg_total_sum = 0; if (period < 1) return TC_INVALID_OPTION; if (size < period) return TC_OKAY; int i; for (i = 0; i < period; ++i) { avg_body_sum += (fabs(open[(i)] - close[(i)])); avg_total_sum += (high[(i)] - low[(i)]); }
        while(i < size) { const TC_REAL top = (open[(i)] > close[(i)] ? open[(i)] : close[(i)]); const TC_REAL bottom = (open[(i)] < close[(i)] ? open[(i)] : close[(i)]); const TC_REAL body = (fabs(open[(i)] - close[(i)])); const TC_REAL total = (high[(i)] - low[(i)]); const TC_REAL upper = (high[(i)] - top); const TC_REAL lower = (bottom - low[(i)]); const TC_REAL avg_body = avg_body_sum * div; const TC_REAL avg_total = avg_total_sum * div; (void)top;(void)bottom;(void)body;(void)total; (void)upper;(void)lower;(void)avg_body;(void)avg_total; if (i>=1 && (open[i]>close[i]) && (open[i-1]<close[i-1]) && close[i] < open[i-1] && open[i] > close[i-1]) { do { const tc_hit hit = {i, TC_ENGULFING_BEAR}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } avg_body_sum += body; avg_body_sum -= (fabs(open[(i-period)] - close[(i-period)])); avg_total_sum += total; avg_total_sum -= (high[(i-period)] - low[(i-period)]); ++i; };
        return TC_OKAY;
    }
int tc_engulfing_bull(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output) {
        const TC_REAL *open = inputs[0]; const TC_REAL *high = inputs[1]; const TC_REAL *low = inputs[2]; const TC_REAL *close = inputs[3]; const int period = options->period; const TC_REAL div = 1.0 / period; TC_REAL avg_body_sum = 0; TC_REAL avg_total_sum = 0; if (period < 1) return TC_INVALID_OPTION; if (size < period) return TC_OKAY; int i; for (i = 0; i < period; ++i) { avg_body_sum += (fabs(open[(i)] - close[(i)])); avg_total_sum += (high[(i)] - low[(i)]); }
        while(i < size) { const TC_REAL top = (open[(i)] > close[(i)] ? open[(i)] : close[(i)]); const TC_REAL bottom = (open[(i)] < close[(i)] ? open[(i)] : close[(i)]); const TC_REAL body = (fabs(open[(i)] - close[(i)])); const TC_REAL total = (high[(i)] - low[(i)]); const TC_REAL upper = (high[(i)] - top); const TC_REAL lower = (bottom - low[(i)]); const TC_REAL avg_body = avg_body_sum * div; const TC_REAL avg_total = avg_total_sum * div; (void)top;(void)bottom;(void)body;(void)total; (void)upper;(void)lower;(void)avg_body;(void)avg_total; if (i>=1 && (open[i]<close[i]) && (open[i-1]>close[i-1]) && close[i] > open[i-1] && open[i] < close[i-1]) { do { const tc_hit hit = {i, TC_ENGULFING_BULL}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } avg_body_sum += body; avg_body_sum -= (fabs(open[(i-period)] - close[(i-period)])); avg_total_sum += total; avg_total_sum -= (high[(i-period)] - low[(i-period)]); ++i; };
        return TC_OKAY;
    }
int tc_evening_doji_star(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output) {
        const TC_REAL *open = inputs[0]; const TC_REAL *high = inputs[1]; const TC_REAL *low = inputs[2]; const TC_REAL *close = inputs[3]; const int period = options->period; const TC_REAL div = 1.0 / period; TC_REAL avg_body_sum = 0; TC_REAL avg_total_sum = 0; if (period < 1) return TC_INVALID_OPTION; if (size < period) return TC_OKAY; int i; for (i = 0; i < period; ++i) { avg_body_sum += (fabs(open[(i)] - close[(i)])); avg_total_sum += (high[(i)] - low[(i)]); }
        while(i < size) { const TC_REAL top = (open[(i)] > close[(i)] ? open[(i)] : close[(i)]); const TC_REAL bottom = (open[(i)] < close[(i)] ? open[(i)] : close[(i)]); const TC_REAL body = (fabs(open[(i)] - close[(i)])); const TC_REAL total = (high[(i)] - low[(i)]); const TC_REAL upper = (high[(i)] - top); const TC_REAL lower = (bottom - low[(i)]); const TC_REAL avg_body = avg_body_sum * div; const TC_REAL avg_total = avg_total_sum * div; (void)top;(void)bottom;(void)body;(void)total; (void)upper;(void)lower;(void)avg_body;(void)avg_total; if (i>=2 && (open[i-2]<close[i-2]) && ((fabs(open[(i-2)] - close[(i-2)])) > (options->body_long * avg_body)) && ((open[(i-1)] < close[(i-1)] ? open[(i-1)] : close[(i-1)]) >= (open[((i-1)-1)] > close[((i-1)-1)] ? open[((i-1)-1)] : close[((i-1)-1)])) && ((fabs(open[(i-1)] - close[(i-1)])) < (options->body_none * avg_total)) && (open[i]>close[i]) && ((open[(i)] > close[(i)] ? open[(i)] : close[(i)]) <= (open[((i)-1)] < close[((i)-1)] ? open[((i)-1)] : close[((i)-1)])) && (close[i] <= close[i-2])) { do { const tc_hit hit = {i, TC_EVENING_DOJI_STAR}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } avg_body_sum += body; avg_body_sum -= (fabs(open[(i-period)] - close[(i-period)])); avg_total_sum += total; avg_total_sum -= (high[(i-period)] - low[(i-period)]); ++i; };
        return TC_OKAY;
    }
int tc_evening_star(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output) {
        const TC_REAL *open = inputs[0]; const TC_REAL *high = inputs[1]; const TC_REAL *low = inputs[2]; const TC_REAL *close = inputs[3]; const int period = options->period; const TC_REAL div = 1.0 / period; TC_REAL avg_body_sum = 0; TC_REAL avg_total_sum = 0; if (period < 1) return TC_INVALID_OPTION; if (size < period) return TC_OKAY; int i; for (i = 0; i < period; ++i) { avg_body_sum += (fabs(open[(i)] - close[(i)])); avg_total_sum += (high[(i)] - low[(i)]); }
        while(i < size) { const TC_REAL top = (open[(i)] > close[(i)] ? open[(i)] : close[(i)]); const TC_REAL bottom = (open[(i)] < close[(i)] ? open[(i)] : close[(i)]); const TC_REAL body = (fabs(open[(i)] - close[(i)])); const TC_REAL total = (high[(i)] - low[(i)]); const TC_REAL upper = (high[(i)] - top); const TC_REAL lower = (bottom - low[(i)]); const TC_REAL avg_body = avg_body_sum * div; const TC_REAL avg_total = avg_total_sum * div; (void)top;(void)bottom;(void)body;(void)total; (void)upper;(void)lower;(void)avg_body;(void)avg_total; if (i>=2 && (open[i-2]<close[i-2]) && ((fabs(open[(i-2)] - close[(i-2)])) > (options->body_long * avg_body)) && ((open[(i-1)] < close[(i-1)] ? open[(i-1)] : close[(i-1)]) >= (open[((i-1)-1)] > close[((i-1)-1)] ? open[((i-1)-1)] : close[((i-1)-1)])) && ((fabs(open[(i-1)] - close[(i-1)])) < (options->body_short * avg_body)) && (open[i]>close[i]) && ((open[(i)] > close[(i)] ? open[(i)] : close[(i)]) <= (open[((i)-1)] < close[((i)-1)] ? open[((i)-1)] : close[((i)-1)])) && (close[i] <= close[i-2])) { do { const tc_hit hit = {i, TC_EVENING_STAR}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } avg_body_sum += body; avg_body_sum -= (fabs(open[(i-period)] - close[(i-period)])); avg_total_sum += total; avg_total_sum -= (high[(i-period)] - low[(i-period)]); ++i; };
        return TC_OKAY;
    }
int tc_four_price_doji(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output) {
        const TC_REAL *open = inputs[0]; const TC_REAL *high = inputs[1]; const TC_REAL *low = inputs[2]; const TC_REAL *close = inputs[3]; const int period = options->period; const TC_REAL div = 1.0 / period; TC_REAL avg_body_sum = 0; TC_REAL avg_total_sum = 0; if (period < 1) return TC_INVALID_OPTION; if (size < period) return TC_OKAY; int i; for (i = 0; i < period; ++i) { avg_body_sum += (fabs(open[(i)] - close[(i)])); avg_total_sum += (high[(i)] - low[(i)]); }
        while(i < size) { const TC_REAL top = (open[(i)] > close[(i)] ? open[(i)] : close[(i)]); const TC_REAL bottom = (open[(i)] < close[(i)] ? open[(i)] : close[(i)]); const TC_REAL body = (fabs(open[(i)] - close[(i)])); const TC_REAL total = (high[(i)] - low[(i)]); const TC_REAL upper = (high[(i)] - top); const TC_REAL lower = (bottom - low[(i)]); const TC_REAL avg_body = avg_body_sum * div; const TC_REAL avg_total = avg_total_sum * div; (void)top;(void)bottom;(void)body;(void)total; (void)upper;(void)lower;(void)avg_body;(void)avg_total; if (((fabs(open[(i)] - close[(i)])) < (options->body_none * avg_total)) && ((high[(i)] - top) < (options->wick_none * avg_total)) && ((bottom - low[(i)]) < (options->wick_none * avg_total))) { do { const tc_hit hit = {i, TC_FOUR_PRICE_DOJI}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } avg_body_sum += body; avg_body_sum -= (fabs(open[(i-period)] - close[(i-period)])); avg_total_sum += total; avg_total_sum -= (high[(i-period)] - low[(i-period)]); ++i; };
        return TC_OKAY;
    }
int tc_gravestone_doji(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output) {
        const TC_REAL *open = inputs[0]; const TC_REAL *high = inputs[1]; const TC_REAL *low = inputs[2]; const TC_REAL *close = inputs[3]; const int period = options->period; const TC_REAL div = 1.0 / period; TC_REAL avg_body_sum = 0; TC_REAL avg_total_sum = 0; if (period < 1) return TC_INVALID_OPTION; if (size < period) return TC_OKAY; int i; for (i = 0; i < period; ++i) { avg_body_sum += (fabs(open[(i)] - close[(i)])); avg_total_sum += (high[(i)] - low[(i)]); }
        while(i < size) { const TC_REAL top = (open[(i)] > close[(i)] ? open[(i)] : close[(i)]); const TC_REAL bottom = (open[(i)] < close[(i)] ? open[(i)] : close[(i)]); const TC_REAL body = (fabs(open[(i)] - close[(i)])); const TC_REAL total = (high[(i)] - low[(i)]); const TC_REAL upper = (high[(i)] - top); const TC_REAL lower = (bottom - low[(i)]); const TC_REAL avg_body = avg_body_sum * div; const TC_REAL avg_total = avg_total_sum * div; (void)top;(void)bottom;(void)body;(void)total; (void)upper;(void)lower;(void)avg_body;(void)avg_total; if (((fabs(open[(i)] - close[(i)])) < (options->body_none * avg_total)) && ((high[(i)] - top) > (options->wick_long * avg_body)) && ((bottom - low[(i)]) < (options->wick_none * avg_total))) { do { const tc_hit hit = {i, TC_GRAVESTONE_DOJI}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } avg_body_sum += body; avg_body_sum -= (fabs(open[(i-period)] - close[(i-period)])); avg_total_sum += total; avg_total_sum -= (high[(i-period)] - low[(i-period)]); ++i; };
        return TC_OKAY;
    }
int tc_hammer(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output) {
        const TC_REAL *open = inputs[0]; const TC_REAL *high = inputs[1]; const TC_REAL *low = inputs[2]; const TC_REAL *close = inputs[3]; const int period = options->period; const TC_REAL div = 1.0 / period; TC_REAL avg_body_sum = 0; TC_REAL avg_total_sum = 0; if (period < 1) return TC_INVALID_OPTION; if (size < period) return TC_OKAY; int i; for (i = 0; i < period; ++i) { avg_body_sum += (fabs(open[(i)] - close[(i)])); avg_total_sum += (high[(i)] - low[(i)]); }
        while(i < size) { const TC_REAL top = (open[(i)] > close[(i)] ? open[(i)] : close[(i)]); const TC_REAL bottom = (open[(i)] < close[(i)] ? open[(i)] : close[(i)]); const TC_REAL body = (fabs(open[(i)] - close[(i)])); const TC_REAL total = (high[(i)] - low[(i)]); const TC_REAL upper = (high[(i)] - top); const TC_REAL lower = (bottom - low[(i)]); const TC_REAL avg_body = avg_body_sum * div; const TC_REAL avg_total = avg_total_sum * div; (void)top;(void)bottom;(void)body;(void)total; (void)upper;(void)lower;(void)avg_body;(void)avg_total; if (i>=1 && ((fabs(open[(i)] - close[(i)])) < (options->body_short * avg_body)) && ((high[(i)] - top) < (options->wick_none * avg_total)) && ((bottom - low[(i)]) > (options->wick_long * avg_body)) && (open[(i)] < close[(i)] ? open[(i)] : close[(i)]) <= low[i-1] + (options->near * avg_total)) { do { const tc_hit hit = {i, TC_HAMMER}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } avg_body_sum += body; avg_body_sum -= (fabs(open[(i-period)] - close[(i-period)])); avg_total_sum += total; avg_total_sum -= (high[(i-period)] - low[(i-period)]); ++i; };
        return TC_OKAY;
    }
int tc_hanging_man(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output) {
        const TC_REAL *open = inputs[0]; const TC_REAL *high = inputs[1]; const TC_REAL *low = inputs[2]; const TC_REAL *close = inputs[3]; const int period = options->period; const TC_REAL div = 1.0 / period; TC_REAL avg_body_sum = 0; TC_REAL avg_total_sum = 0; if (period < 1) return TC_INVALID_OPTION; if (size < period) return TC_OKAY; int i; for (i = 0; i < period; ++i) { avg_body_sum += (fabs(open[(i)] - close[(i)])); avg_total_sum += (high[(i)] - low[(i)]); }
        while(i < size) { const TC_REAL top = (open[(i)] > close[(i)] ? open[(i)] : close[(i)]); const TC_REAL bottom = (open[(i)] < close[(i)] ? open[(i)] : close[(i)]); const TC_REAL body = (fabs(open[(i)] - close[(i)])); const TC_REAL total = (high[(i)] - low[(i)]); const TC_REAL upper = (high[(i)] - top); const TC_REAL lower = (bottom - low[(i)]); const TC_REAL avg_body = avg_body_sum * div; const TC_REAL avg_total = avg_total_sum * div; (void)top;(void)bottom;(void)body;(void)total; (void)upper;(void)lower;(void)avg_body;(void)avg_total; if (i>=1 && ((fabs(open[(i)] - close[(i)])) < (options->body_short * avg_body)) && ((high[(i)] - top) < (options->wick_none * avg_total)) && ((bottom - low[(i)]) > (options->wick_long * avg_body)) && (open[(i)] < close[(i)] ? open[(i)] : close[(i)]) >= high[i-1] - (options->near * avg_total)) { do { const tc_hit hit = {i, TC_HANGING_MAN}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } avg_body_sum += body; avg_body_sum -= (fabs(open[(i-period)] - close[(i-period)])); avg_total_sum += total; avg_total_sum -= (high[(i-period)] - low[(i-period)]); ++i; };
        return TC_OKAY;
    }
int tc_inverted_hammer(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output) {
        const TC_REAL *open = inputs[0]; const TC_REAL *high = inputs[1]; const TC_REAL *low = inputs[2]; const TC_REAL *close = inputs[3]; const int period = options->period; const TC_REAL div = 1.0 / period; TC_REAL avg_body_sum = 0; TC_REAL avg_total_sum = 0; if (period < 1) return TC_INVALID_OPTION; if (size < period) return TC_OKAY; int i; for (i = 0; i < period; ++i) { avg_body_sum += (fabs(open[(i)] - close[(i)])); avg_total_sum += (high[(i)] - low[(i)]); }
        while(i < size) { const TC_REAL top = (open[(i)] > close[(i)] ? open[(i)] : close[(i)]); const TC_REAL bottom = (open[(i)] < close[(i)] ? open[(i)] : close[(i)]); const TC_REAL body = (fabs(open[(i)] - close[(i)])); const TC_REAL total = (high[(i)] - low[(i)]); const TC_REAL upper = (high[(i)] - top); const TC_REAL lower = (bottom - low[(i)]); const TC_REAL avg_body = avg_body_sum * div; const TC_REAL avg_total = avg_total_sum * div; (void)top;(void)bottom;(void)body;(void)total; (void)upper;(void)lower;(void)avg_body;(void)avg_total; if (i>=1 && ((fabs(open[(i)] - close[(i)])) < (options->body_short * avg_body)) && ((high[(i)] - top) > (options->wick_long * avg_body)) && ((bottom - low[(i)]) < (options->wick_none * avg_total)) && ((open[(i)] > close[(i)] ? open[(i)] : close[(i)]) <= (open[((i)-1)] < close[((i)-1)] ? open[((i)-1)] : close[((i)-1)]))) { do { const tc_hit hit = {i, TC_INVERTED_HAMMER}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } avg_body_sum += body; avg_body_sum -= (fabs(open[(i-period)] - close[(i-period)])); avg_total_sum += total; avg_total_sum -= (high[(i-period)] - low[(i-period)]); ++i; };
        return TC_OKAY;
    }
int tc_long_legged_doji(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output) {
        const TC_REAL *open = inputs[0]; const TC_REAL *high = inputs[1]; const TC_REAL *low = inputs[2]; const TC_REAL *close = inputs[3]; const int period = options->period; const TC_REAL div = 1.0 / period; TC_REAL avg_body_sum = 0; TC_REAL avg_total_sum = 0; if (period < 1) return TC_INVALID_OPTION; if (size < period) return TC_OKAY; int i; for (i = 0; i < period; ++i) { avg_body_sum += (fabs(open[(i)] - close[(i)])); avg_total_sum += (high[(i)] - low[(i)]); }
        while(i < size) { const TC_REAL top = (open[(i)] > close[(i)] ? open[(i)] : close[(i)]); const TC_REAL bottom = (open[(i)] < close[(i)] ? open[(i)] : close[(i)]); const TC_REAL body = (fabs(open[(i)] - close[(i)])); const TC_REAL total = (high[(i)] - low[(i)]); const TC_REAL upper = (high[(i)] - top); const TC_REAL lower = (bottom - low[(i)]); const TC_REAL avg_body = avg_body_sum * div; const TC_REAL avg_total = avg_total_sum * div; (void)top;(void)bottom;(void)body;(void)total; (void)upper;(void)lower;(void)avg_body;(void)avg_total; if (((fabs(open[(i)] - close[(i)])) < (options->body_none * avg_total)) && ((high[(i)] - top) > (options->wick_long * avg_body)) && ((bottom - low[(i)]) > (options->wick_long * avg_body))) { do { const tc_hit hit = {i, TC_LONG_LEGGED_DOJI}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } avg_body_sum += body; avg_body_sum -= (fabs(open[(i-period)] - close[(i-period)])); avg_total_sum += total; avg_total_sum -= (high[(i-period)] - low[(i-period)]); ++i; };
        return TC_OKAY;
    }
int tc_marubozu(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output) {
        const TC_REAL *open = inputs[0]; const TC_REAL *high = inputs[1]; const TC_REAL *low = inputs[2]; const TC_REAL *close = inputs[3]; const int period = options->period; const TC_REAL div = 1.0 / period; TC_REAL avg_body_sum = 0; TC_REAL avg_total_sum = 0; if (period < 1) return TC_INVALID_OPTION; if (size < period) return TC_OKAY; int i; for (i = 0; i < period; ++i) { avg_body_sum += (fabs(open[(i)] - close[(i)])); avg_total_sum += (high[(i)] - low[(i)]); }
        while(i < size) { const TC_REAL top = (open[(i)] > close[(i)] ? open[(i)] : close[(i)]); const TC_REAL bottom = (open[(i)] < close[(i)] ? open[(i)] : close[(i)]); const TC_REAL body = (fabs(open[(i)] - close[(i)])); const TC_REAL total = (high[(i)] - low[(i)]); const TC_REAL upper = (high[(i)] - top); const TC_REAL lower = (bottom - low[(i)]); const TC_REAL avg_body = avg_body_sum * div; const TC_REAL avg_total = avg_total_sum * div; (void)top;(void)bottom;(void)body;(void)total; (void)upper;(void)lower;(void)avg_body;(void)avg_total; if (((fabs(open[(i)] - close[(i)])) > (options->body_long * avg_body)) && ((high[(i)] - top) < (options->wick_none * avg_total)) && ((bottom - low[(i)]) < (options->wick_none * avg_total))) { do { const tc_hit hit = {i, TC_MARUBOZU}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } avg_body_sum += body; avg_body_sum -= (fabs(open[(i-period)] - close[(i-period)])); avg_total_sum += total; avg_total_sum -= (high[(i-period)] - low[(i-period)]); ++i; };
        return TC_OKAY;
    }
int tc_morning_doji_star(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output) {
        const TC_REAL *open = inputs[0]; const TC_REAL *high = inputs[1]; const TC_REAL *low = inputs[2]; const TC_REAL *close = inputs[3]; const int period = options->period; const TC_REAL div = 1.0 / period; TC_REAL avg_body_sum = 0; TC_REAL avg_total_sum = 0; if (period < 1) return TC_INVALID_OPTION; if (size < period) return TC_OKAY; int i; for (i = 0; i < period; ++i) { avg_body_sum += (fabs(open[(i)] - close[(i)])); avg_total_sum += (high[(i)] - low[(i)]); }
        while(i < size) { const TC_REAL top = (open[(i)] > close[(i)] ? open[(i)] : close[(i)]); const TC_REAL bottom = (open[(i)] < close[(i)] ? open[(i)] : close[(i)]); const TC_REAL body = (fabs(open[(i)] - close[(i)])); const TC_REAL total = (high[(i)] - low[(i)]); const TC_REAL upper = (high[(i)] - top); const TC_REAL lower = (bottom - low[(i)]); const TC_REAL avg_body = avg_body_sum * div; const TC_REAL avg_total = avg_total_sum * div; (void)top;(void)bottom;(void)body;(void)total; (void)upper;(void)lower;(void)avg_body;(void)avg_total; if (i>=2 && (open[i-2]>close[i-2]) && ((fabs(open[(i-2)] - close[(i-2)])) > (options->body_long * avg_body)) && ((open[(i-1)] > close[(i-1)] ? open[(i-1)] : close[(i-1)]) <= (open[((i-1)-1)] < close[((i-1)-1)] ? open[((i-1)-1)] : close[((i-1)-1)])) && ((fabs(open[(i-1)] - close[(i-1)])) < (options->body_none * avg_total)) && (open[i]<close[i]) && ((open[(i)] < close[(i)] ? open[(i)] : close[(i)]) >= (open[((i)-1)] > close[((i)-1)] ? open[((i)-1)] : close[((i)-1)])) && (close[i] >= close[i-2])) { do { const tc_hit hit = {i, TC_MORNING_DOJI_STAR}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } avg_body_sum += body; avg_body_sum -= (fabs(open[(i-period)] - close[(i-period)])); avg_total_sum += total; avg_total_sum -= (high[(i-period)] - low[(i-period)]); ++i; };
        return TC_OKAY;
    }
int tc_morning_star(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output) {
        const TC_REAL *open = inputs[0]; const TC_REAL *high = inputs[1]; const TC_REAL *low = inputs[2]; const TC_REAL *close = inputs[3]; const int period = options->period; const TC_REAL div = 1.0 / period; TC_REAL avg_body_sum = 0; TC_REAL avg_total_sum = 0; if (period < 1) return TC_INVALID_OPTION; if (size < period) return TC_OKAY; int i; for (i = 0; i < period; ++i) { avg_body_sum += (fabs(open[(i)] - close[(i)])); avg_total_sum += (high[(i)] - low[(i)]); }
        while(i < size) { const TC_REAL top = (open[(i)] > close[(i)] ? open[(i)] : close[(i)]); const TC_REAL bottom = (open[(i)] < close[(i)] ? open[(i)] : close[(i)]); const TC_REAL body = (fabs(open[(i)] - close[(i)])); const TC_REAL total = (high[(i)] - low[(i)]); const TC_REAL upper = (high[(i)] - top); const TC_REAL lower = (bottom - low[(i)]); const TC_REAL avg_body = avg_body_sum * div; const TC_REAL avg_total = avg_total_sum * div; (void)top;(void)bottom;(void)body;(void)total; (void)upper;(void)lower;(void)avg_body;(void)avg_total; if (i>=2 && (open[i-2]>close[i-2]) && ((fabs(open[(i-2)] - close[(i-2)])) > (options->body_long * avg_body)) && ((open[(i-1)] > close[(i-1)] ? open[(i-1)] : close[(i-1)]) <= (open[((i-1)-1)] < close[((i-1)-1)] ? open[((i-1)-1)] : close[((i-1)-1)])) && ((fabs(open[(i-1)] - close[(i-1)])) < (options->body_short * avg_body)) && (open[i]<close[i]) && ((open[(i)] < close[(i)] ? open[(i)] : close[(i)]) >= (open[((i)-1)] > close[((i)-1)] ? open[((i)-1)] : close[((i)-1)])) && (close[i] >= close[i-2])) { do { const tc_hit hit = {i, TC_MORNING_STAR}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } avg_body_sum += body; avg_body_sum -= (fabs(open[(i-period)] - close[(i-period)])); avg_total_sum += total; avg_total_sum -= (high[(i-period)] - low[(i-period)]); ++i; };
        return TC_OKAY;
    }
int tc_shooting_star(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output) {
        const TC_REAL *open = inputs[0]; const TC_REAL *high = inputs[1]; const TC_REAL *low = inputs[2]; const TC_REAL *close = inputs[3]; const int period = options->period; const TC_REAL div = 1.0 / period; TC_REAL avg_body_sum = 0; TC_REAL avg_total_sum = 0; if (period < 1) return TC_INVALID_OPTION; if (size < period) return TC_OKAY; int i; for (i = 0; i < period; ++i) { avg_body_sum += (fabs(open[(i)] - close[(i)])); avg_total_sum += (high[(i)] - low[(i)]); }
        while(i < size) { const TC_REAL top = (open[(i)] > close[(i)] ? open[(i)] : close[(i)]); const TC_REAL bottom = (open[(i)] < close[(i)] ? open[(i)] : close[(i)]); const TC_REAL body = (fabs(open[(i)] - close[(i)])); const TC_REAL total = (high[(i)] - low[(i)]); const TC_REAL upper = (high[(i)] - top); const TC_REAL lower = (bottom - low[(i)]); const TC_REAL avg_body = avg_body_sum * div; const TC_REAL avg_total = avg_total_sum * div; (void)top;(void)bottom;(void)body;(void)total; (void)upper;(void)lower;(void)avg_body;(void)avg_total; if (i>=1 && ((fabs(open[(i)] - close[(i)])) < (options->body_short * avg_body)) && ((high[(i)] - top) > (options->wick_long * avg_body)) && ((bottom - low[(i)]) < (options->wick_none * avg_total)) && ((open[(i)] < close[(i)] ? open[(i)] : close[(i)]) >= (open[((i)-1)] > close[((i)-1)] ? open[((i)-1)] : close[((i)-1)]))) { do { const tc_hit hit = {i, TC_SHOOTING_STAR}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } avg_body_sum += body; avg_body_sum -= (fabs(open[(i-period)] - close[(i-period)])); avg_total_sum += total; avg_total_sum -= (high[(i-period)] - low[(i-period)]); ++i; };
        return TC_OKAY;
    }
int tc_spinning_top(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output) {
        const TC_REAL *open = inputs[0]; const TC_REAL *high = inputs[1]; const TC_REAL *low = inputs[2]; const TC_REAL *close = inputs[3]; const int period = options->period; const TC_REAL div = 1.0 / period; TC_REAL avg_body_sum = 0; TC_REAL avg_total_sum = 0; if (period < 1) return TC_INVALID_OPTION; if (size < period) return TC_OKAY; int i; for (i = 0; i < period; ++i) { avg_body_sum += (fabs(open[(i)] - close[(i)])); avg_total_sum += (high[(i)] - low[(i)]); }
        while(i < size) { const TC_REAL top = (open[(i)] > close[(i)] ? open[(i)] : close[(i)]); const TC_REAL bottom = (open[(i)] < close[(i)] ? open[(i)] : close[(i)]); const TC_REAL body = (fabs(open[(i)] - close[(i)])); const TC_REAL total = (high[(i)] - low[(i)]); const TC_REAL upper = (high[(i)] - top); const TC_REAL lower = (bottom - low[(i)]); const TC_REAL avg_body = avg_body_sum * div; const TC_REAL avg_total = avg_total_sum * div; (void)top;(void)bottom;(void)body;(void)total; (void)upper;(void)lower;(void)avg_body;(void)avg_total; if (((fabs(open[(i)] - close[(i)])) < (options->body_short * avg_body)) && ((high[(i)] - top) > (fabs(open[(i)] - close[(i)]))) && ((bottom - low[(i)]) > (fabs(open[(i)] - close[(i)])))) { do { const tc_hit hit = {i, TC_SPINNING_TOP}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } avg_body_sum += body; avg_body_sum -= (fabs(open[(i-period)] - close[(i-period)])); avg_total_sum += total; avg_total_sum -= (high[(i-period)] - low[(i-period)]); ++i; };
        return TC_OKAY;
    }
int tc_star(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output) {
        const TC_REAL *open = inputs[0]; const TC_REAL *high = inputs[1]; const TC_REAL *low = inputs[2]; const TC_REAL *close = inputs[3]; const int period = options->period; const TC_REAL div = 1.0 / period; TC_REAL avg_body_sum = 0; TC_REAL avg_total_sum = 0; if (period < 1) return TC_INVALID_OPTION; if (size < period) return TC_OKAY; int i; for (i = 0; i < period; ++i) { avg_body_sum += (fabs(open[(i)] - close[(i)])); avg_total_sum += (high[(i)] - low[(i)]); }
        while(i < size) { const TC_REAL top = (open[(i)] > close[(i)] ? open[(i)] : close[(i)]); const TC_REAL bottom = (open[(i)] < close[(i)] ? open[(i)] : close[(i)]); const TC_REAL body = (fabs(open[(i)] - close[(i)])); const TC_REAL total = (high[(i)] - low[(i)]); const TC_REAL upper = (high[(i)] - top); const TC_REAL lower = (bottom - low[(i)]); const TC_REAL avg_body = avg_body_sum * div; const TC_REAL avg_total = avg_total_sum * div; (void)top;(void)bottom;(void)body;(void)total; (void)upper;(void)lower;(void)avg_body;(void)avg_total; if (i>=1 && ((low[i] >= high[(i)-1]) || (high[i] <= low[(i)-1]))) { do { const tc_hit hit = {i, TC_STAR}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } avg_body_sum += body; avg_body_sum -= (fabs(open[(i-period)] - close[(i-period)])); avg_total_sum += total; avg_total_sum -= (high[(i-period)] - low[(i-period)]); ++i; };
        return TC_OKAY;
    }
int tc_three_black_crows(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output) {
        const TC_REAL *open = inputs[0]; const TC_REAL *high = inputs[1]; const TC_REAL *low = inputs[2]; const TC_REAL *close = inputs[3]; const int period = options->period; const TC_REAL div = 1.0 / period; TC_REAL avg_body_sum = 0; TC_REAL avg_total_sum = 0; if (period < 1) return TC_INVALID_OPTION; if (size < period) return TC_OKAY; int i; for (i = 0; i < period; ++i) { avg_body_sum += (fabs(open[(i)] - close[(i)])); avg_total_sum += (high[(i)] - low[(i)]); }
        while(i < size) { const TC_REAL top = (open[(i)] > close[(i)] ? open[(i)] : close[(i)]); const TC_REAL bottom = (open[(i)] < close[(i)] ? open[(i)] : close[(i)]); const TC_REAL body = (fabs(open[(i)] - close[(i)])); const TC_REAL total = (high[(i)] - low[(i)]); const TC_REAL upper = (high[(i)] - top); const TC_REAL lower = (bottom - low[(i)]); const TC_REAL avg_body = avg_body_sum * div; const TC_REAL avg_total = avg_total_sum * div; (void)top;(void)bottom;(void)body;(void)total; (void)upper;(void)lower;(void)avg_body;(void)avg_total; if (i>=2 && (open[i-2]>close[i-2]) && (open[i-1]>close[i-1]) && (open[i]>close[i]) && (open[i-1] < (open[((i-1)-1)] > close[((i-1)-1)] ? open[((i-1)-1)] : close[((i-1)-1)]) && open[i-1] > (open[((i-1)-1)] < close[((i-1)-1)] ? open[((i-1)-1)] : close[((i-1)-1)])) && (open[i] < (open[((i)-1)] > close[((i)-1)] ? open[((i)-1)] : close[((i)-1)]) && open[i] > (open[((i)-1)] < close[((i)-1)] ? open[((i)-1)] : close[((i)-1)]))) { do { const tc_hit hit = {i, TC_THREE_BLACK_CROWS}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } avg_body_sum += body; avg_body_sum -= (fabs(open[(i-period)] - close[(i-period)])); avg_total_sum += total; avg_total_sum -= (high[(i-period)] - low[(i-period)]); ++i; };
        return TC_OKAY;
    }
int tc_three_white_soldiers(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output) {
        const TC_REAL *open = inputs[0]; const TC_REAL *high = inputs[1]; const TC_REAL *low = inputs[2]; const TC_REAL *close = inputs[3]; const int period = options->period; const TC_REAL div = 1.0 / period; TC_REAL avg_body_sum = 0; TC_REAL avg_total_sum = 0; if (period < 1) return TC_INVALID_OPTION; if (size < period) return TC_OKAY; int i; for (i = 0; i < period; ++i) { avg_body_sum += (fabs(open[(i)] - close[(i)])); avg_total_sum += (high[(i)] - low[(i)]); }
        while(i < size) { const TC_REAL top = (open[(i)] > close[(i)] ? open[(i)] : close[(i)]); const TC_REAL bottom = (open[(i)] < close[(i)] ? open[(i)] : close[(i)]); const TC_REAL body = (fabs(open[(i)] - close[(i)])); const TC_REAL total = (high[(i)] - low[(i)]); const TC_REAL upper = (high[(i)] - top); const TC_REAL lower = (bottom - low[(i)]); const TC_REAL avg_body = avg_body_sum * div; const TC_REAL avg_total = avg_total_sum * div; (void)top;(void)bottom;(void)body;(void)total; (void)upper;(void)lower;(void)avg_body;(void)avg_total; if (i>=2 && (open[i-2]<close[i-2]) && (open[i-1]<close[i-1]) && (open[i]<close[i]) && (open[i-1] < (open[((i-1)-1)] > close[((i-1)-1)] ? open[((i-1)-1)] : close[((i-1)-1)]) && open[i-1] > (open[((i-1)-1)] < close[((i-1)-1)] ? open[((i-1)-1)] : close[((i-1)-1)])) && (open[i] < (open[((i)-1)] > close[((i)-1)] ? open[((i)-1)] : close[((i)-1)]) && open[i] > (open[((i)-1)] < close[((i)-1)] ? open[((i)-1)] : close[((i)-1)]))) { do { const tc_hit hit = {i, TC_THREE_WHITE_SOLDIERS}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } avg_body_sum += body; avg_body_sum -= (fabs(open[(i-period)] - close[(i-period)])); avg_total_sum += total; avg_total_sum -= (high[(i-period)] - low[(i-period)]); ++i; };
        return TC_OKAY;
    }
int tc_white_marubozu(int size, TC_REAL const *const *inputs, tc_config const *options, tc_result *output) {
        const TC_REAL *open = inputs[0]; const TC_REAL *high = inputs[1]; const TC_REAL *low = inputs[2]; const TC_REAL *close = inputs[3]; const int period = options->period; const TC_REAL div = 1.0 / period; TC_REAL avg_body_sum = 0; TC_REAL avg_total_sum = 0; if (period < 1) return TC_INVALID_OPTION; if (size < period) return TC_OKAY; int i; for (i = 0; i < period; ++i) { avg_body_sum += (fabs(open[(i)] - close[(i)])); avg_total_sum += (high[(i)] - low[(i)]); }
        while(i < size) { const TC_REAL top = (open[(i)] > close[(i)] ? open[(i)] : close[(i)]); const TC_REAL bottom = (open[(i)] < close[(i)] ? open[(i)] : close[(i)]); const TC_REAL body = (fabs(open[(i)] - close[(i)])); const TC_REAL total = (high[(i)] - low[(i)]); const TC_REAL upper = (high[(i)] - top); const TC_REAL lower = (bottom - low[(i)]); const TC_REAL avg_body = avg_body_sum * div; const TC_REAL avg_total = avg_total_sum * div; (void)top;(void)bottom;(void)body;(void)total; (void)upper;(void)lower;(void)avg_body;(void)avg_total; if (((fabs(open[(i)] - close[(i)])) > (options->body_long * avg_body)) && ((high[(i)] - top) < (options->wick_none * avg_total)) && ((bottom - low[(i)]) < (options->wick_none * avg_total)) && (open[i]<close[i])) { do { const tc_hit hit = {i, TC_WHITE_MARUBOZU}; const int r = tc_result_add(output, hit); if (r != TC_OKAY) return r; } while (0); } avg_body_sum += body; avg_body_sum -= (fabs(open[(i-period)] - close[(i-period)])); avg_total_sum += total; avg_total_sum -= (high[(i-period)] - low[(i-period)]); ++i; };
        return TC_OKAY;
    }
