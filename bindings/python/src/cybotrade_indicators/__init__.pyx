

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

# Alias builtins that are shadowed by indicators with the same name
try: # Python 3
    from builtins import min as builtin_min
except ImportError: # Python 2
    from __builtin__ import min as builtin_min

from libc.limits cimport INT_MAX

import numpy as np
cimport numpy as np

cimport cybotrade_indicators.indicators as ti

class InvalidOptionError(ValueError):
    pass

class InvalidInputError(ValueError):
    pass

cdef dict _type_names = {
    ti.TI_TYPE_OVERLAY:     b'overlay',
    ti.TI_TYPE_INDICATOR:   b'indicator',
    ti.TI_TYPE_MATH:        b'math',
    ti.TI_TYPE_SIMPLE:      b'simple',
    ti.TI_TYPE_COMPARATIVE: b'comparative',
}

cdef class _Indicator:
    cdef const ti.ti_indicator_info * info

    cdef readonly const char * name
    cdef readonly const char * full_name
    cdef readonly const char * type

    def __init__(self, int index):
        assert 0 <= index < ti.TI_INDICATOR_COUNT

        self.info = ti.ti_indicators + index
        self.name = self.info.name
        self.full_name = self.info.full_name
        self.type = _type_names[self.info.type]

    @property
    def inputs(self):
        return [
            self.info.input_names[i]
            for i in range(self.info.inputs)
        ]

    @property
    def options(self):
        return [
            self.info.option_names[i]
            for i in range(self.info.options)
        ]

    @property
    def outputs(self):
        return [
            self.info.output_names[i]
            for i in range(self.info.outputs)
        ]

    def __call__(self, inputs, options):
        cdef int min_input_len = INT_MAX
        for i in range(self.info.inputs):
            min_input_len = builtin_min(min_input_len, inputs[i].shape[0])

        option_list = options if options else [0.0]
        cdef np.ndarray[np.float64_t, ndim=1, mode='c'] c_options = np.array(option_list, dtype=np.float64)

        delta = self.info.start(&c_options[0])
        if min_input_len - delta <= 0:
            # This would cause self.info.indicator to return ti.TI_INVALID_OPTION, but there would
            # be a problem before we got there in creating the `outputs` np.ndarray below with a
            # negative dimension
            raise InvalidOptionError()

        cdef ti.TI_REAL * c_inputs[ti.TI_MAXINDPARAMS]
        cdef np.ndarray[np.float64_t, ndim=1, mode='c'] input_ref

        for i in range(self.info.inputs):
            if inputs[i].dtype == np.float64:
                input_ref = inputs[i][-min_input_len:]
            elif np.issubdtype(inputs[i].dtype, np.number):
                input_ref = inputs[i][-min_input_len:].astype(np.float64)
            else:
                raise InvalidInputError("Input arrays must have a numeric dtype")
            input_ref = inputs[i][-min_input_len:]
            c_inputs[i] = &input_ref[0]

        cdef ti.TI_REAL * c_outputs[ti.TI_MAXINDPARAMS]
        cdef np.ndarray[np.float64_t, ndim=2, mode='c'] outputs = np.empty((self.info.outputs, min_input_len - delta))
        for i in range(self.info.outputs):
            c_outputs[i] = &outputs[i,0]

        ret = self.info.indicator(min_input_len, c_inputs, &c_options[0], c_outputs)
        if ret == ti.TI_INVALID_OPTION:
            raise InvalidOptionError()

        if self.info.outputs == 1:
            return outputs[0]

        return tuple(outputs)


def abs(real):
    """
    Vector Absolute Value
    """

    return _Indicator(0)([real], [])

abs.full_name = _Indicator(0).full_name.decode()
abs.type = _Indicator(0).type.decode()
abs.inputs = [x.decode() for x in _Indicator(0).inputs]
abs.options = [x.decode() for x in _Indicator(0).options]
abs.outputs = [x.decode() for x in _Indicator(0).outputs]


def acos(real):
    """
    Vector Arccosine
    """

    return _Indicator(1)([real], [])

acos.full_name = _Indicator(1).full_name.decode()
acos.type = _Indicator(1).type.decode()
acos.inputs = [x.decode() for x in _Indicator(1).inputs]
acos.options = [x.decode() for x in _Indicator(1).options]
acos.outputs = [x.decode() for x in _Indicator(1).outputs]


def ad(high, low, close, volume):
    """
    Accumulation/Distribution Line
    """

    return _Indicator(2)([high, low, close, volume], [])

ad.full_name = _Indicator(2).full_name.decode()
ad.type = _Indicator(2).type.decode()
ad.inputs = [x.decode() for x in _Indicator(2).inputs]
ad.options = [x.decode() for x in _Indicator(2).options]
ad.outputs = [x.decode() for x in _Indicator(2).outputs]


def add(value_one, value_two):
    """
    Vector Addition
    """

    return _Indicator(3)([value_one, value_two], [])

add.full_name = _Indicator(3).full_name.decode()
add.type = _Indicator(3).type.decode()
add.inputs = [x.decode() for x in _Indicator(3).inputs]
add.options = [x.decode() for x in _Indicator(3).options]
add.outputs = [x.decode() for x in _Indicator(3).outputs]


def adosc(high, low, close, volume, short_period, long_period):
    """
    Accumulation/Distribution Oscillator
    """

    return _Indicator(4)([high, low, close, volume], [short_period, long_period])

adosc.full_name = _Indicator(4).full_name.decode()
adosc.type = _Indicator(4).type.decode()
adosc.inputs = [x.decode() for x in _Indicator(4).inputs]
adosc.options = [x.decode() for x in _Indicator(4).options]
adosc.outputs = [x.decode() for x in _Indicator(4).outputs]


def adx(high, low, period):
    """
    Average Directional Movement Index
    """

    return _Indicator(5)([high, low], [period])

adx.full_name = _Indicator(5).full_name.decode()
adx.type = _Indicator(5).type.decode()
adx.inputs = [x.decode() for x in _Indicator(5).inputs]
adx.options = [x.decode() for x in _Indicator(5).options]
adx.outputs = [x.decode() for x in _Indicator(5).outputs]


def adxr(high, low, period):
    """
    Average Directional Movement Rating
    """

    return _Indicator(6)([high, low], [period])

adxr.full_name = _Indicator(6).full_name.decode()
adxr.type = _Indicator(6).type.decode()
adxr.inputs = [x.decode() for x in _Indicator(6).inputs]
adxr.options = [x.decode() for x in _Indicator(6).options]
adxr.outputs = [x.decode() for x in _Indicator(6).outputs]


def andean_osc(open, close, period, signal_length):
    """
    Andean Osc
    """

    return _Indicator(7)([open, close], [period, signal_length])

andean_osc.full_name = _Indicator(7).full_name.decode()
andean_osc.type = _Indicator(7).type.decode()
andean_osc.inputs = [x.decode() for x in _Indicator(7).inputs]
andean_osc.options = [x.decode() for x in _Indicator(7).options]
andean_osc.outputs = [x.decode() for x in _Indicator(7).outputs]


def ao(high, low):
    """
    Awesome Oscillator
    """

    return _Indicator(8)([high, low], [])

ao.full_name = _Indicator(8).full_name.decode()
ao.type = _Indicator(8).type.decode()
ao.inputs = [x.decode() for x in _Indicator(8).inputs]
ao.options = [x.decode() for x in _Indicator(8).options]
ao.outputs = [x.decode() for x in _Indicator(8).outputs]


def apo(real, short_period, long_period):
    """
    Absolute Price Oscillator
    """

    return _Indicator(9)([real], [short_period, long_period])

apo.full_name = _Indicator(9).full_name.decode()
apo.type = _Indicator(9).type.decode()
apo.inputs = [x.decode() for x in _Indicator(9).inputs]
apo.options = [x.decode() for x in _Indicator(9).options]
apo.outputs = [x.decode() for x in _Indicator(9).outputs]


