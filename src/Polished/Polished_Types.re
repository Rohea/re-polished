module Abstract = {
  module type RGB = {
    type t;
    let make: (~red: int, ~green: int, ~blue: int) => option(t);
  };
  module type RGBA = {
    type t;
    let make:
      (~red: int, ~green: int, ~blue: int, ~alpha: float) => option(t);
  };
  module type HEX = {
    type t;
    let make: string => option(t);
  };
};

module Int8 = {
  type t = int; // 0 - 255
  let make = (value: int): option(t) =>
    if (value > 255) {
      Js.log("Int8 value cannot be more than 255"); // TODO: remove BS dependency
      None;
    } else if (value < 0) {
      Js.log("Int8 value cannot be less than 0"); // TODO: remove BS dependency
      None;
    } else {
      Some(value);
    };
};

module Degree = {
  type t = float; // 0.0-360.0
  let make = (value: float): option(t) =>
    if (value > 360.0) {
      Js.log("Degree value cannot be more than 360.0 (float)"); // TODO: remove BS dependency
      None;
    } else if (value < 0.0) {
      Js.log("Degree value cannot be less than 0.0 (float)"); // TODO: remove BS dependency
      None;
    } else {
      Some(value);
    };
};

module Percent = {
  type t = float; // 0.0-1.0
  let make = (value: float): option(t) =>
    if (value > 1.0) {
      Js.log("Percent value cannot be more than 1.0 (float)"); // TODO: remove BS dependency
      None;
    } else if (value < 0.0) {
      Js.log("Percent value cannot be less than 0.0 (float)"); // TODO: remove BS dependency
      None;
    } else {
      Some(value);
    };
};

type rgb = {
  red: Int8.t,
  green: Int8.t,
  blue: Int8.t,
};
type rgba = {
  red: Int8.t,
  green: Int8.t,
  blue: Int8.t,
  alpha: Percent.t,
};
type hex = string;
/*
 type hsl = {
   hue: Degree.t,
   saturation: Percent.t,
   lightness: Percent.t,
 };
 type hsla = {
   hue: Degree.t,
   saturation: Percent.t,
   lightness: Percent.t,
   alpha: Percent.t,
 };
 */
module RGB: Abstract.RGB = {
  type t = rgb;
  let make = (~red: int, ~green: int, ~blue: int) => {
    let mr = Int8.make(red);
    let mg = Int8.make(green);
    let mb = Int8.make(blue);
    switch (mr, mg, mb) {
    | (Some(r), Some(g), Some(b)) => Some({red: r, green: g, blue: b})
    | _ => None
    };
  };
};

// let foo: RGB.t = Some(Types.RGB({red: 244, green: 234, blue: 123}));
// let bar: RGB.t = RGB.make(~red=243, ~green=234, ~blue=123);

module RGBA: Abstract.RGBA = {
  type t = rgba;
  let make = (~red: int, ~green: int, ~blue: int, ~alpha: float) => {
    let mr = Int8.make(red);
    let mg = Int8.make(green);
    let mb = Int8.make(blue);
    let ma = Percent.make(alpha);
    switch (mr, mg, mb, ma) {
    | (Some(r), Some(g), Some(b), Some(a)) =>
      Some({red: r, green: g, blue: b, alpha: a})
    | _ => None
    };
  };
};

module HEX: Abstract.HEX = {
  type t = hex;
  let make = value => {
    Some(value);
  };
};

type color =
  | RGB(RGB.t)
  | RGBA(RGBA.t)
  | HEX(HEX.t);

/*
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
 */