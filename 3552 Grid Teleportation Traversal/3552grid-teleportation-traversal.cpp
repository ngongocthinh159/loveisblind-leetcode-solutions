pair<int,int> q[1000005];
class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<pair<int,int>> moves = {{1,0},{0,1},{-1,0},{0,-1}};
        const int IINF = 1e9 ;
        vector<vector<int>> dist(n, vector<int>(m, IINF));
        vector<vector<pair<int,int>>> letterToPos(26, vector<pair<int,int>>());
        int top = 0, tail = 0;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) if ('A' <= matrix[i][j] && matrix[i][j] <= 'Z')
                letterToPos[matrix[i][j] - 'A'].push_back({i, j});
        if ('A' <= matrix[0][0] && matrix[0][0] <= 'Z') {
            for (auto &p : letterToPos[matrix[0][0] - 'A']) {
                q[top++] = p;
                dist[p.first][p.second] = 0;
            }
        } else {
            q[top++] = {0, 0};
            dist[0][0] = 0;
        }
        while (tail != top) {
            for (int sz = top - tail; sz; sz--) {
                auto [i, j] = q[tail++];
                for (auto move : moves) {
                    int I = i + move.first;
                    int J = j + move.second;
                    if (0 <= I && I < n && 0 <= J && J < m && matrix[I][J] != '#') {
                        if (dist[I][J] > dist[i][j] + 1) {
                            if ('A' <= matrix[I][J] && matrix[I][J] <= 'Z') {
                                for (auto &p : letterToPos[matrix[I][J] - 'A']) {
                                    dist[p.first][p.second] = dist[i][j] + 1;
                                    q[top++] = {p.first, p.second};
                                }
                            } else {
                                dist[I][J] = dist[i][j] + 1;
                                q[top++] = {I, J};
                            }
                        }
                    }
                }
            }
        }
        return dist[n - 1][m - 1] == IINF ? -1 : dist[n - 1][m - 1];
    }
};