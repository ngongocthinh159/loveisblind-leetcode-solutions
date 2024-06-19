class Solution {
public:
    int helper(int l, int r, vector<int>& nums) {
        if (l > r) return 0;
        int n = nums.size();
        vector<int> dp(n + 1);
        for (int i = l; i <= r; i++) {
            dp[i] = max(nums[i] + (i - 2 >= 0 ? dp[i - 2] : 0), dp[i - 1]);
        }
        return dp[r];
    }
    int rob(vector<int>& nums) {
        return max(nums[0] + helper(2, nums.size() - 2, nums), helper(1, nums.size() - 1, nums));
    }
};