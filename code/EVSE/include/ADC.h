#ifndef ADC_H
#define ADC_H

#include "PilotState.h"

class _ADC_ {
public:
    virtual float getVoltagePP() = 0;
    virtual PilotState getState() = 0;
};

#endif // ADC_H
