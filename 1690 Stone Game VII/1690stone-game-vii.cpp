class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n,
            vector<int>(n));
        vector<int> pref(n + 1);
        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + stones[i];
        for (int len = 2; len <= n; len++) {
            for (int l = 0, r = l + len - 1; r < n; l++, r++) {
                dp[l][r] = max(dp[l][r], pref[r + 1] - pref[l + 1] - dp[l + 1][r]);
                dp[l][r] = max(dp[l][r], pref[r] - pref[l] - dp[l][r - 1]);
            }
        }
        return dp[0][n - 1];
    }
};