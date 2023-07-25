export const roundTo = (digits: number) => (n: number) =>
  Math.round((n + Number.EPSILON) * 10 ** digits) / 10 ** digits;
