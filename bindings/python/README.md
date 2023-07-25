# Cybotrade Indicators

This library provides a wide variety of technical analysis indicators, it was orignally forked from [tulipindicators](https://github.com/TulipCharts/tulipindicators) and we added additional indicators on top of the original ones.

## Installation

Installing this library is simple, just do 

```sh
pip install cybotrade-indicators
```

## Example

```py
from cybotrade_indicators import abs, rsi_divergence
import numpy as np

print(rsi_divergence(
    high=np.array([23509.68, 23459.89, 23647.68, 23223.32, 23472.86 ,23354.36, 23402, 24245, 23933.25, 24226]),
    low=np.array([22850, 22654.37, 22681.22, 22400, 22586.95,22909.52, 22844.62, 23154.25, 22865, 22664.69]),
    close=np.array([23268.01, 22987.79, 22818.37, 22622.98, 23312.42 ,22954.21, 23174.39, 23810, 23149.95, 23954.05]),
    left_bar=4,
    right_bar=2,
    rsi_length=6
))
```

The original documentation for [tulipindicators](https://github.com/TulipCharts/tulipindicators) can be found at [https://tulipindicators.org](https://tulipindicators.org). 

Below shows the list of additional indicators we have added:

```sh
    chaikin_vol "Chaikin Volatility"
    stoch_rsi "Stoch Rsi"
    supertrend "Supertrend"
    wavetrend "Wavetrend"
    andean_osc "Andean Osc"
    braid_filter "Braid Filter"
    boom_pro "Boom Pro"
    chandelier_exit "Chandelier Exit"
    cm_ema_trendbars "CM EMA TRENDBARS"
    di_dx "DI-DX"
    half_trend "Half Trend"
    heatmap_vol "Heatmap Volume"
    hull_suite "Hull Suite"
    macd_fastline_divergence "MACD Fastline Divergence"
    macd_hist_divergence "MACD Hist Divergence"
    mobo_band "Mobo Band"
    qqe_mod "QQE Mod"
    rsi_divergence "Relative Strength Index Divergence"
    rvi "Relative Volatility Index"
    rvi_divergence "Relative Volatility Index Divergence"
    ssl "SSL"
    stc "STC"
    stoch_divergence "Stochastic Divergence"
    sup_and_res "Support and Resistance"
    ut_bot "UT Bot Alert"
    volatility_oscillator "Volatility Oscillator"
    vu_man_chu_swing "VU Man Chu Swing"
    waddah "Waddah"
    psar "PSAR"
    dx "Directional Movement Index"
    adx "Average Directional Movement Index"
    dema "Double Exponential Moving Average"
    ema "Exponential Moving Average"
    hma "Hull Moving Average"
    sma "Simple Moving Average"
    tema "Triple Exponential Moving Average"
    trima "Triangular Moving Average"
    vwma "Volume Weighted Moving Average"
    wma "Weighted Moving Average"
    linreg "Linear Regression"
    bbands "Bollinger Bands"
    cci "Commodity Channel Index"
    stoch "Stochastic Oscillator"
    mfi "Money Flow Index"
    macd "Moving Average Convergence/Divergence"
    rsi "Relative Strength Index"
    natr "Normalized Average True Range"
    atr "Average True Range"
    insidebar "Inside Bar"
    price "Compare Price"
```