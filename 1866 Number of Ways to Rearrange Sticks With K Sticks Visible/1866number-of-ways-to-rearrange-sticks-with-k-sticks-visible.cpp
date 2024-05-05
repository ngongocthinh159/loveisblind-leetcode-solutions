class Solution {
public:
    const int mod = 1e9 + 7;
    int rearrangeSticks(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = (dp[i - 1][j - 1] + (1LL*(i - 1) * dp[i - 1][j]) % mod) % mod;
            }
        }
        return dp[n][k];
    }
};