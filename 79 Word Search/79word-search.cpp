class Solution {
public:
    vector<vector<bool>> visited;
    vector<vector<int>> moves = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        visited = vector<vector<bool>>(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(i, j, 0, board, word)) return true;
            }
        }
        return false;
    }
    bool dfs(int x, int y, int i, vector<vector<char>> &board, string &word) {
        if (i == word.size() - 1 && board[x][y] == word[i]) return true;
        if (board[x][y] != word[i]) return false;

        visited[x][y] = true;
        bool res = false;
        for (auto &move : moves) {
            int X = x + move[0];
            int Y = y + move[1];
            if (0 <= X && X < board.size() && 0 <= Y && Y < board[0].size()) {
                if (!visited[X][Y] && board[X][Y] == word[i + 1]) {
                    res |= dfs(X, Y, i + 1, board, word);
                    if (res) break;
                }
            }
        }
        visited[x][y] = false;
        return res;
    }
};