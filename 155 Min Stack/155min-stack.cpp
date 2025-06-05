class MinStack {
public:
    vector<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push_back({val, st.size() ? min(st.back().second, val) : val});
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */