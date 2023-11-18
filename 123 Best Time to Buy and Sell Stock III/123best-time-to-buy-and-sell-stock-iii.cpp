class Solution {
public:
    vector<vector<int>> dp;
    int maxProfit(vector<int>& prices) {
        dp = vector<vector<int>>(prices.size(), vector<int>(2*2 + 1, -1));
        return dfs(prices, 0, 4);
    }

    int dfs(vector<int>& prices, int i, int k) {
        if (i == prices.size() || k == 0) return 0;
        if (dp[i][k] != -1) return dp[i][k];

        if (k % 2 == 0) {
            return dp[i][k] = max(-prices[i] + dfs(prices, i + 1, k - 1), dfs(prices, i + 1, k));
        } else {
            return dp[i][k] = max(prices[i] + dfs(prices, i + 1, k - 1), dfs(prices, i + 1, k));
        }
    }
};