class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int mn = INT_MAX;
        int mx = INT_MIN;
        int n = nums.size();
        long long ans = LONG_MIN;
        for (int i = m - 1; i < n; i++) {
            mn = min(mn, nums[i - m + 1]);
            mx = max(mx, nums[i - m + 1]);
            if (nums[i] >= 0)
                ans = max(ans, 1LL * nums[i] * mx);
            else
                ans = max(ans, 1LL * nums[i] * mn);
        }
        return ans;
    }
};