/*
 *time: 4ms
 *memory: 8.4MB
 *win: 65.32%
 *coded by jiaxin
 */
class Solution {
 public:
  int cuttingRope(int n) {
    int div = n / 3;
    int res = n % 3;
    if (n == 2) return 1;
    if (n == 3) return 2;
    if (!res) {
      return pow(3, div);
    } else if (res == 1) {
      return pow(3, div - 1) * 4;
    } else if (res == 2) {
      return pow(3, div) * 2;
    }
    return NULL;
  }
};