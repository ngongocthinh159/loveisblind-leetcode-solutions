#define ll long long
class Solution {
public:
    void fill_dp(string &s, vector<int> &dp) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = i, k = i; j >= 0 && k < n && s[j] == s[k]; j--, k++) {
                dp[j] = max(dp[j], k - j + 1);
            }
            if (i + 1 < n && s[i] == s[i + 1]) {
                for (int j = i, k = i + 1; j >= 0 && k < n && s[j] == s[k]; j--, k++) {
                    dp[j] = max(dp[j], k - j + 1);
                }
            }
        }
    }
    int longestPalindrome(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        vector<int> dpS(n), dpT(m);
        fill_dp(s, dpS);
        reverse(t.begin(), t.end());
        fill_dp(t, dpT);
        reverse(dpT.begin(), dpT.end());
        reverse(t.begin(), t.end());
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                if (s[i] != t[j])
                    dp[i][j] = max(dpS[i], dpT[j]);
                else {
                    dp[i][j] = max(dpS[i], dpT[j]);
                    int tmp;
                    if (i + 1 == n && j - 1 == -1) tmp = 0;
                    else if (i + 1 == n) tmp = dpT[j - 1];
                    else if (j - 1 == -1) tmp = dpS[i + 1];
                    else tmp = dp[i + 1][j - 1];
                    dp[i][j] = max(dp[i][j], 2 + tmp);;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};