# Ultrasonic Parking Sensor – Arduino Project

## Description

This Arduino project simulates a car parking sensor.  
It uses an HC-SR04 ultrasonic sensor to measure distance, an RGB LED to display proximity visually, and a buzzer to give audio warnings.  
The closer an object is, the higher the frequency of the buzzer, mimicking real car parking sensors.

---

## Components Needed

- 1 × Arduino Uno  
- 1 × HC-SR04 ultrasonic sensor  
- 1 × RGB LED (common cathode or common anode)  
- 3 × 220Ω resistors (for RGB LED)  
- 1 × Passive Buzzer  
- Jumper wires and breadboard  

---

## Connections

### RGB LED

| Color | Arduino Pin |
|-------|------------|
| Red   | 11         |
| Green | 10         |
| Blue  | 9          |

- Each LED pin must have a 220Ω resistor connected to GND (for common cathode) or VCC (for common anode).

### Buzzer

| Component | Arduino Pin |
|-----------|------------|
| Buzzer    | 13         |

### Ultrasonic Sensor

| Pin  | Arduino Pin |
|------|------------|
| Trig | 4          |
| Echo | 3          |

---

## How It Works

1. The HC-SR04 sensor measures the distance to the nearest object using ultrasonic waves.  
2. Based on the distance:  
   - **Green LED** → distance ≥ 50 cm (safe)  
   - **Yellow LED** → 20 cm < distance < 50 cm (caution)  
   - **Red LED** → distance ≤ 20 cm (too close)  
3. The buzzer emits sound depending on distance:  
   - Far → silent or low frequency  
   - Medium → moderate frequency  
   - Close → high frequency, rapid beeps  
4. The closer the object, the higher the buzzer frequency, simulating a real parking sensor.  

---

## Main Variables

| Variable | Type | Purpose |
|----------|------|---------|
| dist     | long | Stores measured distance from the ultrasonic sensor |
| red      | int  | Pin for Red LED |
| green    | int  | Pin for Green LED |
| blue     | int  | Pin for Blue LED |
| buzzer   | int  | Pin for buzzer |

---

## Notes

- `analogWrite` with gamma correction is used to get smoother LED brightness.  
- `tone(pin, frequency, duration)` generates the buzzer sound; `noTone(pin)` stops it.  
- Avoid using pins 0 and 1 for LEDs or buzzer—they are reserved for USB/Serial.  
- Use `long` for distance because `pulseIn()` may return large values in microseconds.  

---

## Operation Flow

1. Measure distance with HC-SR04.  
2. Update RGB LED color according to the measured distance.  
3. Produce buzzer sound with frequency proportional to distance.  
4. Wait a short interval.  
5. Repeat continuously for real-time feedback on proximity.
6. Optionally, you can use `map()` to scale distance to frequency or LED brightness proportionally:  
```cpp
int freq = map(dist, 20, 50, 3000, 1000); // maps distance 20-50cm to 3000-1000Hz
tone(buzzer, freq, 100);