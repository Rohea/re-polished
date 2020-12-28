open Jest;
open Expect;
open Polished_Types;
open Polished_Color_Shade;

describe("Polished_Color_Shade.shade", () => {
  test("100% shade should make the color black", () => {
    expect(shade(RGB(RGB.fromPrimitives(0, 128, 255)), Percent.make(1.0)))
    |> toEqual(RGB(RGB.fromPrimitives(0, 0, 0)))
  });

  test("0% shade should not change the color", () => {
    expect(shade(RGB(RGB.fromPrimitives(0, 128, 255)), Percent.make(0.0)))
    |> toEqual(RGB(RGB.fromPrimitives(0, 128, 255)))
  });

  test("use shade on rgb color", () => {
    expect(shade(RGB(RGB.fromPrimitives(0, 128, 255)), Percent.make(0.5)))
    |> toEqual(RGB(RGB.fromPrimitives(0, 64, 127)))
  });

  test("use shade on rgba color", () => {
    expect(
      shade(
        RGBA(RGBA.fromPrimitives(0, 128, 255, 0.5)),
        Percent.make(0.5),
      ),
    )
    |> toEqual(RGBA(RGBA.fromPrimitives(0, 64, 127, 0.5)))
  });

  test("use shade on hsl color", () => {
    expect(
      shade(HSL(HSL.fromPrimitives(210.0, 1.0, 0.5)), Percent.make(0.5)),
    )
    |> toEqual(
         HSL(
           HSL.fromPrimitives(209.76377952755905, 1.0, 0.24901960784313726),
         ),
       )
  });

  test("use shade on hsla color", () => {
    expect(
      shade(
        HSLA(HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.5)),
        Percent.make(0.5),
      ),
    )
    |> toEqual(
         HSLA(
           HSLA.fromPrimitives(
             209.76377952755905,
             1.0,
             0.24901960784313726,
             0.5,
           ),
         ),
       )
  });

  test("use shade on hex color", () => {
    expect(shade(HEX(HEX.make("0080FF")), Percent.make(0.5)))
    |> toEqual(HEX(HEX.make("00407F")))
  });
});
