#ifndef J1772_PROXIMITY_PILOT_H
#define J1772_PROXIMITY_PILOT_H

#include <avr/io.h>
#include "ADC.h"


class J1772ProximityPilot {
private:
    _ADC_* adc;
public:
    J1772ProximityPilot(_ADC_* adcInstace);
    bool IsConnectedPP();
};

#endif // J1772_PROXIMITY_PILOT