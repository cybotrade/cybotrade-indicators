import camelcase from 'camelcase';
import fs from 'fs';
import { format } from 'prettier';

const definitionFile = '../../build.tcl';
const outputFiles = {
  core: 'generated.ts',
  public: 'public.ts',
};

const camelToSnakeCase = (str: string) =>
  str.replace(/[A-Z]/g, (letter) => `_${letter.toLowerCase()}`);
const camelToPascalCase = (str: string) => camelToSnakeCase(str).toUpperCase();

const _processName =
  (changeCase = true) =>
  (name: string) => {
    let result = name.startsWith('{') ? name.slice(1, -1) : name;
    switch (name) {
      case 'real':
        result = 'value';
        break;
    }
    return changeCase ? camelToSnakeCase(camelcase(result)) : result;
  };
const processName = _processName();

const cleanName = (name: string) =>
  (name.startsWith('?') ? name.slice(1) : name)
    .replace(/ *\([^)]*\) */g, '')
    .replace(/ *\[[^)]*\] */g, '');

const indicators = fs
  .readFileSync(definitionFile)
  .toString()
  .split('\n')
  .filter((line) => line.startsWith('lappend indicators'))
  .filter((line) => !line.includes('beta'))
  .filter((line) => !line.startsWith('#'))
  .filter((line) => !line.includes(';# NO_INCLUDE'))
  .map((line) => {
    const arr = line.split(' ');
    const full_name_idx = [
      arr.findIndex((v) => v.startsWith('"')),
      arr.findIndex((v) => v.endsWith('"')),
    ];
    const full_name = arr
      .slice(full_name_idx[0], full_name_idx[1] + 1)
      .join(' ')
      .slice(1, -1);
    const arr2 = arr.slice(full_name_idx[1] + 5);
    const input_names_idx = [
      arr2.findIndex((v) => v.startsWith('{')),
      arr2.findIndex((v) => v.endsWith('}')),
    ];
    const input_names = arr2
      .slice(input_names_idx[0], input_names_idx[1] + 1)
      .join(' ')
      .slice(1, -1)
      .split(' ')
      .map(processName);
    const arr3 = arr2.slice(input_names_idx[1] + 1);
    const option_names_idx = [
      arr3.findIndex((v) => v.startsWith('{{')) !== -1
        ? arr3.findIndex((v) => v.startsWith('{{'))
        : arr3.findIndex((v) => v.startsWith('{')),
      arr3.findIndex((v) => v.endsWith('}}')) !== -1
        ? arr3.findIndex((v) => v.endsWith('}}'))
        : arr3.findIndex((v) =>
            arr3.findIndex((v) => v.startsWith('{{')) !== -1 &&
            arr3.findIndex((v) => !v.startsWith('{') && v.endsWith('}')) !== -1
              ? !v.startsWith('{') && v.endsWith('}')
              : v.endsWith('}'),
          ),
    ];
    const option_names = arr3
      .slice(option_names_idx[0], option_names_idx[1] + 1)
      .join(' ')
      .slice(1, -1)
      .split(' ')
      .map(_processName(false));
    const arr4 = arr3.slice(option_names_idx[1] + 1);
    const hasMultipleOutput = arr4.findIndex((v) => v.endsWith('}')) !== -1;
    const output_names_idx = [
      arr4.findIndex((v) => v.startsWith('{')),
      hasMultipleOutput
        ? arr4.findIndex((v) => v.endsWith('}'))
        : arr4.findIndex((v) => v.endsWith('}]')),
    ];
    const output_names = arr4
      .slice(output_names_idx[0], output_names_idx[1] + 1)
      .join(' ')
      .slice(1, hasMultipleOutput ? -1 : -2)
      .split(' ')
      .map(processName);

    return {
      type: arr[3] as 'simple' | 'math' | 'overlay' | 'indicator',
      full_name,
      name: arr[full_name_idx[1] + 1],
      inputs: parseInt(arr[full_name_idx[1] + 2]),
      options: parseInt(arr[full_name_idx[1] + 3]),
      outputs: parseInt(arr[full_name_idx[1] + 4]),
      input_names,
      option_names,
      output_names,
    };
  })
  .filter(({ type }) => ['overlay', 'indicator'].includes(type));

const makeObjectType = (type: Record<string, string>) =>
  `{${Object.entries(type).map(([k, v]) => `${k}: ${v}`)}}`;

const makeOptional = (type: string, isZod = false) =>
  isZod ? `z.optional(${type})` : `Type.Optional(${type})`;
const makeUnion = (types: string[], isZod = false) =>
  isZod ? `${types.length > 1 ? `z.union([${types}])` : types[0]}` : `Type.Union([${types}])`;
