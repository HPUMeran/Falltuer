//***************************************************************************************************
//** Projekt Falltür für Thea                                                                      **
//***************************************************************************************************

#include <Arduino.h>
#include "Entprellung.h"

//***   AUSGÄNGE
#define Mh      2                            // Motor hoch -> D2 (immer max. Geschwindigkeit)
#define Mr      A6                           // Motor runter -> A6 (immer max. Geschwindigkeit)

//***   EINGÄNGE
#define Kzu     7                           // Reed-Schalter Klappe geschlossen (Öffner)
#define Koff    8                           // Reed-Schalter Klappe offen (Öffner)
#define Tman    A3                          // Taster manuelle Steuerung

//***   ZUSTÄNDE
#define ST_Bereit       1
#define ST_Oeffnen    	2
#define ST_Schliessen   3

//*** Globale Variablen
int Zustand;
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