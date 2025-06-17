#include <avr/io.h>
#include <util/delay.h>

#include "LedInterface.h"
#include "EVSE.h" 

int main() {
    LedInterface led;
    EVSE evse;


    // Pode repetir ou parar aqui
    while (1){
        evse.SetRelayOn();
        _delay_ms(10000);
        evse.SetRelayOff();
        _delay_ms(10000);
    }

    return 0;
}
