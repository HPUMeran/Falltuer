//***************************************************************************************************
//** Projekt Falltür für Thea                                                                      **
//***************************************************************************************************
#define DEBUG true
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
  //*** Sensoren auslesen
  Tman_Pressed=TasterMan.fallingedge();             // Taster manuell ist Öffner
  #ifdef DEBUG
    if(Tman_Pressed) Serial.println("Taster Manuell gedrückt!");
  #endif
  //*** Übergänge kontrollieren, um aktuellen Zustand herauszufinden
  transitions();

  //*** Aktionen ausführen, die zum Zustand gehören
  switch(Zustand)
  {
    case ST_Bereit:
      Serial.println("BEREIT!");
      digitalWrite(Mh,LOW);
      digitalWrite(Mr,LOW);
      break;    
    case ST_Oeffnen:
      Serial.println("Klappe ÖFFNET!");
      digitalWrite(Mh,HIGH);
      digitalWrite(Mr,LOW);
      break;
    case ST_Schliessen:
      Serial.println("Klappe SCHLIESST!");
      digitalWrite(Mr,HIGH);
      digitalWrite(Mh,LOW);
      break;
  }
  Serial.println(Zustand);
  delay(500);
}