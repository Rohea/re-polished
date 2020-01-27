module AbstractPrimitives = {
  module type Int8 = {
    type t;
    let make: int => t;
    let asInt: t => int;
  };
  module type Degree = {
    type t;
    let make: float => t;
    let asFloat: t => float;
  };
  module type Percent = {
    type t;
    let make: float => t;
    let asFloat: t => float;
  };
};
module Int8: AbstractPrimitives.Int8 = {
  type t = int; // 0 - 255
  let make = (value: int): t =>
    if (value > 255) {
      255;
    } else if (value < 0) {
      0;
    } else {
      value;
    };
  let asInt = t => t;
};

module Degree: AbstractPrimitives.Degree = {
  type t = float; // 0.0-360.0
  let make = (value: float): t =>
    if (value > 360.0) {
      360.0;
    } else if (value < 0.0) {
      0.0;
    } else {
      value;
    };
  let asFloat = t => t;
};

module Percent: AbstractPrimitives.Percent = {
  type t = float; // 0.0-1.0
  let make = (value: float): t =>
    if (value > 1.0) {
      1.0;
    } else if (value < 0.0) {
      0.0;
    } else {
      value;
    };
  let asFloat = t => t;
};

module Abstract = {
  module type RGB = {
    type t;
    let make: (~red: int, ~green: int, ~blue: int) => t;
    let red: t => Int8.t;
    let green: t => Int8.t;
    let blue: t => Int8.t;
  };
  module type RGBA = {
    type t;
    let make: (~red: int, ~green: int, ~blue: int, ~alpha: float) => t;
    let red: t => Int8.t;
    let green: t => Int8.t;
    let blue: t => Int8.t;
    let alpha: t => Percent.t;
  };
  module type HEX = {
    type t;
    let make: string => t;
    let asString: t => string;
  };
  module type HSL = {
    type t;
    let make: (~hue: float, ~saturation: float, ~lightness: float) => t;
    let hue: t => Degree.t;
    let saturation: t => Percent.t;
    let lightness: t => Percent.t;
  };
  module type HSLA = {
    type t;
    let make:
      (~hue: float, ~saturation: float, ~lightness: float, ~alpha: float) => t;
    let hue: t => Degree.t;
    let saturation: t => Percent.t;
    let lightness: t => Percent.t;
    let alpha: t => Percent.t;
  };
};

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
  type t = {
    red: Int8.t,
    green: Int8.t,
    blue: Int8.t,
  };
  let make = (~red: int, ~green: int, ~blue: int) => {
    let r = Int8.make(red);
    let g = Int8.make(green);
    let b = Int8.make(blue);
    {red: r, green: g, blue: b};
  };
  let red = t => t.red;
  let green = t => t.green;
  let blue = t => t.blue;
};

// let foo: RGB.t = Some(Types.RGB({red: 244, green: 234, blue: 123}));
// let bar: RGB.t = RGB.make(~red=243, ~green=234, ~blue=123);

module RGBA: Abstract.RGBA = {
  type t = {
    red: Int8.t,
    green: Int8.t,
    blue: Int8.t,
    alpha: Percent.t,
  };
  let make = (~red: int, ~green: int, ~blue: int, ~alpha: float) => {
    let r = Int8.make(red);
    let g = Int8.make(green);
    let b = Int8.make(blue);
    let a = Percent.make(alpha);
    {red: r, green: g, blue: b, alpha: a};
  };
  let red = t => t.red;
  let green = t => t.green;
  let blue = t => t.blue;
  let alpha = t => t.alpha;
};

module HEX: Abstract.HEX = {
  type t = string;
  let make = value => value;
  let asString = value => value;
};

module HSL = {
  type t = {
    hue: Degree.t,
    saturation: Percent.t,
    lightness: Percent.t,
  };
  let make = (~hue: float, ~saturation: float, ~lightness: float) => {
    let h = Degree.make(hue);
    let s = Percent.make(saturation);
    let l = Percent.make(lightness);
    {hue: h, saturation: s, lightness: l};
  };
  let hue = t => t.hue;
  let saturation = t => t.saturation;
  let lightness = t => t.lightness;
};

module HSLA = {
  type t = {
    hue: Degree.t,
    saturation: Percent.t,
    lightness: Percent.t,
    alpha: Percent.t,
  };
  let make =
      (~hue: float, ~saturation: float, ~lightness: float, ~alpha: float) => {
    let h = Degree.make(hue);
    let s = Percent.make(saturation);
    let l = Percent.make(lightness);
    let a = Percent.make(alpha);
    {hue: h, saturation: s, lightness: l, alpha: a};
  };
  let hue = t => t.hue;
  let saturation = t => t.saturation;
  let lightness = t => t.lightness;
  let alpha = t => t.alpha;
};

type color =
  | RGB(RGB.t)
  | RGBA(RGBA.t)
  | HEX(HEX.t)
  | HSL(HSL.t)
  | HSLA(HSLA.t);

/*

 module HSLA = {
   type t = Types.hsla;
 };
 */