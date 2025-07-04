#include "J1772ControlPilot.h"
#include "ATMEGA328P_ADC.h"
/*
Schematic:
    Control Pilot ------ ADC_controlPilot
         +12V     ----->       4,54V
           9V     ----->       4,08V
           6V     ----->       3,63V
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

J1772ControlPilot::PilotState J1772ControlPilot::queryState(){
    float voltage = _adc->read(MUX0);   // Send the port to read the ADC value

    if(voltage > 4.3){
        _actualState = PilotState::A;
        _pwm->setDutyCycle(100);
    } else if(voltage > 3.8){
        _actualState = PilotState::B;
        _pwm->setDutyCycle(100);
    } else if(voltage > 3.4){
        _actualState = PilotState::C;
        _pwm->setDutyCycle(_dutyON);
    } else if(voltage > 2.9){
        _actualState = PilotState::D;
        _pwm->setDutyCycle(_dutyON);
    } else if(voltage > 1.5){
        _actualState = PilotState::E;
        _pwm->setDutyCycle(100);
    } else{
        _actualState = PilotState::F;
        _pwm->setDutyCycle(100);
    }

    return _actualState;
}

