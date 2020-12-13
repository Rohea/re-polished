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

describe("PolishedCss_Color.Utils.cssToColor", () => {
  test("bs-css rgb to polished rgb", () => {
    expect(Utils.cssToColor(`rgb((0, 128, 255))))
    |> toEqual(Some(RGB(RGB.fromPrimitives(0, 128, 255))))
  });

  test("bs-css rgba to polished rgba", () => {
    expect(Utils.cssToColor(`rgba((0, 128, 255, 0.5))))
    |> toEqual(Some(RGBA(RGBA.fromPrimitives(0, 128, 255, 0.5))))
  });

  test("bs-css hex to polished hex", () => {
    expect(Utils.cssToColor(`hex("0080FF")))
    |> toEqual(Some(HEX(HEX.make("0080FF"))))
  });

  test("bs-css hsl to polished hsl", () => {
    expect(
      Utils.cssToColor(
        `hsl((`deg(210.0), `percent(100.0), `percent(50.0))),
      ),
    )
    |> toEqual(Some(HSL(HSL.fromPrimitives(210.0, 1.0, 0.5))))
  });

  test("bs-css hsla to polished hsla", () => {
    expect(
      Utils.cssToColor(
        `hsla((
          `deg(210.0),
          `percent(100.0),
          `percent(50.0),
          `percent(0.5),
        )),
      ),
    )
    |> toEqual(Some(HSLA(HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.5))))
  });

  test("bs-css transparent to polished rgba", () => {
    expect(Utils.cssToColor(`transparent))
    |> toEqual(Some(RGBA(RGBA.fromPrimitives(0, 0, 0, 0.0))))
  });
});

describe("PolishedCss_Color.Utils.colorToCss", () => {
  test("polished rgb to bs-css rgb", () => {
    expect(Utils.colorToCss(RGB(RGB.fromPrimitives(0, 128, 255))))
    |> toEqual(`rgb((0, 128, 255)))
  });

  test("polished rgba to bs-css rgba", () => {
    expect(Utils.colorToCss(RGBA(RGBA.fromPrimitives(0, 128, 255, 0.5))))
    |> toEqual(`rgba((0, 128, 255, 0.5)))
  });

  test("polished hex to bs-css hex", () => {
    expect(Utils.colorToCss(HEX(HEX.make("0080ff"))))
    |> toEqual(`hex("0080ff"))
  });

  test("polished hex to bs-css hex with decapitalization", () => {
    expect(Utils.colorToCss(HEX(HEX.make("AABBFF"))))
    |> toEqual(`hex("aabbff"))
  });

  test("polished hsl to bs-css hsl", () => {
    expect(Utils.colorToCss(HSL(HSL.fromPrimitives(210.0, 1.0, 0.5))))
    |> toEqual(`hsl((`deg(210.0), `percent(100.0), `percent(50.0))))
  });

  test("polished hsla to bs-css hsla", () => {
    expect(
      Utils.colorToCss(HSLA(HSLA.fromPrimitives(210.0, 1.0, 0.5, 0.5))),
    )
    |> toEqual(
         `hsla((
           `deg(210.0),
           `percent(100.0),
           `percent(50.0),
           `percent(0.5),
         )),
       )
  });
});

/**
 * These tests are just very simple because the functions usually use internal polished functions
 * that are tested in depth.
 */
describe("PolishedCss_Color.transparentize", () => {
  test("transparentize rgb", () => {
    expect(transparentize(`rgb((0, 128, 255)), 0.5))
    |> toEqual(`rgba((0, 128, 255, 0.5)))
  });

  test("transparentize rgba", () => {
    expect(transparentize(`rgba((0, 128, 255, 0.7)), 0.5))
    |> toEqual(`rgba((0, 128, 255, 0.2)))
  });
});

describe("PolishedCss_Color.readable", () => {
  let onLight = `rgb((10, 10, 10));
  let onDark = `rgb((245, 245, 245));

  test("should return onDark color because of dark background color", () => {
    expect(readable(`rgb((20, 20, 20)), ~onLight, ~onDark, ()))
    |> toEqual(onDark)
  });

  test("should return onLight color because of light background color", () => {
    expect(readable(`rgb((200, 200, 200)), ~onLight, ~onDark, ()))
    |> toEqual(onLight)
  });
});

describe("PolishedCss_Color.opacify", () => {
  test("opacify rgba", () => {
    expect(opacify(`rgba((0, 128, 255, 0.2)), 0.5))
    |> toEqual(`rgba((0, 128, 255, 0.7)))
  })
});

describe("PolishedCss_Color.darken", () => {
  test("darken rgb(0, 128, 255) by 0.3", () => {
    expect(darken(`rgb((0, 128, 255)), 0.3))
    |> toEqual(`rgb((0, 51, 102)))
  })
});

describe("PolishedCss_Color.desaturate", () => {
  test("desaturate rgb(0, 128, 255) by 0.3", () => {
    expect(desaturate(`rgb((0, 128, 255)), 0.3))
    |> toEqual(`rgb((38, 128, 217)))
  })
});

describe("PolishedCss_Color.invert", () => {
  test("invert rgb(101, 100, 205)", () => {
    expect(invert(`rgb((101, 100, 205)))) |> toEqual(`rgb((154, 155, 50)))
  })
});

describe("PolishedCss_Color.mix", () => {
  test("mix two rgb and rgba colors", () => {
    expect(mix(`rgb((0, 0, 0)), `rgba((255, 255, 255, 0.0)), 0.7))
    |> toEqual(`rgba((0, 0, 0, 0.7)))
  });

  test("mix two rgba colors", () => {
    expect(mix(`rgba((0, 255, 128, 0.5)), `rgba((128, 0, 255, 0.5)), 0.5))
    |> toEqual(`rgba((64, 127, 191, 0.5)))
  });
});

describe("PolishedCss_Color.shade", () => {
  test("shade rgb(0, 128, 255) by 0.3", () => {
    expect(shade(`rgb((0, 128, 255)), 0.3)) |> toEqual(`rgb((0, 89, 178)))
  })
});

describe("PolishedCss_Color.tint", () => {
  test("tint rgb(0, 128, 255) by 0.3", () => {
    expect(tint(`rgb((0, 128, 255)), 0.3))
    |> toEqual(`rgb((76, 166, 255)))
  })
});

describe("PolishedCss_Color.setAlpha", () => {
  test("setAlpha of rgb", () => {
    expect(setAlpha(`rgb((0, 128, 255)), 0.5))
    |> toEqual(`rgba((0, 128, 255, 0.5)))
  });

  test("setAlpha of rgba", () => {
    expect(setAlpha(`rgba((0, 128, 255, 0.7)), 0.5))
    |> toEqual(`rgba((0, 128, 255, 0.5)))
  });
});
