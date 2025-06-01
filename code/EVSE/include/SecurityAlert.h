#ifndef SECURITY_ALERT_H
#define SECURITY_ALERT_H

#include <avr/io.h>
#include "EVSE.h"

/*
    SecurityAlert.h is the definition of a security part of the EVSE, this area is responsable to se if GFCI or the Phase 220 is
    fine, or we have a problem.
    The 
*/

class SecurityAlert {
private:
    uint8_t _gpio_pin;
    const char* _alert;

public:
    SecurityAlert(uint8_t GPIO, const char* alert_name);
    
    bool IsFaltSecurity();

};

#endif // SECURITY_ALER
