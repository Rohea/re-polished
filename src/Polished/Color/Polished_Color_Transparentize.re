open Polished_Types;
open Polished_Color_Utils;

module Impl = {
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
    ->Impl.transparentizeRGBA(percentage)
    ->convertRGBAtoRGB
    ->convertRGBtoHEX
    ->HEX
  | RGB(rgb) =>
    rgb
    ->convertRGBtoRGBA
    ->Impl.transparentizeRGBA(percentage)
    ->convertRGBAtoRGB
    ->RGB
  | RGBA(rgba) => rgba->Impl.transparentizeRGBA(percentage)->RGBA
  | HSL(hsl) =>
    hsl
    ->convertHSLtoHSLA
    ->convertHSLAtoRGBA
    ->Impl.transparentizeRGBA(percentage)
    ->convertRGBAtoHSLA
    ->convertHSLAtoHSL
    ->HSL
  | HSLA(hsla) =>
    hsla
    ->convertHSLAtoRGBA
    ->Impl.transparentizeRGBA(percentage)
    ->convertRGBAtoHSLA
    ->HSLA
  };
};