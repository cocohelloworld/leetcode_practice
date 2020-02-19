/*
time: 0ms
win:100%
coded by jiaxin
*/
class Solution {
 public:
  string replaceSpace(string s) {
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == ' ') {
        s.replace(i, 1, "%20");
        i += 2;
      }
    }
    return s;
  }
};