class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.size(), m = part.size();
        vector<int> kmp(m), match(n), st;
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && part[i] != part[j]) j = kmp[j - 1];
            kmp[i] = part[i] == part[j] ? ++j : 0;
        }
        vector<bool> removed(n);
        for (int i = 0, j = 0; i < n; i++) {
            st.push_back(i);
            while (j > 0 && s[i] != part[j]) j = kmp[j - 1];
            match[i] = s[i] == part[j] ? ++j : 0;
            if (match[i] == m) {
                int loop = match[i];
                while (loop--) removed[st.back()] = true, st.pop_back();
                j = st.size() ? match[st.back()] : 0;
            }
        }
        string res = "";
        for (int i = 0; i < n; i++) if (!removed[i]) res += s[i];
        return res;
    }
};