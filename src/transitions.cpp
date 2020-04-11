#include <transitions.h>
#include <Arduino.h>

//*** Berechnet aufgrund der Eingänge und Bedingungen den aktuellen Zustand
//*** Gibt nichts zurück
void transitions()
{
    int TorNichtZu=digitalRead(Kzu);
    int TorNichtOffen=digitalRead(Koff);

    if(Mode==Mode_Zu)                               //*** Protokoll seriell SCHLIEßEN
    {
        // --- von Bereit auf Schließen
        if(Zustand==ST_Bereit && TorNichtZu==HIGH)
            Zustand=ST_Schliessen;
        // --- von Schließen auf Bereit
        if(Zustand==ST_Schliessen && TorNichtZu==LOW)
            Zustand=ST_Bereit;
        return;
    }
    if(Mode==Mode_Auf)                               //*** Protokoll seriell ÖFFNEN
    {
        // --- von Bereit auf Öffnen
        if(Zustand==ST_Bereit && TorNichtOffen==HIGH)
            Zustand=ST_Oeffnen;
        // --- von Öffnen auf Bereit
        if(Zustand==ST_Oeffnen && TorNichtOffen==LOW)
            Zustand=ST_Bereit;
        return;
    }
    if(Mode==Mode_Auto)                             //*** Protokoll seriell AUTO (nur Taster)
    {
        // --- von Schließen auf Bereit
        if(Zustand==ST_Schliessen && TorNichtZu==LOW )
            Zustand=ST_Bereit;

        // --- von Öffnen auf Bereit
        if(Zustand==ST_Oeffnen && TorNichtOffen==LOW)
            Zustand=ST_Bereit;

        // --- von Bereit auf öffnen
        if(Zustand==ST_Bereit && Tman_Pressed && TorNichtOffen==HIGH)
            Zustand=ST_Oeffnen;

        // --- von Bereit auf Schließen
        if(Zustand==ST_Bereit && Tman_Pressed && TorNichtOffen==LOW)
            Zustand=ST_Schliessen;
    }
    if(Mode==Mode_AutoLDR)                             //*** Protokoll seriell AUTO (nur Taster)
    {
        // --- von Schließen auf Bereit
        if(Zustand==ST_Schliessen && TorNichtZu==LOW )
            Zustand=ST_Bereit;

        // --- von Öffnen auf Bereit
        if(Zustand==ST_Oeffnen && TorNichtOffen==LOW)
            Zustand=ST_Bereit;

        // --- von Bereit auf Öffnen wegen Taster
        if(Zustand==ST_Bereit && Tman_Pressed && TorNichtOffen==HIGH)
            {
                Zustand=ST_Oeffnen;
                return;
            }

        // --- von Bereit auf Schließen wegen Taster
        if(Zustand==ST_Bereit && Tman_Pressed && TorNichtOffen==LOW)
        {
            Zustand=ST_Schliessen;
            return;
        }

        // --- Bereit auf Öffnen wegen LDR
        if(Zustand==ST_Bereit && LDR_Changed_to_Day && TorNichtOffen==HIGH)
            Zustand=ST_Oeffnen;

        // --- Bereit auf Schließen wegen LDR
        if(Zustand==ST_Bereit && LDR_Changed_to_Night && TorNichtZu==HIGH)
            Zustand=ST_Schliessen;
    }
}