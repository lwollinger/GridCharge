#include "J1772.h"

// entender melhor isso, fiquei na duvida de varias coisas, o motivo de eu ter que definir tudo isso na j1772.
J1772::J1772(uint8_t max_Current) {
    this->_maxCurrentConnector = max_Current;
}

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
