class Solution {
public:
    vector<vector<int>> g;
    int n;
    vector<vector<int>> dp;
    vector<int> col;
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        n = colors.size();
        g.resize(n);
        vector<int> deg(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
        }
        col.resize(n);
        dp.assign(n, vector<int>(26, -1));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int c = 0; c < 26; c++) {
                bool hasCycle = false;
                ans = max(ans, dfs(i, c, colors, hasCycle));
                if (hasCycle) return -1;
            }
        }
        return ans;
    }
    int dfs(int u, int c, string &colors, bool &hasCycle) {
        col[u] = 1;
        if (dp[u][c] != -1) {
            col[u] = 0;
            return dp[u][c];
        }
        int res = 0;
        for (auto v : g[u]) {
            if (col[v] == 1) {
                hasCycle = 1;
            } else if (col[v] == 0)
                res = max(res, dfs(v, c, colors, hasCycle));
        }
        col[u] = 0;
        return dp[u][c] = res + (colors[u] - 'a' == c ? 1 : 0);
    }
};