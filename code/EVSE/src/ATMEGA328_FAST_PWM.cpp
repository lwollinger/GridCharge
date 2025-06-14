#include "ATMEGA328_FAST_PWM.h"

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

                                    *OBSERVARTION*
_____________________________________________________________________________________________
Here I'm using 50% duty, because my connector and my EVSE was made to support this current!!!


*/

ATMEGA328FAST_PWM::ATMEGA328FAST_PWM(){
    DDRB |= (1 << PORTB2); // PORTB2 -> output
}

void ATMEGA328FAST_PWM::generatePWM(){
    // Config Timer1 for Fast PWM, mode 14
    TCCR1A = (1 << COM1B1) | (1 << WGM11); // Clear OC1B on Compare Match
    TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11); // Fast PWM, Prescaler = 8

    ICR1 = 19999;   // TOP periode 1 kHz
    OCR1B = _inicialDuty;   // Duty cycle 0% (OCR1B / ICR1)
}

void ATMEGA328FAST_PWM::changeDUTY(J1772ControlPilot::PilotState state) {
    switch (state) {
        case J1772ControlPilot::PilotState::A:
            OCR1B = ICR1; // 100% duty
            break;
        case J1772ControlPilot::PilotState::B:
            OCR1B = ICR1; // 100% duty
            break;
        case J1772ControlPilot::PilotState::C:
            OCR1B = 9999; // 50% duty
            break;
        case J1772ControlPilot::PilotState::D:
            OCR1B = 9999; // 50% duty
            break;
        case J1772ControlPilot::PilotState::E:
            OCR1B = ICR1; // 100% duty
            break;
        case J1772ControlPilot::PilotState::F:
            OCR1B = ICR1; // 100% duty
            break;
        default:
            OCR1B = 0; // Desliga PWM em outros casos, ou escolha outro valor
            break;
    }
}


  uint8_t variable;
  if ((amps >= 6) && (amps <= 51)) {
    // amps = (duty cycle %) X 0.6
    variable = amps * (TOP/60);
  } else if ((amps > 51) && (amps <= 80)) {
    // amps = (duty cycle % - 64) X 2.5
    variable = (amps * (TOP/250)) + (64*(TOP/100));
  }