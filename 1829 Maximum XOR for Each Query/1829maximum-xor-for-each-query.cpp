class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xr = 0;
        for (auto x : nums) xr ^= x;
        int i = nums.size() - 1;
        vector<int> ans(nums.size());
        do {
            ans[nums.size() - i - 1] = xr ^ ((1 << maximumBit) - 1) & ((1 << maximumBit) - 1);
            xr ^= nums[i];
            i--;
        } while (i >= 0);
        return ans;
    }
};