class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        int n = nums.size();
        const int LINF = 1e18;
        unordered_map<int, long long> M;
        M[0] = 0;
        vector<long long> dp(n + 1, LINF);
        dp[0] = 0;
        long long pref = 0;
        for (int i = 0; i < n; i++) {
            (pref += nums[i]) %= k;
            dp[i + 1] = dp[i] + nums[i];
            if (M.count(pref)) {
                dp[i + 1] = min(dp[i + 1], M[pref]);              
                M[pref] = min(M[pref], dp[i + 1]);
            } else
                M[pref] = dp[i + 1];
        }
        return dp[n];
    }
};