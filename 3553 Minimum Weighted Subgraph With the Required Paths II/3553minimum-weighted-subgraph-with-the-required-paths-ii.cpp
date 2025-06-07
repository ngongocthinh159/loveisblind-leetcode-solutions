#define ll long long
#define RELAX(x,y) (depth[x] <= depth[y] ? (x) : (y))
#define MASK(x) (1 << (x))
class Solution {
public:
    vector<vector<pair<int,int>>> g;
    int n, msb, T = -1;
    vector<vector<int>> rmq;
    vector<int> depth;
    vector<ll> pref;
    vector<int> pos, euler;
    int solve(int src1, int src2, int dst) {
        return (dist(src1, src2) + dist(src1, dst) + dist(src2, dst)) / 2;
    }
    void dfs(int u, int p) {
        pos[u] = ++T;
        euler[T] = u;
        for (auto [v, w] : g[u]) if (v != p) {
            pref[v] = pref[u] + w;
            depth[v] = depth[u] + 1;
            dfs(v, u);
            euler[++T] = u;
        }
    }
    int lca(int u, int v) {
        if (pos[u] > pos[v]) swap(u, v);
        int msb = 32 - __builtin_clz(pos[v] - pos[u] + 1) - 1;
        return RELAX(rmq[msb][pos[u]], rmq[msb][pos[v] - MASK(msb) + 1]);
    }
    ll dist(int u, int v) {
        return pref[u] + pref[v] - 2*pref[lca(u, v)];
    }
    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n = edges.size() + 1;
        g.resize(n);
        depth.resize(n);
        pref.resize(n);
        pos.resize(n);
        euler.resize(2*n);
        for (auto & e : edges) {
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});
        }
        dfs(0, -1);
        msb = 32 - __builtin_clz(T + 1) - 1;
        rmq.assign(msb + 1, vector<int>(T + 1));
        for (int i = 0; i <= T; i++) rmq[0][i] = euler[i];
        for (int j = 1; j <= msb; j++)
            for (int i = 0; i + MASK(j) - 1 <= T; i++)
                rmq[j][i] = RELAX(rmq[j - 1][i], rmq[j - 1][i + MASK(j - 1)]);
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i< m; i++) {
            ans[i] = solve(queries[i][0], queries[i][1], queries[i][2]);
        }
        return ans;
    }
};