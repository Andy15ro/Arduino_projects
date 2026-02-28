# Arduino Tilt Switch Alarm System

## Description

This project is a simple tilt-activated alarm system using an Arduino Uno.  
The system uses a tilt switch to detect movement and provides visual feedback with an LED and audio feedback with a buzzer.  
Each activation of the tilt switch is counted and displayed in the Serial Monitor.

---

## Components Needed

- 1 × Arduino Uno  
- 1 × LED  
- 1 × Tilt switch  
- 1 × Buzzer or Piezo  
- 1 × 220Ω resistor (for LED)  
- Jumper wires and breadboard  

---

## Connections

### LED

| Component | Arduino Pin |
|-----------|------------|
| LED       | 3          |

Connect the LED anode to pin 3, cathode through a 220Ω resistor to GND.

---

### Tilt Switch

| Component   | Arduino Pin |
|-------------|------------|
| Tilt switch | 7          |

Connect one pin to pin 7 and the other pin to GND.  
The pin is configured using `INPUT_PULLUP`.

---

### Buzzer / Piezo

| Component | Arduino Pin |
|-----------|------------|
| Buzzer    | 12         |

Connect between pin 12 and GND.

---

## How It Works

1. The system continuously reads the tilt switch state.  
2. When the tilt switch is activated (LOW):  
   - The LED turns on.  
   - The buzzer emits a 532 Hz tone for 200 ms.  
   - The counter increases and is printed to the Serial Monitor.  
3. When the tilt switch is inactive (HIGH):  
   - The LED turns off.  
   - The buzzer is silent.  

---

## Main Variables

| Variable | Type | Purpose |
|----------|------|---------|
| `ledPin` | int  | Stores the LED pin number |
| `tilt`   | int  | Stores the tilt switch pin number |
| `buzzer` | int  | Stores the buzzer pin number |
| `nr`     | int  | Counts the number of tilt activations |

---

## Notes

- `INPUT_PULLUP` is used for the tilt switch; pressed = `LOW`.  
- The Serial Monitor shows the total number of activations.  
- Delay of 300 ms prevents counting multiple times for a single tilt.  
- The buzzer tone duration is short to avoid continuous sound.  

---

## System Logic

1. Read tilt switch state.  
2. If activated → LED ON, buzzer sound, increment counter, print to Serial.  
3. If inactive → LED OFF, buzzer OFF.  
4. Repeat continuously in loop.