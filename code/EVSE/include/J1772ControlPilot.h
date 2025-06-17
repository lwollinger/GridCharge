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
        ATMEGA328P_ADC _adc; // Nao to entendendo, eu to instanciando ele e nao sei oq ta acontecendo............!!!!!!!!!
};

#endif // J1772_CONTROL_PILOT