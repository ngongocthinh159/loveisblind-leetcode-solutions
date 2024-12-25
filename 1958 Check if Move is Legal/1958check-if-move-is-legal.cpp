class Solution {
public:
    vector<vector<int>> moves = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    bool isValid(vector<vector<char>>& board, int rMove, int cMove, char color, vector<int> &move) {
        char oppo_color = color^'B'^'W';
        int n = board.size();
        int m = board[0].size();
        int i = rMove + move[0];
        int j = cMove + move[1];
        if (!(0 <= i && i < n && 0 <= j && j < m) || board[i][j] == '.') return false;
        bool ok1 = false;
        while (0 <= i && i < n && 0 <= j && j < m && board[i][j] == oppo_color) {
            ok1 = true;
            i = i + move[0];
            j = j + move[1];
        }
        if (!ok1) return false;
        if (0 <= i && i < n && 0 <= j && j < m && board[i][j] == color) return true;
        return false;
    }
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        for (auto move : moves) {
            if (isValid(board, rMove, cMove, color, move)) return true;
        }
        return false;
    }
};