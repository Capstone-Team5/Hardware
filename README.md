# Braille Display with Arduino and Bluetooth

## Project Overview
This project implements a real-time Braille display using an Arduino and 6 LEDs. The input, which includes English letters, numbers, and Korean characters, is provided in hexadecimal format. The corresponding Braille dots are displayed using the LEDs.

## Required Hardware
- **Arduino Board (Arduino Uno)**
- **6 LEDs**
- **6 Resistors (220Ω)**
- **Bluetooth Module (HC-06)**
- **Switch**

## Circuit Setup
1. Connect the 6 LEDs to the Arduino Uno using the appropriate resistors (220Ω).
2. Use digital pins on the Arduino for controlling the LEDs.
3. Connect the Bluetooth module (HC-06) to the Arduino to receive hexadecimal input via Bluetooth.

## How to Use
1. Upload the Arduino code to the Arduino Uno.
2. Pair your Bluetooth device (e.g., a smartphone or PC) with the HC-06 module.
3. Send hexadecimal values corresponding to Braille characters via Bluetooth.
4. The Arduino will process the input and light up the appropriate LEDs to represent the Braille dots.

## Example Input
- Send hexadecimal values like `AC00` for letter `a` or `ABC` for number `9`.
- You can send mixed string like `AC00a' or '1223abc`.
- The Arduino will translate these values into Braille patterns and display them on the LEDs.

## Notes
- The mapping between hexadecimal values and Braille patterns can be customized.
- This setup supports real-time input via Bluetooth, allowing users to dynamically change the displayed Braille.

## Hardware Circuit Diagram
<img src="https://github.com/user-attachments/assets/dfe87496-3b8e-41f6-9987-fba92327f73f" width="400" />






