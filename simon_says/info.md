# Simon Says – Arduino Project

## Description

This is a mini "Simon Says" game using an Arduino Uno.  
The Arduino generates a sequence of LED flashes, and the player must repeat the sequence by pressing the corresponding buttons.  
Each level adds a new step to the sequence. If the player makes a mistake, the game resets.

---

## Components Needed

- 1 × Arduino Uno  
- 4 × LEDs (Red, Yellow, Green, Blue)  
- 4 × Push buttons  
- 4 × 220Ω resistors for the LEDs  
- Jumper wires and breadboard  
- (Optional) Buzzer for sound effects  

---

## Connections

### LEDs

| LED    | Arduino Pin |
|--------|------------|
| Red    | 2          |
| Yellow | 3          |
| Green  | 4          |
| Blue   | 5          |

- Each LED should have a 220Ω resistor connected to GND.

### Buttons

| Button | Arduino Pin |
|--------|------------|
| Red    | 8          |
| Yellow | 9          |
| Green  | 10         |
| Blue   | 11         |

- Each button connects between the pin and GND.  
- Use `INPUT_PULLUP` mode for the pins.

### Analog Pin

- **A0**: left unconnected  
- Used as a source of randomness (`randomSeed`) for different sequences each time the game starts.

---

## How It Works

1. The Arduino generates a random step in the sequence.  
2. The LEDs flash the sequence for the player to see.  
3. The player repeats the sequence by pressing the buttons.  
4. If the sequence is correct, the level increases and a new step is added.  
5. If the sequence is incorrect, the game ends and resets.

---

## Main Variables

| Variable    | Type | Purpose |
|-------------|------|---------|
| ledPins[4]  | int  | Stores the LED pins |
| buttonPins[4] | int | Stores the button pins |
| sequence[100] | int | Stores the sequence of the game |
| level       | int  | Tracks the current level |

---

## Notes

- Avoid using pins 0 (RX) and 1 (TX) for LEDs or buttons—they are used for USB/Serial communication.  
- A0 should remain unconnected to provide a fluctuating input for randomness.  
- `INPUT_PULLUP` means the pin reads `LOW` when the button is pressed.

---



## Gameplay Flow

1. Generate a new step in the sequence.  
2. Show the sequence using LEDs.  
3. Wait for the player to press the buttons in order.  
4. If the player makes a mistake → Game Over.  
5. If correct → increase level and repeat with an extended sequence.