/*
 *time: 700 ms win: 5.06%
 *memory: 182.7 MB win: 100%
 *coded by jiaxin
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> max;
        if(!nums.size())return max;
        
        for(int i =0;i<nums.size()-k+1;i++){
            vector win(nums.begin()+i,nums.begin()+i+k);
           
            max.push_back(*max_element(win.begin(),win.end()));
            vector<int>().swap(win); 
        }
        return max;
    }
};