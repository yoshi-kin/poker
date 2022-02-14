#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <bitset>
#include "lookup.hpp"

const int prime_product_from_rankbits(int rankbits) {
  /**
  * @param 
  * カードbitの中のrankbits 
  * @return
  * カードbitのprimeの累積積
  */
  
  int product{1};
  for (int i=0; i < PRIME.size(); i++) {
    if (rankbits & (1 << i)) product *= PRIME[i];
  }
  return product;
}

const int prime_product_from_hand(
  std::vector<int> bit_cards) {
  /**
  * @param 
  * bitの配列
  * @return 
  * primeの累積積
  */
  
  int product{1};
  for (auto bit_card : bit_cards) product *= bit_card & 0xFF;
  return product;
}

template<class T>
std::vector<std::vector<T>> combination(
  const std::vector<T>& seed, int target_size) {
  /**
  * @param
  * seed: 選択対象要素
  * target_size: 選択数
  * @return
  * 全ての組み合わせ
  */
  
  assert(target_size <= seed.size());
  std::vector<int> indices(target_size);
  std::vector<std::vector<T>> all_comb; 
  const int seed_size = seed.size();
  int start_index = 0;
  int size = 0;

  while (size >= 0) {
    for (int i=start_index; i<seed_size; ++i) {
      indices[size] = i;
      size++;
      if (size == target_size) {
        std::vector<T> comb;
        for (int x=0; x<target_size; ++x) {
          // std::cout << seed[indices[x]];
          comb.push_back(seed[indices[x]]);
        }
        all_comb.push_back(comb);
        // std::cout << std::endl;
        break;
      }
    }
    --size;
    start_index = indices[size] + 1;
  }
  // std::cout << all_comb.size();
  return all_comb;
}

LookupTable::LookupTable() {
  /**
  * @fn
  * コンストラクタ
  */

  flushes();
  multiples();
}

void LookupTable::flushes() {
  /**
  * @brief
  * flush_lookupにストレートフラッシュとフラッシュのパターンを追加
  * unsuited_lookupにストレートとハイカードのパターンを追加
  */

  std::vector<int> straight_flushes{
    7936,        // int('0b1111100000000', 2), # royal flush
    3968,        // int('0b111110000000', 2),
    1984,        // int('0b11111000000', 2),
    992,         // int('0b1111100000', 2),
    496,         // int('0b111110000', 2),
    248,         // int('0b11111000', 2),
    124,         // int('0b1111100', 2),
    62,          // int('0b111110', 2),
    31,          // int('0b11111', 2),
    4111,        // int('0b1000000001111', 2) # 5 high
  };

  std::vector<int> flushes;
  LexographicallyBitGenerator gen{0b11111};
  for (int i = 0; i < 1286; i++) {
    int f = gen.next();
    bool notSF = true;
    for (auto sf : straight_flushes) {
      if (!(f ^ sf)) notSF = false;
    }
    if (notSF) flushes.push_back(f);
  }

  std::reverse(flushes.begin(), flushes.end());

  fill_in_lookup_table(1, straight_flushes, flush_lookup);
  fill_in_lookup_table(MAX_FULL_HOUSE + 1, flushes, flush_lookup);
  straight_and_highcards(straight_flushes, flushes);
}

void LookupTable::fill_in_lookup_table(
  int rank_init,
  std::vector<int>& rankbits_list,
  std::map<int, int>& lookup_table) {
  
  for (auto rb : rankbits_list) {
    const int prime_product = prime_product_from_rankbits(rb);
    lookup_table[prime_product] = rank_init;
    rank_init++;
  }
}

void LookupTable::straight_and_highcards(
  std::vector<int>& straights,
  std::vector<int>& highcards) {
  
  fill_in_lookup_table(MAX_FLUSH + 1, straights, unsuited_lookup);
  fill_in_lookup_table(MAX_PAIR + 1, highcards, unsuited_lookup);
}

void LookupTable::multiples() {
  /**
  * @brief
  * unsuited_lookupに4カード、フルハウス、3カード、2ペア、ペアのパターンを追加
  */

  std::vector<int> backwards_ranks{12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  
  // 1) Four of a Kind
  int rank = MAX_STRAIGHT_FLUSH + 1;
  for (auto i : backwards_ranks) {
    std::vector<int> kickers = backwards_ranks;
    kickers.erase(std::remove(kickers.begin(), kickers.end(), i), kickers.end());
    for (auto k : kickers) {
      int product = static_cast<int>(std::pow(PRIME[i], 4)) * PRIME[k];
      unsuited_lookup[product] = rank;
      rank++;
    }
  }

  // 2) Full House
  rank = MAX_FOUR_OF_A_KIND + 1;
  for (auto i : backwards_ranks) {
    std::vector<int> pairranks = backwards_ranks;
    pairranks.erase(std::remove(pairranks.begin(), pairranks.end(), i), pairranks.end());
    for (auto pr : pairranks) {
      int product = static_cast<int>(std::pow(PRIME[i], 3)) * static_cast<int>(std::pow(PRIME[pr], 2));
      unsuited_lookup[product] = rank;
      rank++;
    }
  }

  // 3) Three of a Kind
  rank = MAX_STRAIGHT + 1;
  for (auto i : backwards_ranks) {
    std::vector<int> kickers = backwards_ranks;
    kickers.erase(std::remove(kickers.begin(), kickers.end(), i), kickers.end());
    std::vector<std::vector<int>> gen = combination(kickers, 2);
    for (auto g : gen) {
      int c1 = g[0];
      int c2 = g[1];
      int product = static_cast<int>(std::pow(PRIME[i], 3)) * PRIME[c1] * PRIME[c2];
      unsuited_lookup[product] = rank;
      rank++;
    }
  }

  // 4) Two Pair
  rank = MAX_THREE_OF_A_KIND + 1;
  std::vector<std::vector<int>> tpgen = combination(backwards_ranks, 2);
  for (auto tp : tpgen) {
    int pair1 = tp[0];
    int pair2 = tp[1];
    std::vector<int> kickers = backwards_ranks;
    kickers.erase(std::remove(kickers.begin(), kickers.end(), pair1), kickers.end());
    kickers.erase(std::remove(kickers.begin(), kickers.end(), pair2), kickers.end());

    for (int kicker : kickers) {
      int product = static_cast<int>(std::pow(PRIME[pair1], 2)) * static_cast<int>(std::pow(PRIME[pair2], 2)) * PRIME[kicker];
      unsuited_lookup[product] = rank;
      rank++;
    }
  }

  // 5) Pair
  rank = MAX_TWO_PAIR + 1;
  for (int pairrank : backwards_ranks) {
    std::vector<int> kickers = backwards_ranks;
    kickers.erase(std::remove(kickers.begin(), kickers.end(), pairrank), kickers.end());
    std::vector<std::vector<int>> kgen = combination(kickers, 3);
    for (auto kickers : kgen) {
      auto k1 = kickers[0];
      auto k2 = kickers[1];
      auto k3 = kickers[2];
      int product = static_cast<int>(std::pow(PRIME[pairrank], 2)) * PRIME[k1] * PRIME[k2] * PRIME[k3];
      unsuited_lookup[product] = rank;
      rank++;
    }
  }
}

std::map<int, int> LookupTable::get_flush_lookup() {
  return flush_lookup;
}

std::map<int, int> LookupTable::get_unsuited_lookup() {
  return unsuited_lookup;
}

int LexographicallyBitGenerator::next() {
  int t = ((bit | (bit - 1))) + 1;
  bit = t | ((int(((t & -t) / (bit & -bit))) >> 1) - 1);
  return bit;
}