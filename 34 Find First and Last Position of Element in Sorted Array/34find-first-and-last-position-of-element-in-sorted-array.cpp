class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        vector<int> res;
        res.push_back(firstLargerOrEqual(nums,target));
        res.push_back(lastLargerOrEqual(nums,target));
        return res;
    }

    int firstLargerOrEqual(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int res = -1;
        while (l <= r) {
            int m = l + (r - l)/2;

            if (nums[m] < target) {
                res = m;
                l = m + 1;      
            } else {
                r = m - 1;
            }
        }
        if (res == -1 && nums[0] != target) return -1;
        if (res + 1 < nums.size() && nums[res + 1] == target) return res + 1;
        else return -1;
    }

    int lastLargerOrEqual(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l)/2;

            if (nums[m] <= target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if (l == 0) return -1;
        if (l - 1 <= nums.size() - 1 && nums[l - 1] == target) return l - 1;
        else return -1;
    }
};