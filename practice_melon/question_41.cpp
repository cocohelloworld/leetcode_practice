/*
 *time: 308 ms win: 20.90%
 *memory: 30 MB win:100%
 *coded by jiaxin
 */
class Solution {
public:
  vector<string> permutation(string s) {
    if (!s.data()) {
      return result;
    }
    int start = 0;
    int end = s.length() - 1;
    str = s;
    permute(start, end);
    return result;
  }
  vector<string> result;
  string str;
  map<string, int> split;
  void permute(int start, int end) {
    if (start == end) {
      if (split.find(str) == split.end()) {
        result.push_back(str);

        split.insert(make_pair(str, 1));
      }
    } else {
      for (int i = start; i <= end; i++) {
        //  cout<<str<<endl;
        if (str[start] != str[i] || i == start) {
          swapchar(start, i);

          permute(start + 1, end);
          swapchar(start, i);
        }
      }
    }
  }
  void swapchar(int start, int end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
  }
};