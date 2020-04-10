//***************************************************************************************************
//** Projekt Falltür für Thea                                                                      **
//***************************************************************************************************

#include <Arduino.h>
#include <Globals.h>
#include <Entprellung.h>
#include <transitions.h>

//*** Globale Variablen
Entprellung TasterMan(Tman);



void setup() {
  //*** Initialisierungen
  pinMode(Mh,OUTPUT);
  pinMode(Mr,OUTPUT);
  pinMode(Kzu,INPUT_PULLUP);
  pinMode(Koff,INPUT_PULLUP);
  pinMode(Tman,INPUT_PULLUP);


  //*** Kommunikation mit seriellem Monitor
  Serial.begin(115200);
  Serial.println("OK, ICH BIN BEREIT!");

  //*** Startzustand setzen
  Zustand=ST_Bereit;

}



void loop() {
  transistions();
  Serial.println(Zustand);
  delay(1000);
}