#include "J1772.h"
#include "J1772ControlPilot.h"
#include "EVSE.h"

J1772::J1772(_ADC_* adc)
    : _proximity_pilot(adc) // passa o ponteiro pro construtor
{}

// This methode, is gonna get the PilotState and convert to the EVSE state generic.
EVSE::State J1772::getState(){
    switch (_control_pilot.queryState()) {
    case J1772ControlPilot::PilotState::A:
        return EVSE::State::NOTCONNECTED;
    case J1772ControlPilot::PilotState::B:
        return EVSE::State::CONNECTED;
    case J1772ControlPilot::PilotState::C:
        return EVSE::State::CHARGING;
    case J1772ControlPilot::PilotState::D:
        return EVSE::State::CHARGING;
    case J1772ControlPilot::PilotState::E:
        return EVSE::State::ERROR;
    case J1772ControlPilot::PilotState::F:
        return EVSE::State::ERROR;
    default:
        return EVSE::State::ERROR;
    }
}
