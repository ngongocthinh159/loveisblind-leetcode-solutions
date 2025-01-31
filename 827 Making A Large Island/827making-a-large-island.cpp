class Solution {
public:
    vector<pair<int,int>> moves = {{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited, int &sz, int id) {
        sz++;
        grid[i][j] = id;
        visited[i][j] = true;
        for (auto &move : moves) {
            int I = move.first + i;
            int J = move.second + j;
            if (0 <= I && I < grid.size() && 0 <= J && J < grid[0].size()) {
                if (grid[I][J] && !visited[I][J]) {
                    dfs(I, J, grid, visited, sz, id);
                }
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m));
        vector<int> _size(n*m + 1);
        int mx = 0;
        int id = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (grid[i][j] && !visited[i][j]) {
                    int sz = 0;
                    ++id;
                    dfs(i, j, grid, visited, sz, id);
                    mx = max(mx, sz);
                    _size[id] = sz;
                }
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (!grid[i][j]) {
                    int compo_sz = 1;
                    unordered_set<int> S;
                    for (auto &move : moves) {
                        int I = move.first + i;
                        int J = move.second + j;
                        if (0 <= I && I < n && 0 <= J && J < m) {
                            if (grid[I][J]) S.insert(grid[I][J]);
                        }
                    }
                    for (auto _id : S) compo_sz += _size[_id];
                    mx = max(mx, compo_sz);
                }
            }
        return mx;
    }
};