class Solution {
public:
    vector<vector<int>> dp;
    int maxProfit(vector<int>& prices) {
        dp = vector<vector<int>>(prices.size(), vector<int>(2, NULL));
        return dfs(prices, 0, 0);
    }

    // state == 0: can buy
    // state == 1: can sell
    int dfs(vector<int>& prices, int i, int state) {
        if (i >= prices.size()) return 0;
        if (dp[i][state] != NULL) return dp[i][state];

        if (state == 0) {
            return dp[i][state] = max(-prices[i] + dfs(prices, i + 1, 1), dfs(prices, i + 1, 0));
        } else {
            return dp[i][state] = max(prices[i] + dfs(prices, i + 2, 0), dfs(prices, i + 1, 1));
        }
    }
};