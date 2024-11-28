class Solution {
public:
    vector<vector<int>> moves = {{0,1},{1,0},{0,-1},{-1,0}};
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int IINF = 1e8;
        vector<vector<int>> dist(n, vector<int>(m, IINF));
        deque<pair<int,int>> q;
        dist[0][0] = 0;
        q.push_front({0,0});
        while (q.size()) {
            int size = q.size();
            for (int cnt = 0; cnt < size; cnt++) {
                auto p = q.front(); q.pop_front();
                int i = p.first;
                int j = p.second;
                int w_u = dist[i][j];
                for (auto &move : moves) {
                    int I = i + move[0];
                    int J = j + move[1];
                    if (0 <= I && I < n && 0 <= J && J < m) {
                        int w_uv = grid[I][J];
                        if (dist[I][J] > w_u + w_uv) {
                            dist[I][J] = w_u + w_uv;
                            if (w_uv == 0) q.push_front({I,J});
                            if (w_uv == 1) q.push_back({I,J});
                        }
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};