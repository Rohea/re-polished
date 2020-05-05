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
      <h1>{React.string("Transparentize")}</h1>
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
    let getDefaultOnWhite = () => style([
      backgroundColor(`hex("ffffff")),
      color(`hex("ffffff")->PolishedCss.Color.readable())
    ]);
    let getDefaultOnBlack = () => style([
      backgroundColor(`hex("000000")),
      color(`hex("000000")->PolishedCss.Color.readable())
    ]);
    let getDefaultOnGray1 = () => style([
      backgroundColor(`hex("555555")),
      color(`hex("555555")->PolishedCss.Color.readable())
    ]);
    let getDefaultOnGray2 = () => style([
      backgroundColor(`rgb(1,1,1)),
      color(`rgb(1,1,1)->PolishedCss.Color.readable())
    ]);
  };
  [@react.component]
  let make = () => {
    <>
      <h1>{React.string("Readable")}</h1>
      <div className={Styles.getDefaultOnWhite()}>
        {React.string("Default text on white")}
      </div>
      <div className={Styles.getDefaultOnBlack()}>
        {React.string("Default text on black")}
      </div>
      <div className={Styles.getDefaultOnGray1()}>
        {React.string("Default text on #555555")}
      </div>
      <div className={Styles.getDefaultOnGray2()}>
        {React.string("Default text on #666666")}
      </div>
    </>
  }
}

module Main = {
  [@react.component]
  let make = () => {
  <>
    <Transparentize />
    <Readable />
  </>
  }
}

ReactDOMRe.renderToElementWithId(<Main />, "app");