class Solution {
public:
    const int mod = 1e9 + 7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j == 0) dp[i][j] = 1;
                else {
                    int val = (dp[i - 1][j] - (j - i >= 0 ? dp[i - 1][j - i] : 0))%mod;
                    if (val < 0) val += mod;
                    dp[i][j] = (dp[i][j - 1] + val)%mod;
                }
            }
        }
        int res = (dp[n][k] - (k - 1 >= 0 ? dp[n][k - 1] : 0))%mod;
        if (res < 0) res += mod;
        return res;
    }
};


 