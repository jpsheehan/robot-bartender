# Robot Bartender

## Introduction

The Robot Bartender is a final first pro year project for ENEL200 by Dylan Toms, Matt Payne and Jesse Sheehan. The design document for this project can be found [here](https://ucliveac-my.sharepoint.com/:b:/g/personal/jps111_uclive_ac_nz/EQTACNtkXvNOix1AuEiEOE8Bzz9IzEP73t7XxjSLdWC8gQ?e=EXix7b).

## Hardware

The robot bartender is built using the following components:

| Part                | Quantity | Link                                                                                                                                             |
| ------------------- | -------- | ------------------------------------------------------------------------------------------------------------------------------------------------ |
| LCD Module          | 1        | [aliexpress.com](https://www.aliexpress.com/item/1PCS-LCD-module-Blue-screen-IIC-I2C-1602-for-arduino-1602-LCD-UNO-r3-mega2560/32763867041.html) |
| Relay Driver Module | 1        | [mindkits.co.nz](http://www.mindkits.co.nz/store/p/9318-8-Channel-Relay-Module-10A.aspx)                                                         |
| HC-SR04 Proximity Sensor | 1 | [sparkfun.com](https://www.sparkfun.com/products/13959) |


## Installation

The following libraries must be installed in Arduino Studio for the program to run:

| Library            | Author             | Version | Link                                                             |
| ------------------ | ------------------ | ------- | ---------------------------------------------------------------- |
| LiquidCrystal I2C  | Frank de Brabander | 1.1.2   | [github.com](https://github.com/marcoschwartz/LiquidCrystal_I2C) |
| DMTimer            | Nicolas Simonnet   | 1.0.0   | [github.com](https://github.com/toxnico/DMTimer)                 |

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

The SDA and SCL pins must be connected to A4 and A5 respectively because those are the only two pins on the UNO capable of I2C communication (which this module employs).

This file requires that the **LiquidCrystal I2C** library by Frank de Brabander is installed (see above).

The following functions are available from `lcd.ino`:

### `void lcdSetup()`
Must be called once during the setup phase. This function initializes the I2C connection to the LCD hardware.


### `void lcdClear()`
Clears all characters from the LCD screen.


### `void lcdPrintCentered(const char* string, uint8_t row)`
Prints `string` on the particular `row`. A `row` value of 0 represents the top row, while a `row` value of 1 represents the bottom row. If the string is longer than 16 characters it will "run off" the far edge of the screen.

### `void lcdDisplayMenu(const char* prompt, const char* option, bool isLeftArrowEnabled, bool isRightArrowEnabled)`
Displays a menu for the user. The `prompt` appears centered on the top row, the `option` appears centered on the bottom row. The boolean values indicate whether or not arrows are to appear in the bottom corners of the screen. Because of the arrows, the `option` string can be a maximum of 14 characters while the `prompt` string can be the regular 16.

## `relay.ino`

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

The `relay.ino` file gives the following functions:

### `relaySetup(uint8_t s, uint8_t pins[])`
Sets up the other relay functions to work with `s` relays on the specified `pins`. This must be called once in the setup function.

### `relayTurnOn(uint8_t n)`
Turns on the `n`th relay. Relays are indexed from one so that the labels on the physical PCB match up.

### `relayTurnOff(uint8_t n)`
Turns off the `n`th relay. Relays are indexed from one so that the labels on the physical PCB match up.

## `button.ino`

Contains functions for handling the three buttons on the front of the machine. The buttons are connected to the Arduino via one 10K Ohm pulldown resistor each so that floating voltage is mitigated. When the button is pressed the Arduino senses a high input, when the button is released the Arduino senses a low input. The buttons are to be connected as follows:

| Button Pin    | Arduino Board Pin |
| ------------- | ----------------- |
| Shared VCC    | +5V               |
| Left Button   | 3                 |
| Centre Button | 2                 |
| Right Button  | 1                 |

The `button.ino` file gives the following functions:

### `void buttonSetup(uint8_t left, uint8_t centre, uint8_t right)`
Sets up the buttons to work as digital inputs.

### `bool buttonLeftPressed()`
Returns true if the left button is currently being pressed.

### `bool buttonCentrePressed()`
Returns true if the centre button is currently being pressed.

### `bool buttonRightPressed()`
Returns true if the right button is currently being pressed.

## `proximity.ino`

Contains functions for interacting with the ultra-sonic proximity sensor. The sensor is connected directly to the Arduino using the below pinout:

| Proximity Sensor Pin | Arduino Board Pin |
| -------------------- | ----------------- |
| Gnd                  | Gnd               |
| Echo                 | 12                |
| Trigger              | 13                |
| VCC                  | +5V               |

When the distance is required, the Arduino sends out a clean 10ms pulse and the time it takes for the signal to bounce back is converted into a distance.

The `proxitity.ino` file contains the following functions:

### `proximitySetup(uint8_t echo, uint8_t trigger)`
Initialises the echo and trigger pins of the ultrasonic sensor.

### `proximityDistanceGet()`
Returns the measured distance in centimeters. If a value of zero is returned it means that the sensor could not detect and object (out of range).