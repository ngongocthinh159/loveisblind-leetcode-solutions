class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        int n = rewardValues.size();
        int mx = rewardValues[n - 1];
        vector<vector<int>> dp(n + 1, vector<int>(2*(mx + 1), 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = mx; j >= 0; j--) {
                dp[i][j] = dp[i + 1][j];
                if (rewardValues[i] > j) dp[i][j] = max(dp[i][j], rewardValues[i] + dp[i + 1][j + rewardValues[i]]);
            }
        }
        return dp[0][0];
    }
};