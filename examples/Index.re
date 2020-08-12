module Transparentize = {
  module Styles = {
    open Css;
    let getRedBox = () => style([backgroundColor(rgba(255, 0, 0, 1.0))]);
    let getRedBoxTransparentize = () =>
      style([
        backgroundColor(
          rgba(255, 0, 0, 1.0)->PolishedCss.transparentize(0.5),
        ),
      ]);
  };

  [@react.component]
  let make = () => {
    <>
      <h1> {React.string("Transparentize")} </h1>
      <div className={Styles.getRedBox()}>
        {React.string("RedBox RGBA")}
      </div>
      <div className={Styles.getRedBoxTransparentize()}>
        {React.string("RedBox RGBA transparentize")}
      </div>
    </>;
  };
};

let rgbToString = (r: int, g: int, b: int) => {
  "("
  ++ string_of_int(r)
  ++ ","
  ++ string_of_int(g)
  ++ ","
  ++ string_of_int(b)
  ++ ")";
};

module Readable = {
  module Styles = {
    open Css;
    let numCols = 4.0;
    let getColumn1 = (rgbVal: int) =>
      style([
        width(pct(100.0 /. numCols)),
        float(`left),
        backgroundColor(`rgb((rgbVal, rgbVal, rgbVal))),
        color(`rgb((rgbVal, rgbVal, rgbVal))->PolishedCss.readable()),
      ]);
    let getColumn2 = (rgbVal: int) => {
      let darkColor = Css.hex("181818");
      let lightColor = Css.hex("999999");
      let bgColor = Css.rgb(rgbVal, rgbVal, rgbVal);
      style([
        width(pct(100.0 /. numCols)),
        float(`left),
        backgroundColor(bgColor),
        color(
          bgColor->PolishedCss.readable(
            ~onLight=darkColor,
            ~onDark=lightColor,
            (),
          ),
        ),
      ]);
    };
    let getColumn3 = (rgbVal: int) => {
      let darkColor = Css.hex("770000");
      let lightColor = Css.hex("ffffff");
      let bgColor = Css.rgb(225, rgbVal - 30, rgbVal - 30);
      style([
        width(pct(100.0 /. numCols)),
        float(`left),
        backgroundColor(bgColor),
        color(
          bgColor->PolishedCss.readable(
            ~onLight=darkColor,
            ~onDark=lightColor,
            (),
          ),
        ),
      ]);
    };
    let getColumn4 = (rgbVal: int) => {
      let darkColor = Css.hsl(deg(112.0), 100.0, 10.0);
      let lightColor = Css.hsl(deg(112.0), 1.0, 0.9);
      let bgColor = Css.rgb(rgbVal, rgbVal, rgbVal);
      style([
        width(pct(100.0 /. numCols)),
        float(`left),
        backgroundColor(bgColor),
        color(
          bgColor->PolishedCss.readable(
            ~onLight=darkColor,
            ~onDark=lightColor,
            (),
          ),
        ),
      ]);
    };
  };
  [@react.component]
  let make = () => {
    let arr = Belt.Array.make(52, ());
    let items: array(React.element) =
      arr->Belt.Array.mapWithIndex((index, _item) => {
        let rgbVal = index * 5;
        <div key={string_of_int(index)}>
          <div className={Styles.getColumn1(rgbVal)}>
            {React.string(
               "Default on " ++ rgbToString(rgbVal, rgbVal, rgbVal),
             )}
          </div>
          <div className={Styles.getColumn2(rgbVal)}>
            {React.string("Darks on " ++ rgbToString(rgbVal, rgbVal, rgbVal))}
          </div>
          <div className={Styles.getColumn3(rgbVal)}>
            {React.string("Reds on something")}
          </div>
          <div className={Styles.getColumn4(rgbVal)}>
            {React.string("HSL on something")}
          </div>
        </div>;
      });
    <> <h1> {React.string("Readable")} </h1> items->React.array </>;
  };
};

module Main = {
  [@react.component]
  let make = () => {
    <> <Transparentize /> <Readable /> </>;
  };
};

ReactDOMRe.renderToElementWithId(<Main />, "app");
