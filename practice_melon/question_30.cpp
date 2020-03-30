/*
 *time: 456 ms win: 5.18%
 *memory: 9.9 MB win:100%
 *coded by jiaxin
 */
class MinStack {
public:
  /** initialize your data structure here. */
  MinStack() {}
  vector<int> st;

  void push(int x) { st.push_back(x); }

  void pop() { st.pop_back(); }

  int top() { return st[st.size() - 1]; }

  int min() {
    int fmin = st[0];
    for (int i = 0; i < st.size(); i++) {
      if (st[i] < fmin)
        fmin = st[i];
    }
    return fmin;
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */