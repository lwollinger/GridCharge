#ifndef J1772_CONTROL_PILOT_H
#define J1772_CONTROL_PILOT_H

#include <avr/io.h>


class J1772ControlPilot {
    enum class PilotState;
    
    
    private:
        PilotState _actualState;
    
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
};

#endif // J1772_CONTROL_PILOT