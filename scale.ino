#include <Arduino.h>
#include "weight.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 32 
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define OLED_SCK_PIN 9
#define OLED_SDA_PIN 8

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("Hello");
  Wire.begin(OLED_SDA_PIN, OLED_SCK_PIN);
  // WiFi.begin("Sơn 's S22", "9999999999");

  // if(WiFi.status() == WL_CONNECTED){
  //   Serial.println("Wifi connected!");
  //   Serial.println(WiFi.localIP());
  // }

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); 
  }

  display.clearDisplay();
  display.display();
  delay(100);

  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);             
  display.display();
  delay(100);
  
  display.print("MIMO Scale");
  display.display();
  display.setTextSize(1);             

  setup_hx711();
  delay(1000);
}

void loop() {
  Serial.println(".");
  loop_hx711();

  display.clearDisplay();
  display.display();

  display.setCursor(2,0);
  display.print(loadcell_values[0]);
  display.print(", ");
  display.print(loadcell_values[1]);
  display.print(", ");
  display.print(loadcell_values[2]);
  display.print(", ");
  display.print(loadcell_values[3]);
  display.println();
  display.display();
  delay(1000);  
}