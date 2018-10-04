#include <stdbool.h>
#include <dmtimer.h>

#define NUM_RELAYS 8

DMTimer bottleLedTimer(1000000);
DMTimer glassProximityTimer(100000);

void displayWelcomeMessage() {
    lcdClear();
    lcdPrintCentered("Welcome to the", 0);
    lcdPrintCentered("Bot-Tender", 1);
    successBuzzer();
    
    delay(2000);

    // Launch the debug menu if the left and right buttons are held down
    if (buttonLeftPressedRaw() && buttonRightPressedRaw()) {
      buttonUpdate();
      modeDebugMenu();
    }
}

void setup() {
  Serial.begin(9600);
    // setup the relays
    uint8_t relayPins[NUM_RELAYS] = {11, 10, 9, 8, 7, 6, 5, 4};
    relaySetup(NUM_RELAYS, relayPins); // set the relays up on the relayPins
    lcdSetup(); // set the lcd up, it uses A4 and A5 by default
    buttonSetup(2, 1, 0); // set the buttons up on pins 0, 1 and 2
    proximitySetup(12, 13); // set the proximity sensor up on pins 12 and 13
    buzzerSetup(3); // set the buzzer up on pin 3
    // bottleLedOn();
    displayWelcomeMessage();
    // bottleLedOff();
}

void loop() {
   mainMenu();
}
char drinks[6][17] = {
    "Whiskey & Coke",
    "Mojito",
    "Rum & Coke",
    "Snakebite",
    "Maple Nut Shot",
    "Sweet Daquiri"
    };

static void refreshDrinkMenu(const char* option) {
  lcdClear();
  lcdDisplayMenu("Select Drink", option, true, true);
  }

int drinkIndex = 0;


void timeForADrink(int option) {
  if (option == 0) {
    whiskeyAndCoke();
  } else if (option == 1) {
    mojito();
  } else if (option == 2) {
    rumAndCoke();
  } else if (option == 3) {
    snakebite();
  } else if (option == 4) {
    mapleNutShot();
  } else if (option == 5) {
    sweetDaquiri();
  }
}



void mainMenu() {
   refreshDrinkMenu(drinks[drinkIndex]);
  while(1) {
    buttonUpdate();

    if (bottleLedTimer.isTimeReached()) {
      bottleLedToggle();
    }

    if (glassProximityTimer.isTimeReached()) {
      if (proximityIsCupDetected()) {
        glassLedOn();
      } else {
        glassLedOff();
      }
    }
    
    if (buttonLeftPressed()) {
      buttonBuzzer();
      drinkIndex -= 1;
      if (drinkIndex < 0) {
        drinkIndex = 5;
      }
       refreshDrinkMenu(drinks[drinkIndex]);
    } else if (buttonRightPressed()) {
      buttonBuzzer();
      drinkIndex += 1;
      if (drinkIndex > 5) {
        drinkIndex = 0;
      }
       refreshDrinkMenu(drinks[drinkIndex]);
    } else if (buttonCentrePressed()) {
        bottleLedOff();
        
      DMTimer checkForCupTimeout(5000000); // 5 second timer
      DMTimer glassLedTimer(250000); // 0.25 second timer
      
      bool foundCup = false;
      glassLedOff();

      // flash the glass LEDs
      while (!checkForCupTimeout.isTimeReached()) {
        if (proximityIsCupDetected()) {
          foundCup = true;
          break;
        }

        Serial.println("Waiting");

        if (glassLedTimer.isTimeReached()) {
          glassLedToggle();
        }
      }
      
      if (foundCup) {
        glassLedOn();
        successBuzzer();
        lcdClear();
        lcdPrintCentered("Pouring", 0);
        lcdPrintCentered(drinks[drinkIndex], 1);
        timeForADrink(drinkIndex);
    } else { 
      failureBuzzer();
      glassLedOff();
    }
    
       refreshDrinkMenu(drinks[drinkIndex]);
}
  }
}



