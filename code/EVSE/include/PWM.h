#ifndef PWM_H
#define PWM_H

#include <avr/io.h>
//#include "PilotState.h"
#include "J1772ControlPilot.h"

class PWM {
public:

    void setDutyCycle();
    virtual void setControlPilotPWM(J1772ControlPilot::PilotState mode) = 0;
};

#endif // PWM