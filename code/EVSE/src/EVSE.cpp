#include "EVSE.h"


// Init relayStatus

EVSE::EVSE(){
    // Defining the PORTB0 = RelayControl |
    DDRB |= (1 << RELAY);   // Set PB0 to Output
    PORTB &= (1 << RELAY); 
    this->_relayState = false;
}

void EVSE::SetRelayOn() {
    PORTB |= (1 << RELAY);
    _relayState = true;
}

void EVSE::SetRelayOff() {
    PORTB &= ~(1 << RELAY);
    _relayState = false;
}

int EVSE::run(){


    return 0;
}

