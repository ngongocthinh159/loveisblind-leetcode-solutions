class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> cnt;
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        cnt = vector<vector<int>>(m, vector<int>(10, 0));
        dp = vector<vector<int>>(m + 1, vector<int>(10, -1));
        for (int j = 0; j < m ;j ++) {
            for (int i= 0; i < n; i++) {
                cnt[j][grid[i][j]]++;
            }
        }
        for (int i = 0; i <= 9; i++) {
            dp[m][i] = 0;
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int last = 0; last <= 9; last++) {
                int res = INT_MAX;
                for (int j = 0; j <= 9; j++) {
                    if (j != last) {
                        int cost = n - cnt[i][j];
                        res = min(res, cost + dp[i + 1][j]);
                    }
                }
                dp[i][last] = res;
                
            }
        }
        int ans = INT_MAX;
        for (int last = 0; last <= 9; last++) {
            ans = min(ans, dp[0][last]);
        }
        return ans;
    }
};