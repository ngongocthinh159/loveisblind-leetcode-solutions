class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;
        int idx1 = -1, idx2 = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < mx) {
                idx1 = i;
                break;
            }
            mx = max(mx, nums[i]);
        }
        if (idx1 == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > nums[idx1]) {
                idx2 = i;
                break;
            }
        }
        swap(nums[idx1], nums[idx2]);
        reverse(nums.begin() + idx1 + 1, nums.end());
    }
};