class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size(), ans = 0;
        for (int r = 0, l1 = 0, l2 = 0; r < n; r++) {
            if (nums[r] > left - 1) l1 = r + 1;
            if (nums[r] > right) l2 = r + 1;
            ans += l1 - l2;
        }
        return ans;
    }
};