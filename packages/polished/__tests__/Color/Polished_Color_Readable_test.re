open Jest;

open Expect;

open Polished_Types;

open Polished_Color_Readable;

describe("Polished_Color_Readable", () => {
  let onLight = RGB(RGB.fromPrimitives(10, 10, 10));
  let onDark = RGB(RGB.fromPrimitives(245, 245, 245));
  let bgDark = RGB(RGB.fromPrimitives(20, 20, 20));
  let bgMid = RGB(RGB.fromPrimitives(128, 128, 128));
  let bgLight = RGB(RGB.fromPrimitives(200, 200, 200));

  let bgCustom = RGB(RGB.fromPrimitives(0, 128, 128));

  test("should return onDark color because of dark background color", () => {
    expect(readable(bgDark, ~onLight, ~onDark, ())) |> toBe(onDark)
  });

  test("should return onLight color because of light background color", () => {
    expect(readable(bgLight, ~onLight, ~onDark, ())) |> toBe(onLight)
  });

  test(
    "should return onLight color for rgb(128, 128, 128) background color", () => {
    expect(readable(bgMid, ~onLight, ~onDark, ())) |> toBe(onLight)
  });

  test("should return onLight color for rgb(0, 128, 128) background color", () => {
    expect(readable(bgCustom, ~onLight, ~onDark, ())) |> toBe(onDark)
  });

  test(
    "should return defaultOnDark color because of dark background color and no other specified",
    () => {
    expect(readable(bgDark, ()))
    |> toBe(Polished_Color_Readable.defaultDarkReturnColor)
  });

  test(
    "should return defaultOnLight color because of light background color and no other specified",
    () => {
    expect(readable(bgLight, ()))
    |> toBe(Polished_Color_Readable.defaultLightReturnColor)
  });
});