def aroon(high, low, period):
    """
    Aroon
    """

    return _Indicator(10)([high, low], [period])

aroon.full_name = _Indicator(10).full_name.decode()
aroon.type = _Indicator(10).type.decode()
aroon.inputs = [x.decode() for x in _Indicator(10).inputs]
aroon.options = [x.decode() for x in _Indicator(10).options]
aroon.outputs = [x.decode() for x in _Indicator(10).outputs]


def aroonosc(high, low, period):
    """
    Aroon Oscillator
    """

    return _Indicator(11)([high, low], [period])

aroonosc.full_name = _Indicator(11).full_name.decode()
aroonosc.type = _Indicator(11).type.decode()
aroonosc.inputs = [x.decode() for x in _Indicator(11).inputs]
aroonosc.options = [x.decode() for x in _Indicator(11).options]
aroonosc.outputs = [x.decode() for x in _Indicator(11).outputs]


def asin(real):
    """
    Vector Arcsine
    """

    return _Indicator(12)([real], [])

asin.full_name = _Indicator(12).full_name.decode()
asin.type = _Indicator(12).type.decode()
asin.inputs = [x.decode() for x in _Indicator(12).inputs]
asin.options = [x.decode() for x in _Indicator(12).options]
asin.outputs = [x.decode() for x in _Indicator(12).outputs]


def atan(real):
    """
    Vector Arctangent
    """

    return _Indicator(13)([real], [])

atan.full_name = _Indicator(13).full_name.decode()
atan.type = _Indicator(13).type.decode()
atan.inputs = [x.decode() for x in _Indicator(13).inputs]
atan.options = [x.decode() for x in _Indicator(13).options]
atan.outputs = [x.decode() for x in _Indicator(13).outputs]


def atr(high, low, close, period):
    """
    Average True Range
    """

    return _Indicator(14)([high, low, close], [period])

atr.full_name = _Indicator(14).full_name.decode()
atr.type = _Indicator(14).type.decode()
atr.inputs = [x.decode() for x in _Indicator(14).inputs]
atr.options = [x.decode() for x in _Indicator(14).options]
atr.outputs = [x.decode() for x in _Indicator(14).outputs]


def avgprice(open, high, low, close):
    """
    Average Price
    """

    return _Indicator(15)([open, high, low, close], [])

avgprice.full_name = _Indicator(15).full_name.decode()
avgprice.type = _Indicator(15).type.decode()
avgprice.inputs = [x.decode() for x in _Indicator(15).inputs]
avgprice.options = [x.decode() for x in _Indicator(15).options]
avgprice.outputs = [x.decode() for x in _Indicator(15).outputs]


def bbands(real, period, stddev):
    """
    Bollinger Bands
    """

    return _Indicator(16)([real], [period, stddev])

bbands.full_name = _Indicator(16).full_name.decode()
bbands.type = _Indicator(16).type.decode()
bbands.inputs = [x.decode() for x in _Indicator(16).inputs]
bbands.options = [x.decode() for x in _Indicator(16).options]
bbands.outputs = [x.decode() for x in _Indicator(16).outputs]


def boom_pro(close, lp_period_one, k1_quotient, trig_no, lp_period_two, k22_eot):
    """
    Boom Pro
    """

    return _Indicator(17)([close], [lp_period_one, k1_quotient, trig_no, lp_period_two, k22_eot])

boom_pro.full_name = _Indicator(17).full_name.decode()
boom_pro.type = _Indicator(17).type.decode()
boom_pro.inputs = [x.decode() for x in _Indicator(17).inputs]
boom_pro.options = [x.decode() for x in _Indicator(17).options]
boom_pro.outputs = [x.decode() for x in _Indicator(17).outputs]


def bop(open, high, low, close):
    """
    Balance of Power
    """

    return _Indicator(18)([open, high, low, close], [])

bop.full_name = _Indicator(18).full_name.decode()
bop.type = _Indicator(18).type.decode()
bop.inputs = [x.decode() for x in _Indicator(18).inputs]
bop.options = [x.decode() for x in _Indicator(18).options]
bop.outputs = [x.decode() for x in _Indicator(18).outputs]


def braid_filter(open, high, low, close, ma01_length, ma02_length, ma03_length, pips_min_sep_percent):
    """
    Braid Filter
    """

    return _Indicator(19)([open, high, low, close], [ma01_length, ma02_length, ma03_length, pips_min_sep_percent])

braid_filter.full_name = _Indicator(19).full_name.decode()
braid_filter.type = _Indicator(19).type.decode()
braid_filter.inputs = [x.decode() for x in _Indicator(19).inputs]
braid_filter.options = [x.decode() for x in _Indicator(19).options]
braid_filter.outputs = [x.decode() for x in _Indicator(19).outputs]


def cci(high, low, close, period):
    """
    Commodity Channel Index
    """

    return _Indicator(20)([high, low, close], [period])

cci.full_name = _Indicator(20).full_name.decode()
cci.type = _Indicator(20).type.decode()
cci.inputs = [x.decode() for x in _Indicator(20).inputs]
cci.options = [x.decode() for x in _Indicator(20).options]
cci.outputs = [x.decode() for x in _Indicator(20).outputs]


def ceil(real):
    """
    Vector Ceiling
    """

    return _Indicator(21)([real], [])

ceil.full_name = _Indicator(21).full_name.decode()
ceil.type = _Indicator(21).type.decode()
ceil.inputs = [x.decode() for x in _Indicator(21).inputs]
ceil.options = [x.decode() for x in _Indicator(21).options]
ceil.outputs = [x.decode() for x in _Indicator(21).outputs]


def chaikin_vol(high, low, ema_period, roc_period):
    """
    Chaikin Volatility
    """

    return _Indicator(22)([high, low], [ema_period, roc_period])

chaikin_vol.full_name = _Indicator(22).full_name.decode()
chaikin_vol.type = _Indicator(22).type.decode()
chaikin_vol.inputs = [x.decode() for x in _Indicator(22).inputs]
chaikin_vol.options = [x.decode() for x in _Indicator(22).options]
chaikin_vol.outputs = [x.decode() for x in _Indicator(22).outputs]


def chandelier_exit(high, low, close, period, atr_multiplier):
    """
    Chandelier Exit
    """

    return _Indicator(23)([high, low, close], [period, atr_multiplier])

chandelier_exit.full_name = _Indicator(23).full_name.decode()
chandelier_exit.type = _Indicator(23).type.decode()
chandelier_exit.inputs = [x.decode() for x in _Indicator(23).inputs]
chandelier_exit.options = [x.decode() for x in _Indicator(23).options]
chandelier_exit.outputs = [x.decode() for x in _Indicator(23).outputs]


def cm_ema_trendbars(high, low, close, ema_length):
    """
    CM EMA TRENDBARS
    """

    return _Indicator(24)([high, low, close], [ema_length])

cm_ema_trendbars.full_name = _Indicator(24).full_name.decode()
cm_ema_trendbars.type = _Indicator(24).type.decode()
cm_ema_trendbars.inputs = [x.decode() for x in _Indicator(24).inputs]
cm_ema_trendbars.options = [x.decode() for x in _Indicator(24).options]
cm_ema_trendbars.outputs = [x.decode() for x in _Indicator(24).outputs]


def cmo(real, period):
    """
    Chande Momentum Oscillator
    """

    return _Indicator(25)([real], [period])

cmo.full_name = _Indicator(25).full_name.decode()
cmo.type = _Indicator(25).type.decode()
cmo.inputs = [x.decode() for x in _Indicator(25).inputs]
cmo.options = [x.decode() for x in _Indicator(25).options]
cmo.outputs = [x.decode() for x in _Indicator(25).outputs]


