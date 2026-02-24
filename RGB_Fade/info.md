# RGB Fade LED – Premium Smooth Lighting

## Overview
This project demonstrates a **smooth, continuous RGB LED color transition** controlled by an Arduino. The fade is implemented with **gamma correction (γ = 2.2)** to create a visually uniform brightness perceived by the human eye, resulting in a premium, high-quality lighting effect.

## Components
- Arduino Uno (or compatible board)  
- Common-cathode RGB LED  
- 3 × 220Ω resistors  
- Breadboard and jumper wires  

## Circuit Connections
- **Red pin → Arduino digital 6**  
- **Green pin → Arduino digital 5**  
- **Blue pin → Arduino digital 3**  
- Each LED pin is connected in series with a resistor  
- LED cathode connected to **GND**

## Code
- `rgb_fold.ino` – main sketch  
- Uses a `gamma()` function for perceptual linearization of PWM values  
- Color sequence: **Red → Blue → Green → Red**  

```cpp
// Example snippet
analogWrite(RED, gamma(redValue));
analogWrite(GREEN, gamma(greenValue));
analogWrite(BLUE, gamma(blueValue));