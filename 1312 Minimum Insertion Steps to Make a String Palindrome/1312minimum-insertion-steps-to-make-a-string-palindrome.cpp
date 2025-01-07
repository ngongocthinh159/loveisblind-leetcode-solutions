#define MAX 505
int dp[MAX][MAX];
class Solution {
public:
    int lcs(string &a, string &b) {
        for (int i = 1; i <= a.size(); i++) {
            for (int j = 1; j <= b.size(); j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[a.size()][b.size()];
    }
    int minInsertions(string s) {
        int n = s.size();
        int len = n/2;
        string b = s;
        reverse(b.begin(), b.end());
        return n - lcs(s, b);
    }
};