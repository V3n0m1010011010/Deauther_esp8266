void initAll(){
  display.begin(i2c_Address, true);
  irrecv.enableIRIn();
  wifi_set_opmode(0x01);
  wifi_set_channel(1);
}