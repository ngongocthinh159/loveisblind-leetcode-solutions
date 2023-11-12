class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        vector<int> maxAt(nums.size());
        vector<int> minAt(nums.size());
        int res = maxAt[0] = minAt[0] = nums[0];
        int minSub = nums[0];
        int total = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            maxAt[i] = max(nums[i], nums[i] + maxAt[i - 1]);
            minAt[i] = min(nums[i], nums[i] + minAt[i - 1]);
            total += nums[i];
            res = max(res, maxAt[i]);
            minSub = min(minSub, minAt[i]);
        }
        return res < 0 ? res : max(res, total - minSub);
    }
};