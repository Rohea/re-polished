# Re-Polished

A reimplementation of the great [Polished](https://polished.js.org/) library in idiomatic [ReasonML](https://reasonml.github.io/en/) with following goals:
- Provide well designed data types for color manipulation
- Implement most of the color manipulation functions etc. with familiar names from Polished in platform agnostic ReasonML.
- Offer a binding layer for [Bs-Css](https://github.com/reasonml-labs/bs-css) for easier use with it on web platform (Bucklescript)

## Installation

Add following line to your package.json, delete lock file and re-install dependencies.
```
"@rohea/re-polished": "https://github.com/Rohea/re-polished.git#master",
```
Then add `@rohea/re-polished` to `bs-dependencies` in your `bsconfig.json`.

Add some point there will probably be a proper release. Watch this space.

## Example Usage with bs-css

```
let myClass = Css.style([
    Css.backgroundColor(`hex("ff0000")->PolishedCss.darken(0.5))
]);
```

## Supported functions

- darken
- desaturate
- lighten
- opacify
- readable
- transparentize
 
New functions are added as soon as we need them or someone makes a nice pull request :)
