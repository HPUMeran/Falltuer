//***************************************************************************************************
//** Projekt Falltür für Thea                                                                      **
//***************************************************************************************************

#include <Arduino.h>
#include <Globals.h>
#include <Entprellung.h>


//*** Globale Variablen
Entprellung TasterMan(Tman);



void setup() {
  //*** Initialisierungen
  pinMode(Mh,OUTPUT);
  pinMode(Mr,OUTPUT);
  pinMode(Kzu,INPUT_PULLUP);
  pinMode(Koff,INPUT_PULLUP);
  pinMode(Tman,INPUT_PULLUP);



  Serial.begin(115200);
  Serial.println("OK, ICH BIN BEREIT!");
  Zustand=ST_Bereit;

}

void Bedingungen()
{
  // --- von Bereit auf öffnen
  if(Zustand==ST_Bereit );
}

void loop() {
  
}