/* 2020.02.27 mk */
//384 ms
//106.1 MB

class CQueue {
public:
    CQueue() {
    }
    void appendTail(int value) {
        s1.push(value);
    }
    int deleteHead() {
        int ret;
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(!s2.empty()) {
            ret=s2.top();
            s2.pop();
            return ret;
        }
        return -1;
    }
    stack<int> s1;
    stack<int> s2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
