/*
 *time: 352ms
 *memory: 106.1MB
 *win: 92.95%
 *coded by jiaxin
 */
class CQueue {
 public:
  CQueue() {}
  stack<int> st1, st2;

  void appendTail(int value) { st1.push(value); }

  int deleteHead() {
    if (st1.empty() && st2.empty())
      return -1;
    else if (!st1.empty() && st2.empty()) {
      while (!st1.empty()) {
        int val = st1.top();
        st1.pop();
        st2.push(val);
      }
    }
    int temp = st2.top();
    st2.pop();
    return temp;
  }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */