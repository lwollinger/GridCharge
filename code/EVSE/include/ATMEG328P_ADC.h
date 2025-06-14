#ifndef ATMEG328P_ADC_H
#define ATMEG328P_ADC_H

#include "ADC.h"
#include <avr/io.h>

class ATMEG328P_ADC : public _ADC_ {
public:
    ATMEG328P_ADC();
    float getVoltagePP() override;
    float getVoltageCP() override;

private:
    // Here I know that the ADC of ATMEL328P is 10 bits, but I have used only uint16_t which holds the entire content of the 10bit value.
    uint16_t readADC(); // Auxiliar Function
};

#endif // ATMEG328P_ADC_H
