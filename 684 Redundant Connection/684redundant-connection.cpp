class Solution {
public:
    int start_v = -1, idx = -1;
    bool dfs(int u, vector<vector<int>> &g, vector<vector<int>>& edges, vector<int> &color, int ii) {
        color[u] = 1;
        int v;
        for (auto i : g[u]) if (i != ii) {
            v = edges[i][1]^edges[i][0]^u;
            if (color[v] == 1) {
                idx = max(idx, i);
                start_v = v;
                return true;
            }
            if (color[v] == 0) {
                if (dfs(v, g, edges, color, i)) {
                    idx = max(idx, i);
                    if (start_v == u) {
                        return false;
                    }
                    return true;
                }
            }
        }
        color[u] = 2;
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> g(n + 1);
        vector<int> color(n + 1);
        for (int i = 0; i < n; i++) g[edges[i][0]].push_back(i), g[edges[i][1]].push_back(i);
        dfs(1, g, edges, color, -1);
        return {edges[idx][0], edges[idx][1]};
    }
};