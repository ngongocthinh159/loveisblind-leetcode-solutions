class Solution {
public:
    vector<vector<int>> moves = {{1, 0}, {0, 1}};
    int m, n;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return explore(obstacleGrid, dp, 0, 0);
    }

    int explore(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j) {
        if (grid[i][j] == 1) return 0;
        if (i == m - 1 && j == n - 1) return 1;
        if (dp[i][j] != -1) return dp[i][j];

        int res = 0;
        for (int k = 0; k < moves.size(); k++) {
            int newI = i + moves[k][0];
            int newJ = j + moves[k][1];

            if (0 <= newI && newI < grid.size() && 0 <= newJ && newJ < grid[0].size()) {
                res += explore(grid, dp, newI, newJ);
            } 
        }
        return dp[i][j] = res;
    }
};