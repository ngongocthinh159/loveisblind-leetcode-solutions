class Solution {
public:
    const int MOD = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        int freq[31]{};
        for (auto x : nums) {
            for (int bit = 30; bit >= 0; bit--) if ((x >> bit) & 1)
                freq[bit]++;
        }
        long long ans = 0;
        while (k--) {
            int cur = 0;
            for (int bit = 30; bit >= 0; bit--) if (freq[bit]) {
                cur += (1 << bit);
                freq[bit]--;
            }
            ans = (ans + 1LL*cur*cur%MOD) % MOD;
        }
        return ans;
    }
};