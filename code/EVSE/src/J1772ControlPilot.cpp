#include "J1772ControlPilot.h"
#include "ATMEGA328P_ADC.h"
/*
Schematic:
    Control Pilot ------ ADC_controlPilot
         +12V     ----->       4,3V
           9V     ----->       3,7V
    (PWM)  6V     ----->       [3,6V - 2,7V] 
           3V     ----->       3,17V
           0V     ----->       2,71V
         -12V     ----->       0,89V
*/

J1772ControlPilot::J1772ControlPilot(_ADC_ *adc, PWM *pwm, uint8_t curLimit) {
    _adc = adc;
    _pwm = pwm;

    // Calculate the limit of PWM by amps value
    _dutyON = 0;

    if (curLimit <= 51){
        _dutyON = curLimit / 0.6f; // 6A to 51A
    } else{
        _dutyON = ((curLimit - 64.0f) / 2.5f); // Above 51A
    }
    
    _actualState = PilotState::A;
    _pwm->setDutyCycle(100);

}

/*
J1772ControlPilot::PilotState J1772ControlPilot::queryState() {
    const int N = 125;             // Size of the average
    float buffer[N] = {0};         // Buffer
    int index = 0;                 // Actual position buffer
    int count = 0;                 // Samples
    float sum = 0;

    // ADC reading
    float voltage = _adc->read(MUX0);   // Send the port to read the ADC value

    // Update circular buffer
    buffer[index] = voltage;
    index = (index + 1) % N;
    if (count < N) count++;

    // Calculate the average
    for (int i = 0; i < count; i++) {
        sum += buffer[i];
    }
    float filtered = sum / count;

    // State machine
    if (filtered > 4.2) {
        _actualState = PilotState::A;
        _pwm->setDutyCycle(100);
    } else if (filtered > 3.9) {
        _actualState = PilotState::B;
        _pwm->setDutyCycle(100);
    } else if (filtered > 2) {
        _actualState = PilotState::C;
        _pwm->setDutyCycle(_dutyON);
    } else if (filtered > 0.6) {
        _actualState = PilotState::D;
        _pwm->setDutyCycle(_dutyON);
    } else if (filtered > 0.3) {
        _actualState = PilotState::E;
        _pwm->setDutyCycle(100);
    } else {
        _actualState = PilotState::F;
        _pwm->setDutyCycle(100);
    }

    return _actualState;
}
*/

J1772ControlPilot::PilotState J1772ControlPilot::queryState() {
    const int N = 125;  // Size of a periode
    float maxVoltage = 0;

    for (int i = 0; i < N; i++) {
        float voltage = _adc->read(MUX0); // ADC reading
        if (voltage > maxVoltage)
            maxVoltage = voltage;
    }


    // State machine
    if (maxVoltage > 4.5) {
        _actualState = PilotState::A;
        _pwm->setDutyCycle(100);
    } else if (maxVoltage > 3.8) {
        _actualState = PilotState::B;
        _pwm->setDutyCycle(100);
    } else if (maxVoltage > 3.1) {
        _actualState = PilotState::C;
        _pwm->setDutyCycle(_dutyON);
    //} else if (maxVoltage > 2.7) {
    //    _actualState = PilotState::D;
    //    _pwm->setDutyCycle(_dutyON);
    } else if (maxVoltage > 2.4) {
        _actualState = PilotState::E;
        _pwm->setDutyCycle(100);
    } else {
        _actualState = PilotState::F;
        _pwm->setDutyCycle(100);
    }

    return _actualState;
}