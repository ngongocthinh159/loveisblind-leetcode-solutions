class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        deque<pair<int,int>> q;
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m));
        vector<vector<int>> res(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) q.push_front({i, j}), visited[i][j] = true;
            }
        vector<vector<int>> moves = {{1,0},{0,1},{-1,0},{0,-1}};
        int level = 0;
        while (q.size()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto p = q.back(); q.pop_back();
                int x_u = p.first;
                int y_u = p.second;
                res[x_u][y_u] = level;
                for (auto &move : moves) {
                    int I = move[0] + x_u;
                    int J = move[1] + y_u;
                    if (0 <= I && I < n && 0 <= J && J < m) {
                        if (!visited[I][J]) {
                            visited[I][J] = true;
                            q.push_front({I, J});
                        }
                    }
                }
            }
            level++;
        }
        return res;
    }
};