class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int m = queries.size();
        vector<pair<int,int>> q(m);
        for (int i = 0; i < m; i++) q.push_back({queries[i], i});
        sort(q.begin(), q.end());
        sort(items.begin(), items.end());
        vector<int> ans(m);
        int j = -1;
        int mx = -1;
        for (int i = 0; i < q.size(); i++) {
            while (j + 1 < items.size() && items[j + 1][0] <= q[i].first) {
                mx = max(mx, items[j + 1][1]);
                j++;
            }
            if (mx == -1) ans[q[i].second] = 0;
            else ans[q[i].second] = mx;
        }
        return ans;
    }
};