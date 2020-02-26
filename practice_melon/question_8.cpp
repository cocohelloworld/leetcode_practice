/*
time: 4ms
memory: 8.2MB
win:61.94%
coded by jiaxin
*/
class Solution {
 public:
  int numWays(int n) {
    if (n <= 1) return 1;
    int step[n + 1];
    step[0] = 1;
    step[1] = 1;
    for (int i = 2; i < n + 1; i++) {
      step[i] = (step[i - 1] + step[i - 2]) % 1000000007;
    }
    return step[n];
  }
};