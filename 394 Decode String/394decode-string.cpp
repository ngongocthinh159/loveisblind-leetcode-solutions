class Solution {
public:
    vector<int> stoe;
    int n;
    string dfs(int st, int e, string &s) {
        string cur = "";
        for (int i = st; i <= e;) {
            if ('a' <= s[i] && s[i] <= 'z')
                cur += s[i++];
            else {
                int x = 0;
                while (i <= e && '0' <= s[i] && s[i] <= '9') {
                    x = 10*x + (s[i] - '0');
                    i++;
                }
                string tmp = dfs(i + 1, stoe[i] - 1, s);
                while (x--)
                    cur += tmp;
                
                i = stoe[i] + 1;
            }
        }
        return cur;
    }
    string decodeString(string s) {
        n = s.size();
        stoe.resize(n);
        vector<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '[') st.push_back(i);
            else if (s[i] == ']') {
                stoe[st.back()] = i;
                st.pop_back();
            }
        }
        return dfs(0, n - 1, s);
    }
};