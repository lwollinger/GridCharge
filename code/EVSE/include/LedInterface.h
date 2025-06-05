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
/*
class LedRGB {
    private:
        uint8_t _ledRedPin;
        uint8_t _ledGreenPin;
        uint8_t _ledBluePin;
        volatile uint8_t * _port; 

    public:
        LedRGB(uint8_t port, uint8_t rPin, uint8_t gPin, uint8_t bPin){
            this->_port = (uint8_t*)port;
            this->_ledRedPin = rPin;
            this->_ledGreenPin = gPin;
            this->_ledBluePin = bPin;
        }
        void setColor(bool red, bool green, bool blue){
            
        }
};*/

class LedInterface : public StatusInterface {
private:
    const uint8_t _ledRedPin = PORTC0;
    const uint8_t _ledGreenPin = PORTC2;
    const uint8_t _ledBluePin = PORTC3;
public:
    LedInterface();
    void setStatus(EVSE::State mode) override;
    // override garante que eu sobreescrevo quando for usar o metodo.

};

#endif // LED_INTERFACE_H
