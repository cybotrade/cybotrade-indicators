/* eslint-disable no-empty-pattern */
// Path: public.ts
// This code is generated, please do not edit it manually.
import { z } from 'zod';

import { type Static, Type } from '@cybotrade/core';

export enum BuySellSignal {
  Nothing = 0,
  Buy = 1,
  Sell = -1,
}

export enum BuySignal {
  Nothing = 0,
  Buy = 1,
  DontBuy = -1,
}

export enum SellSignal {
  Nothing = 0,
  Sell = 1,
  DontSell = -1,
}

export enum DirectionSignal {
  Nothing = 0,
  Up = 1,
  Down = -1,
}

export enum BarColor {
  Nothing = 0,
  Green = 1,
  Red = -1,
}

export enum HeatmapLevel {
  Low = 0,
  Normal = 1,
  Medium = 2,
  High = 3,
  ExtraHigh = 4,
}

export enum BullSignal {
  Nothing = 0,
  Bull = 1,
}

export enum BearSignal {
  Nothing = 0,
  Bear = -1,
}

export enum CrossSignal {
  Nothing = 0,
  Cross = 1,
}

export enum Comparator {
  GreaterThan = 'GT',
  GreaterThanEqual = 'GTE',
  LesserThan = 'LT',
  LesserThanEqual = 'LTE',
  Equal = 'EQ',
}

export enum SignalComparator {
  Equal = 'EQ',
}

