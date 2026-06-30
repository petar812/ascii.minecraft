#pragma once
#include "inventar.h"
#include <fstream>

class player {

private:
  int x;
  int y;
  inventar inv;
  char selected;

public:
  player();
  void playerMovement(int dy, int dx);
  int getX() const;
  int getY() const;
  void showInventar();
  const inventar &getInventar() const;
  inventar &getInventar();
  void changeSelected(char select);
  char getSelected() const;
  void savePlayer(std::ofstream &datei) const;
  void loadPlayer(std::ifstream &datei);
};
