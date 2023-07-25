import bindings from 'bindings';

import type { Binding, Indicator, IndicatorOptions, Indicators } from './types';

const binding: Binding = bindings('bq-indicators');

const makeCall =
  ({ index }: Indicator) =>
  (inputs: number[][], options: IndicatorOptions) =>
    binding.callByIndex(index, inputs, options);

const makeStart =
  ({ index }: Indicator) =>
  (options: IndicatorOptions) =>
    binding.startByIndex(index, options);

const inds = binding.indicators;
for (const key in inds) {
  const ind = inds[key as keyof Indicators] as Indicator;
  ind.indicator = makeCall(ind);
  ind.start = makeStart(ind);
}

export const version = binding.version as string;
export const indicators = inds as Indicators;