export const IndicatorSchemas = {
  chaikin_vol: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_CHAIKIN_VOL'),
      comparator: Type.Object({
        cvi: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Number(),
        }),
      }),
      params: Type.Object({
        ema_period: Type.Number({ default: 7, minimum: 1 }),
        roc_period: Type.Number({ default: 14, minimum: 1 }),
      }),
    }),
  }),
  stoch_rsi: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_STOCH_RSI'),
      comparator: Type.Object({
        stoch_k: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Number(),
        }),
        stoch_d: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Number(),
        }),
      }),
      params: Type.Object({
        smoothk: Type.Number({ default: 3 }),
        smoothd: Type.Number({ default: 3 }),
        rsi_period: Type.Number({ default: 14, minimum: 1 }),
        stoch_period: Type.Number({ default: 14, minimum: 1 }),
      }),
    }),
  }),
  supertrend: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_SUPERTREND'),
      comparator: Type.Object({
        supertrend: Type.Optional(
          Type.Object({
            comparator: Type.Enum(Comparator),
            value: Type.Union([
              Type.Literal('OPEN'),
              Type.Literal('HIGH'),
              Type.Literal('LOW'),
              Type.Literal('CLOSE'),
            ]),
          }),
        ),
        direction: Type.Optional(
          Type.Object({
            comparator: Type.Enum(SignalComparator),
            value: Type.Enum(DirectionSignal),
          }),
        ),
        bar_color: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BarColor),
        }),
        buy_sell_signal: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BuySellSignal),
        }),
      }),
      params: Type.Object({
        period: Type.Number({ default: 34, minimum: 1 }),
        factor: Type.Number({ default: 3 }),
      }),
    }),
  }),
  wavetrend: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_WAVETREND'),
      comparator: Type.Object({
        wavetrend_one: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Number(),
        }),
        wavetrend_two: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Number(),
        }),
      }),
      params: Type.Object({
        period_one: Type.Number({ default: 9, minimum: 1 }),
        period_two: Type.Number({ default: 12, minimum: 1 }),
      }),
    }),
  }),
  andean_osc: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_ANDEAN_OSC'),
      comparator: Type.Object({
        bull_data: Type.Optional(
          Type.Object({
            comparator: Type.Enum(Comparator),
            value: Type.Number(),
          }),
        ),
        bear_data: Type.Optional(
          Type.Object({
            comparator: Type.Enum(Comparator),
            value: Type.Number(),
          }),
        ),
        ao_data: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Number(),
        }),
      }),
      params: Type.Object({
        period: Type.Number({ default: 50, minimum: 1 }),
        signal_length: Type.Number({ default: 9, minimum: 1 }),
      }),
    }),
  }),
  braid_filter: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_BRAID_FILTER'),
      comparator: Type.Object({
        dif: Type.Optional(
          Type.Object({
            comparator: Type.Enum(Comparator),
            value: Type.Number(),
          }),
        ),
        atr_filter: Type.Optional(
          Type.Object({
            comparator: Type.Enum(Comparator),
            value: Type.Number(),
          }),
        ),
        bar_color: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BarColor),
        }),
      }),
      params: Type.Object({
        ma01_length: Type.Number({ default: 3, minimum: 1 }),
        ma02_length: Type.Number({ default: 7, minimum: 1 }),
        ma03_length: Type.Number({ default: 14, minimum: 1 }),
        pips_min_sep_percent: Type.Number({ default: 40 }),
      }),
    }),
  }),
  boom_pro: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_BOOM_PRO'),
      comparator: Type.Object({
        trigger: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Union([
            Type.Literal('OPEN'),
            Type.Literal('HIGH'),
            Type.Literal('LOW'),
            Type.Literal('CLOSE'),
          ]),
        }),
        q4: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Union([
            Type.Literal('OPEN'),
            Type.Literal('HIGH'),
            Type.Literal('LOW'),
            Type.Literal('CLOSE'),
          ]),
        }),
      }),
      params: Type.Object({
        lp_period_one: Type.Number({ default: 6, minimum: 1 }),
        k1_quotient: Type.Number({ default: 0 }),
        trig_no: Type.Number({ default: 2 }),
        lp_period_two: Type.Number({ default: 27, minimum: 1 }),
        k22_eot: Type.Number({ default: 0.3 }),
      }),
    }),
  }),
  chandelier_exit: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_CHANDELIER_EXIT'),
      comparator: Type.Object({
        buy_sell_signal: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BuySellSignal),
        }),
      }),
      params: Type.Object({
        period: Type.Number({ default: 22, minimum: 1 }),
        atr_multiplier: Type.Number({ default: 3 }),
      }),
    }),
  }),
  cm_ema_trendbars: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_CM_EMA_TRENDBARS'),
      comparator: Type.Object({
        usdema: Type.Optional(
          Type.Object({
            comparator: Type.Enum(Comparator),
            value: Type.Union([
              Type.Literal('OPEN'),
              Type.Literal('HIGH'),
              Type.Literal('LOW'),
              Type.Literal('CLOSE'),
            ]),
          }),
        ),
        bar_color: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BarColor),
        }),
      }),
      params: Type.Object({
        ema_length: Type.Number({ default: 34, minimum: 1 }),
      }),
    }),
  }),
  di_dx: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_DI_DX'),
      comparator: Type.Object({
        dx: Type.Optional(
          Type.Object({
            comparator: Type.Enum(Comparator),
            value: Type.Number(),
          }),
        ),
        di_plus: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Number(),
        }),
        di_minus: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Number(),
        }),
      }),
      params: Type.Object({
        period: Type.Number({ default: 14, minimum: 1 }),
      }),
    }),
  }),
  half_trend: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_HALF_TREND'),
      comparator: Type.Object({
        ht: Type.Optional(
          Type.Object({
            comparator: Type.Enum(Comparator),
            value: Type.Union([
              Type.Literal('OPEN'),
              Type.Literal('HIGH'),
              Type.Literal('LOW'),
              Type.Literal('CLOSE'),
            ]),
          }),
        ),
        bar_color: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BarColor),
        }),
      }),
      params: Type.Object({
        amplitude: Type.Number({ default: 2 }),
        channel_deviation: Type.Number({ default: 2 }),
        atr_length: Type.Number({ default: 100, minimum: 1 }),
      }),
    }),
  }),
  heatmap_vol: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_HEATMAP_VOL'),
      comparator: Type.Object({
        heatmap_level: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(HeatmapLevel),
        }),
      }),
      params: Type.Object({
        length: Type.Number({ default: 610, minimum: 1 }),
        std_length: Type.Number({ default: 610, minimum: 1 }),
        threshold_extra_high: Type.Number({ default: 4 }),
        threshold_high: Type.Number({ default: 2.5 }),
        threshold_medium: Type.Number({ default: 1 }),
        threshold_normal: Type.Number({ default: -0.5 }),
      }),
    }),
  }),
  hull_suite: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_HULL_SUITE'),
      comparator: Type.Object({
        bar_color: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BarColor),
        }),
      }),
      params: Type.Object({
        hma_length: Type.Number({ default: 55, minimum: 1 }),
      }),
    }),
  }),
  macd_fastline_divergence: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_MACD_FASTLINE_DIVERGENCE'),
      comparator: Type.Object({
        bull: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BullSignal),
        }),
        bear: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BearSignal),
        }),
      }),
      params: Type.Object({
        fast_length: Type.Number({ default: 12, minimum: 1 }),
        slow_length: Type.Number({ default: 26, minimum: 1 }),
        signal_length: Type.Number({ default: 9, minimum: 1 }),
      }),
    }),
  }),
  macd_hist_divergence: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_MACD_HIST_DIVERGENCE'),
      comparator: Type.Object({
        bull: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BullSignal),
        }),
        bear: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BearSignal),
        }),
      }),
      params: Type.Object({
        fast_length: Type.Number({ default: 12, minimum: 1 }),
        slow_length: Type.Number({ default: 26, minimum: 1 }),
        signal_length: Type.Number({ default: 9, minimum: 1 }),
      }),
    }),
  }),
  mobo_band: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_MOBO_BAND'),
      comparator: Type.Object({
        buy_sell_signal: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BuySellSignal),
        }),
      }),
      params: Type.Object({
        dpo_length: Type.Number({ default: 13, minimum: 1 }),
        mobo_length: Type.Number({ default: 10, minimum: 1 }),
        num_dev_down: Type.Number({ default: -0.8 }),
        num_dev_up: Type.Number({ default: 0.8 }),
      }),
    }),
  }),
  qqe_mod: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_QQE_MOD'),
      comparator: Type.Object({
        bar_color_one: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BarColor),
        }),
        bar_color_two: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BarColor),
        }),
      }),
      params: Type.Object({
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
    }),
  }),
  rsi_divergence: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_RSI_DIVERGENCE'),
      comparator: Type.Object({
        bull: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BullSignal),
        }),
        bear: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BearSignal),
        }),
      }),
      params: Type.Object({
        left_bar: Type.Number({ default: 6 }),
        right_bar: Type.Number({ default: 2 }),
        rsi_length: Type.Number({ default: 14, minimum: 1 }),
      }),
    }),
  }),
  rvi: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_RVI'),
      comparator: Type.Object({
        rvi: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Number(),
        }),
      }),
      params: Type.Object({
        std_length: Type.Number({ default: 10, minimum: 1 }),
        ema_length: Type.Number({ default: 14, minimum: 1 }),
      }),
    }),
  }),
  rvi_divergence: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_RVI_DIVERGENCE'),
      comparator: Type.Object({
        bull: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BullSignal),
        }),
        bear: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BearSignal),
        }),
      }),
      params: Type.Object({
        left_bar: Type.Number({ default: 6 }),
        right_bar: Type.Number({ default: 2 }),
        std_length: Type.Number({ default: 12, minimum: 1 }),
        ema_length: Type.Number({ default: 14, minimum: 1 }),
      }),
    }),
  }),
  ssl: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_SSL'),
      comparator: Type.Object({
        bbmc: Type.Optional(
          Type.Object({
            comparator: Type.Enum(Comparator),
            value: Type.Union([
              Type.Literal('OPEN'),
              Type.Literal('HIGH'),
              Type.Literal('LOW'),
              Type.Literal('CLOSE'),
            ]),
          }),
        ),
        bar_color: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BarColor),
        }),
        up_erk: Type.Optional(
          Type.Object({
            comparator: Type.Enum(Comparator),
            value: Type.Union([
              Type.Literal('OPEN'),
              Type.Literal('HIGH'),
              Type.Literal('LOW'),
              Type.Literal('CLOSE'),
            ]),
          }),
        ),
        low_erk: Type.Optional(
          Type.Object({
            comparator: Type.Enum(Comparator),
            value: Type.Union([
              Type.Literal('OPEN'),
              Type.Literal('HIGH'),
              Type.Literal('LOW'),
              Type.Literal('CLOSE'),
            ]),
          }),
        ),
        cross_long: Type.Optional(
          Type.Object({
            comparator: Type.Enum(SignalComparator),
            value: Type.Enum(CrossSignal),
          }),
        ),
        cross_short: Type.Optional(
          Type.Object({
            comparator: Type.Enum(SignalComparator),
            value: Type.Enum(CrossSignal),
          }),
        ),
      }),
      params: Type.Object({
        ma_length: Type.Number({ default: 60, minimum: 1 }),
        ssl3_length: Type.Number({ default: 15, minimum: 1 }),
      }),
    }),
  }),
  stc: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_STC'),
      comparator: Type.Object({
        stc: Type.Optional(
          Type.Object({
            comparator: Type.Enum(Comparator),
            value: Type.Number(),
          }),
        ),
        bar_color: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BarColor),
        }),
      }),
      params: Type.Object({
        length: Type.Number({ default: 12, minimum: 1 }),
        fast_length: Type.Number({ default: 26, minimum: 1 }),
        slow_length: Type.Number({ default: 50, minimum: 1 }),
        aaa: Type.Number({ default: 0.5 }),
      }),
    }),
  }),
  stoch_divergence: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_STOCH_DIVERGENCE'),
      comparator: Type.Object({
        bull: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BullSignal),
        }),
        bear: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BearSignal),
        }),
      }),
      params: Type.Object({
        left_bar: Type.Number({ default: 6 }),
        right_bar: Type.Number({ default: 2 }),
        stk_length: Type.Number({ default: 14, minimum: 1 }),
        smooth_length: Type.Number({ default: 3, minimum: 1 }),
        sma_length: Type.Number({ default: 3, minimum: 1 }),
      }),
    }),
  }),
  sup_and_res: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_SUP_AND_RES'),
      comparator: Type.Object({
        buy_one: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BuySignal),
        }),
        buy_two: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BuySignal),
        }),
        buy_three: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BuySignal),
        }),
        buy_four: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BuySignal),
        }),
        buy_five: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BuySignal),
        }),
        buy_six: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BuySignal),
        }),
        buy_seven: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BuySignal),
        }),
        buy_eight: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BuySignal),
        }),
        sell_one: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(SellSignal),
        }),
        sell_two: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(SellSignal),
        }),
        sell_three: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(SellSignal),
        }),
        sell_four: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(SellSignal),
        }),
        sell_five: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(SellSignal),
        }),
        sell_six: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(SellSignal),
        }),
        sell_seven: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(SellSignal),
        }),
        sell_eight: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(SellSignal),
        }),
      }),
      params: Type.Object({
        left_bar: Type.Number({ default: 200 }),
        right_bar_one: Type.Number({ default: 20 }),
        right_bar_two: Type.Number({ default: 5 }),
        hma_length: Type.Number({ default: 9, minimum: 1 }),
      }),
    }),
  }),
  ut_bot: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_UT_BOT'),
      comparator: Type.Object({
        buy_sell_signal: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BuySellSignal),
        }),
      }),
      params: Type.Object({
        atr_period: Type.Number({ default: 10, minimum: 1 }),
        sensitivity: Type.Number({ default: 1 }),
      }),
    }),
  }),
  volatility_oscillator: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_VOLATILITY_OSCILLATOR'),
      comparator: Type.Object({
        spike_line: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Number(),
        }),
        upper_line: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Number(),
        }),
        lower_line: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Number(),
        }),
      }),
      params: Type.Object({
        length: Type.Number({ default: 100, minimum: 1 }),
      }),
    }),
  }),
  vu_man_chu_swing: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_VU_MAN_CHU_SWING'),
      comparator: Type.Object({
        buy_sell_signal_long: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BuySellSignal),
        }),
        buy_sell_signal_short: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BuySellSignal),
        }),
      }),
      params: Type.Object({
        swing_period: Type.Number({ default: 20, minimum: 1 }),
        swing_multiplier: Type.Number({ default: 3.5 }),
      }),
    }),
  }),
  waddah: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_WADDAH'),
      comparator: Type.Object({
        t: Type.Optional(
          Type.Object({
            comparator: Type.Enum(Comparator),
            value: Type.Number(),
          }),
        ),
        e: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Number(),
        }),
        trend_up: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Number(),
        }),
        trend_down: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Number(),
        }),
      }),
      params: Type.Object({
        fast_length: Type.Number({ default: 20, minimum: 1 }),
        slow_length: Type.Number({ default: 40, minimum: 1 }),
        signal_length: Type.Number({ default: 9, minimum: 1 }),
        bb_length: Type.Number({ default: 20, minimum: 1 }),
        multiplier: Type.Number({ default: 2 }),
        sensitivity: Type.Number({ default: 150 }),
      }),
    }),
  }),
  psar: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_PSAR'),
      comparator: Type.Object({
        psar: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Union([
            Type.Literal('OPEN'),
            Type.Literal('HIGH'),
            Type.Literal('LOW'),
            Type.Literal('CLOSE'),
          ]),
        }),
      }),
      params: Type.Object({
        accel_start: Type.Number({ default: 0.02 }),
        accel_step: Type.Number({ default: 0.02 }),
        accel_max: Type.Number({ default: 0.2 }),
      }),
    }),
  }),
  dx: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_DX'),
      comparator: Type.Object({
        dx: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Number(),
        }),
      }),
      params: Type.Object({
        period: Type.Number({ default: 14, minimum: 1 }),
      }),
    }),
  }),
  adx: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_ADX'),
      comparator: Type.Object({
        adx: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Number(),
        }),
      }),
      params: Type.Object({
        period: Type.Number({ default: 14, minimum: 1 }),
      }),
    }),
  }),
  dema: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_DEMA'),
      comparator: Type.Object({
        dema: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Union([
            Type.Literal('OPEN'),
            Type.Literal('HIGH'),
            Type.Literal('LOW'),
            Type.Literal('CLOSE'),
            Type.Literal('VOLUME'),
          ]),
        }),
      }),
      params: Type.Object({
        period: Type.Number({ default: 9, minimum: 1 }),
      }),
    }),
  }),
  ema: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_EMA'),
      comparator: Type.Object({
        ema: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Union([
            Type.Literal('OPEN'),
            Type.Literal('HIGH'),
            Type.Literal('LOW'),
            Type.Literal('CLOSE'),
            Type.Literal('VOLUME'),
          ]),
        }),
      }),
      params: Type.Object({
        period: Type.Number({ default: 9, minimum: 1 }),
      }),
    }),
  }),
  hma: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_HMA'),
      comparator: Type.Object({
        hma: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Union([
            Type.Literal('OPEN'),
            Type.Literal('HIGH'),
            Type.Literal('LOW'),
            Type.Literal('CLOSE'),
            Type.Literal('VOLUME'),
          ]),
        }),
      }),
      params: Type.Object({
        period: Type.Number({ default: 9, minimum: 1 }),
      }),
    }),
  }),
  sma: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_SMA'),
      comparator: Type.Object({
        sma: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Union([
            Type.Literal('OPEN'),
            Type.Literal('HIGH'),
            Type.Literal('LOW'),
            Type.Literal('CLOSE'),
            Type.Literal('VOLUME'),
          ]),
        }),
      }),
      params: Type.Object({
        period: Type.Number({ default: 7, minimum: 1 }),
      }),
    }),
  }),
  tema: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_TEMA'),
      comparator: Type.Object({
        tema: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Union([
            Type.Literal('OPEN'),
            Type.Literal('HIGH'),
            Type.Literal('LOW'),
            Type.Literal('CLOSE'),
            Type.Literal('VOLUME'),
          ]),
        }),
      }),
      params: Type.Object({
        period: Type.Number({ default: 9, minimum: 1 }),
      }),
    }),
  }),
  trima: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_TRIMA'),
      comparator: Type.Object({
        trima: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Union([
            Type.Literal('OPEN'),
            Type.Literal('HIGH'),
            Type.Literal('LOW'),
            Type.Literal('CLOSE'),
            Type.Literal('VOLUME'),
          ]),
        }),
      }),
      params: Type.Object({
        period: Type.Number({ default: 20, minimum: 1 }),
      }),
    }),
  }),
  vwma: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_VWMA'),
      comparator: Type.Object({
        vwma: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Union([Type.Literal('VOLUME')]),
        }),
      }),
      params: Type.Object({
        period: Type.Number({ default: 20, minimum: 1 }),
      }),
    }),
  }),
  wma: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_WMA'),
      comparator: Type.Object({
        wma: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Union([
            Type.Literal('OPEN'),
            Type.Literal('HIGH'),
            Type.Literal('LOW'),
            Type.Literal('CLOSE'),
            Type.Literal('VOLUME'),
          ]),
        }),
      }),
      params: Type.Object({
        period: Type.Number({ default: 9, minimum: 1 }),
      }),
    }),
  }),
  linreg: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_LINREG'),
      comparator: Type.Object({
        linreg: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Union([
            Type.Literal('OPEN'),
            Type.Literal('HIGH'),
            Type.Literal('LOW'),
            Type.Literal('CLOSE'),
            Type.Literal('VOLUME'),
          ]),
        }),
      }),
      params: Type.Object({
        period: Type.Number({ default: 100, minimum: 1 }),
      }),
    }),
  }),
  bbands: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_BBANDS'),
      comparator: Type.Object({
        bbands_lower: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Union([
            Type.Literal('OPEN'),
            Type.Literal('HIGH'),
            Type.Literal('LOW'),
            Type.Literal('CLOSE'),
            Type.Literal('VOLUME'),
          ]),
        }),
        bbands_middle: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Union([
            Type.Literal('OPEN'),
            Type.Literal('HIGH'),
            Type.Literal('LOW'),
            Type.Literal('CLOSE'),
            Type.Literal('VOLUME'),
          ]),
        }),
        bbands_upper: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Union([
            Type.Literal('OPEN'),
            Type.Literal('HIGH'),
            Type.Literal('LOW'),
            Type.Literal('CLOSE'),
            Type.Literal('VOLUME'),
          ]),
        }),
      }),
      params: Type.Object({
        period: Type.Number({ default: 20, minimum: 1 }),
        stddev: Type.Number({ default: 2 }),
      }),
    }),
  }),
  cci: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_CCI'),
      comparator: Type.Object({
        cci: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Number(),
        }),
      }),
      params: Type.Object({
        period: Type.Number({ default: 20, minimum: 1 }),
      }),
    }),
  }),
  stoch: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_STOCH'),
      comparator: Type.Object({
        stoch_k: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Number(),
        }),
        stoch_d: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Number(),
        }),
      }),
      params: Type.Object({
        k_period: Type.Number({ default: 14, minimum: 1 }),
        k_slowing_period: Type.Number({ default: 1, minimum: 1 }),
        d_period: Type.Number({ default: 3, minimum: 1 }),
      }),
    }),
  }),
  mfi: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_MFI'),
      comparator: Type.Object({
        mfi: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Number(),
        }),
      }),
      params: Type.Object({
        period: Type.Number({ default: 14, minimum: 1 }),
      }),
    }),
  }),
  macd: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_MACD'),
      comparator: Type.Object({
        macd: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Number(),
        }),
        macd_signal: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Number(),
        }),
        macd_histogram: Type.Optional(
          Type.Object({
            comparator: Type.Enum(Comparator),
            value: Type.Number(),
          }),
        ),
      }),
      params: Type.Object({
        short_period: Type.Number({ default: 12, minimum: 1 }),
        long_period: Type.Number({ default: 26, minimum: 1 }),
        signal_period: Type.Number({ default: 9, minimum: 1 }),
      }),
    }),
  }),
  rsi: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_RSI'),
      comparator: Type.Object({
        rsi: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Number(),
        }),
      }),
      params: Type.Object({
        period: Type.Number({ default: 14, minimum: 1 }),
      }),
    }),
  }),
  natr: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_NATR'),
      comparator: Type.Object({
        natr: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Number(),
        }),
      }),
      params: Type.Object({
        period: Type.Number({ default: 14, minimum: 1 }),
      }),
    }),
  }),
  atr: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_ATR'),
      comparator: Type.Object({
        atr: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Number(),
        }),
      }),
      params: Type.Object({
        period: Type.Number({ default: 14, minimum: 1 }),
      }),
    }),
  }),
  insidebar: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_INSIDEBAR'),
      comparator: Type.Object({
        buy_sell_signal: Type.Object({
          comparator: Type.Enum(SignalComparator),
          value: Type.Enum(BuySellSignal),
        }),
      }),
      params: Type.Object({}),
    }),
  }),
  price: Type.Object({
    type: Type.Literal('INDICATOR_NODE'),
    id: Type.String(),
    data: Type.Object({
      indicator_type: Type.Literal('INDICATOR_PRICE'),
      comparator: Type.Object({
        price: Type.Object({
          comparator: Type.Enum(Comparator),
          value: Type.Number(),
        }),
      }),
      params: Type.Object({}),
    }),
  }),
};
export const IndicatorSchemasZod = {
  chaikin_vol: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_CHAIKIN_VOL'),
      comparator: z.object({
        cvi: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        ema_period: z.number().min(1).default(7),
        roc_period: z.number().min(1).default(14),
      }),
    }),
  }),
  stoch_rsi: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_STOCH_RSI'),
      comparator: z.object({
        stoch_k: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
        stoch_d: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        smoothk: z.number().default(3),
        smoothd: z.number().default(3),
        rsi_period: z.number().min(1).default(14),
        stoch_period: z.number().min(1).default(14),
      }),
    }),
  }),
  supertrend: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_SUPERTREND'),
      comparator: z.object({
        supertrend: z.optional(
          z.object({
            comparator: z.nativeEnum(Comparator),
            value: z.union([
              z.literal('OPEN'),
              z.literal('HIGH'),
              z.literal('LOW'),
              z.literal('CLOSE'),
            ]),
          }),
        ),
        direction: z.optional(
          z.object({
            comparator: z.nativeEnum(SignalComparator),
            value: z.nativeEnum(DirectionSignal),
          }),
        ),
        bar_color: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BarColor),
        }),
        buy_sell_signal: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySellSignal),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(34),
        factor: z.number().default(3),
      }),
    }),
  }),
  wavetrend: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_WAVETREND'),
      comparator: z.object({
        wavetrend_one: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
        wavetrend_two: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        period_one: z.number().min(1).default(9),
        period_two: z.number().min(1).default(12),
      }),
    }),
  }),
  andean_osc: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_ANDEAN_OSC'),
      comparator: z.object({
        bull_data: z.optional(
          z.object({ comparator: z.nativeEnum(Comparator), value: z.number() }),
        ),
        bear_data: z.optional(
          z.object({ comparator: z.nativeEnum(Comparator), value: z.number() }),
        ),
        ao_data: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(50),
        signal_length: z.number().min(1).default(9),
      }),
    }),
  }),
  braid_filter: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_BRAID_FILTER'),
      comparator: z.object({
        dif: z.optional(z.object({ comparator: z.nativeEnum(Comparator), value: z.number() })),
        atr_filter: z.optional(
          z.object({ comparator: z.nativeEnum(Comparator), value: z.number() }),
        ),
        bar_color: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BarColor),
        }),
      }),
      params: z.object({
        ma01_length: z.number().min(1).default(3),
        ma02_length: z.number().min(1).default(7),
        ma03_length: z.number().min(1).default(14),
        pips_min_sep_percent: z.number().default(40),
      }),
    }),
  }),
  boom_pro: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_BOOM_PRO'),
      comparator: z.object({
        trigger: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
          ]),
        }),
        q4: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
          ]),
        }),
      }),
      params: z.object({
        lp_period_one: z.number().min(1).default(6),
        k1_quotient: z.number().default(0),
        trig_no: z.number().default(2),
        lp_period_two: z.number().min(1).default(27),
        k22_eot: z.number().default(0.3),
      }),
    }),
  }),
  chandelier_exit: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_CHANDELIER_EXIT'),
      comparator: z.object({
        buy_sell_signal: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySellSignal),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(22),
        atr_multiplier: z.number().default(3),
      }),
    }),
  }),
  cm_ema_trendbars: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_CM_EMA_TRENDBARS'),
      comparator: z.object({
        usdema: z.optional(
          z.object({
            comparator: z.nativeEnum(Comparator),
            value: z.union([
              z.literal('OPEN'),
              z.literal('HIGH'),
              z.literal('LOW'),
              z.literal('CLOSE'),
            ]),
          }),
        ),
        bar_color: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BarColor),
        }),
      }),
      params: z.object({
        ema_length: z.number().min(1).default(34),
      }),
    }),
  }),
  di_dx: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_DI_DX'),
      comparator: z.object({
        dx: z.optional(z.object({ comparator: z.nativeEnum(Comparator), value: z.number() })),
        di_plus: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
        di_minus: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(14),
      }),
    }),
  }),
  half_trend: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_HALF_TREND'),
      comparator: z.object({
        ht: z.optional(
          z.object({
            comparator: z.nativeEnum(Comparator),
            value: z.union([
              z.literal('OPEN'),
              z.literal('HIGH'),
              z.literal('LOW'),
              z.literal('CLOSE'),
            ]),
          }),
        ),
        bar_color: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BarColor),
        }),
      }),
      params: z.object({
        amplitude: z.number().default(2),
        channel_deviation: z.number().default(2),
        atr_length: z.number().min(1).default(100),
      }),
    }),
  }),
  heatmap_vol: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_HEATMAP_VOL'),
      comparator: z.object({
        heatmap_level: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(HeatmapLevel),
        }),
      }),
      params: z.object({
        length: z.number().min(1).default(610),
        std_length: z.number().min(1).default(610),
        threshold_extra_high: z.number().default(4),
        threshold_high: z.number().default(2.5),
        threshold_medium: z.number().default(1),
        threshold_normal: z.number().default(-0.5),
      }),
    }),
  }),
  hull_suite: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_HULL_SUITE'),
      comparator: z.object({
        bar_color: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BarColor),
        }),
      }),
      params: z.object({
        hma_length: z.number().min(1).default(55),
      }),
    }),
  }),
  macd_fastline_divergence: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_MACD_FASTLINE_DIVERGENCE'),
      comparator: z.object({
        bull: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BullSignal),
        }),
        bear: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BearSignal),
        }),
      }),
      params: z.object({
        fast_length: z.number().min(1).default(12),
        slow_length: z.number().min(1).default(26),
        signal_length: z.number().min(1).default(9),
      }),
    }),
  }),
  macd_hist_divergence: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_MACD_HIST_DIVERGENCE'),
      comparator: z.object({
        bull: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BullSignal),
        }),
        bear: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BearSignal),
        }),
      }),
      params: z.object({
        fast_length: z.number().min(1).default(12),
        slow_length: z.number().min(1).default(26),
        signal_length: z.number().min(1).default(9),
      }),
    }),
  }),
  mobo_band: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_MOBO_BAND'),
      comparator: z.object({
        buy_sell_signal: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySellSignal),
        }),
      }),
      params: z.object({
        dpo_length: z.number().min(1).default(13),
        mobo_length: z.number().min(1).default(10),
        num_dev_down: z.number().default(-0.8),
        num_dev_up: z.number().default(0.8),
      }),
    }),
  }),
  qqe_mod: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_QQE_MOD'),
      comparator: z.object({
        bar_color_one: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BarColor),
        }),
        bar_color_two: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BarColor),
        }),
      }),
      params: z.object({
        rsi_length_one: z.number().min(1).default(6),
        rsi_smoothing_one: z.number().default(5),
        qqe_factor_one: z.number().default(3),
        threshold_one: z.number().default(3),
        rsi_length_two: z.number().min(1).default(6),
        rsi_smoothing_two: z.number().default(5),
        qqe_factor_two: z.number().default(1.61),
        threshold_two: z.number().default(3),
        bollinger_length: z.number().min(1).default(50),
        qqe_multiplier: z.number().default(0.35),
      }),
    }),
  }),
  rsi_divergence: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_RSI_DIVERGENCE'),
      comparator: z.object({
        bull: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BullSignal),
        }),
        bear: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BearSignal),
        }),
      }),
      params: z.object({
        left_bar: z.number().default(6),
        right_bar: z.number().default(2),
        rsi_length: z.number().min(1).default(14),
      }),
    }),
  }),
  rvi: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_RVI'),
      comparator: z.object({
        rvi: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        std_length: z.number().min(1).default(10),
        ema_length: z.number().min(1).default(14),
      }),
    }),
  }),
  rvi_divergence: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_RVI_DIVERGENCE'),
      comparator: z.object({
        bull: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BullSignal),
        }),
        bear: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BearSignal),
        }),
      }),
      params: z.object({
        left_bar: z.number().default(6),
        right_bar: z.number().default(2),
        std_length: z.number().min(1).default(12),
        ema_length: z.number().min(1).default(14),
      }),
    }),
  }),
  ssl: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_SSL'),
      comparator: z.object({
        bbmc: z.optional(
          z.object({
            comparator: z.nativeEnum(Comparator),
            value: z.union([
              z.literal('OPEN'),
              z.literal('HIGH'),
              z.literal('LOW'),
              z.literal('CLOSE'),
            ]),
          }),
        ),
        bar_color: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BarColor),
        }),
        up_erk: z.optional(
          z.object({
            comparator: z.nativeEnum(Comparator),
            value: z.union([
              z.literal('OPEN'),
              z.literal('HIGH'),
              z.literal('LOW'),
              z.literal('CLOSE'),
            ]),
          }),
        ),
        low_erk: z.optional(
          z.object({
            comparator: z.nativeEnum(Comparator),
            value: z.union([
              z.literal('OPEN'),
              z.literal('HIGH'),
              z.literal('LOW'),
              z.literal('CLOSE'),
            ]),
          }),
        ),
        cross_long: z.optional(
          z.object({
            comparator: z.nativeEnum(SignalComparator),
            value: z.nativeEnum(CrossSignal),
          }),
        ),
        cross_short: z.optional(
          z.object({
            comparator: z.nativeEnum(SignalComparator),
            value: z.nativeEnum(CrossSignal),
          }),
        ),
      }),
      params: z.object({
        ma_length: z.number().min(1).default(60),
        ssl3_length: z.number().min(1).default(15),
      }),
    }),
  }),
  stc: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_STC'),
      comparator: z.object({
        stc: z.optional(z.object({ comparator: z.nativeEnum(Comparator), value: z.number() })),
        bar_color: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BarColor),
        }),
      }),
      params: z.object({
        length: z.number().min(1).default(12),
        fast_length: z.number().min(1).default(26),
        slow_length: z.number().min(1).default(50),
        aaa: z.number().default(0.5),
      }),
    }),
  }),
  stoch_divergence: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_STOCH_DIVERGENCE'),
      comparator: z.object({
        bull: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BullSignal),
        }),
        bear: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BearSignal),
        }),
      }),
      params: z.object({
        left_bar: z.number().default(6),
        right_bar: z.number().default(2),
        stk_length: z.number().min(1).default(14),
        smooth_length: z.number().min(1).default(3),
        sma_length: z.number().min(1).default(3),
      }),
    }),
  }),
  sup_and_res: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_SUP_AND_RES'),
      comparator: z.object({
        buy_one: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySignal),
        }),
        buy_two: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySignal),
        }),
        buy_three: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySignal),
        }),
        buy_four: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySignal),
        }),
        buy_five: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySignal),
        }),
        buy_six: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySignal),
        }),
        buy_seven: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySignal),
        }),
        buy_eight: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySignal),
        }),
        sell_one: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(SellSignal),
        }),
        sell_two: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(SellSignal),
        }),
        sell_three: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(SellSignal),
        }),
        sell_four: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(SellSignal),
        }),
        sell_five: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(SellSignal),
        }),
        sell_six: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(SellSignal),
        }),
        sell_seven: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(SellSignal),
        }),
        sell_eight: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(SellSignal),
        }),
      }),
      params: z.object({
        left_bar: z.number().default(200),
        right_bar_one: z.number().default(20),
        right_bar_two: z.number().default(5),
        hma_length: z.number().min(1).default(9),
      }),
    }),
  }),
  ut_bot: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_UT_BOT'),
      comparator: z.object({
        buy_sell_signal: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySellSignal),
        }),
      }),
      params: z.object({
        atr_period: z.number().min(1).default(10),
        sensitivity: z.number().default(1),
      }),
    }),
  }),
  volatility_oscillator: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_VOLATILITY_OSCILLATOR'),
      comparator: z.object({
        spike_line: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
        upper_line: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
        lower_line: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        length: z.number().min(1).default(100),
      }),
    }),
  }),
  vu_man_chu_swing: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_VU_MAN_CHU_SWING'),
      comparator: z.object({
        buy_sell_signal_long: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySellSignal),
        }),
        buy_sell_signal_short: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySellSignal),
        }),
      }),
      params: z.object({
        swing_period: z.number().min(1).default(20),
        swing_multiplier: z.number().default(3.5),
      }),
    }),
  }),
  waddah: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_WADDAH'),
      comparator: z.object({
        t: z.optional(z.object({ comparator: z.nativeEnum(Comparator), value: z.number() })),
        e: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
        trend_up: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
        trend_down: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        fast_length: z.number().min(1).default(20),
        slow_length: z.number().min(1).default(40),
        signal_length: z.number().min(1).default(9),
        bb_length: z.number().min(1).default(20),
        multiplier: z.number().default(2),
        sensitivity: z.number().default(150),
      }),
    }),
  }),
  psar: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_PSAR'),
      comparator: z.object({
        psar: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
          ]),
        }),
      }),
      params: z.object({
        accel_start: z.number().default(0.02),
        accel_step: z.number().default(0.02),
        accel_max: z.number().default(0.2),
      }),
    }),
  }),
  dx: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_DX'),
      comparator: z.object({
        dx: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(14),
      }),
    }),
  }),
  adx: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_ADX'),
      comparator: z.object({
        adx: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(14),
      }),
    }),
  }),
  dema: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_DEMA'),
      comparator: z.object({
        dema: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
            z.literal('VOLUME'),
          ]),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(9),
      }),
    }),
  }),
  ema: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_EMA'),
      comparator: z.object({
        ema: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
            z.literal('VOLUME'),
          ]),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(9),
      }),
    }),
  }),
  hma: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_HMA'),
      comparator: z.object({
        hma: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
            z.literal('VOLUME'),
          ]),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(9),
      }),
    }),
  }),
  sma: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_SMA'),
      comparator: z.object({
        sma: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
            z.literal('VOLUME'),
          ]),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(7),
      }),
    }),
  }),
  tema: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_TEMA'),
      comparator: z.object({
        tema: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
            z.literal('VOLUME'),
          ]),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(9),
      }),
    }),
  }),
  trima: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_TRIMA'),
      comparator: z.object({
        trima: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
            z.literal('VOLUME'),
          ]),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(20),
      }),
    }),
  }),
  vwma: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_VWMA'),
      comparator: z.object({
        vwma: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.literal('VOLUME'),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(20),
      }),
    }),
  }),
  wma: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_WMA'),
      comparator: z.object({
        wma: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
            z.literal('VOLUME'),
          ]),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(9),
      }),
    }),
  }),
  linreg: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_LINREG'),
      comparator: z.object({
        linreg: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
            z.literal('VOLUME'),
          ]),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(100),
      }),
    }),
  }),
  bbands: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_BBANDS'),
      comparator: z.object({
        bbands_lower: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
            z.literal('VOLUME'),
          ]),
        }),
        bbands_middle: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
            z.literal('VOLUME'),
          ]),
        }),
        bbands_upper: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
            z.literal('VOLUME'),
          ]),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(20),
        stddev: z.number().default(2),
      }),
    }),
  }),
  cci: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_CCI'),
      comparator: z.object({
        cci: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(20),
      }),
    }),
  }),
  stoch: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_STOCH'),
      comparator: z.object({
        stoch_k: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
        stoch_d: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        k_period: z.number().min(1).default(14),
        k_slowing_period: z.number().min(1).default(1),
        d_period: z.number().min(1).default(3),
      }),
    }),
  }),
  mfi: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_MFI'),
      comparator: z.object({
        mfi: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(14),
      }),
    }),
  }),
  macd: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_MACD'),
      comparator: z.object({
        macd: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
        macd_signal: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
        macd_histogram: z.optional(
          z.object({ comparator: z.nativeEnum(Comparator), value: z.number() }),
        ),
      }),
      params: z.object({
        short_period: z.number().min(1).default(12),
        long_period: z.number().min(1).default(26),
        signal_period: z.number().min(1).default(9),
      }),
    }),
  }),
  rsi: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_RSI'),
      comparator: z.object({
        rsi: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(14),
      }),
    }),
  }),
  natr: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_NATR'),
      comparator: z.object({
        natr: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(14),
      }),
    }),
  }),
  atr: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_ATR'),
      comparator: z.object({
        atr: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(14),
      }),
    }),
  }),
  insidebar: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_INSIDEBAR'),
      comparator: z.object({
        buy_sell_signal: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySellSignal),
        }),
      }),
      params: z.object({}),
    }),
  }),
  price: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_PRICE'),
      comparator: z.object({
        price: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({}),
    }),
  }),
};

