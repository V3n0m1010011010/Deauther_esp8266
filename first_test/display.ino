void logoShow(){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.drawBitmap(128 / 4, 0,  logo, 64, 64, 1);
  display.display();
  delay(3000);
  display.clearDisplay();
  display.setCursor(0,0);
  display.display();
}
void pointerF(){
  display.drawLine(0, 2 + 10 * pointer, 0, 7 + 10 * pointer, SH110X_WHITE);
}
void selector(){
}
void displayAll(){
  display.clearDisplay();
  for (int i = 0; i < 6; i++) {
    pointerF();
    display.setCursor(10, first_item_pos + (10 * i) + 2);
    display.println(SSIDS[i + shift]);
  }
  display.display();
}