open Jest;
open Expect;
open Polished_Types;
open Polished_Color_Opacify;

describe("Polished_Color_Opacify.Impl.opacifyAlphaValue", () => {
  test("opacify 0.0 by 0.4", () => {
    expect(Impl.opacifyAlphaValue(Percent.make(0.0), Percent.make(0.4)))
    |> toEqual(Percent.make(0.4))
  });

  test("opacify 0.4 by 0.0", () => {
    expect(Impl.opacifyAlphaValue(Percent.make(0.4), Percent.make(0.0)))
    |> toEqual(Percent.make(0.4))
  });

  test("opacify 1.0 by 0.4", () => {
    expect(Impl.opacifyAlphaValue(Percent.make(1.0), Percent.make(0.4)))
    |> toEqual(Percent.make(1.0))
  });

  test("opacify 0.0 by 1.4", () => {
    expect(Impl.opacifyAlphaValue(Percent.make(0.0), Percent.make(1.4)))
    |> toEqual(Percent.make(1.0))
  });
});

describe("Polished_Color_Opacify.Impl.opacifyRGBA", () => {
  test("opacify rgba(0, 128, 255, 0.3) by 0.4", () => {
    expect(
      Impl.opacifyRGBA(
        RGBA.fromPrimitives(0, 128, 255, 0.3),
        Percent.make(0.4),
      ),
    )
    |> toEqual(RGBA.fromPrimitives(0, 128, 255, 0.7))
  })
});

describe("Polished_Color_Opacify.Impl.opacifyHSLA", () => {
  test("opacify hsla(210.0, 1.0, 0.5, 0.3) by 0.4", () => {
    expect(
      Impl.opacifyHSLA(
        HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.3),
        Percent.make(0.4),
      ),
    )
    |> toEqual(HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.7))
  })
});

describe("Polished_Color_Opacify.opacify", () => {
  test("opacify #0080FF by 0.6", () => {
    expect(opacify(HEX(HEX.make("0080FF")), Percent.make(0.6)))
    |> toEqual(RGBA(RGBA.fromPrimitives(0, 128, 255, 1.0)))
  });

  test("opacify rgb(0, 128, 255) by 0.6", () => {
    expect(
      opacify(RGB(RGB.fromPrimitives(0, 128, 255)), Percent.make(0.6)),
    )
    |> toEqual(RGBA(RGBA.fromPrimitives(0, 128, 255, 1.0)))
  });

  test("opacify rgba(0, 128, 255, 0.4) by 0.3", () => {
    expect(
      opacify(
        RGBA(RGBA.fromPrimitives(0, 128, 255, 0.4)),
        Percent.make(0.3),
      ),
    )
    |> toEqual(RGBA(RGBA.fromPrimitives(0, 128, 255, 0.7)))
  });

  test("opacify hsl(210.0, 1.0, 0.5) by 0.6", () => {
    expect(
      opacify(HSL(HSL.fromPrimitives(210.0, 1.0, 0.5)), Percent.make(0.6)),
    )
    |> toEqual(HSLA(HSLA.fromPrimitives(210.0, 1.0, 0.5, 1.0)))
  });

  test("opacify hsla(210.0, 1.0, 0.5, 0.4) by 0.3", () => {
    expect(
      opacify(
        HSLA(HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.4)),
        Percent.make(0.3),
      ),
    )
    |> toEqual(HSLA(HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.7)))
  });
});
