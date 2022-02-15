#include <iostream>
#include <map>
#include "Deck.cpp"

// #ifndef LOOKUP_H
// # LOOKUP_H

#ifndef _LOOKUP_HPP_INCLUDED_
#define _LOOKUP_HPP_INCLUDED_

const int MAX_STRAIGHT_FLUSH = 10;
const int MAX_FOUR_OF_A_KIND = 166;
const int MAX_FULL_HOUSE = 322;
const int MAX_FLUSH = 1599;
const int MAX_STRAIGHT = 1609;
const int MAX_THREE_OF_A_KIND = 2467;
const int MAX_TWO_PAIR = 3325;
const int MAX_PAIR = 6185;
const int MAX_HIGH_CARD = 7462;

inline const int prime_product_from_hand(std::vector<int> bit_cards);
inline const int prime_product_from_rankbits(int rankbits);

template<class T>
std::vector<std::vector<T>> combination(
  const std::vector<T>& seed, int target_size);

class LookupTable {
public:
  LookupTable();
  std::map<int, int> get_flush_lookup();
  std::map<int, int> get_unsuited_lookup();
  void flushes();
  void multiples();
  void fill_in_lookup_table(
    int rank_init,
    std::vector<int>& rankbits_list,
    std::map<int, int>& lookup_table);
  void straight_and_highcards(
    std::vector<int>& straights,
    std::vector<int>& highcards);

  std::map<int, int> flush_lookup;
  std::map<int, int> unsuited_lookup;
};

class LexographicallyBitGenerator {
public:
  LexographicallyBitGenerator(int bit): bit(bit) {}
  int next();
private:
  int bit;
};

#endif
