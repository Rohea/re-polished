open Jest;
open Expect;
open Polished_Types;
open Polished_Color_Mix;

describe("Polished_Color_Mix.mix", () => {
  let expectedColor = RGBA(RGBA.fromPrimitives(0, 128, 255, 0.5));

  test("if weight 0, return baseColor", () => {
    expect(
      mix(
        RGBA(RGBA.fromPrimitives(0, 128, 255, 1.0)),
        expectedColor,
        Percent.make(0.0),
      ),
    )
    |> toEqual(expectedColor)
  });

  test(
    "should mix rgb(0, 128, 255) with rgb(0, 0, 0) at weight 1.0 and return rgb(0, 128, 255)",
    () => {
    expect(
      mix(
        RGB(RGB.fromPrimitives(0, 128, 255)),
        RGB(RGB.fromPrimitives(0, 0, 0)),
        Percent.make(1.0),
      ),
    )
    |> toEqual(RGB(RGB.fromPrimitives(0, 128, 255)))
  });

  /**
   * the saturation value gets screwed because of float / int conversions
   */
  test(
    "should mix hsl(120.0, 0.5, 0.7) with hsl(0.0, 0.0, 0.0) at weight 1.0 and return hsl(120.0, 0.503267973856209, 0.7)",
    () => {
    expect(
      mix(
        HSL(HSL.fromPrimitives(120.0, 0.5, 0.7)),
        HSL(HSL.fromPrimitives(0.0, 0.0, 0.0)),
        Percent.make(1.0),
      ),
    )
    |> toEqual(HSL(HSL.fromPrimitives(120.0, 0.503267973856209, 0.7)))
  });

  test("should mix #0080FF with #000000 at weight 1.0 and return #0080FF", () => {
    expect(
      mix(
        HEX(HEX.make("0080FF")),
        HEX(HEX.make("000000")),
        Percent.make(1.0),
      ),
    )
    |> toEqual(HEX(HEX.make("0080FF")))
  });

  test("should mix #0080FF with #000000 at weight 0.5 and return #00407F", () => {
    expect(
      mix(
        HEX(HEX.make("0080FF")),
        HEX(HEX.make("000000")),
        Percent.make(0.5),
      ),
    )
    |> toEqual(HEX(HEX.make("00407F")))
  });

  test(
    "should mix rgb(0, 0, 0) with rgb(0, 128, 255) at weight 1.0 and return rgb(0, 0, 0)",
    () => {
    expect(
      mix(
        RGB(RGB.fromPrimitives(0, 0, 0)),
        RGB(RGB.fromPrimitives(0, 128, 255)),
        Percent.make(1.0),
      ),
    )
    |> toEqual(RGB(RGB.fromPrimitives(0, 0, 0)))
  });

  test(
    "should mix rgb(128, 0, 255) with rgb(0, 0, 0) at weight 0.5 and return rgb(64, 0, 127)",
    () => {
    expect(
      mix(
        RGB(RGB.fromPrimitives(128, 0, 255)),
        RGB(RGB.fromPrimitives(0, 0, 0)),
        Percent.make(0.5),
      ),
    )
    |> toEqual(RGB(RGB.fromPrimitives(64, 0, 127)))
  });

  test(
    "should mix rgb(0, 0, 0) with rgb(128, 0, 255) at weight 0.5 and return rgb(64, 0, 127)",
    () => {
    expect(
      mix(
        RGB(RGB.fromPrimitives(0, 0, 0)),
        RGB(RGB.fromPrimitives(128, 0, 255)),
        Percent.make(0.5),
      ),
    )
    |> toEqual(RGB(RGB.fromPrimitives(64, 0, 127)))
  });

  /**
   * This tests the implementation of special case to be same as the one from SASS implementation
   * The special case implementation does not seem to follow logic of the non special case math
   */
  test(
    "should mix rgba(128, 0, 255, 0.5) with rgb(0, 0, 0) at weight 1.0 and return rgba(128, 0, 255, 0.5)",
    () => {
    expect(
      mix(
        RGBA(RGBA.fromPrimitives(128, 0, 255, 0.5)),
        RGB(RGB.fromPrimitives(0, 0, 0)),
        Percent.make(1.0),
      ),
    )
    |> toEqual(RGBA(RGBA.fromPrimitives(128, 0, 255, 0.5)))
  });

  test(
    "should mix rgba(128, 0, 255, 0.0) with rgb(0, 0, 0) at weight 1.0 and return rgba(128, 0, 255, 0.0)",
    () => {
    expect(
      mix(
        RGBA(RGBA.fromPrimitives(128, 0, 255, 0.0)),
        RGB(RGB.fromPrimitives(0, 0, 0)),
        Percent.make(1.0),
      ),
    )
    |> toEqual(RGBA(RGBA.fromPrimitives(128, 0, 255, 0.0)))
  });

  test(
    "should mix rgb(0, 0, 0) with rgba(128, 0, 255, 0.0) at weight 1.0 and return rgba(0, 0, 0, 1.0)",
    () => {
    expect(
      mix(
        RGB(RGB.fromPrimitives(0, 0, 0)),
        RGBA(RGBA.fromPrimitives(128, 0, 255, 0.0)),
        Percent.make(1.0),
      ),
    )
    |> toEqual(RGBA(RGBA.fromPrimitives(0, 0, 0, 1.0)))
  });

  test(
    "should mix rgba(128, 0, 255, 1.0) with rgb(0, 0, 0) at weight 0.5 and return rgba(64, 0, 127, 1.0)",
    () => {
    expect(
      mix(
        RGBA(RGBA.fromPrimitives(128, 0, 255, 1.0)),
        RGB(RGB.fromPrimitives(0, 0, 0)),
        Percent.make(0.5),
      ),
    )
    |> toEqual(RGBA(RGBA.fromPrimitives(64, 0, 127, 1.0)))
  });

  test(
    "should mix rgba(128, 0, 255, 0.5) with rgb(0, 0, 0) at weight 0.5 and return rgba(32, 0, 63, 0.75)",
    () => {
    expect(
      mix(
        RGBA(RGBA.fromPrimitives(128, 0, 255, 0.5)),
        RGB(RGB.fromPrimitives(0, 0, 0)),
        Percent.make(0.5),
      ),
    )
    |> toEqual(RGBA(RGBA.fromPrimitives(32, 0, 63, 0.75)))
  });

  test(
    "should mix rgb(0, 0, 0) with rgba(128, 0, 255, 0.5) at weight 0.5 and return rgba(32, 0, 63, 0.75)",
    () => {
    expect(
      mix(
        RGB(RGB.fromPrimitives(0, 0, 0)),
        RGBA(RGBA.fromPrimitives(128, 0, 255, 0.5)),
        Percent.make(0.5),
      ),
    )
    |> toEqual(RGBA(RGBA.fromPrimitives(32, 0, 63, 0.75)))
  });

  test(
    "should mix rgba(128, 0, 255, 0.0) with rgb(0, 0, 0) at weight 0.5 and return rgba(0, 0, 0, 0.5)",
    () => {
    expect(
      mix(
        RGBA(RGBA.fromPrimitives(128, 0, 255, 0.0)),
        RGB(RGB.fromPrimitives(0, 0, 0)),
        Percent.make(0.5),
      ),
    )
    |> toEqual(RGBA(RGBA.fromPrimitives(0, 0, 0, 0.5)))
  });

  test(
    "should mix rgb(0, 0, 0) with rgba(128, 0, 255, 0.0) at weight 0.5 and return rgba(0, 0, 0, 0.5)",
    () => {
    expect(
      mix(
        RGB(RGB.fromPrimitives(0, 0, 0)),
        RGBA(RGBA.fromPrimitives(128, 0, 255, 0.0)),
        Percent.make(0.5),
      ),
    )
    |> toEqual(RGBA(RGBA.fromPrimitives(0, 0, 0, 0.5)))
  });

  test(
    "should mix rgb(0, 0, 0) with hsla(210.0, 1.0, 0.5, 0.5) at weight 0.5 and return hsl(209.52380952380952, 1.0, 0.12352941176470589, 0.75)",
    () => {
    expect(
      mix(
        RGB(RGB.fromPrimitives(0, 0, 0)),
        HSLA(HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.5)),
        Percent.make(0.5),
      ),
    )
    |> toEqual(
         HSLA(
           HSLA.fromPrimitives(
             209.52380952380952,
             1.0,
             0.12352941176470589,
             0.75,
           ),
         ),
       )
  });

  test(
    "should mix rgba(0, 255, 128) with rgba(128, 0, 255, 0.5) at weight 0.5 and return rgba(64, 127, 191, 0.5)",
    () => {
    expect(
      mix(
        RGBA(RGBA.fromPrimitives(0, 255, 128, 0.5)),
        RGBA(RGBA.fromPrimitives(128, 0, 255, 0.5)),
        Percent.make(0.5),
      ),
    )
    |> toEqual(RGBA(RGBA.fromPrimitives(64, 127, 191, 0.5)))
  });
});
