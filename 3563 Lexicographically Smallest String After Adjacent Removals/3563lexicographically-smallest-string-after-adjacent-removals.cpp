class Solution {
public:
    vector<vector<bool>> dp;
    vector<string> dp2;
    int n;
    bool ok(char c1, char c2) {
        return abs(c1 - c2) == 1 || abs(c1 - c2) == 25;
    }
    string lexicographicallySmallestString(string s) {
        n = s.size();
        dp.assign(n, vector<bool>(n, false));
        dp2.resize(n + 1);
        for (int i = 0; i + 1 < n; i++) if (ok(s[i], s[i + 1])) 
            dp[i][i + 1] = true;
        for (int len = 4; len <= n; len += 2) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (ok(s[i], s[j]) && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    continue;
                }
                for (int k = i + 1; j - k >= 2; k += 2) {
                    if (dp[i][k] && dp[k + 1][j]) {
                        dp[i][j] = true;
                        break;
                    }
                }
            }
        }
        dp2[n] = "";
        for (int i = n - 1; i >= 0; i--) {
            string res1 = "";
            res1 += s[i];
            res1 += dp2[i + 1];

            for (int j = i; j < n; j++) if (dp[i][j]) {
                res1 = min(res1, dp2[j + 1]);
            }

            dp2[i] = res1;
        }
        return dp2[0];
    }
};