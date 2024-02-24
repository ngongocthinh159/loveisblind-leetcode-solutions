class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        int mx = max(m,n);
        vector<vector<int>> g(mx+1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isConnected[i][j]) g[i+1].push_back(j+1);
            }
        }
        int ans = 0;
        vector<bool> visited(mx + 1, false);
        for (int i = 1; i <= mx; i++) {
            if (!visited[i]) {
                visited[i] = true;
                dfs(i, g, visited);
                ans++;
            }
        }
        return ans;
    }
    void dfs(int u, vector<vector<int>> &g, vector<bool> &visited) {
        for (auto v : g[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dfs(v, g, visited);
            }
        }
    }
};