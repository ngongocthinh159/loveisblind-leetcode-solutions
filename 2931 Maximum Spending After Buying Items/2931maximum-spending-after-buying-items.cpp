class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        int n = values.size();
        int m = values[0].size();
        vector<int> v;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                v.push_back(values[i][j]);
            }
        }
        sort(v.begin(), v.end());
        long long ans = 0;
        for (int i = 0; i < n*m; i++) {
            ans += 1LL*(i + 1)*v[i];
        }
        return ans;
    }
};