class Solution {
public:
    vector<pair<int,int>> moves = {{1,0},{0,1},{-1,0},{0,-1}};
    int n, m, sum;
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited, int &sum) {
        visited[i][j] = true;
        sum += grid[i][j];
        for (auto &move : moves) {
            int I = i + move.first;
            int J = j + move.second;
            if (0 <= I && I < n && 0 <= J && J < m && !visited[I][J] && grid[I][J]) {
                dfs(I, J, grid, visited, sum);
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m, false));
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (grid[i][j] && !visited[i][j]) {
                    sum = 0;
                    dfs(i, j, grid, visited, sum);
                    ans = max(ans, sum);
                }
            }
        return ans;
    }
};