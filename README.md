# Robot Bartender

## Introduction

TODO

## Hardware

The robot bartender is built using the following components:

| Part | Quantity | Link |
| ---- | ---- | --- |
| LCD Module | 1 | [aliexpress.com](https://www.aliexpress.com/item/1PCS-LCD-module-Blue-screen-IIC-I2C-1602-for-arduino-1602-LCD-UNO-r3-mega2560/32763867041.html) |
| Relay Driver Module | 1 | [mindkits.co.nz](http://www.mindkits.co.nz/store/p/9318-8-Channel-Relay-Module-10A.aspx) |


## Installation

The following libraries must be installed in Arduino Studio for the program to run:

| Library            | Author             | Version | Link
| ------------------ | ------------------ | ------- | -----
| LiquidCrystal I2C  | Frank de Brabander | 1.1.2   | [github.com](https://github.com/marcoschwartz/LiquidCrystal_I2C) |

To install a library, follow the following steps:

- Open this project in Arduino Studio
- Click the "Sketch" button on the menu bar
- Click "Include Library"
- Click "Manage Libraries..."
- Search for the library using the search bar or scroll down
- Click the "Install" button when you find the library you're looking for

## `lcd.ino`

Contains functions for handling the LCD module. The LCD module has a backlight and is used to give some information to the user in the form of text. The LCD module itself must be connected as follows:

| LCD Module Pin | Arduino Board Pin |
| ---------------| ----------------- |
| GND            | GND               |
| VCC            | +5V               |
| SDA            | A4                |
| SCL            | A5                |

The SDA and SCL pins must be connected to A4 and A5 respect☺ively because those are the only two pins on the UNO capable of I2C communication (which this module employs).

This file requires that the **LiquidCrystal I2C** library by Frank de Brabander is installed (see above).

The following functions are available from `lcd.ino`:

- `void setupLcd()`: Must be called once during the setup phase. This function initializes the I2C connection to the LCD hardware.
- `void lcdClear()`: Clears all characters from the LCD screen.
- `void lcdPrintCentered(const char* string, uint8_t row)`: Prints `string` on the particular `row`. A `row` value of 0 represents the top row, while a `row` value of 1 represents the bottom row. If the string is longer than 16 characters it will "run off" the far edge of the screen.
- `void lcdDisplayMenu(const char* prompt, const char* option, bool isLeftArrowEnabled, bool isRightArrowEnabled)`: Displays a menu for the user. The `prompt` appears centered on the top row, the `option` appears centered on the bottom row. The boolean values indicate whether or not arrows are to appear in the bottom corners of the screen. Because of the arrows, the `option` string can be a maximum of 14 characters while the `prompt` string can be the regular 16.

## `relays.ino`

Contains functions for handling the relay module. The relay module is used to drive the solenoid valves while protecting the sensitive Arduino hardware from high currents. The relay module must be connected as follows:

| Relay Module Pin | Arduino Board Pin |
| ---------------- | ----------------- |
| VCC              | +5V               |
| IN1              | 11                |
| IN2              | 10                |
| IN3              | 9                 |
| IN4              | 8                 |
| IN5              | 7                 |
| IN6              | 6                 |
| IN7              | NC                |
| IN8              | NC                |
| GND              | GND               |

Two of the relays are not connected as we only require 6 to drive the solenoid valves. Any digital pins can be used for the relay module. We experimented with using pins 12 and 13 but found that because those pins are used to flash the program to memory, they caused the first relay to fire prematurely. This would not be good when the project is finished.

The relays are actuated when the corresponding pin is pulled low. They are normally pulled high so that they do not activate the solenoid valves.

The `relays.ino` file gives the following functions:

- `setupRelays(uint8_t s, uint8_t pins[])`: Sets up the other relay functions to work with `s` relays on the specified `pins`. This must be called once in the setup function.
- `turnOnRelay(uint8_t n)`: Turns on the `n`th relay. Relays are indexed from one so that the labels on the physical PCB match up.
- `turnOffRelay(uint8_t n)`: Turns off the `n`th relay.