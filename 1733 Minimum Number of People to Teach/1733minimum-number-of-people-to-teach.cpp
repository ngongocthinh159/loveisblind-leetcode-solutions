class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<unordered_set<int>> l(m + 1);
        for (int i = 1; i <= m; i++) {
            auto& list = languages[i - 1];
            for (auto x : list) l[i].insert(x);
        }
        int k = friendships.size();
        unordered_set<int> vs;
        for (int i = 0; i < k; i++) {
            int u = friendships[i][0];
            int v = friendships[i][1];
            bool ok = false;
            for (auto x : l[u]) if (l[v].count(x)) {
                ok = true;
                break;
            }
            if (!ok) {
                vs.insert(u);
                vs.insert(v);
            }
        }
        int ans = INT_MAX;
        for (int i = 1; i <= n; i++) {
            int cur = 0;
            for (auto v : vs) if (!l[v].count(i)) ++cur;
            ans = min(ans, cur);
        }
        return ans;
    }
};