class Solution {
public:
    vector<vector<vector<int>>> dp;
    int maxProfit(int k, vector<int>& prices) {
        dp = vector<vector<vector<int>>>(prices.size(), vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return dfs(0, k, 1, prices);
    }

    int dfs(int i, int k, int canBuy, vector<int>& prices) {
        if (i == prices.size()) return 0;
        if (dp[i][k][canBuy] != -1) return dp[i][k][canBuy];

        if (canBuy && k > 0) {
            return dp[i][k][canBuy] = max(-prices[i] + dfs(i + 1, k - 1, 0, prices), dfs(i + 1, k, canBuy, prices));
        } else if (!canBuy) {
            return dp[i][k][canBuy] = max(prices[i] + dfs(i + 1, k, 1, prices), dfs(i + 1, k, canBuy, prices));
        } else {
            return dp[i][k][canBuy] = dfs(i + 1, k, canBuy, prices);
        }
    }
};