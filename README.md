# Re-Polished

A reimplementation of the great [Polished](https://polished.js.org/) library in [ReasonML](https://reasonml.github.io/en/) with following goals:
- Provide data types for color manipulation
- Implement many of the color manipulation functions from Polished in platform agnostic ReasonML.
- Offer a binding layer for [Bs-Css](https://github.com/reasonml-labs/bs-css) and others (?) for easier use on web platform (Bucklescript)

## Installation

Add following line to your package.json, delete lock file and re-install dependencies.
```
"@rohea/re-polished": "https://github.com/Rohea/re-polished.git#master",
```
Then add `@rohea/re-polished` to `bs-dependencies` in your `bsconfig.json`.

At some point there will probably be a proper release. Watch this space.

## Example usage with bs-css

```
let myClass = Css.style([
    Css.backgroundColor(`hex("ff0000")->PolishedCss.darken(0.5))
]);
```

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
- Possibly create a proper monorepo structure with published sub packages