export const IndicatorSchema = Type.Union([...Object.values(IndicatorSchemas)]);
export const IndicatorSchemaZod = z.union([
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_CHAIKIN_VOL'),
      comparator: z.object({
        cvi: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        ema_period: z.number().min(1).default(7),
        roc_period: z.number().min(1).default(14),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_STOCH_RSI'),
      comparator: z.object({
        stoch_k: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
        stoch_d: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        smoothk: z.number().default(3),
        smoothd: z.number().default(3),
        rsi_period: z.number().min(1).default(14),
        stoch_period: z.number().min(1).default(14),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_SUPERTREND'),
      comparator: z.object({
        supertrend: z.optional(
          z.object({
            comparator: z.nativeEnum(Comparator),
            value: z.union([
              z.literal('OPEN'),
              z.literal('HIGH'),
              z.literal('LOW'),
              z.literal('CLOSE'),
            ]),
          }),
        ),
        direction: z.optional(
          z.object({
            comparator: z.nativeEnum(SignalComparator),
            value: z.nativeEnum(DirectionSignal),
          }),
        ),
        bar_color: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BarColor),
        }),
        buy_sell_signal: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySellSignal),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(34),
        factor: z.number().default(3),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_WAVETREND'),
      comparator: z.object({
        wavetrend_one: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
        wavetrend_two: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        period_one: z.number().min(1).default(9),
        period_two: z.number().min(1).default(12),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_ANDEAN_OSC'),
      comparator: z.object({
        bull_data: z.optional(
          z.object({ comparator: z.nativeEnum(Comparator), value: z.number() }),
        ),
        bear_data: z.optional(
          z.object({ comparator: z.nativeEnum(Comparator), value: z.number() }),
        ),
        ao_data: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(50),
        signal_length: z.number().min(1).default(9),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_BRAID_FILTER'),
      comparator: z.object({
        dif: z.optional(z.object({ comparator: z.nativeEnum(Comparator), value: z.number() })),
        atr_filter: z.optional(
          z.object({ comparator: z.nativeEnum(Comparator), value: z.number() }),
        ),
        bar_color: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BarColor),
        }),
      }),
      params: z.object({
        ma01_length: z.number().min(1).default(3),
        ma02_length: z.number().min(1).default(7),
        ma03_length: z.number().min(1).default(14),
        pips_min_sep_percent: z.number().default(40),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_BOOM_PRO'),
      comparator: z.object({
        trigger: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
          ]),
        }),
        q4: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
          ]),
        }),
      }),
      params: z.object({
        lp_period_one: z.number().min(1).default(6),
        k1_quotient: z.number().default(0),
        trig_no: z.number().default(2),
        lp_period_two: z.number().min(1).default(27),
        k22_eot: z.number().default(0.3),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_CHANDELIER_EXIT'),
      comparator: z.object({
        buy_sell_signal: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySellSignal),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(22),
        atr_multiplier: z.number().default(3),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_CM_EMA_TRENDBARS'),
      comparator: z.object({
        usdema: z.optional(
          z.object({
            comparator: z.nativeEnum(Comparator),
            value: z.union([
              z.literal('OPEN'),
              z.literal('HIGH'),
              z.literal('LOW'),
              z.literal('CLOSE'),
            ]),
          }),
        ),
        bar_color: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BarColor),
        }),
      }),
      params: z.object({
        ema_length: z.number().min(1).default(34),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_DI_DX'),
      comparator: z.object({
        dx: z.optional(z.object({ comparator: z.nativeEnum(Comparator), value: z.number() })),
        di_plus: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
        di_minus: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(14),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_HALF_TREND'),
      comparator: z.object({
        ht: z.optional(
          z.object({
            comparator: z.nativeEnum(Comparator),
            value: z.union([
              z.literal('OPEN'),
              z.literal('HIGH'),
              z.literal('LOW'),
              z.literal('CLOSE'),
            ]),
          }),
        ),
        bar_color: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BarColor),
        }),
      }),
      params: z.object({
        amplitude: z.number().default(2),
        channel_deviation: z.number().default(2),
        atr_length: z.number().min(1).default(100),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_HEATMAP_VOL'),
      comparator: z.object({
        heatmap_level: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(HeatmapLevel),
        }),
      }),
      params: z.object({
        length: z.number().min(1).default(610),
        std_length: z.number().min(1).default(610),
        threshold_extra_high: z.number().default(4),
        threshold_high: z.number().default(2.5),
        threshold_medium: z.number().default(1),
        threshold_normal: z.number().default(-0.5),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_HULL_SUITE'),
      comparator: z.object({
        bar_color: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BarColor),
        }),
      }),
      params: z.object({
        hma_length: z.number().min(1).default(55),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_MACD_FASTLINE_DIVERGENCE'),
      comparator: z.object({
        bull: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BullSignal),
        }),
        bear: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BearSignal),
        }),
      }),
      params: z.object({
        fast_length: z.number().min(1).default(12),
        slow_length: z.number().min(1).default(26),
        signal_length: z.number().min(1).default(9),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_MACD_HIST_DIVERGENCE'),
      comparator: z.object({
        bull: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BullSignal),
        }),
        bear: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BearSignal),
        }),
      }),
      params: z.object({
        fast_length: z.number().min(1).default(12),
        slow_length: z.number().min(1).default(26),
        signal_length: z.number().min(1).default(9),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_MOBO_BAND'),
      comparator: z.object({
        buy_sell_signal: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySellSignal),
        }),
      }),
      params: z.object({
        dpo_length: z.number().min(1).default(13),
        mobo_length: z.number().min(1).default(10),
        num_dev_down: z.number().default(-0.8),
        num_dev_up: z.number().default(0.8),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_QQE_MOD'),
      comparator: z.object({
        bar_color_one: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BarColor),
        }),
        bar_color_two: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BarColor),
        }),
      }),
      params: z.object({
        rsi_length_one: z.number().min(1).default(6),
        rsi_smoothing_one: z.number().default(5),
        qqe_factor_one: z.number().default(3),
        threshold_one: z.number().default(3),
        rsi_length_two: z.number().min(1).default(6),
        rsi_smoothing_two: z.number().default(5),
        qqe_factor_two: z.number().default(1.61),
        threshold_two: z.number().default(3),
        bollinger_length: z.number().min(1).default(50),
        qqe_multiplier: z.number().default(0.35),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_RSI_DIVERGENCE'),
      comparator: z.object({
        bull: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BullSignal),
        }),
        bear: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BearSignal),
        }),
      }),
      params: z.object({
        left_bar: z.number().default(6),
        right_bar: z.number().default(2),
        rsi_length: z.number().min(1).default(14),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_RVI'),
      comparator: z.object({
        rvi: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        std_length: z.number().min(1).default(10),
        ema_length: z.number().min(1).default(14),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_RVI_DIVERGENCE'),
      comparator: z.object({
        bull: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BullSignal),
        }),
        bear: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BearSignal),
        }),
      }),
      params: z.object({
        left_bar: z.number().default(6),
        right_bar: z.number().default(2),
        std_length: z.number().min(1).default(12),
        ema_length: z.number().min(1).default(14),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_SSL'),
      comparator: z.object({
        bbmc: z.optional(
          z.object({
            comparator: z.nativeEnum(Comparator),
            value: z.union([
              z.literal('OPEN'),
              z.literal('HIGH'),
              z.literal('LOW'),
              z.literal('CLOSE'),
            ]),
          }),
        ),
        bar_color: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BarColor),
        }),
        up_erk: z.optional(
          z.object({
            comparator: z.nativeEnum(Comparator),
            value: z.union([
              z.literal('OPEN'),
              z.literal('HIGH'),
              z.literal('LOW'),
              z.literal('CLOSE'),
            ]),
          }),
        ),
        low_erk: z.optional(
          z.object({
            comparator: z.nativeEnum(Comparator),
            value: z.union([
              z.literal('OPEN'),
              z.literal('HIGH'),
              z.literal('LOW'),
              z.literal('CLOSE'),
            ]),
          }),
        ),
        cross_long: z.optional(
          z.object({
            comparator: z.nativeEnum(SignalComparator),
            value: z.nativeEnum(CrossSignal),
          }),
        ),
        cross_short: z.optional(
          z.object({
            comparator: z.nativeEnum(SignalComparator),
            value: z.nativeEnum(CrossSignal),
          }),
        ),
      }),
      params: z.object({
        ma_length: z.number().min(1).default(60),
        ssl3_length: z.number().min(1).default(15),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_STC'),
      comparator: z.object({
        stc: z.optional(z.object({ comparator: z.nativeEnum(Comparator), value: z.number() })),
        bar_color: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BarColor),
        }),
      }),
      params: z.object({
        length: z.number().min(1).default(12),
        fast_length: z.number().min(1).default(26),
        slow_length: z.number().min(1).default(50),
        aaa: z.number().default(0.5),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_STOCH_DIVERGENCE'),
      comparator: z.object({
        bull: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BullSignal),
        }),
        bear: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BearSignal),
        }),
      }),
      params: z.object({
        left_bar: z.number().default(6),
        right_bar: z.number().default(2),
        stk_length: z.number().min(1).default(14),
        smooth_length: z.number().min(1).default(3),
        sma_length: z.number().min(1).default(3),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_SUP_AND_RES'),
      comparator: z.object({
        buy_one: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySignal),
        }),
        buy_two: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySignal),
        }),
        buy_three: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySignal),
        }),
        buy_four: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySignal),
        }),
        buy_five: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySignal),
        }),
        buy_six: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySignal),
        }),
        buy_seven: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySignal),
        }),
        buy_eight: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySignal),
        }),
        sell_one: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(SellSignal),
        }),
        sell_two: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(SellSignal),
        }),
        sell_three: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(SellSignal),
        }),
        sell_four: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(SellSignal),
        }),
        sell_five: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(SellSignal),
        }),
        sell_six: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(SellSignal),
        }),
        sell_seven: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(SellSignal),
        }),
        sell_eight: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(SellSignal),
        }),
      }),
      params: z.object({
        left_bar: z.number().default(200),
        right_bar_one: z.number().default(20),
        right_bar_two: z.number().default(5),
        hma_length: z.number().min(1).default(9),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_UT_BOT'),
      comparator: z.object({
        buy_sell_signal: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySellSignal),
        }),
      }),
      params: z.object({
        atr_period: z.number().min(1).default(10),
        sensitivity: z.number().default(1),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_VOLATILITY_OSCILLATOR'),
      comparator: z.object({
        spike_line: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
        upper_line: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
        lower_line: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        length: z.number().min(1).default(100),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_VU_MAN_CHU_SWING'),
      comparator: z.object({
        buy_sell_signal_long: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySellSignal),
        }),
        buy_sell_signal_short: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySellSignal),
        }),
      }),
      params: z.object({
        swing_period: z.number().min(1).default(20),
        swing_multiplier: z.number().default(3.5),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_WADDAH'),
      comparator: z.object({
        t: z.optional(z.object({ comparator: z.nativeEnum(Comparator), value: z.number() })),
        e: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
        trend_up: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
        trend_down: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        fast_length: z.number().min(1).default(20),
        slow_length: z.number().min(1).default(40),
        signal_length: z.number().min(1).default(9),
        bb_length: z.number().min(1).default(20),
        multiplier: z.number().default(2),
        sensitivity: z.number().default(150),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_PSAR'),
      comparator: z.object({
        psar: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
          ]),
        }),
      }),
      params: z.object({
        accel_start: z.number().default(0.02),
        accel_step: z.number().default(0.02),
        accel_max: z.number().default(0.2),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_DX'),
      comparator: z.object({
        dx: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(14),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_ADX'),
      comparator: z.object({
        adx: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(14),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_DEMA'),
      comparator: z.object({
        dema: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
            z.literal('VOLUME'),
          ]),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(9),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_EMA'),
      comparator: z.object({
        ema: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
            z.literal('VOLUME'),
          ]),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(9),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_HMA'),
      comparator: z.object({
        hma: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
            z.literal('VOLUME'),
          ]),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(9),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_SMA'),
      comparator: z.object({
        sma: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
            z.literal('VOLUME'),
          ]),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(7),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_TEMA'),
      comparator: z.object({
        tema: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
            z.literal('VOLUME'),
          ]),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(9),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_TRIMA'),
      comparator: z.object({
        trima: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
            z.literal('VOLUME'),
          ]),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(20),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_VWMA'),
      comparator: z.object({
        vwma: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.literal('VOLUME'),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(20),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_WMA'),
      comparator: z.object({
        wma: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
            z.literal('VOLUME'),
          ]),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(9),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_LINREG'),
      comparator: z.object({
        linreg: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
            z.literal('VOLUME'),
          ]),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(100),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_BBANDS'),
      comparator: z.object({
        bbands_lower: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
            z.literal('VOLUME'),
          ]),
        }),
        bbands_middle: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
            z.literal('VOLUME'),
          ]),
        }),
        bbands_upper: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.union([
            z.literal('OPEN'),
            z.literal('HIGH'),
            z.literal('LOW'),
            z.literal('CLOSE'),
            z.literal('VOLUME'),
          ]),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(20),
        stddev: z.number().default(2),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_CCI'),
      comparator: z.object({
        cci: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(20),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_STOCH'),
      comparator: z.object({
        stoch_k: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
        stoch_d: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        k_period: z.number().min(1).default(14),
        k_slowing_period: z.number().min(1).default(1),
        d_period: z.number().min(1).default(3),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_MFI'),
      comparator: z.object({
        mfi: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(14),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_MACD'),
      comparator: z.object({
        macd: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
        macd_signal: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
        macd_histogram: z.optional(
          z.object({ comparator: z.nativeEnum(Comparator), value: z.number() }),
        ),
      }),
      params: z.object({
        short_period: z.number().min(1).default(12),
        long_period: z.number().min(1).default(26),
        signal_period: z.number().min(1).default(9),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_RSI'),
      comparator: z.object({
        rsi: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(14),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_NATR'),
      comparator: z.object({
        natr: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(14),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_ATR'),
      comparator: z.object({
        atr: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({
        period: z.number().min(1).default(14),
      }),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_INSIDEBAR'),
      comparator: z.object({
        buy_sell_signal: z.object({
          comparator: z.nativeEnum(SignalComparator),
          value: z.nativeEnum(BuySellSignal),
        }),
      }),
      params: z.object({}),
    }),
  }),
  z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_PRICE'),
      comparator: z.object({
        price: z.object({
          comparator: z.nativeEnum(Comparator),
          value: z.number(),
        }),
      }),
      params: z.object({}),
    }),
  }),
]);
export type Indicator = Static<typeof IndicatorSchema>;
export type IndicatorZod = z.infer<typeof IndicatorSchemaZod>;
