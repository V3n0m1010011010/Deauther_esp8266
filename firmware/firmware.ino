#include <ESP8266WiFi.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#include <Wire.h>
#include "Menu.h"
#include "variables.h"
void setup() {
  delay(250);
  initAll();
}
void loop() {
  if(deauthing){
    deauth();
  }
  activem->handleInput();
}