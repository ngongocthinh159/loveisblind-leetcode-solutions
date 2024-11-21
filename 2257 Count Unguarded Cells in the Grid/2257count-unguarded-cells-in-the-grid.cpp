class Solution {
public:
    vector<vector<int>> moves = {{-1,0},{0,1},{1,0},{0,-1}};
    void dfs(int i, int j, int n, int m, vector<vector<char>> &grid, int dir) {
        if (grid[i][j] == 'G' || grid[i][j] == 'W') return;
        grid[i][j] = '#';
        int I = i + moves[dir][0];
        int J = j + moves[dir][1];
        if (0 <= I && I < n && 0 <= J && J < m && grid[I][J] != 'G' && grid[I][J] != 'W') {
            dfs(I, J, n, m, grid, dir);
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        swap(n, m);
        vector<vector<char>> grid(n, vector<char>(m));
        for (auto &g : guards) grid[g[0]][g[1]] = 'G';
        for (auto &w : walls) grid[w[0]][w[1]] = 'W';
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'G') {
                    for (int dir = 0; dir < 4; dir++) {
                        int I = i + moves[dir][0];
                        int J = j + moves[dir][1];
                        if (0 <= I && I < n && 0 <= J && J < m)
                            dfs(I, J, n, m, grid, dir);
                    }
                }
            }
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] != 'G' && grid[i][j] != 'W' && grid[i][j] != '#')
                    cnt++;
        return cnt;
    }
};