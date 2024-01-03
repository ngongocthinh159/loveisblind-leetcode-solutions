class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size() + 1, 0));
        for (int i = 0; i < coins.size() + 1; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i <= amount; i++) {
            for (int j = coins.size() - 1; j >= 0; j--) {
                int choose = 0;
                if (i >= coins[j]) choose = dp[i - coins[j]][j];
                int skip = dp[i][j + 1];
                dp[i][j] = choose + skip;
            }
        }
        return dp[amount][0];
    }
};