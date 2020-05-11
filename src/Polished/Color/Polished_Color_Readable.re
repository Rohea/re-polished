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
  let preferredReturnColor = isLightColor ? onLight : onDark;

  if (Polished_Color_Utils.getContrast(color, preferredReturnColor) >= 4.5) {
    preferredReturnColor;
  } else {
    isLightColor ? defaultLightReturnColor : defaultDarkReturnColor;
  };
};