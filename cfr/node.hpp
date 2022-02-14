# pragma once
# include <iostream>
# include <vector>
# include <map>
# include <sstream>
# include <algorithm>
# include <cassert>
# include <math.h>
# include <random>
# include "information_set.hpp"
using InformationList = std::vector<InformationSet>;

enum Actions {
  FOLD,
  CHECK,
  CALL,
  BET,
  ALL
};

class Node {
  public:
    static InformationList info_list;
    int stage;
    int pot_size;
    double utility;
    double reach_probability;
    std::vector<int> action_history;
    InformationList get_information_list();
};

class ChanceNode: public Node {
  public:
    ChanceNode(int pot_size, int stage, double reach_probability);
    std::vector<Card> deal_card(int card_num);
};

class PlayerNode: public Node {
  public:
    int agent_stack;
    int opp_stack;
    PlayerNode(int pot_size, int stage, int stack, double reach_probability);
};

class TerminalNode: public Node {
  public:
    TerminalNode(int pot_size, double reach_probability);
};