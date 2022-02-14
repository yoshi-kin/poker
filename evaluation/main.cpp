#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <bitset>
#include "evaluator.cpp"

int main() {

  Evaluator evaluator;
  Deck deck;

  std::vector<int> self = deck.deal(2);
  std::vector<int> board = deck.deal(5);
  int rank = evaluator.evaluate(self, board);
  std::cout << rank;
  return 0;
}