#include <iostream>
#include <map>
#include <vector>
#include "Lookup.cpp"

// #ifndef EVALUATOR_H
// #define EVALUATOR_H

#ifndef _EVALUATOR_HPP_INCLUDED_
#define _EVALUATOR_HPP_INCLUDED_

class Evaluator {
public:
  // Evaluator();
  const int evaluate(std::vector<int> self, std::vector<int> board);
  int five(std::vector<int> bit_cards);
  int six(std::vector<int> bit_cards);
  int seven(std::vector<int> bit_cards);
  
  // get_rank_class();
  // class_to_string();
  // get_five_card_rank_percentage();
  // hand_summary();
private:
  // std::map<int, int (*)(std::vector<int>)> hand_size_map = {{5, five}, {6, six}, {7, seven}};
  class LookupTable table;
};

#endif


