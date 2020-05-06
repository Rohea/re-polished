open Polished_Types;

let defaultLightReturnColor = RGB(RGB.fromPrimitives(0, 0, 0));
let defaultDarkReturnColor = RGB(RGB.fromPrimitives(255, 255, 255));

let readable =
    (
      color: color,
      ~onLight=defaultLightReturnColor,
      ~onDark=defaultDarkReturnColor,
      (),
    ) => {
  let isLightColor = Polished_Color_Utils.getLuminance(color) > 0.179;
  Js.log(isLightColor);
  let preferredReturnColor = isLightColor ? onLight : onDark;

  // TODO: Make `strict` the default behaviour in the next major release.
  // Without `strict`, this may return a color that does not meet WCAG AA.
  if (Polished_Color_Utils.getContrast(color, preferredReturnColor) >= 4.5) {
    preferredReturnColor;
  } else {
    isLightColor ? defaultLightReturnColor : defaultDarkReturnColor;
  };
};