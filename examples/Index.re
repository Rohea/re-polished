module Test = {
  module Styles = {
    open Css;
    let getRedBox = () => style([backgroundColor(rgba(255, 0, 0, 1.0))]);
    let getRedBoxTransparentize = () =>
      style([
        backgroundColor(
          PolishedCss.Color.transparentize(0.5, rgba(255, 0, 0, 1.0)),
        ),
      ]);
  };

  [@react.component]
  let make = () => {
    <>
      <div className={Styles.getRedBox()}>
        {React.string("RedBox RGBA")}
      </div>
      <div className={Styles.getRedBoxTransparentize()}>
        {React.string("RedBox RGBA transparentize")}
      </div>
    </>;
  };
};

ReactDOMRe.renderToElementWithId(<Test />, "app");