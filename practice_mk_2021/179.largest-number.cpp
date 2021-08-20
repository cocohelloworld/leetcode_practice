/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
bool finishSi, finishSj;
bool compareWithOrder(string si, string sj, int ordi, int ordj)
{

    if(si.length() <= ordi)
    {
        ordi -= si.length();
    }
    if(sj.length() <= ordj)
    {
        ordj -= sj.length();
    }
    if(si[ordi] > sj[ordj]) return true;
    if(si[ordi] < sj[ordj]) return false;
    finishSi =(si.length() == ordi + 1);
    finishSj =(sj.length() == ordj + 1);
    if(finishSi && finishSj) return false;
    //if(si(ordi) == sj(ordj))
    return compareWithOrder(si, sj, ordi + 1, ordj + 1);

}
bool compare(int i, int j) 
{
    string si = to_string(i);
    string sj = to_string(j);
    finishSi = false;
    finishSj = false;
    return compareWithOrder(si, sj, 0, 0);
}


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string result = "";
        bool isFirstNum = true;
        std::sort(nums.begin(), nums.end(),compare);
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i]!= 0 || !isFirstNum)
            {
                isFirstNum = false;
                result += to_string(nums[i]);
            }
        }
        if(isFirstNum) result = "0";
        return result;
    }
};
// @lc code=end

