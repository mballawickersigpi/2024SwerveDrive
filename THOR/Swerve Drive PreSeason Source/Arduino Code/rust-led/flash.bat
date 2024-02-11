set /p "port=Enter Port: "
set /p "rel=debug/release: "
avrdude -p m328p -c arduino -P %port% -b 115200 -U flash:w:target/avr-atmega328p/%rel%/rust-led.elf