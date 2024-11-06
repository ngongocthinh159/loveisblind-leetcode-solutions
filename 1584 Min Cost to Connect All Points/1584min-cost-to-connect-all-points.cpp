class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        set<pair<int,int>> S;
        int n = points.size();
        S.insert({0,0});
        vector<int> min_e(n, 1e8);
        vector<bool> visited(n);
        min_e[0] = 0;
        int ans = 0;
        while (S.size()) {
            auto p = *S.begin();
            S.erase(S.begin());
            int w = p.first;
            int u = p.second;

            visited[u] = true;
            ans += w;

            for (int v = 0; v < n; v++) {
                if (v != u && !visited[v]) {
                    int w_uv = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    if (min_e[v] > w_uv) {
                        S.erase({min_e[v], v});
                        min_e[v] = w_uv;
                        S.insert({min_e[v], v});
                    }
                }
            }
        }
        return ans;
    }
};