const makeEnum = (type: string, isZod = false) =>
  isZod ? `z.nativeEnum(${type})` : `Type.Enum(${type})`;
const makeLiteral = (type: string, isZod = false) =>
  isZod ? `z.literal('${type}')` : `Type.Literal('${type}')`;
const makeObject = (type: Record<string, string>, isZod = false) =>
  isZod ? `z.object(${makeObjectType(type)})` : `Type.Object(${makeObjectType(type)})`;

const deriveOHLCV = (ohlcv: string, isZod = false) =>
  makeUnion(
    ohlcv
      .split('')
      .map((v) =>
        v === 'o'
          ? makeLiteral('OPEN', isZod)
          : v === 'h'
          ? makeLiteral('HIGH', isZod)
          : v === 'l'
          ? makeLiteral('LOW', isZod)
          : v === 'c'
          ? makeLiteral('CLOSE', isZod)
          : v === 'v'
          ? makeLiteral('VOLUME', isZod)
          : '',
      ),
    isZod,
  );

const deriveOptionType = (name: string, isZod = false) => {
  const minimumValue = name.includes('period') || name.includes('length');
  const defaultValue = name.match(/ *\[[^)]*\] */g)?.[0].slice(1, -1);

  if (isZod)
    return defaultValue
      ? `z.number()${minimumValue ? '.min(1)' : ''}.default(${defaultValue})`
      : 'z.number()';
  else
    return defaultValue
      ? `Type.Number({ default: ${defaultValue}${minimumValue ? ', minimum: 1' : ''} })`
      : 'Type.Number()';
};

const deriveOutputType = (name: string, isZod = false) => {
  if (name.startsWith('buy_sell_signal')) return makeEnum('BuySellSignal', isZod);
  else if (name.startsWith('bar_color')) return makeEnum('BarColor', isZod);
  else if (name.startsWith('heatmap_level')) return makeEnum('HeatmapLevel', isZod);
  else if (name.startsWith('cross')) return makeEnum('CrossSignal', isZod);
  else if (name.startsWith('buy')) return makeEnum('BuySignal', isZod);
  else if (name.startsWith('sell')) return makeEnum('SellSignal', isZod);
  else if (name === 'bull') return makeEnum('BullSignal', isZod);
  else if (name === 'bear') return makeEnum('BearSignal', isZod);
  else if (name === 'direction') return makeEnum('DirectionSignal', isZod);
  else return isZod ? 'z.number()' : 'Type.Number()';
};

const deriveComparatorType = (name: string, isZod = false) => {
  const ohlcv = name.match(/\((.*?)\)/)?.[1];
  const optional = name.startsWith('?');
  name = cleanName(name);
  const type = makeObject(
    {
      comparator: makeEnum(
        !['Type.Number()', 'z.number()'].includes(deriveOutputType(name, isZod))
          ? 'SignalComparator'
          : 'Comparator',
        isZod,
      ),
      value: `${ohlcv ? deriveOHLCV(ohlcv, isZod) : deriveOutputType(name, isZod)}`,
    },
    isZod,
  );

  return `${optional ? makeOptional(type, isZod) : type},`;
};

const publicOutput = `
/* eslint-disable no-empty-pattern */
// Path: ${outputFiles.public}
// This code is generated, please do not edit it manually.

import { Type, type Static } from "@cybotrade/core";
import { z } from "zod";

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
  ${indicators
    .map(
      (indicator) =>
        `${indicator.name}: Type.Object({
          type: Type.Literal('INDICATOR_NODE'),
          id: Type.String(),
          data: Type.Object({
            indicator_type: Type.Literal('INDICATOR_${camelToPascalCase(indicator.name)}'),
            comparator: Type.Object({
              ${
                indicator.output_names.length > 0 && indicator.output_names[0] === ''
                  ? ''
                  : indicator.output_names
                      .map((name) => `${cleanName(name)}: ${deriveComparatorType(name)}`)
                      .join('\n')
              }}),
            params: Type.Object({
              ${
                indicator.option_names.length > 0 && indicator.option_names[0] === ''
                  ? ''
                  : indicator.option_names
                      .map((name) => `${cleanName(name)}: ${deriveOptionType(name)},`)
                      .join('\n')
              }}),
              }),
          }),`,
    )
    .join('\n')}
}
export const IndicatorSchemasZod = {
  ${indicators
    .map(
      (indicator) => `${indicator.name}: z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_${camelToPascalCase(indicator.name)}'),
      comparator: z.object({
        ${
          indicator.output_names.length > 0 && indicator.output_names[0] === ''
            ? ''
            : indicator.output_names
                .map((name) => `${cleanName(name)}: ${deriveComparatorType(name, true)}`)
                .join('\n')
        }}),
      params: z.object({
        ${
          indicator.option_names.length > 0 && indicator.option_names[0] === ''
            ? ''
            : indicator.option_names
                .map((name) => `${cleanName(name)}: ${deriveOptionType(name, true)},`)
                .join('\n')
        }}),
      }),
  }),`,
    )
    .join('\n')}
}

export const IndicatorSchema = Type.Union([...Object.values(IndicatorSchemas)]);
export const IndicatorSchemaZod = z.union([${indicators.map(
  (indicator) => `
