import { describe, expect, test } from 'vitest';

import type { Static } from '@cybotrade/core';

import { calculateIndicator, compare, compareResults, findMinCandles } from '../calculator';
import { indicators } from '../generated';
import {
  BarColor,
  BuySellSignal,
  BuySignal,
  Comparator,
  DirectionSignal,
  HeatmapLevel,
  type IndicatorSchemas,
  SignalComparator,
} from '../public';

describe('compare', () => {
  test('NaN > 100 should be false', () => {
    expect(compare({ left: NaN, comparator: Comparator.GreaterThan, right: 100 })).toBe(false);
  });

  test('NaN < 100 should be false', () => {
    expect(compare({ left: NaN, comparator: Comparator.LesserThan, right: 100 })).toBe(false);
  });

  test('NaN === 100 should be false', () => {
    expect(compare({ left: NaN, comparator: Comparator.Equal, right: 100 })).toBe(false);
  });

  test('NaN >= 100 should be false', () => {
    expect(compare({ left: NaN, comparator: Comparator.GreaterThanEqual, right: 100 })).toBe(false);
  });

  test('NaN <= 100 should be false', () => {
    expect(compare({ left: NaN, comparator: Comparator.LesserThanEqual, right: 100 })).toBe(false);
  });

  test('100 > 101 should be false', () => {
    expect(compare({ left: 100, comparator: Comparator.GreaterThan, right: 101 })).toBe(false);
  });

  test('100 < 101 should be true', () => {
    expect(compare({ left: 100, comparator: Comparator.LesserThan, right: 101 })).toBe(true);
  });

  test('100 >= 101 should be false', () => {
    expect(compare({ left: 100, comparator: Comparator.GreaterThanEqual, right: 101 })).toBe(false);
  });

  test('100 <= 101 should be true', () => {
    expect(compare({ left: 100, comparator: Comparator.LesserThanEqual, right: 101 })).toBe(true);
  });

  test('100 === 101 should be false', () => {
    expect(compare({ left: 100, comparator: Comparator.Equal, right: 101 })).toBe(false);
  });

  test('100 === 100 should be true', () => {
    expect(compare({ left: 100, comparator: Comparator.Equal, right: 100 })).toBe(true);
  });

  test('0 === BuySignal.Buy should be false', () => {
    expect(compare({ left: 0, comparator: SignalComparator.Equal, right: BuySignal.Buy })).toBe(
      false,
    );
  });

  test('1 === BuySignal.Buy should be true', () => {
    expect(compare({ left: 1, comparator: SignalComparator.Equal, right: BuySignal.Buy })).toBe(
      true,
    );
  });
});

