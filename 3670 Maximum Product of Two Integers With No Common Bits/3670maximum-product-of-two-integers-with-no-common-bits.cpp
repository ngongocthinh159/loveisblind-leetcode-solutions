#define _N 20
int dp[1 << (_N + 1)];
class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int N = 32 - __builtin_clz(mx);
        memset(dp, 0, (sizeof (int)) * (1 << N));
        for (auto x : nums) dp[x] = x;
        for (int i = 0; i < N; i++) {
            for (int mask = 0; mask < (1 << N); mask++) if ((mask >> i) & 1) {
                if (dp[mask] < dp[mask ^ (1 << i)])
                    dp[mask] = dp[mask ^ (1 << i)];
            }
        }
        long long ans = 0;
        for (auto x : nums)
            ans = max(ans, 1LL * x * dp[x ^ ((1 << N) - 1)]);
        return ans;
    }
};