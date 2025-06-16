#define ll long long
struct FenwickTree {
    vector<ll> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<ll> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    ll sum(int r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, ll delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
class Solution {
public:
    vector<ll> euler;
    vector<int> tin, tout;
    vector<int> depth;
    int T = -1;
    vector<vector<pair<int,int>>> g;
    void dfs(int u, int p, int W) {
        tin[u] = ++T;
        euler[T] = W;
        for (auto [v, w] : g[u]) if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u, w);
        }
        tout[u] = ++T;
        euler[T] = -W;
    }
    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        euler.resize(2*(n + 1));
        tin.resize(2*(n + 1));
        tout.resize(2*(n + 1));
        g.resize(n + 1);
        depth.resize(n + 1);
        for (auto & e : edges) {
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});
        }
        dfs(1, -1, 0);
        FenwickTree tree(euler);
        int m = queries.size(), top = 0;
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            if (queries[i][0] == 1) {
                int u = queries[i][1];
                int v = queries[i][2];
                int w = queries[i][3];
                if (depth[u] < depth[v]) swap(u, v);
                ll delta = w - euler[tin[u]];
                tree.add(tin[u], delta);
                euler[tin[u]] = w;

                delta = -w - euler[tout[u]];
                tree.add(tout[u], delta);
                euler[tout[u]] = -w;
            } else {
                ans[top++] = tree.sum(0, tin[queries[i][1]]);
            }
        }
        return vector<int>(ans.begin(), ans.begin() + top);
    }
};