echo Enter Port:
read port
avrdude -p m328p -c arduino -P $port -b 115200 -U flash:w:target/avr-atmega328p/debug/rust-led.elf