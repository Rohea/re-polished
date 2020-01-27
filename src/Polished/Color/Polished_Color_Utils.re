let convertHEXtoRGB = (tuple: Polished_Types.HEX.t): Polished_Types.RGB.t =>
  Polished_Types.(
    switch (tuple |> Polished_Types.HEX.asTuple) {
    | (c0, c1, c2, c3, c4, c5) =>
      let red = Int8.fromHEX(c0, c1);
      let green = Int8.fromHEX(c2, c3);
      let blue = Int8.fromHEX(c4, c5);
      RGB.make(~red, ~green, ~blue);
    }
  );