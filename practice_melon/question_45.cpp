/*
 *time: 32 ms win: 16%
 *memory: 11.6 MB win:100%
 *coded by jiaxin
 */
class Solution {
 public:
  string minNumber(vector<int>& nums) {
    vector<string> st_array;
    string result;
    for (auto num : nums) st_array.push_back(to_string(num));
    sort(st_array.begin(), st_array.end(), compare);
    for (auto str : st_array) result += str;
    cout << result << endl;
    return result;
  }
  static bool compare(string a, string b) { return a + b < b + a; }
};