#include "LedInterface.h"


LedInterface::LedInterface(){
    DDRC |= (1 << _ledRedPin) | (1 << _ledBluePin) | (1 << _ledGreenPin); // Set LED Pin Outputs
}

void LedInterface::setStatus(EVSE::State mode){
    switch (mode) {
        case EVSE::State::NOTCONNECTED:
            // RED: Connector not connected
            PORTC |= (1 << _ledRedPin);
            PORTC &= ~(1 << _ledBluePin);
            PORTC &= ~(1 << _ledGreenPin);
            break;
        case EVSE::State::CONNECTED:
            // BLUE: Connector connected
            PORTC |= (1 << _ledBluePin);
            PORTC &= ~(1 << _ledRedPin);
            PORTC &= ~(1 << _ledGreenPin);
            break;
        case EVSE::State::CHARGING:
            // GREEN: Charging
            PORTC |= (1 << _ledGreenPin);
            PORTC &= ~(1 << _ledBluePin);
            PORTC &= ~(1 << _ledRedPin);
            break;
        case EVSE::State::ERROR:
            // YELLOW: Error
            PORTC |=  (1 << _ledRedPin) | (1 << _ledGreenPin); 
            PORTC &= ~(1 << _ledBluePin);                     

            break;
    }
}

