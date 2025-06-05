class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= n; j++) {
                dp[i][j] = min(dp[i - 1][j], cost[i - 1] + dp[i - 1][max(j - time[i - 1] - 1, 0)]);
            }
        return dp[n][n];
    }
};