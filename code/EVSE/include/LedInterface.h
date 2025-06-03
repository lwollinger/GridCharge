#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include <avr/io.h>
#include "StatusInterface.h"

/*
    LedInterface.h is the user interface, in this case is the led implementation that will have 4 states:
    
    Led States{
    red -> connector not connected.
    blue -> connector connected, but not charging.
    green -> connector connected and charging.
    yellow -> error.
    }
*/

#define RED PORTC0
#define BLUE PORTC2
#define GREEN PORTC3

class LedInterface : public StatusInterface {
private:
    
    uint8_t _ledRedPin = RED;
    uint8_t _ledGreenPin = GREEN;
    uint8_t _ledBluePin = BLUE;

public:
    LedInterface();

    void setStatus(EVSE::State mode) override;
    // override garante que eu sobreescrevo quando for usar o metodo.
    void ledStatus();
};

#endif // LED_INTERFACE_H
