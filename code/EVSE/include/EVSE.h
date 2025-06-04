#ifndef EVSE_H
#define EVSE_H

#include <avr/io.h>
#include "State.h"
#include "SecurityAlert.h"  

#define RELAY PORTB0 

class EVSE {
private:
    bool _relayState;
    
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