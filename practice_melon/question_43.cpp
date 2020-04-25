/*
 *time: 124 ms win: 6.12%
 *memory: 22.8 MB win:100%
 *coded by jiaxin
 */
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int sum = 0;
    int max = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {

      if (sum + nums[i] <= nums[i]) {
        sum = nums[i];
        // cout<<nums[i]<<endl;
      } else {
        cout << nums[i] << endl;
        sum = sum + nums[i];
      }
      if (sum > max)
        max = sum;
    }
    return max;
  }
};