def cos(real):
    """
    Vector Cosine
    """

    return _Indicator(26)([real], [])

cos.full_name = _Indicator(26).full_name.decode()
cos.type = _Indicator(26).type.decode()
cos.inputs = [x.decode() for x in _Indicator(26).inputs]
cos.options = [x.decode() for x in _Indicator(26).options]
cos.outputs = [x.decode() for x in _Indicator(26).outputs]


def cosh(real):
    """
    Vector Hyperbolic Cosine
    """

    return _Indicator(27)([real], [])

cosh.full_name = _Indicator(27).full_name.decode()
cosh.type = _Indicator(27).type.decode()
cosh.inputs = [x.decode() for x in _Indicator(27).inputs]
cosh.options = [x.decode() for x in _Indicator(27).options]
cosh.outputs = [x.decode() for x in _Indicator(27).outputs]


def crossany(value_one, value_two):
    """
    Crossany
    """

    return _Indicator(28)([value_one, value_two], [])

crossany.full_name = _Indicator(28).full_name.decode()
crossany.type = _Indicator(28).type.decode()
crossany.inputs = [x.decode() for x in _Indicator(28).inputs]
crossany.options = [x.decode() for x in _Indicator(28).options]
crossany.outputs = [x.decode() for x in _Indicator(28).outputs]


def crossover(value_one, value_two):
    """
    Crossover
    """

    return _Indicator(29)([value_one, value_two], [])

crossover.full_name = _Indicator(29).full_name.decode()
crossover.type = _Indicator(29).type.decode()
crossover.inputs = [x.decode() for x in _Indicator(29).inputs]
crossover.options = [x.decode() for x in _Indicator(29).options]
crossover.outputs = [x.decode() for x in _Indicator(29).outputs]


def cvi(high, low, period):
    """
    Chaikins Volatility
    """

    return _Indicator(30)([high, low], [period])

cvi.full_name = _Indicator(30).full_name.decode()
cvi.type = _Indicator(30).type.decode()
cvi.inputs = [x.decode() for x in _Indicator(30).inputs]
cvi.options = [x.decode() for x in _Indicator(30).options]
cvi.outputs = [x.decode() for x in _Indicator(30).outputs]


def decay(real, period):
    """
    Linear Decay
    """

    return _Indicator(31)([real], [period])

decay.full_name = _Indicator(31).full_name.decode()
decay.type = _Indicator(31).type.decode()
decay.inputs = [x.decode() for x in _Indicator(31).inputs]
decay.options = [x.decode() for x in _Indicator(31).options]
decay.outputs = [x.decode() for x in _Indicator(31).outputs]


def dema(real, period):
    """
    Double Exponential Moving Average
    """

    return _Indicator(32)([real], [period])

dema.full_name = _Indicator(32).full_name.decode()
dema.type = _Indicator(32).type.decode()
dema.inputs = [x.decode() for x in _Indicator(32).inputs]
dema.options = [x.decode() for x in _Indicator(32).options]
dema.outputs = [x.decode() for x in _Indicator(32).outputs]


def di(high, low, close, period):
    """
    Directional Indicator
    """

    return _Indicator(33)([high, low, close], [period])

di.full_name = _Indicator(33).full_name.decode()
di.type = _Indicator(33).type.decode()
di.inputs = [x.decode() for x in _Indicator(33).inputs]
di.options = [x.decode() for x in _Indicator(33).options]
di.outputs = [x.decode() for x in _Indicator(33).outputs]


def di_dx(high, low, close, period):
    """
    DI-DX
    """

    return _Indicator(34)([high, low, close], [period])

di_dx.full_name = _Indicator(34).full_name.decode()
di_dx.type = _Indicator(34).type.decode()
di_dx.inputs = [x.decode() for x in _Indicator(34).inputs]
di_dx.options = [x.decode() for x in _Indicator(34).options]
di_dx.outputs = [x.decode() for x in _Indicator(34).outputs]


def div(value_one, value_two):
    """
    Vector Division
    """

    return _Indicator(35)([value_one, value_two], [])

div.full_name = _Indicator(35).full_name.decode()
div.type = _Indicator(35).type.decode()
div.inputs = [x.decode() for x in _Indicator(35).inputs]
div.options = [x.decode() for x in _Indicator(35).options]
div.outputs = [x.decode() for x in _Indicator(35).outputs]


def dm(high, low, period):
    """
    Directional Movement
    """

    return _Indicator(36)([high, low], [period])

dm.full_name = _Indicator(36).full_name.decode()
dm.type = _Indicator(36).type.decode()
dm.inputs = [x.decode() for x in _Indicator(36).inputs]
dm.options = [x.decode() for x in _Indicator(36).options]
dm.outputs = [x.decode() for x in _Indicator(36).outputs]


def dpo(real, period):
    """
    Detrended Price Oscillator
    """

    return _Indicator(37)([real], [period])

dpo.full_name = _Indicator(37).full_name.decode()
dpo.type = _Indicator(37).type.decode()
dpo.inputs = [x.decode() for x in _Indicator(37).inputs]
dpo.options = [x.decode() for x in _Indicator(37).options]
dpo.outputs = [x.decode() for x in _Indicator(37).outputs]


def dx(high, low, period):
    """
    Directional Movement Index
    """

    return _Indicator(38)([high, low], [period])

dx.full_name = _Indicator(38).full_name.decode()
dx.type = _Indicator(38).type.decode()
dx.inputs = [x.decode() for x in _Indicator(38).inputs]
dx.options = [x.decode() for x in _Indicator(38).options]
dx.outputs = [x.decode() for x in _Indicator(38).outputs]


def edecay(real, period):
    """
    Exponential Decay
    """

    return _Indicator(39)([real], [period])

edecay.full_name = _Indicator(39).full_name.decode()
edecay.type = _Indicator(39).type.decode()
edecay.inputs = [x.decode() for x in _Indicator(39).inputs]
edecay.options = [x.decode() for x in _Indicator(39).options]
edecay.outputs = [x.decode() for x in _Indicator(39).outputs]


def ema(real, period):
    """
    Exponential Moving Average
    """

    return _Indicator(40)([real], [period])

ema.full_name = _Indicator(40).full_name.decode()
ema.type = _Indicator(40).type.decode()
ema.inputs = [x.decode() for x in _Indicator(40).inputs]
ema.options = [x.decode() for x in _Indicator(40).options]
ema.outputs = [x.decode() for x in _Indicator(40).outputs]


def emv(high, low, volume):
    """
    Ease of Movement
    """

    return _Indicator(41)([high, low, volume], [])

emv.full_name = _Indicator(41).full_name.decode()
emv.type = _Indicator(41).type.decode()
emv.inputs = [x.decode() for x in _Indicator(41).inputs]
emv.options = [x.decode() for x in _Indicator(41).options]
emv.outputs = [x.decode() for x in _Indicator(41).outputs]


def exp(real):
    """
    Vector Exponential
    """

    return _Indicator(42)([real], [])

exp.full_name = _Indicator(42).full_name.decode()
exp.type = _Indicator(42).type.decode()
exp.inputs = [x.decode() for x in _Indicator(42).inputs]
exp.options = [x.decode() for x in _Indicator(42).options]
exp.outputs = [x.decode() for x in _Indicator(42).outputs]


def floor(real):
    """
    Vector Floor
    """

    return _Indicator(43)([real], [])

floor.full_name = _Indicator(43).full_name.decode()
floor.type = _Indicator(43).type.decode()
floor.inputs = [x.decode() for x in _Indicator(43).inputs]
floor.options = [x.decode() for x in _Indicator(43).options]
floor.outputs = [x.decode() for x in _Indicator(43).outputs]


def fosc(real, period):
    """
    Forecast Oscillator
    """

    return _Indicator(44)([real], [period])

