#ifndef EVSE_H
#define EVSE_H

#include <avr/io.h>
//#include "Connector.h"
class Connector; // Forward declaration

//#include "StatusInterface.h"
class StatusInterface; // Forward declaration

class EVSE
{
private:
    bool _relayState;
    const uint8_t _relay = PORTB0;

    Connector *_connector;
    StatusInterface *_statusIface;

public:
    enum class State
    {
        NOTCONNECTED,
        CONNECTED,
        CHARGING,
        ERROR
    };

    EVSE();
    int run();
    void SetRelayOn();
    void SetRelayOff();
    void setConnector(Connector *conn) { _connector = conn; }
    void setInterface(StatusInterface *iface) { _statusIface = iface; }

};

#endif // EVSE_H