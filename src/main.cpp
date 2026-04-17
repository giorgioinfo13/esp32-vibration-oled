#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

constexpr uint8_t VIBRATION_PIN = 4;  // Digital vibration sensor output

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void drawStatusScreen(bool vibrationDetected) {
  u8g2.clearBuffer();
  u8g2.drawStr(0, 10, "Vibration Sensor");
  u8g2.drawHLine(0, 12, 128);

  u8g2.setCursor(0, 30);
  u8g2.print("Status: ");
  u8g2.print(vibrationDetected ? "DETECTED!" : "Quiet");

  u8g2.sendBuffer();
}

void setup() {
  Serial.begin(115200);
  pinMode(VIBRATION_PIN, INPUT);
  
  u8g2.begin();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  drawStatusScreen(false);
}

void loop() {
  const bool vibrationDetected = digitalRead(VIBRATION_PIN);
  
  Serial.print("Vibration: ");
  Serial.println(vibrationDetected ? "DETECTED" : "No vibration");

  drawStatusScreen(vibrationDetected);
  
  delay(100);  // Short delay to reduce chatter from the digital output
}
