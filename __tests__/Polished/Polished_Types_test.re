open Jest;

open Expect;

open Polished_Types;

describe("Polished_Types.Int8", () => {
  test("make", () => {
    expect(Int8.make(127)->Int8.asInt) |> toBe(127)
  });

  test("max 255", () => {
    expect(Int8.make(256)->Int8.asInt) |> toBe(255)
  });

  test("min 0", () => {
    expect(Int8.make(-1)->Int8.asInt) |> toBe(0)
  });

  test("asFloat", () => {
    expect(Int8.make(127)->Int8.toFloat) |> toBe(127.0)
  });

  test("fromHEX with 0A", () => {
    expect(Int8.fromHEX('0', 'A')->Int8.asInt) |> toBe(10)
  });

  test("fromHEX with FF", () => {
    expect(Int8.fromHEX('F', 'F')->Int8.asInt) |> toBe(255)
  });
});

describe("Polished_Types.Degree", () => {
  test("make", () => {
    expect(Degree.make(127.0)->Degree.asFloat) |> toBe(127.0)
  });

  test("max 360.0", () => {
    expect(Degree.make(361.0)->Degree.asFloat) |> toBe(360.0)
  });

  test("min 0.0", () => {
    expect(Degree.make(-1.0)->Degree.asFloat) |> toBe(0.0)
  });
});

describe("Polished_Types.Percent", () => {
  test("make", () => {
    expect(Percent.make(0.5)->Percent.asFloat) |> toBe(0.5)
  });

  test("max 1.0", () => {
    expect(Percent.make(1.5)->Percent.asFloat) |> toBe(1.0)
  });

  test("min 0.0", () => {
    expect(Percent.make(-1.0)->Percent.asFloat) |> toBe(0.0)
  });
});

describe("Polished_Types.RGB", () => {
  let rgb =
    RGB.make(
      ~red=Int8.make(1),
      ~green=Int8.make(127),
      ~blue=Int8.make(255),
    );
  let rgbFromPrimitives = RGB.fromPrimitives(1, 127, 255);
  let expectedRGBTuple = (Int8.make(1), Int8.make(127), Int8.make(255));

  test("make", () => {
    expect((rgb->RGB.red, rgb->RGB.green, rgb->RGB.blue))
    |> toEqual(expectedRGBTuple)
  });

  test("fromPrimitives", () => {
    expect(rgbFromPrimitives) |> toEqual(rgb)
  });

  test("red", () => {
    expect(rgb->RGB.red) |> toBe(Int8.make(1))
  });

  test("green", () => {
    expect(rgb->RGB.green) |> toBe(Int8.make(127))
  });

  test("blue", () => {
    expect(rgb->RGB.blue) |> toBe(Int8.make(255))
  });
});

describe("Polished_Types.RGBA", () => {
  let rgba =
    RGBA.make(
      ~red=Int8.make(0),
      ~green=Int8.make(127),
      ~blue=Int8.make(255),
      ~alpha=Percent.make(0.5),
    );
  let rgbaFromPrimitives = RGBA.fromPrimitives(0, 127, 255, 0.5);
  let expectedRGBATuple = (
    Int8.make(0),
    Int8.make(127),
    Int8.make(255),
    Percent.make(0.5),
  );

  test("make", () => {
    expect((
      rgba->RGBA.red,
      rgba->RGBA.green,
      rgba->RGBA.blue,
      rgba->RGBA.alpha,
    ))
    |> toEqual(expectedRGBATuple)
  });

  test("fromPrimitives", () => {
    expect(rgbaFromPrimitives) |> toEqual(rgba)
  });

  test("red", () => {
    expect(rgba->RGBA.red) |> toBe(Int8.make(0))
  });

  test("green", () => {
    expect(rgba->RGBA.green) |> toBe(Int8.make(127))
  });

  test("blue", () => {
    expect(rgba->RGBA.blue) |> toBe(Int8.make(255))
  });

  test("alpha", () => {
    expect(rgba->RGBA.alpha) |> toBe(Percent.make(0.5))
  });
});

describe("Polished_Types.HEX", () => {
  let hex = HEX.make("0008b5");

  test("make", () => {
    expect(hex->HEX.asString) |> toBe("0008b5")
  });

  test("asTuple", () => {
    expect(hex->HEX.asTuple) |> toEqual(('0', '0', '0', '8', 'b', '5'))
  });

  test("asString", () => {
    expect(hex->HEX.asString) |> toBe("0008b5")
  });

  test("make", () => {
    expect(HEX.make("AABBFF")->HEX.asString) |> toBe("aabbff")
  });
});

describe("Polished_Types.HSL", () => {
  let hsl =
    HSL.make(
      ~hue=Degree.make(180.0),
      ~saturation=Percent.make(0.7),
      ~lightness=Percent.make(0.5),
    );
  let hslFromPrimitives = HSL.fromPrimitives(180.0, 0.7, 0.5);
  let expectedHSLTuple = (
    Degree.make(180.0),
    Percent.make(0.7),
    Percent.make(0.5),
  );

  test("make", () => {
    expect((hsl->HSL.hue, hsl->HSL.saturation, hsl->HSL.lightness))
    |> toEqual(expectedHSLTuple)
  });

  test("fromPrimitives", () => {
    expect(hslFromPrimitives) |> toEqual(hsl)
  });

  test("hue", () => {
    expect(hsl->HSL.hue) |> toBe(Degree.make(180.0))
  });

  test("saturation", () => {
    expect(hsl->HSL.saturation) |> toBe(Percent.make(0.7))
  });

  test("lightness", () => {
    expect(hsl->HSL.lightness) |> toBe(Percent.make(0.5))
  });
});

describe("Polished_Types.HSLA", () => {
  let hsla =
    HSLA.make(
      ~hue=Degree.make(180.0),
      ~saturation=Percent.make(0.7),
      ~lightness=Percent.make(0.5),
      ~alpha=Percent.make(0.8),
    );
  let hslaFromPrimitives = HSLA.fromPrimitives(180.0, 0.7, 0.5, 0.8);
  let expectedHSLATuple = (
    Degree.make(180.0),
    Percent.make(0.7),
    Percent.make(0.5),
    Percent.make(0.8),
  );

  test("make", () => {
    expect((
      hsla->HSLA.hue,
      hsla->HSLA.saturation,
      hsla->HSLA.lightness,
      hsla->HSLA.alpha,
    ))
    |> toEqual(expectedHSLATuple)
  });

  test("fromPrimitives", () => {
    expect(hslaFromPrimitives) |> toEqual(hsla)
  });

  test("hue", () => {
    expect(hsla->HSLA.hue) |> toBe(Degree.make(180.0))
  });

  test("saturation", () => {
    expect(hsla->HSLA.saturation) |> toBe(Percent.make(0.7))
  });

  test("lightness", () => {
    expect(hsla->HSLA.lightness) |> toBe(Percent.make(0.5))
  });

  test("alpha", () => {
    expect(hsla->HSLA.alpha) |> toBe(Percent.make(0.8))
  });
});
