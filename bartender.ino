#include <stdbool.h>
#define BUZZER_PIN 3

#define NUM_RELAYS 8

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
    buttonSetup(2, 1, 0);
    proximitySetup(12, 13);
    buzzerSetup();
    successBuzzer();
    
}

void loop() {

  // testLed();
  modeDisplayDistance();
   //modeDisplayButtons();
   // buzzerTest();
   // relayTestIndividual();
}
