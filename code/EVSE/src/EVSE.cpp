#include "EVSE.h"


// Init relayStatus

EVSE::EVSE(){
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

int EVSE::run(){


    return 0;
}

