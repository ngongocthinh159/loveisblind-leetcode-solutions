#define N 33
bool dp[N][N][N];
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        for (int i = 0; i <= n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    dp[i][j][k] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) 
                dp[1][i][j] = s1[i] == s2[j];
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++)
                for (int j = 0; j + len - 1 < n; j++) {
                    for (int len1 = 1; len1 < len; len1++) {
                        int len2 = len - len1;
                        bool res1 = dp[len1][i][j] && dp[len2][i + len1][j + len1];
                        bool res2 = dp[len1][i][j + len2] && dp[len2][i + len1][j];
                        dp[len][i][j] = res1 || res2;
                        if (dp[len][i][j])
                            break;
                    }
                }
        }
        return dp[n][0][0];
    }
};