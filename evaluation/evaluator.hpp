#include <iostream>
#include <map>
#include <vector>
#include "lookup.cpp"

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


