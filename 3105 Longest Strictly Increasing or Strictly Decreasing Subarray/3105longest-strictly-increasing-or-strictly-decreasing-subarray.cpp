class Solution {
public:
    int longestIncrease(vector<int> &nums) {
        int i = 0, n = nums.size(), ans = 0;
        while (i < n) {
            int prev = -1, cnt = 0;
            while (i < n && nums[i] > prev) cnt++, prev = nums[i++];
            ans = max(ans, cnt);
        }
        return ans;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        int res = longestIncrease(nums);
        reverse(nums.begin(), nums.end());
        return max(res, longestIncrease(nums));
    }
};