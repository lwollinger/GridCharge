#include "J1772ControlPilot.h"

J1772ControlPilot::J1772ControlPilot() {
    _actualState = PilotState::A;
}

J1772ControlPilot::PilotState J1772ControlPilot::queryState() {
    return _actualState;
}
