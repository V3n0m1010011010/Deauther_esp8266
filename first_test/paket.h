uint8_t deauthPacket[26] = {
      /*  0 - 1  */ 0xC0, 0x00, //Frame-Typ
      /*  2 - 3  */ 0x00, 0x00, //Zeitspanne
      /*  4 - 9  */ 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, //Ziel-Adresse
      /* 10 - 15 */ 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, //Quell-Adresse
      /* 16 - 21 */ 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, //Indentifizierungs-Adresse
      /* 22 - 23 */ 0x00, 0x01, //Sequenz-nummer
      /* 24 - 25 */ 0x01, 0x00 //Reason-code
<<<<<<< HEAD
};
=======
};
>>>>>>> bbe58e329e037081869622cc17c492fd1640deed
