void initAll() {
  Serial.begin(115200);
  Wire.begin(4, 5);
  SPI.begin();
  // dis.begin(ic2_adress);
  dis.begin();
  wifi_set_opmode(0x01);
  wifi_set_channel(1);
  if (rad.begin()) {
    Serial.println("Success");
    rad.setDataRate(RF24_2MBPS);
    rad.setPALevel(RF24_PA_MAX, true);
    rad.stopListening();
    radInit = true;
  } else {
    Serial.println("Fail");
  }
  bootDisplay();
  mainMenu();
  scanMenu();
  selectMenu();
  attackMenu();
  deauthMenu();
  if(radInit)jammerMenu();
  snifferMenu();
  packetMonitorMenu();
  mainm->setSubMenu(scanm);
  mainm->setSubMenu(selectm);
  mainm->setSubMenu(attackm);
  mainm->setSubMenu(snifferm);
  scanm->setSubMenu(apScanm);
  scanm->setSubMenu(stScanm);
  attackm->setSubMenu(deauthm);
  if(radInit)attackm->setSubMenu(jammerm);
  snifferm->setSubMenu(packetMonitorm);
  selectedApList.resize(apList.size(), false);
  selectedStList.resize(stList.size(), false);
  activem = mainm;
  activem->render();
  irrecv.enableIRIn();
}