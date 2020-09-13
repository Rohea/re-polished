open Polished_Types;
open Polished_Color_Utils;

module Impl = {
  let invertRGBA = (rgba: RGBA.t) => {
    RGBA.fromPrimitives(
      255 - rgba->RGBA.red->Int8.asInt,
      255 - rgba->RGBA.green->Int8.asInt,
      255 - rgba->RGBA.blue->Int8.asInt,
      rgba->RGBA.alpha->Percent.asFloat,
    );
  };
};

/**
 * Invert color.
 */
let invert = (color: color) => {
  switch (color) {
  | HEX(hex) =>
    hex
    ->convertHEXtoRGB
    ->convertRGBtoRGBA
    ->Impl.invertRGBA
    ->convertRGBAtoRGB
    ->convertRGBtoHEX
    ->HEX
  | RGB(rgb) => rgb->convertRGBtoRGBA->Impl.invertRGBA->convertRGBAtoRGB->RGB
  | RGBA(rgba) => rgba->Impl.invertRGBA->RGBA
  | HSL(hsl) =>
    hsl
    ->convertHSLtoHSLA
    ->convertHSLAtoRGBA
    ->Impl.invertRGBA
    ->convertRGBAtoHSLA
    ->convertHSLAtoHSL
    ->HSL
  | HSLA(hsla) =>
    hsla->convertHSLAtoRGBA->Impl.invertRGBA->convertRGBAtoHSLA->HSLA
  };
};
