//***************************************************************************************************
//** Projekt Falltür für Thea                                                                      **
//***************************************************************************************************
#define Mh 2                            // Motor hoch -> D2 (immer max. Geschwindigkeit)
#define Mr A6                           // Motor runter -> A6 (immer max. Geschwindigkeit)

#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  Serial.println("OK, ICH BIN BEREIT!");
}

void loop() {
  
}