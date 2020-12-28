open Polished_Types;
open Polished_Color_Utils;

module Impl = {
  let setAlphaForRGBA = (rgba: RGBA.t, percentage: Percent.t) => {
    RGBA.make(
      ~red=RGBA.red(rgba),
      ~green=RGBA.green(rgba),
      ~blue=RGBA.blue(rgba),
      ~alpha=percentage,
    );
  };

  let setAlphaForHSLA = (hsla: HSLA.t, percentage: Percent.t) => {
    HSLA.make(
      ~hue=HSLA.hue(hsla),
      ~saturation=HSLA.saturation(hsla),
      ~lightness=HSLA.lightness(hsla),
      ~alpha=percentage,
    );
  };
};

/**
 * Set alpha value of a color. Its range for the amount is between 0 to 1.
 * If input is HSL or HSLA color, returns HSLA, otherwise returns RGBA color.
 */
let setAlpha = (color: color, percentage: Percent.t): color => {
  switch (color) {
  | HEX(hex) =>
    hex
    ->convertHEXtoRGB
    ->convertRGBtoRGBA
    ->Impl.setAlphaForRGBA(percentage)
    ->RGBA
  | RGB(rgb) => rgb->convertRGBtoRGBA->Impl.setAlphaForRGBA(percentage)->RGBA
  | RGBA(rgba) => rgba->Impl.setAlphaForRGBA(percentage)->RGBA
  | HSL(hsl) => hsl->convertHSLtoHSLA->Impl.setAlphaForHSLA(percentage)->HSLA
  | HSLA(hsla) => hsla->Impl.setAlphaForHSLA(percentage)->HSLA
  };
};
