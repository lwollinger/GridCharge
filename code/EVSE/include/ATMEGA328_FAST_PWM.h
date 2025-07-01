#ifndef ATMEGA328_FAST_PWM_H
#define ATMEGA328_FAST_PWM_H

#include <avr/io.h>
#include "PWM.h"

/* This part is for generate the PWM, that's gonna tell the car, what's the capability of how much current the car can drain.

 *  +--------+-------------+--------+-------------+
 *  | Amps   | Duty Cycle  | Amps   | Duty Cycle  |
 *  +--------+-------------+--------+-------------+
 *  |  6 A   |    10%      | 40 A   |    66%      |
 *  | 12 A   |    20%      | 48 A   |    80%      |
 *  | 18 A   |    30%      | 65 A   |    90%      |
 *  | 24 A   |    40%      | 75 A   |    94%      |
 *  | 30 A   |    50%      | 80 A   |    96%      |
 *  +--------+-------------+--------+-------------+

*/

class ATMEGA328FAST_PWM : public PWM {
private:
    const uint16_t _PWM = PORTB2;   // PWM atmega328P 16 bits.
    const uint16_t _inicialDuty = 0;
    uint16_t getCurrentLimit();
    uint16_t setPWM();
    void generatePWM();
public:
    ATMEGA328FAST_PWM();
    //uint16_t getCurrentLimit();
    //uint16_t setPWM();
    virtual void setControlPilotPWM(J1772ControlPilot::PilotState state) override;
};

#endif // ATMEGA328_FAST_PWM