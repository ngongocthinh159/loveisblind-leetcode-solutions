class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<long long> dp(n + 1);
        vector<long long> pref(n + 1);
        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + stones[i];
        long long mx = pref[n];
        for (int i = n - 1; i >= 0; i--) {
            // j [i + 1 .. j]
            // dp[i] = max(dp[i], pref[i] - pref[i + 1] + pref[j + 1] - dp[j]); 
            // j [i + 1 .. n - 1]
            dp[i] = mx;
            if (i != 1) mx = max(mx, pref[i] - dp[i]);
        }

        // dp[i]: 
        return dp[0];
    }
};