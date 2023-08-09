

# cybotrade-indicators: Python bindings for Cybotrade Indicators
# https://github.com/cybotrade/cybotrade-indicators
# Copyright (c) 2023 cybotrade-indicators authors
# https://github.com/cybotrade/cybotrade-indicators/blob/master/AUTHORS
#
# This file is part of cybotrade-indicators: Python bindings for Cybotrade Indicators.
#
# cybotrade-indicators is free software: you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License as published by the
# Free Software Foundation, either version 3 of the License, or (at your
# option) any later version.
#
# cybotrade-indicators is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License
# for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with cybotrade-indicators. If not, see <http://www.gnu.org/licenses/>.


# This file is generated. Do not modify directly.

from nptyping import NDArray, Float, Shape


def abs(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Absolute Value
    Inputs: real
    Options: 
    Outputs: abs
    """
    pass


def acos(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Arccosine
    Inputs: real
    Options: 
    Outputs: acos
    """
    pass


def ad(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], volume: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Accumulation/Distribution Line
    Inputs: high, low, close, volume
    Options: 
    Outputs: ad
    """
    pass


def add(value_one: NDArray[Shape["*", Float]], value_two: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Addition
    Inputs: value_one, value_two
    Options: 
    Outputs: add
    """
    pass


def adosc(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], volume: NDArray[Shape["*", Float]], short_period: float | int, long_period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Accumulation/Distribution Oscillator
    Inputs: high, low, close, volume
    Options: short_period, long_period
    Outputs: adosc
    """
    pass


def adx(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Average Directional Movement Index
    Inputs: high, low
    Options: period[14]
    Outputs: adx
    """
    pass


def adxr(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Average Directional Movement Rating
    Inputs: high, low
    Options: period
    Outputs: adxr
    """
    pass


def andean_osc(open: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], period: float | int, signal_length: float | int) -> NDArray[Shape["3 *"], Float]:
    """
    Andean Osc
    Inputs: open, close
    Options: period[50], signal_length[9]
    Outputs: ?bull_data, ?bear_data, ao_data
    """
    pass


def ao(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Awesome Oscillator
    Inputs: high, low
    Options: 
    Outputs: ao
    """
    pass


def apo(real: NDArray[Shape["*", Float]], short_period: float | int, long_period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Absolute Price Oscillator
    Inputs: real
    Options: short_period, long_period
    Outputs: apo
    """
    pass


def aroon(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    Aroon
    Inputs: high, low
    Options: period
    Outputs: aroon_down, aroon_up
    """
    pass


def aroonosc(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Aroon Oscillator
    Inputs: high, low
    Options: period
    Outputs: aroonosc
    """
    pass


def asin(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Arcsine
    Inputs: real
    Options: 
    Outputs: asin
    """
    pass


def atan(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Arctangent
    Inputs: real
    Options: 
    Outputs: atan
    """
    pass


def atr(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Average True Range
    Inputs: high, low, close
    Options: period[14]
    Outputs: atr
    """
    pass


def avgprice(open: NDArray[Shape["*", Float]], high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Average Price
    Inputs: open, high, low, close
    Options: 
    Outputs: avgprice
    """
    pass


def bbands(real: NDArray[Shape["*", Float]], period: float | int, stddev: float | int) -> NDArray[Shape["3 *"], Float]:
    """
    Bollinger Bands
    Inputs: real
    Options: period[20], stddev[2]
    Outputs: bbands_lower(ohlcv), bbands_middle(ohlcv), bbands_upper(ohlcv)
    """
    pass


def boom_pro(close: NDArray[Shape["*", Float]], lp_period_one: float | int, k1_quotient: float | int, trig_no: float | int, lp_period_two: float | int, k22_eot: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    Boom Pro
    Inputs: close
    Options: lp_period_one[6], k1_quotient[0], trig_no[2], lp_period_two[27], k22_eot[0.3]
    Outputs: trigger(ohlc), q4(ohlc)
    """
    pass


def bop(open: NDArray[Shape["*", Float]], high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Balance of Power
    Inputs: open, high, low, close
    Options: 
    Outputs: bop
    """
    pass


def braid_filter(open: NDArray[Shape["*", Float]], high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], ma01_length: float | int, ma02_length: float | int, ma03_length: float | int, pips_min_sep_percent: float | int) -> NDArray[Shape["3 *"], Float]:
    """
    Braid Filter
    Inputs: open, high, low, close
    Options: ma01_length[3], ma02_length[7], ma03_length[14], pips_min_sep_percent[40]
    Outputs: ?dif, ?atr_filter, bar_color
    """
    pass


def cci(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Commodity Channel Index
    Inputs: high, low, close
    Options: period[20]
    Outputs: cci
    """
    pass


def ceil(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Ceiling
    Inputs: real
    Options: 
    Outputs: ceil
    """
    pass


def chaikin_vol(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], ema_period: float | int, roc_period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Chaikin Volatility
    Inputs: high, low
    Options: ema_period[7], roc_period[14]
    Outputs: cvi
    """
    pass


def chandelier_exit(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], period: float | int, atr_multiplier: float | int) -> NDArray[Shape["*"], Float]:
    """
    Chandelier Exit
    Inputs: high, low, close
    Options: period[22], atr_multiplier[3]
    Outputs: buy_sell_signal
    """
    pass


def cm_ema_trendbars(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], ema_length: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    CM EMA TRENDBARS
    Inputs: high, low, close
    Options: ema_length[34]
    Outputs: ?usdema(ohlc), bar_color
    """
    pass


def cmo(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Chande Momentum Oscillator
    Inputs: real
    Options: period
    Outputs: cmo
    """
    pass


def cos(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Cosine
    Inputs: real
    Options: 
    Outputs: cos
    """
    pass


def cosh(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Hyperbolic Cosine
    Inputs: real
    Options: 
    Outputs: cosh
    """
    pass


def crossany(value_one: NDArray[Shape["*", Float]], value_two: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Crossany
    Inputs: value_one, value_two
    Options: 
    Outputs: crossany
    """
    pass


def crossover(value_one: NDArray[Shape["*", Float]], value_two: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Crossover
    Inputs: value_one, value_two
    Options: 
    Outputs: crossover
    """
    pass


def cvi(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Chaikins Volatility
    Inputs: high, low
    Options: period
    Outputs: cvi
    """
    pass


def decay(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Linear Decay
    Inputs: real
    Options: period
    Outputs: decay
    """
    pass


def dema(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Double Exponential Moving Average
    Inputs: real
    Options: period[9]
    Outputs: dema(ohlcv)
    """
    pass


def di(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    Directional Indicator
    Inputs: high, low, close
    Options: period
    Outputs: plus_di, minus_di
    """
    pass


def di_dx(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["3 *"], Float]:
    """
    DI-DX
    Inputs: high, low, close
    Options: period[14]
    Outputs: ?dx, di_plus, di_minus
    """
    pass


def div(value_one: NDArray[Shape["*", Float]], value_two: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Division
    Inputs: value_one, value_two
    Options: 
    Outputs: div
    """
    pass


def dm(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    Directional Movement
    Inputs: high, low
    Options: period
    Outputs: plus_dm, minus_dm
    """
    pass


def dpo(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Detrended Price Oscillator
    Inputs: real
    Options: period
    Outputs: dpo
    """
    pass


def dx(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Directional Movement Index
    Inputs: high, low
    Options: period[14]
    Outputs: dx
    """
    pass


def edecay(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Exponential Decay
    Inputs: real
    Options: period
    Outputs: edecay
    """
    pass


def ema(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Exponential Moving Average
    Inputs: real
    Options: period[9]
    Outputs: ema(ohlcv)
    """
    pass


def emv(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], volume: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Ease of Movement
    Inputs: high, low, volume
    Options: 
    Outputs: emv
    """
    pass


def exp(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Exponential
    Inputs: real
    Options: 
    Outputs: exp
    """
    pass


def floor(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Floor
    Inputs: real
    Options: 
    Outputs: floor
    """
    pass


def fosc(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Forecast Oscillator
    Inputs: real
    Options: period
    Outputs: fosc
    """
    pass


def ha(open: NDArray[Shape["*", Float]], high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]]) -> NDArray[Shape["4 *"], Float]:
    """
    Heikin-Ashi
    Inputs: open, high, low, close
    Options: 
    Outputs: ha_open, ha_high, ha_low, ha_close
    """
    pass


def half_trend(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], amplitude: float | int, channel_deviation: float | int, atr_length: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    Half Trend
    Inputs: high, low, close
    Options: amplitude[2], channel_deviation[2], atr_length[100]
    Outputs: ?ht(ohlc), bar_color
    """
    pass


def heatmap_vol(volume: NDArray[Shape["*", Float]], length: float | int, std_length: float | int, threshold_extra_high: float | int, threshold_high: float | int, threshold_medium: float | int, threshold_normal: float | int) -> NDArray[Shape["*"], Float]:
    """
    Heatmap Volume
    Inputs: volume
    Options: length[610], std_length[610], threshold_extra_high[4], threshold_high[2.5], threshold_medium[1], threshold_normal[-0.5]
    Outputs: heatmap_level
    """
    pass


def hlc3(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    HLC3
    Inputs: high, low, close
    Options: 
    Outputs: hlc3_data
    """
    pass


def hma(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Hull Moving Average
    Inputs: real
    Options: period[9]
    Outputs: hma(ohlcv)
    """
    pass


def hull_suite(close: NDArray[Shape["*", Float]], hma_length: float | int) -> NDArray[Shape["*"], Float]:
    """
    Hull Suite
    Inputs: close
    Options: hma_length[55]
    Outputs: bar_color
    """
    pass


def insidebar(open: NDArray[Shape["*", Float]], high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Inside Bar
    Inputs: open, high, low, close
    Options: 
    Outputs: buy_sell_signal
    """
    pass


def kama(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Kaufman Adaptive Moving Average
    Inputs: real
    Options: period
    Outputs: kama
    """
    pass


def kvo(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], volume: NDArray[Shape["*", Float]], short_period: float | int, long_period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Klinger Volume Oscillator
    Inputs: high, low, close, volume
    Options: short_period, long_period
    Outputs: kvo
    """
    pass


def lag(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Lag
    Inputs: real
    Options: period
    Outputs: lag
    """
    pass


def linreg(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Linear Regression
    Inputs: real
    Options: period[100]
    Outputs: linreg(ohlcv)
    """
    pass


def linregintercept(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Linear Regression Intercept
    Inputs: real
    Options: period
    Outputs: linregintercept
    """
    pass


def linregslope(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Linear Regression Slope
    Inputs: real
    Options: period
    Outputs: linregslope
    """
    pass


def ln(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Natural Log
    Inputs: real
    Options: 
    Outputs: ln
    """
    pass


def log10(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Base-10 Log
    Inputs: real
    Options: 
    Outputs: log10
    """
    pass


def macd(real: NDArray[Shape["*", Float]], short_period: float | int, long_period: float | int, signal_period: float | int) -> NDArray[Shape["3 *"], Float]:
    """
    Moving Average Convergence/Divergence
    Inputs: real
    Options: short_period[12], long_period[26], signal_period[9]
    Outputs: macd, macd_signal, ?macd_histogram
    """
    pass


def macd_fastline_divergence(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], fast_length: float | int, slow_length: float | int, signal_length: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    MACD Fastline Divergence
    Inputs: high, low, close
    Options: fast_length[12], slow_length[26], signal_length[9]
    Outputs: bull, bear
    """
    pass


def macd_hist_divergence(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], fast_length: float | int, slow_length: float | int, signal_length: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    MACD Hist Divergence
    Inputs: high, low, close
    Options: fast_length[12], slow_length[26], signal_length[9]
    Outputs: bull, bear
    """
    pass


def marketfi(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], volume: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Market Facilitation Index
    Inputs: high, low, volume
    Options: 
    Outputs: marketfi
    """
    pass


def mass(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Mass Index
    Inputs: high, low
    Options: period
    Outputs: mass
    """
    pass


def max(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Maximum In Period
    Inputs: real
    Options: period
    Outputs: max
    """
    pass


def md(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Mean Deviation Over Period
    Inputs: real
    Options: period
    Outputs: md
    """
    pass


def medprice(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Median Price
    Inputs: high, low
    Options: 
    Outputs: medprice
    """
    pass


def mfi(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], volume: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Money Flow Index
    Inputs: high, low, close, volume
    Options: period[14]
    Outputs: mfi
    """
    pass


def min(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Minimum In Period
    Inputs: real
    Options: period
    Outputs: min
    """
    pass


def mobo_band(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], dpo_length: float | int, mobo_length: float | int, num_dev_down: float | int, num_dev_up: float | int) -> NDArray[Shape["*"], Float]:
    """
    Mobo Band
    Inputs: high, low
    Options: dpo_length[13], mobo_length[10], num_dev_down[-0.8], num_dev_up[0.8]
    Outputs: buy_sell_signal
    """
    pass


def mom(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Momentum
    Inputs: real
    Options: period
    Outputs: mom
    """
    pass


def mul(value_one: NDArray[Shape["*", Float]], value_two: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Multiplication
    Inputs: value_one, value_two
    Options: 
    Outputs: mul
    """
    pass


def natr(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Normalized Average True Range
    Inputs: high, low, close
    Options: period[14]
    Outputs: natr
    """
    pass


def price(value: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Compare Price
    Inputs: value(ohlc)
    Options: 
    Outputs: price
    """
    pass


def psar(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], accel_start: float | int, accel_step: float | int, accel_max: float | int) -> NDArray[Shape["*"], Float]:
    """
    PSAR
    Inputs: high, low, close
    Options: accel_start[0.02], accel_step[0.02], accel_max[0.2]
    Outputs: psar(ohlc)
    """
    pass


def qqe_mod(close: NDArray[Shape["*", Float]], rsi_length_one: float | int, rsi_smoothing_one: float | int, qqe_factor_one: float | int, threshold_one: float | int, rsi_length_two: float | int, rsi_smoothing_two: float | int, qqe_factor_two: float | int, threshold_two: float | int, bollinger_length: float | int, qqe_multiplier: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    QQE Mod
    Inputs: close
    Options: rsi_length_one[6], rsi_smoothing_one[5], qqe_factor_one[3], threshold_one[3], rsi_length_two[6], rsi_smoothing_two[5], qqe_factor_two[1.61], threshold_two[3], bollinger_length[50], qqe_multiplier[0.35]
    Outputs: bar_color_one, bar_color_two
    """
    pass


def roc(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Rate of Change
    Inputs: real
    Options: period
    Outputs: roc
    """
    pass


def rocr(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Rate of Change Ratio
    Inputs: real
    Options: period
    Outputs: rocr
    """
    pass


def round(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Round
    Inputs: real
    Options: 
    Outputs: round
    """
    pass


def rsi(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Relative Strength Index
    Inputs: real
    Options: period[14]
    Outputs: rsi
    """
    pass


def rsi_divergence(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], left_bar: float | int, right_bar: float | int, rsi_length: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    Relative Strength Index Divergence
    Inputs: high, low, close
    Options: left_bar[6], right_bar[2], rsi_length[14]
    Outputs: bull, bear
    """
    pass


def rvi(close: NDArray[Shape["*", Float]], std_length: float | int, ema_length: float | int) -> NDArray[Shape["*"], Float]:
    """
    Relative Volatility Index
    Inputs: close
    Options: std_length[10], ema_length[14]
    Outputs: rvi
    """
    pass


def rvi_divergence(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], left_bar: float | int, right_bar: float | int, std_length: float | int, ema_length: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    Relative Volatility Index Divergence
    Inputs: high, low, close
    Options: left_bar[6], right_bar[2], std_length[12], ema_length[14]
    Outputs: bull, bear
    """
    pass


def sin(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Sine
    Inputs: real
    Options: 
    Outputs: sin
    """
    pass


def sinh(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Hyperbolic Sine
    Inputs: real
    Options: 
    Outputs: sinh
    """
    pass


def sma(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Simple Moving Average
    Inputs: real
    Options: period[7]
    Outputs: sma(ohlcv)
    """
    pass


def sqrt(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Square Root
    Inputs: real
    Options: 
    Outputs: sqrt
    """
    pass


def ssl(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], ma_length: float | int, ssl3_length: float | int) -> NDArray[Shape["6 *"], Float]:
    """
    SSL
    Inputs: high, low, close
    Options: ma_length[60], ssl3_length[15]
    Outputs: ?bbmc(ohlc), bar_color, ?up_erk(ohlc), ?low_erk(ohlc), ?cross_long, ?cross_short
    """
    pass


def stc(close: NDArray[Shape["*", Float]], length: float | int, fast_length: float | int, slow_length: float | int, aaa: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    STC
    Inputs: close
    Options: length[12], fast_length[26], slow_length[50], aaa[0.5]
    Outputs: ?stc, bar_color
    """
    pass


def stddev(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Standard Deviation Over Period
    Inputs: real
    Options: period
    Outputs: stddev
    """
    pass


def stderr(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Standard Error Over Period
    Inputs: real
    Options: period
    Outputs: stderr
    """
    pass


def stoch(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], k_period: float | int, k_slowing_period: float | int, d_period: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    Stochastic Oscillator
    Inputs: high, low, close
    Options: k_period[14], k_slowing_period[1], d_period[3]
    Outputs: stoch_k, stoch_d
    """
    pass


def stoch_divergence(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], left_bar: float | int, right_bar: float | int, stk_length: float | int, smooth_length: float | int, sma_length: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    Stochastic Divergence
    Inputs: high, low, close
    Options: left_bar[6], right_bar[2], stk_length[14], smooth_length[3], sma_length[3]
    Outputs: bull, bear
    """
    pass


def stoch_rsi(close: NDArray[Shape["*", Float]], smoothk: float | int, smoothd: float | int, rsi_period: float | int, stoch_period: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    Stoch Rsi
    Inputs: close
    Options: smoothk[3], smoothd[3], rsi_period[14], stoch_period[14]
    Outputs: stoch_k, stoch_d
    """
    pass


def stochrsi(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Stochastic RSI
    Inputs: real
    Options: period[14]
    Outputs: stochrsi
    """
    pass


def sub(value_one: NDArray[Shape["*", Float]], value_two: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Subtraction
    Inputs: value_one, value_two
    Options: 
    Outputs: sub
    """
    pass


def sum(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Sum Over Period
    Inputs: real
    Options: period
    Outputs: sum
    """
    pass


def sup_and_res(close: NDArray[Shape["*", Float]], left_bar: float | int, right_bar_one: float | int, right_bar_two: float | int, hma_length: float | int) -> NDArray[Shape["16 *"], Float]:
    """
    Support and Resistance
    Inputs: close
    Options: left_bar[200], right_bar_one[20], right_bar_two[5], hma_length[9]
    Outputs: buy_one, buy_two, buy_three, buy_four, buy_five, buy_six, buy_seven, buy_eight, sell_one, sell_two, sell_three, sell_four, sell_five, sell_six, sell_seven, sell_eight
    """
    pass


def supertrend(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], period: float | int, factor: float | int) -> NDArray[Shape["4 *"], Float]:
    """
    Supertrend
    Inputs: high, low, close
    Options: period[34], factor[3]
    Outputs: ?supertrend(ohlc), ?direction, bar_color, buy_sell_signal
    """
    pass


def tan(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Tangent
    Inputs: real
    Options: 
    Outputs: tan
    """
    pass


def tanh(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Hyperbolic Tangent
    Inputs: real
    Options: 
    Outputs: tanh
    """
    pass


def tema(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Triple Exponential Moving Average
    Inputs: real
    Options: period[9]
    Outputs: tema(ohlcv)
    """
    pass


def todeg(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Degree Conversion
    Inputs: real
    Options: 
    Outputs: degrees
    """
    pass


def torad(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Radian Conversion
    Inputs: real
    Options: 
    Outputs: radians
    """
    pass


def tr(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    True Range
    Inputs: high, low, close
    Options: 
    Outputs: tr
    """
    pass


def trima(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Triangular Moving Average
    Inputs: real
    Options: period[20]
    Outputs: trima(ohlcv)
    """
    pass


def trix(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Trix
    Inputs: real
    Options: period
    Outputs: trix
    """
    pass


def trunc(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Truncate
    Inputs: real
    Options: 
    Outputs: trunc
    """
    pass


def tsf(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Time Series Forecast
    Inputs: real
    Options: period
    Outputs: tsf
    """
    pass


def typprice(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Typical Price
    Inputs: high, low, close
    Options: 
    Outputs: typprice
    """
    pass


def ultosc(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], short_period: float | int, medium_period: float | int, long_period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Ultimate Oscillator
    Inputs: high, low, close
    Options: short_period, medium_period, long_period
    Outputs: ultosc
    """
    pass


def unshift(value: NDArray[Shape["*", Float]], default_value: float | int, length: float | int) -> NDArray[Shape["*"], Float]:
    """
    Unshift
    Inputs: value
    Options: default_value, length
    Outputs: unshifted_value
    """
    pass


def ut_bot(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], atr_period: float | int, sensitivity: float | int) -> NDArray[Shape["*"], Float]:
    """
    UT Bot Alert
    Inputs: high, low, close
    Options: atr_period[10], sensitivity[1]
    Outputs: buy_sell_signal
    """
    pass


def var(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Variance Over Period
    Inputs: real
    Options: period
    Outputs: var
    """
    pass


def vhf(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Vertical Horizontal Filter
    Inputs: real
    Options: period
    Outputs: vhf
    """
    pass


def volatility(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Annualized Historical Volatility
    Inputs: real
    Options: period
    Outputs: volatility
    """
    pass


def volatility_oscillator(open: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], length: float | int) -> NDArray[Shape["3 *"], Float]:
    """
    Volatility Oscillator
    Inputs: open, close
    Options: length[100]
    Outputs: spike_line, upper_line, lower_line
    """
    pass


def vosc(volume: NDArray[Shape["*", Float]], short_period: float | int, long_period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Volume Oscillator
    Inputs: volume
    Options: short_period, long_period
    Outputs: vosc
    """
    pass


def vu_man_chu_swing(close: NDArray[Shape["*", Float]], swing_period: float | int, swing_multiplier: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    VU Man Chu Swing
    Inputs: close
    Options: swing_period[20], swing_multiplier[3.5]
    Outputs: buy_sell_signal_long, buy_sell_signal_short
    """
    pass


def vwma(close: NDArray[Shape["*", Float]], volume: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Volume Weighted Moving Average
    Inputs: close, volume
    Options: period[20]
    Outputs: vwma(v)
    """
    pass


def wad(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Williams Accumulation/Distribution
    Inputs: high, low, close
    Options: 
    Outputs: wad
    """
    pass


def waddah(close: NDArray[Shape["*", Float]], fast_length: float | int, slow_length: float | int, signal_length: float | int, bb_length: float | int, multiplier: float | int, sensitivity: float | int) -> NDArray[Shape["4 *"], Float]:
    """
    Waddah
    Inputs: close
    Options: fast_length[20], slow_length[40], signal_length[9], bb_length[20], multiplier[2], sensitivity[150]
    Outputs: ?t, e, trend_up, trend_down
    """
    pass


def wavetrend(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], period_one: float | int, period_two: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    Wavetrend
    Inputs: high, low, close
    Options: period_one[9], period_two[12]
    Outputs: wavetrend_one, wavetrend_two
    """
    pass


def wcprice(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Weighted Close Price
    Inputs: high, low, close
    Options: 
    Outputs: wcprice
    """
    pass


def wilders(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Wilders Smoothing
    Inputs: real
    Options: period
    Outputs: wilders
    """
    pass


def willr(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Williams %R
    Inputs: high, low, close
    Options: period
    Outputs: willr
    """
    pass


def wma(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Weighted Moving Average
    Inputs: real
    Options: period[9]
    Outputs: wma(ohlcv)
    """
    pass

