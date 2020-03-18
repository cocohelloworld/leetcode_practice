/*
 *time: 24 ms win: 73.94%
 *memory: 20.8 MB win:100%
 *coded by jiaxin
 */
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int> odd;
        vector<int> even;
        for(const auto& n : nums){
            if(n%2)odd.push_back(n);
            else even.push_back(n);
        }
        odd.insert(odd.end(),even.begin(),even.end());
        return odd;
    }
};