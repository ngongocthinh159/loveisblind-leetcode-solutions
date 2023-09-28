class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int,int>> move = {{-1,0},{0,-1},{1,0},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int cnt = 0;
                for (int k = 0; k < move.size(); k++) {
                    int nextX = i + move[k].first;
                    int nextY = j + move[k].second;

                    if (0 <= nextX && nextX < board.size() && 
                    0 <= nextY && nextY < board[0].size() && 
                    (board[nextX][nextY] == 1 || board[nextX][nextY] == -1)) cnt++;
                }
                if (cnt < 2) {
                    if (board[i][j] == 1) board[i][j] = -1;
                }
                else if (cnt > 3) {
                    if (board[i][j] == 1) board[i][j] = -1;
                }
                else if (cnt == 3) {
                    if (board[i][j] == 0) board[i][j] = -2;
                }
            }
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == -1) board[i][j] = 0;
                if (board[i][j] == -2) board[i][j] = 1;
            }
        }
    }
};