/*
time: 52ms
66.13%
coded by jiaxin
*/
class Solution {
 public:
  int findRepeatNumber(vector<int>& nums) {
    int n[nums.size()] = {0};
    for (int i = 0; i < nums.size(); i++) {
      if (n[nums[i]]) {
        return nums[i];
      }
      n[nums[i]]++;
    }
    return -1;
  }
};