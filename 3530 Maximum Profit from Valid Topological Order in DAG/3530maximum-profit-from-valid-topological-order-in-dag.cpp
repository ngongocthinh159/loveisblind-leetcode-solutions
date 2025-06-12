#define ll long long
class Solution {
public:
    vector<ll> dp;
    vector<int> depend;
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        dp.assign((1 << n), -1);
        dp[0] = 0;
        depend.assign(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            auto &e = edges[i];
            depend[e[0]] = depend[e[0]] | (1 << e[1]);
        }
        for (int mask = 0; mask < (1 << n); mask++) if (dp[mask] != -1) {
            int pos = n - __builtin_popcount(mask);
            for (int i = 0; i < n; i++) if (!((mask>>i)&1) && (depend[i] & mask) == depend[i]) {
                dp[mask | (1 << i)] = max(dp[mask | (1 << i)], dp[mask] + 1LL * score[i] * pos);
            }
        }
        int fmask = (1 << n) - 1;
        return dp[fmask];
    }
};