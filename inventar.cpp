#include "inventar.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void inventar::showVector() {
  int increment = 1;
  for (std::string &i : inventar) {
    std::cout << increment << ": " << i << " ";
    increment++;
  }
  std::cout << "\n";
}

void inventar::addItem(std::string item) { inventar.push_back(item); }

bool inventar::removeItem(char selectedItem) {
  std::string item;
  int len = inventar.size();

  if (selectedItem == '1') {
    item = "wood";
  } else if (selectedItem == '2') {
    item = "stone";
  }

  for (int i = 0; i < len; i++) {
    if (inventar[i] == item) {
      inventar.erase(inventar.begin() + i);
      return true;
      break;
    }
  }
  return false;
}

void inventar::saveInv(std::ofstream &datei) const {
  int len = inventar.size();
  datei << "INVENTAR\n";
  for (int i = 0; i < len; i++) {
    datei << inventar[i] << "\n";
  }
}

void inventar::loadInv(std::ifstream &datei) {
  std::string zeile;
  inventar.clear();
  while (std::getline(datei, zeile)) {
    if (zeile == "INVENTAR") {
      break;
    }
  }
  while (std::getline(datei, zeile)) {
    inventar.push_back(zeile);
  }
}
