class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        int next = 0, cur = -1;
        int ans = 0;
        for (int i = nums.size() - 3; i >= 0; i--) {
            if (nums[i] - nums[i + 1] == nums[i + 1] - nums[i + 2]) {
                cur = 1 + next;
            } else cur = 0;
            ans += cur;
            next = cur;
        }
        return ans;
    }
};