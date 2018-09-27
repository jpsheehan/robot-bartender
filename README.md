# Robot Bartender

## Installation

The following libraries must be installed in Arduino Studio for the program to run:

| Library            | Author             | Version | Link
| ------------------ | ------------------ | ------- | -----
| LiquidCrystal I2C  | Frank de Brabander | 1.1.2   | [github.com](https://github.com/marcoschwartz/LiquidCrystal_I2C)

To install a library, follow the following steps:

- Open this project in Arduino Studio
- Click the "Sketch" button on the menu bar
- Click "Include Library"
- Click "Manage Libraries..."

## `lcd.ino`

Contains functions for handling the LCD module. The LCD module itself must be connected as follows:

| LCD Module Pin # | Arduino Board Pin # |
| ---------------- | ------------------- |
| GND              | GND                 |
| VCC              | +5V                 |
| SDA              | A4                  |
| SCL              | A5                  |

The SDA and SCL pins must be connected to A4 and A5 respectively because those are the only two pins on the UNO capable of I2C communication (which this module employs).

This file requires that the **LiquidCrystal I2C** library by Frank de Brabander is installed (see above).

The following functions are available from `lcd.ino`:

- `void setupLcd()`: Must be called once during the setup phase. This function initializes the I2C connection to the LCD hardware.
- `void lcdClear()`: Clears all characters from the LCD screen.
- `void lcdPrintCentered(const char* string, uint8_t row)`: Prints `string` on the particular `row`. A `row` value of 0 represents the top row, while a `row` value of 1 represents the bottom row. If the string is longer than 16 characters it will "run off" the far edge of the screen.
- `void lcdDisplayMenu(const char* prompt, const char* option, bool isLeftArrowEnabled, bool isRightArrowEnabled)`: Displays a menu for the user. The `prompt` appears centered on the top row, the `option` appears centered on the bottom row. The boolean values indicate whether or not arrows are to appear in the bottom corners of the screen. Because of the arrows, the `option` string can be a maximum of 14 characters while the `prompt` string can be the regular 16.

## `relays.ino`

