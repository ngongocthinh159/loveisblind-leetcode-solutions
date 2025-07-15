class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        dp[0][0] = 1;
        s = " " + s;
        p = " " + p;
        for (int i = 2; i <= m; i += 2) {
            if (p[i] == '*')
                dp[0][i] = 1;
            else
                break;
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if ('a' <= p[j] && p[j] <= 'z') {
                    if (s[i] == p[j])
                        dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                else {
                    if (p[j - 1] == s[i] || p[j - 1] == '.') 
                        dp[i][j] = dp[i - 1][j];
                    dp[i][j] = dp[i][j] | dp[i][j - 2];
                }
            }
        return dp[n][m];
    }
};