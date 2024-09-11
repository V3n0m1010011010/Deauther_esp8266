#include "logo.h"
#define i2c_Address 0x3c
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void logoShow() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.drawBitmap(128 / 4, 0, logo, 64, 64, 1);
  display.display();
  delay(3000);
  display.clearDisplay();
  display.setCursor(0, 0);
  display.display();
}
void pointerF() {
  display.drawLine(0, 3 + 10 * pointer, 0, 8 + 10 * pointer, SH110X_WHITE);
}
void displayAll() {
  if (n > 0) {
    display.clearDisplay();
    for (int i = 0; i < 6; i++) {
      pointerF();
      if (i == pointer) {
        display.setCursor(18, first_item_pos + (10 * i) + 2);
        if (isSelected) {
          display.setTextColor(SH110X_BLACK, SH110X_WHITE);
        }
        display.println(SSIDS[i + shift].substring(0, 16));
      } else {
        display.setCursor(13, first_item_pos + (10 * i) + 2);
        display.setTextColor(SH110X_WHITE);
        display.println(SSIDS[i + shift].substring(0, 16));
      }
    }
    display.display();
  } else {
    display.clearDisplay();
    display.setCursor(0,0);
    display.print("0 Networks found");
    display.display();
  }
}