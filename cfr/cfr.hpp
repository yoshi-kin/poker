# pragma once
# include <iostream>
# include <vector>
# include <map>
# include <algorithm>
# include <cassert>
# include <math.h>
# include <random>
using Strategy = std::map<History, std::map<int, double>>;
using Regret = std::map<History, std::map<int, double>>;

class CFR {
  private:
    Strategy average_strategy;
    Regret average_regret;
  public:
    CFR();
    const auto& minimize_cfr(
      Node r1, Node r2, std::string b, float p1, float p2);
};