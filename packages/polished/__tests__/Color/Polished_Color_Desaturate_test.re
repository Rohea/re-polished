open Jest;
open Expect;
open Polished_Types;
open Polished_Color_Desaturate;

describe("Polished_Color_Desaturate.Impl.desaturateHSLA", () => {
  test("desaturate hsla(210.0, 1.0, 0.5, 0.5)  by 0.4", () => {
    expect(
      Impl.desaturateHSLA(
        HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.5),
        Percent.make(0.4),
      ),
    )
    |> toEqual(HSLA.fromPrimitives(210.0, 0.6, 0.5, 0.5))
  });

  test("desaturate by 0.0 should not affect saturation value", () => {
    expect(
      Impl.desaturateHSLA(
        HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.5),
        Percent.make(0.0),
      ),
    )
    |> toEqual(HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.5))
  });

  test("desaturate should not decrease saturation under 0.0", () => {
    expect(
      Impl.desaturateHSLA(
        HSLA.fromPrimitives(210.0, 0.1, 0.5, 0.5),
        Percent.make(0.4),
      ),
    )
    |> toEqual(HSLA.fromPrimitives(210.0, 0.0, 0.5, 0.5))
  });
});

describe("Polished_Color_Desaturate.desaturate", () => {
  test("desaturate #0080FF by 0.3", () => {
    expect(desaturate(HEX(HEX.make("0080FF")), Percent.make(0.3)))
    |> toEqual(HEX(HEX.make("2680d9")))
  });

  test("desaturate rgb(0, 128, 255) by 0.3", () => {
    expect(
      desaturate(RGB(RGB.fromPrimitives(0, 128, 255)), Percent.make(0.3)),
    )
    |> toEqual(RGB(RGB.fromPrimitives(38, 128, 217)))
  });

  test("desaturate rgba(0, 128, 255, 0.5) by 0.3", () => {
    expect(
      desaturate(
        RGBA(RGBA.fromPrimitives(0, 128, 255, 0.5)),
        Percent.make(0.3),
      ),
    )
    |> toEqual(RGBA(RGBA.fromPrimitives(38, 128, 217, 0.5)))
  });

  test("desaturate hsl(210.0, 1.0, 0.5) by 0.3", () => {
    expect(
      desaturate(
        HSL(HSL.fromPrimitives(210.0, 1.0, 0.5)),
        Percent.make(0.3),
      ),
    )
    |> toEqual(HSL(HSL.fromPrimitives(210.0, 0.7, 0.5)))
  });

  test("desaturate hsl(210.0, 1.0, 0.5, 0.5) by 0.3", () => {
    expect(
      desaturate(
        HSLA(HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.5)),
        Percent.make(0.3),
      ),
    )
    |> toEqual(HSLA(HSLA.fromPrimitives(210.0, 0.7, 0.5, 0.5)))
  });
});
