#ifndef ADC_H
#define ADC_H


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
#include <avr/io.h>

class _ADC_ {
public:
    virtual float read(uint8_t pin) = 0;
};

#endif // ADC_H
