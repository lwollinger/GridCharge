#ifndef J1772_H
#define J1772_H

#include <avr/io.h>
#include "Connector.h"
#include "State.h"
#include "J1772ProximityPilot.h"
#include "J1772ControlPilot.h"


class J1772 : public Connector {
private:
    J1772ProximityPilot _proximity;
    J1772ControlPilot _control;

public:
    J1772();  // construtor padrão
    bool isConnected() override;
    State getState() override;
};

#endif // J1772