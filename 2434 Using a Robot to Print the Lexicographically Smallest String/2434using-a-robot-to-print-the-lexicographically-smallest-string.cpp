class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<int> mn(n + 1);
        mn[n] = 30;
        for (int i = n - 1; i >= 0; i--) {
            mn[i] = min(s[i] - 'a', mn[i + 1]);
        }
        vector<int> st;
        string res = "";
        for (int i = 0; i < n; i++) {
            st.push_back(i);
            while (st.size() && s[st.back()] - 'a' <= mn[i + 1]) {
                res += s[st.back()];
                st.pop_back();
            }
        }
        while (st.size()) res += s[st.back()], st.pop_back();
        return res;
    }
};