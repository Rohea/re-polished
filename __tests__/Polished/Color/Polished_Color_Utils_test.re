open Jest;
open Expect;
open Polished_Types;
open Polished_Color_Utils;

describe("convertRGBtoHEX", () => {
  test("rgba(0,0,0) -> 000000", () => {
    let rgb = RGB.fromPrimitives(0, 0, 0);
    expect(rgb->convertRGBtoHEX->HEX.asString) |> toBe("000000");
  });
  test("rgba(255,255,255) -> ffffff", () => {
    let rgb = RGB.fromPrimitives(255, 255, 255);
    expect(rgb->convertRGBtoHEX->HEX.asString) |> toBe("ffffff");
  });
  test("rgba(122,32,65) -> 7a2041", () => {
    let rgb = RGB.fromPrimitives(122, 32, 65);
    expect(rgb->convertRGBtoHEX->HEX.asString) |> toBe("7a2041");
  });
});

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

describe("Polished_Color_Utils.getLuminance", () => {
  test("luminance of black", () => {
    expect(RGB(RGB.fromPrimitives(0, 0, 0))->getLuminance) |> toBe(0.0)
  });
  test("luminance of white", () => {
    expect(RGB(RGB.fromPrimitives(255, 255, 255))->getLuminance)
    |> toBe(1.0)
  });
  test("luminance of #808080", () => {
    expect(RGB(RGB.fromPrimitives(128, 128, 128))->getLuminance)
    |> toBeSoCloseTo(0.21586, ~digits=4)
  });
});
