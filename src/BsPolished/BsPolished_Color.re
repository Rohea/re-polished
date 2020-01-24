module Utils = {
  let cssToColor =
      (cssColor: Css.Types.Color.t): option(Polished.Types.color) => {
    Polished.Types.(
      switch (cssColor) {
      | `rgb(r, g, b) =>
        switch (RGB.make(~red=r, ~green=g, ~blue=b)) {
        | Some(rgb) => Polished.Types.RGB(rgb)
        | None => None
        }
      | `rgba(r, g, b, a) => RGBA.make(~red=r, ~green=g, ~blue=b, ~alpha=a)
      | `hex(str) => HEX.make(~value=str)
      | `hsl(h, s, l) =>
        let deg: float =
          switch (h) {
          | `grad(f) => f // WRONG!!!
          | `turn(f) => f // WRONG!!!
          | `deg(f) => f
          | `rad(f) => f // WRONG!!!
          };
        HSL.make(
          ~hue=deg,
          ~saturation=
            switch (s) {
            | `percent(f) => f
            },
          ~lightness=
            switch (l) {
            | `percent(f) => f
            },
        );
      | _ => None
      }
    );
  };

  let colorToCss = (color: Polished.Types.color): Css.Types.Color.t => {
    Polished.Types.(
      switch (color) {
      | RGB(rgb) => Css.rgb(rgb.red, rgb.green, rgb.blue)
      | RGBA(rgba) => Css.rgba(rgba.red, rgba.green, rgba.blue, rgba.alpha)
      | HEX(hex) => Css.hex(hex.value)
      | HSL(hsl) =>
        Css.hsl(Css.Types.Angle.deg(hsl.hue), hsl.saturation, hsl.lightness)
      | HSLA(hsla) =>
        Css.hsla(
          Css.Types.Angle.deg(hsla.hue),
          hsla.saturation,
          hsla.lightness,
          `percent(hsla.alpha),
        )
      }
    );
  };
};

let transparentize =
    (percentage: float, cssColor: Css.Types.Color.t): Css.Types.Color.t => {
  let maybeColor = Utils.cssToColor(cssColor);
  let maybePercent = Polished.Types.Percent.make(percentage);
  switch (maybePercent, maybeColor) {
  | (Some(p), Some(c)) =>
    let tr = Polished.Color.Transparentize.transparentize(p, c);
    let newColor = Utils.colorToCss(tr);
    newColor;
  | _ =>
    Js.log(
      "Transparentize failed. Given percentage or css color was invalid",
    );
    cssColor;
  };
};