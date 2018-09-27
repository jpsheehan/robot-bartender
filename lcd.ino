#include <LiquidCrystal_I2C.h>
#include <string.h>

static LiquidCrystal_I2C lcd(0x27, 16, 2);

static uint8_t leftArrowData[8] = {0x02, 0x06, 0x0E, 0x1E, 0x0E, 0x06, 0x02};
static uint8_t rightArrowData[8] = {0x08, 0x0C, 0x0E, 0x0F, 0x0E, 0x0C, 0x08};

#define LEFT_ARROW 0
#define RIGHT_ARROW 1

#define TOP 0
#define BOTTOM 1

void setupLcd() {
  lcd.init();
  lcd.backlight();
  lcd.createChar(LEFT_ARROW, leftArrowData);
  lcd.createChar(RIGHT_ARROW, rightArrowData);
}

void lcdClear() {
  lcd.clear();
}

void lcdPrintCentered(const char* string, uint8_t row) {
  lcd.setCursor((16 - strlen(string))/2, row);
  lcd.print(string);
}

void lcdDisplay(const char* topString, uint8_t topStringOffset, const char* bottomString, uint8_t bottomStringOffset, char left, char right) {
  lcdClear();
  lcdPrintCentered((topString + topStringOffset), TOP);
  lcdPrintCentered((bottomString + bottomStringOffset), BOTTOM);
  
  lcd.setCursor(0,1);
  lcd.write(left);
  lcd.setCursor(15, 1);
  lcd.write(right);
}

void lcdDisplayMenu(const char* prompt, uint8_t promptOffset, const char* option, uint8_t optionOffset, bool isLeftArrowEnabled, bool isRightArrowEnabled) {
  lcdDisplay(prompt, promptOffset, option, optionOffset, isLeftArrowEnabled ? LEFT_ARROW : ' ', isRightArrowEnabled ? RIGHT_ARROW : ' ');
}

