class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int L = 0, R = n - 1;
        for (int i = 0; i < n && i <= R; i++) {
            while (i >= L && i <= R && nums[i] != 1) {
                if (nums[i] == 0)
                    swap(nums[i], nums[L++]);
                else if (nums[i] == 2)
                    swap(nums[i], nums[R--]);
            }
        }
    }
};