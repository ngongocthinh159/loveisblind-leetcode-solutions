#define ll long long
class Solution {
public:
    // Key: in an optimal solution for a NxM grid, we always can find either
    // a whole horizontal or vertical line not intersecting any rectangles
    // => try to brute force this whole line and divide to smaller problems

    // Note: the condition "entire height or width" in the problem is not neccesary
    // because the optimal solution always exist with a whole line
    long long sellingWood(int n, int m, vector<vector<int>>& prices) {
        vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
        for (auto &p : prices)
            dp[p[0]][p[1]] = p[2];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int t = 1; t <= i - 1; t++)
                    dp[i][j] = max(dp[i][j], dp[t][j] + dp[i - t][j]);
                for (int t = 1; t <= j - 1; t++)
                    dp[i][j] = max(dp[i][j], dp[i][t] + dp[i][j - t]);
            }
        }
        return dp[n][m];
    }
};