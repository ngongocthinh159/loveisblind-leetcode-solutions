class Solution {
public:
    void rotate90(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ngrid(m, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) ngrid[j][i] = grid[i][j];
        swap(n, m);
        for (int i = 0; i < n; i++)
            for (int j = 0, k = m - 1; j < k; j++, k--) 
                swap(ngrid[i][j], ngrid[i][k]);
        grid = ngrid;
    }
    int solve(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp1(n, vector<int>(m));
        vector<vector<int>> dp2(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = m - 1; j >= 0; j--) if (grid[i][j] != 1) {
                if (i - 1 >= 0 && j + 1 < m && grid[i - 1][j + 1] != 1 &&
                grid[i - 1][j + 1] != grid[i][j])
                    dp1[i][j] = 1 + dp1[i - 1][j + 1];
                else
                    dp1[i][j] = 1;
            }
        int ans = 0;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    ans = max(ans, 1);
                    if (i - 1 >= 0 && j - 1 >= 0 && grid[i - 1][j - 1] == 2)
                        ans = max(ans, 1 + dp2[i - 1][j - 1]);
                } else {
                    dp2[i][j] = dp1[i][j];
                    if (i - 1 >= 0 && j - 1 >= 0 && grid[i - 1][j - 1] != 1 &&
                    grid[i - 1][j - 1] != grid[i][j]) 
                        dp2[i][j] = max(dp2[i][j], 1 + dp2[i - 1][j - 1]);
                }
            }
        return ans;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            ans = max(ans, solve(grid));
            int n = grid.size(), m = grid[0].size();
            rotate90(grid);
        }
        return ans;
    }
};