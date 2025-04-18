#define N 16
int sum[1 << N], dp[1 << N];
class Solution {
public:
    void clear(int n) {
        for (int mask = 0; mask < (1 << n); mask++) dp[mask] = 0;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size(), tot = 0;
        clear(n);
        for (auto x : nums) tot += x;
        if (tot % k != 0) return false;
        int set_sum = tot/k;
        int nMask = (1 << n) - 1;
        for (int mask = 0; mask <= nMask; mask++) {
            sum[mask] = 0;
            if (mask) {
                int msb = 32 - __builtin_clz(mask) - 1;
                sum[mask] = sum[mask ^ (1 << msb)] + nums[msb];
            }

            for (int i = 0; i < n; i++) if (!((mask >> i) & 1)) {
                int remain = set_sum - (sum[mask] - dp[mask] * set_sum);
                if (nums[i] <= remain)
                    dp[mask ^ (1 << i)] = dp[mask] + (nums[i] == remain);
            }
        }
        return dp[nMask] >= k;
    }
};