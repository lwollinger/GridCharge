#ifndef ADC_H
#define ADC_H

#include "J1772ControlPilot.h"

/*
    The ADC.h is the definition about 2 things.
    1° - The EVSE know's when it's connected or pretendeed to be disconnected with a resistor divider.
    2° - The car is the responsable to change the voltage to the EVSE understand that we can charge.

    Schematic:

    Control Pilot ------ ADC_controlPilot (Verificar os erros!!!!)
         +12V     ----->       4,54V  
           9V     ----->       4,08V
           6V     ----->       3,63V
           3V     ----->       3,17V
           0V     ----->       2,71V
         -12V     ----->       0,89V


*/

class _ADC_ {
public:
    virtual float getVoltagePP() = 0;   
    virtual J1772ControlPilot::PilotState getState() = 0; // this metode, returns the pilot state that's running.
};

#endif // ADC_H
