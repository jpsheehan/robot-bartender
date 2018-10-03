void buzzerSetup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

// plays a beep for when a button is pressed
void buttonBuzzer() {
  tone(BUZZER_PIN, 1000);
  delay(300);
  noTone(BUZZER_PIN);
}
//plays a little tune indicating that what you did worked
void successBuzzer() {
  tone(BUZZER_PIN, 1047);
  delay(250);
  tone(BUZZER_PIN, 1319);
  delay(250);
  tone(BUZZER_PIN, 1568);
  delay(250);
  noTone(BUZZER_PIN);
  }

// plays a failure sound
void failureBuzzer() {
  tone(BUZZER_PIN, 155);
  delay(250);
  tone(BUZZER_PIN, 131);
  delay(350);
  noTone(BUZZER_PIN);
}

//tests each sound by linking it to a button
void buzzerTest() {
  if (buttonLeftPressed()) {
    buttonBuzzer();
  } else if (buttonRightPressed()) {
    successBuzzer();
  } else if (buttonCentrePressed()) {
    failureBuzzer();
  }
}

