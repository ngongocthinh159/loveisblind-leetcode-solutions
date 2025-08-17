class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n + 1), pref(n + 2);
        dp[0] = 1;
        pref[1] = dp[0];
        for (int i = 1; i <= n; i++) {
            int u = max(0, i - maxPts);
            int v = min(i - 1, k - 1);
            if (u <= v)
                dp[i] = (pref[v + 1] - pref[u]) / maxPts;
            pref[i + 1] = pref[i] + dp[i];
        }
        return pref[n + 1] - pref[k];
    }
};