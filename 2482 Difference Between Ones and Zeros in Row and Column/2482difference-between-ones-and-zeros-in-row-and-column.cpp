class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<vector<int>> row(grid.size(), vector<int>(2, 0));
        vector<vector<int>> col(grid[0].size(), vector<int>(2, 0));
        vector<vector<int>> res(grid.size(), vector<int>(grid[0].size(), 0));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    row[i][1]++;
                    col[j][1]++;
                } else {
                    row[i][0]++;
                    col[j][0]++;
                }
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                res[i][j] = row[i][1] + col[j][1] - row[i][0] - col[j][0];
            }
        }
        return res;
    }
};