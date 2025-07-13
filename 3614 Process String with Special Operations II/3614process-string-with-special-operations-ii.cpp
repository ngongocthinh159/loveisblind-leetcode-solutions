#define ll long long
class Solution {
public:
    char dfs(int i, ll len, ll k, string &s) {
        if (i < 0)
            return '.';
        if (k > len)
            return '.';
        

        if ('a' <= s[i] && s[i] <= 'z') {
            if (k == len)
                return s[i];
            return dfs(i - 1, len - 1, k, s);
        }
        if (s[i] == '*')
            return dfs(i - 1, len + 1, k, s);
        if (s[i] == '%')
            return dfs(i - 1, len, len + 1 - k, s);
        if (len % 2 != 0)
            return '.';
        ll half = len / 2;
        return dfs(i - 1, half, (k <= half ? k : k - half), s);
    };
    char processStr(string s, long long k) {
        ll len = 0;
        string t = "";
        for (auto c : s) {
            bool used = true;
            if ('a' <= c && c <= 'z') len++;
            if (c == '*') {
                if (len == 0) used = false;
                else
                    len--;
            }
            if (c == '#') len *= 2;
            if (used)
                t += c;
        }
        k++;
        return dfs((int) t.size() - 1, len, k, t);
    }
};