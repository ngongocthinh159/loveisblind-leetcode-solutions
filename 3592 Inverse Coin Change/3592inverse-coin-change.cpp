#define ll long long
class Solution {
public:
    vector<vector<ll>> dp;
    vector<int> findCoins(vector<int>& numWays) {
        vector<int> coins;
        int n = numWays.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) dp[i] = numWays[i - 1];
        for (int i = 1; i <= n; i++) {
            if (dp[i] == 0) continue;
            if (dp[i] != 1) return {};
            coins.push_back(i);
            for (int j = n; j - i >= 0; j--) {
                dp[j] -= dp[j - i];
                if (dp[j] < 0) return {};
            }
        }
        for (int i = 1; i <= n; i++) if (dp[i] != 0) return {};
        return coins;
    }
};