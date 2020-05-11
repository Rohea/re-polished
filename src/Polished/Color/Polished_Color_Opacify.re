open Polished_Types;
open Polished_Color_Utils;

module Impl = {
  let opacifyRGBA = (rgba: RGBA.t, amount: Percent.t) => {
    let alphaF = rgba->RGBA.alpha->Percent.asFloat;
    RGBA.make(
      ~red=rgba->RGBA.red,
      ~green=rgba->RGBA.green,
      ~blue=rgba->RGBA.blue,
      ~alpha=
        Percent.make(
          (alphaF *. 100.0 +. amount->Percent.asFloat *. 100.0) /. 100.0,
        ),
    );
  };
};
/**
 * Increases the opacity of a color.
 */
let opacify = (color: color, amount: Percent.t) => {
  switch (color) {
  | HEX(hex) =>
    hex
    ->convertHEXtoRGB
    ->convertRGBtoRGBA
    ->Impl.opacifyRGBA(amount)
    ->convertRGBAtoRGB
    ->convertRGBtoHEX
    ->HEX
  | RGB(rgb) =>
    rgb->convertRGBtoRGBA->Impl.opacifyRGBA(amount)->convertRGBAtoRGB->RGB
  | RGBA(rgba) => rgba->Impl.opacifyRGBA(amount)->RGBA
  | HSL(hsl) =>
    hsl
    ->convertHSLtoHSLA
    ->convertHSLAtoRGBA
    ->Impl.opacifyRGBA(amount)
    ->convertRGBAtoHSLA
    ->convertHSLAtoHSL
    ->HSL
  | HSLA(hsla) =>
    hsla->convertHSLAtoRGBA->Impl.opacifyRGBA(amount)->convertRGBAtoHSLA->HSLA
  };
};