class Solution {
public:
    vector<vector<int>> dp;
    int maxProfit(vector<int>& prices) {
        dp = vector<vector<int>>(prices.size(), vector<int>(2, -1));
        return dfs(prices, 0, 1);
    }

    int dfs(vector<int>& prices, int i, int canBuy) {
        if (i == prices.size()) return 0;
        if (dp[i][canBuy] != -1 ) return dp[i][canBuy];

        if (canBuy) {
            return dp[i][canBuy] = max(-prices[i] + dfs(prices, i + 1, 0), dfs(prices, i + 1, canBuy));
        } else {
            return dp[i][canBuy] = max(prices[i] + dfs(prices, i + 1, 1), dfs(prices, i + 1, canBuy));
        }
    }
};