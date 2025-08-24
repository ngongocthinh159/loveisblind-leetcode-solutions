class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, ans = 0;
        for (int r = 0, l = 0; r < n; r++) {
            if (!nums[r]) cnt++;
            while (l < r && cnt > 1) {
                if (!nums[l++]) cnt--;
            }
            ans = max(ans, r - l + 1 - 1);
        }
        return ans;
    }
};