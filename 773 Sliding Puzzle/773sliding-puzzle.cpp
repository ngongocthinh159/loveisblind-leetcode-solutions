#define UNVISIT -2
class Solution {
public:
    vector<vector<int>> moves = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int slidingPuzzle(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        unordered_set<string> S;
        deque<string> q;
        string src = "";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) src += (board[i][j] + '0');
        }
        q.push_front(src);
        S.insert(src);
        int level = 0;
        string dest = "123450";
        while (q.size()) {
            int size = q.size();
            for (int cnt = 0; cnt < size; cnt++) {
                auto u = q.back(); q.pop_back();
                
                if (u == dest) return level;
                int i, j;
                for (int k = 0; k < n*m; k++) {
                    if (u[k] == '0') {
                        i = k/m;
                        j = k%m;
                        break;
                    }
                }
                
                string v = u;
                for (auto &move : moves) {
                    int I = i + move[0];
                    int J = j + move[1];
                    if (0 <= I && I < n && 0 <= J && J < m) {
                        swap(v[i*m + j], v[I*m + J]);
                        if (!S.count(v)) {
                            S.insert(v);
                            q.push_front(v);
                        }
                        swap(v[i*m + j], v[I*m + J]);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};