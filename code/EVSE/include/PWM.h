#ifndef PWM_H
#define PWM_H

#include <avr/io.h>
//#include "PilotState.h"
//#include "J1772ControlPilot.h"

class PWM {
public:
    virtual void generatePWM() = 0;
    virtual void setFrequency(uint16_t frequency) = 0;
    virtual void setDutyCycle(float percent) = 0;
    virtual void stopPWM() = 0;
};

#endif // PWM