fosc.full_name = _Indicator(44).full_name.decode()
fosc.type = _Indicator(44).type.decode()
fosc.inputs = [x.decode() for x in _Indicator(44).inputs]
fosc.options = [x.decode() for x in _Indicator(44).options]
fosc.outputs = [x.decode() for x in _Indicator(44).outputs]


def ha(open, high, low, close):
    """
    Heikin-Ashi
    """

    return _Indicator(45)([open, high, low, close], [])

ha.full_name = _Indicator(45).full_name.decode()
ha.type = _Indicator(45).type.decode()
ha.inputs = [x.decode() for x in _Indicator(45).inputs]
ha.options = [x.decode() for x in _Indicator(45).options]
ha.outputs = [x.decode() for x in _Indicator(45).outputs]


def half_trend(high, low, close, amplitude, channel_deviation, atr_length):
    """
    Half Trend
    """

    return _Indicator(46)([high, low, close], [amplitude, channel_deviation, atr_length])

half_trend.full_name = _Indicator(46).full_name.decode()
half_trend.type = _Indicator(46).type.decode()
half_trend.inputs = [x.decode() for x in _Indicator(46).inputs]
half_trend.options = [x.decode() for x in _Indicator(46).options]
half_trend.outputs = [x.decode() for x in _Indicator(46).outputs]


def heatmap_vol(volume, length, std_length, threshold_extra_high, threshold_high, threshold_medium, threshold_normal):
    """
    Heatmap Volume
    """

    return _Indicator(47)([volume], [length, std_length, threshold_extra_high, threshold_high, threshold_medium, threshold_normal])

heatmap_vol.full_name = _Indicator(47).full_name.decode()
heatmap_vol.type = _Indicator(47).type.decode()
heatmap_vol.inputs = [x.decode() for x in _Indicator(47).inputs]
heatmap_vol.options = [x.decode() for x in _Indicator(47).options]
heatmap_vol.outputs = [x.decode() for x in _Indicator(47).outputs]


def hlc3(high, low, close):
    """
    HLC3
    """

    return _Indicator(48)([high, low, close], [])

hlc3.full_name = _Indicator(48).full_name.decode()
hlc3.type = _Indicator(48).type.decode()
hlc3.inputs = [x.decode() for x in _Indicator(48).inputs]
hlc3.options = [x.decode() for x in _Indicator(48).options]
hlc3.outputs = [x.decode() for x in _Indicator(48).outputs]


def hma(real, period):
    """
    Hull Moving Average
    """

    return _Indicator(49)([real], [period])

hma.full_name = _Indicator(49).full_name.decode()
hma.type = _Indicator(49).type.decode()
hma.inputs = [x.decode() for x in _Indicator(49).inputs]
hma.options = [x.decode() for x in _Indicator(49).options]
hma.outputs = [x.decode() for x in _Indicator(49).outputs]


def hull_suite(close, hma_length):
    """
    Hull Suite
    """

    return _Indicator(50)([close], [hma_length])

hull_suite.full_name = _Indicator(50).full_name.decode()
hull_suite.type = _Indicator(50).type.decode()
hull_suite.inputs = [x.decode() for x in _Indicator(50).inputs]
hull_suite.options = [x.decode() for x in _Indicator(50).options]
hull_suite.outputs = [x.decode() for x in _Indicator(50).outputs]


def insidebar(open, high, low, close):
    """
    Inside Bar
    """

    return _Indicator(51)([open, high, low, close], [])

insidebar.full_name = _Indicator(51).full_name.decode()
insidebar.type = _Indicator(51).type.decode()
insidebar.inputs = [x.decode() for x in _Indicator(51).inputs]
insidebar.options = [x.decode() for x in _Indicator(51).options]
insidebar.outputs = [x.decode() for x in _Indicator(51).outputs]


def kama(real, period):
    """
    Kaufman Adaptive Moving Average
    """

    return _Indicator(52)([real], [period])

kama.full_name = _Indicator(52).full_name.decode()
kama.type = _Indicator(52).type.decode()
kama.inputs = [x.decode() for x in _Indicator(52).inputs]
kama.options = [x.decode() for x in _Indicator(52).options]
kama.outputs = [x.decode() for x in _Indicator(52).outputs]


def kvo(high, low, close, volume, short_period, long_period):
    """
    Klinger Volume Oscillator
    """

    return _Indicator(53)([high, low, close, volume], [short_period, long_period])

kvo.full_name = _Indicator(53).full_name.decode()
kvo.type = _Indicator(53).type.decode()
kvo.inputs = [x.decode() for x in _Indicator(53).inputs]
kvo.options = [x.decode() for x in _Indicator(53).options]
kvo.outputs = [x.decode() for x in _Indicator(53).outputs]


def lag(real, period):
    """
    Lag
    """

    return _Indicator(54)([real], [period])

lag.full_name = _Indicator(54).full_name.decode()
lag.type = _Indicator(54).type.decode()
lag.inputs = [x.decode() for x in _Indicator(54).inputs]
lag.options = [x.decode() for x in _Indicator(54).options]
lag.outputs = [x.decode() for x in _Indicator(54).outputs]


def linreg(real, period):
    """
    Linear Regression
    """

    return _Indicator(55)([real], [period])

linreg.full_name = _Indicator(55).full_name.decode()
linreg.type = _Indicator(55).type.decode()
linreg.inputs = [x.decode() for x in _Indicator(55).inputs]
linreg.options = [x.decode() for x in _Indicator(55).options]
linreg.outputs = [x.decode() for x in _Indicator(55).outputs]


def linregintercept(real, period):
    """
    Linear Regression Intercept
    """

    return _Indicator(56)([real], [period])

linregintercept.full_name = _Indicator(56).full_name.decode()
linregintercept.type = _Indicator(56).type.decode()
linregintercept.inputs = [x.decode() for x in _Indicator(56).inputs]
linregintercept.options = [x.decode() for x in _Indicator(56).options]
linregintercept.outputs = [x.decode() for x in _Indicator(56).outputs]


def linregslope(real, period):
    """
    Linear Regression Slope
    """

    return _Indicator(57)([real], [period])

linregslope.full_name = _Indicator(57).full_name.decode()
linregslope.type = _Indicator(57).type.decode()
linregslope.inputs = [x.decode() for x in _Indicator(57).inputs]
linregslope.options = [x.decode() for x in _Indicator(57).options]
linregslope.outputs = [x.decode() for x in _Indicator(57).outputs]


def ln(real):
    """
    Vector Natural Log
    """

    return _Indicator(58)([real], [])

ln.full_name = _Indicator(58).full_name.decode()
ln.type = _Indicator(58).type.decode()
ln.inputs = [x.decode() for x in _Indicator(58).inputs]
ln.options = [x.decode() for x in _Indicator(58).options]
ln.outputs = [x.decode() for x in _Indicator(58).outputs]


def log10(real):
    """
    Vector Base-10 Log
    """

    return _Indicator(59)([real], [])

log10.full_name = _Indicator(59).full_name.decode()
log10.type = _Indicator(59).type.decode()
log10.inputs = [x.decode() for x in _Indicator(59).inputs]
log10.options = [x.decode() for x in _Indicator(59).options]
log10.outputs = [x.decode() for x in _Indicator(59).outputs]


def macd(real, short_period, long_period, signal_period):
    """
    Moving Average Convergence/Divergence
    """

    return _Indicator(60)([real], [short_period, long_period, signal_period])

macd.full_name = _Indicator(60).full_name.decode()
macd.type = _Indicator(60).type.decode()
macd.inputs = [x.decode() for x in _Indicator(60).inputs]
macd.options = [x.decode() for x in _Indicator(60).options]
macd.outputs = [x.decode() for x in _Indicator(60).outputs]


def macd_fastline_divergence(high, low, close, fast_length, slow_length, signal_length):
    """
    MACD Fastline Divergence
    """

    return _Indicator(61)([high, low, close], [fast_length, slow_length, signal_length])

