class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> pre1(n + 1), pre2(n + 1);
        for (int i = 0; i < n; i++) {
            pre1[i + 1] = pre1[i] + grid[0][i];
            pre2[i + 1] = pre2[i] + grid[1][i]; 
        }
        long long ans = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            int idx_1 = i + 1;
            long long sum1 = 0;
            if (idx_1 < n) {
                sum1 = pre1[n] - pre1[idx_1];
            }
            int idx2 = i - 1;
            long long sum2 = 0;
            if (idx2 >= 0) {
                sum2 = pre2[idx2 + 1];
            }
            ans = min(ans, max(sum1, sum2));
        }
        return ans;
    }
};