#define ll long long
class Solution {
public:
    ll query(int x1, int y1, int x2, int y2, vector<vector<ll>> &pref) {
        return pref[x2 + 1][y2 + 1] - pref[x2 + 1][y1] - pref[x1][y2 + 1] + pref[x1][y1];
    }
    bool solve(const vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        unordered_map<int,set<int>> val_col;
        vector<vector<ll>> pref(n + 1, vector<ll>(m + 1));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                val_col[grid[i][j]].insert(j);
                
                pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + grid[i][j];
            }
        if (n == 1) {
            for (int j = 0; j < m - 1; j++) {
                ll sum1 = query(0,0,0,j, pref);
                ll sum2 = query(0,j+1,0,m-1, pref);
                ll delta = abs(sum1 - sum2);
                if (sum1 == sum2) return true;
                if (sum1 < sum2 && j != m - 2) {
                    if (grid[0][j + 1] == delta || grid[0][m - 1] == delta)
                        return true;
                } else if (sum1 > sum2 && j != 0) {
                    if (grid[0][0] == delta || grid[0][j] == delta)
                        return true;
                }
            }
            return false;
        }
        for (int j = 0; j < m - 1; j++) {
            int x1 = 0, y1 = 0, x2 = n - 1, y2 = j;
            int x11 = 0, y11 = j + 1, x22 = n - 1, y22 = m - 1;
            bool can1 = j != 0, can2 = j != m - 2;
            ll sum1 = query(x1, y1, x2, y2, pref);
            ll sum2 = query(x11, y11, x22, y22, pref);
            if (sum1 == sum2) return true;
            ll delta = abs(sum1 - sum2);
            if (val_col.count(delta)) {
                set<int> &list = val_col[delta];
                if (sum1 < sum2) {
                    if (can2) {
                        auto it = list.lower_bound(j + 1);
                        if (it != list.end()) return true;
                    } else {
                        if (grid[0][m - 1] == delta || grid[n - 1][m - 1] == delta)
                            return true;
                    }
                } else if (sum1 > sum2) {
                    if (can1) {
                        auto it = list.upper_bound(j);
                        if (it != list.begin()) return true;
                    } else {
                        if (grid[0][0] == delta || grid[n - 1][0] == delta)
                            return true;
                    }
                }
            }
        }
        return false;
    }
    vector<vector<int>> transform(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) res[j][i] = grid[i][j];
        return res;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        return solve(grid) || solve(transform(grid));
    }
};