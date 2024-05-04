#define ll long long
class Solution {
public:
    bool check(int health, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        health += grid[0][0];
        if (health <= 0) return false;
        deque<vector<int>> q;
        q.push_back({0,0, health});
        while (q.size()) {
            int size = q.size();
            for (int k  =0; k < size; k++) {
                auto cur = q.back(); q.pop_back();
                int i = cur[0];
                int j = cur[1];
                int w_u = cur[2];
                if (i == n - 1 && j == m - 1) return true;
                if (i + 1 < n) {
                    if (w_u + grid[i + 1][j] >= 1) {
                        q.push_front({i + 1, j, w_u + grid[i + 1][j]});
                    }
                }
                if (j + 1 < m) {
                    if (w_u + grid[i][j + 1] >= 1) {
                        q.push_front({i, j + 1, w_u + grid[i][j + 1]});
                    }
                }
            }
        }
        return false;
    }
    int calculateMinimumHP(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int l = 0, r = 2e5 + 1;
        while (r - l > 1) {
            int m = l + (r - l)/2;
            if (check(m, grid)) {
                r = m;
            } else
                l = m;
        }
        return r;
    }
};