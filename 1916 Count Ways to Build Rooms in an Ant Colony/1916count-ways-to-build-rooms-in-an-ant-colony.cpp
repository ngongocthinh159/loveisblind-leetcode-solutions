#define ll long long
#define N 100005
const int MOD = 1e9 + 7;
ll fact[N], inv[N];
ll expo(ll a, ll b) {
    ll res = 1;
    ll cur = a;
    while (b) {
        if (b&1)
            res = res * cur % MOD;
        cur = cur * cur % MOD;
        b >>= 1;
    }
    return res;
}
auto init = []{
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % MOD;
    inv[N - 1] = expo(fact[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
    return 0;
}();
ll nCk(int n, int k) {
    if (k > n) return 0;
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}
class Solution {
public:
    vector<vector<int>> g;
    vector<int> subSize;
    void dfs_sz(int u) {
        subSize[u] = 1;
        for (auto v : g[u]) {
            dfs_sz(v);
            subSize[u] += subSize[v];
        }
    }
    int dfs_ans(int u) {
        ll res = 1;
        int sz = subSize[u] - 1;
        for (auto v : g[u]) {
            int res_v = dfs_ans(v);
            res = res * nCk(sz, subSize[v]) % MOD * res_v % MOD;
            sz -= subSize[v];
        }
        return res;
    }
    int waysToBuildRooms(vector<int>& prevRoom) {
        int n = prevRoom.size();
        vector<int> indeg(n);
        g.resize(n);
        subSize.resize(n);
        for (int i = 0; i < n; i++) {
            if (prevRoom[i] == -1) continue;
            g[prevRoom[i]].push_back(i);
            indeg[i]++;
        }
        ll ans = 1;
        for (int i = 0; i < n; i++) if (!indeg[i]) {
            dfs_sz(i);
        }
        int sz = n;
        for (int i = 0; i < n; i++) if (!indeg[i]) {
            ans = ans * nCk(sz, subSize[i]) % MOD * dfs_ans(i) % MOD;
            sz -= subSize[i];
        }
        return ans;
    }
};