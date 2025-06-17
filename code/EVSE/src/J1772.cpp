#include "J1772.h"
#include "J1772ControlPilot.h"

//J1772::J1772(uint8_t maxCurrentConnector){
//    this->_maxCurrentConnector = maxCurrentConnector;
//}

J1772::J1772(_ADC_* adc)
    : _proximity_pilot(adc) // passa o ponteiro pro construtor
{}

// This methode, is gonna get the PilotState and convert to the EVSE state generic.
State J1772::getState(){
    switch (_control_pilot.queryState()) {
    case J1772ControlPilot::PilotState::A:
        return State::OFF;
    case J1772ControlPilot::PilotState::B:
        return State::CONNECTED;
    case J1772ControlPilot::PilotState::C:
        return State::CHARGING;
    case J1772ControlPilot::PilotState::D:
        return State::CHARGING;
    case J1772ControlPilot::PilotState::E:
        return State::ERROR;
    case J1772ControlPilot::PilotState::F:
        return State::ERROR;
    default:
        return State::ERROR;
    }
}
