class Solution {
public:
    void dfs(int u, vector<vector<int>> &g, int &cnt, vector<bool> &visited) {
        cnt++;
        visited[u] = true;
        for (auto v : g[u]) {
            if (!visited[v]) dfs(v, g, cnt, visited);
        }
    }
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> g(n*m);
        vector<bool> visited(n*m);
        for (int i = 0; i < n; i++) {
            int prev_i = -1, prev_j = -1;
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    if (!(prev_i == -1 && prev_j == -1)) {
                        int u = prev_i*m + prev_j;
                        int v = i*m + j;
                        g[u].push_back(v);
                        g[v].push_back(u);
                    }
                    prev_i = i; prev_j = j;
                }
            }
        }
        for (int j = 0; j < m; j++) {
            int prev_i = -1, prev_j = -1;
            for (int i = 0; i < n; i++) {
                if (grid[i][j]) {
                    if (!(prev_i == -1 && prev_j == -1)) {
                        int u = prev_i*m + prev_j;
                        int v = i*m + j;
                        g[u].push_back(v);
                        g[v].push_back(u);
                    }
                    prev_i = i; prev_j = j;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n*m; i++) {
            int cnt = 0;
            if (!visited[i]) {
                dfs(i, g, cnt, visited);
            }
            if (cnt > 1) ans += cnt;
        }
        return ans;
    }
};