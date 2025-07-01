#include <avr/io.h>
#include <util/delay.h>

#include "LedInterface.h"
#include "EVSE.h"
#include "J1772.h"
#include "ATMEGA328P_ADC.h"
#include "ATMEGA328_FAST_PWM.h"

int main()
{
    LedInterface led;
    ATMEGA328P_ADC adc;
    J1772 connector(&adc);

    //ATMEGA328FAST_PWM pwm;
    //pwm.generatePWM();

    EVSE system();
    system.setInterface(&led);
    system.setConnector(&connector);
    system.run();

    return 0;
}


