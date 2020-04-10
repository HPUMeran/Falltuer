#ifndef GLOBALS_H
#define GLOBALS_H

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
extern int Zustand;


#endif