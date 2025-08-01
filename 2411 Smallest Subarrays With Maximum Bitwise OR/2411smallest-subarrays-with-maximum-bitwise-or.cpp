class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> bit(32, -1);
        for (int r = n - 1; r >= 0; r--) {
            for (int i = 0; i < 32; i++) if ((nums[r] >> i) & 1)
                bit[i] = r;
            int mx = r;
            for (int i = 0; i < 32; i++) if (bit[i] != -1) mx = max(mx, bit[i]);
            ans[r] = (mx - r + 1);
        }
        return ans;
    }
};