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
uint8_t ring_pos=0, ring_num=0;     // Variablen für Ringpuffer: Position des Zeigers, Anzahl Bytes im Puffer
const uint8_t ring_cap = 10;        // Kapazität des Puffers
uint8_t ring[ring_cap];             // Ring-Puffer für Datenübertragung über serielle Schnittstelle



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
  //*** Serielle Schnittstelle auslesen und in RingPuffer speichern
  if(Serial.available())
  {
    delay(5);
    while (Serial.available())
    {
      ring[ring_pos]=Serial.read();
      ring_num++;
    }
  }
  if(ring_num>1)
  {
    //*** Daten vorhanden
    if(ring[ring_pos]==Do_Mode)
    {
      ring_pos=(ring_pos+1) % ring_cap;
      if(ring[ring_pos]== Par_Auf)
      {
        Mode=Mode_Auf;
        Serial.println("MODE AUF");
      }
      else if(ring[ring_pos]==Par_Auto)
        {
          Mode=Mode_Auto;
          Serial.println("MODE Auto");
        }
        else if(ring[ring_pos]==Par_Zu)
          {
            Mode=Mode_Zu;
            Serial.println("MODE ZU");
          }
          else
              {
                Serial.println("Fehler beim Protokoll MODE");
              }
              
    }
  }

  if(Mode==Mode_Auf)
    Zustand=ST_Oeffnen;
  if(Mode==Mode_Zu)
    Zustand=ST_Schliessen;
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