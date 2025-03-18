class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int mask = 0, ans = 0;
        for (int r = 0, l = 0; r < nums.size(); r++) {
            while (l < r && (mask & nums[r]))
                mask ^= nums[l++];
            mask |= nums[r];
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};