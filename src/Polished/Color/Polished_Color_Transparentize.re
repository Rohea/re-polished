open Polished_Types;
open Polished_Color_Utils;

module Utils = {
  let transparentizeRGBA = (rgba: RGBA.t, percentage: Percent.t) =>
    RGBA.make(
      ~red=RGBA.red(rgba),
      ~green=RGBA.green(rgba),
      ~blue=RGBA.blue(rgba),
      ~alpha=
        Percent.make(
          (percentage |> Percent.asFloat)
          *. (RGBA.alpha(rgba) |> Percent.asFloat),
        ),
    );
};

let transparentize = (color: color, percentage: Percent.t): color => {
  switch (color) {
  | HEX(hex) =>
    hex
    ->convertHEXtoRGB
    ->convertRGBtoRGBA
    ->Utils.transparentizeRGBA(percentage)
    ->convertRGBAtoRGB
    ->convertRGBtoHEX
    ->HEX
  | RGB(rgb) =>
    rgb
    ->convertRGBtoRGBA
    ->Utils.transparentizeRGBA(percentage)
    ->convertRGBAtoRGB
    ->RGB
  | RGBA(rgba) => rgba->Utils.transparentizeRGBA(percentage)->RGBA
  | HSL(hsl) =>
    hsl
    ->convertHSLtoHSLA
    ->convertHSLAtoRGBA
    ->Utils.transparentizeRGBA(percentage)
    ->convertRGBAtoHSLA
    ->convertHSLAtoHSL
    ->HSL
  | HSLA(hsla) =>
    hsla
    ->convertHSLAtoRGBA
    ->Utils.transparentizeRGBA(percentage)
    ->convertRGBAtoHSLA
    ->HSLA
  };
};