class Solution {
public:
    long long helper(vector<int> &nums, int upper) {
        long long ans = 0;
        for (int r = 1, l = 0; r < nums.size(); r++) {
            if (nums[r] + nums[r - 1] <= upper) ans += r, l = r;
            else {
                while (l >= 0 && nums[l] + nums[r] > upper) {
                    l--;
                }
                ans += l + 1;
            }
        }
        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return helper(nums, upper) - helper(nums, lower - 1);
    }
};