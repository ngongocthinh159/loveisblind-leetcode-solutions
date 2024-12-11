class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool has_one = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                has_one = true;
                break;
            }
        }
        if (!has_one) return 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) nums[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (abs(nums[i]) <= n) nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) return i + 1;
        }
        return n + 1;
    }
};