#ifndef ATMEGA328P_ADC_H
#define ATMEGA328P_ADC_H

#include "ADC.h"
#include <avr/io.h>

class ATMEGA328P_ADC : public _ADC_ {
public:
    ATMEGA328P_ADC(float voltage, float scale);
    
    // Here I know that the ADC of ATMEL328P is 10 bits, but I have used only uint16_t which holds the entire content of the 10bit value.
    float read(uint8_t pin) override; // Auxiliar Function

private:
    float voltage;
    float scale;
};

#endif // ATMEG328P_ADC_H
