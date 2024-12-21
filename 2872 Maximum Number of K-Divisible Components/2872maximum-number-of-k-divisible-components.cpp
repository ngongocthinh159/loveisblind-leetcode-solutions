#define ll long long
class Solution {
public:
    vector<vector<int>> g;
    int ans = 0;
    ll dfs(int u, int par, int k, vector<int> &values) {
        ll sum = values[u];
        for (auto v : g[u]) if (v != par) {
            sum = sum + dfs(v, u, k, values);
        }
        if (sum%k == 0) ans++;
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        g.resize(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs(0, -1, k, values);
        return ans;
    }
};