class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size() + 1, 0);
        for (int i = arr.size() - 1; i >= 0; i--) {
            int mx = INT_MIN;
            for (int j = i; j < min(i + k, (int) arr.size()); j++) {
                mx = max(mx, arr[j]);
                dp[i] = max(dp[i], (j - i + 1)*mx + dp[j + 1]);
            }
        }
        return dp[0];
    }
};