class Solution {
public:
    int countHillValley(vector<int>& nums) {
        {
            int i = 0, j = 0;
            int n = nums.size();
            while (i < n) {
                int x = nums[i];
                while (i < n && x == nums[i]) i++;
                nums[j++] = x;
            }
            nums.erase(nums.begin() + j, nums.end());
        }
        int n = nums.size();
        int h = 0, v = 0;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i - 1] < nums[i] && nums[i + 1] < nums[i])
                h++;
            else if (nums[i - 1] > nums[i] && nums[i + 1] > nums[i])
                v++;
        }
        return h + v;
    }
};