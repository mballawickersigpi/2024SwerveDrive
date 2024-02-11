#![no_std]
#![no_main]

use arduino_hal::prelude::*;
use panic_halt as _;

use embedded_hal::serial::Read;

#[arduino_hal::entry]
fn main() -> ! {
    let dp = arduino_hal::Peripherals::take().unwrap();
    let pins = arduino_hal::pins!(dp);
    let mut serial = arduino_hal::default_serial!(dp, pins, 115200);

    loop {
        let b = nb::block!(serial.read()).void_unwrap();

        ufmt::uwriteln!(&mut serial, "Got {}!\n", b).void_unwrap();
    }
}