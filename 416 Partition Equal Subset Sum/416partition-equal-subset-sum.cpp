class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (auto x : nums) sum += x;
        if (sum&1) return false;
        int S = sum/2;
        bitset<10005> dp;
        dp[0] = true;
        for (int i = 1; i <= n; i++)
            for (int j = S; j >= 0; j--) if (j >= nums[i - 1]) {
                dp[j] = dp[j] | dp[j - nums[i - 1]];
                if (dp[S]) return true;
            }
        return dp[S];
    }
};