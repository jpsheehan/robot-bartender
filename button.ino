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

static bool leftButtonChecked;
static bool rightButtonChecked;
static bool centreButtonChecked;

void buttonUpdate() {
  if (!buttonLeftPressedRaw()) {
    leftButtonChecked = false;
  }

  if (!buttonCentrePressedRaw()) {
    centreButtonChecked = false;
  }

  if (!buttonRightPressedRaw()) {
    rightButtonChecked = false;
  }
}

bool buttonLeftPressed() {
  if (leftButtonChecked == false && buttonLeftPressedRaw()) {
    leftButtonChecked = true;
    return true;
  } else {
    return false;
  }
}

bool buttonRightPressed() {
  if (rightButtonChecked == false && buttonRightPressedRaw()) {
    rightButtonChecked = true;
    return true;
  } else {
    return false;
  }
}

bool buttonCentrePressed() {
  if (centreButtonChecked == false && buttonCentrePressedRaw()) {
    centreButtonChecked = true;
    return true;
  } else {
    return false;
  }
}

bool buttonAnyPressed() {
  return buttonLeftPressed() || buttonRightPressed() || buttonCentrePressed();
}

bool buttonAnyPressedRaw() {
  return buttonLeftPressedRaw() || buttonRightPressedRaw() || buttonCentrePressedRaw();
}

// buttonLeftPressed returns true if the left button is pressed
bool buttonLeftPressedRaw() {
  if (digitalRead(leftButtonPin) == HIGH) {
    return true;
  } else {
    return false;
  }
}

// buttonRightPressed returns true if the right button is pressed
bool buttonRightPressedRaw() {
  if (digitalRead(rightButtonPin) == HIGH) {
    return true;
  } else {
    return false;
  }
}

// buttonCentrePressed returns true if the centre button is pressed
bool buttonCentrePressedRaw() {
  if (digitalRead(centreButtonPin) == HIGH) {
    return true;
  } else {
    return false;
  }
}

