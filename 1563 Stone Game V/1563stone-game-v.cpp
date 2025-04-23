class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        const long long LINF = 1e18 + 5;
        vector<vector<long long>> dp(n, vector<long long>(n));
        vector<vector<int>> pivot(n, vector<int>(n));
        vector<vector<long long>> max_pref(n, vector<long long>(n));
        vector<vector<long long>> max_surf(n, vector<long long>(n));
        vector<long long> pref(n + 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + stoneValue[i];
            pivot[i][i] = i - 1;
            max_surf[i][i] = max_pref[i][i] = stoneValue[i];
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0, j = i + len - 1; j < n; i++, j++) {
                int k = pivot[i][j - 1];
                while (pref[k + 1] - pref[i] + stoneValue[k + 1] <= pref[j + 1] - pref[k + 2]) k++;
                pivot[i][j] = k;
                int k2 = k + 2;

                if (k >= i && (pref[k + 1] - pref[i] == pref[j + 1] - pref[k + 1])) { // equal
                    dp[i][j] = max(dp[i][j], pref[k + 1] - pref[i] + max(dp[i][k], dp[k + 1][j]));
                    k--;
                }
                if (k >= i) dp[i][j] = max(dp[i][j], max_pref[i][k]);
                if (k2 <= j) dp[i][j] = max(dp[i][j], max_surf[k2][j]);

                max_pref[i][j] = max(max_pref[i][j - 1], pref[j + 1] - pref[i] + dp[i][j]);
                max_surf[i][j] = max(max_surf[i + 1][j], pref[j + 1] - pref[i] + dp[i][j]);
            }
        }
        return dp[0][n - 1];
    }
};