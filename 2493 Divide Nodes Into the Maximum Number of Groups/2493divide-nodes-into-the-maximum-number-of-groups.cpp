class Solution {
public:
    vector<vector<int>> g;
    vector<int> color, depth;
    vector<bool> visited;
    vector<set<pair<int,int>>> child;
    bool is_bipartile = true;
    int mx;
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
                        is_bipartile &= color[v] != color[u];
                    }
                }
            }
        }
    }
    void dfs(int u, vector<vector<int>> &g, vector<int> &compo) {
        visited[u] = true;
        compo.push_back(u);
        for (auto v : g[u]) if (!visited[v]) dfs(v, g, compo);
    }
    int bfs1(int src, vector<vector<int>> &g) {
        unordered_set<int> visited;
        visited.insert(src);
        deque<int> q;
        q.push_front(src);
        int level = -1;
        while (q.size()) {
            int sz = q.size();
            level++;
            while (sz--) {
                auto u = q.back(); q.pop_back();
                for (auto v : g[u]) {
                    if (!visited.count(v)) {
                        visited.insert(v);
                        q.push_front(v);
                    }
                }
            }
        }
        return level + 1;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        g.resize(n + 1);
        color.assign(n + 1, -1);
        visited.resize(n + 1);
        depth.resize(n + 1);
        child.resize(n + 1);
        for (auto &e : edges) g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
        
        // bipartile check
        for (int i = 1; i <= n; i++) if (color[i] == -1) bfs(i, g);
        if (!is_bipartile) return -1;
        
        int ans = 0;
        for (int i = 1; i <= n; i++) if (!visited[i]) {
            vector<int> compo;
            dfs(i, g, compo);
            int local_ans = 0;
            for (auto u : compo) local_ans = max(local_ans, bfs1(u, g));
            ans += local_ans;
        }
        return ans;
    }
};