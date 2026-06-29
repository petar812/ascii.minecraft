#include "inventar.h"

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
