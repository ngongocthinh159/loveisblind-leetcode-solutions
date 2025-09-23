class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        int n = nums.size();
        int d = 30;
        vector<int> basis(d, -1);
        int sz = 0;
        for (int i = 0; i < n; i++) {
            int mask = nums[i];
            for (int bit = d - 1; bit >= 0; bit--)
                if ((mask >> bit) & 1) {
                    if (basis[bit] == -1) {
                        basis[bit] = mask;
                        sz++;
                        break;
                    }
                    mask ^= basis[bit];
                }
        }
        int ans = 0;
        for (int i = d - 1; i >= 0; i--)
            if (basis[i] != -1 && !((ans >> i) & 1))
                ans ^= basis[i];
        return ans;
    }
};