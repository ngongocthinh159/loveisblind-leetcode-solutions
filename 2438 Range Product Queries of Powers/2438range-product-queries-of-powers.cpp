class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> p;
        for (int bit = 0; bit <= 30; bit++) if ((n >> bit) & 1) p.push_back((1 << bit));
        int m = queries.size();
        vector<int> ans(m);
        const int MOD = 1e9 + 7;
        for (int i = 0; i < m; i++) {
            long long cur = 1;
            for (int j = queries[i][0]; j <= queries[i][1]; j++) {
                cur = cur * p[j] % MOD;
            }
            ans[i] = cur;
        }
        return ans;
    }
};