class Solution {
public:
    vector<long long> fi;
    vector<long long> se;
    vector<long long> ans;
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        fi = vector<long long>(n, 0);
        se = vector<long long>(n, 0);
        ans = vector<long long>(n, 0);
        vector<vector<int>> g(n);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs1(0,-1,g,price); // calculate in
        dfs2(0,-1,0,g,price); // calculate out
        long long res = 0;
        for (int i = 0; i < n; i++) {
            if (g[i].size() == 1) res = max(res, ans[i] - price[i]);
        }
        return res;
    }
    void dfs1(int u, int parent, vector<vector<int>> &g, vector<int> &price) {
        fi[u] = se[u] = price[u];
        for (auto &v : g[u]) {
            if (v != parent) {
                dfs1(v, u, g, price);
                if (fi[u] < fi[v] + price[u]) {
                    se[u] = fi[u];
                    fi[u] = fi[v] + price[u];
                } else if (se[u] < fi[v] + price[u]) {
                    se[u] = fi[v] + price[u];
                }
            }
        }
    }
    void dfs2(int u, int parent, long long out_u, vector<vector<int>> &g, vector<int> &price) {
        ans[u] = max(fi[u], out_u);
        for (auto &v : g[u]) {
            if (v != parent) {
                long long inU_without_v = fi[v] + price[u] == fi[u] ? se[u] : fi[u];
                long long out_v = max(out_u, inU_without_v) + price[v];
                dfs2(v, u, out_v, g, price);
            }
        }
    }
};