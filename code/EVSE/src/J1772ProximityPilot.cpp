#include "J1772ProximityPilot.h"

J1772ProximityPilot::J1772ProximityPilot(){
    this->_connectedPP = false;
    this->_voltagePP = 0; // nao sei se ta certo aqui teria que buscar no getVoltagePP()?
}

bool J1772ProximityPilot::IsConnectedPP(){
    
}

