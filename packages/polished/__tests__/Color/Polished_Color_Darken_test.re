open Jest;
open Expect;
open Polished_Types;
open Polished_Color_Darken;

describe("Polished_Color_Darken.Impl.darkenHSLA", () => {
  test("darken hsla(210.0, 0.5, 1.0, 0.5) by 0.4", () => {
    expect(
      Impl.darkenHSLA(
        HSLA.fromPrimitives(210.0, 0.5, 1.0, 0.5),
        Percent.make(0.4),
      ),
    )
    |> toEqual(HSLA.fromPrimitives(210.0, 0.5, 0.6, 0.5))
  });

  test("darken by 0.0 should not affect lightness value", () => {
    expect(
      Impl.darkenHSLA(
        HSLA.fromPrimitives(210.0, 0.5, 1.0, 0.5),
        Percent.make(0.0),
      ),
    )
    |> toEqual(HSLA.fromPrimitives(210.0, 0.5, 1.0, 0.5))
  });

  test("darken should not decrease lightness under 0.0", () => {
    expect(
      Impl.darkenHSLA(
        HSLA.fromPrimitives(210.0, 0.5, 0.1, 0.5),
        Percent.make(0.4),
      ),
    )
    |> toEqual(HSLA.fromPrimitives(210.0, 0.5, 0.0, 0.5))
  });
});

describe("Polished_Color_Darken.darken", () => {
  test("darken hsl(210.0, 1.0, 0.5) by 0.3", () => {
    expect(
      darken(HSL(HSL.fromPrimitives(210.0, 1.0, 0.5)), Percent.make(0.3)),
    )
    |> toEqual(HSL(HSL.fromPrimitives(210.0, 1.0, 0.2)))
  });

  test("darken hsla(210.0, 1.0, 0.5, 0.5) by 0.3", () => {
    expect(
      darken(
        HSLA(HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.5)),
        Percent.make(0.3),
      ),
    )
    |> toEqual(HSLA(HSLA.fromPrimitives(210.0, 1.0, 0.2, 0.5)))
  });

  test("darken hsl(0.0, 1.0, 0.5) by 0.1", () => {
    expect(
      darken(HSL(HSL.fromPrimitives(0.0, 1.0, 0.5)), Percent.make(0.1)),
    )
    |> toEqual(HSL(HSL.fromPrimitives(0.0, 1.0, 0.4)))
  });

  test("darken rgb(255, 0, 0) by 0.1", () => {
    expect(darken(RGB(RGB.fromPrimitives(255, 0, 0)), Percent.make(0.1)))
    |> toEqual(RGB(RGB.fromPrimitives(204, 0, 0)))
  });

  test("darken #ff0000 by 0.1", () => {
    expect(darken(HEX(HEX.make("ff0000")), Percent.make(0.1)))
    |> toEqual(HEX(HEX.make("cc0000")))
  });
});
