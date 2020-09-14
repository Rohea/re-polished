open Jest;
open Expect;
open Polished_Types;
open Polished_Color_Tint;

describe("Polished_Color_Tint.tint", () => {
  test("100% tint should make the color white", () => {
    expect(tint(RGB(RGB.fromPrimitives(0, 128, 255)), Percent.make(1.0)))
    |> toEqual(RGB(RGB.fromPrimitives(255, 255, 255)))
  });

  test("0% tint should not change the color", () => {
    expect(tint(RGB(RGB.fromPrimitives(0, 128, 255)), Percent.make(0.0)))
    |> toEqual(RGB(RGB.fromPrimitives(0, 128, 255)))
  });

  test("use tint on rgb color", () => {
    expect(tint(RGB(RGB.fromPrimitives(0, 128, 255)), Percent.make(0.5)))
    |> toEqual(RGB(RGB.fromPrimitives(127, 191, 255)))
  });

  test("use tint on rgba color", () => {
    expect(
      tint(RGBA(RGBA.fromPrimitives(0, 128, 255, 0.5)), Percent.make(0.5)),
    )
    |> toEqual(RGBA(RGBA.fromPrimitives(127, 191, 255, 0.5)))
  });

  test("use tint on hsl color", () => {
    expect(
      tint(HSL(HSL.fromPrimitives(210.0, 1.0, 0.5)), Percent.make(0.5)),
    )
    |> toEqual(HSL(HSL.fromPrimitives(210.0, 1.0, 0.7490196078431373)))
  });
  test("use tint on hsla color", () => {
    expect(
      tint(
        HSLA(HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.5)),
        Percent.make(0.5),
      ),
    )
    |> toEqual(
         HSLA(HSLA.fromPrimitives(210.0, 1.0, 0.7490196078431373, 0.5)),
       )
  });
  test("use tint on hex color", () => {
    expect(tint(HEX(HEX.make("0080FF")), Percent.make(0.5)))
    |> toEqual(HEX(HEX.make("7FBFFF")))
  });
});
