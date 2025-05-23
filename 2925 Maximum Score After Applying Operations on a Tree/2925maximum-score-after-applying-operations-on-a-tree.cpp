#define ll long long
class Solution {
public:
    vector<vector<ll>> dp;
    int n;
    vector<vector<int>> g;
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        n = values.size();
        g.resize(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dp.assign(n, vector<ll>(2));
        dfs(0, -1, values);
        return dp[0][0];
    }
    void dfs(int u, int p, vector<int>& nums) {
        if (g[u].size() == 1 && g[u][0] == p) {
            dp[u][0] = 0;
            dp[u][1] = nums[u];
            return;
        };
        for (auto v : g[u]) if (v != p) {
            dfs(v, u, nums);
        }
        ll res1 = 0, res2 = 0;
        for (auto v : g[u]) {
            res1 += dp[v][1];
            res2 += dp[v][0];
        }
        dp[u][1] = res1 + nums[u];
        dp[u][0] = max(res2 + nums[u], res1);
    }
};