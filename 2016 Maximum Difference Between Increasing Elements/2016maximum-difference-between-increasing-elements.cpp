class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1, n = nums.size();
        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums[i] > mn) {
                ans = max(ans, nums[i] - mn);
            }
            mn = min(mn, nums[i]);
        }
        return ans;
    }
};