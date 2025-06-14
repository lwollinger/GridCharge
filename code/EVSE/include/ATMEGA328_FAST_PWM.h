#ifndef ATMEGA328_FAST_PWM_H
#define ATMEGA328_FAST_PWM_H

#include <avr/io.h>
#include "PWM.h"

/* This part is for generate the PWM, that's gonna tell the car, what's the capability of how much current the car can drain.
___________________________________________
| PWM   | SAE Continuous | SAE Short Term |
|-------|----------------|----------------|
| 50%   | 30 A           | 36 A peak      |
| 40%   | 24 A           | 30 A peak      |
| 30%   | 18 A           | 22 A peak      |
| 25%   | 15 A           | 20 A peak      |
| 16%   | 9.6 A          |                |
| 10%   | 6 A            |                |

*/

class ATMEGA328FAST_PWM : public PWM {
private:
    const uint8_t _PWM = PORTB2;
    const uint8_t _inicialDuty = 0;
public:
    ATMEGA328FAST_PWM();
    void generatePWM();
    void changeDUTY(J1772ControlPilot::PilotState state);
    //void setPWM();
    //void set
};

#endif // ATMEGA328_FAST_PWM