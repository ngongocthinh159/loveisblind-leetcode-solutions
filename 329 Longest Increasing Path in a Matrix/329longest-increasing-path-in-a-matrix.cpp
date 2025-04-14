class Solution {
public:
    vector<pair<int,int>> moves = {{0,1},{1,0},{0,-1},{-1,0}};
    int dfs(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &a, int n, int m) {
        if (dp[i][j] != -1) return dp[i][j];
        int res = 0;
        for (auto &move : moves) {
            int I = i + move.first;
            int J = j + move.second;
            if (0 <= I && I < n && 0 <= J && J < m && a[I][J] > a[i][j]) {
                res = max(res, dfs(I, J, dp, a, n, m));
            }
        }
        return dp[i][j] = res + 1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0, n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, dp, matrix, n, m));
            }
        return ans;
    }
};