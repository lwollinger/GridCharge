#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <avr/io.h>
#include "EVSE.h"


/*
    Connector.h is a generic interface class that every connector has
    this implementation.
    For that application we gona use the J1772, but at the future, 
    if someone wants to implement other connector, is just to add a new 
    connector class.
*/

class Connector {
public:
    virtual bool isConnected() = 0;
    virtual EVSE::State getState() = 0;
};

#endif // CONNECTOR