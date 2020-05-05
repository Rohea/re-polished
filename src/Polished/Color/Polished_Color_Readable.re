
open Polished_Types;

let defaultLightReturnColor = HEX(HEX.make("000000"));
let defaultDarkReturnColor = HEX(HEX.make("ffffff"));

let readable = (
  color: color,
  ~light=defaultLightReturnColor,
  ~dark=defaultDarkReturnColor,
  ()
) => {
  let isLightColor = Polished_Color_Utils.getLuminance(color) > 0.179
  Js.log(isLightColor);
  let preferredReturnColor = isLightColor ? light : dark

  // TODO: Make `strict` the default behaviour in the next major release.
  // Without `strict`, this may return a color that does not meet WCAG AA.
  if (Polished_Color_Utils.getContrast(color, preferredReturnColor) >= 4.5) {
    preferredReturnColor
  } else {
    isLightColor ? defaultLightReturnColor : defaultDarkReturnColor
  }
}
