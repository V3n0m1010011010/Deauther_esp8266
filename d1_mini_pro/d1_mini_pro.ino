// Wifi library for esp8266
#include <ESP8266WiFi.h>
//-------------------------
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#include <algorithm>
#include <RF24.h>
#include <nRF24L01.h>
#include <Wire.h>
#include <SPI.h>
#include "Menu.h"
#include "variables.h"
void setup() {
  delay(250);
  initAll();
}
void loop() {
  if (deauthing) {
    deauth();
  }
  if (jamming) {
    Jammer();
  }
  if (monitor) {
    packetMonitor();
  }
  activem->handleInput();
}
