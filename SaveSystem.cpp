#include "SaveSystem.h"
#include "inventar.h"
#include "player.h"
#include "welt.h"

#include <fstream>

void saveSystem::save(const player &p, const welt &w) {
  std::ofstream dateiName("save.txt");
  p.savePlayer(dateiName);
  w.saveWelt(dateiName);
  p.getInventar().saveInv(dateiName);
  dateiName.close();
}

void saveSystem::load(player &p, welt &w) {
  std::ifstream dateiName("save.txt");
  p.loadPlayer(dateiName);
  w.loadWelt(dateiName);
  p.getInventar().loadInv(dateiName);
  dateiName.close();
}
