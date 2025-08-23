#define N 85
#define K 15
int dp[N][N], ndp[N][N];
pair<int,int> pos[N * N];
int surf[N * N];
class Solution {
public:
    int n, m;
    const int IINF = 1e9;
    int minCost(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size();

        int top = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) pos[top++] = {i, j}; 
        sort(pos, pos + top, [&](auto &p1 ,auto &p2) {
            return grid[p1.first][p1.second] < grid[p2.first][p2.second];
        });
        unordered_map<int,int> valueToIdx;
        {
            int i = top - 1;
            while (i >= 0) {
                int x = grid[pos[i].first][pos[i].second];
                while (i >= 0 && x == grid[pos[i].first][pos[i].second]) {
                    valueToIdx[grid[pos[i].first][pos[i].second]] = i;
                    i--;
                }
            }
        }
        
        for (int i = 0; i < top + 2; i++) surf[i] = IINF;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) dp[i][j] = IINF;
        dp[0][0] = 0;
        for (int t = 0; t <= k; t++) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    ndp[i][j] = min(dp[i][j], surf[valueToIdx[grid[i][j]] + 1]);
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    if (i > 0) ndp[i][j] = min(ndp[i][j], ndp[i - 1][j] + grid[i][j]);
                    if (j > 0) ndp[i][j] = min(ndp[i][j], ndp[i][j - 1] + grid[i][j]);
                }
            for (int i = top - 1; i >= 0; i--)
                surf[i + 1] = min(surf[i + 2], ndp[pos[i].first][pos[i].second]);
            swap(dp, ndp);
        }
        
        return dp[n - 1][m - 1];
    }
};