open Polished_Types;
open Polished_Color_Utils;

module Impl = {
  /** the *. 100.0 and /. 100.0 is here to prevent situations where for example 0.7 - 0.3 = 0.39999999999999997 */;
  let opacifyAlphaValue = (alpha: Percent.t, amount: Percent.t) => {
    Percent.make(
      floatInRange(
        (alpha->Percent.asFloat *. 100.0 +. amount->Percent.asFloat *. 100.0)
        /. 100.0,
        0.0,
        1.0,
      ),
    );
  };

  let opacifyRGBA = (rgba: RGBA.t, amount: Percent.t) => {
    let alpha = opacifyAlphaValue(RGBA.alpha(rgba), amount);

    RGBA.make(
      ~red=rgba->RGBA.red,
      ~green=rgba->RGBA.green,
      ~blue=rgba->RGBA.blue,
      ~alpha,
    );
  };

  let opacifyHSLA = (hsla: HSLA.t, amount: Percent.t) => {
    let alpha = opacifyAlphaValue(HSLA.alpha(hsla), amount);

    HSLA.make(
      ~hue=hsla->HSLA.hue,
      ~saturation=hsla->HSLA.saturation,
      ~lightness=hsla->HSLA.lightness,
      ~alpha,
    );
  };
};

/**
 * Increase the opacity of a color. Its range for the amount is between 0 to 1.
 * If input is HSL or HSLA color, returns HSLA, otherwise returns RGBA color.
 */
let opacify = (color: color, amount: Percent.t) => {
  switch (color) {
  | HEX(hex) =>
    hex->convertHEXtoRGB->convertRGBtoRGBA->Impl.opacifyRGBA(amount)->RGBA
  | RGB(rgb) => rgb->convertRGBtoRGBA->Impl.opacifyRGBA(amount)->RGBA
  | RGBA(rgba) => rgba->Impl.opacifyRGBA(amount)->RGBA
  | HSL(hsl) => hsl->convertHSLtoHSLA->Impl.opacifyHSLA(amount)->HSLA
  | HSLA(hsla) => hsla->Impl.opacifyHSLA(amount)->HSLA
  };
};
