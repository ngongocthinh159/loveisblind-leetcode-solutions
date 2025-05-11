class Solution {
public:
    int n, m;
    vector<pair<int,int>> moves = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<bool>> vis;
    void dfs(int i, int j, int &cells, vector<vector<int>>& grid) {
        vis[i][j] = true;
        cells++;
        for (auto &move : moves) {
            int I = i + move.first;
            int J = j + move.second;
            if (0 <= I && I < n && 0 <= J && J < m && !vis[I][J] && grid[I][J]) {
                vis[I][J] = true;
                dfs(I, J, cells, grid);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vis.assign(n, vector<bool>(m));
        int ans = 0;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) if (!vis[i][j] && grid[i][j]){
                int cells = 0;
                dfs(i, j, cells, grid);
                ans = max(ans, cells);
            }
        return ans;
    }
};