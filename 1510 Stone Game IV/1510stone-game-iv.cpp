class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n + 1, false);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                int step = j * j;
                if (!dp[i - step]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};