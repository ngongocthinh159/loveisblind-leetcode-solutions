class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            int bit = __builtin_popcount(nums[i]);
            int l = i, r;
            while (i < nums.size() && __builtin_popcount(nums[i]) == bit) {
                r = i;
                i++;
            }
            sort(nums.begin() + l, nums.begin() + r + 1);
        }
        for (int i = 1; i < nums.size();i++) {
            if (!(nums[i] >= nums[i - 1])) return false;
        }
        return true;
    }
};