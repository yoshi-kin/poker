# pragma once
# include <iostream>
# include <vector>
# include <map>
# include <sstream>
# include <algorithm>
# include <cassert>
# include <math.h>
# include <random>
// # include "config.hpp"
// using Card = std::pair<std::string, std::string>;
// using Buckets = std::vector<PrivateBucket>;

// const std::vector<std::string> SUIT = {"S", "C", "H", "D"};
// const std::vector<std::string> RANK = {
//   "1", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"
// };

// class PrivateBucket {
//   public:
//     int num_comb = 0;
//     bool is_pair;
//     bool is_suited;
//     std::vector<char> suits;
//     std::vector<char> ranks;
//     std::vector<std::vector<std::string>> combs;
//     PrivateBucket(std::vector<std::string> comb);
//     bool operator==(std::vector<std::string> comb);
//     void add_comb(std::vector<std::string> comb);
// };
const std::vector<int> PRIME{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
char RANK[] = "23456789TJQKA";
char SUIT[] = "SCHD";

class Deck {
public:
  // int deal_num = 0;
  // std::vector<PrivateBucket> private_buckets;
  Deck();
  std::vector<int> deal(int card_num);
  void display_bit_cards();
  void display_str_cards();
  void shuffle();
  // void bucket_for_private();
  // void remove_bucket();
private:
  std::vector<int> cards;
};


