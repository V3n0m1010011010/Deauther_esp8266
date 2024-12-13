//----------------------------------------------------MAIN MENU--------------------------------------------------------------------

void mainMenu() {
  mainm = new Menu(0.0, "Main Menu", true, c, down, up);
  mainm->addSection("Scannen", []() {
    activem = scanm;
    activem->setSelectedIndex(0);
    activem->render();
  });
  mainm->addSection("Select", []() {
    activem = selectm;
    activem->setSelectedIndex(0);
    activem->render();
  });
  mainm->addSection("Attack", []() {
    activem = attackm;
    activem->setSelectedIndex(0);
    activem->render();
  });
}

//----------------------------------------------------END MAIN MENU--------------------------------------------------------------------




//----------------------------------------------------Scan MENUs--------------------------------------------------------------------

void scanMenu() {
  scanm = new Menu(1, "Scan Menu", true, c, down, up);
  scanm->addSection("Back", []() {
    activem = scanm->getParentMenu();
    activem->setSelectedIndex(0);
    activem->render();
  });
  scanm->addSection("AP scan", []() {
    apscanm();
    activem = apScanm;
    activem->render();
    scanAps();
  });
  scanm->addSection("ST scan", []() {
    stscanm();
    activem = stScanm;
    activem->render();
    scanSts();
  });
}




void apscanm() {
  apScanm = new Menu(1.1, "Scanning APs...", true, c, down, up);
  scanm->setSubMenu(apScanm);
}

void stscanm() {
  stScanm = new Menu(1.2, "Scanning STs...", true, c, down, up);
  scanm->setSubMenu(stScanm);
}

//----------------------------------------------------END Scan MENUs--------------------------------------------------------------------



//----------------------------------------------------Select MENUs--------------------------------------------------------------------

void selectMenu() {
  selectm = new Menu(2, "Select Menu", true, c, down, up);
  selectm->addSection("Back", []() {
    activem = selectm->getParentMenu();
    activem->setSelectedIndex(0);
    activem->render();
  });
  selectm->addSection("APs", []() {
    selectMenuAp();
    activem = selectAp;
    activem->setSelectedIndex(0);
    activem->render();
  });
  selectm->addSection("STs", []() {
    selectMenuSt();
    activem = selectSt;
    activem->setSelectedIndex(0);
    activem->render();
  });
}



void selectMenuAp() {
  selectAp = new Menu(2.1, "Select Menu     APs", true, c, down, up);
  selectAp->addSection("Back", []() {
    activem = selectAp->getParentMenu();
    activem->setSelectedIndex(0);
    activem->render();
  });
  if (firstApScan) {
    selectedApList.resize(apList.size(), false);
    for (int i = 0; i < apList.size(); i++) {
      selectAp->addSection(apList[i].ssid.c_str(), [i]() {
        selectedApList[i] = !selectedApList[i];
        for (int j = 0; j < apList.size(); j++) {
          Serial.println(selectedApList[j]);
        }
      });
    }
  }
  selectm->setSubMenu(selectAp);
}



void selectMenuSt() {
  selectSt = new Menu(2.2, "Select Menu     STs", true, c, down, up);
  selectSt->addSection("Back", []() {
    activem = selectSt->getParentMenu();
    activem->setSelectedIndex(0);
    activem->render();
  });
  for (int i = 0; i < stList.size(); i++) {
    selectSt->addSection(((selectedApList[i] ? "*" : " ") + stList[i].ssid).c_str(), [i]() {
      selectedStList[i] = !selectedStList[i];
    });
  }
  selectm->setSubMenu(selectSt);
}
//----------------------------------------------------END Select MENUs--------------------------------------------------------------------
