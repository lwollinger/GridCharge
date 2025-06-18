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
    DDRB |= (1 << PORTB2); // PORTB2 -> output
}

void ATMEGA328FAST_PWM::generatePWM(){
    // Config Timer1 for Fast PWM, mode 14
    TCCR1A = (1 << COM1B1) | (1 << WGM11); // Clear OC1B on Compare Match
    TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11); // Fast PWM, Prescaler = 8
    ICR1 = 1999;   // TOP periode 1 kHz
    OCR1B = _inicialDuty;   // Duty cycle 0%.
}

uint16_t ATMEGA328FAST_PWM::getCurrentLimit(){ // função dando problema

    // getCurrentLimit is gonna return the lowest number of current of the system to make the PWM (i think this is not the best way)

    EVSE evse;
    uint16_t evseAMP = evse.getEvseCurrentLimit();
    
    ATMEGA328P_ADC adc;
    J1772 j1772(&adc); 
    uint16_t connectorAMP = j1772.getConnectorCurrentLimit();

    if(evseAMP > connectorAMP){
        return connectorAMP;
    } else{
        return evseAMP;
    }
}


uint16_t ATMEGA328FAST_PWM::setPWM(){
    uint16_t amps = getCurrentLimit();

    // Calculate the limit of PWM by amps value
    
    if (amps < 6 || amps > 80){
        OCR1B = 0; // out of range, set pwm off
    }

    float duty = 0;

    if (amps <= 51){
        duty = amps / 0.6f; // 6A to 51A
    } else{
        duty = ((amps - 64.0f) / 2.5f); // Above 51A
    }

    // Convert duty % for the number of the timer variable OCR1B -> (OCR1B / ICR1)
    return OCR1B = (uint16_t)((duty / 100.0f) * ICR1);
}



void ATMEGA328FAST_PWM::setControlPilotPWM(J1772ControlPilot::PilotState state){


    switch (state) {
        case J1772ControlPilot::PilotState::A:
            OCR1B = ICR1; // 100% duty
            break;
        case J1772ControlPilot::PilotState::B:
            //OCR1B = ICR1; 
            OCR1B = ICR1;
            break;
        case J1772ControlPilot::PilotState::C:
            setPWM();
            break;
        case J1772ControlPilot::PilotState::D:
            setPWM();
            break;
        case J1772ControlPilot::PilotState::E:
            OCR1B = ICR1;
            break;
        case J1772ControlPilot::PilotState::F:
            OCR1B = ICR1;
            break;
        default:
            OCR1B = 0; // Desliga PWM em outros casos, ou escolha outro valor
            break;
    }
}


