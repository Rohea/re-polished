module Int8 = {
  type t = int; // 0 - 255
  let make = (value: t): option(t) =>
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

module Deg = {
  type t = float; // 0.0-360.0
  let make = (value: t): option(t) =>
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
  let make = (value: t): option(t) =>
    if (value > 360.0) {
      Js.log("Percent value cannot be more than 1.0 (float)"); // TODO: remove BS dependency
      None;
    } else if (value < 0.0) {
      Js.log("Percent value cannot be less than 0.0 (float)"); // TODO: remove BS dependency
      None;
    } else {
      Some(value);
    };
};

module RGB = {
  type t = {
    red: Int8.t,
    green: Int8.t,
    blue: Int8.t,
  };
};

module RGBA = {
  type t = {
    red: Int8.t,
    green: Int8.t,
    blue: Int8.t,
    alpha: Percent.t,
  };
};

module HEX = {
  type t = {value: string};
};

module HSL = {
  type t = {
    hue: Deg.t,
    saturation: Percent.t,
    lightness: Percent.t,
  };
};

module HSLA = {
  type t = {
    hue: Deg.t,
    saturation: Percent.t,
    lightness: Percent.t,
    alpha: Percent.t,
  };
};

type color =
  | RGB(RGB.t)
  | RGBA(RGBA.t)
  | HEX(HEX.t)
  | HSL(HSL.t)
  | HSLA(HSLA.t);