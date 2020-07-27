open Polished_Types;
open Polished_Color_Utils;

module Impl = {
  let darkenHSLA = (hsla: HSLA.t, amount: Percent.t) => {
    let lightnessF = hsla->HSLA.lightness->Percent.asFloat;
    let newLightness =
      (lightnessF -. amount->Percent.asFloat)->floatInRange(0.0, 1.0);
    HSLA.make(
      ~hue=hsla->HSLA.hue,
      ~saturation=hsla->HSLA.saturation,
      ~lightness=Percent.make(newLightness),
      ~alpha=hsla->HSLA.alpha,
    );
  };
};

/**
 * Decrease the lightness of a color. Its range for the amount is between 0 to 1.
 *
 */

let darken = (color: color, amount: Percent.t) => {
  switch (color) {
  | HEX(hex) =>
    hex
    ->convertHEXtoRGB
    ->convertRGBtoRGBA
    ->convertRGBAtoHSLA
    ->Impl.darkenHSLA(amount)
    ->convertHSLAtoRGBA
    ->convertRGBAtoRGB
    ->convertRGBtoHEX
    ->HEX
  | RGB(rgb) =>
    rgb
    ->convertRGBtoRGBA
    ->convertRGBAtoHSLA
    ->Impl.darkenHSLA(amount)
    ->convertHSLAtoRGBA
    ->convertRGBAtoRGB
    ->RGB
  | RGBA(rgba) =>
    rgba->convertRGBAtoHSLA->Impl.darkenHSLA(amount)->convertHSLAtoRGBA->RGBA
  | HSL(hsl) =>
    hsl->convertHSLtoHSLA->Impl.darkenHSLA(amount)->convertHSLAtoHSL->HSL
  | HSLA(hsla) => hsla->Impl.darkenHSLA(amount)->HSLA
  };
};
