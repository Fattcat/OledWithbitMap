#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET -1
Adafruit_SSD1306 display(OLED_RESET);

// [+] --------------------- [+]
// Pripojenie pinov :
// OLED -> Arduino Nano
// VCC  -> 5V
// GND  -> GND
// SCL  -> A5
// SDA  -> A4
// [+] --------------------- [+]

const unsigned char myBitmap [] PROGMEM = {
  0xfb, 0xff, 0xff, 0xf7, 0x80, 
  0xf3, 0xff, 0xff, 0xe7, 0x80, 
  0xe7, 0xff, 0xff, 0xf3, 0x80, 
  0xc7, 0xff, 0xff, 0xf3, 0x80, 
  0xcf, 0xff, 0xff, 0x79, 0x80, 
  0xcf, 0x3f, 0xfe, 0x78, 0x80, 
  0x9e, 0x7f, 0xff, 0x3c, 0x80, 
  0x9e, 0x7f, 0xff, 0x3c, 0x80, 
  0x3c, 0xff, 0xbf, 0x9c, 0x80, 
  0x3c, 0xe7, 0xf5, 0x9e, 0x00, 
  0x39, 0xe7, 0xe3, 0x9e, 0x00, 
  0x3c, 0xe7, 0xf3, 0xde, 0x00, 
  0x39, 0xee, 0x7b, 0xce, 0x00, 
  0x39, 0xce, 0x39, 0xce, 0x00, 
  0x7d, 0xee, 0x33, 0xde, 0x00, 
  0x39, 0xc6, 0x79, 0xce, 0x00, 
  0x3d, 0xe7, 0xf3, 0xde, 0x00, 
  0x38, 0xe7, 0xe3, 0x8e, 0x00, 
  0xbd, 0xf7, 0x77, 0x9e, 0x80, 
  0x9c, 0xff, 0x7f, 0xbc, 0x80, 
  0x9e, 0x7e, 0x3f, 0x1c, 0x80, 
  0x9e, 0x7e, 0x3f, 0x3d, 0x80, 
  0xcf, 0x3e, 0x3e, 0x79, 0x80, 
  0xcf, 0x7c, 0x3f, 0xf9, 0x80, 
  0xe7, 0xfc, 0x1f, 0xf3, 0x80, 
  0xe7, 0xfc, 0x1f, 0xf3, 0x80, 
  0xf3, 0xf8, 0x1f, 0xe7, 0x80, 
  0xf7, 0xf8, 0x0f, 0xe7, 0x80, 
  0xff, 0xf8, 0x0f, 0xff, 0x80, 
  0xff, 0xf8, 0x0f, 0xff, 0x80, 
  0xff, 0xf0, 0x07, 0xff, 0x80, 
  0xff, 0xf0, 0x0f, 0xff, 0x80, 
  0xff, 0xe0, 0x07, 0xff, 0x80
};

void setup() {
  // Inicializace OLED displeje s I2C adresou 0x3D
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  delay(2000);
}

void loop() {
  // Zobrazte bitmapu na OLED displeji na pozici (0, 0) s šířkou 120 a výškou 60 pixelů
  display.drawBitmap(0, 0, myBitmap, 120, 60, WHITE);
  display.display();
}
