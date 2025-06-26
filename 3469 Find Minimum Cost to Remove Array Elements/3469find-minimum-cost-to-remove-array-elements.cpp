class Solution {
public:
    void minimize(long long &x, long long y) {
        if (x > y) x = y;
    }
    int minCost(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            if (n == 1) 
                return nums[0];
            return max(nums[0], nums[1]);
        }
        const int LINF = 1e18;
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, LINF));
        dp[2][0] = 0;
        long long ans1 = LINF;
        long long ans2 = LINF;
        for (int i = 2; i < n; i++) 
            for (int j = 0; j <= i - 2; j++) {
                if (i + 2 < n) {
                    minimize(dp[i + 2][j], dp[i][j] + max(nums[i], nums[i - 1]));
                    minimize(dp[i + 2][i - 1], dp[i][j] + max(nums[j], nums[i]));
                    minimize(dp[i + 2][i], dp[i][j] + max(nums[j], nums[i - 1]));
                } else {
                    if (i + 1 < n) {
                        minimize(ans1, dp[i][j] + max(nums[i], nums[i - 1]) + max(nums[j], nums[i + 1]));
                        minimize(ans1, dp[i][j] + max(nums[j], nums[i]) + max(nums[i - 1], nums[i + 1]));
                        minimize(ans1, dp[i][j] + max(nums[j], nums[i - 1]) + max(nums[i], nums[i + 1]));
                    } else {
                        minimize(ans2, dp[i][j] + max(nums[i], nums[i - 1]) + nums[j]);
                        minimize(ans2, dp[i][j] + max(nums[j], nums[i]) + nums[i - 1]);
                        minimize(ans2, dp[i][j] + max(nums[j], nums[i - 1]) + nums[i]);
                    }       
                }
            }
        
        return (n & 1) ? ans2 : ans1;
    }
};