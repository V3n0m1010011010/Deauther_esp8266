void scanAps() {
  firstApScan = true;
  apList.clear();
  WiFi.mode(WIFI_STA);
  int n = WiFi.scanNetworks();
  for (int i = 0; i < n; ++i) {
    String ssid = WiFi.SSID(i);
    uint8_t* bssid = WiFi.BSSID(i);
    bool exists = false;
    for (const auto& ap : apList) {
      if (ap.ssid == ssid && ap.bssid == bssid) {
        exists = true;
        break;
      }
    }
    if (!exists) {
      apList.push_back({ ssid, bssid });
    }
  }
  activem->addSection(("Found " + String(n) + " APs").c_str());
  activem->render();
  delay(1000);
  activem = apScanm->getParentMenu();
  activem->render();
}
void scanSts() {
  stList.clear();
  WiFi.mode(WIFI_AP_STA);
  int n = WiFi.scanNetworks();
  for (int i = 0; i < n; ++i) {
    String ssid = WiFi.SSID(i);
    uint8_t* bssid = WiFi.BSSID(i);
    int rssi = WiFi.RSSI(i);
    bool exists = false;
    for (const auto& station : stList) {
      if (station.ssid == ssid && station.bssid == bssid) {
        exists = true;
        break;
      }
    }
    if (!exists) {
      stList.push_back({ ssid, bssid, rssi });
    }
  }
  activem->addSection(("Found " + String(n) + " STs").c_str());
  activem->render();
  delay(1000);
  activem = stScanm->getParentMenu();
  activem->render();
}