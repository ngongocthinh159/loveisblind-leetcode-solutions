class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, NULL);
        return minAt(amount, coins, dp);
    }

    int minAt(int amount, vector<int>& coins, vector<int>& dp) {
        if (amount == 0) return 0;
        if (dp[amount] != NULL) return dp[amount];
        
        int res = INT_MAX;
        bool found = false;
        for (int i = 0; i < coins.size(); i++) {
            if (amount < coins[i]) continue;
            int tmp = minAt(amount - coins[i], coins, dp);
            if (tmp != -1 && res > tmp) {
                found = true;
                res = tmp;
            } 
        }
        if (!found) return dp[amount] = -1;
        return dp[amount] = res + 1;
    }
};