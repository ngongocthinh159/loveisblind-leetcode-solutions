class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>> moves = {{-1,-1},{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        deque<pair<int,pair<int,int>>> q;
        q.push_front({0, {0, 0}});
        dist[0][0] = 0;
        while (q.size()) {
            auto p = q.front();
            q.pop_front();
            int w_u = p.first;
            int x_u = p.second.first;
            int y_u = p.second.second;
            for (int i = 1; i <= 4; i++) {
                int x_v = x_u + moves[i].first;
                int y_v = y_u + moves[i].second;
                if (0 <= x_v && x_v < n && 0 <= y_v && y_v < m) {
                    int w_uv = (grid[x_u][y_u] != i);
                    if (dist[x_v][y_v] > w_u + w_uv) {
                        dist[x_v][y_v] = w_u + w_uv;
                        if (w_uv) q.push_back({dist[x_v][y_v], {x_v, y_v}});
                        else q.push_front({dist[x_v][y_v], {x_v, y_v}});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};