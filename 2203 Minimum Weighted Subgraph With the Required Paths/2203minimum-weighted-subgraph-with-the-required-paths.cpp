#define ll long long
class Solution {
public:
    const ll LINF = 1e18;
    vector<ll> dijkstra(int src, vector<vector<pair<int,int>>> &g) {
        int n = g.size();
        vector<ll> dist(n, LINF);
        dist[src] = 0;
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> q;
        q.push({0, src});
        while (q.size()) {
            auto [w_u, u] = q.top();
            q.pop();
            if (w_u > dist[u]) continue;
            for (auto [v, w_uv] : g[u]) {
                if (dist[v] > w_u + w_uv) {
                    dist[v] = w_u + w_uv;
                    q.push({dist[v], v});
                }
            }
        }
        return move(dist);
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,int>>> g, rg;
        g.resize(n);
        rg.resize(n);
        for (auto &e : edges) {
            g[e[0]].push_back({e[1], e[2]});
            rg[e[1]].push_back({e[0], e[2]});
        }
        auto d1 = dijkstra(src1, g);
        auto d2 = dijkstra(src2, g);
        auto d3 = dijkstra(dest, rg);
        ll ans = LINF;
        for (int i = 0; i < n; i++) {
            if (d1[i] != LINF && d2[i] != LINF && d3[i] != LINF) {
                ans = min(ans, d1[i] + d2[i] + d3[i]);
            }
        }
        return ans == LINF ? -1 : ans;
    }
};