#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>
// #include "common.hpp"

// inline const int prime_product_from_rankbits(int rankbits) {
//   /**
//   * @param 
//   * カードbitの中のrankbits 
//   * @return
//   * カードbitのprimeの累積積
//   */
  
//   int product{1};
//   for (int i=0; i < PRIME.size(); i++) {
//     if (rankbits & (1 << i)) product *= PRIME[i];
//   }
//   return product;
// }

// inline const int prime_product_from_hand(
//   std::vector<int> bit_cards) {
//   /**
//   * @param 
//   * bitの配列
//   * @return 
//   * primeの累積積
//   */
  
//   int product{1};
//   for (auto bit_card : bit_cards) product *= bit_card & 0xFF;
//   return product;
// }

// template<class T>
// std::vector<std::vector<T>> combination(
//   const std::vector<T>& seed, int target_size) {
//   /**
//   * @param
//   * seed: 選択対象要素
//   * target_size: 選択数
//   * @return
//   * 全ての組み合わせ
//   */
  
//   assert(target_size <= seed.size());
//   std::vector<int> indices(target_size);
//   std::vector<std::vector<T>> all_comb; 
//   const int seed_size = seed.size();
//   int start_index = 0;
//   int size = 0;

//   while (size >= 0) {
//     for (int i=start_index; i<seed_size; ++i) {
//       indices[size] = i;
//       size++;
//       if (size == target_size) {
//         std::vector<T> comb;
//         for (int x=0; x<target_size; ++x) {
//           // std::cout << seed[indices[x]];
//           comb.push_back(seed[indices[x]]);
//         }
//         all_comb.push_back(comb);
//         // std::cout << std::endl;
//         break;
//       }
//     }
//     --size;
//     start_index = indices[size] + 1;
//   }
//   // std::cout << all_comb.size();
//   return all_comb;
// }