class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int m = costs.size();;
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            int res = INT_MAX;
            for (int j = 0; j < m; j++) {
                int d;
                if (j == 0) d = 1;
                else if (j == 1) d = 7;
                else d = 30;
                int tar = max(days[i - 1] - d + 1, 1);
                // cout << i << " " << tar << "\n";
                int l = -1, r = n;
                while (r - l > 1) {
                    int m = l + (r - l)/2;
                    if (days[m] >= tar)
                        r = m;
                    else
                        l = m;
                }
                res = min(res, costs[j] + dp[r]);
            }
            dp[i] = res;
        }
        return dp[n];
    }
};