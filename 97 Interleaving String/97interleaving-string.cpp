class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int k = s3.size();
        if (k != n + m) return false;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[n][m] = true;
        for (int i = n; i >= 0; i--) {
            for (int j = m; j >= 0; j--) {
                if (i == n && j == m) continue;
                int p = i + j;
                if (i < n && s1[i] == s3[p]) dp[i][j] = dp[i + 1][j];
                if (j < m && s2[j] == s3[p]) dp[i][j] = dp[i][j] | dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
};