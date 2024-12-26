class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int median = nums[n/2];
        int ans = 0;
        for (auto x : nums) ans += abs(median - x);
        return ans;
    }
};