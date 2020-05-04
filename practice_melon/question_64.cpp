/*
 *time: 4 ms win: 46.55%
 *memory: 6.1 MB win: 100%
 *coded by jiaxin
 */
class Solution {
public:
  int sumNums(int n) {
    n && (res += n--) && sumNums(n);
    return res;
  }
  int res = 0;
};