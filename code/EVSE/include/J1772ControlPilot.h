#ifndef J1772_CONTROL_PILOT_H
#define J1772_CONTROL_PILOT_H

#include <avr/io.h>
#include "J1772.h"


class J1772ControlPilot {
public:
    J1772ControlPilot(uint8_t maxCurrentConnectorSupport);
    void queryState();
    enum class PilotState {
    A, // Nothing connected
    B, // Connected but not charging
    C, // Charging
    D, // Ventilation required
    E, // Error
    };

private:
    PilotState _actualState;
    //uint8_t _maxCurrentConnector; 
};

#endif // J1772_CONTROL_PILOT