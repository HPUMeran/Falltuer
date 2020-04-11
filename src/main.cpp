//***************************************************************************************************
//** Projekt Falltür für Thea                                                                      **
//***************************************************************************************************
#define DEBUG true
#include <Arduino.h>
#include <Globals.h>
#include <Entprellung.h>
#include <transitions.h>
#include <LDR.h>

//*** Globale Variablen
Entprellung TasterMan(Tman);
LDR ldr_Aussen(LDRpin);

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
  pinMode(LDRpin,INPUT);

  //*** Kommunikation mit seriellem Monitor
  Serial.begin(115200);
  Serial.println("OK, ICH BIN BEREIT!");

  //*** Start-Annahmen
  Tag=Kzu;                          // Wenn Klappe geschlossen, nehme ich an, es sei Tag, sonst Nacht
  
}



void loop() {
  //*** Sensoren auslesen
  Tman_Pressed=TasterMan.raisingedge();             // Taster manuell ist Schließer
  if(Mode==Mode_AutoLDR)
  {
      ldr_Aussen.readState();
      LDR_Changed_to_Day=ldr_Aussen._raisingEdge;
      LDR_Changed_to_Night=ldr_Aussen._fallingEdge;
  }
  //*** Serielle Schnittstelle auslesen und in RingPuffer speichern
  if(Serial.available())
  {
    delay(5);
    while (Serial.available())
    {
      ring[(ring_pos+ring_num)%ring_cap]=Serial.read();
      ring_num++;
    }
  }

  //*** MODE Befehle interpretieren
  if(ring_num>1)
  {
    //*** Daten vorhanden
    Serial.print("Datenvorhanden: ");
    Serial.print(ring[ring_pos],HEX);
    if(ring[ring_pos]==Do_Mode)
    {
      ring_pos=(ring_pos+1) % ring_cap;
      Serial.println("2. Byte");
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
          else if (ring[ring_pos]==Par_AutoLDR)
            {
              Mode=Mode_AutoLDR;
              Serial.println("MODE AUTO_LDR");
            }
            else
                {
                  Serial.println("Fehler beim Protokoll MODE");
                }
      ring_num-=2;        
    }
  }

  //*** Übergänge kontrollieren, um aktuellen Zustand herauszufinden
  transitions();
    
  //*** Aktionen ausführen, die zum Zustand gehören
  switch(Zustand)
  {
    case ST_Bereit:
      //Serial.println("BEREIT!");
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
  Serial.print(Zustand);
  if(digitalRead(Koff)==LOW)
    Serial.println("Klappe OFFEN");
  if(digitalRead(Kzu)==LOW)
    Serial.println("Klappe ZU");
   
  delay(500);
}