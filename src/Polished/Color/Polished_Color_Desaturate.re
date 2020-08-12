open Polished_Types;
open Polished_Color_Utils;

module Impl = {
  let desaturateHSLA = (hsla: HSLA.t, amount: Percent.t) => {
    let saturationF = hsla->HSLA.saturation->Percent.asFloat;
    let newSaturation =
      (saturationF -. amount->Percent.asFloat)->floatInRange(0.0, 1.0);
    HSLA.make(
      ~hue=hsla->HSLA.hue,
      ~saturation=Percent.make(newSaturation),
      ~lightness=hsla->HSLA.lightness,
      ~alpha=hsla->HSLA.alpha,
    );
  };
};

/**
 * Decreases the intensity (saturation) of a color. Its range is between 0 to 1.
 */
let desaturate = (color: color, amount: Percent.t): color => {
  switch (color) {
  | HEX(hex) =>
    hex
    ->convertHEXtoRGB
    ->convertRGBtoRGBA
    ->convertRGBAtoHSLA
    ->Impl.desaturateHSLA(amount)
    ->convertHSLAtoRGBA
    ->convertRGBAtoRGB
    ->convertRGBtoHEX
    ->HEX
  | RGB(rgb) =>
    rgb
    ->convertRGBtoRGBA
    ->convertRGBAtoHSLA
    ->Impl.desaturateHSLA(amount)
    ->convertHSLAtoRGBA
    ->convertRGBAtoRGB
    ->RGB
  | RGBA(rgba) =>
    rgba
    ->convertRGBAtoHSLA
    ->Impl.desaturateHSLA(amount)
    ->convertHSLAtoRGBA
    ->RGBA
  | HSL(hsl) =>
    hsl->convertHSLtoHSLA->Impl.desaturateHSLA(amount)->convertHSLAtoHSL->HSL
  | HSLA(hsla) => hsla->Impl.desaturateHSLA(amount)->HSLA
  };
};
