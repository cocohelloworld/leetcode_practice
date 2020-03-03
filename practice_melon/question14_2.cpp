/*
 *time: 0ms
 *memory: 8.1MB
 *win: 100%
 *coded by jiaxin
 */
class Solution {
 public:
  int cuttingRope(int n) {
    int div = n / 3;
    int res = n % 3;
    if (n == 2) return 1;
    if (n == 3) return 2;
    int m = div;
    long result;
    if (!res) {
      result = 1;
      while (m) {
        result = 3 * result % 1000000007;
        m--;
      }
      return result;
    } else if (res == 1) {
      result = 4;
      m--;
      while (m) {
        result = 3 * result % 1000000007;
        m--;
      }
      return result;
    } else if (res == 2) {
      result = 2;
      while (m) {
        result = 3 * result % 1000000007;
        m--;
      }
      return result;
    }
    return NULL;
  }
};