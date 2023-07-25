/* eslint-disable @typescript-eslint/ban-ts-comment */
import { TypeCompiler } from '@cybotrade/core';

import { indicators } from './generated';
import { Comparator, type Indicator, IndicatorSchema, SignalComparator } from './public';

const IndicatorChecker = TypeCompiler.Compile(IndicatorSchema);

type ExtractIndicatorType<T extends Indicator['data']['indicator_type']> = Lowercase<
  T extends `INDICATOR_${infer name}` ? name : never
>;
export const extractIndicatorType = <T extends Indicator>(indicator: T) =>
  indicator.data.indicator_type.split('_').slice(1).join('_').toLowerCase() as ExtractIndicatorType<
    T['data']['indicator_type']
  >;

export const compare = ({
  left,
  comparator,
  right,
}: {
  left: number;
  comparator: Comparator | SignalComparator;
  right: number;
}): boolean => {
  if (isNaN(left) || isNaN(right)) return false;

  switch (comparator) {
    case Comparator.GreaterThan:
      return left > right;
    case Comparator.GreaterThanEqual:
      return left >= right;
    case Comparator.LesserThan:
      return left < right;
    case Comparator.LesserThanEqual:
      return left <= right;
    case Comparator.Equal:
      return left === right;
    case SignalComparator.Equal:
      return left === right;
    default:
      throw new Error(`Invalid comparator: ${comparator}`);
  }
};

export type ConditionFn = (params: { current: number; previous: number }) => boolean;

export const compareResults = ({
  results,
  comparator,
  value,
  conditions,
  candles,
}: {
  results: number[];
  comparator: Comparator | SignalComparator;
  value: number | 'OPEN' | 'HIGH' | 'LOW' | 'CLOSE' | 'VOLUME';
  conditions: ConditionFn[][];
  candles?: Array<{ open: number; high: number; low: number; close: number; volume: number }>;
}) => {
  if (conditions.length === 0) throw new Error('Must have at least one condition');
  if (!!candles && candles.length !== results.length)
    throw new Error('Candles and results must be the same length');
  if (typeof value !== 'number' && !candles)
    throw new Error('Candles must be provided if value is not a number');

  let count = 0;

  const computeValue = (
    value: number | 'OPEN' | 'HIGH' | 'LOW' | 'CLOSE' | 'VOLUME',
    index: number,
  ) => {
    if (typeof value === 'number') return value;
    else if (value === 'OPEN' && candles) return candles[index].open;
    else if (value === 'HIGH' && candles) return candles[index].high;
    else if (value === 'LOW' && candles) return candles[index].low;
    else if (value === 'CLOSE' && candles) return candles[index].close;
    else if (value === 'VOLUME' && candles) return candles[index].volume;
    else return 0;
  };

  for (
    let i = results.length - 1, j = conditions.length - 1;
    i > results.length - conditions.length - 1;
    i--
  ) {
    const current = results[i];
    const previous = results[i - 1];

    const comparison = compare({ left: results[i], comparator, right: computeValue(value, i) });
    const condition = conditions[j--].every((fn) => fn({ current, previous }));

    comparison && condition && count++;
  }

  return count === conditions.length;
};

export const findMinCandles = (multipler: number) => (indicator: Indicator) =>
  Math.max(...Object.values(indicator.data.params)) * multipler;

export const calculateIndicator = async <T extends Indicator>({
  indicator,
  candles,
  conditions,
  minCandlesMultiplier = 3,
}: {
  indicator: T;
  candles: Array<{ open: number; high: number; low: number; close: number; volume: number }>;
  conditions: ConditionFn[][];
  minCandlesMultiplier?: number;
}): Promise<Record<string, boolean>> => {
  if (!IndicatorChecker.Check(indicator)) throw new Error(`Indicator does not pass validation`);
  if (candles.length < findMinCandles(minCandlesMultiplier)(indicator))
    throw new Error('Not enough candles to calculate indicator');

  const indicatorType = extractIndicatorType(indicator);
  const indicatorFn = indicators[indicatorType];
  // TODO: This calculation can be minimised if we have a cache or a way to not recalculate every time.
  const outputs = indicatorFn(
    // @ts-ignore
    {
      // NOTE: We are currently hardcoding the value to use the close value
      value: candles.reduce((acc, cv) => [...acc, cv.close], [] as number[]),
      open: candles.reduce((acc, cv) => [...acc, cv.open], [] as number[]),
      high: candles.reduce((acc, cv) => [...acc, cv.high], [] as number[]),
      low: candles.reduce((acc, cv) => [...acc, cv.low], [] as number[]),
      close: candles.reduce((acc, cv) => [...acc, cv.close], [] as number[]),
      volume: candles.reduce((acc, cv) => [...acc, cv.volume], [] as number[]),
    },
    // @ts-ignore
    indicator.data.params,
  );

  return Object.fromEntries(
    Object.entries(outputs).map(([key, results]) => {
      return [
        key,
        key in indicator.data.comparator &&
          compareResults({
            results,
            // @ts-ignore
            comparator: indicator.data.comparator[key].comparator,
            // @ts-ignore
            value: indicator.data.comparator[key].value,
            conditions,
            // @ts-ignore
            candles: typeof indicator.data.comparator[key].value === 'number' ? undefined : candles,
          }),
      ];
    }),
  );
};
