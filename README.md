# Re-Polished

A reimplementation of the great [Polished](https://polished.js.org/) library in [ReasonML](https://reasonml.github.io/en/) with following goals:
- Provide data types for color manipulation
- Implement many of the color manipulation functions from Polished in platform agnostic ReasonML.
- Offer a binding layer for [bs-css](https://github.com/reasonml-labs/bs-css) and others (?) for easier use on web platform in [ReScript](https://rescript-lang.org/)

## Installation with bs-css

```
yarn add @rohea/re-polished-bs-css
```
Then add `@rohea/re-polished` and `@rohea/re-polished-bs-css` to `bs-dependencies` in your `bsconfig.json`.

## Usage with bs-css

```
let myClass = Css.style([
    Css.backgroundColor(`hex("ff0000")->PolishedCss.darken(0.5))
]);
```

## Installation without bindings

```
yarn add @rohea/re-polished
```
Then add `@rohea/re-polished` to `bs-dependencies` in your `bsconfig.json`.


## Supported functions

- darken
- desaturate
- invert
- lighten
- mix
- opacify
- readable
- shade
- tint
- transparentize
- setAlpha
 
New functions are added as soon as we need them or someone makes a nice pull request :)

## TODO

- Add more functions

## A note about the future plans

It is likely that this library will develop prioritizing the web platform needs and maintain compatibility with ReScript as that is currently the primary usecase for the authors. However, if there are any users on native side and something breaks, don't hesitate to let us know :)