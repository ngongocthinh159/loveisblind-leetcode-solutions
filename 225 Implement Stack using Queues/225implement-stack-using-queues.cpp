class MyStack {
public:
    queue<int> q1;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    int pop_back() {
        int sz = q1.size();
        for (int i = 0; i < sz - 1; i++) {
            q1.push(q1.front());
            q1.pop();
        }
        int res = q1.front();
        q1.pop();
        return res;
    }
    int pop() {
        return pop_back();
    }
    
    int top() {
        int res = pop_back();
        q1.push(res);
        return res;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */