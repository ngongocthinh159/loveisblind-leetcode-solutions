class Solution {
public:
    const int mod = 1e9 + 7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<pair<int,int>> moves = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (int cur = maxMove - 1; cur >= 0; cur--) {
            vector<vector<int>> tmp = dp;

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    dp[i][j] = 0;
                    for (auto &move : moves) {
                        int I = i + move.first;
                        int J = j + move.second;
                        if (I < 0 || I >= m || J < 0 || J >= n) {
                            dp[i][j] = (dp[i][j] + 1)%mod;
                        } else {
                            dp[i][j] = (dp[i][j] + tmp[I][J])%mod;
                        }
                    }
                }
            }
        }
        return dp[startRow][startColumn];
    }
};