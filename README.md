# arduino-serial-hex-sniffer
Prints every incoming byte from Rx to Tx. Prints a newline after 0xBB.

## Two modes
### Normal Mode
Prints every incoming byte as integer value
### Hex Mode
Prints every incoming byte as hex value with leading 0. For example Rx = b to Tx 0B
  
## Default values
* Mode: Hex Mode
* Newline after: 0xBB
* Baudrate: 115200

## The circuit
Connect Rx (pin 0 Arduino Uno) to Tx from another serial device.

## History
Originally written to observe the serial communication of the python-can serial interface.
