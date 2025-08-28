class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int dx = 1, dy = 1, n = grid.size();
        for (int cur = 0; cur < n; cur++) {
            vector<int> v;
            int i = cur;
            int j = 0;
            while (i < n && j < n) {
                v.push_back(grid[i][j]);
                i += dx;
                j += dy;
            }
            sort(v.begin(), v.end(), greater<int>());
            i = cur;
            j = 0;
            int k = 0;
            while (i < n && j < n) {
                grid[i][j] = v[k++];
                i += dx;
                j += dy;
            }
        }
        for (int cur = 1; cur < n; cur++) {
            int i = 0, j = cur;
            vector<int> v;
            while (i < n && j < n) {
                v.push_back(grid[i][j]);
                i += dx;
                j += dy;
            }
            sort(v.begin(), v.end());
            i = 0;
            j = cur;
            int k = 0;
            while (i < n && j < n) {
                grid[i][j] = v[k++];
                i += dx;
                j += dy;
            }
        }
        return grid;
    }
};