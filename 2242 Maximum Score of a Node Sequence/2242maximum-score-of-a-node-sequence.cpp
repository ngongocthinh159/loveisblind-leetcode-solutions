class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        vector<set<pair<int,int>>> mx;
        mx.resize(scores.size());
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            mx[u].insert({scores[v], v});
            mx[v].insert({scores[u], u});
            if (mx[u].size() > 3) mx[u].erase(mx[u].begin());
            if (mx[v].size() > 3) mx[v].erase(mx[v].begin());
        }
        int ans = -1;
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            for (auto [w1, s] : mx[u]) {
                for (auto [w2, e] : mx[v]) {
                    if (s != e && s != v && e != u) {
                        ans = max(ans, scores[u] + scores[v] + scores[s] + scores[e]);
                    }
                }
            }
        }
        return ans;
    }
};