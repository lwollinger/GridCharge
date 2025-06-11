#ifndef EVSE_H
#define EVSE_H

#include <avr/io.h>
#include "SecurityAlert.h"  


class EVSE {
private:
    bool _relayState;
    const uint8_t _relay = PORTB0;
    
public:
    EVSE();
    int run();
    void SetRelayOn();
    void SetRelayOff();
    
    enum class State {
        NOTCONNECTED,
        CONNECTED,
        CHARGING,
        ERROR
    };
   
};

#endif // EVSE_H