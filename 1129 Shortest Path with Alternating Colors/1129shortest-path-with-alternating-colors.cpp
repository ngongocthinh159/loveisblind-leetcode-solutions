class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> dist(n, vector<int>(2, INT_MAX));
        vector<vector<pair<int,int>>> g(n);
        for (auto &e : redEdges) {
            g[e[0]].push_back({e[1], 0});
        }
        for (auto &e : blueEdges) {
            g[e[0]].push_back({e[1], 1});
        }
        deque<pair<int, int>> q;
        q.push_front({0, 0});
        q.push_front({0, 1}); 
        dist[0][0] = 0;
        dist[0][1] = 0;
        while (q.size()) {
            int sz = q.size();
            for (int j = 0; j < sz; j++) {
                auto p = q.back();
                q.pop_back();
                int u = p.first;
                int color = p.second;
                for (auto &nei : g[u]) {
                    int v = nei.first;
                    int next_color = nei.second;
                    if (next_color != color && dist[v][next_color] == INT_MAX) {
                        dist[v][next_color] = dist[u][color] + 1;
                        q.push_front({v, next_color});
                    }
                }
            }
        }
        vector<int> ans(n, INT_MAX);
        for (int i = 0; i < n; i++) {
            ans[i] = min(dist[i][0], dist[i][1]);
            if (ans[i] == INT_MAX) ans[i] = -1;
        }
        return ans;
    }
};