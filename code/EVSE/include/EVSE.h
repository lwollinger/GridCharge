#ifndef EVSE_H
#define EVSE_H

#include <avr/io.h>
#include "Connector.h"
#include "StatusInterface.h"


class EVSE {
private:
    bool _relayState;
    const uint8_t _relay = PORTB0;

    Connector * _connector;
    StatusInterface * _statusIface;
    
public:
    EVSE();
    int run();
    void SetRelayOn();
    void SetRelayOff();
    void setConnector(Connector* conn) { _connector = conn; }
    void setInterface(StatusIntercace* iface) { _statusIface = iface; }

    enum class State {
        NOTCONNECTED,
        CONNECTED,
        CHARGING,
        ERROR
    };
   
};

#endif // EVSE_H