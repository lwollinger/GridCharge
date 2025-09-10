#include "EVSE.h"
#include "StatusInterface.h"
#include "Connector.h"
#include "SecurityAlert.h"

EVSE::EVSE() {
    DDRB |= (1 << _relay);  
    PORTB &= (1 << _relay); 
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
        if(_securityAlert->IsFaultSecurity()){
            _state = EVSE::State::ERROR;
            _statusIface->setStatus(_state);  
            SetRelayOff();
        }
        else if (_connector->isConnected() && !_securityAlert->IsFaultSecurity()) {
            _state = _connector->getState();
            _statusIface->setStatus(_state);

            switch (_state) {
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
        } else {
            _statusIface->setStatus(EVSE::State::NOTCONNECTED);
            SetRelayOff();
        }
    }
    return 0;
}
