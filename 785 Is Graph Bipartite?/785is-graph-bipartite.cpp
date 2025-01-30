class Solution {
public:
    vector<int> color;
    int n;
    bool is_bipartile = true;
    void bfs(int src, vector<vector<int>> &g) {
        color[src] = 0;
        deque<int> q;
        q.push_front(src);
        while (q.size()) {
            int sz = q.size();
            while (sz--) {
                int u = q.back(); q.pop_back();
                for (auto v : g[u]) {
                    if (color[v] == -1) {
                        color[v] = color[u]^1;
                        q.push_front(v);
                    } else {
                        is_bipartile &= (color[v] != color[u]);
                    }
                }
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        color.assign(n, -1);
        for (int i = 0; i < n; i++) if (color[i] == -1) bfs(i, graph);
        return is_bipartile;
    }
};