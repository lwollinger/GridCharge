#include "J1772ProximityPilot.h"
#include "ATMEGA328P_ADC.h"

/*
Connector voltage
+-------------------------+
|  Connector  |  Voltage  |
| ---------   |---------- | 
| Connected   |  2,50V~3V |
| Button Press|   1,5 V   |
| Desconected |    0 V    |
+-------------------------+

button press -> button pressed means intention to remove the connector
*/


J1772ProximityPilot::J1772ProximityPilot(_ADC_* adcInstance) {
    this->adc = adcInstance;
}

bool J1772ProximityPilot::IsConnectedPP(){
    float voltage = adc->read(MUX2);

    if (voltage > 2.2f) {
        return true;    // Connected
    } else {
        return false;   // Disconnected or error
    }
}

