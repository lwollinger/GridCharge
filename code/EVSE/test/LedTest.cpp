#include <avr/io.h>
#include <util/delay.h>

#include "LedInterface.h"
#include "EVSE.h" 

int main() {
    LedInterface led;

    // Inicialização do hardware: configura os pinos como saída no construtor (já está no seu LedInterface)
    
    // Testa todos os estados em sequência
    led.setStatus(EVSE::State::NOTCONNECTED);
    _delay_ms(1000);  // delay para ver o LED ligado

    led.setStatus(EVSE::State::CONNECTED);
    _delay_ms(1000);

    led.setStatus(EVSE::State::CHARGING);
    _delay_ms(1000);

    led.setStatus(EVSE::State::ERROR);
    _delay_ms(1000);

    // Pode repetir ou parar aqui
    while (1);

    return 0;
}
