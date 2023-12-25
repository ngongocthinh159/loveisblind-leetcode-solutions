class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> dp;
    int numDecodings(string s) {
        dp = vector<int>(s.size(), -1);
        return dfs(0, s);
    }

    long long dfs(int i, string &s) {
        if (i > s.size()) return 0;
        if (i == s.size()) return 1;
        if (s[i] == '0') return 0;
        if (dp[i] != -1) return dp[i];

        long long res = 0;
        if (s[i] == '1') {
            if (i + 1 < s.size() && s[i + 1] != '*') res = dfs(i + 1, s) + dfs(i + 2, s);
            else if (i + 1 < s.size() && s[i + 1] == '*') res = dfs(i + 1, s) + 9*dfs(i + 2, s);
            else res = dfs(i + 1, s);
        } else if (s[i] == '2') {
            if (i + 1 < s.size() && '0' <= s[i + 1] && s[i + 1] <= '6') res = dfs(i + 1, s) + dfs(i + 2, s);
            else if (i + 1 < s.size() && s[i + 1] == '*') res = dfs(i + 1, s) + 6*dfs(i + 2, s);
            else res = dfs(i + 1, s);
        } else if (s[i] != '*') res = dfs(i + 1, s);
        else {
            res = 9*dfs(i + 1, s);
            if (i + 1 < s.size() && s[i + 1] != '*') res += dfs(i + 2, s);
            if (i + 1 < s.size() && '0' <= s[i + 1] && s[i + 1] <= '6') res += dfs(i + 2, s);
            if (i + 1 < s.size() && s[i + 1] == '*') res += 9*dfs(i + 2, s) + 6*dfs(i + 2, s);
        }
        return dp[i] = res%mod;
    }
};