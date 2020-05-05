open Polished_Types;

let positiveFloat = (x, y) => mod_float(mod_float(x, y) +. y, y);

let convertHEXtoRGB = (tuple: HEX.t): RGB.t =>
  switch (tuple |> HEX.asTuple) {
  | (c0, c1, c2, c3, c4, c5) =>
    let red = Int8.fromHEX(c0, c1);
    let green = Int8.fromHEX(c2, c3);
    let blue = Int8.fromHEX(c4, c5);
    RGB.make(~red, ~green, ~blue);
  };

let convertRGBAtoHSLA = (rgba: RGBA.t): HSLA.t => {
  let (red, green, blue, alpha) = (
    rgba->RGBA.red |> Int8.asInt,
    rgba->RGBA.green |> Int8.asInt,
    rgba->RGBA.blue |> Int8.asInt,
    rgba->RGBA.alpha |> Percent.asFloat,
  );
  let r = float_of_int(red) /. 255.;
  let g = float_of_int(green) /. 255.;
  let b = float_of_int(blue) /. 255.;
  let c_max = max(max(red, green), blue);
  let c_min = min(min(red, green), blue);
  let c = c_max - c_min;
  let c' = float_of_int(c) /. 255.;
  let hue' = c =>
    if (c == 0) {
      0.;
    } else if (c_max == red) {
      positiveFloat((g -. b) /. c', 6.);
    } else if (c_max == green) {
      (b -. r) /. c' +. 2.;
    } else {
      (r -. g) /. c' +. 4.;
    };
  let hue = 60. *. hue'(c);
  let lightness = float_of_int(c_max + c_min) /. (255. *. 2.);
  let saturation =
    if (c == 0) {
      0.;
    } else {
      c' /. (1. -. abs_float(2. *. lightness -. 1.));
    };
  HSLA.fromPrimitives(hue, saturation, lightness, alpha);
};

let convertHSLAtoRGBA = (hsla: HSLA.t): RGBA.t => {
  let (h, s, l, a) = (
    hsla->HSLA.hue |> Degree.asFloat,
    hsla->HSLA.saturation |> Percent.asFloat,
    hsla->HSLA.lightness |> Percent.asFloat,
    hsla->HSLA.alpha |> Percent.asFloat,
  );
  let clip_hue = x =>
    if (360.0 == x) {
      x;
    } else {
      positiveFloat(x, 360.0);
    };
  let norm_hue = clip_hue(h) /. 60.;
  let chr = (1. -. abs_float(2. *. l -. 1.)) *. s;
  let m = l -. chr /. 2.;
  let x = chr *. (1. -. abs_float(mod_float(norm_hue, 2.) -. 1.));
  let make = (r, g, b) => {
    let red = int_of_float(255.0 *. r);
    let green = int_of_float(255.0 *. g);
    let blue = int_of_float(255.0 *. b);
    RGBA.fromPrimitives(red, green, blue, a);
  };
  if (norm_hue < 0.) {
    make(0., 0., 0.);
  } else if (norm_hue < 1.) {
    make(chr, x, 0.);
  } else if (norm_hue < 2.) {
    make(x, chr, 0.);
  } else if (norm_hue < 3.) {
    make(0., chr, x);
  } else if (norm_hue < 4.) {
    make(0., x, chr);
  } else if (norm_hue < 5.) {
    make(x, 0., chr);
  } else if (norm_hue < 6.) {
    make(chr, 0., x);
  } else {
    make(0., 0., 0.);
  };
};

let convertRGBAtoRGB = (rgba: RGBA.t): RGB.t => {
  RGB.make(
    ~red=rgba->RGBA.red,
    ~green=rgba->RGBA.green,
    ~blue=rgba->RGBA.blue,
  );
};

let convertHSLtoHSLA = (hsl: HSL.t): HSLA.t => {
  HSLA.make(
    ~hue=hsl->HSL.hue,
    ~saturation=hsl->HSL.saturation,
    ~lightness=hsl->HSL.lightness,
    ~alpha=Percent.make(1.0),
  );
};

let convertColorToRGB = (color: color) =>
  switch (color) {
  | RGB(rgb) => rgb
  | RGBA(rgba) => convertRGBAtoRGB(rgba)
  | HEX(hex) => convertHEXtoRGB(hex)
  | HSLA(hsla) => hsla->convertHSLAtoRGBA->convertRGBAtoRGB
  | HSL(hsl) => hsl->convertHSLtoHSLA->convertHSLAtoRGBA->convertRGBAtoRGB
  };

let getLuminance = (color: color): float => {
  let rgb = convertColorToRGB(color);
  let (r, g, b) = (
    rgb->RGB.red |> Int8.toFloat,
    rgb->RGB.green |> Int8.toFloat,
    rgb->RGB.blue |> Int8.toFloat,
  );
  let (rc, gc, bc) = (r /. 255.0, b /. 255.0, b /. 255.0);
  let convert = c =>
    if (c <= 0.03928) {
      c /. 12.92;
    } else {
      (c +. 0.055) /. 1.055 ** 2.4;
    };
  let r2 = convert(rc);
  let g2 = convert(gc);
  let b2 = convert(bc);
  0.2126 *. r2 +. 0.7152 *. g2 +. 0.0722 *. b2;
};

let getContrast = (color1: color, color2: color): float => {
  let luminance1 = getLuminance(color1);
  let luminance2 = getLuminance(color2);
  luminance1 > luminance2
    ? (luminance1 +. 0.05) /. (luminance2 +. 0.05)
    : (luminance2 +. 0.05) /. (luminance1 +. 0.05);
};