class Solution {
public:
    vector<vector<int>> es;
    const long long LINF = 1e18;
    int N;
    long long getDistance(int idx) {
        vector<vector<pair<int,int>>> g(N);
        int m = es.size();
        for (int i = idx; i < m; i++) {
            int u = es[i][0];
            int v = es[i][1];
            int w = es[i][2];
            g[u].push_back({v, w});
        }
        vector<long long> dist(N, LINF);
        dist[0] = 0;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> q;
        q.push({0, 0});
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
        return dist[N - 1];
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        N = online.size();
        for (auto &e : edges) {
            if (online[e[0]] && online[e[1]]) {
                es.push_back(e);
            }
        }
        sort(es.begin(), es.end(), [&](auto &e1, auto &e2) {
            return e1[2] < e2[2];
        });
        int l = -1, r = es.size();
        while (r - l > 1) {
            int m = l + (r - l)/2;
            long long D = getDistance(m);
            if (D > k || D == LINF)
                r = m;
            else
                l = m;
        }
        return (l == -1) ? -1 : es[l][2];
    }
};