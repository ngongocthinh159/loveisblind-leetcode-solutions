class Solution {
public:
    int ans = 0;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> g(n);
        for (int v = 0; v < n; v++) {
            int u = manager[v];
            if (u != -1) {
                g[u].push_back(v);
            }
        }
        dfs(headID, informTime[headID], g, informTime);
        return ans;
    }
    void dfs(int u, int sum, vector<vector<int>>& g, vector<int>& informTime) {
        if (g[u].size() == 0) return;
        ans = max(ans, sum);
        for (auto &v : g[u]) {
            dfs(v, sum + informTime[v], g, informTime);
        }
    }
};