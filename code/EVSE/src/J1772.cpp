#include "J1772.h"

J1772::J1772(uint8_t maxCurrentConnector){
    this->_maxCurrentConnector = maxCurrentConnector;
};

bool J1772::isConnected(){


    return true;
}

State J1772::getState(){

    return ;
}