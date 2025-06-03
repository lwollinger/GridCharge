#ifndef PILOT_STATE_H
#define PILOT_STATE_H

/*
    just here we gonna use just A,B,C/D,F.
*/

enum class PilotState {
    A, // Nothing connected
    B, // Connected but not charging
    C, // Charging
    D, // Ventilation required
    E, // Error
};

#endif // PILOT_STATE