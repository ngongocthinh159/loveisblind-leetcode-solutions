#define BIT(x,y) ((x >> y) & 1)
#define TOG(x,y) (x ^ (1 << y))
int row[9], col[9], sub[9];
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
            for (int k = 1; k <= 9; k++) if (!BIT(row[i], k) && !BIT(col[j], k) && !BIT(sub[sidx], k)) {
                tog(row[i], k);
                tog(col[j], k);
                tog(sub[sidx], k);
                board[i][j] = k + '0';
                if (dfs(I, J, board))
                    return true;
                tog(row[i], k);
                tog(col[j], k);
                tog(sub[sidx], k);
                board[i][j] = '.';
            }
        }
        return false;
    }
    void tog(int &x, int bit) {
        x = x ^ (1 << bit);
    }
    void solveSudoku(vector<vector<char>>& board) {
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);
        memset(sub, 0, sizeof sub);
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int x = board[i][j] - '0';
                    int sidx = get_sidx(i, j);
                    tog(row[i], x);
                    tog(col[j], x);
                    tog(sub[sidx], x);
                }
            }
        dfs(0, 0, board);
    }
};