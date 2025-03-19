class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(), flip = 0, ans = 0;
        for (int i = 0; i <= n - k; i++) {
            flip ^= ((nums[i] >> 1) & 1);
            if ((nums[i] & 1) == flip) {
                flip ^= 1;
                if (i + k < n) nums[i + k] |= (1 << 1);
                ans++;
            }
        }
        for (int i = n - k + 1; i < n; i++) {
            flip ^= ((nums[i] >> 1) & 1);
            if ((nums[i] & 1) == flip) 
                return -1;
        }
        return ans;
    }
};