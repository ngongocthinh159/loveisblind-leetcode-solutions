class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size(), rep, miss;
        vector<bool> vis(n*n + 1, false);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (vis[grid[i][j]]) {
                    rep = grid[i][j];
                } else {
                    vis[grid[i][j]] = true;
                }
            } 
        for (int i = 1; i <= n*n; i++) if (!vis[i]) {
            miss = i;
            break;
        }
        return {rep, miss};
    }
};