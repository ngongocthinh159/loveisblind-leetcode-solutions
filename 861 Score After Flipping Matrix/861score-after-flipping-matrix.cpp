class Solution {
public:
    void reverse_row(int i, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int j = 0; j < m; j++) {
            if (grid[i][j]) grid[i][j] = 0;
            else grid[i][j] = 1;
        }
    }
    void reverse_col(int j, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            if (grid[i][j]) grid[i][j] = 0;
            else grid[i][j] = 1;
        }
    }
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0) reverse_row(i, grid);
        }
        for (int j = 1; j < m; j++) {
            int cnt_0 = 0;
            int cnt_1 = 0;
            for (int i = 0; i < n; i++) {
                if (grid[i][j]) cnt_1++;
                else cnt_0++;
            }
            if (cnt_0 > cnt_1) {
                reverse_col(j, grid);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int bit = m - 1; bit >= 0; bit--) {
                if (grid[i][bit]) cur = cur | (1 << (m - 1 - bit));
            }
            ans += cur;
        }
        return ans;
    }
};