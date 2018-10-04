#include <stdbool.h>

// set this to true if we want to force only one relay on at a time
#define ALLOW_ONLY_ONE_RELAY_ON_AT_A_TIME false

// relays stores the pin mapping for the relays
static uint8_t *relays;

// num_relays stores the number of relays that exist
static uint8_t num_relays;

// some useful definitions for this file
#define RELAY_OFF HIGH
#define RELAY_ON LOW

#define RELAY_SAFETY_TIMEOUT 50

#if ALLOW_ONLY_ONE_RELAY_ON_AT_A_TIME
  #define NO_RELAY 0
  static uint8_t current_relay = NO_RELAY;
#endif

// relaySetup initialises s relays on the pins supplied and turns them off.
// 
// s is the length of the pins array.
// pins is the array of pins that each relay is connected to.
// 
// returns true if successful, false if unsuccessful.
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

// relayTurnOn turns on the nth relay. relay numbers start at 1.
// 
// n is the relay number to turn on
void relayTurnOn(uint8_t n) {
    #if ALLOW_ONLY_ONE_RELAY_ON_AT_A_TIME
      if (current_relay != NO_RELAY) {
        relayTurnOff(current_relay);
      }
      current_relay = n;
    #endif
    digitalWrite(relays[n - 1], RELAY_ON);
}

// relayTurnOff turns off the nth relay safely. relay numbers start at 1.
// 
// n is the relay number to turn off.
void relayTurnOff(uint8_t n) {
    digitalWrite(relays[n - 1], RELAY_OFF);
    #if ALLOW_ONLY_ONE_RELAY_ON_AT_A_TIME
      current_relay = NO_RELAY;
    #endif
    delay(RELAY_SAFETY_TIMEOUT);
}

// relayTurnOffAll turns off all the relays safely.
void relayTurnOffAll() {
  for (uint8_t i = 1; i <= num_relays; i++) {
    relayTurnOff(i);
  }
}

// relayTestIndividual tests each relay individually with a 1 second delay between each of them
void relayTestIndividual() {
   for (uint8_t i = 1; i <= 6; i++) {
      relayTurnOn(i);
      delay(1000);
      relayTurnOff(i);
   }
}

// relayTestStress2 tests each of the individual relays that are known good
void relayTestStress2() {
  bool state = false;
  lcdClear();
  lcdPrintCentered("Stress Test 2", 0);
  lcdPrintCentered("Hold any button", 1);
  
  while (!buttonAnyPressed()) {
   for (uint8_t i = 1; i <= 6; i++) {
      relayTurnOn(1);
      relayTurnOn(2);
      relayTurnOn(4);
      relayTurnOn(5);
      delay(500);
      relayTurnOffAll();
   }
    buttonUpdate();
  }
  relayTurnOffAll();
}

// relayTestStress tests all the relay
void relayTestStress() {
  bool state = false;
  lcdClear();
  lcdPrintCentered("Stress Test 1", 0);
  lcdPrintCentered("Hold any button", 1);
  
  while (!buttonAnyPressed()) {
   for (uint8_t i = 1; i <= 6; i++) {
      if (state) {
        relayTurnOff(i);
      } else {
      relayTurnOn(i);
      }
   }
   
     state = !state;
     delay(1000);
    buttonUpdate();
  }
  relayTurnOffAll();
}

