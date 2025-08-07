class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        vector<vector<int>> grid = fruits;
        int diag = 0;
        for (int i = 0; i < n; i++) diag += fruits[i][i];
        auto cal = [&]() -> int {
            vector<pair<int,int>> m = {{-1,1},{0,1},{1,1}};
            vector<vector<int>> dp(n, vector<int>(n, -1));
            dp[n - 1][0] = grid[n - 1][0];
            for (int j = 0; j < n; j++) 
                for (int i = n - 1; i > j; i--) if (dp[i][j] != -1) {
                    for (auto [dx, dy] : m) {
                        int I = dx + i;
                        int J = dy + j;
                        if (0 <= I && I < n && 0 <= J && J < n && I > J)
                            dp[I][J] = max(dp[I][J], dp[i][j] + grid[I][J]);
                    }
                }
            return dp[n - 1][n - 2];
        };
        int ans = cal();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) grid[i][j] = fruits[j][i];
        ans += cal();
        return diag + ans;
    }
};