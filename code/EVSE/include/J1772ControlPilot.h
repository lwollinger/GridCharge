#ifndef J1772_CONTROL_PILOT_H
#define J1772_CONTROL_PILOT_H

#include <avr/io.h>


class J1772ControlPilot {
public:
    J1772ControlPilot();
    enum class PilotState {
    A, // Nothing connected
    B, // Connected but not charging
    C, // Charging
    D, // Ventilation required
    E, // No Power
    F, // Error
    };

    PilotState queryState(); // querystate returns a pilotState

private:
    PilotState _actualState;
    //uint8_t _maxCurrentConnector; 
};

#endif // J1772_CONTROL_PILOT