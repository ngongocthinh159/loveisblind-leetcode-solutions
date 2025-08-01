class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int i = 0, n = nums.size();
        int ans = 0;
        while (i < n) {
            if (nums[i] == mx) {
                int cnt = 0;
                while (i < n && nums[i] == mx) {
                    cnt++;
                    i++;
                }
                ans = max(ans, cnt);
            } else {
                i++;
            }
        }
        return ans;
    }
};