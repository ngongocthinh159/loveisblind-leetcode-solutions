#define ll long long
class Solution {
public:
    vector<vector<bool>> vis;
    vector<vector<vector<pair<int,int>>>> to; 
    vector<vector<ll>> dp;
    int n, m;
    vector<pair<int,int>> moves = {{0,1}, {1,0}};
    pair<int,int> find(int i, int j, int k, vector<vector<int>> &grid) {
        if (!(0 <= i && i < n && 0 <= j && j < m)) return {-1, -1};
        if (grid[i][j] == 0) return to[i][j][k] = {i, j};
        if (to[i][j][k].first != -2) return to[i][j][k];
        int nk = k ^ 1;
        int I = i + moves[nk].first;
        int J = j + moves[nk].second;
        return to[i][j][k] = find(I, J, nk, grid);
    }
    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis.assign(n, vector<bool>(m));
        dp.assign(n, vector<ll>(m, 0));
        to.assign(n, vector<vector<pair<int,int>>>(m,
            vector<pair<int,int>>(2, {-2, -2})));
        dp[0][0] = 1;
        const int MOD = 1e9 + 7;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) if (dp[i][j]) {
                for (int k = 0; k < 2; k++) {
                    int I = i + moves[k].first;
                    int J = j + moves[k].second;
                    if (0 <= I && I < n && 0 <= J && J < m) {
                        auto p = find(I, J, k, grid);
                        if (p.first != -1) {
                            int ii = p.first;
                            int jj = p.second;
                            dp[ii][jj] += dp[i][j];
                            if (dp[ii][jj] >= MOD) dp[ii][jj] -= MOD;
                        }
                    }
                }
            }
        return dp[n - 1][m - 1];
    }
};