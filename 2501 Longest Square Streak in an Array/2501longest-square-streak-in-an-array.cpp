class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(1e5 + 1);
        int ans = -1;
        for (int i = nums.size() - 1; i>=0; i--) {
            if (1LL*nums[i]*nums[i] <= 1e5) {
                dp[nums[i]] = 1 + dp[nums[i]*nums[i]];
            } else dp[nums[i]] = 1;
            ans = max(ans, dp[nums[i]]);
        }
        return ans == 1 ? -1 : ans;
    }
};