#include "ATMEGA328P_ADC.h"
/*
Config ADC
+--------------------------------------------------------+
| MUX       | Chanel ADC| FisicPin    | Name             |
| --------- | --------- | ----------- | ---------------- |
| 0000      | ADC0      | PC0         | A0               |
| **0001**  | **ADC1**  | **PC1**     | **A1**           |
| 0010      | ADC2      | PC2         | A2               |
| 0011      | ADC3      | PC3         | A3               |
| **0100**  | **ADC4**  | **PC4**     | **A4**           |
| 0101      | ADC5      | PC5         | A5               |
+--------------------------------------------------------+

Schematic:
    Control Pilot ------ ADC_controlPilot
         +12V     ----->       4,54V
           9V     ----->       4,08V
           6V     ----->       3,63V
           3V     ----->       3,17V
           0V     ----->       2,71V
         -12V     ----->       0,89V

ADC = (Vin/Vref)*2^n
n -> bits ADC number (10bits)


** Nyquist Rule **

According to Nyquist, the sampling frequency > 2 * signal frequency.

With 16MHz on, we will use the prescaler, so that the sampled signal has precision and reduces aliasing (distortion due to undersampling).

16Mhz / 128 = 125kHz (ADC Clock)


*/

ATMEGA328P_ADC::ATMEGA328P_ADC(){

    // ADC and config prescaler / 128 -> ADC clock = 125kHz
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

}

uint16_t ATMEGA328P_ADC::readADC(){
    // Start conversion
    ADCSRA |= (1 << ADSC);

    // Wait the conversion
    while (ADCSRA & (1 << ADSC));

    // return the 10 bits ADC value
    return ADC;
}


float ATMEGA328P_ADC::getVoltageCP(){

    // Configuration of ADC1 Control Pilot
    ADMUX = (1 << REFS0) | (1 << MUX0); // 0001 -> ADC1

    // Get the ADC value
    uint16_t adcValue = readADC();

    // conversion the voltage (AVcc = 5V e resolução de 10 bits = 1024)
    float voltage = (adcValue * 5.0f) / 1023.0f;
    
    return voltage;
}

float ATMEGA328P_ADC::getVoltagePP(){

    // Configuration of ADC4 Proximity Pilot
    ADMUX = (1 << REFS0) | (1 << MUX2); // 0100 -> ADC4

     // Get the ADC value
    uint16_t adcValue = readADC();

    // conversion the voltage (AVcc = 5V e resolução de 10 bits = 1024)
    float voltage = (adcValue * 5.0f) / 1023.0f;
    
    return voltage;
}
