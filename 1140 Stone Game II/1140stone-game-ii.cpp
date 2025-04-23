class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
        long long sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += piles[i];
            for (int m = n; m >= 1; m--) {
                for (int j = i; j - i + 1 <= 2*m && j < n; j++) {
                    dp[i][m] = max(dp[i][m], sum - dp[j + 1][max(j - i + 1, m)]);
                }
            }
        }
        // Time: O(n^3)
        // Space: O(n^2)
        return dp[0][1];
    }
};