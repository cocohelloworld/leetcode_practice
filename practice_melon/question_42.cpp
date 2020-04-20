class Solution {
public:
  vector<int> getLeastNumbers(vector<int> &arr, int k) {
    vector<int> n;
    if (!arr.size())
      return n;
    sort(arr.begin(), arr.end());
    vector<int> re(arr.begin(), arr.begin() + k);
    return re;
  }
};