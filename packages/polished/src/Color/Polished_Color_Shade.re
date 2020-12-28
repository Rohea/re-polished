open Polished_Types;

/**
 * Shades a color by mixing it with black. `shade` can produce
 * hue shifts, where as `darken` manipulates the luminance channel and therefore
 * doesn't produce hue shifts.
 *
 * NOTE: This implementation deviate from original polished implementation, where shade
 * would alter the alpha value of transparent colors.
 * In this implementation the alpha value is preserved
 */
module Impl = {
  let shade = (color: color, amount: Percent.t): color => {
    Polished_Color_Mix.mix(RGB(RGB.fromPrimitives(0, 0, 0)), color, amount);
  };

  let shadeRGBA = (rgba: RGBA.t, amount: Percent.t): color => {
    let alpha = RGBA.alpha(rgba);
    let rgb = Polished_Color_Utils.convertRGBAtoRGB(rgba);

    let shadedRgb = shade(RGB(rgb), amount);
    Polished_Color_Transparentize.transparentize(shadedRgb, alpha);
  };

  let shadeHSLA = (hsla: HSLA.t, amount: Percent.t): color => {
    let alpha = HSLA.alpha(hsla);
    let hsl = Polished_Color_Utils.convertHSLAtoHSL(hsla);

    let shadedHsl = shade(HSL(hsl), amount);
    Polished_Color_Transparentize.transparentize(shadedHsl, alpha);
  };
};

let shade = (color: color, amount: Percent.t) => {
  switch (color) {
  | RGB(_)
  | HEX(_)
  | HSL(_) => Impl.shade(color, amount)
  | RGBA(rgbaColor) => Impl.shadeRGBA(rgbaColor, amount)
  | HSLA(hslaColor) => Impl.shadeHSLA(hslaColor, amount)
  };
};
