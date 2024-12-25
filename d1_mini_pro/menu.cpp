#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#include "menu.h"
extern Adafruit_SH1106G dis;
extern decode_results results;
extern Menu* activem;
Menu::Menu(double id, const std::string& title, bool isScrollable, int buttonSelectPin, int buttonDownPin, int buttonUpPin, std::function<void()> aDown, std::function<void()> aUp)
  : id(id), title(title), isScrollable(isScrollable), buttonSelectPin(buttonSelectPin), buttonDownPin(buttonDownPin), buttonUpPin(buttonUpPin), aDown(aDown), aUp(aUp) {
}

void Menu::addSection(const std::string& section, std::function<void()> action) {
  sections.push_back(section);
  actions.push_back(action);
}

void Menu::render() {
  const int maxVisibleItems = 3;
  const int maxTextWidth = 12;
  static int scrollOffset = 0;
  if (selectedIndex < scrollOffset) {
    scrollOffset = selectedIndex;
  } else if (selectedIndex >= scrollOffset + maxVisibleItems) {
    scrollOffset = selectedIndex - maxVisibleItems + 1;
  }
  dis.clearDisplay();
  dis.setTextColor(SH110X_WHITE);
  dis.drawRoundRect(0, 0, 128, 64, 5, SH110X_WHITE);
  dis.setCursor(5, 4);
  dis.setTextSize(1.5);
  dis.print(title.c_str());
  dis.drawLine(0, 15, 128, 15, SH110X_WHITE);
  dis.setTextSize(1);


  for (int i = scrollOffset; i < std::min(scrollOffset + maxVisibleItems, (int)sections.size()); ++i) {
    int y = 21 + ((i - scrollOffset) * 14);
    int16_t x1, y1;
    uint16_t textWidth, textHeight;
    dis.getTextBounds(sections[i].substr(0, maxTextWidth).c_str(), 0, 0, &x1, &y1, &textWidth, &textHeight);
    uint16_t center = (128 - textWidth) / 2;
    if (i == selectedIndex) {
      dis.fillRoundRect(10, y - 2, 108, 12, 8, SH110X_WHITE);
      dis.setCursor(center, y);
      dis.setTextColor(SH110X_BLACK, SH110X_WHITE);
    } else {
      dis.setTextColor(SH110X_WHITE);
      dis.drawRoundRect(20, y - 2, 88, 12, 8, SH110X_WHITE);
      dis.setCursor(center, y);
    }
    dis.print(sections[i].substr(0, maxTextWidth).c_str());
  }
  dis.display();
}

void Menu::handleInput() {
  if (irrecv.decode(&results)) {
    bool needsRender = false;
    if (results.value == buttonDownPin && isScrollable) {
      if (aDown == nullptr) {
        selectedIndex = (selectedIndex + 1) % sections.size();
        needsRender = true;
      } else {
        aDown();
      }
    } else if (results.value == buttonUpPin && isScrollable) {
      if (aUp == nullptr) {
        selectedIndex = (selectedIndex - 1 + sections.size()) % sections.size();
        needsRender = true;
      }else{
        aUp();
      }
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
void Menu::setlist(std::vector<bool> list) {
  selectedList = list;
}
std::vector<bool> Menu::getlist() {
  return selectedList;
}
void Menu::setTitle(std::string t) {
  title = t;
}
std::string Menu::getTitle() {
  return title;
}
void Menu::setSection(std::string t, int i) {
  sections[i] = t;
}
std::string Menu::getSection(int i) {
  return sections[i];
}
void Menu::setScroll(bool scroll) {
  isScrollable = scroll;
}