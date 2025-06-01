#ifndef PWM_H
#define PWM_H

#include <avr/io.h>
#include "PilotState.h"

class PWM {
public:
    virtual void setControlPilotPWM(PilotState mode) = 0;
};

#endif // PWM