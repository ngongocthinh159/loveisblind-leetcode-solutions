class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        long long sum = 0;
        vector<long long> pref(n + 1);
        for (int i = 0; i < n; i++) {
            sum += piles[i];
            pref[i + 1] = pref[i] + piles[i];
        }
        vector<long long> dp(n);
        for (int i = 0; i < n; i++) dp[i] = piles[i];
        for (int len = 2; len <= n; len++) {
            vector<long long> ndp(n);
            for (int i = 0; i < n; i++) {
                int j = i + len - 1;
                if (j >= n) break;
                ndp[i] = max(dp[i], pref[j + 1] - pref[i] - min(dp[i], dp[i + 1]));
            }
            swap(dp, ndp);
        }
        return 2*dp[0] > sum;
    }
};