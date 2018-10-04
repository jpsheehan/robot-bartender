static uint8_t buzzer_pin;

#define TONE_DELAY 250

#define NOTE_C3 131
#define NOTE_Eb3 155
#define NOTE_C6 1047
#define NOTE_E6 1319
#define NOTE_G6 1568

void buzzerSetup(uint8_t buzzer) {
  buzzer_pin = buzzer;
  pinMode(buzzer_pin, OUTPUT);
}

void buzzerPlay(uint16_t frequency, uint16_t duration) {
  tone(buzzer_pin, frequency);
  delay(duration);
}

void buzzerStop() {
  noTone(buzzer_pin);
}

// plays a beep for when a button is pressed
void buttonBuzzer() {
  buzzerPlay(NOTE_C6, TONE_DELAY);
  buzzerStop();
}

//plays a little tune indicating that what you did worked
// C major
void successBuzzer() {
  buzzerPlay(NOTE_C6, TONE_DELAY);
  buzzerPlay(NOTE_E6, TONE_DELAY);
  buzzerPlay(NOTE_G6, TONE_DELAY);
  buzzerStop();
  }

// plays a failure sound
// minor third between C and Eb
void failureBuzzer() {
  buzzerPlay(NOTE_Eb3, TONE_DELAY);
  buzzerPlay(NOTE_C3, TONE_DELAY + 100);
  buzzerStop();
}

//tests each sound by linking it to a button
void buzzerTest() {
  buttonUpdate();
  if (buttonLeftPressed()) {
    buttonBuzzer();
  } else if (buttonRightPressed()) {
    successBuzzer();
  } else if (buttonCentrePressed()) {
    failureBuzzer();
  }
}

