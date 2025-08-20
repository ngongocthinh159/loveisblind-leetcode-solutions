class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> dp(m + 1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> ndp(m + 1);
            for (int j = 0; j < m; j++) if (matrix[i][j]) {
                ndp[j + 1] = 1 + min(ndp[j], min(dp[j + 1], dp[j]));
                ans += ndp[j + 1];
            }
            swap(dp, ndp);
        }
        return ans;
    }
};