class Solution {
public:
    /*
        In the final solution exists at least 1 whole vertical or horizontal cut
        => Brute force all vertical and horizontal cut, for each cut, brute force two halfs
    */

    const int IINF = 1e9;
    vector<vector<int>> rotate90(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ngrid(m, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) ngrid[j][i] = grid[i][j];
        for (int i = 0; i < m; i++)
            for (int j = 0, k = n - 1; j < k; j++, k--)
                swap(ngrid[i][j], ngrid[i][k]);
        return ngrid;
    }
    int cal(int sr, int er, int sc, int ec, vector<vector<int>> &grid) {
        int t = IINF, b = -1, l = IINF, r = -1;
        int n = grid.size(), m = grid[0].size();
        for (int i = sr; i <= er; i++)
            for (int j = sc; j <= ec; j++) if (grid[i][j]) {
                t = min(t, i);
                b = max(b, i);
                l = min(l, j);
                r = max(r, j);
            }
        if (b == -1) return 0;
        return (b - t + 1) * (r - l + 1);
    }
    int cal_try(int sc, int ec, vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = IINF;
        for (int j = sc; j <= ec - 1; j++) {
            ans = min(ans, cal(0, n - 1, sc, j, grid) + cal(0, n - 1, j + 1, ec, grid));
        }
        for (int i = 0; i < n - 1; i++) {
            ans = min(ans, cal(0, i, sc, ec, grid) + cal(i + 1, n - 1, sc, ec, grid));
        }
        return ans;
    }
    int solve(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = IINF;
        for (int j = 0; j < m - 1; j++) {
            int ans1 = cal_try(0, j, grid) + cal(0, n - 1, j + 1, m - 1, grid);
            int ans2 = cal(0, n - 1, 0, j, grid) + cal_try(j + 1, m - 1, grid);
            ans = min(ans, min(ans1, ans2));
        }
        return ans;
    }
    int minimumSum(vector<vector<int>>& grid) {
        auto ngrid = rotate90(grid);
        return min(solve(grid), solve(ngrid));
    }
};