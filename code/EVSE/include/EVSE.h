#ifndef EVSE_H
#define EVSE_H

#include <avr/io.h>

class Connector; // Forward declaration
class StatusInterface; // Forward declaration
class SecurityAlert; // Forward declaration

class EVSE
{
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

private:
    bool _relayState;
    const uint8_t _relay = PORTB0;

    Connector *_connector;
    StatusInterface *_statusIface;
    SecurityAlert *_securityAlert; 

    EVSE::State _state = State::NOTCONNECTED; // Initial state
    // Variable to hold the current state that's necessary for the interface and security alert.
};

#endif // EVSE_H