#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include <avr/io.h>
#include "StatusInterface.h"


class LedInterface : public StatusInterface {
private:
    const uint8_t _ledRedPin = PORTC2;
    const uint8_t _ledGreenPin = PORTC3;
    const uint8_t _ledBluePin = PORTC0;
public:
    LedInterface();
    void setStatus(EVSE::State mode) override;

};

#endif // LED_INTERFACE_H
