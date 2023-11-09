class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        while (i < nums.size()) {
            int prev = nums[i++];
            while (i < nums.size() && nums[i] == nums[i - 1]) {
                i++;
            }
            nums[j] = prev;
            j++;
        }
        return j;
    }
};