#ifndef J1772_CONTROL_PILOT_H
#define J1772_CONTROL_PILOT_H

#include <avr/io.h>
#include "ATMEGA328P_ADC.h"
#include "ATMEGA328_FAST_PWM.h"


class J1772ControlPilot { 
    
    public:
        J1772ControlPilot(_ADC_ *adc, PWM *pwm, uint8_t curLimit);
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
        uint8_t _dutyON;
        _ADC_ * _adc;
        PWM * _pwm;
};

#endif // J1772_CONTROL_PILOT_H
