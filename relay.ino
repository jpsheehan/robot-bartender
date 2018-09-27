#include <stdbool.h>

// relays stores the pin mapping for the relays
static uint8_t *relays;

// num_relays stores the number of relays that exist
static uint8_t num_relays;

// relaySetup initialises s relays on the pins supplied and turns them off
// returns true if successful, false if unsuccessful
bool relaySetup(uint8_t s, uint8_t pins[]) {
    relays = (uint8_t*)malloc(s * sizeof(uint8_t));
    if (relays == NULL) {
        return false;
    }

    num_relays = s;

    for (uint8_t i = 0; i < s; i++) {
        relays[i] = pins[i];
        pinMode(relays[i], OUTPUT);
        relayTurnOff(i + 1);
    }

    return true;
}



// relayTurnOn turns on the nth relay
// relay numbers start at 1
void relayTurnOn(uint8_t n) {
    digitalWrite(relays[n - 1], LOW);
}

// relayTurnOff turns off the nth relay
// relay numbers start at 1
void relayTurnOff(uint8_t n) {
    digitalWrite(relays[n - 1], HIGH);
}
