#ifndef GLOBALS_H
#define GLOBALS_H
#include <Arduino.h>

//***   AUSGÄNGE
#define Mh      2                            // Motor hoch -> D2 (immer max. Geschwindigkeit)
#define Mr      A0                           // Motor runter -> A6 (immer max. Geschwindigkeit)

//***   EINGÄNGE
#define Kzu     7                           // Reed-Schalter Klappe geschlossen (Öffner)
#define Koff    8                           // Reed-Schalter Klappe offen (Öffner)
#define Tman    A3                          // Taster manuelle Steuerung

//***   ZUSTÄNDE
#define ST_Bereit       1
#define ST_Oeffnen    	2
#define ST_Schliessen   3

#define Mode_Auf        0
#define Mode_Zu         1
#define Mode_Auto       2


//*** PROTOKOLL -> Befehle und Parameter
//*** Jedes Frame besteht aus 2 Byte: einem BEFEHL und einem PARAMETER
//********************************************************************
//*** MODE - BEFEHL:
extern uint8_t Do_Mode;
//*** MODE - PARAMETER:
extern uint8_t Par_Auf;
extern uint8_t Par_Zu;
extern uint8_t Par_Auto;

//*** Globale Variablen
extern int Mode;                            // Konfigurations-Modus: Offen-ZU-Automatik
extern int Zustand;                         // Zustand im Zustandsdiagramm
extern bool Tman_Pressed;                   // Taster Manuell gedrückt?

#endif