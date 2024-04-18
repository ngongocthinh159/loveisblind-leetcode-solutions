class Solution {
public:
    vector<vector<int>> moves = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    res += 4;
                    for (auto &move : moves) {
                        int I = i + move[0];
                        int J = j + move[1];
                        if (0 <= I && I < n && 0 <= J && J < m && grid[I][J] == 1) res -= 1;
                    }
                }
            }
        }
        return res;
    }
};