macd_fastline_divergence.full_name = _Indicator(61).full_name.decode()
macd_fastline_divergence.type = _Indicator(61).type.decode()
macd_fastline_divergence.inputs = [x.decode() for x in _Indicator(61).inputs]
macd_fastline_divergence.options = [x.decode() for x in _Indicator(61).options]
macd_fastline_divergence.outputs = [x.decode() for x in _Indicator(61).outputs]


def macd_hist_divergence(high, low, close, fast_length, slow_length, signal_length):
    """
    MACD Hist Divergence
    """

    return _Indicator(62)([high, low, close], [fast_length, slow_length, signal_length])

macd_hist_divergence.full_name = _Indicator(62).full_name.decode()
macd_hist_divergence.type = _Indicator(62).type.decode()
macd_hist_divergence.inputs = [x.decode() for x in _Indicator(62).inputs]
macd_hist_divergence.options = [x.decode() for x in _Indicator(62).options]
macd_hist_divergence.outputs = [x.decode() for x in _Indicator(62).outputs]


def marketfi(high, low, volume):
    """
    Market Facilitation Index
    """

    return _Indicator(63)([high, low, volume], [])

marketfi.full_name = _Indicator(63).full_name.decode()
marketfi.type = _Indicator(63).type.decode()
marketfi.inputs = [x.decode() for x in _Indicator(63).inputs]
marketfi.options = [x.decode() for x in _Indicator(63).options]
marketfi.outputs = [x.decode() for x in _Indicator(63).outputs]


def mass(high, low, period):
    """
    Mass Index
    """

    return _Indicator(64)([high, low], [period])

mass.full_name = _Indicator(64).full_name.decode()
mass.type = _Indicator(64).type.decode()
mass.inputs = [x.decode() for x in _Indicator(64).inputs]
mass.options = [x.decode() for x in _Indicator(64).options]
mass.outputs = [x.decode() for x in _Indicator(64).outputs]


def max(real, period):
    """
    Maximum In Period
    """

    return _Indicator(65)([real], [period])

max.full_name = _Indicator(65).full_name.decode()
max.type = _Indicator(65).type.decode()
max.inputs = [x.decode() for x in _Indicator(65).inputs]
max.options = [x.decode() for x in _Indicator(65).options]
max.outputs = [x.decode() for x in _Indicator(65).outputs]


def md(real, period):
    """
    Mean Deviation Over Period
    """

    return _Indicator(66)([real], [period])

md.full_name = _Indicator(66).full_name.decode()
md.type = _Indicator(66).type.decode()
md.inputs = [x.decode() for x in _Indicator(66).inputs]
md.options = [x.decode() for x in _Indicator(66).options]
md.outputs = [x.decode() for x in _Indicator(66).outputs]


def medprice(high, low):
    """
    Median Price
    """

    return _Indicator(67)([high, low], [])

medprice.full_name = _Indicator(67).full_name.decode()
medprice.type = _Indicator(67).type.decode()
medprice.inputs = [x.decode() for x in _Indicator(67).inputs]
medprice.options = [x.decode() for x in _Indicator(67).options]
medprice.outputs = [x.decode() for x in _Indicator(67).outputs]


def mfi(high, low, close, volume, period):
    """
    Money Flow Index
    """

    return _Indicator(68)([high, low, close, volume], [period])

mfi.full_name = _Indicator(68).full_name.decode()
mfi.type = _Indicator(68).type.decode()
mfi.inputs = [x.decode() for x in _Indicator(68).inputs]
mfi.options = [x.decode() for x in _Indicator(68).options]
mfi.outputs = [x.decode() for x in _Indicator(68).outputs]


def min(real, period):
    """
    Minimum In Period
    """

    return _Indicator(69)([real], [period])

min.full_name = _Indicator(69).full_name.decode()
min.type = _Indicator(69).type.decode()
min.inputs = [x.decode() for x in _Indicator(69).inputs]
min.options = [x.decode() for x in _Indicator(69).options]
min.outputs = [x.decode() for x in _Indicator(69).outputs]


def mobo_band(high, low, dpo_length, mobo_length, num_dev_down, num_dev_up):
    """
    Mobo Band
    """

    return _Indicator(70)([high, low], [dpo_length, mobo_length, num_dev_down, num_dev_up])

mobo_band.full_name = _Indicator(70).full_name.decode()
mobo_band.type = _Indicator(70).type.decode()
mobo_band.inputs = [x.decode() for x in _Indicator(70).inputs]
mobo_band.options = [x.decode() for x in _Indicator(70).options]
mobo_band.outputs = [x.decode() for x in _Indicator(70).outputs]


def mom(real, period):
    """
    Momentum
    """

    return _Indicator(71)([real], [period])

mom.full_name = _Indicator(71).full_name.decode()
mom.type = _Indicator(71).type.decode()
mom.inputs = [x.decode() for x in _Indicator(71).inputs]
mom.options = [x.decode() for x in _Indicator(71).options]
mom.outputs = [x.decode() for x in _Indicator(71).outputs]


def mul(value_one, value_two):
    """
    Vector Multiplication
    """

    return _Indicator(72)([value_one, value_two], [])

mul.full_name = _Indicator(72).full_name.decode()
mul.type = _Indicator(72).type.decode()
mul.inputs = [x.decode() for x in _Indicator(72).inputs]
mul.options = [x.decode() for x in _Indicator(72).options]
mul.outputs = [x.decode() for x in _Indicator(72).outputs]


def natr(high, low, close, period):
    """
    Normalized Average True Range
    """

    return _Indicator(73)([high, low, close], [period])

natr.full_name = _Indicator(73).full_name.decode()
natr.type = _Indicator(73).type.decode()
natr.inputs = [x.decode() for x in _Indicator(73).inputs]
natr.options = [x.decode() for x in _Indicator(73).options]
natr.outputs = [x.decode() for x in _Indicator(73).outputs]


def price(value):
    """
    Compare Price
    """

    return _Indicator(74)([value], [])

price.full_name = _Indicator(74).full_name.decode()
price.type = _Indicator(74).type.decode()
price.inputs = [x.decode() for x in _Indicator(74).inputs]
price.options = [x.decode() for x in _Indicator(74).options]
price.outputs = [x.decode() for x in _Indicator(74).outputs]


def psar(high, low, close, accel_start, accel_step, accel_max):
    """
    PSAR
    """

    return _Indicator(75)([high, low, close], [accel_start, accel_step, accel_max])

psar.full_name = _Indicator(75).full_name.decode()
psar.type = _Indicator(75).type.decode()
psar.inputs = [x.decode() for x in _Indicator(75).inputs]
psar.options = [x.decode() for x in _Indicator(75).options]
psar.outputs = [x.decode() for x in _Indicator(75).outputs]


def qqe_mod(close, rsi_length_one, rsi_smoothing_one, qqe_factor_one, threshold_one, rsi_length_two, rsi_smoothing_two, qqe_factor_two, threshold_two, bollinger_length, qqe_multiplier):
    """
    QQE Mod
    """

    return _Indicator(76)([close], [rsi_length_one, rsi_smoothing_one, qqe_factor_one, threshold_one, rsi_length_two, rsi_smoothing_two, qqe_factor_two, threshold_two, bollinger_length, qqe_multiplier])

qqe_mod.full_name = _Indicator(76).full_name.decode()
qqe_mod.type = _Indicator(76).type.decode()
qqe_mod.inputs = [x.decode() for x in _Indicator(76).inputs]
qqe_mod.options = [x.decode() for x in _Indicator(76).options]
qqe_mod.outputs = [x.decode() for x in _Indicator(76).outputs]


def roc(real, period):
    """
    Rate of Change
    """

    return _Indicator(77)([real], [period])

