class Solution {
public:
    unordered_set<string> S;
    unordered_set<string> res;
    vector<vector<int>> moves = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    vector<vector<bool>> visited;
    int mx;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (auto &word : words) {
            S.insert(word);
            mx = max(mx, (int) word.size());
        }
        int n = board.size();
        int m = board[0].size();
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        string cur = "";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i][j] = true;
                cur += board[i][j];
                dfs(i, j, cur, board);
                cur.pop_back();
                visited[i][j] = false;
            }
        }
        return vector<string>(res.begin(), res.end());
    }
    void dfs(int i, int j, string &cur, vector<vector<char>> &board) {
        if (S.count(cur)) {
            res.insert(cur);
        }
        if (cur.size() >= mx) return;
        for (auto &move : moves) {
            int I = move[0] + i;
            int J = move[1] + j;
            if (0 <= I && I < board.size() && 0 <= J && J < board[0].size()) {
                if (!visited[I][J]) {
                    visited[I][J] = true;
                    cur += board[I][J];
                    dfs(I, J, cur, board);
                    cur.pop_back();
                    visited[I][J] = false;
                }
            }
        }
    }
};