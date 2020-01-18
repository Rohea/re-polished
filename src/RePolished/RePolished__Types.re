type rgb = {
  red: int, // 0-255
  green: int, // 0-255
  blue: int // 0-255
};
type rgba = {
  red: int, // 0-255
  green: int, // 0-255
  blue: int, // 0-255
  alpha: float // 0.0-1.0
};
type hex = {value: string};
type hsl = {
  hue: float, // degrees
  saturation: float,
  lightness: float,
};
type hsla = {
  hue: float, // degrees
  saturation: float,
  lightness: float,
  alpha: float,
};

type color =
  | RGB(rgb)
  | RGBA(rgba)
  | HEX(hex)
  | HSL(hsl)
  | HSLA(hsla);