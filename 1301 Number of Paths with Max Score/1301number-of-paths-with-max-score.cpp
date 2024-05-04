#define ll long long
class Solution {
public:
    const int mod = 1e9 + 7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
        dp[0][0] = 0; // dp[i][j] => maxPath from [0,0] to [i,j]
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;
                if (board[i][j] != 'X') {
                    int res = INT_MIN;
                    if (i - 1 >= 0 && board[i - 1][j] != 'X') res = max(res, dp[i - 1][j]);
                    if (j - 1 >= 0 && board[i][j - 1] != 'X') res = max(res, dp[i][j - 1]);
                    if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] != 'X') res = max(res, dp[i - 1][j - 1]);
                    if (res != INT_MIN) dp[i][j] = ((i == n - 1 && j == m - 1) ? 0 : (board[i][j] - '0')) + res;
                }
            }
        }
        if (dp[n - 1][m - 1] == INT_MIN) return {0, 0};
        else {
            vector<vector<int>> dp2(n, vector<int>(m, -1));
            int pathSum = dp[n - 1][m - 1];
            int pathCnt = cnt_path(0, 0, 0, board, dp, dp2);
            return {pathSum, dp2[0][0]};
        }
    }

    ll cnt_path(int i, int j, int curPath, vector<string>& board, vector<vector<int>> &dp, vector<vector<int>> &dp2) {
        int n = board.size();
        int m = board[0].size();
        if (i == n - 1 && j == m - 1) {
            if (curPath == dp[n - 1][m - 1]) return dp2[i][j] = 1;
            return dp2[i][j] = 0;
        }
        if (dp2[i][j] != -1) return dp2[i][j];

        ll res = 0;
        if (i + 1 < n && board[i + 1][j] != 'X') {
            int val = ((i + 1 == n - 1 && j == m - 1) ? 0 : (board[i + 1][j] - '0'));
            if (curPath + val == dp[i + 1][j])
                res = (res + cnt_path(i + 1, j, curPath + val, board, dp, dp2)) % mod;
        }
        if (j + 1 < n && board[i][j + 1] != 'X') {
            int val = ((i == n - 1 && j + 1 == m - 1) ? 0 : (board[i][j + 1] - '0'));
            if (curPath + val == dp[i][j + 1])
                res = (res + cnt_path(i, j + 1, curPath + val, board, dp, dp2)) % mod;
        }
        if (i + 1 < n && j + 1 < m) {
            int val = ((i + 1 == n - 1 && j + 1 == m - 1) ? 0 : (board[i + 1][j + 1] - '0'));
            if (curPath + val == dp[i + 1][j + 1])
                res = (res + cnt_path(i + 1, j + 1, curPath + val, board, dp, dp2)) % mod;
        }
        return dp2[i][j] = res;
    }
};