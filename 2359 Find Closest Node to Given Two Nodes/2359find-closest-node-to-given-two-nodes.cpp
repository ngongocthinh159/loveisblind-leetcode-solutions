class Solution {
public:
    vector<vector<int>> g;
    int n;
    const int IINF = 1e9 + 5;
    vector<int> bfs(int src) {
        vector<int> dist(n, IINF);
        dist[src] = 0;
        deque<int> q;
        q.push_front(src);
        while (q.size()) {
            for (int sz = q.size(); sz; sz--) {
                auto u = q.back();
                q.pop_back();
                for (auto v : g[u]) if (dist[v] > dist[u] + 1) { 
                    dist[v] = dist[u] + 1;
                    q.push_front(v);
                }
            }
        }
        return move(dist);
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();
        g.resize(n);
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) 
                g[i].push_back(edges[i]);
        }
        auto d1 = bfs(node1);
        auto d2 = bfs(node2);
        int ans = IINF, res = -1;
        for (int i = 0; i < n; i++) {
            if (d1[i] != IINF && d2[i] != IINF) {
                if (ans > max(d1[i], d2[i])) {
                    ans = max(d1[i], d2[i]);
                    res = i;
                }
            }
        }
        return res;
    }
};