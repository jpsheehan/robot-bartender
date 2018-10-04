#include <stdbool.h>

#define NUM_RELAYS 8

char prompt[] = "Select Drink";



void displayWelcomeMessage() {
    lcdClear();
    lcdPrintCentered("Welcome to the", 0);
    lcdPrintCentered("Bot-Tender", 1);
    successBuzzer();
    
    delay(1000);

    // Launch the debug menu if the left and right buttons are held down
    if (buttonLeftPressedRaw() && buttonRightPressedRaw()) {
      buttonUpdate();
      modeDebugMenu();
    }
}

void setup() {
    // setup the relays
    uint8_t relayPins[NUM_RELAYS] = {11, 10, 9, 8, 7, 6, 5, 4};
    relaySetup(NUM_RELAYS, relayPins); // set the relays up on the relayPins
    lcdSetup(); // set the lcd up, it uses A4 and A5 by default
    buttonSetup(2, 1, 0); // set the buttons up on pins 0, 1 and 2
    proximitySetup(12, 13); // set the proximity sensor up on pins 12 and 13
    buzzerSetup(3); // set the buzzer up on pin 3

    displayWelcomeMessage();
    
}

void loop() {
   mainMenu();
}
char drinks[6][17] = {
    "Whiskey and Coke",
    "Mojito",
    "Rum and Coke",
    "Snakebite",
    "Maple Nut Shot",
    "Sweet Daquiri"
    };

static void refreshDrinkMenu(const char* option) {
  lcdClear();
  lcdDisplayMenu("Select Drink", option, true, true);
  }

// char* currentDrink = drinks[0];
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

  while(1) {
    buttonUpdate();
    refreshDrinkMenu(drinks[drinkIndex]);
    if (buttonLeftPressed()) {
      buttonBuzzer();
      drinkIndex -= 1;
      if (drinkIndex < 0) {
        drinkIndex = 5;
      }
    } else if (buttonRightPressed()) {
      buttonBuzzer();
      drinkIndex += 1;
      if (drinkIndex > 5) {
        drinkIndex = 0;
      }
    } else if (buttonCentrePressed()) {
      successBuzzer();
      if (proximityIsCupDetected()) {
      timeForADrink(drinkIndex);
    } else { 
      failureBuzzer();
    }
}
  }
}



