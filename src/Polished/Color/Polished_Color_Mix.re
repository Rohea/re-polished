open Polished_Types;
open Polished_Color_Utils;

/**
 * Returns [color] and [baseColor], mixed together and weighted by [weight]
 */
let mix = (color: color, baseColor: color, weight: Percent.t): color => {
  let colorRgba = convertColorToRGBA(color);
  let baseColorRgba = convertColorToRGBA(baseColor);

  /** The formula is copied from the original Sass implementation:
   * https://github.com/sass/dart-sass/blob/master/lib/src/functions/color.dart
   * This algorithm factors in both the user-provided weight (w) and the
   * difference between the alpha values of the two colors (a) to decide how
   * to perform the weighted average of the two RGB values.
   *
   * It works by first normalizing both parameters to be within [-1, 1], where
   * 1 indicates "only use color1", -1 indicates "only use color2", and all
   * values in between indicated a proportionately weighted average.
   *
   * Once we have the normalized variables w and a, we apply the formula
   * (w + a)/(1 + w*a) to get the combined weight (in [-1, 1]) of color1. This
   * formula has two especially nice properties:
   *
   *
   * When either w or a are -1 or 1, the combined weight is also that
   *     number (cases where w * a == -1 are undefined, and handled as a
   *     special case).
   *
   * When a is 0, the combined weight is w, and vice versa.
   *
   * Finally, the weight of color1 is renormalized to be within [0, 1] and the
   * weight of color2 is given by 1 minus the weight of color1
   */
  let normalizedWeight = Percent.asFloat(weight) *. 2.0 -. 1.0;
  let alphaDistance =
    Percent.asFloat(RGBA.alpha(colorRgba))
    -. Percent.asFloat(RGBA.alpha(baseColorRgba));

  let combinedWeight =
    normalizedWeight *. alphaDistance == (-1.0)
      ? normalizedWeight
      : (normalizedWeight +. alphaDistance)
        /. (1.0 +. normalizedWeight *. alphaDistance);

  let weight1 = (combinedWeight +. 1.0) /. 2.0;
  let weight2 = 1.0 -. weight1;

  let red =
    int_of_float(
      floor(
        Int8.toFloat(RGBA.red(colorRgba))
        *. weight1
        +. Int8.toFloat(RGBA.red(baseColorRgba))
        *. weight2,
      ),
    );
  let green =
    int_of_float(
      floor(
        Int8.toFloat(RGBA.green(colorRgba))
        *. weight1
        +. Int8.toFloat(RGBA.green(baseColorRgba))
        *. weight2,
      ),
    );
  let blue =
    int_of_float(
      floor(
        Int8.toFloat(RGBA.blue(colorRgba))
        *. weight1
        +. Int8.toFloat(RGBA.blue(baseColorRgba))
        *. weight2,
      ),
    );
  let alpha =
    Percent.asFloat(RGBA.alpha(colorRgba))
    *. Percent.asFloat(weight)
    +. Percent.asFloat(RGBA.alpha(baseColorRgba))
    *. (1.0 -. Percent.asFloat(weight));

  switch (color, baseColor) {
  | (RGB(_) | HEX(_) | HSL(_), RGB(_)) =>
    RGB(RGB.fromPrimitives(red, green, blue))
  | (RGB(_) | HEX(_) | HSL(_), HEX(_)) =>
    HEX(convertRGBtoHEX(RGB.fromPrimitives(red, green, blue)))
  | (RGB(_) | HEX(_) | HSL(_), HSL(_)) =>
    HSL(convertRGBtoHSL(RGB.fromPrimitives(red, green, blue)))
  | (_, RGBA(_))
  | (RGBA(_), RGB(_) | HEX(_) | HSL(_)) =>
    RGBA(RGBA.fromPrimitives(red, green, blue, alpha))
  | (_, HSLA(_))
  | (HSLA(_), RGB(_) | HEX(_) | HSL(_)) =>
    HSLA(convertRGBAtoHSLA(RGBA.fromPrimitives(red, green, blue, alpha)))
  };
};
