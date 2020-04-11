#include <Arduino.h>
#include <LDR.h>
#include <Globals.h>

//** Constructor
        LDR::LDR(int pin)
        {
            _pin=pin;
            _lastMillis=millis();
            LDRstate=_lastState=(analogRead(_pin)>_hellGrenze);  // Wenn heller als hellGrenze, dann HIGH
        }

//*** Method for detecting LDR-state
//*** returns State of LDR (hell=HIGH=heller als hellGrenze)       
        int LDR::readState()
        {
            int aktState=(analogRead(_pin)>_hellGrenze);
            _fallingEdge=_raisingEdge=false;
            if(aktState!=_lastState)
            {
                _lastMillis=millis();
            }
            if(millis()-_lastMillis>_hellIntervall)
            {
                if(aktState!=LDRstate)
                {
                    LDRstate=aktState;
                    if(LDRstate==0)
                        _fallingEdge=true;
                    else
                        _raisingEdge=true;             
                }
            }
            _lastState=aktState;
            return LDRstate;
        }


    