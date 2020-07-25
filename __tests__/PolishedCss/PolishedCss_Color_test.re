open Jest;
open Expect;

open Polished_Types;

open PolishedCss_Color;

describe("PolishedCss_Color.Utils.cssAngleToDegree", () => {
  test("100 grad to 90 deg", () => {
    expect(Utils.cssAngleToDegree(`grad(100.0)))
    |> toBe(Degree.make(90.0))
  });

  test("0 grad to 0 deg", () => {
    expect(Utils.cssAngleToDegree(`grad(0.0))) |> toBe(Degree.make(0.0))
  });

  test("400 grad to 360 deg", () => {
    expect(Utils.cssAngleToDegree(`grad(400.0)))
    |> toBe(Degree.make(360.0))
  });

  test("0.5 turn to 180 deg", () => {
    expect(Utils.cssAngleToDegree(`turn(0.5))) |> toBe(Degree.make(180.0))
  });

  test("1 turn to 360 deg", () => {
    expect(Utils.cssAngleToDegree(`turn(1.0))) |> toBe(Degree.make(360.0))
  });

  test("0 turn to 0 deg", () => {
    expect(Utils.cssAngleToDegree(`turn(0.0))) |> toBe(Degree.make(0.0))
  });

  test("45 deg to 45 deg", () => {
    expect(Utils.cssAngleToDegree(`deg(45.0))) |> toBe(Degree.make(45.0))
  });

  test("0 deg to 0 deg", () => {
    expect(Utils.cssAngleToDegree(`deg(0.0))) |> toBe(Degree.make(0.0))
  });

  test("360 deg to 360 deg", () => {
    expect(Utils.cssAngleToDegree(`deg(360.0)))
    |> toBe(Degree.make(360.0))
  });

  test("3.141592654 rad to 179.9087 deg", () => {
    expect(Utils.cssAngleToDegree(`rad(3.141592654))->Degree.asFloat)
    |> toBeSoCloseTo(Degree.make(180.0)->Degree.asFloat, ~digits=4)
  });

  test("0.0 rad to 0 deg", () => {
    expect(Utils.cssAngleToDegree(`rad(0.0))) |> toBe(Degree.make(0.0))
  });

  test("6.283185415 rad to 360 deg", () => {
    expect(Utils.cssAngleToDegree(`rad(6.283185415)))
    |> toBe(Degree.make(360.0))
  });
});
