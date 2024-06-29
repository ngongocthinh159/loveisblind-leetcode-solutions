class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
        }
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++) {
            dfs(i, i, ans, g);
        }
        return ans;
    }
    void dfs(int root, int u, vector<vector<int>> &ans, vector<vector<int>> &g) {
        for (auto v : g[u]) {
            if (ans[v].size() && ans[v].back() == root) continue;
            ans[v].push_back(root);
            dfs(root, v, ans, g);
        }
    }
};