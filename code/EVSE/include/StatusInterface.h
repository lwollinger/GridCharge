#ifndef STATUS_INTERFACE_H
#define STATUS_INTERFACE_H

#include "EVSE.h"
//#include "State.h"

/*
    Pure Abstract interface class defines a setStatus() function ensure that any derived class (such as LedInterface) 
    must implement this function.
*/

class StatusInterface {
public:
    virtual void setStatus(EVSE::State mode) = 0;
};

#endif // STATUS_INTERFACE_H
