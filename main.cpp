#include "SaveSystem.h"
#include "player.h"
#include "welt.h"
#include <iostream>

int main() {
  char eingabe;
  char facing;
  char block;
  welt w;
  player p;
  saveSystem s;
  w.generateWorld();
  // gameloop
  do {
    w.showWelt(p);
    p.showInventar();
    std::cin >> eingabe;
    switch (eingabe) {
    case 'w':
      facing = 'w';
      if (!w.isBlocked(p.getY() - 1, p.getX())) {
        p.playerMovement(-1, 0);
      }
      break;

    case 's':
      facing = 's';
      if (!w.isBlocked(p.getY() + 1, p.getX())) {
        p.playerMovement(1, 0);
      }
      break;

    case 'd':
      facing = 'd';
      if (!w.isBlocked(p.getY(), p.getX() + 1)) {
        p.playerMovement(0, 1);
      }
      break;

    case 'a':
      facing = 'a';
      if (!w.isBlocked(p.getY(), p.getX() - 1)) {
        p.playerMovement(0, -1);
      }
      break;

    case 'q':
      if (w.getBlockinFront(p, facing) == '.' &&
          p.getInventar().removeItem(p.getSelected())) {
        w.placeBlock(facing, p);
      }
      break;

    case 'm':
      s.save(p, w);
      std::cout << "Game Saved.\n";
      break;

    case 'l':
      s.load(p, w);
      break;

    case '1':
      p.changeSelected(eingabe);
      break;

    case '2':
      p.changeSelected(eingabe);
      break;

    case 'e':
      block = w.getBlockinFront(p, facing);
      switch (block) {
      case 'T':
        w.breakBlock(facing, p);
        p.getInventar().addItem("wood");
        break;

      case 'S':
        w.breakBlock(facing, p);
        p.getInventar().addItem("stone");
        break;
      }
      break;
    }
  } while (eingabe != 0);

  return 0;
}
