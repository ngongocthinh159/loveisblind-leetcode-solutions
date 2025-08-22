class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        const int IINF = 1e9;
        vector<int> dist(n, IINF);
        vector<vector<pair<int,int>>> out(n), in(n);
        for (auto &e : edges) {
            out[e[0]].push_back({e[1], e[2]});
            in[e[1]].push_back({e[0], e[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0, 0});
        dist[0] = 0;
        while (q.size()) {
            auto [w_u, u] = q.top();
            q.pop();
            if (dist[u] > w_u) continue;
            for (auto [v, w_uv] : out[u]) {
                if (dist[v] > w_u + w_uv) {
                    dist[v] = w_u + w_uv;
                    q.push({dist[v], v});
                }
            }
            for (auto [v, w_uv] : in[u]) {
                if (dist[v] > w_u + 2*w_uv) {
                    dist[v] = w_u + 2*w_uv;
                    q.push({dist[v], v});
                }
            }
        }
        return dist[n - 1] == IINF ? -1 : dist[n - 1];
    }
};