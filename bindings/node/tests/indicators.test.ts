import { describe, expect, test } from 'vitest';

import { indicators } from '../index';
import { roundTo } from './utils';

describe('Generated indicator bindings ', () => {
  test('price', async () => {
    const value = [
      63.75, 63.625, 63, 62.75, 63.25, 65.375, 66, 65, 64.875, 64.75, 64.375, 64.375, 64.625,
      64.375, 64.5, 65.25, 67.875, 68, 66.875, 66.25, 65.875, 66, 65.875, 64.75, 63, 63.375, 63.375,
      63.375, 63.875, 65.5, 63.25, 60.75, 57.25, 59.125, 59.25, 58.5, 59.125, 59.75, 60.625, 60.5,
      59, 59.5, 58.875, 59.625, 59.875, 59.75, 59.625, 59.25, 58.875, 59.125, 60.875, 60.75, 61.125,
      62.5, 63.25,
    ];
    const { price } = indicators.price({ value }, {});
    expect(price).deep.eq(value);
  });

  test('macd', async () => {
    const long_period = 26;
    const dp = 9;
    const { macd, macd_signal, macd_histogram } = await indicators.macd(
      {
        value: [
          63.75, 63.625, 63, 62.75, 63.25, 65.375, 66, 65, 64.875, 64.75, 64.375, 64.375, 64.625,
          64.375, 64.5, 65.25, 67.875, 68, 66.875, 66.25, 65.875, 66, 65.875, 64.75, 63, 63.375,
          63.375, 63.375, 63.875, 65.5, 63.25, 60.75, 57.25, 59.125, 59.25, 58.5, 59.125, 59.75,
          60.625, 60.5, 59, 59.5, 58.875, 59.625, 59.875, 59.75, 59.625, 59.25, 58.875, 59.125,
          60.875, 60.75, 61.125, 62.5, 63.25,
        ],
      },
      { short_period: 12, long_period, signal_period: 9 },
    );
    expect(macd.map(roundTo(dp))).deep.eq(
      new Array(long_period - 1)
        .fill(0)
        .concat([
          0.069246173, -0.056749361, -0.155174919, -0.193316296, -0.099255145, -0.192932945,
          -0.45191662, -0.912958472, -1.124556845, -1.268899802, -1.424364329, -1.483699214,
          -1.466784652, -1.37135925, -1.290278236, -1.324512659, -1.299028706, -1.311252875,
          -1.249862534, -1.168783424, -1.101261161, -1.045157593, -1.01741314, -1.012278166,
          -0.978102663, -0.808978519, -0.676278653, -0.536210248, -0.316924099, -0.084694969,
        ]),
    );
    expect(macd_signal.map(roundTo(dp))).deep.eq(
      new Array(long_period - 1)
        .fill(0)
        .concat([
          0.069246173, 0.044047066, 0.004202669, -0.035301124, -0.048091928, -0.077060132,
          -0.152031429, -0.304216838, -0.468284839, -0.628407832, -0.787599131, -0.926819148,
          -1.034812249, -1.102121649, -1.139752966, -1.176704905, -1.201169665, -1.223186307,
          -1.228521552, -1.216573927, -1.193511374, -1.163840617, -1.134555122, -1.110099731,
          -1.083700317, -1.028755957, -0.958260496, -0.873850447, -0.762465177, -0.626911135,
        ]),
    );
    expect(macd_histogram.map(roundTo(dp))).deep.eq(
      new Array(long_period - 1)
        .fill(0)
        .concat([
          0, -0.100796427, -0.159377588, -0.158015172, -0.051163217, -0.115872813, -0.29988519,
          -0.608741634, -0.656272006, -0.64049197, -0.636765198, -0.556880067, -0.431972403,
          -0.269237601, -0.15052527, -0.147807754, -0.097859041, -0.088066568, -0.021340981,
          0.047790503, 0.092250213, 0.118683025, 0.117141982, 0.097821565, 0.105597654, 0.219777438,
          0.281981844, 0.337640199, 0.445541078, 0.542216167,
        ]),
    );
  });

  test('chandelier_exit', async () => {
    const { buy_sell_signal } = indicators.chandelier_exit(
      {
        close: [
          23509.68, 23459.89, 23647.68, 23223.32, 23472.86, 23354.36, 23402, 24245, 23933.25, 24226,
          24918.54, 24456.5, 24888, 25047.56, 25211.32,
        ],
        high: [
          22850, 22654.37, 22681.22, 22400, 22586.95, 22909.52, 22844.62, 23154.25, 22865, 22664.69,
          23852.13, 23583, 24291.22, 24144, 23773.22,
        ],
        low: [
          23268.01, 22987.79, 22818.37, 22622.98, 23312.42, 22954.21, 23174.39, 23810, 23149.95,
          23954.05, 23934.39, 24403.68, 24441.38, 24305.24, 24094.82,
        ],
      },
      { period: 1, atr_multiplier: 1.85 },
    );

    expect(buy_sell_signal).deep.eq([
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    ]);
  });

  test('qqe_mod', async () => {
    const { bar_color_one, bar_color_two } = await indicators.qqe_mod(
      {
        close: [
          23268.01, 22987.79, 22818.37, 22622.98, 23312.42, 22954.21, 23174.39, 23810, 23149.95,
          23954.05, 23934.39, 24403.68, 24441.38, 24305.24, 24094.82, 23854.74, 23342.66, 23191.2,
          20834.39, 21140.07, 21515.61, 21399.83, 21529.12, 21368.08, 21559.04, 20241.05, 20037.6,
          19555.61, 20285.73, 19811.66, 20050.02, 20131.46, 19951.86, 19831.9, 20000.3, 19796.84,
          18790.61, 19292.84, 19319.77, 21360.11, 21648.34, 21826.87, 22395.74, 20173.57, 20226.71,
          19701.88, 19803.3, 20113.62, 19416.18, 19537.02, 18875, 18461.36, 19401.63, 19289.91,
          18920.5, 18807.38, 19227.82, 19079.13, 19412.82, 19591.51, 19422.61, 19310.95, 19056.8,
          19629.08, 20337.82, 20158.26, 19960.67, 19530.09, 19417.96, 19439.02,
        ],
      },
      {
        rsi_length_one: 2,
        rsi_smoothing_one: 2,
        qqe_factor_one: 2,
        threshold_one: 2,
        rsi_length_two: 2,
        rsi_smoothing_two: 2,
        qqe_factor_two: 1,
        threshold_two: 3,
        bollinger_length: 5,
        qqe_multiplier: 0.35,
      },
    );

    expect(bar_color_one).deep.eq([
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0,
      0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0,
    ]);
    expect(bar_color_two).deep.eq([
      -1.0, -1.0, -1.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, -1.0, -1.0,
      -1.0, -1.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, -1.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
      0.0, -1.0, -1.0, -1.0, -1.0, 0.0, 0.0, 0.0, 0.0, -1.0, -1.0, -1.0, -1.0, 0.0, -1.0, -1.0,
      -1.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, -1.0, 0.0, 0.0, 0.0, 0.0, -1.0,
      -1.0, -1.0,
    ]);
  });

  test('heatmap_vol', async () => {
    const { heatmap_level } = indicators.heatmap_vol(
      {
        volume: [
          144210.16219, 158073.28225, 145948.80995, 154854.67016, 175251.69749, 83911.80307,
          88890.00877, 170958.44152, 143182.50858, 208916.54953, 249759.79557, 174207.5704,
          152852.25435, 151206.14473, 242539.54758,
        ],
      },
      {
        length: 5,
        std_length: 5,
        threshold_extra_high: 4,
        threshold_high: 2.5,
        threshold_medium: 1,
        threshold_normal: -0.5,
      },
    );

    expect(heatmap_level).deep.eq([
      0.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 1.0, 1.0, 2.0, 2.0, 1.0, 0.0, 0.0, 2.0,
    ]);
  });
});
