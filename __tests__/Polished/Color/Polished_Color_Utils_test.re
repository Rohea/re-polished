open Jest;
open Expect;
open Polished_Types;
open Polished_Color_Utils;

describe("Polished_Color_Utils.round_float", () => {
  test("round 0.0 to 0.0", () => {
    expect(round_float(0.0)) |> toBe(0.0)
  });

  test("round 0.2 to 0.0", () => {
    expect(round_float(0.2)) |> toBe(0.0)
  });

  test("round 0.5 to 1.0", () => {
    expect(round_float(0.5)) |> toBe(1.0)
  });

  test("round 0.7 to 1.0", () => {
    expect(round_float(0.7)) |> toBe(1.0)
  });

  test("round -0.2 to 0.0", () => {
    expect(round_float(-0.2)) |> toBe(0.0)
  });

  test("round -0.5 to 0.0", () => {
    expect(round_float(-0.5)) |> toBe(0.0)
  });

  test("round -0.501 to 1.0", () => {
    expect(round_float(-0.501)) |> toBe(-1.0)
  });

  test("round -1.0 to -1.0", () => {
    expect(round_float(-1.0)) |> toBe(-1.0)
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

describe("Polished_Color_Utils.convertHEXtoRGB", () => {
  test("convert #000000 to rgb(0, 0, 0)", () => {
    expect(HEX.make("000000")->convertHEXtoRGB)
    |> toEqual(RGB.fromPrimitives(0, 0, 0))
  });

  test("convert #ffffff to rgb(255, 255, 255)", () => {
    expect(HEX.make("ffffff")->convertHEXtoRGB)
    |> toEqual(RGB.fromPrimitives(255, 255, 255))
  });

  test("convert #0080ff to rgb(0, 128, 255)", () => {
    expect(HEX.make("0080ff")->convertHEXtoRGB)
    |> toEqual(RGB.fromPrimitives(0, 128, 255))
  });

  test("convert #5588cc to rgb(85, 136, 204)", () => {
    expect(HEX.make("5588cc")->convertHEXtoRGB)
    |> toEqual(RGB.fromPrimitives(85, 136, 204))
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

describe("Polished_Color_Utils.convertRGBAtoHSLA", () => {
  test("convert rgba(0, 0, 0, 0.0) to hsla(0.0, 0.0, 0.0, 0.0) ", () => {
    expect(RGBA.fromPrimitives(0, 0, 0, 0.0)->convertRGBAtoHSLA)
    |> toEqual(HSLA.fromPrimitives(0.0, 0.0, 0.0, 0.0))
  });

  test("convert rgba(0, 0, 0, 0.5) to hsla(0.0, 0.0, 0.0, 0.5) ", () => {
    expect(RGBA.fromPrimitives(0, 0, 0, 0.5)->convertRGBAtoHSLA)
    |> toEqual(HSLA.fromPrimitives(0.0, 0.0, 0.0, 0.5))
  });

  test("convert rgba(0, 0, 0, 1.0) to hsla(0.0, 0.0, 0.0, 1.0) ", () => {
    expect(RGBA.fromPrimitives(0, 0, 0, 1.0)->convertRGBAtoHSLA)
    |> toEqual(HSLA.fromPrimitives(0.0, 0.0, 0.0, 1.0))
  });

  test("convert rgba(255, 255, 255, 0.0) to hsla(0.0, 0.0, 1.0, 0.0) ", () => {
    expect(RGBA.fromPrimitives(255, 255, 255, 0.0)->convertRGBAtoHSLA)
    |> toEqual(HSLA.fromPrimitives(0.0, 0.0, 1.0, 0.0))
  });

  test("convert rgba(255, 255, 255, 0.5) to hsla(0.0, 0.0, 1.0, 0.5) ", () => {
    expect(RGBA.fromPrimitives(255, 255, 255, 0.5)->convertRGBAtoHSLA)
    |> toEqual(HSLA.fromPrimitives(0.0, 0.0, 1.0, 0.5))
  });

  test("convert rgba(255, 255, 255, 1.0) to hsla(0.0, 0.0, 1.0, 1.0) ", () => {
    expect(RGBA.fromPrimitives(255, 255, 255, 1.0)->convertRGBAtoHSLA)
    |> toEqual(HSLA.fromPrimitives(0.0, 0.0, 1.0, 1.0))
  });

  test(
    "convert rgba(0, 128, 255, 0.0) to hsla(209.88235294117646, 1.0, 0.5, 0.0) ",
    () => {
    expect(RGBA.fromPrimitives(0, 128, 255, 0.0)->convertRGBAtoHSLA)
    |> toEqual(HSLA.fromPrimitives(209.88235294117646, 1.0, 0.5, 0.0))
  });

  test(
    "convert rgba(0, 128, 255, 0.5) to hsla(209.88235294117646, 1.0, 0.5, 0.5) ",
    () => {
    expect(RGBA.fromPrimitives(0, 128, 255, 0.5)->convertRGBAtoHSLA)
    |> toEqual(HSLA.fromPrimitives(209.88235294117646, 1.0, 0.5, 0.5))
  });

  test(
    "convert rgba(0, 128, 255, 1.0) to hsla(209.88235294117646, 1.0, 0.5, 1.0) ",
    () => {
    expect(RGBA.fromPrimitives(0, 128, 255, 1.0)->convertRGBAtoHSLA)
    |> toEqual(HSLA.fromPrimitives(209.88235294117646, 1.0, 0.5, 1.0))
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

describe("Polished_Color_Utils.convertRGBAtoRGB", () => {
  test("convert rgba(0, 128, 255, 0.5) to rgb(0, 128, 255) ", () => {
    expect(RGBA.fromPrimitives(0, 128, 255, 0.5)->convertRGBAtoRGB)
    |> toEqual(RGB.fromPrimitives(0, 128, 255))
  })
});

describe("Polished_Color_Utils.convertRGBtoRGBA", () => {
  test("convert rgb(0, 128, 255) to rgba(0, 128, 255, 1.0) ", () => {
    expect(RGB.fromPrimitives(0, 128, 255)->convertRGBtoRGBA)
    |> toEqual(RGBA.fromPrimitives(0, 128, 255, 1.0))
  })
});

describe("Polished_Color_Utils.convertHSLtoHSLA", () => {
  test("convert hsl(180.0, 0.5, 1.0) to hsla(180.0, 0.5, 1.0, 1.0) ", () => {
    expect(HSL.fromPrimitives(180.0, 0.5, 1.0)->convertHSLtoHSLA)
    |> toEqual(HSLA.fromPrimitives(180.0, 0.5, 1.0, 1.0))
  })
});

describe("Polished_Color_Utils.convertHSLAtoHSL", () => {
  test("convert hsla(180.0, 0.5, 1.0, 0.5) to hsl(180.0, 0.5, 1.0) ", () => {
    expect(HSLA.fromPrimitives(180.0, 0.5, 1.0, 0.5)->convertHSLAtoHSL)
    |> toEqual(HSL.fromPrimitives(180.0, 0.5, 1.0))
  })
});

describe("Polished_Color_Utils.convertColorToRGB", () => {
  let expectedRGB = RGB.fromPrimitives(0, 128, 255);

  test("convert color rgb(0, 128, 255) to rgb(0, 128, 255) ", () => {
    expect(RGB(RGB.fromPrimitives(0, 128, 255))->convertColorToRGB)
    |> toEqual(expectedRGB)
  });

  test("convert color rgba(0, 128, 255, 0.5) to rgb(0, 128, 255) ", () => {
    expect(RGBA(RGBA.fromPrimitives(0, 128, 255, 0.5))->convertColorToRGB)
    |> toEqual(expectedRGB)
  });

  test("convert color #0080FF to rgb(0, 128, 255) ", () => {
    expect(HEX(HEX.make("0080FF"))->convertColorToRGB)
    |> toEqual(expectedRGB)
  });

  test("convert color hsla(210.0, 1.0, 0.5, 0.5) to rgb(0, 128, 255) ", () => {
    expect(
      HSLA(HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.5))->convertColorToRGB,
    )
    |> toEqual(expectedRGB)
  });

  test("convert color hsl(210.0, 1.0, 0.5) to rgb(0, 128, 255) ", () => {
    expect(HSL(HSL.fromPrimitives(210.0, 1.0, 0.5))->convertColorToRGB)
    |> toEqual(expectedRGB)
  });
});

describe("Polished_Color_Utils.convertColorToRGBA", () => {
  let expectedRGBA = RGBA.fromPrimitives(0, 128, 255, 0.5);
  let expectedRGBAOpaque = RGBA.fromPrimitives(0, 128, 255, 1.0);

  test("convert color rgb(0, 128, 255) to rgba(0, 128, 255, 1.0) ", () => {
    expect(RGB(RGB.fromPrimitives(0, 128, 255))->convertColorToRGBA)
    |> toEqual(expectedRGBAOpaque)
  });

  test("convert color rgba(0, 128, 255, 0.5) to rgba(0, 128, 255, 0.5) ", () => {
    expect(RGBA(RGBA.fromPrimitives(0, 128, 255, 0.5))->convertColorToRGBA)
    |> toEqual(expectedRGBA)
  });

  test("convert color #0080FF to rgba(0, 128, 255, 1.0) ", () => {
    expect(HEX(HEX.make("0080FF"))->convertColorToRGBA)
    |> toEqual(expectedRGBAOpaque)
  });

  test(
    "convert color hsla(210.0, 1.0, 0.5, 0.5) to rgba(0, 128, 255, 0.5) ", () => {
    expect(
      HSLA(HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.5))->convertColorToRGBA,
    )
    |> toEqual(expectedRGBA)
  });

  test("convert color hsl(210.0, 1.0, 0.5) to rgba(0, 128, 255, 1.0) ", () => {
    expect(HSL(HSL.fromPrimitives(210.0, 1.0, 0.5))->convertColorToRGBA)
    |> toEqual(expectedRGBAOpaque)
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

describe("Polished_Color_Utils.getContrast", () => {
  let black = RGB(RGB.fromPrimitives(0, 0, 0));
  let white = RGB(RGB.fromPrimitives(255, 255, 255));
  let color = RGB(RGB.fromPrimitives(0, 128, 128));

  test("contrast between white and black", () => {
    expect(getContrast(white, black)) |> toBe(21.0)
  });

  test("contrast between black and #008080", () => {
    expect(getContrast(black, color)) |> toBeSoCloseTo(4.39937, ~digits=4)
  });

  test("contrast between white and #008080", () => {
    expect(getContrast(white, color)) |> toBeSoCloseTo(4.77340, ~digits=4)
  });
});
