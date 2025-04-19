class Solution {
public:
    string longestPalindrome(string s) {
        string t;
        t += '#';
        for (auto c : s) t += c, t += '#';
        int T = t.size();
        vector<int> d(T, 0);
        for (int i = 1, l = 0, r = 0; i < T; i++) {
            if (i <= r) d[i] = min(r - i + 1, d[r + l - i]);
            while (0 <= i - d[i] && i + d[i] < T && t[i - d[i]] == t[i + d[i]]) ++ d[i];
            if (i + d[i] - 1 > r) l = i - d[i] + 1, r = i + d[i] - 1;
        }
        int len = 0, idx;
        bool odd;
        for (int i = 1; i < T - 1; i++) {
            if (len < d[i]) {
                len = d[i];
                odd = i&1;
                idx = (i - !(i&1))/2;
            }
        }
        len /= 2;
        int l, r;
        if (odd) 
            l = idx - len + 1, r = idx + len - 1;
        else 
            l = idx - len + 1, r = idx + 1 + len - 1;
        string res = "";
        for (int i = l; i <= r; i++) res += s[i];
        return res;
    }
};