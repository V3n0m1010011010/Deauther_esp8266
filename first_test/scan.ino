void scan(){
  int n = WiFi.scanNetworks();
  if (n == 0) {
    display.println("no networks");
    display.display();
  } else {
    for (int i = 0; i < n; ++i) {
      SSIDS[i] = WiFi.SSID(i);
      SSID_counter++;
    }
  }
}