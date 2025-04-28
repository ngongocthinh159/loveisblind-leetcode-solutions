class Solution {
public:
    const int MOD = 1e9 + 7;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int u = 0, v = 0, n = nums.size();
        vector<long long> dp(n + 1), pref(n + 2);
        pref[1] = dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (nums[i - 1] == 1) {
                u = v;
                v = i;
            }

            if (v) {
                dp[i] = pref[v] - pref[u];
                if (dp[i] < 0) dp[i] += MOD;
            }
            pref[i + 1] = (pref[i] + dp[i]) % MOD;
        }
        return dp[n];
    }
};