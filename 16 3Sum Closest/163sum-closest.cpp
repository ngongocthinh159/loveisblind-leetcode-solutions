class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int dist = INT_MAX, ans = -1;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (dist > abs(nums[i] + nums[l] + nums[r] - target)) {
                    dist = abs(nums[i] + nums[l] + nums[r] - target);
                    ans = nums[i] + nums[l] + nums[r];
                }
                if (nums[l] + nums[r] + nums[i]> target) {
                    r--;
                } else if (nums[l] + nums[r] + nums[i] < target) {
                    l++;
                } else return target;
            }
        }
        return ans;
    }
};