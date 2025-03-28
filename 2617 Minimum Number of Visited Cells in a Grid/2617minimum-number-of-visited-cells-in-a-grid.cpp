class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<multiset<int>> row_set(n + 1), col_set(m + 1);
        vector<vector<vector<int>>> row_cancle(n + 1, 
            vector<vector<int>>(m + 1, vector<int>()));
        vector<vector<vector<int>>> col_cancle(n + 1, 
            vector<vector<int>>(m + 1, vector<int>()));
        vector<vector<int>> dp(n, vector<int>(m, -1));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                for (auto x : row_cancle[i][j]) {
                    row_set[i].erase(row_set[i].find(x));
                }
                for (auto x : col_cancle[i][j]) {
                    col_set[j].erase(col_set[j].find(x));
                }

                if (!(i == 0 && j == 0)) {
                    int mn1 = row_set[i].size() ? *row_set[i].begin() : INT_MAX;
                    int mn2 = col_set[j].size() ? *col_set[j].begin() : INT_MAX;
                    int mn = min(mn1, mn2);
                    dp[i][j] = mn == INT_MAX ? -1 : mn + 1;
                }

                if (dp[i][j] == -1) continue; 
                {
                    int l = j + 1, r = min(m - 1, grid[i][j] + j);
                    if (l <= r) {
                        row_set[i].insert(dp[i][j]);
                        row_cancle[i][r + 1].push_back(dp[i][j]);
                    }
                }
                {
                    int l = i + 1, r = min(n - 1, grid[i][j] + i);
                    if (l <= r) {
                        col_set[j].insert(dp[i][j]);
                        col_cancle[r + 1][j].push_back(dp[i][j]);
                    }
                }
            }
        // cout << dp[0][0] << "\n";
        // cout << dp[0][1] << "\n";
        
        return dp[n - 1][m - 1];
    }
};