z.object({
    type: z.literal('INDICATOR_NODE'),
    id: z.string(),
    data: z.object({
      indicator_type: z.literal('INDICATOR_${camelToPascalCase(indicator.name)}'),
      comparator: z.object({
        ${
          indicator.output_names.length > 0 && indicator.output_names[0] === ''
            ? ''
            : indicator.output_names
                .map((name) => `${cleanName(name)}: ${deriveComparatorType(name, true)}`)
                .join('\n')
        }}),
      params: z.object({
        ${
          indicator.option_names.length > 0 && indicator.option_names[0] === ''
            ? ''
            : indicator.option_names
                .map((name) => `${cleanName(name)}: ${deriveOptionType(name, true)},`)
                .join('\n')
        }}),
      }),
  })`,
)}]);
export type Indicator = Static<typeof IndicatorSchema>;
export type IndicatorZod = z.infer<typeof IndicatorSchemaZod>;
`;

const coreOutput = `
/* eslint-disable no-empty-pattern */
// Path: ${outputFiles.core}
// This code is generated, please do not edit it manually.

import { Type, type Static, TSchema } from "@cybotrade/core";
import { indicators as rawIndicators } from "./bindings";
import {
  BuySellSignal, 
  BuySignal,
  SellSignal,
  DirectionSignal,
  BarColor,
  HeatmapLevel,
  BullSignal,
  BearSignal,
  CrossSignal
} from "./public";

export const schemas = {
  ${indicators.map(
    (indicator) => `${indicator.name}: {
    inputs: Type.Object({
      ${
        indicator.input_names.length > 0 && indicator.input_names[0] === ''
          ? ''
          : indicator.input_names
              .map(cleanName)
              .map((name) => `${name}: Type.Array(Type.Number()),`)
              .join('\n')
      }
    }),
    options: Type.Object({
      ${
        indicator.option_names.length > 0 && indicator.option_names[0] === ''
          ? ''
          : indicator.option_names
              .map((name) => `${cleanName(name)}: ${deriveOptionType(name)},`)
              .join('\n')
      }
    }),
    outputs: Type.Object({
      ${
        indicator.output_names.length > 0 && indicator.output_names[0] === ''
          ? ''
          : indicator.output_names
              .map(cleanName)
              .map((name) => `${name}: Type.Array(${deriveOutputType(name)}),`)
              .join('\n')
      }
    }),
  }\n`,
  )}
};

type IndicatorFn<
  S extends {
    inputs: TSchema;
    options: TSchema;
    outputs: TSchema;
  }
> = (
  input: Static<S["inputs"]>,
  option: Static<S["options"]>
) => Static<S["outputs"]>;

const unshift = (
  value: number[],
  length: number,
  defaultValue: number = 0
): number[] => new Array(length).fill(defaultValue).concat(value);

export const indicators = {
  ${indicators.map(
    (indicator) =>
      `${indicator.name}: (({ ${indicator.input_names.map(cleanName).join(', ')} }${
        indicator.option_names.length > 0
          ? `, { ${indicator.option_names.map(cleanName).join(', ')} }`
          : ''
      }) => {
    const start = rawIndicators.${indicator.name}.start([${indicator.option_names
        .map(cleanName)
        .join(', ')}]);
    const result = rawIndicators.${indicator.name}.indicator([${indicator.input_names
        .map(cleanName)
        .join(', ')}], [${indicator.option_names.map(cleanName).join(', ')}]);
    return { ${
      indicator.output_names.length === 0
        ? ''
        : indicator.output_names.map(cleanName).map((n, i) => `${n}: unshift(result[${i}], start)`)
    } };
      }) as IndicatorFn<typeof schemas.${indicator.name}>\n`,
  )}
};
`;

fs.writeFileSync(outputFiles.public, format(publicOutput, { parser: 'typescript' }));
fs.writeFileSync(outputFiles.core, format(coreOutput, { parser: 'typescript' }));
console.log(`Generated typescript bindings for ${indicators.length} indicators!`);
