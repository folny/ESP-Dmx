// - - - - -
// ESPDMX - A Arduino library for sending and receiving DMX using the builtin serial hardware port.
//
// Copyright (C) 2015  Rick <ricardogg95@gmail.com>
// This work is licensed under a GNU style license.
//
// Last change: Marcel Seerig <https://github.com/mseerig> (edited by Marcel Seerig)
//
// Documentation and samples are available at https://github.com/Rickgg/ESP-Dmx
// - - - - -

#include <ESPDMX.h>

DMXESPSerial dmx;

void setup() {
  dmx.init();               // initialization
  delay(200);               // wait a while (not necessary)
}

void loop() {

    dmx.write(3, 0);        // channal 3 off
    dmx.write(1, 255);      // channal 1 on
    dmx.update();           // update the DMX bus
    delay(1000);            // wait for 1s
    
    dmx.write(1, 0);
    dmx.write(2, 255);
    dmx.update();
    delay(1000);

    dmx.write(2, 0);
    dmx.write(3, 255);
    dmx.update();
    delay(1000);

}
