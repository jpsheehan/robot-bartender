#define WHISKEY 1
#define COKE 4
#define SYRUP 3
#define RUM 2
#define LIMEJUICE 6
#define SODA 5

#define SINGLE 5000

void pourWhiskey(float size) {
  relayTurnOn(WHISKEY);
  delay(SINGLE * size);
  relayTurnOff(WHISKEY);
}

void pourCoke(float size) {
  relayTurnOn(COKE);
  delay(SINGLE * size);
  relayTurnOff(COKE);
}

void pourSyrup(float size) {
  relayTurnOn(SYRUP);
  delay(SINGLE * size);
  relayTurnOff(SYRUP);
}

void pourRum(float size) {
  relayTurnOn(RUM);
  delay(SINGLE * size);
  relayTurnOff(RUM);
}

void pourLimeJuice(float size) {
  relayTurnOn(LIMEJUICE);
  delay(SINGLE * size);
  relayTurnOff(LIMEJUICE);
}

void pourSoda(float size) {
  relayTurnOn(SODA);
  delay(SINGLE * size);
  relayTurnOff(SODA);
}









