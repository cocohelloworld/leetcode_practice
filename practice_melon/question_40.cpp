/*
 *time: 88 ms win: 5.47%
 *memory: 19 MB win:100%
 *coded by jiaxin
 */
//! method 1
class Solution {
public:
  int majorityElement(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int last;
    int cur;
    int times = 0;
    for (int i = 0; i < nums.size(); i++) {
      cur = nums[i];
      if (i) {
        if (cur == last) {
          times++;
        } else {
          times = 1;
        }
      } else {
        times++;
      }
      if (times > nums.size() / 2)
        return cur;
      last = nums[i];
    }
    return times;
  }
};
//! method 2
class Solution {
public:
  int majorityElement(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    return nums[nums.size() / 2];
  }

  //解法三：摩尔投票法
  //也可以理解成混战极限一换一，不同的两者一旦遇见就同归于尽，最后活下来的值都是相同的，即要求的结果
  //时间O(n)，空间O(1)
  class Solution {
  public:
    int majorityElement(vector<int> &nums) {
      int res = 0, count = 0;
      for (int i = 0; i < nums.size(); i++) {
        if (count == 0) {
          res = nums[i];
          count++;
        } else
          res == nums[i] ? count++ : count--;
      }
      return res;
    }
  };