class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> cur(n + 1, 0);
        vector<int> next(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int res = INT_MAX;
                if (0 <= j - 1 && j - 1 < n) res = min(res, next[j - 1]);
                res = min(res, next[j]);
                if (0 <= j + 1 && j + 1 < n) res = min(res, next[j + 1]);
                cur[j] = matrix[i][j] + res;
            }
            next = cur;
        }
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, next[j]);
        }
        return ans;
    }
};