#include <LiquidCrystal_I2C.h>
#include <string.h>

// an instance that represents the LCD screen
static LiquidCrystal_I2C lcd(0x27, 16, 2);

// defines 0 to be associated with the left arrow character
#define LEFT_ARROW 0

// defines 1 to be associated with the right arrow character
#define RIGHT_ARROW 1

// defines a macro for the top row of the display
#define TOP_ROW 0

// defines a macro for the bottom row of the display
#define BOTTOM_ROW 1

// lcdSetup sets up the LCD. it initialises the I2C connection, turns the
// backlight on and creates the custom character associations.
void lcdSetup() {
    uint8_t leftArrowData[8] = {0x02, 0x06, 0x0E, 0x1E, 0x0E, 0x06, 0x02};
    uint8_t rightArrowData[8] = {0x08, 0x0C, 0x0E, 0x0F, 0x0E, 0x0C, 0x08};

    lcd.init();
    lcd.backlight();
    lcd.createChar(LEFT_ARROW, leftArrowData);
    lcd.createChar(RIGHT_ARROW, rightArrowData);
}

// lcdClear clears the LCD of any text.
void lcdClear() {
    lcd.clear();
}

// lcdPrintCentered prints the string on the specific row.
// 
// string is the string to be printed. Maximum 16 of characters, if more 
//   characters are printed, then the string will run off the far edge of the //   LCD.
// row indicates which row to print the string on. 0 indicates the top row.
//   1 indicates the bottom row.
void lcdPrintCentered(const char* string, uint8_t row) {
    lcd.setCursor((16 - strlen(string))/2, row);
    lcd.print(string);
}

// lcdDisplay displays a string on the top row, a string on the bottom row
// and a character in either bottom corner of the LCD.
// 
// topString is the string to display on the top row
// topStringOffset is the number of characters to advance through the string
//   before displaying the string. Useful for scrolling text.
// bottomString is the string to display on the bottom row
// bottomStringOffset is the number of characters to advance through the
//   bottomString before printing. Useful for scrolling text.
// left is the character to display in the bottom left corner of the LCD.
// right is the character to display in the bottom right corner of the LCD.
void lcdDisplay(const char* topString, uint8_t topStringOffset, const char* bottomString, uint8_t bottomStringOffset, char left, char right) {

    // clear the LCD and print the two strings
    lcdClear();
    lcdPrintCentered((topString + topStringOffset), TOP_ROW);
    lcdPrintCentered((bottomString + bottomStringOffset), BOTTOM_ROW);

    // print the character in the bottom left corner
    lcd.setCursor(0, 1);
    lcd.write(left);

    // print the character in the bottom right corner
    lcd.setCursor(15, 1);
    lcd.write(right);
}

// lcdDisplayMenu displays a prompt on the top row, an option on the bottom row
// and, optionally, next and previous arrows in the bottom corners of the LCD.
// 
// prompt is the string to display on the top row. Maximum of 16 characters.
// option is the string to display on the bottom row. Maximum of 14 characters
//   (because of the arrows).
// isLeftArrowEnabled indicates whether or not an arrow will be displayed in the
//   bottom left corner of the LCD. If false, no character is displayed.
// isRightArrowEnabled indicates whether or not an arrow will be displayed in
//   the bottom right corner of the LCD. If false, no character is displayed.
void lcdDisplayMenu(const char* prompt, const char* option, bool isLeftArrowEnabled, bool isRightArrowEnabled) {
    lcdDisplay(prompt, 0, option, 0, isLeftArrowEnabled ? LEFT_ARROW : ' ', isRightArrowEnabled ? RIGHT_ARROW : ' ');
}

