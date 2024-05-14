class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<deque<vector<int>>> col(n, deque<vector<int>>());
        int k = 3;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < k; i++) {
                while (col[j].size() && grid[i][j] >= col[j].front()[0]) col[j].pop_front();
                col[j].push_front({grid[i][j], i});
            }
        }
        vector<vector<int>> res(n - 2, vector<int>(n - 2));
        for (int i = 0; i + k - 1 < n; i++) {
            if (i != 0) {
                for (int j = 0; j < n; j++) {
                    while (col[j].size() && grid[i + k - 1][j] >= col[j].front()[0]) col[j].pop_front();
                    col[j].push_front({grid[i + k - 1][j], i + k - 1});
                    while (col[j].size() && !(i <= col[j].back()[1] && col[j].back()[1] <= i + k - 1)) col[j].pop_back();
                }
            }

            deque<vector<int>> q;
            for (int j = 0; j < k; j++) {
                while (q.size() && col[j].back()[0] >= q.front()[0]) q.pop_front();
                q.push_front({col[j].back()[0], j});
            }
            res[i][0] = q.back()[0];
            int _col = 1;
            for (int j = k; j < n; j++) {
                while (q.size() && col[j].back()[0] >= q.front()[0]) q.pop_front();
                q.push_front({col[j].back()[0], j});
                while (q.size() && !(j - k + 1 <= q.back()[1] && q.back()[1] <= j)) q.pop_back();
                res[i][_col] = q.back()[0];
                _col++;
            }
        }
        return res;
    }
};