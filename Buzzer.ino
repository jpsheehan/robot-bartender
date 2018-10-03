void buzzerSetup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void buttonBuzzer() {
  tone(BUZZER_PIN, 1000);
  delay(300);
  noTone(BUZZER_PIN);
}

void successBuzzer() {
  tone(BUZZER_PIN, 1047);
  delay(250);
  tone(BUZZER_PIN, 1319);
  delay(250);
  tone(BUZZER_PIN, 1568);
  delay(250);
  noTone(BUZZER_PIN);
  }


void failureBuzzer() {
  tone(BUZZER_PIN, 155);
  delay(250);
  tone(BUZZER_PIN, 131);
  delay(350);
  noTone(BUZZER_PIN);
  
}

