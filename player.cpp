#include "player.h"
#include "inventar.h"

player::player() {

  y = 5;
  x = 5;
  selected = '1';
}

void player::playerMovement(int dy, int dx) {

  y += dy;
  x += dx;
}

int player::getX() const { return x; }

int player::getY() const { return y; }

void player::showInventar() { inv.showVector(); }

inventar &player::getInventar() { return inv; }

void player::changeSelected(char select) { selected = select; }

char player::getSelected() const { return selected; }
