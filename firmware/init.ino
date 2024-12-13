#include "logo.h"
void initAll(){
  Serial.begin(115200);
  dis.begin(i2c_Address);
  wifi_set_opmode(0x01);
  wifi_set_channel(1);
  logoShow();
  mainMenu();
  scanMenu();
  selectMenu();
  mainm->setSubMenu(scanm);
  mainm->setSubMenu(selectm);
  mainm->setSubMenu(attackm);
  scanm->setSubMenu(apScanm);
  scanm->setSubMenu(stScanm);
  activem = mainm;
  activem->render();
  irrecv.enableIRIn();
}
void logoShow() {
  dis.clearDisplay();
  dis.setTextSize(1);
  dis.setTextColor(SH110X_WHITE);
  dis.drawBitmap(128 / 4, 0, logo, 64, 64, 1);
  dis.display();
  delay(3000);
  dis.clearDisplay();
  dis.setCursor(0, 0);
  dis.display();
}