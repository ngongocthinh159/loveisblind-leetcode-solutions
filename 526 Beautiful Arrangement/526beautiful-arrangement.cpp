class Solution {
public:
    int countArrangement(int n) {
        int maxMask = (1 << n) - 1;
        vector<int> dp(maxMask + 1, 0);
        dp[maxMask] = 1;
        for (int mask = maxMask - 1; mask >= 0; mask--) {
            int i = __builtin_popcount(mask);
            for (int bit = n - 1; bit >= 0; bit--) {
                if (!((mask >> bit) & 1)) {
                    if (((bit + 1) % (i + 1) == 0) 
                        || ((i + 1) % (bit + 1) == 0)) dp[mask] += dp[mask | (1 << bit)];
                }
            }
        }
        return dp[0];
    }
};