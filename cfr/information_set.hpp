# pragma once
# include <iostream>
# include <vector>
# include <map>
# include <sstream>
# include <random>

enum class Action {
  FOLD,
  CHECK,
  CALL,
  BET,
  ALL
};

class InformationSet {
public:
  double reach_probability;
  std::vector<int> available_actions;
  std::vector<int> action_history;
  std::map<int, double> average_strategy;
  std::map<int, double> average_regret;
  InformationSet(
    double reach_probability,
    std::vector<std::vector<int>> action_history,
    std::vector<int> available_actions
  );
  
  InformationSet(
    double reach_probability,
    std::vector<std::vector<int>> action_history,
    std::vector<std::vector<int>> available_actions
  );

  bool operator==(std::vector<std::vector<int>> history_available) {
    return this->action_history == history_available[0] 
      & this->available_actions == history_available[1];
    }
};

