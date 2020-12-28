open Jest;
open Expect;
open Polished_Types;
open Polished_Color_Lighten;

describe("Polished_Color_Lighten.Impl.lightenHSLA", () => {
  test("lighten hsla(210.0, 0.5, 0.0, 0.5) by 0.4", () => {
    expect(
      Impl.lightenHSLA(
        HSLA.fromPrimitives(210.0, 0.5, 0.0, 0.5),
        Percent.make(0.4),
      ),
    )
    |> toEqual(HSLA.fromPrimitives(210.0, 0.5, 0.4, 0.5))
  });

  test("lighten by 0.0 should not affect lightness value", () => {
    expect(
      Impl.lightenHSLA(
        HSLA.fromPrimitives(210.0, 0.5, 0.0, 0.5),
        Percent.make(0.0),
      ),
    )
    |> toEqual(HSLA.fromPrimitives(210.0, 0.5, 0.0, 0.5))
  });

  test("lighten should not increase lightness above 1.0", () => {
    expect(
      Impl.lightenHSLA(
        HSLA.fromPrimitives(210.0, 0.5, 0.8, 0.5),
        Percent.make(0.4),
      ),
    )
    |> toEqual(HSLA.fromPrimitives(210.0, 0.5, 1.0, 0.5))
  });
});

describe("Polished_Color_Lighten.lighten", () => {
  test("lighten hsl(210.0, 1.0, 0.5) by 0.3", () => {
    expect(
      lighten(HSL(HSL.fromPrimitives(210.0, 1.0, 0.5)), Percent.make(0.3)),
    )
    |> toEqual(HSL(HSL.fromPrimitives(210.0, 1.0, 0.8)))
  });

  test("lighten hsla(210.0, 1.0, 0.5, 0.5) by 0.3", () => {
    expect(
      lighten(
        HSLA(HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.5)),
        Percent.make(0.3),
      ),
    )
    |> toEqual(HSLA(HSLA.fromPrimitives(210.0, 1.0, 0.8, 0.5)))
  });

  test("lighten hsl(0.0, 1.0, 0.5) by 0.1", () => {
    expect(
      lighten(HSL(HSL.fromPrimitives(0.0, 1.0, 0.5)), Percent.make(0.1)),
    )
    |> toEqual(HSL(HSL.fromPrimitives(0.0, 1.0, 0.6)))
  });

  test("lighten rgb(255, 0, 0) by 0.1", () => {
    expect(lighten(RGB(RGB.fromPrimitives(255, 0, 0)), Percent.make(0.1)))
    |> toEqual(RGB(RGB.fromPrimitives(255, 51, 51)))
  });

  test("lighten #ff0000 by 0.1", () => {
    expect(lighten(HEX(HEX.make("ff0000")), Percent.make(0.1)))
    |> toEqual(HEX(HEX.make("ff3333")))
  });
});
