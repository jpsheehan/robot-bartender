#define bottleLeds 7
#define glassLeds 8

// these functions do exactly what they say on the tin
static bool bottleLedState = false;
static bool glassLedState = false;

void bottleLedToggle() {
  if (bottleLedState) {
    bottleLedOff();
  } else {
    bottleLedOn();
  }
}

void glassLedToggle() {
  if (glassLedState) {
    glassLedOff();
  } else {
    glassLedOn();
  }
}

void bottleLedOn() {
  relayTurnOn(bottleLeds);
  bottleLedState = true;
}

void bottleLedOff() {
  relayTurnOff(bottleLeds);
  bottleLedState = false;
}

void glassLedOn() {
  relayTurnOn(glassLeds);
  glassLedState = true;
}

void glassLedOff() {
  relayTurnOff(glassLeds);
  glassLedState = false;
}

void testLed() {
  bottleLedOn();
  delay(500);
  bottleLedOff();
  delay(500);
  glassLedOn();
  delay(500);
  glassLedOff();
  delay(500);
}


