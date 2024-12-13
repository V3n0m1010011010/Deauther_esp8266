#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#include "menu.h"
extern Adafruit_SH1106G dis;
extern decode_results results;
extern Menu* activem;
Menu::Menu(double id, const std::string& title, bool isScrollable, int buttonSelectPin, int buttonDownPin, int buttonUpPin)
  : id(id), title(title), isScrollable(isScrollable), buttonSelectPin(buttonSelectPin), buttonDownPin(buttonDownPin), buttonUpPin(buttonUpPin) {
}

void Menu::addSection(const std::string& section, std::function<void()> action) {
  sections.push_back(section);
  actions.push_back(action);
}

void Menu::render() {
  const int maxVisibleItems = 4;
  const int maxTextWidth = 18;
  static int scrollOffset = 0;
  if (selectedIndex < scrollOffset) {
    scrollOffset = selectedIndex;
  } else if (selectedIndex >= scrollOffset + maxVisibleItems) {
    scrollOffset = selectedIndex - maxVisibleItems + 1;
  }
  dis.clearDisplay();
  dis.setCursor(2, 2);
  dis.setTextSize(1.5);
  dis.print(title.c_str());
  dis.drawLine(0, 13, 128, 13, SH110X_WHITE);
  dis.setTextSize(1);
  for (int i = scrollOffset; i < std::min(scrollOffset + maxVisibleItems, (int)sections.size()); ++i) {
    int y = 20 + ((i - scrollOffset) * 10);
    if (i == selectedIndex) {
      dis.drawLine(5, y, 5, y + 5, SH110X_WHITE);
      dis.setCursor(20, y);
    } else {
      dis.setCursor(15, y);
    }
    dis.setTextColor(SH110X_WHITE);
    if (selectedList.size() > 0 && selectedList[i]) {
      dis.setTextColor(SH110X_BLACK, SH110X_WHITE);
    }
    dis.print(sections[i].substr(0, maxTextWidth).c_str());
  }
  dis.display();
}

void Menu::handleInput() {
  if (irrecv.decode(&results)) {
    bool needsRender = false;
    if (results.value == buttonDownPin && isScrollable) {
      selectedIndex = (selectedIndex + 1) % sections.size();
      needsRender = true;
    } else if (results.value == buttonUpPin && isScrollable) {
      selectedIndex = (selectedIndex - 1 + sections.size()) % sections.size();
      needsRender = true;
    } else if (results.value == buttonSelectPin) {
      actions[selectedIndex]();
    }
    if (needsRender) {
      activem->render();
    }
    irrecv.resume();
  }
}

void Menu::setSubMenu(Menu* menu) {
  subMenu = menu;
  if (menu) {
    menu->setParentMenu(this);
  }
}
void Menu::setParentMenu(Menu* menu) {
  parentMenu = menu;
}
Menu* Menu::getSubMenu() {
  return subMenu;
}

Menu* Menu::getParentMenu() {
  return parentMenu;
}

int Menu::getSelectedIndex() {
  return selectedIndex;
}
void Menu::setSelectedIndex(int index) {
  if (index >= 0 && index < sections.size()) {
    selectedIndex = index;
  } else {
    selectedIndex = 0;
  }
}
void Menu::setlist(std::vector<bool> list){
  selectedList = list;
}
std::vector<bool> Menu::getlist(){
  return selectedList;
}