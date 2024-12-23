class Solution {
public:
    vector<int> dp;
    int n;
    vector<vector<int>> g;
    int ans = 0;
    void dfs(int u, int par, string &s) {
        int res = 0;
        for (auto v : g[u]) if (v != par) {
            dfs(v, u, s);
            if (s[u] != s[v]) res = max(res, dp[v]);
        }
        dp[u] = 1 + res;
    }
    void dfs2(int u, int par, string &s) {
        int mx1 = 0, mx2 = 0;
        for (auto v : g[u]) if (v != par) {
            dfs2(v, u, s);
            if (s[u] != s[v]) {
                if (mx1 < dp[v]) {
                    mx2 = mx1;
                    mx1 = dp[v];
                } else if (mx2 < dp[v]) {
                    mx2 = dp[v];
                }
            }
        }
        ans = max(ans, mx1 + mx2 + 1);
    }
    int longestPath(vector<int>& parent, string s) {
        n = parent.size();
        dp.resize(n);
        g.resize(n);
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1) {
                g[i].push_back(parent[i]);
                g[parent[i]].push_back(i);
            }
        }
        dfs(0, -1, s);
        dfs2(0, -1, s);
        return ans;
    }
};