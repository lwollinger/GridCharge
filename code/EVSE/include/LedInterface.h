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

class LedInterface : public StatusInterface {
private:
    
    uint8_t _ledRedPin;
    uint8_t _ledGreenPin;
    uint8_t _ledBluePin;

public:
    LedInterface(uint8_t rLed, uint8_t gLed, uint8_t bLed){
        this->_ledRedPin = rLed;
        this->_ledGreenPin = gLed;
        this->_ledBluePin = bLed;
    } // botar isso na .cpp

    void setStatus(State mode) override;
    // override garante que eu sobreescrevo quando for usar o metodo.
    void ledStatus();
};

#endif // LED_INTERFACE_H
