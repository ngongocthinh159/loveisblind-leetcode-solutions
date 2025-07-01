class Solution {
public:
    long long countSubstrings(string s) {
        int n = s.size();
        vector<vector<long long>> dp(10, vector<long long>(10));
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            vector<vector<long long>> ndp(10, vector<long long>(10));
            for (int j = 1; j <= 9; j++) 
                dp[j][(s[i] - '0') % j]++;
            if (i + 1 < n)
                for (int j = 1; j <= 9; j++)
                    for (int k = 0; k < j; k++) {
                        int nk = (k * 10 + (s[i + 1] - '0')) % j;
                        ndp[j][nk] += dp[j][k];
                    }
            if (s[i] != '0')
                ans += dp[s[i] - '0'][0];
            swap(dp, ndp);
        }
        return ans;
    }
};