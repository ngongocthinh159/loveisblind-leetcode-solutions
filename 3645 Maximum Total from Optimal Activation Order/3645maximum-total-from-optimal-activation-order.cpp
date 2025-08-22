class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        int n = value.size();
        long long ans = 0;
        vector<vector<int>> l(n + 1);
        for (int i = 0; i < n; i++) l[limit[i]].push_back(value[i]);
        for (int i = 1; i <= n; i++) {
            if (l[i].size() <= i) {
                for (auto v : l[i]) ans += v;
            } else {
                int idx = l[i].size() - i - 1;
                nth_element(l[i].begin(), l[i].begin() + idx, l[i].end());
                for (int j = idx + 1; j < l[i].size(); j++)
                    ans += l[i][j];
            }
        }
        return ans;
    }
};