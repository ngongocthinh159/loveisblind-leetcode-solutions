class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = (int) obstacles.size() - 1;
        int dp[4] = {0, 1, 0, 1};
        for (int i = 1; i <= n; i++) {
            if (obstacles[i]) dp[obstacles[i]] = 1e9;
            for (int j = 1; j <= 3; j++) if (obstacles[i] != j) {
                dp[j] = min(dp[j], 1 + min(dp[(j % 3) + 1], dp[(j + 1)%3 + 1]));
            }
        }
        return min(dp[1], min(dp[2], dp[3]));
    }
};