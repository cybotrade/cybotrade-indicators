

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
    """
    pass


def acos(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Arccosine
    """
    pass


def ad(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], volume: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Accumulation/Distribution Line
    """
    pass


def add(value_one: NDArray[Shape["*", Float]], value_two: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Addition
    """
    pass


def adosc(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], volume: NDArray[Shape["*", Float]], short_period: float | int, long_period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Accumulation/Distribution Oscillator
    """
    pass


def adx(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Average Directional Movement Index
    """
    pass


def adxr(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Average Directional Movement Rating
    """
    pass


def andean_osc(open: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], period: float | int, signal_length: float | int) -> NDArray[Shape["3 *"], Float]:
    """
    Andean Osc
    """
    pass


def ao(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Awesome Oscillator
    """
    pass


def apo(real: NDArray[Shape["*", Float]], short_period: float | int, long_period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Absolute Price Oscillator
    """
    pass


def aroon(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    Aroon
    """
    pass


def aroonosc(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Aroon Oscillator
    """
    pass


def asin(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Arcsine
    """
    pass


def atan(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Arctangent
    """
    pass


def atr(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Average True Range
    """
    pass


def avgprice(open: NDArray[Shape["*", Float]], high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Average Price
    """
    pass


def bbands(real: NDArray[Shape["*", Float]], period: float | int, stddev: float | int) -> NDArray[Shape["3 *"], Float]:
    """
    Bollinger Bands
    """
    pass


def boom_pro(close: NDArray[Shape["*", Float]], lp_period_one: float | int, k1_quotient: float | int, trig_no: float | int, lp_period_two: float | int, k22_eot: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    Boom Pro
    """
    pass


def bop(open: NDArray[Shape["*", Float]], high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Balance of Power
    """
    pass


def braid_filter(open: NDArray[Shape["*", Float]], high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], ma01_length: float | int, ma02_length: float | int, ma03_length: float | int, pips_min_sep_percent: float | int) -> NDArray[Shape["3 *"], Float]:
    """
    Braid Filter
    """
    pass


def cci(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Commodity Channel Index
    """
    pass


def ceil(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Ceiling
    """
    pass


def chaikin_vol(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], ema_period: float | int, roc_period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Chaikin Volatility
    """
    pass


def chandelier_exit(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], period: float | int, atr_multiplier: float | int) -> NDArray[Shape["*"], Float]:
    """
    Chandelier Exit
    """
    pass


def cm_ema_trendbars(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], ema_length: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    CM EMA TRENDBARS
    """
    pass


def cmo(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Chande Momentum Oscillator
    """
    pass


def cos(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Cosine
    """
    pass


def cosh(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Hyperbolic Cosine
    """
    pass


def crossany(value_one: NDArray[Shape["*", Float]], value_two: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Crossany
    """
    pass


def crossover(value_one: NDArray[Shape["*", Float]], value_two: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Crossover
    """
    pass


def cvi(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Chaikins Volatility
    """
    pass


def decay(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Linear Decay
    """
    pass


def dema(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Double Exponential Moving Average
    """
    pass


def di(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    Directional Indicator
    """
    pass


def di_dx(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["3 *"], Float]:
    """
    DI-DX
    """
    pass


def div(value_one: NDArray[Shape["*", Float]], value_two: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Division
    """
    pass


def dm(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    Directional Movement
    """
    pass


def dpo(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Detrended Price Oscillator
    """
    pass


def dx(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Directional Movement Index
    """
    pass


def edecay(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Exponential Decay
    """
    pass


def ema(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Exponential Moving Average
    """
    pass


def emv(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], volume: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Ease of Movement
    """
    pass


def exp(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Exponential
    """
    pass


def floor(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Floor
    """
    pass


def fosc(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Forecast Oscillator
    """
    pass


def ha(open: NDArray[Shape["*", Float]], high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]]) -> NDArray[Shape["4 *"], Float]:
    """
    Heikin-Ashi
    """
    pass


def half_trend(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], amplitude: float | int, channel_deviation: float | int, atr_length: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    Half Trend
    """
    pass


def heatmap_vol(volume: NDArray[Shape["*", Float]], length: float | int, std_length: float | int, threshold_extra_high: float | int, threshold_high: float | int, threshold_medium: float | int, threshold_normal: float | int) -> NDArray[Shape["*"], Float]:
    """
    Heatmap Volume
    """
    pass


def hlc3(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    HLC3
    """
    pass


def hma(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Hull Moving Average
    """
    pass


def hull_suite(close: NDArray[Shape["*", Float]], hma_length: float | int) -> NDArray[Shape["*"], Float]:
    """
    Hull Suite
    """
    pass


def insidebar(open: NDArray[Shape["*", Float]], high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Inside Bar
    """
    pass


def kama(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Kaufman Adaptive Moving Average
    """
    pass


def kvo(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], volume: NDArray[Shape["*", Float]], short_period: float | int, long_period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Klinger Volume Oscillator
    """
    pass


def lag(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Lag
    """
    pass


def linreg(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Linear Regression
    """
    pass


def linregintercept(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Linear Regression Intercept
    """
    pass


def linregslope(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Linear Regression Slope
    """
    pass


def ln(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Natural Log
    """
    pass


def log10(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Base-10 Log
    """
    pass


def macd(real: NDArray[Shape["*", Float]], short_period: float | int, long_period: float | int, signal_period: float | int) -> NDArray[Shape["3 *"], Float]:
    """
    Moving Average Convergence/Divergence
    """
    pass


def macd_fastline_divergence(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], fast_length: float | int, slow_length: float | int, signal_length: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    MACD Fastline Divergence
    """
    pass


def macd_hist_divergence(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], fast_length: float | int, slow_length: float | int, signal_length: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    MACD Hist Divergence
    """
    pass


def marketfi(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], volume: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Market Facilitation Index
    """
    pass


def mass(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Mass Index
    """
    pass


def max(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Maximum In Period
    """
    pass


def md(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Mean Deviation Over Period
    """
    pass


def medprice(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Median Price
    """
    pass


def mfi(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], volume: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Money Flow Index
    """
    pass


def min(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Minimum In Period
    """
    pass


def mobo_band(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], dpo_length: float | int, mobo_length: float | int, num_dev_down: float | int, num_dev_up: float | int) -> NDArray[Shape["*"], Float]:
    """
    Mobo Band
    """
    pass


def mom(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Momentum
    """
    pass


def mul(value_one: NDArray[Shape["*", Float]], value_two: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Multiplication
    """
    pass


def natr(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Normalized Average True Range
    """
    pass


def price(value: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Compare Price
    """
    pass


def psar(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], accel_start: float | int, accel_step: float | int, accel_max: float | int) -> NDArray[Shape["*"], Float]:
    """
    PSAR
    """
    pass


def qqe_mod(close: NDArray[Shape["*", Float]], rsi_length_one: float | int, rsi_smoothing_one: float | int, qqe_factor_one: float | int, threshold_one: float | int, rsi_length_two: float | int, rsi_smoothing_two: float | int, qqe_factor_two: float | int, threshold_two: float | int, bollinger_length: float | int, qqe_multiplier: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    QQE Mod
    """
    pass


def roc(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Rate of Change
    """
    pass


def rocr(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Rate of Change Ratio
    """
    pass


def round(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Round
    """
    pass


def rsi(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Relative Strength Index
    """
    pass


def rsi_divergence(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], left_bar: float | int, right_bar: float | int, rsi_length: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    Relative Strength Index Divergence
    """
    pass


def rvi(close: NDArray[Shape["*", Float]], std_length: float | int, ema_length: float | int) -> NDArray[Shape["*"], Float]:
    """
    Relative Volatility Index
    """
    pass


def rvi_divergence(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], left_bar: float | int, right_bar: float | int, std_length: float | int, ema_length: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    Relative Volatility Index Divergence
    """
    pass


def sin(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Sine
    """
    pass


def sinh(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Hyperbolic Sine
    """
    pass


def sma(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Simple Moving Average
    """
    pass


def sqrt(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Square Root
    """
    pass


def ssl(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], ma_length: float | int, ssl3_length: float | int) -> NDArray[Shape["6 *"], Float]:
    """
    SSL
    """
    pass


def stc(close: NDArray[Shape["*", Float]], length: float | int, fast_length: float | int, slow_length: float | int, aaa: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    STC
    """
    pass


def stddev(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Standard Deviation Over Period
    """
    pass


def stderr(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Standard Error Over Period
    """
    pass


def stoch(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], k_period: float | int, k_slowing_period: float | int, d_period: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    Stochastic Oscillator
    """
    pass


def stoch_divergence(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], left_bar: float | int, right_bar: float | int, stk_length: float | int, smooth_length: float | int, sma_length: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    Stochastic Divergence
    """
    pass


def stoch_rsi(close: NDArray[Shape["*", Float]], smoothk: float | int, smoothd: float | int, rsi_period: float | int, stoch_period: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    Stoch Rsi
    """
    pass


def stochrsi(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Stochastic RSI
    """
    pass


def sub(value_one: NDArray[Shape["*", Float]], value_two: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Subtraction
    """
    pass


def sum(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Sum Over Period
    """
    pass


def sup_and_res(close: NDArray[Shape["*", Float]], left_bar: float | int, right_bar_one: float | int, right_bar_two: float | int, hma_length: float | int) -> NDArray[Shape["16 *"], Float]:
    """
    Support and Resistance
    """
    pass


def supertrend(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], period: float | int, factor: float | int) -> NDArray[Shape["4 *"], Float]:
    """
    Supertrend
    """
    pass


def tan(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Tangent
    """
    pass


def tanh(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Hyperbolic Tangent
    """
    pass


def tema(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Triple Exponential Moving Average
    """
    pass


def todeg(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Degree Conversion
    """
    pass


def torad(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Radian Conversion
    """
    pass


def tr(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    True Range
    """
    pass


def trima(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Triangular Moving Average
    """
    pass


def trix(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Trix
    """
    pass


def trunc(real: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Vector Truncate
    """
    pass


def tsf(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Time Series Forecast
    """
    pass


def typprice(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Typical Price
    """
    pass


def ultosc(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], short_period: float | int, medium_period: float | int, long_period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Ultimate Oscillator
    """
    pass


def unshift(value: NDArray[Shape["*", Float]], default_value: float | int, length: float | int) -> NDArray[Shape["*"], Float]:
    """
    Unshift
    """
    pass


def ut_bot(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], atr_period: float | int, sensitivity: float | int) -> NDArray[Shape["*"], Float]:
    """
    UT Bot Alert
    """
    pass


def var(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Variance Over Period
    """
    pass


def vhf(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Vertical Horizontal Filter
    """
    pass


def volatility(real: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Annualized Historical Volatility
    """
    pass


def volatility_oscillator(open: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], length: float | int) -> NDArray[Shape["3 *"], Float]:
    """
    Volatility Oscillator
    """
    pass


def vosc(volume: NDArray[Shape["*", Float]], short_period: float | int, long_period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Volume Oscillator
    """
    pass


def vu_man_chu_swing(close: NDArray[Shape["*", Float]], swing_period: float | int, swing_multiplier: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    VU Man Chu Swing
    """
    pass


def vwma(close: NDArray[Shape["*", Float]], volume: NDArray[Shape["*", Float]], period: float | int) -> NDArray[Shape["*"], Float]:
    """
    Volume Weighted Moving Average
    """
    pass


def wad(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Williams Accumulation/Distribution
    """
    pass


def waddah(close: NDArray[Shape["*", Float]], fast_length: float | int, slow_length: float | int, signal_length: float | int, bb_length: float | int, multiplier: float | int, sensitivity: float | int) -> NDArray[Shape["4 *"], Float]:
    """
    Waddah
    """
    pass


def wavetrend(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]], period_one: float | int, period_two: float | int) -> NDArray[Shape["2 *"], Float]:
    """
    Wavetrend
    """
    pass


def wcprice(high: NDArray[Shape["*", Float]], low: NDArray[Shape["*", Float]], close: NDArray[Shape["*", Float]]) -> NDArray[Shape["*"], Float]:
    """
    Weighted Close Price
    """
    pass

