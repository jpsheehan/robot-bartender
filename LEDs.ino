#define bottleLeds 7
#define glassLeds 8

// these functions do exactly what they say on the tin

void bottleLedOn() {
  relayTurnOn(bottleLeds);
}

void bottleLedOff() {
  relayTurnOff(bottleLeds);
}

void glassLedOn() {
  relayTurnOn(glassLeds);
}

void glassLedOff() {
  relayTurnOff(glassLeds);
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


