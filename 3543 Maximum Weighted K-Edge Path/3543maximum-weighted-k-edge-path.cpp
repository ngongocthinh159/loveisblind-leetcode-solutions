class Solution {
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        vector<vector<pair<int,int>>> g(n);
        for (auto &e : edges) {
            g[e[0]].push_back({e[1], e[2]});
        }
        for (int i = 0; i < n; i++) sort(g[i].begin(), g[i].end(), [](pair<int,int> &p1, pair<int,int> &p2) {
            return p1.second < p2.second;
        });
        vector<unordered_set<int>> dp(n);
        for (int i = 0; i < n; i++) dp[i].insert(0);
        for (int j = 1; j <= k; j++) {
            vector<unordered_set<int>> ndp(n);
            for (int u = 0; u < n; u++)
                for (auto sum : dp[u]) {
                    for (auto &[v, w] : g[u]) {
                        if (sum + w >= t) break;
                        ndp[v].insert(sum + w);
                    }
                }
            swap(dp, ndp);
        }
        int ans = -1;
        for (int u = 0; u < n; u++)
            for (auto sum : dp[u]) ans = max(ans, sum);
        return ans;
    }
};