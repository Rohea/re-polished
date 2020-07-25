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

describe("Polished_Color_Utils.convertHSLAtoRGBA", () => {
  test("convert hsla(0.0, 0.0, 0.0, 0.0) to rgba(0, 0, 0, 0.0) ", () => {
    expect(HSLA.fromPrimitives(0.0, 0.0, 0.0, 0.0)->convertHSLAtoRGBA)
    |> toEqual(RGBA.fromPrimitives(0, 0, 0, 0.0))
  });

  test("convert hsla(0.0, 0.0, 0.0, 0.5) to rgba(0, 0, 0, 0.5) ", () => {
    expect(HSLA.fromPrimitives(0.0, 0.0, 0.0, 0.5)->convertHSLAtoRGBA)
    |> toEqual(RGBA.fromPrimitives(0, 0, 0, 0.5))
  });

  test("convert hsla(0.0, 0.0, 0.0, 1.0) to rgba(0, 0, 0, 1.0) ", () => {
    expect(HSLA.fromPrimitives(0.0, 0.0, 0.0, 1.0)->convertHSLAtoRGBA)
    |> toEqual(RGBA.fromPrimitives(0, 0, 0, 1.0))
  });

  test("convert hsla(0.0, 0.0, 1.0, 0.0) to rgba(255, 255, 255, 0.0) ", () => {
    expect(HSLA.fromPrimitives(0.0, 0.0, 1.0, 0.0)->convertHSLAtoRGBA)
    |> toEqual(RGBA.fromPrimitives(255, 255, 255, 0.0))
  });

  test("convert hsla(0.0, 0.0, 1.0, 0.5) to rgba(255, 255, 255, 0.5) ", () => {
    expect(HSLA.fromPrimitives(0.0, 0.0, 1.0, 0.5)->convertHSLAtoRGBA)
    |> toEqual(RGBA.fromPrimitives(255, 255, 255, 0.5))
  });

  test("convert hsla(0.0, 0.0, 1.0, 1.0) to rgba(255, 255, 255, 1.0) ", () => {
    expect(HSLA.fromPrimitives(0.0, 0.0, 1.0, 1.0)->convertHSLAtoRGBA)
    |> toEqual(RGBA.fromPrimitives(255, 255, 255, 1.0))
  });

  test("convert hsla(0.0, 0.5, 0.5, 0.0) to rgba(191, 64, 64, 0.0) ", () => {
    expect(HSLA.fromPrimitives(0.0, 0.5, 0.5, 0.0)->convertHSLAtoRGBA)
    |> toEqual(RGBA.fromPrimitives(191, 64, 64, 0.0))
  });

  test("convert hsla(0.0, 0.5, 0.5, 0.5) to rgba(191, 64, 64, 0.5) ", () => {
    expect(HSLA.fromPrimitives(0.0, 0.5, 0.5, 0.5)->convertHSLAtoRGBA)
    |> toEqual(RGBA.fromPrimitives(191, 64, 64, 0.5))
  });

  test("convert hsla(0.0, 0.5, 0.5, 1.0) to rgba(191, 64, 64, 1.0) ", () => {
    expect(HSLA.fromPrimitives(0.0, 0.5, 0.5, 1.0)->convertHSLAtoRGBA)
    |> toEqual(RGBA.fromPrimitives(191, 64, 64, 1.0))
  });

  test("convert hsla(360.0, 0.5, 0.5, 0.0) to rgba(191, 64, 64, 0.0) ", () => {
    expect(HSLA.fromPrimitives(360.0, 0.5, 0.5, 0.0)->convertHSLAtoRGBA)
    |> toEqual(RGBA.fromPrimitives(191, 64, 64, 0.0))
  });

  test("convert hsla(360.0, 0.5, 0.5, 0.5) to rgba(191, 64, 64, 0.5) ", () => {
    expect(HSLA.fromPrimitives(360.0, 0.5, 0.5, 0.5)->convertHSLAtoRGBA)
    |> toEqual(RGBA.fromPrimitives(191, 64, 64, 0.5))
  });

  test("convert hsla(360.0, 0.5, 0.5, 1.0) to rgba(191, 64, 64, 1.0) ", () => {
    expect(HSLA.fromPrimitives(360.0, 0.5, 0.5, 1.0)->convertHSLAtoRGBA)
    |> toEqual(RGBA.fromPrimitives(191, 64, 64, 1.0))
  });

  test("convert hsla(210.0, 1.0, 0.5, 0.5) to rgba(0, 128, 255, 0.5) ", () => {
    expect(HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.5)->convertHSLAtoRGBA)
    |> toEqual(RGBA.fromPrimitives(0, 128, 255, 0.5))
  });

  test("convert hsla(209.8, 1.0, 0.5, 1.0) to rgba(0, 128, 255, 1.0) ", () => {
    expect(HSLA.fromPrimitives(209.8, 1.0, 0.5, 1.0)->convertHSLAtoRGBA)
    |> toEqual(RGBA.fromPrimitives(0, 128, 255, 1.0))
  });

  test("convert hsla(209.2, 1.0, 0.5, 1.0) to rgba(0, 131, 255, 1.0) ", () => {
    expect(HSLA.fromPrimitives(209.2, 1.0, 0.5, 1.0)->convertHSLAtoRGBA)
    |> toEqual(RGBA.fromPrimitives(0, 131, 255, 1.0))
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
