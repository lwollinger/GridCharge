#include "SecurityAlert.h"



SecurityAlert::SecurityAlert(){
    //DDRD &= ~((1 << _GFCI) | (1 << _Phase1) | (1 << _Phase2)); // Define I/O Input with high impedance, to read the pins.
    //PORTD |= (1 << _GFCI) | (1 << _Phase1) | (1 << _Phase2); // Enable internal pull-ups on these inputs

    DDRD &= ~(1 << PD2);
    PORTD |= (1 << PD2);

    /*
    The pull-up resistor here is used to, when I have the floating point of the device protection, I'll 
    set the pin to high and cut the relay_phase for more security and don't have any problem with false-positive
    */
}

// MID400 is used to see the phases so, the circuito tells me that, with a AC input the output is set to Low.
// If is nothing at input, the output of MID400 is set to high.
// GFCI is the same, low when ok, and high when we have 20mA detection.

bool SecurityAlert::IsFaultSecurity(){
    //bool gfci_fault = (PIND & (1 << _GFCI));     // HIGH = fault
    bool gfci_fault = (PIND & (1 << PD2)); // HIGH = falha

    //bool phase1_fault = (PIND & (1 << _Phase1)); // HIGH = no AC
    //bool phase2_fault = (PIND & (1 << _Phase2)); // HIGH = no AC
    //return gfci_fault | phase1_fault | phase2_fault;
    return gfci_fault; // || phase1_fault || phase2_fault;
}
