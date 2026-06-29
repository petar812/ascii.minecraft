#pragma once
#include "inventar.h"

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
  inventar &getInventar();
  void changeSelected(char select);
  char getSelected() const;
};