describe('compareResults', () => {
  const results = [23268.01, 22987.79, 22818.37, 22622.98, 23312.42];
  const currentGreaterThanPrevious = ({
    current,
    previous,
  }: {
    current: number;
    previous: number;
  }) => current > previous;

  test('should throw if no conditions are given', () => {
    expect(() =>
      compareResults({
        results,
        comparator: Comparator.GreaterThan,
        value: 1,
        conditions: [],
      }),
    ).toThrowError('Must have at least one condition');
  });

  test('should throw if candles and results are not the same length', () => {
    expect(() =>
      compareResults({
        results,
        comparator: Comparator.GreaterThan,
        value: 1,
        conditions: [[() => true]],
        candles: [],
      }),
    ).toThrowError('Candles and results must be the same length');
  });

  test('should throw if candles are not provided when value is not a number', () => {
    expect(() =>
      compareResults({
        results,
        comparator: Comparator.GreaterThan,
        value: 'CLOSE',
        conditions: [[() => true]],
      }),
    ).toThrowError('Candles must be provided if value is not a number');
  });

  test('should return false if results is empty', () => {
    expect(
      compareResults({
        results: [],
        comparator: Comparator.GreaterThan,
        value: 1,
        conditions: [[() => true]],
      }),
    ).eq(false);
  });

  test('should return false if comparator does not match', () => {
    expect(
      compareResults({
        results,
        comparator: Comparator.GreaterThan,
        value: 10000000,
        conditions: [[() => true]],
      }),
    ).eq(false);

    expect(
      compareResults({
        results,
        comparator: Comparator.GreaterThan,
        value: 10000000,
        conditions: [[() => true], [() => true], [() => true]],
      }),
    ).eq(false);
  });

  test('should return false if condition does not match', () => {
    expect(
      compareResults({
        results,
        comparator: Comparator.GreaterThan,
        value: 1,
        conditions: [[() => false]],
      }),
    ).eq(false);

    expect(
      compareResults({
        results,
        comparator: Comparator.GreaterThan,
        value: 1,
        conditions: [[() => false], [() => false], [() => false]],
      }),
    ).eq(false);
  });

  test('should return true if comparator and condition match', () => {
    expect(
      compareResults({
        results,
        comparator: Comparator.GreaterThan,
        value: 1,
        conditions: [[() => true]],
      }),
    ).eq(true);
  });

  test('should return false if previous is bigger than current', () => {
    const results = [0, 0, 0, 4, 3];

    expect(
      compareResults({
        results,
        comparator: Comparator.GreaterThan,
        value: 1,
        conditions: [[currentGreaterThanPrevious], [currentGreaterThanPrevious]],
      }),
    ).eq(false);

    expect(
      compareResults({
        results,
        comparator: Comparator.GreaterThan,
        value: 1,
        conditions: [
          [currentGreaterThanPrevious, currentGreaterThanPrevious],
          [currentGreaterThanPrevious],
        ],
      }),
    ).eq(false);
  });

  test('should return true if previous is smaller than current', () => {
    const results = [0, 0, 0, 3, 4];

    expect(
      compareResults({
        results,
        comparator: Comparator.GreaterThan,
        value: 1,
        conditions: [[currentGreaterThanPrevious], [currentGreaterThanPrevious]],
      }),
    ).eq(true);

    expect(
      compareResults({
        results,
        comparator: Comparator.GreaterThan,
        value: 1,
        conditions: [[currentGreaterThanPrevious, () => true], [currentGreaterThanPrevious]],
      }),
    ).eq(true);
  });
});

const rsi: Static<typeof IndicatorSchemas.rsi> = {
  type: 'INDICATOR_NODE',
  id: 'rsi',
  data: {
    indicator_type: 'INDICATOR_RSI',
    params: { period: 5 },
    comparator: { rsi: { comparator: Comparator.GreaterThanEqual, value: 50 } },
  },
};

describe('findMinCandles', () => {
  test('should return 0 if multiplier given is 0', () => {
    expect(findMinCandles(0)(rsi)).eq(0);
  });

  test('should return equal to rsi period if multiplier given is 1', () => {
    expect(findMinCandles(1)(rsi)).eq(rsi.data.params.period);
  });

  test('should return two times the rsi period if multiplier given is 2', () => {
    expect(findMinCandles(2)(rsi)).eq(rsi.data.params.period * 2);
  });
});

