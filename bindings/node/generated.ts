/* eslint-disable no-empty-pattern */
// Path: generated.ts
// This code is generated, please do not edit it manually.
import type { TSchema } from '@cybotrade/core';
import { type Static, Type } from '@cybotrade/core';

import { indicators as rawIndicators } from './bindings';
import {
  BarColor,
  BearSignal,
  BullSignal,
  BuySellSignal,
  BuySignal,
  CrossSignal,
  DirectionSignal,
  HeatmapLevel,
  SellSignal,
} from './public';

export const schemas = {
  chaikin_vol: {
    inputs: Type.Object({
      high: Type.Array(Type.Number()),
      low: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      ema_period: Type.Number({ default: 7, minimum: 1 }),
      roc_period: Type.Number({ default: 14, minimum: 1 }),
    }),
    outputs: Type.Object({
      cvi: Type.Array(Type.Number()),
    }),
  },
  stoch_rsi: {
    inputs: Type.Object({
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      smoothk: Type.Number({ default: 3 }),
      smoothd: Type.Number({ default: 3 }),
      rsi_period: Type.Number({ default: 14, minimum: 1 }),
      stoch_period: Type.Number({ default: 14, minimum: 1 }),
    }),
    outputs: Type.Object({
      stoch_k: Type.Array(Type.Number()),
      stoch_d: Type.Array(Type.Number()),
    }),
  },
  supertrend: {
    inputs: Type.Object({
      high: Type.Array(Type.Number()),
      low: Type.Array(Type.Number()),
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      period: Type.Number({ default: 34, minimum: 1 }),
      factor: Type.Number({ default: 3 }),
    }),
    outputs: Type.Object({
      supertrend: Type.Array(Type.Number()),
      direction: Type.Array(Type.Enum(DirectionSignal)),
      bar_color: Type.Array(Type.Enum(BarColor)),
      buy_sell_signal: Type.Array(Type.Enum(BuySellSignal)),
    }),
  },
  wavetrend: {
    inputs: Type.Object({
      high: Type.Array(Type.Number()),
      low: Type.Array(Type.Number()),
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      period_one: Type.Number({ default: 9, minimum: 1 }),
      period_two: Type.Number({ default: 12, minimum: 1 }),
    }),
    outputs: Type.Object({
      wavetrend_one: Type.Array(Type.Number()),
      wavetrend_two: Type.Array(Type.Number()),
    }),
  },
  andean_osc: {
    inputs: Type.Object({
      open: Type.Array(Type.Number()),
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      period: Type.Number({ default: 50, minimum: 1 }),
      signal_length: Type.Number({ default: 9, minimum: 1 }),
    }),
    outputs: Type.Object({
      bull_data: Type.Array(Type.Number()),
      bear_data: Type.Array(Type.Number()),
      ao_data: Type.Array(Type.Number()),
    }),
  },
  braid_filter: {
    inputs: Type.Object({
      open: Type.Array(Type.Number()),
      high: Type.Array(Type.Number()),
      low: Type.Array(Type.Number()),
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      ma01_length: Type.Number({ default: 3, minimum: 1 }),
      ma02_length: Type.Number({ default: 7, minimum: 1 }),
      ma03_length: Type.Number({ default: 14, minimum: 1 }),
      pips_min_sep_percent: Type.Number({ default: 40 }),
    }),
    outputs: Type.Object({
      dif: Type.Array(Type.Number()),
      atr_filter: Type.Array(Type.Number()),
      bar_color: Type.Array(Type.Enum(BarColor)),
    }),
  },
  boom_pro: {
    inputs: Type.Object({
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      lp_period_one: Type.Number({ default: 6, minimum: 1 }),
      k1_quotient: Type.Number({ default: 0 }),
      trig_no: Type.Number({ default: 2 }),
      lp_period_two: Type.Number({ default: 27, minimum: 1 }),
      k22_eot: Type.Number({ default: 0.3 }),
    }),
    outputs: Type.Object({
      trigger: Type.Array(Type.Number()),
      q4: Type.Array(Type.Number()),
    }),
  },
  chandelier_exit: {
    inputs: Type.Object({
      high: Type.Array(Type.Number()),
      low: Type.Array(Type.Number()),
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      period: Type.Number({ default: 22, minimum: 1 }),
      atr_multiplier: Type.Number({ default: 3 }),
    }),
    outputs: Type.Object({
      buy_sell_signal: Type.Array(Type.Enum(BuySellSignal)),
    }),
  },
  cm_ema_trendbars: {
    inputs: Type.Object({
      high: Type.Array(Type.Number()),
      low: Type.Array(Type.Number()),
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      ema_length: Type.Number({ default: 34, minimum: 1 }),
    }),
    outputs: Type.Object({
      usdema: Type.Array(Type.Number()),
      bar_color: Type.Array(Type.Enum(BarColor)),
    }),
  },
  di_dx: {
    inputs: Type.Object({
      high: Type.Array(Type.Number()),
      low: Type.Array(Type.Number()),
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      period: Type.Number({ default: 14, minimum: 1 }),
    }),
    outputs: Type.Object({
      dx: Type.Array(Type.Number()),
      di_plus: Type.Array(Type.Number()),
      di_minus: Type.Array(Type.Number()),
    }),
  },
  half_trend: {
    inputs: Type.Object({
      high: Type.Array(Type.Number()),
      low: Type.Array(Type.Number()),
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      amplitude: Type.Number({ default: 2 }),
      channel_deviation: Type.Number({ default: 2 }),
      atr_length: Type.Number({ default: 100, minimum: 1 }),
    }),
    outputs: Type.Object({
      ht: Type.Array(Type.Number()),
      bar_color: Type.Array(Type.Enum(BarColor)),
    }),
  },
  heatmap_vol: {
    inputs: Type.Object({
      volume: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      length: Type.Number({ default: 610, minimum: 1 }),
      std_length: Type.Number({ default: 610, minimum: 1 }),
      threshold_extra_high: Type.Number({ default: 4 }),
      threshold_high: Type.Number({ default: 2.5 }),
      threshold_medium: Type.Number({ default: 1 }),
      threshold_normal: Type.Number({ default: -0.5 }),
    }),
    outputs: Type.Object({
      heatmap_level: Type.Array(Type.Enum(HeatmapLevel)),
    }),
  },
  hull_suite: {
    inputs: Type.Object({
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      hma_length: Type.Number({ default: 55, minimum: 1 }),
    }),
    outputs: Type.Object({
      bar_color: Type.Array(Type.Enum(BarColor)),
    }),
  },
  macd_fastline_divergence: {
    inputs: Type.Object({
      high: Type.Array(Type.Number()),
      low: Type.Array(Type.Number()),
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      fast_length: Type.Number({ default: 12, minimum: 1 }),
      slow_length: Type.Number({ default: 26, minimum: 1 }),
      signal_length: Type.Number({ default: 9, minimum: 1 }),
    }),
    outputs: Type.Object({
      bull: Type.Array(Type.Enum(BullSignal)),
      bear: Type.Array(Type.Enum(BearSignal)),
    }),
  },
  macd_hist_divergence: {
    inputs: Type.Object({
      high: Type.Array(Type.Number()),
      low: Type.Array(Type.Number()),
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      fast_length: Type.Number({ default: 12, minimum: 1 }),
      slow_length: Type.Number({ default: 26, minimum: 1 }),
      signal_length: Type.Number({ default: 9, minimum: 1 }),
    }),
    outputs: Type.Object({
      bull: Type.Array(Type.Enum(BullSignal)),
      bear: Type.Array(Type.Enum(BearSignal)),
    }),
  },
  mobo_band: {
    inputs: Type.Object({
      high: Type.Array(Type.Number()),
      low: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      dpo_length: Type.Number({ default: 13, minimum: 1 }),
      mobo_length: Type.Number({ default: 10, minimum: 1 }),
      num_dev_down: Type.Number({ default: -0.8 }),
      num_dev_up: Type.Number({ default: 0.8 }),
    }),
    outputs: Type.Object({
      buy_sell_signal: Type.Array(Type.Enum(BuySellSignal)),
    }),
  },
  qqe_mod: {
    inputs: Type.Object({
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      rsi_length_one: Type.Number({ default: 6, minimum: 1 }),
      rsi_smoothing_one: Type.Number({ default: 5 }),
      qqe_factor_one: Type.Number({ default: 3 }),
      threshold_one: Type.Number({ default: 3 }),
      rsi_length_two: Type.Number({ default: 6, minimum: 1 }),
      rsi_smoothing_two: Type.Number({ default: 5 }),
      qqe_factor_two: Type.Number({ default: 1.61 }),
      threshold_two: Type.Number({ default: 3 }),
      bollinger_length: Type.Number({ default: 50, minimum: 1 }),
      qqe_multiplier: Type.Number({ default: 0.35 }),
    }),
    outputs: Type.Object({
      bar_color_one: Type.Array(Type.Enum(BarColor)),
      bar_color_two: Type.Array(Type.Enum(BarColor)),
    }),
  },
  rsi_divergence: {
    inputs: Type.Object({
      high: Type.Array(Type.Number()),
      low: Type.Array(Type.Number()),
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      left_bar: Type.Number({ default: 6 }),
      right_bar: Type.Number({ default: 2 }),
      rsi_length: Type.Number({ default: 14, minimum: 1 }),
    }),
    outputs: Type.Object({
      bull: Type.Array(Type.Enum(BullSignal)),
      bear: Type.Array(Type.Enum(BearSignal)),
    }),
  },
  rvi: {
    inputs: Type.Object({
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      std_length: Type.Number({ default: 10, minimum: 1 }),
      ema_length: Type.Number({ default: 14, minimum: 1 }),
    }),
    outputs: Type.Object({
      rvi: Type.Array(Type.Number()),
    }),
  },
  rvi_divergence: {
    inputs: Type.Object({
      high: Type.Array(Type.Number()),
      low: Type.Array(Type.Number()),
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      left_bar: Type.Number({ default: 6 }),
      right_bar: Type.Number({ default: 2 }),
      std_length: Type.Number({ default: 12, minimum: 1 }),
      ema_length: Type.Number({ default: 14, minimum: 1 }),
    }),
    outputs: Type.Object({
      bull: Type.Array(Type.Enum(BullSignal)),
      bear: Type.Array(Type.Enum(BearSignal)),
    }),
  },
  ssl: {
    inputs: Type.Object({
      high: Type.Array(Type.Number()),
      low: Type.Array(Type.Number()),
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      ma_length: Type.Number({ default: 60, minimum: 1 }),
      ssl3_length: Type.Number({ default: 15, minimum: 1 }),
    }),
    outputs: Type.Object({
      bbmc: Type.Array(Type.Number()),
      bar_color: Type.Array(Type.Enum(BarColor)),
      up_erk: Type.Array(Type.Number()),
      low_erk: Type.Array(Type.Number()),
      cross_long: Type.Array(Type.Enum(CrossSignal)),
      cross_short: Type.Array(Type.Enum(CrossSignal)),
    }),
  },
  stc: {
    inputs: Type.Object({
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      length: Type.Number({ default: 12, minimum: 1 }),
      fast_length: Type.Number({ default: 26, minimum: 1 }),
      slow_length: Type.Number({ default: 50, minimum: 1 }),
      aaa: Type.Number({ default: 0.5 }),
    }),
    outputs: Type.Object({
      stc: Type.Array(Type.Number()),
      bar_color: Type.Array(Type.Enum(BarColor)),
    }),
  },
  stoch_divergence: {
    inputs: Type.Object({
      high: Type.Array(Type.Number()),
      low: Type.Array(Type.Number()),
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      left_bar: Type.Number({ default: 6 }),
      right_bar: Type.Number({ default: 2 }),
      stk_length: Type.Number({ default: 14, minimum: 1 }),
      smooth_length: Type.Number({ default: 3, minimum: 1 }),
      sma_length: Type.Number({ default: 3, minimum: 1 }),
    }),
    outputs: Type.Object({
      bull: Type.Array(Type.Enum(BullSignal)),
      bear: Type.Array(Type.Enum(BearSignal)),
    }),
  },
  sup_and_res: {
    inputs: Type.Object({
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      left_bar: Type.Number({ default: 200 }),
      right_bar_one: Type.Number({ default: 20 }),
      right_bar_two: Type.Number({ default: 5 }),
      hma_length: Type.Number({ default: 9, minimum: 1 }),
    }),
    outputs: Type.Object({
      buy_one: Type.Array(Type.Enum(BuySignal)),
      buy_two: Type.Array(Type.Enum(BuySignal)),
      buy_three: Type.Array(Type.Enum(BuySignal)),
      buy_four: Type.Array(Type.Enum(BuySignal)),
      buy_five: Type.Array(Type.Enum(BuySignal)),
      buy_six: Type.Array(Type.Enum(BuySignal)),
      buy_seven: Type.Array(Type.Enum(BuySignal)),
      buy_eight: Type.Array(Type.Enum(BuySignal)),
      sell_one: Type.Array(Type.Enum(SellSignal)),
      sell_two: Type.Array(Type.Enum(SellSignal)),
      sell_three: Type.Array(Type.Enum(SellSignal)),
      sell_four: Type.Array(Type.Enum(SellSignal)),
      sell_five: Type.Array(Type.Enum(SellSignal)),
      sell_six: Type.Array(Type.Enum(SellSignal)),
      sell_seven: Type.Array(Type.Enum(SellSignal)),
      sell_eight: Type.Array(Type.Enum(SellSignal)),
    }),
  },
  ut_bot: {
    inputs: Type.Object({
      high: Type.Array(Type.Number()),
      low: Type.Array(Type.Number()),
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      atr_period: Type.Number({ default: 10, minimum: 1 }),
      sensitivity: Type.Number({ default: 1 }),
    }),
    outputs: Type.Object({
      buy_sell_signal: Type.Array(Type.Enum(BuySellSignal)),
    }),
  },
  volatility_oscillator: {
    inputs: Type.Object({
      open: Type.Array(Type.Number()),
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      length: Type.Number({ default: 100, minimum: 1 }),
    }),
    outputs: Type.Object({
      spike_line: Type.Array(Type.Number()),
      upper_line: Type.Array(Type.Number()),
      lower_line: Type.Array(Type.Number()),
    }),
  },
  vu_man_chu_swing: {
    inputs: Type.Object({
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      swing_period: Type.Number({ default: 20, minimum: 1 }),
      swing_multiplier: Type.Number({ default: 3.5 }),
    }),
    outputs: Type.Object({
      buy_sell_signal_long: Type.Array(Type.Enum(BuySellSignal)),
      buy_sell_signal_short: Type.Array(Type.Enum(BuySellSignal)),
    }),
  },
  waddah: {
    inputs: Type.Object({
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      fast_length: Type.Number({ default: 20, minimum: 1 }),
      slow_length: Type.Number({ default: 40, minimum: 1 }),
      signal_length: Type.Number({ default: 9, minimum: 1 }),
      bb_length: Type.Number({ default: 20, minimum: 1 }),
      multiplier: Type.Number({ default: 2 }),
      sensitivity: Type.Number({ default: 150 }),
    }),
    outputs: Type.Object({
      t: Type.Array(Type.Number()),
      e: Type.Array(Type.Number()),
      trend_up: Type.Array(Type.Number()),
      trend_down: Type.Array(Type.Number()),
    }),
  },
  psar: {
    inputs: Type.Object({
      high: Type.Array(Type.Number()),
      low: Type.Array(Type.Number()),
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      accel_start: Type.Number({ default: 0.02 }),
      accel_step: Type.Number({ default: 0.02 }),
      accel_max: Type.Number({ default: 0.2 }),
    }),
    outputs: Type.Object({
      psar: Type.Array(Type.Number()),
    }),
  },
  dx: {
    inputs: Type.Object({
      high: Type.Array(Type.Number()),
      low: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      period: Type.Number({ default: 14, minimum: 1 }),
    }),
    outputs: Type.Object({
      dx: Type.Array(Type.Number()),
    }),
  },
  adx: {
    inputs: Type.Object({
      high: Type.Array(Type.Number()),
      low: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      period: Type.Number({ default: 14, minimum: 1 }),
    }),
    outputs: Type.Object({
      adx: Type.Array(Type.Number()),
    }),
  },
  dema: {
    inputs: Type.Object({
      value: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      period: Type.Number({ default: 9, minimum: 1 }),
    }),
    outputs: Type.Object({
      dema: Type.Array(Type.Number()),
    }),
  },
  ema: {
    inputs: Type.Object({
      value: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      period: Type.Number({ default: 9, minimum: 1 }),
    }),
    outputs: Type.Object({
      ema: Type.Array(Type.Number()),
    }),
  },
  hma: {
    inputs: Type.Object({
      value: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      period: Type.Number({ default: 9, minimum: 1 }),
    }),
    outputs: Type.Object({
      hma: Type.Array(Type.Number()),
    }),
  },
  sma: {
    inputs: Type.Object({
      value: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      period: Type.Number({ default: 7, minimum: 1 }),
    }),
    outputs: Type.Object({
      sma: Type.Array(Type.Number()),
    }),
  },
  tema: {
    inputs: Type.Object({
      value: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      period: Type.Number({ default: 9, minimum: 1 }),
    }),
    outputs: Type.Object({
      tema: Type.Array(Type.Number()),
    }),
  },
  trima: {
    inputs: Type.Object({
      value: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      period: Type.Number({ default: 20, minimum: 1 }),
    }),
    outputs: Type.Object({
      trima: Type.Array(Type.Number()),
    }),
  },
  vwma: {
    inputs: Type.Object({
      close: Type.Array(Type.Number()),
      volume: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      period: Type.Number({ default: 20, minimum: 1 }),
    }),
    outputs: Type.Object({
      vwma: Type.Array(Type.Number()),
    }),
  },
  wma: {
    inputs: Type.Object({
      value: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      period: Type.Number({ default: 9, minimum: 1 }),
    }),
    outputs: Type.Object({
      wma: Type.Array(Type.Number()),
    }),
  },
  linreg: {
    inputs: Type.Object({
      value: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      period: Type.Number({ default: 100, minimum: 1 }),
    }),
    outputs: Type.Object({
      linreg: Type.Array(Type.Number()),
    }),
  },
  bbands: {
    inputs: Type.Object({
      value: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      period: Type.Number({ default: 20, minimum: 1 }),
      stddev: Type.Number({ default: 2 }),
    }),
    outputs: Type.Object({
      bbands_lower: Type.Array(Type.Number()),
      bbands_middle: Type.Array(Type.Number()),
      bbands_upper: Type.Array(Type.Number()),
    }),
  },
  cci: {
    inputs: Type.Object({
      high: Type.Array(Type.Number()),
      low: Type.Array(Type.Number()),
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      period: Type.Number({ default: 20, minimum: 1 }),
    }),
    outputs: Type.Object({
      cci: Type.Array(Type.Number()),
    }),
  },
  stoch: {
    inputs: Type.Object({
      high: Type.Array(Type.Number()),
      low: Type.Array(Type.Number()),
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      k_period: Type.Number({ default: 14, minimum: 1 }),
      k_slowing_period: Type.Number({ default: 1, minimum: 1 }),
      d_period: Type.Number({ default: 3, minimum: 1 }),
    }),
    outputs: Type.Object({
      stoch_k: Type.Array(Type.Number()),
      stoch_d: Type.Array(Type.Number()),
    }),
  },
  mfi: {
    inputs: Type.Object({
      high: Type.Array(Type.Number()),
      low: Type.Array(Type.Number()),
      close: Type.Array(Type.Number()),
      volume: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      period: Type.Number({ default: 14, minimum: 1 }),
    }),
    outputs: Type.Object({
      mfi: Type.Array(Type.Number()),
    }),
  },
  macd: {
    inputs: Type.Object({
      value: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      short_period: Type.Number({ default: 12, minimum: 1 }),
      long_period: Type.Number({ default: 26, minimum: 1 }),
      signal_period: Type.Number({ default: 9, minimum: 1 }),
    }),
    outputs: Type.Object({
      macd: Type.Array(Type.Number()),
      macd_signal: Type.Array(Type.Number()),
      macd_histogram: Type.Array(Type.Number()),
    }),
  },
  rsi: {
    inputs: Type.Object({
      value: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      period: Type.Number({ default: 14, minimum: 1 }),
    }),
    outputs: Type.Object({
      rsi: Type.Array(Type.Number()),
    }),
  },
  natr: {
    inputs: Type.Object({
      high: Type.Array(Type.Number()),
      low: Type.Array(Type.Number()),
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      period: Type.Number({ default: 14, minimum: 1 }),
    }),
    outputs: Type.Object({
      natr: Type.Array(Type.Number()),
    }),
  },
  atr: {
    inputs: Type.Object({
      high: Type.Array(Type.Number()),
      low: Type.Array(Type.Number()),
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({
      period: Type.Number({ default: 14, minimum: 1 }),
    }),
    outputs: Type.Object({
      atr: Type.Array(Type.Number()),
    }),
  },
  insidebar: {
    inputs: Type.Object({
      open: Type.Array(Type.Number()),
      high: Type.Array(Type.Number()),
      low: Type.Array(Type.Number()),
      close: Type.Array(Type.Number()),
    }),
    options: Type.Object({}),
    outputs: Type.Object({
      buy_sell_signal: Type.Array(Type.Enum(BuySellSignal)),
    }),
  },
  price: {
    inputs: Type.Object({
      value: Type.Array(Type.Number()),
    }),
    options: Type.Object({}),
    outputs: Type.Object({
      price: Type.Array(Type.Number()),
    }),
  },
};

type IndicatorFn<
  S extends {
    inputs: TSchema;
    options: TSchema;
    outputs: TSchema;
  },
> = (input: Static<S['inputs']>, option: Static<S['options']>) => Static<S['outputs']>;

const unshift = (value: number[], length: number, defaultValue = 0): number[] =>
  new Array(length).fill(defaultValue).concat(value);

export const indicators = {
  chaikin_vol: (({ high, low }, { ema_period, roc_period }) => {
    const start = rawIndicators.chaikin_vol.start([ema_period, roc_period]);
    const result = rawIndicators.chaikin_vol.indicator([high, low], [ema_period, roc_period]);
    return { cvi: unshift(result[0], start) };
  }) as IndicatorFn<typeof schemas.chaikin_vol>,
  stoch_rsi: (({ close }, { smoothk, smoothd, rsi_period, stoch_period }) => {
    const start = rawIndicators.stoch_rsi.start([smoothk, smoothd, rsi_period, stoch_period]);
    const result = rawIndicators.stoch_rsi.indicator(
      [close],
      [smoothk, smoothd, rsi_period, stoch_period],
    );
    return {
      stoch_k: unshift(result[0], start),
      stoch_d: unshift(result[1], start),
    };
  }) as IndicatorFn<typeof schemas.stoch_rsi>,
  supertrend: (({ high, low, close }, { period, factor }) => {
    const start = rawIndicators.supertrend.start([period, factor]);
    const result = rawIndicators.supertrend.indicator([high, low, close], [period, factor]);
    return {
      supertrend: unshift(result[0], start),
      direction: unshift(result[1], start),
      bar_color: unshift(result[2], start),
      buy_sell_signal: unshift(result[3], start),
    };
  }) as IndicatorFn<typeof schemas.supertrend>,
  wavetrend: (({ high, low, close }, { period_one, period_two }) => {
    const start = rawIndicators.wavetrend.start([period_one, period_two]);
    const result = rawIndicators.wavetrend.indicator([high, low, close], [period_one, period_two]);
    return {
      wavetrend_one: unshift(result[0], start),
      wavetrend_two: unshift(result[1], start),
    };
  }) as IndicatorFn<typeof schemas.wavetrend>,
  andean_osc: (({ open, close }, { period, signal_length }) => {
    const start = rawIndicators.andean_osc.start([period, signal_length]);
    const result = rawIndicators.andean_osc.indicator([open, close], [period, signal_length]);
    return {
      bull_data: unshift(result[0], start),
      bear_data: unshift(result[1], start),
      ao_data: unshift(result[2], start),
    };
  }) as IndicatorFn<typeof schemas.andean_osc>,
  braid_filter: ((
    { open, high, low, close },
    { ma01_length, ma02_length, ma03_length, pips_min_sep_percent },
  ) => {
    const start = rawIndicators.braid_filter.start([
      ma01_length,
      ma02_length,
      ma03_length,
      pips_min_sep_percent,
    ]);
    const result = rawIndicators.braid_filter.indicator(
      [open, high, low, close],
      [ma01_length, ma02_length, ma03_length, pips_min_sep_percent],
    );
    return {
      dif: unshift(result[0], start),
      atr_filter: unshift(result[1], start),
      bar_color: unshift(result[2], start),
    };
  }) as IndicatorFn<typeof schemas.braid_filter>,
  boom_pro: (({ close }, { lp_period_one, k1_quotient, trig_no, lp_period_two, k22_eot }) => {
    const start = rawIndicators.boom_pro.start([
      lp_period_one,
      k1_quotient,
      trig_no,
      lp_period_two,
      k22_eot,
    ]);
    const result = rawIndicators.boom_pro.indicator(
      [close],
      [lp_period_one, k1_quotient, trig_no, lp_period_two, k22_eot],
    );
    return {
      trigger: unshift(result[0], start),
      q4: unshift(result[1], start),
    };
  }) as IndicatorFn<typeof schemas.boom_pro>,
  chandelier_exit: (({ high, low, close }, { period, atr_multiplier }) => {
    const start = rawIndicators.chandelier_exit.start([period, atr_multiplier]);
    const result = rawIndicators.chandelier_exit.indicator(
      [high, low, close],
      [period, atr_multiplier],
    );
    return { buy_sell_signal: unshift(result[0], start) };
  }) as IndicatorFn<typeof schemas.chandelier_exit>,
  cm_ema_trendbars: (({ high, low, close }, { ema_length }) => {
    const start = rawIndicators.cm_ema_trendbars.start([ema_length]);
    const result = rawIndicators.cm_ema_trendbars.indicator([high, low, close], [ema_length]);
    return {
      usdema: unshift(result[0], start),
      bar_color: unshift(result[1], start),
    };
  }) as IndicatorFn<typeof schemas.cm_ema_trendbars>,
  di_dx: (({ high, low, close }, { period }) => {
    const start = rawIndicators.di_dx.start([period]);
    const result = rawIndicators.di_dx.indicator([high, low, close], [period]);
    return {
      dx: unshift(result[0], start),
      di_plus: unshift(result[1], start),
      di_minus: unshift(result[2], start),
    };
  }) as IndicatorFn<typeof schemas.di_dx>,
  half_trend: (({ high, low, close }, { amplitude, channel_deviation, atr_length }) => {
    const start = rawIndicators.half_trend.start([amplitude, channel_deviation, atr_length]);
    const result = rawIndicators.half_trend.indicator(
      [high, low, close],
      [amplitude, channel_deviation, atr_length],
    );
    return {
      ht: unshift(result[0], start),
      bar_color: unshift(result[1], start),
    };
  }) as IndicatorFn<typeof schemas.half_trend>,
  heatmap_vol: ((
    { volume },
    {
      length,
      std_length,
      threshold_extra_high,
      threshold_high,
      threshold_medium,
      threshold_normal,
    },
  ) => {
    const start = rawIndicators.heatmap_vol.start([
      length,
      std_length,
      threshold_extra_high,
      threshold_high,
      threshold_medium,
      threshold_normal,
    ]);
    const result = rawIndicators.heatmap_vol.indicator(
      [volume],
      [
        length,
        std_length,
        threshold_extra_high,
        threshold_high,
        threshold_medium,
        threshold_normal,
      ],
    );
    return { heatmap_level: unshift(result[0], start) };
  }) as IndicatorFn<typeof schemas.heatmap_vol>,
  hull_suite: (({ close }, { hma_length }) => {
    const start = rawIndicators.hull_suite.start([hma_length]);
    const result = rawIndicators.hull_suite.indicator([close], [hma_length]);
    return { bar_color: unshift(result[0], start) };
  }) as IndicatorFn<typeof schemas.hull_suite>,
  macd_fastline_divergence: ((
    { high, low, close },
    { fast_length, slow_length, signal_length },
  ) => {
    const start = rawIndicators.macd_fastline_divergence.start([
      fast_length,
      slow_length,
      signal_length,
    ]);
    const result = rawIndicators.macd_fastline_divergence.indicator(
      [high, low, close],
      [fast_length, slow_length, signal_length],
    );
    return { bull: unshift(result[0], start), bear: unshift(result[1], start) };
  }) as IndicatorFn<typeof schemas.macd_fastline_divergence>,
  macd_hist_divergence: (({ high, low, close }, { fast_length, slow_length, signal_length }) => {
    const start = rawIndicators.macd_hist_divergence.start([
      fast_length,
      slow_length,
      signal_length,
    ]);
    const result = rawIndicators.macd_hist_divergence.indicator(
      [high, low, close],
      [fast_length, slow_length, signal_length],
    );
    return { bull: unshift(result[0], start), bear: unshift(result[1], start) };
  }) as IndicatorFn<typeof schemas.macd_hist_divergence>,
  mobo_band: (({ high, low }, { dpo_length, mobo_length, num_dev_down, num_dev_up }) => {
    const start = rawIndicators.mobo_band.start([
      dpo_length,
      mobo_length,
      num_dev_down,
      num_dev_up,
    ]);
    const result = rawIndicators.mobo_band.indicator(
      [high, low],
      [dpo_length, mobo_length, num_dev_down, num_dev_up],
    );
    return { buy_sell_signal: unshift(result[0], start) };
  }) as IndicatorFn<typeof schemas.mobo_band>,
  qqe_mod: ((
    { close },
    {
      rsi_length_one,
      rsi_smoothing_one,
      qqe_factor_one,
      threshold_one,
      rsi_length_two,
      rsi_smoothing_two,
      qqe_factor_two,
      threshold_two,
      bollinger_length,
      qqe_multiplier,
    },
  ) => {
    const start = rawIndicators.qqe_mod.start([
      rsi_length_one,
      rsi_smoothing_one,
      qqe_factor_one,
      threshold_one,
      rsi_length_two,
      rsi_smoothing_two,
      qqe_factor_two,
      threshold_two,
      bollinger_length,
      qqe_multiplier,
    ]);
    const result = rawIndicators.qqe_mod.indicator(
      [close],
      [
        rsi_length_one,
        rsi_smoothing_one,
        qqe_factor_one,
        threshold_one,
        rsi_length_two,
        rsi_smoothing_two,
        qqe_factor_two,
        threshold_two,
        bollinger_length,
        qqe_multiplier,
      ],
    );
    return {
      bar_color_one: unshift(result[0], start),
      bar_color_two: unshift(result[1], start),
    };
  }) as IndicatorFn<typeof schemas.qqe_mod>,
  rsi_divergence: (({ high, low, close }, { left_bar, right_bar, rsi_length }) => {
    const start = rawIndicators.rsi_divergence.start([left_bar, right_bar, rsi_length]);
    const result = rawIndicators.rsi_divergence.indicator(
      [high, low, close],
      [left_bar, right_bar, rsi_length],
    );
    return { bull: unshift(result[0], start), bear: unshift(result[1], start) };
  }) as IndicatorFn<typeof schemas.rsi_divergence>,
  rvi: (({ close }, { std_length, ema_length }) => {
    const start = rawIndicators.rvi.start([std_length, ema_length]);
    const result = rawIndicators.rvi.indicator([close], [std_length, ema_length]);
    return { rvi: unshift(result[0], start) };
  }) as IndicatorFn<typeof schemas.rvi>,
  rvi_divergence: (({ high, low, close }, { left_bar, right_bar, std_length, ema_length }) => {
    const start = rawIndicators.rvi_divergence.start([left_bar, right_bar, std_length, ema_length]);
    const result = rawIndicators.rvi_divergence.indicator(
      [high, low, close],
      [left_bar, right_bar, std_length, ema_length],
    );
    return { bull: unshift(result[0], start), bear: unshift(result[1], start) };
  }) as IndicatorFn<typeof schemas.rvi_divergence>,
  ssl: (({ high, low, close }, { ma_length, ssl3_length }) => {
    const start = rawIndicators.ssl.start([ma_length, ssl3_length]);
    const result = rawIndicators.ssl.indicator([high, low, close], [ma_length, ssl3_length]);
    return {
      bbmc: unshift(result[0], start),
      bar_color: unshift(result[1], start),
      up_erk: unshift(result[2], start),
      low_erk: unshift(result[3], start),
      cross_long: unshift(result[4], start),
      cross_short: unshift(result[5], start),
    };
  }) as IndicatorFn<typeof schemas.ssl>,
  stc: (({ close }, { length, fast_length, slow_length, aaa }) => {
    const start = rawIndicators.stc.start([length, fast_length, slow_length, aaa]);
    const result = rawIndicators.stc.indicator([close], [length, fast_length, slow_length, aaa]);
    return {
      stc: unshift(result[0], start),
      bar_color: unshift(result[1], start),
    };
  }) as IndicatorFn<typeof schemas.stc>,
  stoch_divergence: ((
    { high, low, close },
    { left_bar, right_bar, stk_length, smooth_length, sma_length },
  ) => {
    const start = rawIndicators.stoch_divergence.start([
      left_bar,
      right_bar,
      stk_length,
      smooth_length,
      sma_length,
    ]);
    const result = rawIndicators.stoch_divergence.indicator(
      [high, low, close],
      [left_bar, right_bar, stk_length, smooth_length, sma_length],
    );
    return { bull: unshift(result[0], start), bear: unshift(result[1], start) };
  }) as IndicatorFn<typeof schemas.stoch_divergence>,
  sup_and_res: (({ close }, { left_bar, right_bar_one, right_bar_two, hma_length }) => {
    const start = rawIndicators.sup_and_res.start([
      left_bar,
      right_bar_one,
      right_bar_two,
      hma_length,
    ]);
    const result = rawIndicators.sup_and_res.indicator(
      [close],
      [left_bar, right_bar_one, right_bar_two, hma_length],
    );
    return {
      buy_one: unshift(result[0], start),
      buy_two: unshift(result[1], start),
      buy_three: unshift(result[2], start),
      buy_four: unshift(result[3], start),
      buy_five: unshift(result[4], start),
      buy_six: unshift(result[5], start),
      buy_seven: unshift(result[6], start),
      buy_eight: unshift(result[7], start),
      sell_one: unshift(result[8], start),
      sell_two: unshift(result[9], start),
      sell_three: unshift(result[10], start),
      sell_four: unshift(result[11], start),
      sell_five: unshift(result[12], start),
      sell_six: unshift(result[13], start),
      sell_seven: unshift(result[14], start),
      sell_eight: unshift(result[15], start),
    };
  }) as IndicatorFn<typeof schemas.sup_and_res>,
  ut_bot: (({ high, low, close }, { atr_period, sensitivity }) => {
    const start = rawIndicators.ut_bot.start([atr_period, sensitivity]);
    const result = rawIndicators.ut_bot.indicator([high, low, close], [atr_period, sensitivity]);
    return { buy_sell_signal: unshift(result[0], start) };
  }) as IndicatorFn<typeof schemas.ut_bot>,
  volatility_oscillator: (({ open, close }, { length }) => {
    const start = rawIndicators.volatility_oscillator.start([length]);
    const result = rawIndicators.volatility_oscillator.indicator([open, close], [length]);
    return {
      spike_line: unshift(result[0], start),
      upper_line: unshift(result[1], start),
      lower_line: unshift(result[2], start),
    };
  }) as IndicatorFn<typeof schemas.volatility_oscillator>,
  vu_man_chu_swing: (({ close }, { swing_period, swing_multiplier }) => {
    const start = rawIndicators.vu_man_chu_swing.start([swing_period, swing_multiplier]);
    const result = rawIndicators.vu_man_chu_swing.indicator(
      [close],
      [swing_period, swing_multiplier],
    );
    return {
      buy_sell_signal_long: unshift(result[0], start),
      buy_sell_signal_short: unshift(result[1], start),
    };
  }) as IndicatorFn<typeof schemas.vu_man_chu_swing>,
  waddah: ((
    { close },
    { fast_length, slow_length, signal_length, bb_length, multiplier, sensitivity },
  ) => {
    const start = rawIndicators.waddah.start([
      fast_length,
      slow_length,
      signal_length,
      bb_length,
      multiplier,
      sensitivity,
    ]);
    const result = rawIndicators.waddah.indicator(
      [close],
      [fast_length, slow_length, signal_length, bb_length, multiplier, sensitivity],
    );
    return {
      t: unshift(result[0], start),
      e: unshift(result[1], start),
      trend_up: unshift(result[2], start),
      trend_down: unshift(result[3], start),
    };
  }) as IndicatorFn<typeof schemas.waddah>,
  psar: (({ high, low, close }, { accel_start, accel_step, accel_max }) => {
    const start = rawIndicators.psar.start([accel_start, accel_step, accel_max]);
    const result = rawIndicators.psar.indicator(
      [high, low, close],
      [accel_start, accel_step, accel_max],
    );
    return { psar: unshift(result[0], start) };
  }) as IndicatorFn<typeof schemas.psar>,
  dx: (({ high, low }, { period }) => {
    const start = rawIndicators.dx.start([period]);
    const result = rawIndicators.dx.indicator([high, low], [period]);
    return { dx: unshift(result[0], start) };
  }) as IndicatorFn<typeof schemas.dx>,
  adx: (({ high, low }, { period }) => {
    const start = rawIndicators.adx.start([period]);
    const result = rawIndicators.adx.indicator([high, low], [period]);
    return { adx: unshift(result[0], start) };
  }) as IndicatorFn<typeof schemas.adx>,
  dema: (({ value }, { period }) => {
    const start = rawIndicators.dema.start([period]);
    const result = rawIndicators.dema.indicator([value], [period]);
    return { dema: unshift(result[0], start) };
  }) as IndicatorFn<typeof schemas.dema>,
  ema: (({ value }, { period }) => {
    const start = rawIndicators.ema.start([period]);
    const result = rawIndicators.ema.indicator([value], [period]);
    return { ema: unshift(result[0], start) };
  }) as IndicatorFn<typeof schemas.ema>,
  hma: (({ value }, { period }) => {
    const start = rawIndicators.hma.start([period]);
    const result = rawIndicators.hma.indicator([value], [period]);
    return { hma: unshift(result[0], start) };
  }) as IndicatorFn<typeof schemas.hma>,
  sma: (({ value }, { period }) => {
    const start = rawIndicators.sma.start([period]);
    const result = rawIndicators.sma.indicator([value], [period]);
    return { sma: unshift(result[0], start) };
  }) as IndicatorFn<typeof schemas.sma>,
  tema: (({ value }, { period }) => {
    const start = rawIndicators.tema.start([period]);
    const result = rawIndicators.tema.indicator([value], [period]);
    return { tema: unshift(result[0], start) };
  }) as IndicatorFn<typeof schemas.tema>,
  trima: (({ value }, { period }) => {
    const start = rawIndicators.trima.start([period]);
    const result = rawIndicators.trima.indicator([value], [period]);
    return { trima: unshift(result[0], start) };
  }) as IndicatorFn<typeof schemas.trima>,
  vwma: (({ close, volume }, { period }) => {
    const start = rawIndicators.vwma.start([period]);
    const result = rawIndicators.vwma.indicator([close, volume], [period]);
    return { vwma: unshift(result[0], start) };
  }) as IndicatorFn<typeof schemas.vwma>,
  wma: (({ value }, { period }) => {
    const start = rawIndicators.wma.start([period]);
    const result = rawIndicators.wma.indicator([value], [period]);
    return { wma: unshift(result[0], start) };
  }) as IndicatorFn<typeof schemas.wma>,
  linreg: (({ value }, { period }) => {
    const start = rawIndicators.linreg.start([period]);
    const result = rawIndicators.linreg.indicator([value], [period]);
    return { linreg: unshift(result[0], start) };
  }) as IndicatorFn<typeof schemas.linreg>,
  bbands: (({ value }, { period, stddev }) => {
    const start = rawIndicators.bbands.start([period, stddev]);
    const result = rawIndicators.bbands.indicator([value], [period, stddev]);
    return {
      bbands_lower: unshift(result[0], start),
      bbands_middle: unshift(result[1], start),
      bbands_upper: unshift(result[2], start),
    };
  }) as IndicatorFn<typeof schemas.bbands>,
  cci: (({ high, low, close }, { period }) => {
    const start = rawIndicators.cci.start([period]);
    const result = rawIndicators.cci.indicator([high, low, close], [period]);
    return { cci: unshift(result[0], start) };
  }) as IndicatorFn<typeof schemas.cci>,
  stoch: (({ high, low, close }, { k_period, k_slowing_period, d_period }) => {
    const start = rawIndicators.stoch.start([k_period, k_slowing_period, d_period]);
    const result = rawIndicators.stoch.indicator(
      [high, low, close],
      [k_period, k_slowing_period, d_period],
    );
    return {
      stoch_k: unshift(result[0], start),
      stoch_d: unshift(result[1], start),
    };
  }) as IndicatorFn<typeof schemas.stoch>,
  mfi: (({ high, low, close, volume }, { period }) => {
    const start = rawIndicators.mfi.start([period]);
    const result = rawIndicators.mfi.indicator([high, low, close, volume], [period]);
    return { mfi: unshift(result[0], start) };
  }) as IndicatorFn<typeof schemas.mfi>,
  macd: (({ value }, { short_period, long_period, signal_period }) => {
    const start = rawIndicators.macd.start([short_period, long_period, signal_period]);
    const result = rawIndicators.macd.indicator(
      [value],
      [short_period, long_period, signal_period],
    );
    return {
      macd: unshift(result[0], start),
      macd_signal: unshift(result[1], start),
      macd_histogram: unshift(result[2], start),
    };
  }) as IndicatorFn<typeof schemas.macd>,
  rsi: (({ value }, { period }) => {
    const start = rawIndicators.rsi.start([period]);
    const result = rawIndicators.rsi.indicator([value], [period]);
    return { rsi: unshift(result[0], start) };
  }) as IndicatorFn<typeof schemas.rsi>,
  natr: (({ high, low, close }, { period }) => {
    const start = rawIndicators.natr.start([period]);
    const result = rawIndicators.natr.indicator([high, low, close], [period]);
    return { natr: unshift(result[0], start) };
  }) as IndicatorFn<typeof schemas.natr>,
  atr: (({ high, low, close }, { period }) => {
    const start = rawIndicators.atr.start([period]);
    const result = rawIndicators.atr.indicator([high, low, close], [period]);
    return { atr: unshift(result[0], start) };
  }) as IndicatorFn<typeof schemas.atr>,
  insidebar: (({ open, high, low, close }, {}) => {
    const start = rawIndicators.insidebar.start([]);
    const result = rawIndicators.insidebar.indicator([open, high, low, close], []);
    return { buy_sell_signal: unshift(result[0], start) };
  }) as IndicatorFn<typeof schemas.insidebar>,
  price: (({ value }, {}) => {
    const start = rawIndicators.price.start([]);
    const result = rawIndicators.price.indicator([value], []);
    return { price: unshift(result[0], start) };
  }) as IndicatorFn<typeof schemas.price>,
};