roc.full_name = _Indicator(77).full_name.decode()
roc.type = _Indicator(77).type.decode()
roc.inputs = [x.decode() for x in _Indicator(77).inputs]
roc.options = [x.decode() for x in _Indicator(77).options]
roc.outputs = [x.decode() for x in _Indicator(77).outputs]


def rocr(real, period):
    """
    Rate of Change Ratio
    """

    return _Indicator(78)([real], [period])

rocr.full_name = _Indicator(78).full_name.decode()
rocr.type = _Indicator(78).type.decode()
rocr.inputs = [x.decode() for x in _Indicator(78).inputs]
rocr.options = [x.decode() for x in _Indicator(78).options]
rocr.outputs = [x.decode() for x in _Indicator(78).outputs]


def round(real):
    """
    Vector Round
    """

    return _Indicator(79)([real], [])

round.full_name = _Indicator(79).full_name.decode()
round.type = _Indicator(79).type.decode()
round.inputs = [x.decode() for x in _Indicator(79).inputs]
round.options = [x.decode() for x in _Indicator(79).options]
round.outputs = [x.decode() for x in _Indicator(79).outputs]


def rsi(real, period):
    """
    Relative Strength Index
    """

    return _Indicator(80)([real], [period])

rsi.full_name = _Indicator(80).full_name.decode()
rsi.type = _Indicator(80).type.decode()
rsi.inputs = [x.decode() for x in _Indicator(80).inputs]
rsi.options = [x.decode() for x in _Indicator(80).options]
rsi.outputs = [x.decode() for x in _Indicator(80).outputs]


def rsi_divergence(high, low, close, left_bar, right_bar, rsi_length):
    """
    Relative Strength Index Divergence
    """

    return _Indicator(81)([high, low, close], [left_bar, right_bar, rsi_length])

rsi_divergence.full_name = _Indicator(81).full_name.decode()
rsi_divergence.type = _Indicator(81).type.decode()
rsi_divergence.inputs = [x.decode() for x in _Indicator(81).inputs]
rsi_divergence.options = [x.decode() for x in _Indicator(81).options]
rsi_divergence.outputs = [x.decode() for x in _Indicator(81).outputs]


def rvi(close, std_length, ema_length):
    """
    Relative Volatility Index
    """

    return _Indicator(82)([close], [std_length, ema_length])

rvi.full_name = _Indicator(82).full_name.decode()
rvi.type = _Indicator(82).type.decode()
rvi.inputs = [x.decode() for x in _Indicator(82).inputs]
rvi.options = [x.decode() for x in _Indicator(82).options]
rvi.outputs = [x.decode() for x in _Indicator(82).outputs]


def rvi_divergence(high, low, close, left_bar, right_bar, std_length, ema_length):
    """
    Relative Volatility Index Divergence
    """

    return _Indicator(83)([high, low, close], [left_bar, right_bar, std_length, ema_length])

rvi_divergence.full_name = _Indicator(83).full_name.decode()
rvi_divergence.type = _Indicator(83).type.decode()
rvi_divergence.inputs = [x.decode() for x in _Indicator(83).inputs]
rvi_divergence.options = [x.decode() for x in _Indicator(83).options]
rvi_divergence.outputs = [x.decode() for x in _Indicator(83).outputs]


def sin(real):
    """
    Vector Sine
    """

    return _Indicator(84)([real], [])

sin.full_name = _Indicator(84).full_name.decode()
sin.type = _Indicator(84).type.decode()
sin.inputs = [x.decode() for x in _Indicator(84).inputs]
sin.options = [x.decode() for x in _Indicator(84).options]
sin.outputs = [x.decode() for x in _Indicator(84).outputs]


def sinh(real):
    """
    Vector Hyperbolic Sine
    """

    return _Indicator(85)([real], [])

sinh.full_name = _Indicator(85).full_name.decode()
sinh.type = _Indicator(85).type.decode()
sinh.inputs = [x.decode() for x in _Indicator(85).inputs]
sinh.options = [x.decode() for x in _Indicator(85).options]
sinh.outputs = [x.decode() for x in _Indicator(85).outputs]


def sma(real, period):
    """
    Simple Moving Average
    """

    return _Indicator(86)([real], [period])

sma.full_name = _Indicator(86).full_name.decode()
sma.type = _Indicator(86).type.decode()
sma.inputs = [x.decode() for x in _Indicator(86).inputs]
sma.options = [x.decode() for x in _Indicator(86).options]
sma.outputs = [x.decode() for x in _Indicator(86).outputs]


def sqrt(real):
    """
    Vector Square Root
    """

    return _Indicator(87)([real], [])

sqrt.full_name = _Indicator(87).full_name.decode()
sqrt.type = _Indicator(87).type.decode()
sqrt.inputs = [x.decode() for x in _Indicator(87).inputs]
sqrt.options = [x.decode() for x in _Indicator(87).options]
sqrt.outputs = [x.decode() for x in _Indicator(87).outputs]


def ssl(high, low, close, ma_length, ssl3_length):
    """
    SSL
    """

    return _Indicator(88)([high, low, close], [ma_length, ssl3_length])

ssl.full_name = _Indicator(88).full_name.decode()
ssl.type = _Indicator(88).type.decode()
ssl.inputs = [x.decode() for x in _Indicator(88).inputs]
ssl.options = [x.decode() for x in _Indicator(88).options]
ssl.outputs = [x.decode() for x in _Indicator(88).outputs]


def stc(close, length, fast_length, slow_length, aaa):
    """
    STC
    """

    return _Indicator(89)([close], [length, fast_length, slow_length, aaa])

stc.full_name = _Indicator(89).full_name.decode()
stc.type = _Indicator(89).type.decode()
stc.inputs = [x.decode() for x in _Indicator(89).inputs]
stc.options = [x.decode() for x in _Indicator(89).options]
stc.outputs = [x.decode() for x in _Indicator(89).outputs]


def stddev(real, period):
    """
    Standard Deviation Over Period
    """

    return _Indicator(90)([real], [period])

stddev.full_name = _Indicator(90).full_name.decode()
stddev.type = _Indicator(90).type.decode()
stddev.inputs = [x.decode() for x in _Indicator(90).inputs]
stddev.options = [x.decode() for x in _Indicator(90).options]
stddev.outputs = [x.decode() for x in _Indicator(90).outputs]


def stderr(real, period):
    """
    Standard Error Over Period
    """

    return _Indicator(91)([real], [period])

stderr.full_name = _Indicator(91).full_name.decode()
stderr.type = _Indicator(91).type.decode()
stderr.inputs = [x.decode() for x in _Indicator(91).inputs]
stderr.options = [x.decode() for x in _Indicator(91).options]
stderr.outputs = [x.decode() for x in _Indicator(91).outputs]


def stoch(high, low, close, k_period, k_slowing_period, d_period):
    """
    Stochastic Oscillator
    """

    return _Indicator(92)([high, low, close], [k_period, k_slowing_period, d_period])

stoch.full_name = _Indicator(92).full_name.decode()
stoch.type = _Indicator(92).type.decode()
stoch.inputs = [x.decode() for x in _Indicator(92).inputs]
stoch.options = [x.decode() for x in _Indicator(92).options]
stoch.outputs = [x.decode() for x in _Indicator(92).outputs]


def stoch_divergence(high, low, close, left_bar, right_bar, stk_length, smooth_length, sma_length):
    """
    Stochastic Divergence
    """

    return _Indicator(93)([high, low, close], [left_bar, right_bar, stk_length, smooth_length, sma_length])

stoch_divergence.full_name = _Indicator(93).full_name.decode()
stoch_divergence.type = _Indicator(93).type.decode()
stoch_divergence.inputs = [x.decode() for x in _Indicator(93).inputs]
stoch_divergence.options = [x.decode() for x in _Indicator(93).options]
stoch_divergence.outputs = [x.decode() for x in _Indicator(93).outputs]


