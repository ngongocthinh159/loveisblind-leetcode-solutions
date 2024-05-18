class Solution {
public:
    vector<vector<int>> moves ={{1,0},{0,1},{-1,0},{0,-1}};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> safeFactor(n, vector<int>(n, -1));

        deque<pair<int,int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    q.push_front({i, j});
                    safeFactor[i][j] = 0;
                }
            }
        }

        int level = 1;
        while (q.size()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                auto cur = q.back(); q.pop_back();
                int i = cur.first;
                int j = cur.second;
                for (auto &move : moves) {
                    int I = i + move[0];
                    int J = j + move[1];
                    if (0 <= I && I < n && 0 <= J && J < n) {
                        if (safeFactor[I][J] == -1) {
                            safeFactor[I][J] = level;
                            q.push_front({I, J});
                        }
                    }
                }
            }
            level++;
        }
        
        vector<vector<int>> bestFactor(n, vector<int>(n, INT_MIN));
        q.clear();
        q.push_front({0,0});
        bestFactor[0][0] = safeFactor[0][0];
        while (q.size()) {
            auto cur = q.front(); q.pop_front();
            int i = cur.first;
            int j = cur.second;
            if (i == n - 1 && j == n - 1) break;
            for (auto &move : moves) {
                int I = i + move[0];
                int J = j + move[1];
                if (0 <= I && I < n && 0 <= J && J < n) {
                    int w_uv = safeFactor[I][J] >= bestFactor[i][j] ? 0 : 1;
                    int w_v = max(bestFactor[i][j] - w_uv, 0);
                    if (bestFactor[I][J] < w_v) {
                        bestFactor[I][J] = w_v;
                        if (w_uv == 1) q.push_back({I, J});
                        else q.push_front({I, J});
                    }
                }
            }
        }
        return bestFactor[n - 1][n - 1];
    }
};