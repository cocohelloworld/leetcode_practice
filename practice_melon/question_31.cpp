/*
 *time: 40 ms win: 6.14%
 *memory: 15.4 MB win:100%
 *coded by jiaxin
 */
class Solution {
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    stack<int> st;
    int index = 0;
    for (int i = 0; i < pushed.size(); i++) {
      st.push(pushed[i]);
      while (index < popped.size() && !st.empty() &&
             st.top() == popped[index]) {
        st.pop();
        index++;
      }
    }
    return st.empty() == 1 ? 1 : 0;
  }
};