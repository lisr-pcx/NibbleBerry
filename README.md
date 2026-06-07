# NibbleBerry

A silly experiment after dinner... (for two)

## Setting up environment (OS Fedora Linux)

### Toolchain

Visit [Rust official site](https://rust-lang.org/tools/install) and run proposed command terminal.

```bash
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```

Follow instructions and finally check that everything went fine via command `rustc --version`.

Finally add missing libraries:

```bash
sudo dnf makecache --refresh
sudo dnf install gcc-c++ libX11-devel alsa-lib-devel systemd-devel
```

### Editor (VSCode)

Feel free to use any other editor/IDE you like.

Upgrade packages:

```bash
sudo dnf upgrade --refresh
```

Import VSCode GPG key to verify the authenticity of the installed packages:

```bash
sudo rpm --import https://packages.microsoft.com/keys/microsoft.asc
```

Import VSCode RPM Repository using the command below (it creates a new repository file with the necessary configuration to access the Visual Studio Code packages):

```bash
printf "[vscode]\nname=packages.microsoft.com\nbaseurl=https://packages.microsoft.com/yumrepos/vscode/\nenabled=1\ngpgcheck=1\nrepo_gpgcheck=1\ngpgkey=https://packages.microsoft.com/keys/microsoft.asc\nmetadata_expire=1h" | sudo tee -a /etc/yum.repos.d/vscode.repo
```

Finalize Installation (for stable version) and installa desired editor extensions: Git Graph, Markdown Preview Github Styling, rust-analyzer:

```bash
sudo dnf install code
```

## Development and Game Engine

> [!WARNING]
> Work in progress. Current status is just a basic skeleton.

rustc 1.86.0  
Piston v1.0.0 further info [here](https://piston.rs/)

Refer to file *Cargo.toml* for complete list of dependencies.

## Design

+ Turn-based game.  
+ A pair number of berries is available inside a jar.  
+ The goal is to pick (=remove) berries to earn points.  
+ Each player get points based on the number of berries moved after picking one.  
+ The difference in size between the berry picked by each player will cut the points earned on that turn.

### Physics

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
