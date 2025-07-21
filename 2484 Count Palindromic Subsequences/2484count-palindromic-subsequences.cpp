class Solution {
public:
    const int MOD = 1e9 + 7;
    void cal(string &s, vector<vector<vector<int>>> &dp) {
        int n = s.size();
        vector<vector<int>> pref(n + 1, vector<int>(10));
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < 10; j++)
                pref[i + 1][j] = pref[i][j] + (s[i] - '0' == j);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 10; j++)
                for (int k = 0; k < 10; k++) {
                    if (s[i] - '0' == j) {
                        dp[i + 1][j][k] = dp[i][j][k] + pref[i][k];           
                    } else {
                        dp[i + 1][j][k] = dp[i][j][k];
                    }
                }
    }
    int countPalindromes(string s) {
        int n = s.size();
        vector<vector<vector<int>>> dp1(n + 1, vector<vector<int>>(10, 
            vector<int>(10)));
        vector<vector<vector<int>>> dp2(n + 1, vector<vector<int>>(10, 
            vector<int>(10)));
        cal(s, dp1);
        reverse(s.begin(), s.end());
        cal(s, dp2);
        long long ans = 0;
        for (int i = 2; i + 2 < n; i++) {
            int prv = i - 1;
            int nxt = n - 1 - (i + 1);
            for (int j = 0; j < 10; j++)
                for (int k = 0; k < 10; k++) {
                    ans += 1LL * dp1[prv + 1][j][k] * dp2[nxt + 1][j][k] % MOD;
                    if (ans >= MOD) ans -= MOD;
                } 
        }
        return ans;
    }
};