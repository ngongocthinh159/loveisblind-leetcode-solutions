class Solution {
public:
    bool isMatch(string s, string t) {
        int n = s.size(), m = t.size();
        s = " " + s;
        t = " " + t;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= m && t[i] == '*'; i++)
            dp[0][i] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if ('a' <= t[j] && t[j] <= 'z') {
                    if (s[i] == t[j])
                        dp[i][j] = dp[i - 1][j - 1];
                } 
                else if (t[j] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = dp[i][j - 1];
                    dp[i][j] = dp[i][j] | dp[i - 1][j];
                }
            }
        return dp[n][m];
    }
};