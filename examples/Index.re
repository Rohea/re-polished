module Transparentize = {
  module Styles = {
    open Css;
    let getRedBox = () => style([backgroundColor(rgba(255, 0, 0, 1.0))]);
    let getRedBoxTransparentize = () =>
      style([
        backgroundColor(
          rgba(255, 0, 0, 1.0)->PolishedCss.Color.transparentize(0.5),
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

module Readable = {
  module Styles = {
    open Css;
    let numCols = 2.0;
    let getColumn1 = (rgbVal: int) =>
      style([
        width(pct(100.0 /. numCols)),
        float(`left),
        backgroundColor(`rgb((rgbVal, rgbVal, rgbVal))),
        color(`rgb((rgbVal, rgbVal, rgbVal))->PolishedCss.Color.readable()),
      ]);
    let getColumn2 = (rgbVal: int) => {
      let darkColor = Css.hex("999999");
      let lightColor = Css.hex("555555");
      style([
        width(pct(100.0 /. numCols)),
        float(`left),
        backgroundColor(`rgb((rgbVal, rgbVal, rgbVal))),
        color(
          `rgb((rgbVal, rgbVal, rgbVal))
          ->PolishedCss.Color.readable(
              ~light=lightColor,
              ~dark=darkColor,
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
            {React.string("Default text on " ++ string_of_int(rgbVal))}
          </div>
          <div className={Styles.getColumn2(rgbVal)}>
            {React.string("Default text on " ++ string_of_int(rgbVal))}
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