#ifndef J1772_H
#define J1772_H

#include <avr/io.h>
#include "EVSE.h"
#include "Connector.h"
#include "J1772ProximityPilot.h"
#include "J1772ControlPilot.h"


class J1772 : public Connector {
private:
    uint8_t _maxCurrentConnector;
public:
    J1772(uint8_t maxCurrentConnector); 
    bool isConnected() override;
    State getState() override;
};

#endif // J1772