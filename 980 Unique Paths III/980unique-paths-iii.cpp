class Solution {
public:
    vector<pair<int,int>> moves = {{1,0},{0,1},{-1,0},{0,-1}};
    int res = 0;
    void dfs(int i, int j, int cnt, int cells, int i_e, int j_e, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        vis[i][j] = true;
        if (i == i_e && j == j_e) {
            if (cnt == cells) res++;
        } else {
            for (auto &move : moves) {
                int I = i + move.first;
                int J = j + move.second;
                if (0 <= I && I < grid.size() && 0 <= J && J < grid[0].size() && grid[I][J] != -1 && !vis[I][J]) {
                    dfs(I, J, cnt + 1, cells, i_e, j_e, grid, vis);
                }
            }
        }
        vis[i][j] = false;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        int i_s, j_s, i_e, j_e, cells = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    i_s = i, j_s = j;
                if (grid[i][j] == 2)
                    i_e = i, j_e = j;
                if (grid[i][j] != -1) cells++;
            }
        dfs(i_s, j_s, 1, cells, i_e, j_e, grid, vis);
        return res;
    }
};