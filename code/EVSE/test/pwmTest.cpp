#include <avr/io.h>
#include <util/delay.h>

#include "LedInterface.h"
#include "EVSE.h" 
#include "J1772.h"
#include "J1772ControlPilot.h"
#include "J1772ProximityPilot.h"
#include "ATMEGA328P_ADC.h"
#include "ATMEGA328_FAST_PWM.h"

int main() {
    LedInterface led;
    EVSE evse;
    ATMEGA328P_ADC adc;
    J1772 conector1(&adc);
    J1772ControlPilot control;
    J1772ProximityPilot proximity(&adc); 
    ATMEGA328FAST_PWM pwm;


    // Inicialização do hardware: configura os pinos como saída no construtor (já está no seu LedInterface)
    pwm.generatePWM();

    // Pode repetir ou parar aqui
    while (1){
        
        pwm.setControlPilotPWM(J1772ControlPilot::PilotState::C);

    }

    return 0;
}
