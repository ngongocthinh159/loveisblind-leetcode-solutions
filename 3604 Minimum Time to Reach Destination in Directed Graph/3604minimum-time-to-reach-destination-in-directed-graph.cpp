#define ll long long
class Solution {
public:
    const ll LINF = 1e18;
    int minTime(int n, vector<vector<int>>& edges) {
        auto compare = [](pair<ll,int> &p1, pair<ll,int>& p2) {
            return p2.first < p1.first;
        };
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,decltype(compare)> q(compare);
        vector<vector<int>> g(n);
        for (int i = 0; i < (int) edges.size(); i++) {
            g[edges[i][0]].push_back(i);
        }
        vector<ll> dist(n, LINF);
        dist[0] = 0;
        q.push({0,0});
        while (q.size()) {
            auto [w_u, u] = q.top();
            q.pop();
            if (dist[u] > w_u)
                continue;
            if (u == n - 1)
                return w_u;
            for (auto j : g[u]) {
                auto [_u, _v, s, e] = tie(edges[j][0], edges[j][1], edges[j][2], edges[j][3]);
                int v = _u ^ _v ^ u;
                ll w_v = -1;
                if (s <= w_u && w_u <= e) 
                    w_v = w_u + 1;
                else if (w_u < s)
                    w_v = s + 1;
                if (w_v != -1 && dist[v] > w_v) {
                    dist[v] = w_v;
                    q.push({dist[v], v});
                }
            }
        }
        return -1;
    }
};