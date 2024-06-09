class Solution {
public:
    vector<vector<vector<int>>> g;
    vector<bool> ans;
    vector<int> dist2;
    int shortestPath;
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        dist2 = vector(n, INT_MAX);
        g.resize(n);
        ans.resize(edges.size());
        for (int i = 0; i < edges.size(); i++) {
            g[edges[i][0]].push_back({edges[i][1], edges[i][2], i});
            g[edges[i][1]].push_back({edges[i][0], edges[i][2], i});
        }
        dijkstra(n - 1, dist2);
        shortestPath = dist2[0];
        dfs(0, 0);
        return ans;
    }
    void dfs(int u, int cost_to_u) {
        for (auto &p : g[u]) {
            int v = p[0];
            int w_uv = p[1];
            int idx = p[2];
            if (!ans[idx]) {
                if (dist2[v] != INT_MAX && cost_to_u + w_uv + dist2[v] == shortestPath) {
                    ans[idx] = true;
                    dfs(v, cost_to_u + w_uv);
                }
            }
        }
    }
    void dijkstra(int src, vector<int> &dist) {
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> pq;
        pq.push({src, 0});
        int u, w_u, v, w_uv;
        while (pq.size()) {
            auto p = pq.top(); pq.pop();
            u = p.first;
            w_u = p.second;
            for (auto &cur : g[u]) {
                v = cur[0];
                w_uv = cur[1];
                if (w_u + w_uv < dist[v]) {
                    dist[v] = w_u + w_uv;
                    pq.push({v, dist[v]});
                }
            }
        }
    }
};