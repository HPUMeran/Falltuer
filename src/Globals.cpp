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

//*** Globale Variablen initialisieren
int Mode=Mode_Auto;                         
int Zustand=ST_Bereit;
bool Tman_Pressed=false;

bool Tag;                                   // Tag oder Nacht?
bool LDR_Changed_to_Day=false;              // Hat der LDR-Zustand gerade zu Tag gewechselt?
bool LDR_Changed_to_Night= false;           // Hat der LDR-Zustand gerade zu Nacht gewechselt?
