#define ll long long
class Solution {
public:
    const ll LINF = 1e18;
    const int MOD = 1e9 + 7;
    struct comparator {
        bool operator () (pair<int,ll> &p1, pair<int,ll>&p2) {
            return p2.second < p1.second;
        }
    };
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> g(n);
        for (auto &r : roads) {
            g[r[0]].push_back({r[1], r[2]});
            g[r[1]].push_back({r[0], r[2]});
        }
        vector<pair<ll,ll>> dist(n, {LINF,0});
        vector<bool> visited(n);
        dist[0] = {0, 1};
        priority_queue<pair<int,ll>,vector<pair<int,ll>>,comparator> q;
        q.push({0, 0LL});
        while (q.size()) {
            auto p = q.top(); q.pop();
            int u = p.first;
            ll w_u = p.second;
            if (w_u > dist[u].first) continue;
            for (auto [v, w_uv] : g[u]) {
                if (w_u + w_uv < dist[v].first) {
                    dist[v] = {w_u + w_uv, dist[u].second};
                    q.push({v, dist[v].first});
                } else if (w_u + w_uv == dist[v].first) {
                    (dist[v].second += dist[u].second) %= MOD;
                }
            }
        }
        return dist[n - 1].second;
    }
};