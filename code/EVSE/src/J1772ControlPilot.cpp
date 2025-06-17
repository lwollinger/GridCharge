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

J1772ControlPilot::J1772ControlPilot() {
    _actualState = PilotState::A;
}

J1772ControlPilot::PilotState J1772ControlPilot::queryState(){
    float voltage = _adc.getVoltageCP();

    if(voltage > 4.3){
        _actualState = PilotState::A;
    } else if(voltage > 3.8){
        _actualState = PilotState::B;
    } else if(voltage > 3.4){
        _actualState = PilotState::C;
    } else if(voltage > 2.9){
        _actualState = PilotState::D;
    } else if(voltage > 1.5){
        _actualState = PilotState::E;
    } else{
        _actualState = PilotState::F;
    }

    return _actualState;
}

