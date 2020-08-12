open Polished_Types;
open Polished_Color_Utils;

module Impl = {
  /** the *. 100.0 and /. 100.0 is here to prevent situations where for example 0.7 - 0.3 = 0.39999999999999997 */;
  let transparentizeAlphaValue = (alpha: Percent.t, percentage: Percent.t) => {
    Percent.make(
      floatInRange(
        (
          (alpha |> Percent.asFloat)
          *. 100.0
          -. (percentage |> Percent.asFloat)
          *. 100.0
        )
        /. 100.0,
        0.0,
        1.0,
      ),
    );
  };

  let transparentizeRGBA = (rgba: RGBA.t, percentage: Percent.t) => {
    let alpha = transparentizeAlphaValue(RGBA.alpha(rgba), percentage);

    RGBA.make(
      ~red=RGBA.red(rgba),
      ~green=RGBA.green(rgba),
      ~blue=RGBA.blue(rgba),
      ~alpha,
    );
  };

  let transparentizeHSLA = (hsla: HSLA.t, percentage: Percent.t) => {
    let alpha = transparentizeAlphaValue(HSLA.alpha(hsla), percentage);

    HSLA.make(
      ~hue=HSLA.hue(hsla),
      ~saturation=HSLA.saturation(hsla),
      ~lightness=HSLA.lightness(hsla),
      ~alpha,
    );
  };
};

/**
 * Decreases the opacity of a color. Its range for the amount is between 0 to 1.
 * If input is HSL or HSLA color, returns HSLA, otherwise returns RGBA color.
 */
let transparentize = (color: color, percentage: Percent.t): color => {
  switch (color) {
  | HEX(hex) =>
    hex
    ->convertHEXtoRGB
    ->convertRGBtoRGBA
    ->Impl.transparentizeRGBA(percentage)
    ->RGBA
  | RGB(rgb) =>
    rgb->convertRGBtoRGBA->Impl.transparentizeRGBA(percentage)->RGBA
  | RGBA(rgba) => rgba->Impl.transparentizeRGBA(percentage)->RGBA
  | HSL(hsl) =>
    hsl->convertHSLtoHSLA->Impl.transparentizeHSLA(percentage)->HSLA
  | HSLA(hsla) => hsla->Impl.transparentizeHSLA(percentage)->HSLA
  };
};
