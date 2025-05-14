class Solution {
public:
    vector<vector<int>> dist;
    vector<vector<int>> g;
    int N;
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        N = n;
        dist.assign(n, vector<int>(n));
        g.resize(n);
        for (auto &e : edges) {
            g[e[0] - 1].push_back(e[1] - 1);
            g[e[1] - 1].push_back(e[0] - 1);
        }
        for (int i = 0; i < n; i++) {
            bfs(i);
        }
        vector<int> ans(n - 1);
        for (int mask = 0; mask < (1 << n); mask++) {
            if (__builtin_popcount(mask) < 2) continue;
            unordered_set<int> vertices;
            for (int i = 0; i < n; i++) if ((mask >> i) & 1) vertices.insert(i);
            int cnt = 0;
            dfs(*vertices.begin(), -1, cnt, vertices);
            if (cnt != vertices.size()) continue;
            int d = 0;
            for (auto u : vertices)
                for (auto v : vertices) 
                    d = max(d, dist[u][v]);
            ans[d - 1]++;
        }
        return ans;
    }
    void dfs(int u, int p, int &cnt, unordered_set<int> &vertices) {
        cnt++;
        for (auto v : g[u]) if (v != p && vertices.count(v))
            dfs(v, u, cnt, vertices);
    }
    void bfs(int src) {
        vector<bool> vis(N);
        vis[src] = true;
        deque<int> q;
        q.push_front(src);
        int level = 0;
        while (q.size()) {
            int sz = q.size();
            while (sz--) {
                auto u = q.back();
                q.pop_back();
                dist[src][u] = level;
                for (auto v : g[u]) if (!vis[v]) {
                    vis[v] = true;
                    q.push_front(v);
                }
            }
            level++;
        }
    }
};