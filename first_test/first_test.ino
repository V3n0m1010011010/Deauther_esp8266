#include <ESP8266WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#include <user_config.h>

int n;
String SSIDS[30];

void setup() {
  delay(250);
  initAll();
  delay(200);
  logoShow();
  scan();
}
void loop() {
  if (n > 0) {
    controls();
    delay(100);
  }
  displayAll();
}