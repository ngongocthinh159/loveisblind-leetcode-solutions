class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> psum(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            psum[i] = i == 0 ? nums[i] : nums[i] + psum[i - 1];
        }
        int mn = INT_MAX, ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            mn = min(mn, psum[i] - nums[i]);
            ans = max(ans, psum[i] - mn);
        }
        return ans;
    }
};