describe('calculateIndicator', () => {
  const heatmap_vol: Static<typeof IndicatorSchemas.heatmap_vol> = {
    type: 'INDICATOR_NODE',
    id: 'heatmap_vol',
    data: {
      indicator_type: 'INDICATOR_HEATMAP_VOL',
      params: {
        length: 5,
        std_length: 5,
        threshold_extra_high: 4,
        threshold_high: 2.5,
        threshold_medium: 1,
        threshold_normal: -0.5,
      },
      comparator: {
        heatmap_level: { comparator: SignalComparator.Equal, value: HeatmapLevel.Medium },
      },
    },
  };

  const supertrend: Static<typeof IndicatorSchemas.supertrend> = {
    type: 'INDICATOR_NODE',
    id: 'supertrend',
    data: {
      indicator_type: 'INDICATOR_SUPERTREND',
      params: { period: 2, factor: 1 },
      comparator: {
        bar_color: { comparator: SignalComparator.Equal, value: BarColor.Green },
        buy_sell_signal: { comparator: SignalComparator.Equal, value: BuySellSignal.Sell },
      },
    },
  };

  test('should throw if indicator given fails validation', async () => {
    await expect(
      calculateIndicator({ indicator: {} as never, candles: [], conditions: [] }),
    ).rejects.toThrow('Indicator does not pass validation');
  });

  test('should throw if candles lesser than the minimum required', async () => {
    await expect(
      calculateIndicator({ indicator: rsi, candles: [], conditions: [[() => true]] }),
    ).rejects.toThrow('Not enough candles to calculate indicator');
  });

  test('should throw if give zero conditions', async () => {
    await expect(
      calculateIndicator({
        indicator: rsi,
        candles: [
          37.875, 39.5, 38.75, 39.8125, 40, 39.875, 40.1875, 41.25, 41.125, 41.625, 41.25, 40.1875,
          39.9375, 39.9375, 40.5, 41.9375, 42.25, 42.25, 41.875, 41.875,
        ].map((v) => ({ open: 0, high: 0, low: 0, close: v, volume: 0 })),
        conditions: [],
      }),
    ).rejects.toThrow('Must have at least one condition');
  });

  test('should return true if rsi is greater or equal to the previous rsi', async () => {
    const value = [
      37.875, 39.5, 38.75, 39.8125, 40, 39.875, 40.1875, 41.25, 41.125, 41.625, 41.25, 40.1875,
      39.9375, 39.9375, 40.5, 41.9375, 42.25, 42.25, 41.875, 41.875,
    ];
    const { rsi: _rsi } = await indicators.rsi({ value }, rsi.data.params);
    await expect(
      calculateIndicator({
        indicator: rsi,
        candles: value.map((v) => ({ open: 0, high: 0, low: 0, close: v, volume: 0 })),
        conditions: [
          [
            ({ current, previous }) =>
              compare({
                left: current,
                comparator: rsi.data.comparator.rsi.comparator,
                right: previous,
              }),
          ],
        ],
      }),
    ).resolves.deep.eq({
      rsi: compare({
        left: _rsi.slice(-1)[0],
        comparator: rsi.data.comparator.rsi.comparator,
        right: rsi.data.comparator.rsi.value,
      }),
    });
  });

  test('should return false if rsi is not greater or equal to previous two rsi', async () => {
    const value = [
      37.875, 39.5, 38.75, 39.8125, 40, 39.875, 40.1875, 41.25, 41.125, 41.625, 41.25, 40.1875,
      39.9375, 39.9375, 40.5, 41.9375, 42.25, 42.25, 41.875, 41.875,
    ];
    const { rsi: _rsi } = await indicators.rsi({ value }, rsi.data.params);
    await expect(
      calculateIndicator({
        indicator: rsi,
        candles: value.map((v) => ({ open: 0, high: 0, low: 0, close: v, volume: 0 })),
        conditions: [
          [
            ({ current, previous }) =>
              compare({
                left: current,
                comparator: rsi.data.comparator.rsi.comparator,
                right: previous,
              }),
          ],
          [
            ({ current, previous }) =>
              compare({
                left: current,
                comparator: rsi.data.comparator.rsi.comparator,
                right: previous,
              }),
          ],
        ],
      }),
    ).resolves.deep.eq({
      rsi: false,
    });
  });

  test('should match with result from tulipindicators testcase of heatmap_vol', async () => {
    const volume = [
      144210.16219, 158073.28225, 145948.80995, 154854.67016, 175251.69749, 83911.80307,
      88890.00877, 170958.44152, 143182.50858, 208916.54953, 249759.79557, 174207.5704,
      152852.25435, 151206.14473, 242539.54758,
    ];
    const { heatmap_level } = await indicators.heatmap_vol({ volume }, heatmap_vol.data.params);
    await expect(
      calculateIndicator({
        indicator: heatmap_vol,
        candles: volume.map((v) => ({ open: 0, high: 0, low: 0, close: 0, volume: v })),
        conditions: [[() => true]],
      }),
    ).resolves.deep.eq({
      heatmap_level: heatmap_level.slice(-1)[0] == heatmap_vol.data.comparator.heatmap_level.value,
    });
  });

  test('should work with optional comparator', async () => {
    const high = [
      23509.68, 23459.89, 23647.68, 23223.32, 23472.86, 23354.36, 23402, 24245, 23933.25, 24226,
      24918.54, 24456.5, 24888, 25047.56, 25211.32,
    ];
    const low = [
      22850, 22654.37, 22681.22, 22400, 22586.95, 22909.52, 22844.62, 23154.25, 22865, 22664.69,
      23852.13, 23583, 24291.22, 24144, 23773.22,
    ];
    const close = [
      23268.01, 22987.79, 22818.37, 22622.98, 23312.42, 22954.21, 23174.39, 23810, 23149.95,
      23954.05, 23934.39, 24403.68, 24441.38, 24305.24, 24094.82,
    ];
    await expect(
      calculateIndicator({
        indicator: supertrend,
        candles: high.map((v, i) => ({
          open: 0,
          high: v,
          low: low[i],
          close: close[i],
          volume: 0,
        })),
        conditions: [[() => true]],
      }),
    ).resolves.deep.eq({
      supertrend: false,
      direction: false,
      bar_color: true,
      buy_sell_signal: false,
    });

    await expect(
      calculateIndicator({
        indicator: {
          ...supertrend,
          data: {
            ...supertrend.data,
            comparator: {
              ...supertrend.data.comparator,
              direction: {
                comparator: SignalComparator.Equal,
                value: DirectionSignal.Down,
              },
            },
          },
        },
        candles: high.map((v, i) => ({
          open: 0,
          high: v,
          low: low[i],
          close: close[i],
          volume: 0,
        })),
        conditions: [[() => true]],
      }),
    ).resolves.deep.eq({
      supertrend: false,
      direction: true,
      bar_color: true,
      buy_sell_signal: false,
    });
  });

  test('should work with OHLC comparator', async () => {
    const high = [
      23509.68, 23459.89, 23647.68, 23223.32, 23472.86, 23354.36, 23402, 24245, 23933.25, 24226,
      24918.54, 24456.5, 24888, 25047.56, 25211.32,
    ];
    const low = [
      22850, 22654.37, 22681.22, 22400, 22586.95, 22909.52, 22844.62, 23154.25, 22865, 22664.69,
      23852.13, 23583, 24291.22, 24144, 23773.22,
    ];
    const close = [
      23268.01, 22987.79, 22818.37, 22622.98, 23312.42, 22954.21, 23174.39, 23810, 23149.95,
      23954.05, 23934.39, 24403.68, 24441.38, 24305.24, 24094.82,
    ];
    await expect(
      calculateIndicator({
        indicator: {
          ...supertrend,
          data: {
            ...supertrend.data,
            comparator: {
              ...supertrend.data.comparator,
              supertrend: {
                comparator: Comparator.GreaterThan,
                value: 'LOW',
              },
            },
          },
        },
        candles: high.map((v, i) => ({
          open: 0,
          high: v,
          low: low[i],
          close: close[i],
          volume: 0,
        })),
        conditions: [[() => true]],
      }),
    ).resolves.deep.eq({
      supertrend: true,
      direction: false,
      bar_color: true,
      buy_sell_signal: false,
    });
  });

  test('test', async () => {
    const high = [
      23509.68, 23459.89, 23647.68, 23223.32, 23472.86, 23354.36, 23402, 24245, 23933.25, 24226,
      24918.54, 24456.5, 24888, 25047.56, 25211.32,
    ];
    const low = [
      22850, 22654.37, 22681.22, 22400, 22586.95, 22909.52, 22844.62, 23154.25, 22865, 22664.69,
      23852.13, 23583, 24291.22, 24144, 23773.22,
    ];
    const close = [
      23268.01, 22987.79, 22818.37, 22622.98, 23312.42, 22954.21, 23174.39, 23810, 23149.95,
      23954.05, 23934.39, 24403.68, 24441.38, 24305.24, 24094.82,
    ];
    const result = await calculateIndicator({
      indicator: {
        ...supertrend,
        data: {
          ...supertrend.data,
          comparator: {
            ...supertrend.data.comparator,
            supertrend: {
              comparator: Comparator.GreaterThan,
              value: 'LOW',
            },
          },
        },
      },
      candles: high.map((v, i) => ({
        open: 0,
        high: v,
        low: low[i],
        close: close[i],
        volume: 0,
      })),
      conditions: [[() => true]],
    });
    console.log(result);
  });
});
