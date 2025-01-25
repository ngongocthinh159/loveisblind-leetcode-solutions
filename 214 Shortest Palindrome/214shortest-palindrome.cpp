class Solution {
public:
    vector<int> z_func(string &s) {
        int n = s.size();
        vector<int> z(n);
        for (int i = 1, l = 0, r = 0; i < n; i++) {
            if (i <= r) z[i] = min(z[i - l], r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
            if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
        }
        return z;
    }
    string shortestPalindrome(string s) {
        int n = s.size();
        string t = s + "#";
        reverse(s.begin(), s.end());
        t += s;
        reverse(s.begin(), s.end());
        auto z = z_func(t);
        for (int i = n + 1; i < 2*n + 1; i++) {
            if (i + z[i] == 2*n + 1) {
                string tmp = s.substr(z[i]);
                reverse(tmp.begin(), tmp.end());
                return tmp + s;
            }
        }
        return "";
    }
};