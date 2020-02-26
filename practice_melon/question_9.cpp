/*
 *time: 4ms
 *memory: 14.5MB
 *win: 96.20%
 *coded by jiaxin
 */
class Solution {
 public:
  int minArray(vector<int>& numbers) {
    int index;
    for (int i = 0; i < numbers.size(); i++) {
      if (i + 1 != numbers.size() && numbers[i] > numbers[i + 1]) {
        return numbers[i + 1];
      } else if (i == numbers.size() - 1) {
        return numbers[0];
      }
    }
    return NULL;
  }
};