/*
 *time: 88 ms win: 5.47%
 *memory: 19 MB win:100%
 *coded by jiaxin
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int last;
        int cur;
        int times=0;
        for(int i =0;i<nums.size();i++){
            cur=nums[i];
            if(i){
                if(cur==last){
                    times++;
                }
                else{
                    times=1;
                }
            }else{
                times++;
            }
            if(times>nums.size()/2)return cur;
            last =nums[i]; 
        }
        return times;
    }
};