class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
        vector<int> pref(n + 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] ^ nums[i];
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= k; j++) {
                for (int s = i; s >= 1; s--) {
                    dp[i][j] = min(dp[i][j], max(dp[s - 1][j - 1], pref[i] ^ pref[s - 1]));
                }
            }
        return dp[n][k];
    }
};