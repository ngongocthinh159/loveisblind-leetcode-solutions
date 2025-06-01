class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int label = 1;
        const int IINF = 1e9;
        vector<pair<int,int>> labelToPos(n * n + 1, pair<int,int>());
        vector<int> dist(n * n +1, IINF);
        for (int i = n - 1; i >= 0; i--) {
            if ((n - i - 1)&1) {
                for (int j = n - 1; j >= 0; j--) {
                    labelToPos[label++] = {i, j};
                }
            } else {
                for (int j = 0; j < n; j++) {
                    labelToPos[label++] = {i, j};
                }
            }
        }
        dist[1] = 0;
        deque<int> q;
        q.push_front(1);
        while (q.size()) {
            for (auto sz = q.size(); sz; sz--) {
                auto u = q.back();
                q.pop_back();
                for (int nxt = u + 1; nxt <= min(u + 6, n*n); nxt++) {
                    auto [i, j] = labelToPos[nxt];
                    int v = nxt;
                    if (board[i][j] != -1) {
                        v = board[i][j];
                    }
                    if (dist[v] > dist[u] + 1) {
                        dist[v] = dist[u] + 1;
                        q.push_front(v);
                    }
                }
            }
        }
        return dist[n*n] == IINF ? -1 : dist[n*n];
    }
};