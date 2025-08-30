bool row[9][10], col[9][10], sub[9][10];
class Solution {
public:
    int n = 9, m = 9;
    int get_sidx(int i, int j) {
        int ii = i / 3;
        int jj = j / 3;
        return ii * 3 + jj;
    }
    bool dfs(int i, int j, vector<vector<char>> &board) {
        if (i == n) {
            return true;
        }

        int I = i, J = j + 1;
        if (j == m - 1) {
            I = i + 1;
            J = 0;
        }

        int x = board[i][j] - '0';
        int sidx = get_sidx(i, j);
        if (board[i][j] != '.') {
            if (dfs(I, J, board))
                return true;
        } else {
            for (int k = 1; k <= 9; k++) if (!row[i][k] && !col[j][k] && !sub[sidx][k]) {
                row[i][k] = col[j][k] = sub[sidx][k] = 1;
                if (dfs(I, J, board))
                    return true;
                row[i][k] = col[j][k] = sub[sidx][k] = 0;
            }
        }
        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);
        memset(sub, 0, sizeof sub);
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int x = board[i][j] - '0';
                    int sidx = get_sidx(i, j);
                    if (row[i][x] || col[j][x] || sub[sidx][x])
                        return false;
                    row[i][x] = col[j][x] = sub[sidx][x] = 1;
                }
            }
        return true;
    }
};