open Jest;
open Expect;
open Polished_Types;
open Polished_Color_Transparentize;

describe("transparentize", () => {
  test("rgba(0,0,0) -> 000000", () => {
    let rgba = RGBA.fromPrimitives(0, 0, 0, 1.0);
    let amount = Percent.make(0.4);
    expect(
      rgba->Impl.transparentizeRGBA(amount)->RGBA.alpha->Percent.asFloat,
    )
    |> toBe(0.4);
  })
});