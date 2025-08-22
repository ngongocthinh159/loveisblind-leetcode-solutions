class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int t = INT_MAX, b = INT_MIN, l = INT_MAX, r = INT_MIN;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) if (grid[i][j]) {
                t = min(t, i);
                b = max(b, i);
                l = min(l, j);
                r = max(r, j);
            }
        return (b - t + 1) * (r - l + 1);
    }
};