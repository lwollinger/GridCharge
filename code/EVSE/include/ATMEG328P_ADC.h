#ifndef ATMEG328P_ADC_H
#define ATMEG328P_ADC_H

#include "ADC.h"
#include <avr/io.h>

class ATMEG328P_ADC : public _ADC_ {
public:
    ATMEG328P_ADC();

    float getVoltagePP() override;
    PilotState getState() override;

private:
    uint16_t readADC(); // função auxiliar
};

#endif // ATMEG328P_ADC_H
