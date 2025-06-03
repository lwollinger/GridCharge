#ifndef EVSE_H
#define EVSE_H

#include "State.h"
#include "SecurityAlert.h"  


class EVSE {
private:
    bool _relayState;
    

public:
    EVSE();
    int run();
    
    enum class State {
    OFF,
    CONNECTED,
    CHARGING,
    ERROR
};
   
};

#endif // EVSE_H