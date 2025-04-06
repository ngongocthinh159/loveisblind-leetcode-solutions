class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), mx = 0;
        vector<int> dp(n, 1), res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) if (nums[j] % nums[i] == 0)
                dp[j] = max(dp[j], dp[i] + 1);
            mx = max(mx, dp[i]);
        }
        for (int i = n - 1; i >= 0 && mx; i--) {
            if (dp[i] == mx && (!res.size() || res.back() % nums[i] == 0)) {
                res.push_back(nums[i]);
                mx--;
            }
        }
        return res;
    }
};