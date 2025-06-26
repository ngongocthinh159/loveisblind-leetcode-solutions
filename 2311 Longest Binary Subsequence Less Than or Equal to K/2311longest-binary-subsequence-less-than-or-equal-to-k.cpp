class Solution {
public:
    const long long LINF = 1e18;
    int longestSubsequence(string s, int k) {
        int n = s.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(30 + 1, LINF));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= __lg(k); j++) if (dp[i][j] != LINF) {
                // not choose
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);

                // choose
                long long nxt = 2 * dp[i][j] + s[i] - '0';
                if (nxt <= k)
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], nxt);
            }
        int ans = 0;
        for (int j = 0; j <= __lg(k) + 1; j++) if (dp[n][j] != LINF) ans = max(ans, j);
        return ans;
    }
};