#include "EVSE.h"
#include "StatusInterface.h"
#include "Connector.h"

EVSE::EVSE() {
    // Defining the PORTB0 = RelayControl |
    DDRB |= (1 << _relay);  // Set PB0 to Output
    PORTB &= (1 << _relay); // Start relay off
    this->_relayState = false;
}

void EVSE::SetRelayOn() {
    PORTB |= (1 << _relay);
    _relayState = true;
}

void EVSE::SetRelayOff() {
    PORTB &= ~(1 << _relay);
    _relayState = false;
}

int EVSE::run() {
    while (1) {
        if (_connector->isConnected()) { // Check if the connector is connected
            EVSE::State state = _connector->getState();
            _statusIface->setStatus(state);
            switch (state)
            {
            case EVSE::State::CHARGING:
                SetRelayOn();
                break;

            case EVSE::State::NOTCONNECTED:
            case EVSE::State::CONNECTED:
            case EVSE::State::ERROR:
            default:
                SetRelayOff();
                break;
            }
        }
    }

    return 0;
}
