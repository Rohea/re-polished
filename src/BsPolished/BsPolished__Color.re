module Utils = {
  let cssToColor = (cssColor: Css.Types.Color.t): RePolished.Types.color => {
    RePolished.Types.(
      switch (cssColor) {
      | `rgb(r, g, b) => RGB({red: r, green: g, blue: b})
      | `rgba(r, g, b, a) => RGBA({red: r, green: g, blue: b, alpha: a})
      | `hex(str) => HEX({value: str})
      | `hsl(h, s, l) =>
        let deg: float =
          switch (h) {
          | `grad(f) => f // WRONG!!!
          | `turn(f) => f // WRONG!!!
          | `deg(f) => f
          | `rad(f) => f // WRONG!!!
          };
        HSL({
          hue: deg,
          saturation:
            switch (s) {
            | `percent(f) => f
            },
          lightness:
            switch (l) {
            | `percent(f) => f
            },
        });
      | _ => RePolished.Types.RGBA({red: 0, green: 0, blue: 0, alpha: 1.0}) // TODO: REMOVE
      }
    );
  };

  let colorToCss = (color: RePolished.Types.color): Css.Types.Color.t => {
    RePolished.Types.(
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
  let color = Utils.cssToColor(cssColor);
  let tr = RePolished.Color.Transparentize.transparentize(percentage, color);
  let cssColor = Utils.colorToCss(tr);
  cssColor;
};