class Solution {
public:
    int maxSum(vector<int>& nums, int k, int m) {
        int n = nums.size();
        const int IINF = 1e9;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -IINF));
        vector<int> pref(n + 2);
        for (int i = 0; i <= n; i++) dp[i][0] = 0;
        // dp[0][0] = 0;
        vector<int> mx(k, -IINF);
        for (int i = 1; i <= n; i++) {
            pref[i + 1] = pref[i] + nums[i - 1];
            
            for (int j = 1; j <= k; j++) {
                if (i - m >= 0) {
                    mx[j - 1] = max(mx[j - 1], dp[i - m][j - 1] - pref[i - m + 1]);
                }
                dp[i][j] = dp[i - 1][j];
                
                if (mx[j - 1] != -IINF)
                    dp[i][j] = max(dp[i][j], pref[i + 1] + mx[j - 1]);
            }
        }
        return dp[n][k];
    }
};