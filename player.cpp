#include "player.h"
#include "inventar.h"
#include <cstddef>
#include <fstream>
#include <string>

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

const inventar &player::getInventar() const { return inv; }

inventar &player::getInventar() { return inv; }

void player::changeSelected(char select) { selected = select; }

char player::getSelected() const { return selected; }

void player::savePlayer(std::ofstream &datei) const {

  datei << "PLAYER\n"
        << "Y: " << y << "\n"
        << "X: " << x << "\n"
        << "selected: " << selected << "\n";
}

void player::loadPlayer(std::ifstream &datei) {
  std::string zeile;

  std::getline(datei, zeile); // PLAYER

  std::getline(datei, zeile); // Y
  size_t pos = zeile.find(':');
  if (pos != std::string::npos) {
    std::string wertY = zeile.substr(pos + 2);
    y = std::stoi(wertY);
  }

  std::getline(datei, zeile); // X
  pos = zeile.find(':');
  if (pos != std::string::npos) {
    std::string wertX = zeile.substr(pos + 2);
    x = std::stoi(wertX);
  }

  std::getline(datei, zeile); // selected
  pos = zeile.find(':');
  if (pos != std::string::npos) {
    selected = zeile.substr(pos + 2)[0];
  }
}
