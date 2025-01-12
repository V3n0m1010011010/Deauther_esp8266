#include "icons.h"
#include "functions.h"
const String name = "ESP8266 Custom";
const String name2 = "Deauther";
const String github = "by @V3n0m1010011010";
const String inits[] = { "WiFi", "nRF24l01" };
void bootDisplay() {
  dis.clearDisplay();
  dis.setTextSize(1);
  dis.setTextColor(SH110X_WHITE);
  dis.drawBitmap(128 / 4, 0, logo, 64, 64, 1);
  dis.display();
  delay(2000);
  dis.clearDisplay();
  dis.setCursor(getCenter(name.c_str()), 10);
  dis.println(name);
  dis.setCursor(getCenter(name2.c_str()), 20);
  dis.println(name2);
  dis.setCursor(getCenter(github.c_str()), 40);
  dis.println(github);
  dis.display();
  delay(1000);
  dis.clearDisplay();
  dis.drawRoundRect(0, 0, 128, 64, 5, SH110X_WHITE);
  dis.setCursor(5, 4);
  dis.print("Initializing...");
  dis.drawLine(0, 15, 128, 15, SH110X_WHITE);
  //-------init wifi---------
  dis.setCursor(5, 20);
  dis.print(inits[0]);
  dis.display();
  for (int i = 0; i < 3; i++) {
    dis.print(".");
    dis.display();
    delay(400);
  }
  dis.print(" done");
  dis.display();
  //-------------------------
  delay(1000);
  //-------init nrf24l01---------
  dis.setCursor(5, 35);
  dis.print(inits[1]);
  dis.display();
  for (int i = 0; i < 3; i++) {
    dis.print(".");
    dis.display();
    delay(400);
  }
  delay(400);
  dis.setCursor(5, 45);
  if (radInit) {
    dis.println("detected");
  } else {
    dis.println("not detected");
  }
  dis.display();
  //-----------------------------
  delay(2000);
}