let cssToRgba = (cssColor: Css.Types.Color.t): RePolished.Types.RGBA.t => {
  switch (cssColor) {
  | `hex(str) =>
    let hex = RePolished.Types.HEX.fromString(str);
    RePolished.Types.RGBA.make(0, 0, 0, 1.0);
  | `rgba(r, g, b, a) => RePolished.Types.RGBA.make(r, g, b, a)
  | _ => RePolished.Types.RGBA.make(0, 0, 0, 1.0) // TODO: REMOVE
  };
};

let transparentize =
    (percentage: float, cssColor: Css.Types.Color.t): Css.Types.Color.t => {
  let rgba = cssToRgba(cssColor);
  RePolished.Color.Transparentize.transparentize(percentage, rgba);
};