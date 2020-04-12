#include <Arduino.h>
#include <Globals.h>

//*** PROTOKOLL -> Befehle und Parameter
//*** Jedes Frame besteht aus 2 Byte: einem BEFEHL und einem PARAMETER
//********************************************************************
//*** MODE - BEFEHL:
uint8_t Do_Mode     = 0x4D;                 // M
//*** MODE - PARAMETER:
uint8_t Par_Auf     = 0x30;                 // 0
uint8_t Par_Zu      = 0x31;                 // 1
uint8_t Par_Auto    = 0x32;                 // 2
uint8_t Par_AutoLDR = 0x33;                 // 3
uint8_t Par_TempiOn = 0x34;                 // 4
uint8_t Par_TempiOff= 0x35;                 // 5
uint8_t Par_TempAOn = 0x36;                 // 6
uint8_t Par_TempAOff= 0x37;                 // 7

//*** Globale Variablen initialisieren
int Mode=Mode_Auto;                         
int Zustand=ST_Bereit;
bool Tman_Pressed=false;

bool Tag;                                   // Tag oder Nacht?
bool LDR_Changed_to_Day=false;              // Hat der LDR-Zustand gerade zu Tag gewechselt?
bool LDR_Changed_to_Night= false;           // Hat der LDR-Zustand gerade zu Nacht gewechselt?

bool Mode_InnenTemp= false;                 // Soll Innentemperatur kontrolliert werden?
bool InnenVentilator= false;                // Innenventilator eingeschaltet?
int InnenTempMax = 33;                      // Maximale Innentemperatur, ab der Ventilator eingeschalten wird

bool Mode_AussenTemp=false;                 // Soll Aussentemperatur kontrolliert werden?
bool AussenKalt=false;                      // Ist es außen zu kalt -> zeitverzögert starten
int AussenTempGrenze=-5;                    // Mindest-Außentemperatur, ab der normal geöffnet wird (-5 Grad)
unsigned long Verzoegerung=10000000;        // Verzögerungszeit zum Öffnen, wennes draussen zu kalt ist (ca. 3 Std.).