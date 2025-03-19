class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), flip = 0, ans = 0;
        for (int i = 0; i <= n - 3; i++) {
            flip ^= (nums[i] >> 1);
            if ((nums[i] & 1) == flip) {
                flip ^= 1;
                if (i + 3 < n) 
                    nums[i + 3] ^= (1 << 1);
                ans++;
            }
        }
        for (int i = n - 3 + 1; i < n; i++) {
            flip ^= (nums[i] >> 1);
            if ((nums[i] & 1) == flip)
                return -1;
        }
        return ans;
    }
};