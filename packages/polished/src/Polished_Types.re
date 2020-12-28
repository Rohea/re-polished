let pi: float = 3.141592653589793;

module AbstractPrimitives = {
  module type Int8 = {
    type t;
    let make: int => t;
    let asInt: t => int;
    let toFloat: t => float;
    let fromHEX: (char, char) => t;
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
  let toFloat = t => float_of_int(t);
  let fromHEX = (c0: char, c1: char): t => {
    make(int_of_string("0x" ++ String.make(1, c0) ++ String.make(1, c1)));
  };
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

module AbstractColors = {
  module type RGB = {
    type t;
    let make: (~red: Int8.t, ~green: Int8.t, ~blue: Int8.t) => t;
    let fromPrimitives: (int, int, int) => t;
    let red: t => Int8.t;
    let green: t => Int8.t;
    let blue: t => Int8.t;
  };
  module type RGBA = {
    type t;
    let make:
      (~red: Int8.t, ~green: Int8.t, ~blue: Int8.t, ~alpha: Percent.t) => t;
    let fromPrimitives: (int, int, int, float) => t;
    let red: t => Int8.t;
    let green: t => Int8.t;
    let blue: t => Int8.t;
    let alpha: t => Percent.t;
  };
  module type HEX = {
    type t;
    let make: string => t;
    let asTuple: t => (char, char, char, char, char, char);
    let asString: t => string;
  };
  module type HSL = {
    type t;
    let make:
      (~hue: Degree.t, ~saturation: Percent.t, ~lightness: Percent.t) => t;
    let fromPrimitives: (float, float, float) => t;
    let hue: t => Degree.t;
    let saturation: t => Percent.t;
    let lightness: t => Percent.t;
  };
  module type HSLA = {
    type t;
    let make:
      (
        ~hue: Degree.t,
        ~saturation: Percent.t,
        ~lightness: Percent.t,
        ~alpha: Percent.t
      ) =>
      t;
    let fromPrimitives: (float, float, float, float) => t;
    let hue: t => Degree.t;
    let saturation: t => Percent.t;
    let lightness: t => Percent.t;
    let alpha: t => Percent.t;
  };
};

module RGB: AbstractColors.RGB = {
  type t = {
    red: Int8.t,
    green: Int8.t,
    blue: Int8.t,
  };
  let make = (~red, ~green, ~blue) => {
    {red, green, blue};
  };
  let fromPrimitives = (red, green, blue) => {
    let r = Int8.make(red);
    let g = Int8.make(green);
    let b = Int8.make(blue);
    {red: r, green: g, blue: b};
  };
  let red = t => t.red;
  let green = t => t.green;
  let blue = t => t.blue;
};

module RGBA: AbstractColors.RGBA = {
  type t = {
    red: Int8.t,
    green: Int8.t,
    blue: Int8.t,
    alpha: Percent.t,
  };
  let make = (~red, ~green, ~blue, ~alpha) => {
    {red, green, blue, alpha};
  };
  let fromPrimitives = (red, green, blue, alpha) => {
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

module HEX: AbstractColors.HEX = {
  type t = (char, char, char, char, char, char);

  let make = (value: string): t => {
    let str = [|'0', '0', '0', '0', '0', '0'|];
    String.mapi(
      (index, char) =>
        if (index < 6) {
          let validChar =
            switch (char) {
            | '0' => '0'
            | '1' => '1'
            | '2' => '2'
            | '3' => '3'
            | '4' => '4'
            | '5' => '5'
            | '6' => '6'
            | '7' => '7'
            | '8' => '8'
            | '9' => '9'
            | 'a'
            | 'A' => 'a'
            | 'b'
            | 'B' => 'b'
            | 'c'
            | 'C' => 'c'
            | 'd'
            | 'D' => 'd'
            | 'e'
            | 'E' => 'e'
            | 'f'
            | 'F' => 'f'
            | _ => ' '
            };
          str[index] = validChar;
          validChar;
        } else {
          ' ';
        },
      value,
    )
    |> ignore;
    let tuple = (str[0], str[1], str[2], str[3], str[4], str[5]);
    tuple;
  };
  let asTuple = (tuple: t) => tuple;

  let asString = (tuple: t): string =>
    switch (tuple) {
    | (c0, c1, c2, c3, c4, c5) =>
      String.make(1, c0)
      ++ String.make(1, c1)
      ++ String.make(1, c2)
      ++ String.make(1, c3)
      ++ String.make(1, c4)
      ++ String.make(1, c5)
    };
};

module HSL: AbstractColors.HSL = {
  type t = {
    hue: Degree.t,
    saturation: Percent.t,
    lightness: Percent.t,
  };
  let make = (~hue, ~saturation, ~lightness) => {
    {hue, saturation, lightness};
  };
  let fromPrimitives = (hue, saturation, lightness) => {
    let h = Degree.make(hue);
    let s = Percent.make(saturation);
    let l = Percent.make(lightness);
    {hue: h, saturation: s, lightness: l};
  };
  let hue = t => t.hue;
  let saturation = t => t.saturation;
  let lightness = t => t.lightness;
};

module HSLA: AbstractColors.HSLA = {
  type t = {
    hue: Degree.t,
    saturation: Percent.t,
    lightness: Percent.t,
    alpha: Percent.t,
  };
  let make = (~hue, ~saturation, ~lightness, ~alpha) => {
    {hue, saturation, lightness, alpha};
  };
  let fromPrimitives = (hue, saturation, lightness, alpha) => {
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
