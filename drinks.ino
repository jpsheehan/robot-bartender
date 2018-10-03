#define WHISKEY 1
#define COKE 6
#define SYRUP 2
#define RUM 3
#define LIMEJUICE 4
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









