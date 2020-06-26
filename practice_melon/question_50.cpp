/*
 *time: 88 ms win: 46.56%
 *memory: 10.8 MB win:100%
 *coded by jiaxin
 */
class Solution {
 public:
  char firstUniqChar(string s) {
    unordered_map<char, int> map;
    for (char letter : s) {
      map[letter]++;
    }
    for (char letter : s) {
      if (map[letter] == 1) return letter;
    }
    return ' ';
  }
};