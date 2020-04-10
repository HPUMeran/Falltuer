#include <Arduino.h>
#include <Globals.h>

//*** PROTOKOLL -> Befehle und Parameter
//*** Jedes Frame besteht aus 2 Byte: einem BEFEHL und einem PARAMETER
//********************************************************************
//*** MODE - BEFEHL:
uint8_t Do_Mode     = 0x01;
//*** MODE - PARAMETER:
uint8_t Par_Auf     = 0x00;
uint8_t Par_Zu      = 0x01;
uint8_t Par_Auto    = 0x02;


//*** Globale Variablen
int Mode=Mode_Auto;                         
int Zustand;
bool Tman_Pressed=false;