def stoch_rsi(close, smoothk, smoothd, rsi_period, stoch_period):
    """
    Stoch Rsi
    """

    return _Indicator(94)([close], [smoothk, smoothd, rsi_period, stoch_period])

stoch_rsi.full_name = _Indicator(94).full_name.decode()
stoch_rsi.type = _Indicator(94).type.decode()
stoch_rsi.inputs = [x.decode() for x in _Indicator(94).inputs]
stoch_rsi.options = [x.decode() for x in _Indicator(94).options]
stoch_rsi.outputs = [x.decode() for x in _Indicator(94).outputs]


def stochrsi(real, period):
    """
    Stochastic RSI
    """

    return _Indicator(95)([real], [period])

stochrsi.full_name = _Indicator(95).full_name.decode()
stochrsi.type = _Indicator(95).type.decode()
stochrsi.inputs = [x.decode() for x in _Indicator(95).inputs]
stochrsi.options = [x.decode() for x in _Indicator(95).options]
stochrsi.outputs = [x.decode() for x in _Indicator(95).outputs]


def sub(value_one, value_two):
    """
    Vector Subtraction
    """

    return _Indicator(96)([value_one, value_two], [])

sub.full_name = _Indicator(96).full_name.decode()
sub.type = _Indicator(96).type.decode()
sub.inputs = [x.decode() for x in _Indicator(96).inputs]
sub.options = [x.decode() for x in _Indicator(96).options]
sub.outputs = [x.decode() for x in _Indicator(96).outputs]


def sum(real, period):
    """
    Sum Over Period
    """

    return _Indicator(97)([real], [period])

sum.full_name = _Indicator(97).full_name.decode()
sum.type = _Indicator(97).type.decode()
sum.inputs = [x.decode() for x in _Indicator(97).inputs]
sum.options = [x.decode() for x in _Indicator(97).options]
sum.outputs = [x.decode() for x in _Indicator(97).outputs]


def sup_and_res(close, left_bar, right_bar_one, right_bar_two, hma_length):
    """
    Support and Resistance
    """

    return _Indicator(98)([close], [left_bar, right_bar_one, right_bar_two, hma_length])

sup_and_res.full_name = _Indicator(98).full_name.decode()
sup_and_res.type = _Indicator(98).type.decode()
sup_and_res.inputs = [x.decode() for x in _Indicator(98).inputs]
sup_and_res.options = [x.decode() for x in _Indicator(98).options]
sup_and_res.outputs = [x.decode() for x in _Indicator(98).outputs]


def supertrend(high, low, close, period, factor):
    """
    Supertrend
    """

    return _Indicator(99)([high, low, close], [period, factor])

supertrend.full_name = _Indicator(99).full_name.decode()
supertrend.type = _Indicator(99).type.decode()
supertrend.inputs = [x.decode() for x in _Indicator(99).inputs]
supertrend.options = [x.decode() for x in _Indicator(99).options]
supertrend.outputs = [x.decode() for x in _Indicator(99).outputs]


def tan(real):
    """
    Vector Tangent
    """

    return _Indicator(100)([real], [])

tan.full_name = _Indicator(100).full_name.decode()
tan.type = _Indicator(100).type.decode()
tan.inputs = [x.decode() for x in _Indicator(100).inputs]
tan.options = [x.decode() for x in _Indicator(100).options]
tan.outputs = [x.decode() for x in _Indicator(100).outputs]


def tanh(real):
    """
    Vector Hyperbolic Tangent
    """

    return _Indicator(101)([real], [])

tanh.full_name = _Indicator(101).full_name.decode()
tanh.type = _Indicator(101).type.decode()
tanh.inputs = [x.decode() for x in _Indicator(101).inputs]
tanh.options = [x.decode() for x in _Indicator(101).options]
tanh.outputs = [x.decode() for x in _Indicator(101).outputs]


def tema(real, period):
    """
    Triple Exponential Moving Average
    """

    return _Indicator(102)([real], [period])

tema.full_name = _Indicator(102).full_name.decode()
tema.type = _Indicator(102).type.decode()
tema.inputs = [x.decode() for x in _Indicator(102).inputs]
tema.options = [x.decode() for x in _Indicator(102).options]
tema.outputs = [x.decode() for x in _Indicator(102).outputs]


def todeg(real):
    """
    Vector Degree Conversion
    """

    return _Indicator(103)([real], [])

todeg.full_name = _Indicator(103).full_name.decode()
todeg.type = _Indicator(103).type.decode()
todeg.inputs = [x.decode() for x in _Indicator(103).inputs]
todeg.options = [x.decode() for x in _Indicator(103).options]
todeg.outputs = [x.decode() for x in _Indicator(103).outputs]


def torad(real):
    """
    Vector Radian Conversion
    """

    return _Indicator(104)([real], [])

torad.full_name = _Indicator(104).full_name.decode()
torad.type = _Indicator(104).type.decode()
torad.inputs = [x.decode() for x in _Indicator(104).inputs]
torad.options = [x.decode() for x in _Indicator(104).options]
torad.outputs = [x.decode() for x in _Indicator(104).outputs]


def tr(high, low, close):
    """
    True Range
    """

    return _Indicator(105)([high, low, close], [])

tr.full_name = _Indicator(105).full_name.decode()
tr.type = _Indicator(105).type.decode()
tr.inputs = [x.decode() for x in _Indicator(105).inputs]
tr.options = [x.decode() for x in _Indicator(105).options]
tr.outputs = [x.decode() for x in _Indicator(105).outputs]


def trima(real, period):
    """
    Triangular Moving Average
    """

    return _Indicator(106)([real], [period])

trima.full_name = _Indicator(106).full_name.decode()
trima.type = _Indicator(106).type.decode()
trima.inputs = [x.decode() for x in _Indicator(106).inputs]
trima.options = [x.decode() for x in _Indicator(106).options]
trima.outputs = [x.decode() for x in _Indicator(106).outputs]


def trix(real, period):
    """
    Trix
    """

    return _Indicator(107)([real], [period])

trix.full_name = _Indicator(107).full_name.decode()
trix.type = _Indicator(107).type.decode()
trix.inputs = [x.decode() for x in _Indicator(107).inputs]
trix.options = [x.decode() for x in _Indicator(107).options]
trix.outputs = [x.decode() for x in _Indicator(107).outputs]


def trunc(real):
    """
    Vector Truncate
    """

    return _Indicator(108)([real], [])

trunc.full_name = _Indicator(108).full_name.decode()
trunc.type = _Indicator(108).type.decode()
trunc.inputs = [x.decode() for x in _Indicator(108).inputs]
trunc.options = [x.decode() for x in _Indicator(108).options]
trunc.outputs = [x.decode() for x in _Indicator(108).outputs]


def tsf(real, period):
    """
    Time Series Forecast
    """

    return _Indicator(109)([real], [period])

tsf.full_name = _Indicator(109).full_name.decode()
tsf.type = _Indicator(109).type.decode()
tsf.inputs = [x.decode() for x in _Indicator(109).inputs]
tsf.options = [x.decode() for x in _Indicator(109).options]
tsf.outputs = [x.decode() for x in _Indicator(109).outputs]


def typprice(high, low, close):
    """
    Typical Price
    """

    return _Indicator(110)([high, low, close], [])

typprice.full_name = _Indicator(110).full_name.decode()
typprice.type = _Indicator(110).type.decode()
typprice.inputs = [x.decode() for x in _Indicator(110).inputs]
typprice.options = [x.decode() for x in _Indicator(110).options]
typprice.outputs = [x.decode() for x in _Indicator(110).outputs]


def ultosc(high, low, close, short_period, medium_period, long_period):
    """
    Ultimate Oscillator
    """

    return _Indicator(111)([high, low, close], [short_period, medium_period, long_period])

