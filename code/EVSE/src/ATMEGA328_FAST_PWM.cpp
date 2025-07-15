#include "ATMEGA328_FAST_PWM.h"
#include "J1772.h"
#include "EVSE.h"
#include "ATMEGA328P_ADC.h"

/* This part is for generate the PWM, that's gonna tell the car, what's the capability of how much current the car can drain.
 *
 *
 * SAE J1772 PWM Duty Cycle vs. Available Current
 * ----------------------------------------------
 *  This table defines the relation between the PWM duty cycle 
 *  sent by the EVSE and the maximum current (in amperes) that 
 *  the vehicle is allowed to draw.
 * 
 *  +--------+-------------+--------+-------------+
 *  | Amps   | Duty Cycle  | Amps   | Duty Cycle  |
 *  +--------+-------------+--------+-------------+
 *  |  6 A   |    10%      | 40 A   |    66%      |
 *  | 12 A   |    20%      | 48 A   |    80%      |
 *  | 18 A   |    30%      | 65 A   |    90%      |
 *  | 24 A   |    40%      | 75 A   |    94%      |
 *  | 30 A   |    50%      | 80 A   |    96%      |
 *  +--------+-------------+--------+-------------+
 * 
 *  Notes:
 *  - Between 6 A and 51 A:    A = DutyCycle% × 0.6
 *  - Between 51 A and 80 A:   A = (DutyCycle% - 64) × 2.5
 * 

                                    *OBSERVARTION*
_____________________________________________________________________________________________
Here I'm using 50% duty = 30A, because my connector and my EVSE was made to support this current!!!

*/

ATMEGA328FAST_PWM::ATMEGA328FAST_PWM(){
    DDRB |= (1 << DDB2); // PORTB2 -> output
    generatePWM();
}

void ATMEGA328FAST_PWM::generatePWM() {
    // Config Timer1 for Fast PWM, mode 14
    TCCR1A = (1 << COM1B1) | (1 << WGM11); // Clear OC1B on Compare Match
    TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11); // Fast PWM, Prescaler = 8
    setFrequency(1000);
    setDutyCycle(0);  // Duty cycle 0%.
}

void ATMEGA328FAST_PWM::setFrequency(uint16_t frequency) {
    ICR1 = 1999;   // TOP periode 1 kHz
}

void ATMEGA328FAST_PWM::setDutyCycle(float percent) {
    OCR1B = (uint16_t)((percent / 100.0f) * ICR1);
}

void ATMEGA328FAST_PWM::stopPWM() { 
    setDutyCycle(0);
}

