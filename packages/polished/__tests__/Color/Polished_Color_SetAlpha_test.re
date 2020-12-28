open Jest;
open Expect;
open Polished_Types;
open Polished_Color_SetAlpha;

describe("Polished_Color_SetAlpha.Impl.setAlphaForRGBA", () => {
  test("setAplha of rgba(0, 128, 255, 0.7) to 0.4", () => {
    expect(
      Impl.setAlphaForRGBA(
        RGBA.fromPrimitives(0, 128, 255, 0.7),
        Percent.make(0.4),
      ),
    )
    |> toEqual(RGBA.fromPrimitives(0, 128, 255, 0.4))
  });
  test("setAplha of rgba(0, 128, 255, 0.7) to 1", () => {
    expect(
      Impl.setAlphaForRGBA(
        RGBA.fromPrimitives(0, 128, 255, 0.7),
        Percent.make(1.0),
      ),
    )
    |> toEqual(RGBA.fromPrimitives(0, 128, 255, 1.0))
  });
});

describe("Polished_Color_SetAlpha.Impl.setAlphaForHSLA", () => {
  test("setAplha of hsla(210.0, 1.0, 0.5, 0.7) to 0.4", () => {
    expect(
      Impl.setAlphaForHSLA(
        HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.7),
        Percent.make(0.4),
      ),
    )
    |> toEqual(HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.4))
  });
  test("setAplha of hsla(210.0, 1.0, 0.5, 0.7) to 1.0", () => {
    expect(
      Impl.setAlphaForHSLA(
        HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.7),
        Percent.make(1.0),
      ),
    )
    |> toEqual(HSLA.fromPrimitives(210.0, 1.0, 0.5, 1.0))
  });
});

describe("Polished_Color_SetAlpha.setAlpha", () => {
  test("setAlpha of #0080FF to 0.6", () => {
    expect(setAlpha(HEX(HEX.make("0080FF")), Percent.make(0.6)))
    |> toEqual(RGBA(RGBA.fromPrimitives(0, 128, 255, 0.6)))
  });

  test("setAlpha of rgb(0, 128, 255) to 0.6", () => {
    expect(
      setAlpha(RGB(RGB.fromPrimitives(0, 128, 255)), Percent.make(0.6)),
    )
    |> toEqual(RGBA(RGBA.fromPrimitives(0, 128, 255, 0.6)))
  });

  test("setAlpha of rgba(0, 128, 255, 0.7) to 0.3", () => {
    expect(
      setAlpha(
        RGBA(RGBA.fromPrimitives(0, 128, 255, 0.7)),
        Percent.make(0.3),
      ),
    )
    |> toEqual(RGBA(RGBA.fromPrimitives(0, 128, 255, 0.3)))
  });

  test("setAlpha of hsl(210.0, 1.0, 0.5) to 0.6", () => {
    expect(
      setAlpha(
        HSL(HSL.fromPrimitives(210.0, 1.0, 0.5)),
        Percent.make(0.6),
      ),
    )
    |> toEqual(HSLA(HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.6)))
  });

  test("setAlpha of hsla(210.0, 1.0, 0.5, 0.7) to 0.3", () => {
    expect(
      setAlpha(
        HSLA(HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.7)),
        Percent.make(0.3),
      ),
    )
    |> toEqual(HSLA(HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.3)))
  });
});
