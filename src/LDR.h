#ifndef LDR_H
#define LDR_H

#include <Arduino.h>

//**** Klasse, um ein LDR stabil auszulesen
class LDR
{
    public:
        int LDRstate=LOW;
        //** Constructor
        LDR(int pin);

        //*** Method for detecting LDR-state
        //*** returns State of LDR (HIGH=>more light than treshold, LOW=less light than treshold)
        int readState();
        bool _raisingEdge, _fallingEdge;
        
    private:
        int _pin;
        unsigned long _lastMillis=0;
        unsigned long _hellIntervall=2000;    // 600000= 10 Min. Zeit, die es hell/dunkel sein muss, um einen Tag/Nacht-Zustand zu erkennen
        int _lastState;
        int _hellGrenze=512;                // Schwellwert für Helligkeit (ADC)

};
#endif