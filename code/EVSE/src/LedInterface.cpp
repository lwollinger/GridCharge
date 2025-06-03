#include "LedInterface.h"


LedInterface::LedInterface(uint8_t rLed, uint8_t gLed, uint8_t bLed){
    this->_ledRedPin = rLed;
    this->_ledGreenPin = gLed;
    this->_ledBluePin = bLed;
}

void LedInterface::setStatus(EVSE::State mode){
    
}

void LedInterface::ledStatus(){

}