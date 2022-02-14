# pragma once
# include <iostream>
# include <vector>
# include <map>
# include <sstream>
# include <algorithm>
# include <cassert>
# include <math.h>
# include <random>
# include "node.hpp"

ChanceNode::ChanceNode(
  int pot_size,
  int stage
  double reach_probability,
  std::vector<int> action_history) {
  
  pot_size = pot_size;
  stage = stage;
  if (stage == 0) {

  } else if (stage == 1) {

  } else if (stage == 2) {

  } else {

  }
  // for (int i=0; i<available_actions.size(); i++) {
  //   std::cout << actions_probability[i] << std::endl;
  //   TerminalNode child_node = TerminalNode(
  //     this->pot_size,
  //     actions_probability[i]
  //   );
  //   this->utility += child_node.utility;
  // }
}

ChanceNode::get_information_list() {
  return information_list;
}

ChanceNode::deal_card(Deck& deck, int& card_num) {
  std::vector<Card> card_list;
  for (int i=0; i<card_num; i++) {
    card_list.puch_back(deck.back());
  }
}

TerminalNode::TerminalNode(
  int pot_size,
  double reach_probability) {
  
  utility = (double)pot_size * reach_probability;
}
