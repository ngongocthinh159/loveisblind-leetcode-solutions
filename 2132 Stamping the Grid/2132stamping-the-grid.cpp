class Solution {
public:
    int n, m;
    int N, M;
    vector<vector<int>> pref, diff;
    int query(int x1, int y1, int x2, int y2) {
        return pref[x2 + 1][y2 + 1] - pref[x2 + 1][y1] - pref[x1][y2 + 1] + pref[x1][y1];
    }
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        n = grid.size(), m = grid[0].size();
        N = stampHeight, M = stampWidth;
        pref.assign(n + 1, vector<int>(m + 1));
        diff.assign(n + 2, vector<int>(m + 2));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + (grid[i][j] == 0);
        for (int i = 0; i <= n - N; i++)
            for (int j = 0; j <= m - M; j++) {
                int x1 = i, y1 = j, x2 = i + N - 1, y2 = j + M - 1;
                if (query(x1, y1, x2, y2) == N * M) {
                    // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
                    diff[x1 + 1][y1 + 1] += 1;
                    diff[x1 + 1][y2 + 1 + 1] -= 1;
                    diff[x2 + 1 + 1][y1 + 1] -= 1;
                    diff[x2 + 1 + 1][y2 + 1 + 1] += 1;
                }
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                diff[i + 1][j + 1] = diff[i + 1][j] + diff[i][j + 1] - diff[i][j] + diff[i + 1][j + 1];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) if (grid[i][j] == 0 && diff[i + 1][j + 1] == 0)
                return false;
        return true;
    }
};