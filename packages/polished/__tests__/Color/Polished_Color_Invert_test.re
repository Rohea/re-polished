open Jest;
open Expect;
open Polished_Types;
open Polished_Color_Invert;

describe("Polished_Color_Invert.Impl.invertRGBA", () => {
  test("lighten hsla(210.0, 0.5, 0.0, 0.5) by 0.4", () => {
    expect(Impl.invertRGBA(RGBA.fromPrimitives(255, 255, 255, 1.0)))
    |> toEqual(RGBA.fromPrimitives(0, 0, 0, 1.0))
  });

  test("inverting twice should produce original value", () => {
    expect(
      RGBA.fromPrimitives(210, 5, 30, 0.4)->Impl.invertRGBA->Impl.invertRGBA,
    )
    |> toEqual(RGBA.fromPrimitives(210, 5, 30, 0.4))
  });

  describe("Polished_Color_Lighten.invert", () => {
    test("invert rgba(101,100,205,0.7)", () => {
      expect(invert(RGBA(RGBA.fromPrimitives(101, 100, 205, 0.7))))
      |> toEqual(RGBA(RGBA.fromPrimitives(154, 155, 50, 0.7)))
    });

    test("invert #CCCD64", () => {
      expect(invert(HEX(HEX.make("CCCD64"))))
      |> toEqual(HEX(HEX.make("33329b")))
    });
  });
});
