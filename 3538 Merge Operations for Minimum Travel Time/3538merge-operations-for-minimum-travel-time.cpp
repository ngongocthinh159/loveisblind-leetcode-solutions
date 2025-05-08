#define ll long long
#define N 100005
#define K 11
ll dp[N][K][K];
class Solution {
public:
    const ll LINF = 1e18;
    vector<ll> pref;
    ll dfs(int i, int prev_merge, int remain_merge, vector<int>& pos, vector<int>& time) {
        if (i == pos.size()) {
            if (remain_merge != 0) return LINF;
            return 0;
        }
        if (dp[i][prev_merge][remain_merge] != -1) return dp[i][prev_merge][remain_merge];

        ll res = LINF;
        if (i == 0)
            res = dfs(i + 1, 0, remain_merge, pos, time);
        else {
            for (int merge = 0; merge <= remain_merge && i + remain_merge < pos.size(); merge++) {
                res = min(res, dfs(i + merge + 1, merge, remain_merge - merge, pos, time) + 
                    (pref[i] - pref[i - 1 - prev_merge]) * (pos[i + merge] - pos[i - 1]));
            }
        }
        return dp[i][prev_merge][remain_merge] = res;
    }
    int minTravelTime(int l, int n, int k, vector<int>& pos, vector<int>& time) {
        pref.resize(n + 1);
        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + time[i];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= k; j++)
                for (int m = 0; m <= k; m++) dp[i][j][m] = -1;
        return dfs(0, 0, k, pos, time);
    }
};