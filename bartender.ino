#include <stdbool.h>

#define NUM_RELAYS 6

void setup() {
  // setup the relays
  uint8_t relayPins[NUM_RELAYS] = {11, 10, 9, 8, 7, 6};
  relaySetup(NUM_RELAYS, relayPins);
  lcdSetup();
}

void loop() {
  
      char message[16] = {0};
      char drinks[6][10] = {
        "Whisky",
        "Bourbon",
        "Rum",
        "Coke",
        "Gin",
        "Vodka"
      };

      char prompt[] = "Select Drink";

      int offset = 0;
  
  // turn each relay on in sequence. this is a simple demo
  // relays are accessed using one-based indexing as this is how they are labelled on the board
   int previousRelayIndex = NUM_RELAYS;
   for (uint8_t i = 1; i <= NUM_RELAYS; i++) {

      lcdDisplayMenu(prompt, drinks[i-1], true, true);
     relayTurnOff(previousRelayIndex);
     relayTurnOn(i);
     previousRelayIndex = i;
     delay(1000);
   }

}
