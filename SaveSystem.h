#pragma once
#include "inventar.h"
#include "player.h"
#include "welt.h"

#include <string>
class saveSystem {

private:
  const std::string dateiName;

public:
  void save(const player &, const welt &);
  void load(player &, welt &);
};
