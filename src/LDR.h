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

        //*** Method for detecting raising Edges
        //*** returns true if detected
        bool raisingLDR();
        
        //*** Method for detecting falling Edges
        //*** returns true if detected
        bool fallingLDR();
        
    private:
        int _pin;
        unsigned long _lastMillis=0;
        unsigned long _hellIntervall=2000;    // 600000= 10 Min. Zeit, die es hell/dunkel sein muss, um einen Tag/Nacht-Zustand zu erkennen
        int _lastState;
        bool _raisingEdge, _fallingEdge;
        int _hellGrenze=512;                // Schwellwert für Helligkeit (ADC)

};
#endif