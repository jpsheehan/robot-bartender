static uint8_t leftButtonPin;
static uint8_t centreButtonPin;
static uint8_t rightButtonPin;


// buttonSetup initialises the pins for the 3 buttons
// 
// left is the pin number of the left button
// centre is the pin number of the centre button
// right is the pin number of the right button
void buttonSetup(uint8_t left, uint8_t centre, uint8_t right) {
  leftButtonPin = left;
  centreButtonPin = centre;
  rightButtonPin = right;
  pinMode(leftButtonPin, OUTPUT);
  pinMode(centreButtonPin, OUTPUT);
  pinMode(rightButtonPin, OUTPUT);
}

// buttonLeftPressed returns true if the left button is pressed
bool buttonLeftPressed() {
  return digitalRead(leftButtonPin) == HIGH;
}

// buttonRightPressed returns true if the right button is pressed
bool buttonRightPressed() {
  return digitalRead(rightButtonPin) == HIGH;
}

// buttonCentrePressed returns true if the centre button is pressed
bool buttonCentrePressed() {
  return digitalRead(centreButtonPin) == HIGH;
}
