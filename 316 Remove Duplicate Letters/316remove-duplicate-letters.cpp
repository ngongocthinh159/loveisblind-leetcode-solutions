class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<vector<bool>> cnt(26, vector<bool>(n + 1));
        for (int i = n - 1; i >= 0; i--)
            for (int j = 0; j < 26; j++) {
                if (s[i] == j + 'a') cnt[j][i] = true;
                else cnt[j][i] = cnt[j][i + 1];
            }
        vector<bool> added(26);
        vector<int> st;
        string res = "";
        for (int i = 0; i < n; i++) {
            if (added[s[i] - 'a']) continue;

            while (st.size() && s[st.back()] > s[i] && cnt[s[st.back()] - 'a'][i]) {
                added[s[st.back()] - 'a'] = false;
                st.pop_back();
            }
            
            if (!cnt[s[i] - 'a'][i + 1]) {
                for (int i = 0; i < st.size(); i++) {
                    int c = s[st[i]];
                    added[c - 'a'] = true;
                    res += c;
                }
                added[s[i] - 'a'] = true;
                res += s[i];
                st.clear();
            } else {
                added[s[i] - 'a'] = true;
                st.push_back(i);
            }
        }
        for (int i = 0; i < st.size(); i++) res += s[st[i]];
        return res;
    }
};