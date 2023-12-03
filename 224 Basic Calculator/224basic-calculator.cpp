class Solution {
public:
    int calculate(string s) {
        stack<string> st;
        int i = 0;
        int res = 0;
        while (i < s.size()) {
            if (s[i] == ' ') {i++; continue;}
            else if (s[i] == '(' || s[i] == '+' || s[i] == '-') {
                string tmp = "";
                tmp += s[i];
                st.push(tmp);
                i++;
            } else if ('0' <= s[i] && s[i] <= '9') {
                string cur = "";
                while (i < s.size() && '0' <= s[i] && s[i] <= '9') {
                    cur += s[i++];
                }
                st.push(cur);
            } else if (s[i] == ')') {
                vector<string> v;
                while (st.size() && st.top() != "(") {
                    v.push_back(st.top()); st.pop();
                }
                st.pop();
                reverse(v.begin(), v.end());
                int num = calculateS(v);
                if (num < 0) {
                    if (!st.size()) {
                        st.push("-"); st.push(to_string(abs(num)));
                    } else if (st.top() == "+") {
                        st.pop(); st.push("-"); st.push(to_string(abs(num)));
                    }
                    else if (st.top() == "-") {st.pop(); st.push(to_string(abs(num)));}
                } else {
                    st.push(to_string(num));
                }
                i++;
            }
        }
        vector<string> v;
        while (st.size()) {v.push_back(st.top()); st.pop();}
        reverse(v.begin(), v.end());
        return calculateS(v);
    }
    int calculateS(vector<string>& v) {
        int i = 0;
        int res = 0;
        while (i < v.size()) {
            string op = "";
            while (i < v.size() && (v[i] == "+" || v[i] == "-")) {
                op += v[i++];
            }
            string cur = v[i++];
            if (op == "" || op == "+") res += stoi(cur);
            else if (op == "-") res -= stoi(cur);
        }
        return res;
    }
};