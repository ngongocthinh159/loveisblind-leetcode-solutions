class Solution {
public:
    vector<vector<int>> dp;
    int longestPalindromeSubseq(string s) {
        dp  =vector<vector<int>>(s.size(), vector<int>(s.size(), -1));
        return dfs(0, s.size() -1, s);
    }

    int dfs(int l, int r, string &s) {
        if (r < l) return 0;
        if (r == l) return 1;
        if (dp[l][r] != -1) return dp[l][r];

        int res;
        if (s[l] == s[r]) {
            res = 2 + dfs(l + 1, r - 1, s);
        } else {
            res = max(dfs(l + 1, r, s), dfs(l, r - 1, s));
        }
        return dp[l][r] = res;
    }
};