/*
 *time: 16 ms, win:28.91%
 *memory: 14.3 MB, win:100%
 *coded by jiaxin
 */
class Solution {
 public:
  vector<int> result;
  vector<int> printNumbers(int n) {
    int max = pow(10, n) - 1;
    for (int i = 1; i <= max; i++) result.push_back(i);
    return result;
  }
};