void createPacket(uint8_t *bssid){
  for(int i = 0; i < 6; i++){
    deauthPacket[10 + i] = deauthPacket[16 + i] = bssid[i];
  }
}