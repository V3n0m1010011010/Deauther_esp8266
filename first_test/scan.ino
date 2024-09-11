void scan(){
  display.println("Scanning...");
  display.display();
  delay(500);
  n = WiFi.scanNetworks();
  if (n != 0) {
    for (int i = 0; i < n; ++i) {
      SSIDS[i] = WiFi.SSID(i);
      SSID_counter++;
    }
  }
  display.clearDisplay();
  display.display();
}