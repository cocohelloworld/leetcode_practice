/* 2020.02.18 mk */
//60 ms
//14.3 MB

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();++i){
            if(nums[i] == nums[i+1]) return nums[i];
        }
        return -1;
    }
};
