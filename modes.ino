
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

#define DEBUG_NUM_OPTIONS 5

static void refreshDebugMenu(const char* option) {
  lcdClear();
  lcdDisplayMenu("Debug Menu", option, true, true);
}

void modeDebugMenu() {
  uint8_t optionIndex = 0;
  
  char options[DEBUG_NUM_OPTIONS][16] = {
    "Exit",
    "Glass LED On",
    "Glass LED Off",
    "Bottle LED On",
    "Bottle LED Off"
  };

  void (*optionFunctions[DEBUG_NUM_OPTIONS])() = {
    NULL,   // this is a special value, it will exit the debug menu
    glassLedOn,
    glassLedOff,
    bottleLedOn,
    bottleLedOff
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
        if (optionIndex == 0) {
          return;
        } else {
          (*optionFunctions[optionIndex])();
          refreshDebugMenu(options[optionIndex]);
        }
      }
  }
}

