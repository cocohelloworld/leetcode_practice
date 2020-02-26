class Solution {
 public:
  int fib(int n) {
    long long f[101];
    f[0] = 0;
    f[1] = 1;
    if (n == 0) return 0;
    if (n == 1)
      return 1;
    else
      for (int i = 2; i <= n; i++) {
        f[i] = (f[i - 1] + f[i - 2]) %
               1000000007;  //中间计算斐波那契数列取余数和计算完再取余数结果相同
      }
    return f[n];
  }
};