#define ll long long
class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<ll>> dp;
    vector<vector<int>> g;
    int n;
    ll ans = 0;
    bool can_use(int x, int &cur_mask) {
        while (x != 0) {
            int d = x % 10;
            if ((cur_mask >> d) & 1) {
                return false;
            }
            cur_mask = cur_mask | (1 << d);
            x /= 10;
        }
        return true;
    }
    void dfs(int u, int p, vector<int>&vals) {
        for (auto v : g[u]) if (v != p) 
            dfs(v, u, vals);
        
        int cur_mask = 0;
        if (can_use(vals[u], cur_mask)) 
            dp[u][cur_mask] = vals[u];

        int nmask = (1 << 10) - 1;
        for (auto v : g[u]) if (v != p) {
            vector<ll> ndp = dp[u];
            for (int v_mask = 0; v_mask < (1 << 10); v_mask++) if (dp[v][v_mask]) {
                int u_mask = v_mask ^ nmask;
                for (int submask = u_mask; ; submask = (submask - 1) & u_mask) {
                    int nmask = submask | v_mask;
                    ndp[nmask] = max(ndp[nmask], dp[u][submask] + dp[v][v_mask]);
                    if (submask == 0) break;
                }
            }
            swap(ndp, dp[u]);
        }
    }
    int goodSubtreeSum(vector<int>& vals, vector<int>& par) {
        n = vals.size();
        dp.resize(n, vector<ll>(1 << 10));
        g.resize(n);
        for (int i = 1; i < n; i++) {
            g[i].push_back(par[i]);
            g[par[i]].push_back(i);
        }
        dfs(0, -1, vals);
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll cur = -1e18;
            for (int mask = 0; mask < (1<< 10); mask++) {
                cur = max(cur, dp[i][mask]);
            }
            ans = (ans + cur) % MOD;
        }
        return ans;
    }
};