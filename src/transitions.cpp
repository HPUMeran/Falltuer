#include <transitions.h>
#include <Arduino.h>

//*** Berechnet aufgrund der Eingänge und Bedingungen den aktuellen Zustand
//*** Gibt nichts zurück
void transitions()
{
    // --- von Bereit auf öffnen
    if(Zustand==ST_Bereit && Tman_Pressed && digitalRead(Koff)==HIGH)
        Zustand=ST_Oeffnen;

    // --- von Öffnen auf Bereit
    if(Zustand==ST_Oeffnen && (digitalRead(Koff)==LOW || Tman_Pressed))
        Zustand=ST_Bereit;

    // --- von Bereit auf Schließen
    if(Zustand==ST_Bereit && Tman_Pressed && digitalRead(Koff)==LOW)
        Zustand=ST_Schliessen;

    // --- von Schließen auf Bereit
    if(Zustand==ST_Schliessen && (digitalRead(Kzu)==LOW || Tman_Pressed))
        Zustand=ST_Bereit;
}