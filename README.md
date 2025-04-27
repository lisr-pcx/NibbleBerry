# NibbleBerry

A silly experiment after dinner... (for two)

## Toolchain

rustc 1.86.0

Please refer to "Cargo.toml" for complete list of dependencies.

```bash
rustup update
rustup install 1.86.0
rustup default 1.86.0
```

```bash
cargo add piston
cargo add rand
```

Some libraries missing on my OS (Fedora)

```bash
sudo dnf makecache --refresh
sudo dnf install gcc-c++ libX11-devel alsa-lib-devel systemd-devel
```

## Game Engine

Piston v1.0.0  
Further info ([here](https://piston.rs/)).

## Design

Turn-based game.  
A pair number of berries is available inside a jar.  
The goal is to pick (=remove) berries to earn points.  
Each player get points based on the number of berries moved after picking one.  
The difference in size between the berry picked by each player will cut the points earned on that turn.

## Physics

The *gravity* is applied without acceleration.

TODO describe algorithm (when complete)

## Documentation and tests

Update rustdoc comments (outer/inner) frequently.  
Then run `cargo doc --open`.

More info [here](https://doc.rust-lang.org/rustdoc/what-is-rustdoc.html)

## Live demo

Currently [not available](https://lisr-pcx.github.io/NibbleBerry/index.html)

## License

This is free and unencumbered software released into the public domain.  
For more information, please refer to <https://unlicense.org>