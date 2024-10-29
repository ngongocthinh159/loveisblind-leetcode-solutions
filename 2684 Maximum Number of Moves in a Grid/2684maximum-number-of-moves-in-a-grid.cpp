class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> cur(n);
        vector<int> next(n);
        int ans = 0;
        for (int j = m - 1; j >= 0; j--) {
            for (int i = n - 1; i >= 0; i--) {
                cur[i] = 1;
                if (i - 1 >= 0 && j + 1 < m && grid[i - 1][j + 1] > grid[i][j]) cur[i] = max(cur[i], 1 + next[i - 1]);
                if (j + 1 < m && grid[i][j + 1] > grid[i][j]) cur[i] = max(cur[i], next[i] + 1);
                if (i + 1 < n && j + 1 < m && grid[i + 1][j + 1] > grid[i][j]) cur[i] = max(cur[i], 1 + next[i + 1]);
                if (j == 0)  {
                    ans = max(ans, cur[i]);
                }
            }
            next = cur;
        }
        return ans - 1;
    }
};