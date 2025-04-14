#define N 55
int dp[2*N + 5][N][N];
vector<vector<int>> moves = {{1,0,0},{1,1,0},{1,0,1},{1,1,1}};
class Solution {
public:
    bool isValid(int x, int y, int n, int m) {
        return 0 <= x && x < n && 0 <= y && y < m;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < 2*n - 1; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++) dp[i][j][k] = -1;
        dp[0][0][0] = grid[0][0];
        for (int len = 0; len <= 2*n - 3; len++) {
            int mn = max(len - (n - 1), 0), mx = min(len, n - 1);
            for (int j1 = mn; j1 <= mx; j1++) {
                for (int j2 = mn; j2 <= mx; j2++) if (dp[len][j1][j2] != -1) {
                    for (auto &move : moves) {
                        int L = len + move[0];
                        int J1 = j1 + move[1];
                        int J2 = j2 + move[2];
                        int I1 = L - J1;
                        int I2 = L - J2;
                        if (isValid(I1, J1, n, n) && isValid(I2, J2, n, n) && grid[I1][J1] != -1 && grid[I2][J2] != -1) {
                            int val = grid[I1][J1];
                            if (I1 != I2) val += grid[I2][J2];
                            dp[L][J1][J2] = max(dp[L][J1][J2], dp[len][j1][j2] + val);
                        }
                    }
                }
            }
        }
        return max(dp[2*n - 2][n - 1][n - 1], 0);
    }
};