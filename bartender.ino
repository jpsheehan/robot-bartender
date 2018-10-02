#include <stdbool.h>

#define NUM_RELAYS 6

char prompt[] = "Select Drink";

void displayWelcomeMessage() {
    lcdClear();
    lcdPrintCentered("Welcome!", 0);
    delay(500);
}


void setup() {
    // setup the relays
    uint8_t relayPins[NUM_RELAYS] = {11, 10, 9, 8, 7, 6, 5, 4};
    relaySetup(NUM_RELAYS, relayPins);
    lcdSetup();
    buttonSetup(3, 2, 1);
    proximitySetup(12, 13);
    
}

void loop() {

  modeDisplayDistance();

}
