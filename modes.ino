
#include <dmtimer.h>

DMTimer timerDisplayDistance(1000000); // 1 s timer

void modeDisplayDistance() {
  if (timerDisplayDistance.isTimeReached()) {
    char message[16] = {0};
    long distance = proximityGetDistance();

    if (distance <= 0 || distance >= 200) {
      snprintf(message, 16, "%s", "Out of range");
    } else {
      snprintf(message, 16, "%.d cm", distance);
    }
    lcdClear();
    if (cupInPlace(distance)) {
      lcdPrintCentered("Glass in place", 0);
    } else {
      lcdPrintCentered("Place Glass", 0);
    }
    lcdPrintCentered(message, 1);
  }
}

void modeDisplayButtons() {
        if (buttonLeftPressed()) {
     lcdPrintCentered("Left", 0);
   }
   else if (buttonRightPressed()) {
     lcdPrintCentered("Right", 0);
   }
   else if (buttonCentrePressed()) {
     lcdPrintCentered("Centre", 0);
   }
   else {
     lcdClear();
   }
}

#define DEBUG_NUM_OPTIONS 13

static void refreshDebugMenu(const char* option) {
  lcdClear();
  lcdDisplayMenu("Debug Menu", option, true, true);
}

void testProgress() {
  lcdClear();
  for (int i = 0; i <= 100; i+=1) {
    lcdDisplayProgress(i, 0);
    lcdDisplayProgress(i, 1);
    delay(500);
  }
}

void modeDebugMenu() {
  uint8_t optionIndex = 0;
  
  char options[DEBUG_NUM_OPTIONS][17] = {
    "Exit",
    "Glass LED On",
    "Glass LED Off",
    "Bottle LED On",
    "Bottle LED Off",
    "Test Progress",
    "Manual 1",
    "Manual 2",
    "Manual 3",
    "Manual 4",
    "Manual 5",
    "Manual 6",
    "Stress Test 1",
  };

  void (*optionFunctions[DEBUG_NUM_OPTIONS])() = {
    NULL,   // this is a special value, it will exit the debug menu
    glassLedOn,
    glassLedOff,
    bottleLedOn,
    bottleLedOff,
    testProgress,
    NULL, // manual pour 1
    NULL, // manual pour 2
    NULL, // manual pour 3
    NULL, // manual pour 4
    NULL, // manual pour 5
    NULL, // manual pour 6
    relayTestStress,
  };
  
  refreshDebugMenu(options[optionIndex]);
  
  while (1) {
      buttonUpdate();

      if (buttonLeftPressed()) {
        optionIndex -= 1;
        if (optionIndex >= DEBUG_NUM_OPTIONS) {
          optionIndex = DEBUG_NUM_OPTIONS - 1;
        }
        refreshDebugMenu(options[optionIndex]);
      }

      if (buttonRightPressed()) {
        optionIndex += 1;
        if (optionIndex >= DEBUG_NUM_OPTIONS) {
          optionIndex = 0;
        }
        refreshDebugMenu(options[optionIndex]);
      }

      if (buttonCentrePressed()) {
        switch (optionIndex) {
          case 0:
            return;
            break;
           case 6: // manual pour 1
            relayTurnOn(1);
            while (buttonCentrePressedRaw()) {
              continue;
            }
            relayTurnOff(1);
            break;
           case 7: // manual pour 2
            relayTurnOn(2);
            while (buttonCentrePressedRaw()) {
              continue;
            }
            relayTurnOff(2);
            break;
           case 8: // manual pour 3
            relayTurnOn(3);
            while (buttonCentrePressedRaw()) {
              continue;
            }
            relayTurnOff(3);
            break;
           case 9: // manual pour 4
            relayTurnOn(4);
            while (buttonCentrePressedRaw()) {
              continue;
            }
            relayTurnOff(4);
            break;
           case 10: // manual pour 5
            relayTurnOn(5);
            while (buttonCentrePressedRaw()) {
              continue;
            }
            relayTurnOff(5);
            break;
           case 11: // manual pour 6
            relayTurnOn(6);
            while (buttonCentrePressedRaw()) {
              continue;
            }
            relayTurnOff(6);
            break;
            default:
          (*optionFunctions[optionIndex])();
          refreshDebugMenu(options[optionIndex]);
          break;
            
        }
      }
  }
}

