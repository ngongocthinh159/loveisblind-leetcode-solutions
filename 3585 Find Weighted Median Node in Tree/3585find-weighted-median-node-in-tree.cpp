#define ll long long
class Solution {
public:
    vector<vector<pair<int,int>>> g;
    vector<ll> pref;
    vector<vector<int>> par;
    vector<int> depth;
    int msb;
    void dfs(int u, int p) {
        for (auto [v, w] : g[u]) if (v != p) {
            depth[v] = depth[u] + 1;
            pref[v] = pref[u] + w;
            par[0][v] = u;
            dfs(v, u);
        }
    }
    ll lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int k = depth[u] - depth[v];
        for (int bit = msb; bit >= 0; bit--) {
            if ((k >> bit)&1)
                u = par[bit][u];
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
    ll dist(int u, int v, int uv) {
        return pref[u] + pref[v] - 2 * pref[uv];
    }
    int find(int u, int v) {
        if (u == v) return u;
        int lca_uv = lca(u, v);
        int e_u_lca = depth[u] - depth[lca_uv];
        int e_v_lca = depth[v] - depth[lca_uv];
        ll d_u_lca = pref[u] - pref[lca_uv];
        ll D = dist(u, v, lca_uv);
        int ans = -1;
        if (2*d_u_lca >= D) {
            int mx = 32 - __builtin_clz(e_u_lca) - 1;
            ll cur = 0;
            for (int bit = mx; bit >= 0; bit--) {
                if (2*(cur + pref[u] - pref[par[bit][u]]) < D) {
                    cur += pref[u] - pref[par[bit][u]];
                    u = par[bit][u];
                }
            }
            ans = par[0][u];
        } else {
            int mx = 32 - __builtin_clz(e_v_lca) - 1;
            ll cur = pref[u] - pref[lca_uv];
            for (int bit = mx; bit >= 0; bit--) {
                if (2*(cur + pref[par[bit][v]] - pref[lca_uv]) >= D) {
                    v = par[bit][v];
                }
            }
            ans = v;
        }
        return ans;
    }
    vector<int> findMedian(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        g.resize(n);
        for (auto & e : edges) {
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});
        }
        pref.resize(n);
        depth.resize(n);
        msb = 32 - __builtin_clz(n) - 1;
        par.assign(msb + 1, vector<int>(n));
        dfs(0, -1);
        for (int j = 1; j <= msb; j++) 
            for (int i = 0; i < n; i++) 
                par[j][i] = par[j - 1][par[j - 1][i]];
        
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            ans[i] = find(queries[i][0], queries[i][1]);
        }
        return ans;
    }
};