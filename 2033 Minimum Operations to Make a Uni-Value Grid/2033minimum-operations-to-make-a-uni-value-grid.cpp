#define MAXN 100005
int buf[MAXN];
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int ans = 0, n = grid.size(), m = grid[0].size(), top = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) buf[top++] = grid[i][j];
        nth_element(buf, buf + top/2, buf + top);
        int median = buf[top/2];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (abs(grid[i][j] - median) % x != 0) return -1;
                ans += abs(grid[i][j] - median) / x;
            }
        return ans;
    }
};