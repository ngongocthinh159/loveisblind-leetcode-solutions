class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1));
        dp[n][0] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int l = i, r = n;
            while (r - l > 1) {
                int m = l + (r - l)/2;
                if (events[m][0] > events[i][1])
                    r = m;
                else
                    l = m;
            }
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i + 1][j];
                dp[i][j] = max(dp[i][j], events[i][2] + dp[r][j - 1]);
            }
        }
            
        return dp[0][k];
    }
};