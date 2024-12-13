#ifndef MENU_H
#define MENU_H
#include <vector>
#include <string>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
extern Adafruit_SH1106G dis;
extern IRrecv irrecv;
extern decode_results results;
class Menu {
private:
  int id;
  std::string title;
  std::vector<std::string> sections;
  std::vector<std::function<void()>> actions;
  size_t selectedIndex = 0;
  int buttonSelectPin;
  int buttonDownPin;
  int buttonUpPin;
  bool isScrollable;
  std::vector<bool> selectedList;
  Menu* subMenu = nullptr;
  Menu* parentMenu = nullptr;
public:
  Menu(double id, const std::string& title, bool isScrollable, int buttonSelectPin, int buttonDownPin, int buttonUpPin);
  void addSection(const std::string& section, std::function<void()> action = nullptr);
  virtual void render();
  void handleInput();

  void setParentMenu(Menu* menu);
  Menu* getParentMenu();
  void setSubMenu(Menu* menu);
  Menu* getSubMenu();

  int getSelectedIndex();
  void setSelectedIndex(int index);

  void setlist(std::vector<bool> list);
  std::vector<bool> getlist();
};
#endif
