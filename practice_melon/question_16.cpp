/*
 *time: 8 ms
 *memory: 8.3 MB, win:100%
 *coded by jiaxin
 */
class Solution {
 public:
  double myPow(double x, int n) {
    double result = 1.0;
    int k = n;
    while (k) {
      if (k % 2) result = result * x;
      x = x * x;
      k /= 2;
      // cout<<"result"<<result<<endl;
    }
    return n > 0 ? result : 1 / result;
  }
};