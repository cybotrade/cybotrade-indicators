from collections import Counter

cimport indicators as ti

COPYRIGHT = """
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
"""

CYBOTRADE_INDICATORS_INTERFACE_TEMPLATE = """
{copyright}

# This file is generated. Do not modify directly.

from nptyping import NDArray, Float, Shape

{indicators}
"""

INDICATOR_INTERFACE_TEMPLATE = """
def {name}({inputs}{sep}{options}) -> {return_type}:
    \"\"\"
    {full_name}
    \"\"\"
    pass
"""

INDICATOR_TEMPLATE = """
def {name}({inputs}{sep}{options}):
    \"\"\"
    {full_name}
    \"\"\"

    return _Indicator({index})([{inputs}], [{options}])

{name}.full_name = _Indicator({index}).full_name.decode()
{name}.type = _Indicator({index}).type.decode()
{name}.inputs = [x.decode() for x in _Indicator({index}).inputs]
{name}.options = [x.decode() for x in _Indicator({index}).options]
{name}.outputs = [x.decode() for x in _Indicator({index}).outputs]
"""

WRAPPER_TEMPLATE = """
{copyright}

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

cdef dict _type_names = {{
    ti.TI_TYPE_OVERLAY:     b'overlay',
    ti.TI_TYPE_INDICATOR:   b'indicator',
    ti.TI_TYPE_MATH:        b'math',
    ti.TI_TYPE_SIMPLE:      b'simple',
    ti.TI_TYPE_COMPARATIVE: b'comparative',
}}

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

{indicators}
"""

INDICATOR_WRAPPER_TEMPLATE = """
{name} = _Indicator({index})
"""


def clean(names, no_default = False):
    c = Counter()

    for n in names:
        n = n.decode().replace(' ', '_').replace('%', 'pct_').replace('[', ' = ').replace(']', '').replace('(ohlc)', '')
        if no_default == True:
            n = n.split('=')[0].strip()
        c[n] += 1
        if c[n] > 1:
            yield "{}{}".format(n, c[n])
        else:
            yield n

def clean_with_type(names, type):
    c = Counter()

    for n in names:
        n = n.decode().replace(' ', '_').replace('%', 'pct_').replace('[', ' = ').replace(']', '').replace('(ohlc)', '').split('=')[0].strip()
        n += ': ' + type
        c[n] += 1
        if c[n] > 1:
            yield "{}{}".format(n, c[n])
        else:
            yield n


def gen(lib_pyx, lib_pyi):
    indicators = []
    interfaces = []

    for i in range(ti.TI_INDICATOR_COUNT):
        info = ti.ti_indicators[i]

        indicators.append(INDICATOR_TEMPLATE.format(
            name=info.name.decode(),
            full_name=info.full_name.decode(),
            inputs_params=', '.join(clean([info.input_names[j] for j in range(info.inputs)])),
            sep=', ' if info.options else '',
            options_params=', '.join(clean([info.option_names[j] for j in range(info.options)])),
            inputs=', '.join(clean([info.input_names[j] for j in range(info.inputs)], True)),
            options=', '.join(clean([info.option_names[j] for j in range(info.options)], True)),
            index=i,
        ))

        interfaces.append(INDICATOR_INTERFACE_TEMPLATE.format(
            name=info.name.decode(),
            full_name=info.full_name.decode(),
            inputs=', '.join(clean_with_type([info.input_names[j] for j in range(info.inputs)], 'NDArray[Shape["*", Float]]')),
            sep=', ' if info.options else '',
            options=', '.join(clean_with_type([info.option_names[j] for j in range(info.options)], 'float | int')),
            return_type='NDArray[Shape["*"], Float]' if info.outputs == 1 else 'NDArray[Shape["{dim} *"], Float]'.format(dim=info.outputs),
        ))

    lib_pyx.write(WRAPPER_TEMPLATE.format(
        copyright=COPYRIGHT, 
        indicators='\n'.join(indicators))
    )
    lib_pyi.write(
        CYBOTRADE_INDICATORS_INTERFACE_TEMPLATE.format(
            copyright=COPYRIGHT, 
            indicators='\n'.join(interfaces),
        )
    )
