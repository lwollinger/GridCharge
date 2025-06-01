#ifndef J1772_CONTROL_PILOT
#define J1772_CONTROL_PILOT

#include <avr/io.h>
#include "J1772.h"
#include "PilotState.h"
#include "PWM.h"


class J1772ControlPilot {
private:
    PilotState _actualState;
    uint8_t _maxCurrentConnector; 

public:
    J1772ControlPilot(uint8_t maxCurrentConnectorSupport);
    void queryState();
    
};

#endif // J1772_CONTROL_PILOT