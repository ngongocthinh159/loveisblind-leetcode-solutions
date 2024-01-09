class Solution {
public:
    int numberOfArithmeticSlices(std::vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long,int> dp[n];
        int ans = 0;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                long long diff = 1LL*nums[j] - nums[i];
                dp[i][diff] += 1 + dp[j][diff];
                ans += dp[j][diff];
            }
        }
        return ans;
    }
};