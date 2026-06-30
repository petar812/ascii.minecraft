#include "welt.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

void welt::generateWorld() {
  generateBlocks('T', 8);
  generateBlocks('S', 4);
}

void welt::generateBlocks(char block, int amount) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distY(1, 8);
  std::uniform_int_distribution<int> distX(1, 8);

  int blocks = 0;
  while (blocks < amount) {

    int y = distY(gen);
    int x = distX(gen);

    if (welt[y][x] == '.') {
      welt[y][x] = block;
      blocks++;
    }
  }
}

void welt::showWelt(const player &p) {
  system("clear");

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (i == p.getY() && j == p.getX()) {
        std::cout << " P ";
      } else {
        std::cout << " " << welt[i][j] << " ";
      }
    }
    std::cout << "\n";
  }
}

bool welt::isBlocked(int y, int x) {
  if (welt[y][x] == '#' || welt[y][x] == 'T' || welt[y][x] == 'S') {
    return true;
  } else {
    return false;
  }
}

char welt::getBlockinFront(const player &p, char facing) {
  switch (facing) {
  case 'w':
    return welt[p.getY() - 1][p.getX()];
    break;

  case 's':
    return welt[p.getY() + 1][p.getX()];
    break;

  case 'd':
    return welt[p.getY()][p.getX() + 1];
    break;

  case 'a':
    return welt[p.getY()][p.getX() - 1];
    break;
  }
  return '.';
}

void welt::breakBlock(char facing, const player &p) {
  switch (facing) {
  case 'w':
    welt[p.getY() - 1][p.getX()] = '.';
    break;

  case 's':
    welt[p.getY() + 1][p.getX()] = '.';
    break;

  case 'd':
    welt[p.getY()][p.getX() + 1] = '.';
    break;

  case 'a':
    welt[p.getY()][p.getX() - 1] = '.';
    break;
  }
}

void welt::placeBlock(char facing, const player &p) {
  char selectedBlock = p.getSelected();

  switch (selectedBlock) {
  case '1':
    switch (facing) {
    case 'w':
      welt[p.getY() - 1][p.getX()] = 'T';
      break;

    case 's':
      welt[p.getY() + 1][p.getX()] = 'T';
      break;

    case 'd':
      welt[p.getY()][p.getX() + 1] = 'T';
      break;

    case 'a':
      welt[p.getY()][p.getX() - 1] = 'T';
      break;
    }
    break;

  case '2':
    switch (facing) {
    case 'w':
      welt[p.getY() - 1][p.getX()] = 'S';
      break;

    case 's':
      welt[p.getY() + 1][p.getX()] = 'S';
      break;

    case 'd':
      welt[p.getY()][p.getX() + 1] = 'S';
      break;

    case 'a':
      welt[p.getY()][p.getX() - 1] = 'S';
      break;
    }
    break;
  }
}

void welt::saveWelt(std::ofstream &datei) const {
  datei << "WELT\n";
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      datei << welt[i][j];
    }
    datei << "\n";
  }
}

void welt::loadWelt(std::ifstream &datei) {
  std::string zeile;
  while (std::getline(datei, zeile)) {
    if (zeile == "WELT") {
      break;
    }
  }
  for (int i = 0; i < 10; i++) {
    std::getline(datei, zeile);
    for (int j = 0; j < 10; j++) {
      welt[i][j] = zeile[j];
    }
  }
}
