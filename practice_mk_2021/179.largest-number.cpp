/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        //add every number to the same length
        //e.g. 9 -> 99999 78 -> 78787 130 -> 13013 1657 -> 16571
        //e.g. 9=99999 78 > 78787 (circle end at 7, 8>7) 130 < 13013 (circle end at 3, 0<3) 1657 > 16571 (circle end at 1, 6>1)
        int length = -1;
        for (int i = 0; i < nums.size();++i) 
        {
            string strnum = nums[i];
            length = strlen(strnum) > length ? strlen(strnum) : length;
        }
        
    }
};
// @lc code=end

