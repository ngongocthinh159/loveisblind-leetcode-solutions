class Solution {
public:
    vector<vector<int>> g1, g2;
    int n, m;
    int dfs(int u, int p, int d, vector<vector<int>> &g) {
        if (d < 0) return 0;
        int res = 1;
        for (auto v : g[u]) if (v != p) {
            res += dfs(v, u, d - 1, g);
        }
        return res;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        n = edges1.size() + 1;
        m = edges2.size() + 1;
        g1.resize(n);
        g2.resize(m);
        for (auto &e : edges1) {
            g1[e[0]].push_back(e[1]);
            g1[e[1]].push_back(e[0]);
        }
        for (auto &e : edges2) {
            g2[e[0]].push_back(e[1]);
            g2[e[1]].push_back(e[0]);
        }
        int mx2 = 0;
        for (int i = 0; i < m; i++) {
            mx2 = max(mx2, dfs(i, -1, k - 1, g2));
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = dfs(i, -1, k, g1) + mx2;
        }
        return move(ans);
    }
};