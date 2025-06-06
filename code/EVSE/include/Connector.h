#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <avr/io.h>
#include "State.h"


class Connector {
public:
    virtual bool isConnected() = 0;
    virtual State getState() = 0;
};

#endif // CONNECTOR