ultosc.full_name = _Indicator(111).full_name.decode()
ultosc.type = _Indicator(111).type.decode()
ultosc.inputs = [x.decode() for x in _Indicator(111).inputs]
ultosc.options = [x.decode() for x in _Indicator(111).options]
ultosc.outputs = [x.decode() for x in _Indicator(111).outputs]


def unshift(value, default_value, length):
    """
    Unshift
    """

    return _Indicator(112)([value], [default_value, length])

unshift.full_name = _Indicator(112).full_name.decode()
unshift.type = _Indicator(112).type.decode()
unshift.inputs = [x.decode() for x in _Indicator(112).inputs]
unshift.options = [x.decode() for x in _Indicator(112).options]
unshift.outputs = [x.decode() for x in _Indicator(112).outputs]


def ut_bot(high, low, close, atr_period, sensitivity):
    """
    UT Bot Alert
    """

    return _Indicator(113)([high, low, close], [atr_period, sensitivity])

ut_bot.full_name = _Indicator(113).full_name.decode()
ut_bot.type = _Indicator(113).type.decode()
ut_bot.inputs = [x.decode() for x in _Indicator(113).inputs]
ut_bot.options = [x.decode() for x in _Indicator(113).options]
ut_bot.outputs = [x.decode() for x in _Indicator(113).outputs]


def var(real, period):
    """
    Variance Over Period
    """

    return _Indicator(114)([real], [period])

var.full_name = _Indicator(114).full_name.decode()
var.type = _Indicator(114).type.decode()
var.inputs = [x.decode() for x in _Indicator(114).inputs]
var.options = [x.decode() for x in _Indicator(114).options]
var.outputs = [x.decode() for x in _Indicator(114).outputs]


def vhf(real, period):
    """
    Vertical Horizontal Filter
    """

    return _Indicator(115)([real], [period])

vhf.full_name = _Indicator(115).full_name.decode()
vhf.type = _Indicator(115).type.decode()
vhf.inputs = [x.decode() for x in _Indicator(115).inputs]
vhf.options = [x.decode() for x in _Indicator(115).options]
vhf.outputs = [x.decode() for x in _Indicator(115).outputs]


def volatility(real, period):
    """
    Annualized Historical Volatility
    """

    return _Indicator(116)([real], [period])

volatility.full_name = _Indicator(116).full_name.decode()
volatility.type = _Indicator(116).type.decode()
volatility.inputs = [x.decode() for x in _Indicator(116).inputs]
volatility.options = [x.decode() for x in _Indicator(116).options]
volatility.outputs = [x.decode() for x in _Indicator(116).outputs]


def volatility_oscillator(open, close, length):
    """
    Volatility Oscillator
    """

    return _Indicator(117)([open, close], [length])

volatility_oscillator.full_name = _Indicator(117).full_name.decode()
volatility_oscillator.type = _Indicator(117).type.decode()
volatility_oscillator.inputs = [x.decode() for x in _Indicator(117).inputs]
volatility_oscillator.options = [x.decode() for x in _Indicator(117).options]
volatility_oscillator.outputs = [x.decode() for x in _Indicator(117).outputs]


def vosc(volume, short_period, long_period):
    """
    Volume Oscillator
    """

    return _Indicator(118)([volume], [short_period, long_period])

vosc.full_name = _Indicator(118).full_name.decode()
vosc.type = _Indicator(118).type.decode()
vosc.inputs = [x.decode() for x in _Indicator(118).inputs]
vosc.options = [x.decode() for x in _Indicator(118).options]
vosc.outputs = [x.decode() for x in _Indicator(118).outputs]


def vu_man_chu_swing(close, swing_period, swing_multiplier):
    """
    VU Man Chu Swing
    """

    return _Indicator(119)([close], [swing_period, swing_multiplier])

vu_man_chu_swing.full_name = _Indicator(119).full_name.decode()
vu_man_chu_swing.type = _Indicator(119).type.decode()
vu_man_chu_swing.inputs = [x.decode() for x in _Indicator(119).inputs]
vu_man_chu_swing.options = [x.decode() for x in _Indicator(119).options]
vu_man_chu_swing.outputs = [x.decode() for x in _Indicator(119).outputs]


def vwma(close, volume, period):
    """
    Volume Weighted Moving Average
    """

    return _Indicator(120)([close, volume], [period])

vwma.full_name = _Indicator(120).full_name.decode()
vwma.type = _Indicator(120).type.decode()
vwma.inputs = [x.decode() for x in _Indicator(120).inputs]
vwma.options = [x.decode() for x in _Indicator(120).options]
vwma.outputs = [x.decode() for x in _Indicator(120).outputs]


def wad(high, low, close):
    """
    Williams Accumulation/Distribution
    """

    return _Indicator(121)([high, low, close], [])

wad.full_name = _Indicator(121).full_name.decode()
wad.type = _Indicator(121).type.decode()
wad.inputs = [x.decode() for x in _Indicator(121).inputs]
wad.options = [x.decode() for x in _Indicator(121).options]
wad.outputs = [x.decode() for x in _Indicator(121).outputs]


def waddah(close, fast_length, slow_length, signal_length, bb_length, multiplier, sensitivity):
    """
    Waddah
    """

    return _Indicator(122)([close], [fast_length, slow_length, signal_length, bb_length, multiplier, sensitivity])

waddah.full_name = _Indicator(122).full_name.decode()
waddah.type = _Indicator(122).type.decode()
waddah.inputs = [x.decode() for x in _Indicator(122).inputs]
waddah.options = [x.decode() for x in _Indicator(122).options]
waddah.outputs = [x.decode() for x in _Indicator(122).outputs]


def wavetrend(high, low, close, period_one, period_two):
    """
    Wavetrend
    """

    return _Indicator(123)([high, low, close], [period_one, period_two])

wavetrend.full_name = _Indicator(123).full_name.decode()
wavetrend.type = _Indicator(123).type.decode()
wavetrend.inputs = [x.decode() for x in _Indicator(123).inputs]
wavetrend.options = [x.decode() for x in _Indicator(123).options]
wavetrend.outputs = [x.decode() for x in _Indicator(123).outputs]


def wcprice(high, low, close):
    """
    Weighted Close Price
    """

    return _Indicator(124)([high, low, close], [])

wcprice.full_name = _Indicator(124).full_name.decode()
wcprice.type = _Indicator(124).type.decode()
wcprice.inputs = [x.decode() for x in _Indicator(124).inputs]
wcprice.options = [x.decode() for x in _Indicator(124).options]
wcprice.outputs = [x.decode() for x in _Indicator(124).outputs]


def wilders(real, period):
    """
    Wilders Smoothing
    """

    return _Indicator(125)([real], [period])

wilders.full_name = _Indicator(125).full_name.decode()
wilders.type = _Indicator(125).type.decode()
wilders.inputs = [x.decode() for x in _Indicator(125).inputs]
wilders.options = [x.decode() for x in _Indicator(125).options]
wilders.outputs = [x.decode() for x in _Indicator(125).outputs]


def willr(high, low, close, period):
    """
    Williams %R
    """

    return _Indicator(126)([high, low, close], [period])

willr.full_name = _Indicator(126).full_name.decode()
willr.type = _Indicator(126).type.decode()
willr.inputs = [x.decode() for x in _Indicator(126).inputs]
willr.options = [x.decode() for x in _Indicator(126).options]
willr.outputs = [x.decode() for x in _Indicator(126).outputs]


def wma(real, period):
    """
    Weighted Moving Average
    """

    return _Indicator(127)([real], [period])

wma.full_name = _Indicator(127).full_name.decode()
wma.type = _Indicator(127).type.decode()
wma.inputs = [x.decode() for x in _Indicator(127).inputs]
wma.options = [x.decode() for x in _Indicator(127).options]
wma.outputs = [x.decode() for x in _Indicator(127).outputs]

