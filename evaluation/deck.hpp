# pragma once
# include <iostream>
# include <vector>
# include <map>
# include <sstream>
# include <algorithm>
# include <cassert>
# include <math.h>
# include <random>


// #ifndef DECK_H
// #define DECK_H

#ifndef _DECK_HPP_INCLUDED_
#define _DECK_HPP_INCLUDED_
const std::vector<int> PRIME{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
char RANK[] = "23456789TJQKA";
char SUIT[] = "SCHD";

class Deck {
public:
  Deck();
  std::vector<int> deal(int card_num);
  void show_cards_num(); 
  void display_bit_cards();
  void display_str_cards();
  void shuffle();
private:
  std::vector<int> cards;
};

#endif

