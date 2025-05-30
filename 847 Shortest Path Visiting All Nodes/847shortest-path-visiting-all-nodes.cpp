class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        const int IINF = 1e9;
        vector<vector<int>> dist(n, vector<int>((1 << n), IINF));
        deque<pair<int,int>> q;
        for (int i = 0; i < n; i++) {
            q.push_front({i, (1 << i)});
            dist[i][1 << i] = 0;
        }
        int fMask = (1 << n) - 1;
        while (q.size()) {
            for (int sz = q.size(); sz; sz--) {
                auto [u, mask] = q.back();
                q.pop_back();
                for (auto v : graph[u]) {
                    int nmask = mask | (1 << v);
                    if (dist[v][nmask] > dist[u][mask] + 1) {
                        dist[v][nmask] = dist[u][mask] + 1;
                        q.push_front({v, nmask});
                        if (nmask == fMask) 
                            return dist[v][nmask];
                    }
                }
            }
        }
        return 0;
    }
};