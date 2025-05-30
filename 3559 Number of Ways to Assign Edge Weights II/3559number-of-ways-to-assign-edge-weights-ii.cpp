#define ll long long
#define N 100005
#define LOG 19
#define MASK(i) (1 << (i))
const int MOD = 1e9 + 7;
int par[LOG + 1][N], depth[N];
ll expo(ll a, ll b) {
    ll res = 1;
    ll cur = a;
    while (b) {
        if (b&1) res = res * cur % MOD;
        cur = cur * cur % MOD;
        b >>= 1;
    }
    return res;
}
class Solution {
public:
    vector<vector<int>> g;
    int msb;
    void dfs(int u, int p, int cur, int &d) {
        d = max(d, cur);
        for (auto v : g[u]) if (v != p) {
            par[0][v] = u;
            depth[v] = depth[u] + 1;
            dfs(v, u, cur + 1, d);
        }
    }
    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int k = depth[u] - depth[v];
        for (int bit = msb; bit >= 0; bit--) {
            if ((k >> bit) & 1) u = par[bit][u];
        }
        if (u == v) return u;
        for (int bit = msb; bit >= 0; bit--) {
            if (par[bit][u] != par[bit][v]) {
                u = par[bit][u];
                v = par[bit][v];
            }
        }
        return par[0][u];
    }
    int dist(int u, int v) {
        return depth[u] + depth[v] - 2*depth[lca(u,v)];
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1, m = queries.size();
        g.resize(n + 1);
        for (auto & e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int d = 0;
        dfs(1, -1, 0, d);
        msb = 32 - __builtin_clz(d) - 1;
        for (int j = 1; j <= msb; j++)
            for (int i = 1; i <= n; i++) 
                par[j][i] = par[j - 1][par[j - 1][i]];
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            int D = dist(u, v);
            if (D == 0) 
                ans[i] = 0;
            else
                ans[i] = expo(2, D - 1) % MOD;
        }
        return move(ans);
    }
};