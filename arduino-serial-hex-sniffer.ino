/*
  Sketch serial-hex-sniffer

  Prints every incoming byte from Rx to Tx. Prints a newline after 0xBB.
  Two modes:
    Normal Mode: Prints every incoming byte as integer value
    Hex Mode: Prints every incoming byte as hex value with leading 0
              For example Rx = b to Tx 0B
  
  Default values:
    Mode: Hex Mode
    Newline after: 0xBB
    Baudrate: 115200

  The circuit:
  Connect Rx (pin 0 Arduino Uno) to Tx from another serial device.

  Copyright 2017 Boris Wenzlaff

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, 
  or any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#define SERIAL_BAUDRATE   115200  // default baudrate
#define NEWLINE_AFTER     0xBB    // print new line after this byte
#define MODE_HEX          0
#define MODE_NORMAL       1

byte b;
const int mode = MODE_HEX;        // mode

void setup() {
  Serial.begin(SERIAL_BAUDRATE);
  Serial.println("start serial hex printer");
}

void loop() {
  if (Serial.available() > 0) {
    b = Serial.read();
    if(mode == MODE_HEX) {
      if(b <0x10) {
        Serial.print("0");
      }
      Serial.print(b, HEX);
      Serial.print(" ");
    }
    else {
      Serial.print(b);
      Serial.print(" ");
    }
    if(b == NEWLINE_AFTER) {
      Serial.println();
    }
  }
}

