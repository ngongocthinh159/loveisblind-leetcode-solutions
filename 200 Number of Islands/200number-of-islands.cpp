class Solution {
public:
    vector<vector<bool>> visited;
    int n, m;
    vector<vector<int>> moves = {{0,1},{1,0},{0,-1},{-1,0}};
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        visited.assign(n, vector<bool>(m, false));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    visited[i][j] = true;
                    dfs(i, j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    void dfs(int i, int j, vector<vector<char>> &grid) {
        for (auto &move : moves) {
            int I = i + move[0];
            int J = j + move[1];
            if (0 <= I && I < n && 0 <= J && J < m) {
                if (!visited[I][J] && grid[I][J] == '1') {
                    visited[I][J] = true;
                    dfs(I, J, grid);
                }
            }
        }
    }
};