class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        const int IINF = 1e9 + 5;
        int mn = IINF, mx = -IINF, n = nums.size();
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            mn = min(nums[i], nums[i] + mn);
            mx = max(nums[i], nums[i] + mx);
            ans = max(ans, max(abs(mn), abs(mx)));
        }
        return ans;
    }
};