class Solution {
public:
    vector<vector<int>> moves = {{1,-1}, {1,1}};
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (n == 1 && m == 1) return grid[0][0];
        pair<int,int> fi = {0,-1};
        pair<int,int> se = {0,-1};
        for (int i = n - 1; i >= 0; i--) {
            pair<int,int> _fi = {INT_MAX,-1};
            pair<int,int> _se = {INT_MAX,-1};
            for (int j = 0; j < m; j++) {
                int res = grid[i][j] + (fi.second == j ? se.first : fi.first);
                if (res < _fi.first) {
                    _se = {_fi.first, _fi.second};
                    _fi = {res, j};
                } else if (res < _se.first) {
                    _se = {res, j};
                }
            }
            fi = _fi;
            se = _se;
        }
        return fi.first;
    }
};