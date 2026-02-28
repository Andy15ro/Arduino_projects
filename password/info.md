# Arduino 4-Button Password Lock System

## Description

This project is a simple password-based locking system using an Arduino Uno.  
The user sets a 4-button password and must enter the correct sequence to unlock the device.  
If the password is incorrect, access is denied.

The system includes visual feedback using LEDs and an RGB LED, plus audio feedback using a buzzer or piezo element.

---

## Components Needed

- 1 × Arduino Uno  
- 4 × LEDs (input feedback)  
- 4 × Push buttons  
- 1 × RGB LED  
- 1 × Buzzer or Piezo  
- 7 × 220Ω resistors (4 for LEDs, 3 for RGB)  
- Jumper wires and breadboard  

---

## Connections

### LEDs (Input Feedback)

| LED | Arduino Pin |
|-----|------------|
| LED 1 | A3 |
| LED 2 | A2 |
| LED 3 | A1 |
| LED 4 | A0 |

Each LED should have a 220Ω resistor connected to GND.

---

### Buttons

| Button | Arduino Pin |
|--------|------------|
| Button 1 | 3 |
| Button 2 | 4 |
| Button 3 | 5 |
| Button 4 | 6 |
| Menu / Confirm Button | 7 |

Each button connects between the pin and GND.  
Pins are configured using `INPUT_PULLUP`.

---

### RGB LED

| Color | Arduino Pin |
|-------|------------|
| Red   | 11 |
| Green | 10 |
| Blue  | 9  |

Each color channel should have a resistor.

---

### Buzzer / Piezo

| Component | Arduino Pin |
|-----------|------------|
| Buzzer    | 12 |

Connected between the pin and GND.

---

## Menu System (RGB Colors)

The RGB LED indicates the selected option:

- 🔴 Red → Set password  
- 🟡 Yellow → Unlock  
- 🟢 Green → Lock  
- 🔵 Blue → Change password  

Press one of the 4 main buttons to select an option.  
Press the menu button to execute it.

---

## How It Works

1. The user selects an option using one of the four buttons.  
2. The RGB LED changes color to indicate the selected mode.  
3. When setting or checking a password, the user must press exactly 4 buttons in sequence.  
4. If the password matches → success sound.  
5. If incorrect → error sound.

---

## Main Variables

| Variable | Type | Purpose |
|----------|------|----------|
| ledPins[4] | int | Stores LED pins |
| buttonPins[4] | int | Stores button pins |
| password[4] | int | Stores the 4-step password |
| currentOption | int | Stores selected menu option |
| deviceLocked | bool | Tracks lock state |

---

## Notes

- Pins 0 and 1 should be avoided (Serial communication).  
- Buttons use `INPUT_PULLUP`, meaning pressed = `LOW`.  
- Password is stored in RAM and resets when Arduino resets.  
- Password length is fixed to 4 inputs.

---

## System Logic

1. Select an option.  
2. Execute the selected action.  
3. If required, enter a 4-button password.  
4. System verifies the sequence.  
5. Device state updates accordingly.
