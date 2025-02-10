class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        vector<int> st, removed(n);
        for (int i = 0; i < n; i++) {
            if ('a' <= s[i] && s[i] <= 'z') st.push_back(i);
            if ('0' <= s[i] && s[i] <= '9') removed[st.back()] = 1, removed[i] = 1, st.pop_back();
        }
        string res = "";
        for (int i = 0; i < n; i++) if (!removed[i]) res += s[i];
        return res;
    }
};