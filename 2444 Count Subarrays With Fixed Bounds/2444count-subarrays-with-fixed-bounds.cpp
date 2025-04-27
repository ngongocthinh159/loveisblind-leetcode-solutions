class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int invalid = -1, mn = -1, mx = -1;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < minK || nums[i] > maxK)
                invalid = i;
            if (nums[i] == minK) mn = i;
            if (nums[i] == maxK) mx = i;
            if (mn > invalid && mx > invalid)
                ans += min(mn, mx) - (invalid + 1) + 1;
        }
        return ans;
    }
};