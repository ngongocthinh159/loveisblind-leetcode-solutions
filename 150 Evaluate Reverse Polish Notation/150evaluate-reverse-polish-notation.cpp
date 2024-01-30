class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto s : tokens) {
            if (s == "+") {
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();
                st.push(top2 + top1);
            } else if (s == "-") {
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();
                st.push(top2 - top1);
            } else if (s == "*") {
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();
                st.push(top2 * top1);
            } else if (s == "/") {
                int top1 = st.top(); st.pop();
                int top2 = st.top(); st.pop();
                st.push(top2 / top1);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};