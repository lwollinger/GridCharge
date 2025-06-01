#ifndef J1772_PROXIMITY_PILOT_H
#define J1772_PROXIMITY_PILOT_H

#include <avr/io.h>
#include "J1772.h"
#include "ADC.h"


class J1772ProximityPilot {
private:
    bool _connectedPP;
    float _voltagePP;

public:
    J1772ProximityPilot();
    bool IsConnectedPP();
    void setConnectedPP(bool IsConnected);
};

#endif // J1772_PROXIMITY_PILOT