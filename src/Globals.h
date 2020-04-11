#ifndef GLOBALS_H
#define GLOBALS_H
#include <Arduino.h>

//***   AUSGÄNGE
#define Mh      2                            // Motor hoch -> D2 (immer max. Geschwindigkeit)
#define Mr      A0                           // Motor runter -> A6 (immer max. Geschwindigkeit)

//***   EINGÄNGE
#define Kzu             7                           // Reed-Schalter Klappe geschlossen (Öffner)
#define Koff            8                           // Reed-Schalter Klappe offen (Öffner)
#define Tman            A3                          // Taster manuelle Steuerung
#define LDRpin          A6                          // LDR : je höher der Wert, desto dunkler ist es.
#define DHTpinInnen     6                           // Pin für Innentemperatur
#define VentPin         A1                          // Pin für Ventilator innen

//***   ZUSTÄNDE
#define ST_Bereit       1
#define ST_Oeffnen    	2
#define ST_Schliessen   3
//*** KONFIGURATIONSMODI
#define Mode_Auf        0                   // Öffnen über serielle
#define Mode_Zu         1                   // Schließen über serielle
#define Mode_Auto       2                   // Automatik nur über Taster manuell und serielle gesteuert
#define Mode_AutoLDR    3                   // Automatik über Taster manuell, seriell und Helligkeit gesteuert


//*** PROTOKOLL -> Befehle und Parameter
//*** Jedes Frame besteht aus 2 Byte: einem BEFEHL und einem PARAMETER
//********************************************************************
//*** MODE - BEFEHL:
extern uint8_t Do_Mode;
//*** MODE - PARAMETER:
extern uint8_t Par_Auf;
extern uint8_t Par_Zu;
extern uint8_t Par_Auto;
extern uint8_t Par_AutoLDR;
extern uint8_t Par_TempiOn;
extern uint8_t Par_TempiOff;

//*** Globale Variablen
extern int Mode;                            // Konfigurations-Modus: Offen-ZU-Automatik
extern int Zustand;                         // Zustand im Zustandsdiagramm
extern bool Tman_Pressed;                   // Taster Manuell gedrückt?

extern bool Tag;                            // Tag oder Nacht?
extern bool LDR_Changed_to_Day;             // Hat der LDR-Zustand gerade zu Tag gewechselt?
extern bool LDR_Changed_to_Night;           // Hat der LDR-Zustand gerade zu Nacht gewechselt?

extern bool Mode_InnenTemp;                 // Soll Innentemperatur kontrolliert werden?
extern bool InnenVentilator;                // Innenventilator eongeschaltet?
extern int InnenTempMax;                    // Maximale Innentemperatur, ab der Ventilator eingeschalten wird

#endif