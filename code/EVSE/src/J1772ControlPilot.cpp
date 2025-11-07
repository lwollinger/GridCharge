#include "J1772ControlPilot.h"
#include "ATMEGA328P_ADC.h"
/*
Schematic:
    Control Pilot ------ ADC_controlPilot
         +12V     ----->       4,3V
           9V     ----->       3,7V
    (PWM)  6V     ----->       [3,6V - 2,7V] 
           3V     ----->       3,17V
           0V     ----->       2,71V
         -12V     ----->       0,89V
*/

J1772ControlPilot::J1772ControlPilot(_ADC_ *adc, PWM *pwm, uint8_t curLimit) {
    _adc = adc;
    _pwm = pwm;

    // Calculate the limit of PWM by amps value
    _dutyON = 0;

    if (curLimit <= 51){
        _dutyON = curLimit / 0.6f; // 6A to 51A
    } else{
        _dutyON = ((curLimit - 64.0f) / 2.5f); // Above 51A
    }
    
    _actualState = PilotState::A;
    _pwm->setDutyCycle(100);

}

J1772ControlPilot::PilotState J1772ControlPilot::queryState() {
    const int N = 125;  // Size of a periode
    float maxVoltage = 0;

    /*
    The problem here is that the signal is PWM modulated, 
    and the project has a ADC with 125kHz sampling rate.
    So that's why, with 1khz PWM signal we take 125 samples
    to find the maximum voltage in the signal in a period.
    */
    for (int i = 0; i < N; i++) {
        float voltage = _adc->read(MUX0); // ADC reading
        if (voltage > maxVoltage)
            maxVoltage = voltage;
    }

    if (maxVoltage > 4.5) {
        _actualState = PilotState::A;
        _pwm->setDutyCycle(100);
    } else if (maxVoltage > 3.8) {
        _actualState = PilotState::B;
        _pwm->setDutyCycle(100);
    } else if (maxVoltage > 3.1) {
        _actualState = PilotState::C;
        _pwm->setDutyCycle(_dutyON);
    //} else if (maxVoltage > 2.7) {
    //    _actualState = PilotState::D;
    //    _pwm->setDutyCycle(_dutyON);
    } else if (maxVoltage > 2.4) {
        _actualState = PilotState::E;
        _pwm->setDutyCycle(100);
    } else {
        _actualState = PilotState::F;
        _pwm->setDutyCycle(100);
    }

    return _actualState;
}