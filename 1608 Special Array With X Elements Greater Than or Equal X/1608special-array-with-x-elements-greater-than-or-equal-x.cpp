class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                int cur = (int) nums.size() - i;
                if (cur <= nums[i]) {
                    if (i == 0) return cur;
                    else if (cur > nums[i - 1]) return cur;
                }
            }
        }
        return -1;
    }
};