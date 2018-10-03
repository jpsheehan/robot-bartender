
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

DMTimer timerDisplayButtons(10000); // 10ms timer

void modeDisplayButtons() {
    if (timerDisplayButtons.isTimeReached()) {
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
}
