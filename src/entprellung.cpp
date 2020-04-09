#include <Arduino.h>
#include "Entprellung.h"

        Entprellung::Entprellung(int pin)
        {
            _pin=pin;
            _lastMillis=millis();
            buttonstate=_lastState=digitalRead(_pin);
        }

        
        int Entprellung::readState()
        {
            int aktState=digitalRead(_pin);
            if(aktState!=_lastState)
            {
                _lastMillis=millis();
            }
            if(millis()-_lastMillis>_intervall)
            {
                if(aktState!=buttonstate)
                {
                    buttonstate=aktState;
                }
            }
            _lastState=aktState;
            return buttonstate;
        }
    