class Solution {
public:
    void dfs(int u, vector<vector<int>>& g, vector<int> &color, vector<bool> &is_safe) {
        color[u] = 2;
        for (auto v : g[u]) {
            if (color[v] == 2) 
                is_safe[u] = false;
            else if (!color[v])
                dfs(v, g, color, is_safe);
            is_safe[u] = is_safe[u] & is_safe[v];
        }
        color[u] = 1;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> is_safe(n, true);
        vector<int> color(n), res;
        for (int i = 0; i < n; i++) if (color[i] == 0)
            dfs(i, graph, color, is_safe);
        for (int i = 0; i < n; i++) if (is_safe[i]) 
            res.push_back(i);
        return res;
    }
};