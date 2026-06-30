#pragma once

#include "player.h"
#include <fstream>
class welt {

private:
  char welt[10][10] = {{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                       {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
                       {'#', 'S', '.', '.', '.', '.', '.', '.', '.', '#'},
                       {'#', '.', 'T', '.', '.', '.', '.', 'T', '.', '#'},
                       {'#', '.', '.', '.', '.', 'S', '.', '.', '.', '#'},
                       {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
                       {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
                       {'#', '.', '.', 'T', '.', '.', '.', '.', 'S', '#'},
                       {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
                       {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};

public:
  void showWelt(const player &p);
  bool isBlocked(int y, int x);
  char getBlockinFront(const player &p, char facing);
  void breakBlock(char facing, const player &p);
  void placeBlock(char facing, const player &p);
  void saveWelt(std::ofstream &datei) const;
  void loadWelt(std::ifstream &datei);
};
