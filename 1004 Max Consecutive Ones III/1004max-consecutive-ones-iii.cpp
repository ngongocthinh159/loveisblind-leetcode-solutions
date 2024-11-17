class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int cnt_0 = 0;
        int ans = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r]==0) cnt_0++;

            while (l <= r && cnt_0 > k) {
                if (nums[l] == 0)cnt_0--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};