# Installation and setup

## Using Avrdude

A Hardware Abstraction Layer (HAL) is required to run Rust on AVR microcontrollers and other common boards. To get this, you need the nightly Rust compiler that compiles Rust code to AVR on your machine. Run the command below to install it:

`rustup toolchain install nightly`

## On Windows

On Windows, you will need to install Scoop via Powershell using the command:

```
Set-ExecutionPolicy RemoteSigned -Scope CurrentUser # Needed to run a remote script the first time
irm get.scoop.sh | iex
```
Afterwards, run the following commands to install avr-gcc and avrdude:

`scoop install avr-gcc`

`scoop install avrdude`

## On macOS

On macOS, simply set up the homebrew-avr tap and run the following commands:

```
xcode-select --install # for the fist time
brew tap osx-cross/avr
brew install avr-binutils avr-gcc avrdude
```

## On Linux

If you use a Linux distribution like Ubuntu, the command is:

`sudo apt install avr-libc gcc-avr pkg-config avrdude libudev-dev build-essential`

There is an installation guide for all operating systems here, should you come across an obstacle following the guide above.

After either of these steps, the next step is to install the ravedudetool for flashing the microcontroller board against cargo:

`cargo +stable install ravedude`