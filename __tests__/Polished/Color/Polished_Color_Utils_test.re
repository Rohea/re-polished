open Jest;
open Expect;
open Polished_Types;
open Polished_Color_Utils;

describe("floatInRange", () => {
  test("-0.3 -> 0.0", () => {
    expect((-0.3)->floatInRange(0.0, 1.0)) |> toBe(0.0)
  });
  test("0.45 -> 0.45", () => {
    expect(0.45->floatInRange(0.0, 1.0)) |> toBe(0.45)
  });
  test("1.23 -> 1.00", () => {
    expect(1.23->floatInRange(0.0, 1.0)) |> toBe(1.0)
  });
});

describe("Polished_Color_Utils.convertRGBtoHEX", () => {
  test("convert rgb(0, 0, 0) to #000000", () => {
    expect(RGB.fromPrimitives(0, 0, 0)->convertRGBtoHEX)
    |> toEqual(HEX.make("000000"))
  });

  test("convert rgb(255, 255, 255) to #ffffff", () => {
    expect(RGB.fromPrimitives(255, 255, 255)->convertRGBtoHEX)
    |> toEqual(HEX.make("ffffff"))
  });

  test("convert rgb(0, 128, 255) to #0080ff", () => {
    expect(RGB.fromPrimitives(0, 128, 255)->convertRGBtoHEX)
    |> toEqual(HEX.make("0080ff"))
  });
});
