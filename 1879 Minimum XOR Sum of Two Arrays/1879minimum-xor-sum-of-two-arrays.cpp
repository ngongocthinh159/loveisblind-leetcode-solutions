const int INF = 1e9;

class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int maxMask = (1 << n) - 1;
        vector<vector<int>> dp(n + 1,
            vector<int>(maxMask + 1, INF));
        dp[n][maxMask] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int mask = 0; mask <= maxMask; mask++) {
                for (int bit = 0; bit < n; bit++) {
                    if (!((mask >> bit) & 1)) {
                        if (dp[i + 1][mask | (1 << bit)] != INF) dp[i][mask] = min(dp[i][mask], dp[i + 1][mask | (1 << bit)] + (nums1[i] ^ nums2[bit]));
                    }
                }
            }
        }
        return dp[0][0];
    }
};