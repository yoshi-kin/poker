# pragma once
# include <iostream>
# include <vector>
# include <map>
# include <sstream>
# include <random>
# include "information_set.hpp"

InformationSet::InformationSet(
  double reach_probability,
  std::vector<std::vector<int>> action_history,
  std::vector<int> available_actions) {
  
  reach_probability = reach_probability;
  available_actions = available_actions;
  action_history = action_history;
  for (auto& action : available_actions) {
    average_strategy[action] = (double) 1 / available_actions.size();
    average_regret[action] = 0;
  }
}

InformationSet::InformationSet(
  double reach_probability,
  std::vector<std::vector<std::string>> action_history,
  std::vector<std::vector<std::string>> available_actions) {
  
  reach_probability = reach_probability;
  action_history = action_history;
  available_actions = available_actions;
  for (auto& action : available_actions) {
    average_strategy[action] = (double) 1 / available_actions.size();
    average_regret[action] = 0;
  }
}