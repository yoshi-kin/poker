# pragma once
# include <iostream>
# include <vector>
# include <map>
# include <algorithm>
# include <cassert>
# include <math.h>
# include <random>
# include <bitset>
# include "Deck.hpp"

Deck::Deck() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < PRIME.size(); j++) {
      int card_bit;
      card_bit = static_cast<int>(1 * std::pow(2, j));
      card_bit <<= 4;
      card_bit |= static_cast<int>(1 * std::pow(2, i));
      card_bit <<= 4;
      card_bit += j;
      card_bit <<= 8;
      card_bit += PRIME[j];
      cards.push_back(card_bit);
    }
  }
}

void Deck::show_cards_num() {
  std::cout << cards.size();
}

std::vector<int> Deck::deal(int card_num) {
  std::vector<int> deal_cards;
  shuffle();
  for (int i = 0; i < card_num; i++) {
    deal_cards.push_back(cards.back());
    cards.erase(std::remove(cards.begin(), cards.end(), cards.back()), cards.end());
  }
  return deal_cards;
}

void Deck::display_bit_cards() {
  for (int i = 0; i < cards.size(); i++) {
    std::cout << std::bitset<32>(cards[i]) << std::endl;
  }
}

void Deck::display_str_cards() {
  for (int i = 0; i < cards.size(); i++) {
    int rank_bit = (cards[i] >> 8) & 0xf;
    int suit_bit = (cards[i] >> 12) & 0xf;
    char rank = RANK[rank_bit];
    int position;
    for (int j = 0; j < 4; j++) {
      if (suit_bit == static_cast<int>(1 * std::pow(2, j)))
        position = j;
        break;
    }
    char suit = SUIT[position];
    std::cout << "rank : " << rank << " suit : " << suit << std::endl;
  }
}

void Deck::shuffle() {
  std::random_device rand_dev;
  std::mt19937 rand_engine(12);
  std::shuffle(std::begin(cards), std::end(cards), rand_engine);
  // std::random_shuffle(cards.begin(), cards.end());
}


