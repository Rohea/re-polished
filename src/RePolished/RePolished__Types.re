module RGB = {
  type rgb = {
    red: int, // 0-255
    green: int, // 0-255
    blue: int // 0-255
  };
  type t = [ | `RGB(rgb)];
  let toString = rgb => {
    "ff0000";
  };
};

module RGBA = {
  type rgba = {
    red: int, // 0-255
    green: int, // 0-255
    blue: int, // 0-255
    alpha: float // 0.0-1.0
  };
  type t = [ | `RGBA(rgba)];
  let make = (red, green, blue, alpha): t => {
    let rgba: rgba = {red, green, blue, alpha};
    `RGBA(rgba);
  };
};

module HEX = {
  type t = [ | `HEX(char, char, char, char, char, char)];
  let fromString = (str: string): t => {
    `HEX(('f', 'f', '0', '0', '0', '0'));
  };
  let toString = (value: t): string => {
    "ff0000";
  };
};

module HSL = {
  type hsl = {
    hue: float, // degrees
    saturation: float,
    lightness: float,
  };
  type t = [ | `HSL(hsl)];
};

module HSLA = {
  type hsla = {
    hue: float, // degrees
    saturation: float,
    lightness: float,
    alpha: float,
  };
  type t = [ | `HSLA(hsla)];
};
module HSV = {
  type hsv = {
    hue: float,
    saturation: float,
    value: float,
  };
  type t = [ | `HSV(hsv)];
};
type color = [ RGB.t | RGBA.t | HEX.t | HSL.t | HSLA.t | HSV.t];