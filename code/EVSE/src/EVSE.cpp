#include "EVSE.h"

static uint8_t Running = 1;
static uint8_t Stopped = 0;

// Init relayStatus

EVSE::EVSE(){
    // Defining the PORTB0 = RelayControl |
    DDRB |= (1 << RELAY);   // Set PB0 to Output
    PORTB &= (1 << RELAY);  // Coloca PB0 em nível alto (fornece corrente)
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

