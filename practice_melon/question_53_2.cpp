/*
 *time: 48 ms win:16.06%
 *memory:17.1 MB win:100%
 *coded by jiaxin
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(!nums.size())return NULL;
        int left = 0,right = nums.size()-1;
        if(nums[left]==1)return 0;
        if(nums[right]==nums.size()-1)return nums.size();
        
        while(right-left>1){
            if(nums[(left+right)/2]==(left+right)/2)left = (left+right)/2;
            else right = (left+right)/2;
           
        }
            
       return nums[left]+1;
        
    }
};