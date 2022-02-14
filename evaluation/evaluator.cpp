#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "evaluator.hpp"

const int Evaluator::evaluate(std::vector<int> self, std::vector<int> board) {
  /**
  * @param
  * カードbitを2つ
  * @return
  * カード5枚の場合 => five()の返り値
  * カード6枚の場合 => six()の返り値
  * カード7枚の場合 => seven()の返り値
  */
  
  self.insert(self.end(), board.begin(), board.end());
  if (self.size() == 5) return five(self);
  if (self.size() == 6) return six(self);
  if (self.size() == 7) return seven(self);
  // return hand_size_map[bit_cards.size()](bit_cards);
  return 0;
}

int Evaluator::five(std::vector<int> cards) {
  /**
  * @param
  * 5枚のカードbit
  * @return
  * フラッシュの場合=>カードのprimeの累積積に対応するflush_tableの値
  * フラッシュでない場合=>カードのprimeの累積積に対応するunsuited_tableの値
  */

  if (cards[0] & cards[1] & cards[2] & cards[3] & cards[4] & 0xF000) {
    // フラッシュの場合
    int handOR = (cards[0] | cards[1] | cards[2] | cards[3] | cards[4]) >> 16;
    int prime = prime_product_from_rankbits(handOR);
    return table.flush_lookup[prime];
  } else {
    // フラッシュでない場合
    int prime = prime_product_from_hand(cards);
    return table.unsuited_lookup[prime];
  }
}

int Evaluator::six(std::vector<int> bit_cards) {
  /**
  * @brief
  * 6枚のカードの中から5枚のカードを選ぶときの
  * すべての組み合わせのscoreを比較
  * @param
  * 6つのカードbit
  * @return
  * 最小のscore（一番強い）
  */

  int minimum = MAX_HIGH_CARD;
  std::vector<std::vector<int>> all5cardcombobs = combination(bit_cards, 5);
  for (auto combo : all5cardcombobs) {
    int score = five(combo);
    if (score < minimum) minimum = score;
  }
  return minimum;
}

int Evaluator::seven(std::vector<int> bit_cards) {
  /**
  * @brief
  * 7枚のカードの中から5枚のカードを選んだ場合の
  * すべての組み合わせのscoreを比較
  * @param
  * 7つのカードbit
  * @return
  * 最小のscore
  */

  int minimum = MAX_HIGH_CARD;
  std::vector<std::vector<int>> all5cardcombobs = combination(bit_cards, 5);
  for (auto combo : all5cardcombobs) {
    int score = five(combo);
    if (score < minimum) minimum = score;
  }
  return minimum;
}