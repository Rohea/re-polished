open Jest;
open Expect;
open Polished_Types;
open Polished_Color_Transparentize;

describe("Polished_Color_Transparentize.Impl.transparentizeAlphaValue", () => {
  test("transparentize 1.0 by 0.4", () => {
    expect(
      Impl.transparentizeAlphaValue(Percent.make(1.0), Percent.make(0.4)),
    )
    |> toEqual(Percent.make(0.6))
  });

  test("transparentize 0.4 by 0.0", () => {
    expect(
      Impl.transparentizeAlphaValue(Percent.make(0.4), Percent.make(0.0)),
    )
    |> toEqual(Percent.make(0.4))
  });

  test("transparentize 0.0 by 0.4", () => {
    expect(
      Impl.transparentizeAlphaValue(Percent.make(0.0), Percent.make(0.4)),
    )
    |> toEqual(Percent.make(0.0))
  });

  test("transparentize 1.0 by 1.4", () => {
    expect(
      Impl.transparentizeAlphaValue(Percent.make(1.0), Percent.make(1.4)),
    )
    |> toEqual(Percent.make(0.0))
  });
});

describe("Polished_Color_Transparentize.Impl.transparentizeRGBA", () => {
  test("transparentize rgba(0, 128, 255, 0.7) by 0.4", () => {
    expect(
      Impl.transparentizeRGBA(
        RGBA.fromPrimitives(0, 128, 255, 0.7),
        Percent.make(0.4),
      ),
    )
    |> toEqual(RGBA.fromPrimitives(0, 128, 255, 0.3))
  })
});

describe("Polished_Color_Transparentize.Impl.transparentizeHSLA", () => {
  test("transparentize hsla(210.0, 1.0, 0.5, 0.7) by 0.4", () => {
    expect(
      Impl.transparentizeHSLA(
        HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.7),
        Percent.make(0.4),
      ),
    )
    |> toEqual(HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.3))
  })
});

describe("Polished_Color_Transparentize.transparentize", () => {
  test("transparentize #0080FF by 0.6", () => {
    expect(transparentize(HEX(HEX.make("0080FF")), Percent.make(0.6)))
    |> toEqual(RGBA(RGBA.fromPrimitives(0, 128, 255, 0.4)))
  });

  test("transparentize rgb(0, 128, 255) by 0.6", () => {
    expect(
      transparentize(
        RGB(RGB.fromPrimitives(0, 128, 255)),
        Percent.make(0.6),
      ),
    )
    |> toEqual(RGBA(RGBA.fromPrimitives(0, 128, 255, 0.4)))
  });

  test("transparentize rgba(0, 128, 255, 0.7) by 0.3", () => {
    expect(
      transparentize(
        RGBA(RGBA.fromPrimitives(0, 128, 255, 0.7)),
        Percent.make(0.3),
      ),
    )
    |> toEqual(RGBA(RGBA.fromPrimitives(0, 128, 255, 0.4)))
  });

  test("transparentize hsl(210.0, 1.0, 0.5) by 0.6", () => {
    expect(
      transparentize(
        HSL(HSL.fromPrimitives(210.0, 1.0, 0.5)),
        Percent.make(0.6),
      ),
    )
    |> toEqual(HSLA(HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.4)))
  });

  test("transparentize hsla(210.0, 1.0, 0.5, 0.7) by 0.3", () => {
    expect(
      transparentize(
        HSLA(HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.7)),
        Percent.make(0.3),
      ),
    )
    |> toEqual(HSLA(HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.4)))
  });
});
