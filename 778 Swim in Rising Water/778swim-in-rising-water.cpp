class Solution {
public:
    struct comparator {
        bool operator() (const vector<int> &v1, const vector<int> &v2) const {
            return v2[0] < v1[0];
        }
    };
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, comparator> q;
        q.push({0, 0, 0});
        vector<vector<int>> moves = {{1,0},{0,1},{-1,0},{0,-1}};
        int t = 0;
        while (q.size()) {
            auto u = q.top(); q.pop();
            int w_u = u[0];
            for (auto &move : moves) {
                int I = u[1] + move[0];
                int J = u[2] + move[1];
                if (0 <= I && I < n && 0 <= J && J < m) {
                    int w_v = max(w_u, max(grid[I][J], grid[u[1]][u[2]]));
                    // cout << w_v << "\n";
                    if (dist[I][J] > w_v) {
                        dist[I][J] = w_v;
                        q.push({dist[I][J], I, J});
                    }
                }
            }
        }
            // for (int i = 0; i < n; i++) {
            //     for (int j = 0; j < m; j++) {
            //         cout << dist[i][j] << " ";
            //     }
            //     cout << "\n";
            // }
            // cout << "\n";
        return dist[n - 1][m - 1];
    }
};