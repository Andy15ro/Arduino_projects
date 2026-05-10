# Arduino Weather Station – Multi-Sensor Environmental Monitor

## Description

This project is a **multi-sensor weather station built on Arduino Uno** that monitors environmental parameters in real time.  
It reads temperature, humidity, light intensity, and water presence, then displays the data on a 16x2 LCD with a simple page system.

The system also includes a **water detection alarm (LED + buzzer)** that overrides normal display behavior for safety alerting.

The architecture is based on **non-blocking timing (millis-based scheduling)** to allow simultaneous sensor updates without freezing the system.

---

## Components Needed

- 1 × Arduino Uno  
- 1 × 16x2 LCD (HD44780 compatible)  
- 1 × DHT11 temperature & humidity sensor  
- 1 × 10K NTC thermistor  
- 1 × LDR (light sensor)  
- 1 × water detection sensor  
- 1 × push button  
- 1 × LED  
- 1 × buzzer  
- Resistors:
  - 1 × 10kΩ (thermistor divider)
  - 4 × 220Ω (LED + LCD optional backlight)
- Breadboard + jumper wires  

---

## Connections

### Sensors

| Sensor | Arduino Pin |
|--------|------------|
| Water sensor | A4 |
| Light sensor (LDR) | A3 |
| Thermistor (NTC) | A2 |
| DHT11 DATA | 3 |

---

### Outputs

| Component | Arduino Pin |
|-----------|------------|
| LED | 2 |
| Buzzer | 5 |
| LCD RS | 7 |
| LCD E | 8 |
| LCD D4 | 9 |
| LCD D5 | 10 |
| LCD D6 | 11 |
| LCD D7 | 12 |

---

### Input

| Component | Arduino Pin |
|-----------|------------|
| Button | 4 |

Button uses `INPUT_PULLUP` (pressed = LOW).

---

## System Features

### Water Alarm Mode (Priority System)
When water is detected:
- LED turns ON
- Buzzer activates (2 kHz tone)
- LCD shows “WATER ALERT”
- Overrides all other screens

---

### Sensor Monitoring

- **Temperature (NTC thermistor)**  
  Calculated using Beta equation model for better accuracy

- **Humidity (DHT11)**  
  Digital sensor updated every 2 seconds

- **Light intensity (LDR)**  
  Raw analog value (0–1023)

- **Water level sensor**  
  Threshold-based detection system

---

## LCD Interface (Page System)

The LCD cycles through 3 pages using a button:

### Page 0 – Temperature
Displays temperature in Celsius (°C)

### Page 1 – Humidity
Displays humidity in percentage (%)

### Page 2 – Light
Displays raw light sensor value

---

## System Behavior

1. System continuously reads sensors using `millis()` timing
2. Button changes LCD page (debounced input)
3. Water detection has highest priority
4. LCD updates every 500ms (non-blocking)
5. DHT11 updates every 2 seconds to avoid invalid readings

---

## Key Variables

| Variable | Type | Purpose |
|----------|------|----------|
| water | bool | Water alarm state |
| waterValue | int | Raw water sensor value |
| humidityValue | float | Stored humidity |
| nr_page | int | LCD page index |
| timerHum | unsigned long | Humidity timing control |
| timerWater | unsigned long | Water sensor timing |
| timerLCD | unsigned long | LCD refresh control |

---

## System Architecture

### 1. Sensor Layer
- `water_level()`
- `update_humidity()`
- `read_temperature()`
- `read_light()`

### 2. Logic Layer
- alarm detection
- page switching
- state management

### 3. UI Layer
- `writeLCD()`
- LCD page rendering
- override display (water alert)

---

## Important Notes

- DHT11 must not be polled faster than ~2 seconds
- LCD must not be cleared continuously (prevents flickering)
- All timing is handled using `millis()` (no blocking delays)
- Water alarm overrides all UI states
- Thermistor requires correct 10K divider circuit

---

## Limitations

- DHT11 has low precision (±5% humidity, ±2°C temperature)
- Thermistor requires calibration for accurate readings
- No persistent memory (data resets on restart)

---

## Future Improvements

- ESP8266 WiFi dashboard integration (IoT monitoring)
- Data logging (SD card or cloud storage)
- Graphical display upgrade (OLED/TFT)
- Automatic weather prediction logic
- Sensor calibration system