#ifndef J1772_H
#define J1772_H

#include <avr/io.h>
#include "EVSE.h"
#include "Connector.h"
#include "J1772ProximityPilot.h"
#include "J1772ControlPilot.h"

class J1772 : public Connector {
private:
    uint8_t _maxCurrentConnector = 30;
    J1772ControlPilot _control_pilot;
    J1772ProximityPilot _proximity_pilot;
    
public:
     J1772(_ADC_* adc);
    uint8_t getConnectorCurrentLimit(){
        return _maxCurrentConnector;
    }
    State getState() override;
    bool isConnected() override {  // inline method
        return _proximity_pilot.IsConnectedPP();
    }
};

#endif // J1772