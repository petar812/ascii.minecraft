#pragma once
#include <fstream>
#include <string>
#include <vector>

class inventar {

private:
  std::vector<std::string> inventar;

public:
  void showVector();
  void addItem(std::string item);
  bool removeItem(char selectedItem);
  void saveInv(std::ofstream &datei) const;
  void loadInv(std::ifstream &datei);
};
