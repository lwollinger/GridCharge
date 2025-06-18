#include <avr/io.h>
#include <util/delay.h>

#include "LedInterface.h"
#include "EVSE.h"
#include "J1772.h"
#include "J1772ControlPilot.h"
#include "J1772ProximityPilot.h"
#include "ATMEGA328P_ADC.h"
#include "ATMEGA328_FAST_PWM.h"

int main()
{
    LedInterface led;
    EVSE evse;
    ATMEGA328P_ADC adc;
    J1772 conector1(&adc);
    J1772ControlPilot control;
    J1772ProximityPilot proximity(&adc);
    ATMEGA328FAST_PWM pwm;

    // Init PWM
    pwm.generatePWM();

    while (1)
    {
        EVSE::State state = conector1.getState();
        led.setStatus(state);

        switch (state){
        case EVSE::State::NOTCONNECTED:
            evse.SetRelayOff();

            break;
        case EVSE::State::CONNECTED:
            evse.SetRelayOff();

            break;
        case EVSE::State::CHARGING:
            evse.SetRelayOn();

            break;
        case EVSE::State::ERROR:
        default:
            evse.SetRelayOff();

            break;
        }
    }

    return 0;
}