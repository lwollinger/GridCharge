#ifndef SECURITY_ALERT_H
#define SECURITY_ALERT_H

#include <avr/io.h>
#include "EVSE.h"

/*
    SecurityAlert.h is the definition of a security part of the EVSE, this area is responsable to se if GFCI or the Phase 220 is
    fine, or we have a problem.
    The 
*/

#define GFCI PD2
#define Phase1 PORTD3
#define Phase2 PORTD4

class SecurityAlert {
private:
    uint8_t _GFCI = GFCI;
    uint8_t _Phase1 = Phase1;
    uint8_t _Phase2 = Phase2;

public:
    SecurityAlert();
    bool IsFaultSecurity();
};

#endif // SECURITY_ALERT_H
