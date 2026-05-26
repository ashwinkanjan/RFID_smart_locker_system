# RFID Smart Locker System

An RFID-based smart locker system developed using Arduino UNO.  
The system allows access only to authorized RFID cards. When a valid RFID card is scanned, the servo motor rotates to unlock the locker. Unauthorized cards are denied access.

---

## Features

- RFID based authentication
- Servo motor based locking mechanism
- LCD display status messages
- Access granted / access denied system
- Arduino UNO implementation
- Wokwi simulation support

---

## Components Used

- Arduino UNO
- MFRC522 RFID Reader Module
- RFID Card / Tag
- Servo Motor (SG90)
- 16x2 LCD Display with I2C Module
- Jumper Wires
- Breadboard

---

## Circuit Connections

### RFID RC522 Connections

| RC522 Pin | Arduino UNO Pin |
|---|---|
| SDA | D10 |
| SCK | D13 |
| MOSI | D11 |
| MISO | D12 |
| RST | D9 |
| GND | GND |
| 3.3V | 3.3V |

---

### LCD 16x2 I2C Connections

| LCD Pin | Arduino UNO Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

---

### Servo Motor Connections

| Servo Pin | Arduino UNO Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| Signal | D6 |

---

## Working Principle

1. The RFID reader waits for an RFID card.
2. When a card is scanned, the Arduino checks the UID.
3. If the UID matches the authorized RFID card:
   - LCD displays "Access Granted"
   - Servo motor rotates to 90°
   - Locker unlocks temporarily
4. If the UID does not match:
   - LCD displays "Access Denied"
   - Locker remains locked

---

## Arduino Libraries Used

```cpp
SPI.h
MFRC522.h
Wire.h
LiquidCrystal_I2C.h
Servo.h
```

## Wokvi circuit simulation

Follow the link for the circuit simulations. 
https://wokwi.com/projects/465107374252156929

## Future Improvements

- Fingerprint authentication
- Mobile app control
- IoT monitoring
- EEPROM based user storage
- Password + RFID authentication
- Solenoid lock integration

## Applications

- Smart lockers
- Office access systems
- Home security systems
- RFID based access control
- Industrial locker systems


## Keywords

Arduino ,RFID ,Smart Locker ,Embedded Systems ,IoT ,Servo Motor, Access Control , Wokwi 
