module Types = RePolished__Types;

module RGB = {
  type t = Types.rgb;
  let make = (~red: int, ~green: int, ~blue: int): option(Types.color) => {
    let mr = Types.Int8.make(red);
    let mg = Types.Int8.make(green);
    let mb = Types.Int8.make(blue);
    switch (mr, mg, mb) {
    | (Some(r), Some(g), Some(b)) =>
      Some(Types.RGB({red: r, green: g, blue: b}))
    | _ => None
    };
  };
};

module RGBA = {
  type t = Types.rgba;
  let make =
      (~red: int, ~green: int, ~blue: int, ~alpha: float)
      : option(Types.color) => {
    let mr = Types.Int8.make(red);
    let mg = Types.Int8.make(green);
    let mb = Types.Int8.make(blue);
    let ma = Types.Percent.make(alpha);
    switch (mr, mg, mb, ma) {
    | (Some(r), Some(g), Some(b), Some(a)) =>
      Some(Types.RGBA({red: r, green: g, blue: b, alpha: a}))
    | _ => None
    };
  };
};

module HEX = {
  type t = Types.hex;
  let make = (~value: string): option(Types.color) => {
    Some(Types.HEX({value: value}));
  };
};

module HSL = {
  type t = Types.hsl;
  let make = (~hue: float, ~saturation: float, ~lightness: float) => {
    let mh = Types.Degree.make(hue);
    let ms = Types.Percent.make(saturation);
    let ml = Types.Percent.make(lightness);
    switch (mh, ms, ml) {
    | (Some(h), Some(s), Some(l)) =>
      Some(Types.HSL({hue: h, saturation: s, lightness: l}))
    | _ => None
    };
  };
};

module HSLA = {
  type t = Types.hsla;
};

// Modules
module Color = RePolished__Color;