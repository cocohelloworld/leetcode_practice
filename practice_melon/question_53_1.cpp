/*
 *time: 24 ms win:19.67%
 *memory:13.1 MB win:100%
 *coded by jiaxin
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int flag = 0;
        int times=0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]==target){
                flag = 1;
                times++;
            }
            if(flag==1&&nums[i]!=target)break;
            if(flag==0&&nums[i]>target)break;
        }
        return times;
        
    }
};