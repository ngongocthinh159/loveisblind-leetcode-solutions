class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(k));
        dp[0][nums[0]%k] = 1;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < k; j++) {
                dp[i + 1][1LL*j*nums[i + 1]%k] += dp[i][j];
            }
            dp[i + 1][nums[i + 1]%k] += 1;
        }
        vector<long long> ans(k);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < k; j++) ans[j] += dp[i][j];
        return ans;
    }
};