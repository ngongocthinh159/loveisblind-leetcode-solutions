#define N 305
int dp[N][N][6];
auto init = [] {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < 6; k++) dp[i][j][k] = -1;
    return 0;
}();
class Solution {
public:
    const int MOD = 1e9 + 7;
    int dfs(int n, int x, int st) {
        if (n == 0) return 1;
        if (st > n) return 0;
        if (dp[n][st][x] != -1) return dp[n][st][x];
        int res = 0;
        res += dfs(n, x, st + 1);
        if (res >= MOD) res -= MOD;
        long long cur = pow(1LL * st, x);
        if (cur <= n) {
            res += dfs(n - cur, x, st + 1);
            if (res >= MOD) res -= MOD;
        }
        return dp[n][st][x] = res;
    }
    int numberOfWays(int n, int x) {
        return dfs(n, x, 1);
    }
};