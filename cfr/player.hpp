# pragma once
# include <iostream>
# include <vector>
# include <map>
# include <sstream>
# include <algorithm>
# include <cassert>
# include <math.h>
# include <random>

struct Player {
  int stack;
  std::vector<InformationSet> infomation_partition;
  Player();
};