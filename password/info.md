# Arduino 4-Button Password Lock System

## Overview

This project is a simple password-based locking system built using Arduino.  
It uses:

- 4 push buttons (password input)
- 4 LEDs (input feedback)
- 1 RGB LED (menu indicator)
- 1 buzzer (audio feedback)

The password length is fixed to **4 button presses**.

---

## Hardware Components

- Arduino board (Uno/Nano/etc.)
- 4x Push buttons
- 4x LEDs
- 1x RGB LED
- 1x Buzzer
- Resistors
- Breadboard and jumper wires

---

## Menu System (RGB Colors)

The RGB LED shows the current selected option:

- 🔴 **Red** → Set new password  
- 🟡 **Yellow** → Unlock device  
- 🟢 **Green** → Lock device  
- 🔵 **Blue** → Change password (requires current password)

Press one of the 4 main buttons to select a menu option.  
Press the **menu button** to execute it.

---

## How It Works

### Setting a Password
1. Select **Red**.
2. Press 4 buttons in your desired order.
3. The password is saved.
4. Device becomes locked.

### Unlocking
1. Select **Yellow**.
2. Enter the 4-button password.
3. If correct → device unlocks.
4. If incorrect → error sound.

### Locking
1. Select **Green**.
2. Device locks immediately.

### Changing Password
1. Select **Blue**.
2. Enter the current password.
3. If correct → enter a new 4-button password.

---

## Security Notes

- Password is stored in RAM.
- Password is lost if Arduino resets.
- No brute-force protection (simple version).

---

## Project Purpose

This project demonstrates:

- Digital input handling
- Menu logic
- State management
- Password comparison logic
- Basic embedded system design

---

## Possible Improvements

- Store password in EEPROM
- Add LCD or OLED display
- Add lockout after multiple failed attempts
- Add different RGB colors for locked/unlocked state

---

## Author

Created as an educational embedded systems project using Arduino.