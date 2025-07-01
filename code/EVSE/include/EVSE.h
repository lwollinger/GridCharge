#ifndef EVSE_H
#define EVSE_H

#include <avr/io.h>
#include "Connector.h"
#include "StatusInterface.h"


class EVSE {
private:
    // **Important** define mine evse current limit (maybe it's more interesting make a methode to create a evse with any value)
    const uint8_t _evseCurrentLimit = 30; 
    bool _relayState;
    const uint8_t _relay = PORTB0;

    Connector * _connector;
    StatusInterface * _statusIface;
    
public:
    EVSE();
    int run();
    void SetRelayOn();
    void SetRelayOff();
    uint8_t getEvseCurrentLimit() const{
        return _evseCurrentLimit;
    }
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