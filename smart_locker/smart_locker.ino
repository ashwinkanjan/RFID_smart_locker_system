#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);

LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo lockServo;

// Authorized RFID Card UID
byte authorizedCard[4] = {0x63, 0xA9, 0xF2, 0x1A};

void setup() {

  Serial.begin(9600);

  SPI.begin();

  rfid.PCD_Init();

  lcd.init();

  lcd.backlight();

  lockServo.attach(6);

  // Locker initially locked
  lockServo.write(0);

  lcd.setCursor(0,0);
  lcd.print("Smart Locker");

  lcd.setCursor(0,1);
  lcd.print("System Ready");

  delay(2000);

  lcd.clear();
}

void loop() {

  lcd.setCursor(0,0);
  lcd.print("Scan your card");

  // Wait until RFID card is tapped
  if (!rfid.PICC_IsNewCardPresent()) {
    return;
  }

  if (!rfid.PICC_ReadCardSerial()) {
    return;
  }

  bool accessGranted = true;

  // Compare scanned UID with authorized UID
  for (int i = 0; i < 4; i++) {

    if (rfid.uid.uidByte[i] != authorizedCard[i]) {

      accessGranted = false;

      break;
    }
  }

  lcd.clear();

  // Authorized card detected
  if (accessGranted) {

    lcd.setCursor(0,0);

    lcd.print("Access Granted");

    // Unlock locker
    lockServo.write(90);

    delay(3000);

    // Lock again
    lockServo.write(0);

    lcd.clear();

    lcd.setCursor(0,0);

    lcd.print("Scan your card");

    delay(2000);
  }

  // Unauthorized card
  else {

    lcd.setCursor(0,0);

    lcd.print("Access Denied");

    delay(2000);
  }

  lcd.clear();

  // Stop reading current card
  rfid.PICC_HaltA();
}