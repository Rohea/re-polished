open Polished_Types;

let defaultLightReturnColor = RGB(RGB.fromPrimitives(0, 0, 0));
let defaultDarkReturnColor = RGB(RGB.fromPrimitives(255, 255, 255));

/**
 * Returns black or white (or optional light and dark return colors) for best
 * contrast depending on the luminosity of the given color.
 * If this test fails, the default return color (black or white) is returned in place of the
 * custom return color.
 *
 * Follows [W3C specs for readability](https://www.w3.org/TR/WCAG20-TECHS/G18.html)
 */
let readable =
    (
      color: color,
      ~onLight=defaultLightReturnColor,
      ~onDark=defaultDarkReturnColor,
      ~strict=false,
      (),
    ) => {
  let isLightColor = Polished_Color_Utils.getLuminance(color) > 0.179;
  let preferredReturnColor = isLightColor ? onLight : onDark;

  if (!strict || Polished_Color_Utils.getContrast(color, preferredReturnColor) >= 4.5) {
    preferredReturnColor;
  } else {
    isLightColor ? defaultLightReturnColor : defaultDarkReturnColor;
  };
};