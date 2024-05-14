class Solution {
public:
    int n, m;
    vector<vector<bool>> visited;
    int res = 0;
    vector<vector<int>> moves = {{1,0},{0,1},{-1,0},{0,-1}};
    int totalGold = 0;
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                totalGold += grid[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    visited[i][j] = true;
                    dfs(i, j, grid[i][j], grid);
                    visited[i][j] = false;
                }
            }
        }
        return res;
    }
    void dfs(int i, int j, int cur, vector<vector<int>> &grid) {
        res = max(res, cur);
        if (res == totalGold) return;
        for (auto &move : moves) {
            int I = move[0] + i;
            int J = move[1] + j;
            if (0 <= I && I < n && 0 <= J && J < m) {
                if (!visited[I][J] && grid[I][J]) {
                    visited[I][J] = true;
                    dfs(I, J, cur + grid[I][J], grid);
                    visited[I][J] = false;
                }
            }
        }
    } 
};