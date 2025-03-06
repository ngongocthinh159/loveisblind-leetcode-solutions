class Solution {
public:
    bool check(int idx, string &cur, string &str2) {
        int n = cur.size(), m = str2.size();
        for (int i = max(0, idx - m + 1); i <= idx; i++) {
            if (i + m - 1 < n) {
                bool match = true;
                for (int j = i, k = 0; j < i + m; j++, k++) {
                    if (cur[j] == ' ' || cur[j] != str2[k]) {
                        match = false;
                        break;
                    }
                }
                if (match) return false;
            }
        }
        return true;
    }
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        string res(n + m - 1, ' ');
        vector<int> kmp(m);
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && str2[i] != str2[j]) j = kmp[j - 1];
            kmp[i] = str2[i] == str2[j] ? ++j : 0;
        }
        unordered_set<int> S;
        int j = m - 1;
        while (j > 0) {
            S.insert(kmp[j]);
            j = kmp[j] - 1;
        }
        int last = -1;
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                if (last != -1 && last + m - 1 >= i) {
                    int len = last + m - 1 - i + 1;
                    if (!S.count(len)) {
                        return "";
                    }
                }
                last = i;
            }
        }
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = i, k = 0; j < i + m; j++, k++) res[j] = str2[k];
            }
        }
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;
                for (int j = i, k = 0; j < i + m; j++, k++) if (res[j] == ' ' || res[j] != str2[k]) {
                    match = false;
                    break;
                }
                if (match) {
                    return "";
                }
            }
        }
        for (int i = 0; i < n + m - 1; i++) {
            if (res[i] == ' ') {
                res[i] = 'a';
                if (!check(i, res, str2)) res[i] = 'b';
            }
        }
        return res;
    }
};