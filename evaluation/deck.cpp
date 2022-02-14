# pragma once
# include <iostream>
# include <vector>
# include <map>
# include <algorithm>
# include <cassert>
# include <math.h>
# include <random>
# include <bitset>
# include "deck.hpp"

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

// Deck::Deck() {
//   for (int i=0; i<(int)SUIT.size(); i++) {
//     for (int j=0; j<(int)RANK.size(); j++) {>
//       std::string card = SUIT[i]+RANK[j];
//       cards.push_back(card);
//     }
//   }
// }



// void Deck::bucket_for_private() {
//   std::vector<std::vector<std::string>> all_comb = combination(cards, 2);
//   for (auto comb : all_comb) {
//     auto result = std::find(private_buckets.begin(), private_buckets.end(), comb);
//     if (result == private_buckets.end()) {
//       // 既存のバケットに当てはまらない場合
//       PrivateBucket bucket(comb);
//       private_buckets.push_back(bucket);
//     } else {
//       result->add_comb(comb);
//     }
//   }
// }

// void Deck::remove_bucket() {
//   for (int i=0; i<private_buckets.size(); i++) {
//     if (private_buckets[i].num_comb == 0) {
//       remove(private_buckets, i);
//     }
//   }
// }

// PrivateBucket::PrivateBucket(std::vector<std::string> comb) {
//   std::string card1, card2;
//   card1 = comb[0];
//   card2 = comb[1];
//   char card1_suit = card1[0];
//   char card1_rank = card1[1];
//   char card2_suit = card2[0];
//   char card2_rank = card2[1];
//   card1_rank == card2_rank ? this->is_pair = true : this->is_pair = false;
//   card1_suit == card2_suit ? this->is_suited = true : this->is_suited = false;
//   this->suits.push_back(card1_suit);
//   this->suits.push_back(card2_suit);
//   this->ranks.push_back(card1_rank);
//   this->ranks.push_back(card2_rank);
//   std::sort(this->suits.begin(), this->suits.end());
//   std::sort(this->ranks.begin(), this->ranks.end());
//   this->combs.push_back(comb);
//   this->num_comb++;
// }

// bool PrivateBucket::operator==(std::vector<std::string> comb) {
//   std::string card1, card2;
//   card1 = comb[0];
//   card2 = comb[1];
//   std::vector<char> input_suits;
//   std::vector<char> input_ranks;
//   char card1_suit = card1[0];
//   char card1_rank = card1[1];
//   char card2_suit = card2[0];
//   char card2_rank = card2[1];
//   input_suits.push_back(card1_suit);
//   input_suits.push_back(card2_suit);
//   input_ranks.push_back(card1_rank);
//   input_ranks.push_back(card2_rank);
//   std::sort(input_suits.begin(), input_suits.end());
//   std::sort(input_ranks.begin(), input_ranks.end());
//   if (this->is_pair) {
//     // ペアの場合
//     if (this->ranks == input_ranks) {
//       return true;
//     } else {
//       return false;
//     }
//   } else if (this->is_suited) {
//     // スーツの場合
//     if (this->ranks == input_ranks && input_suits[0] == input_suits[1]) {
//       return true;
//     } else {
//       return false;
//     }
//   } else {
//     // どちらでも場合
//     if (this->ranks == input_ranks) {
//       return true;
//     } else {
//       return false;
//     }
//   }
// }

// void PrivateBucket::add_comb(std::vector<std::string> comb) {
//   combs.push_back(comb);
//   num_comb++;
// }

// void cal_private_bucket_comb_probability() {
//   Deck deck;
//   deck.bucket_for_private();
//   std::vector<double> probability_for_bucket_combs;
//   for (int i=0; i<deck.private_buckets.size(); i++) {
//     for (int j=0; j<deck_private_buckets.size(); j++) {
//       if (i == j) {
//         double probability = 1/
//       }
//     }
//   }
// }


