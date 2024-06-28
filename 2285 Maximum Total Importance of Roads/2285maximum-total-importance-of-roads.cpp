class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> cnt(n, 0);
        for (auto &e : roads) {
            cnt[e[0]]++;
            cnt[e[1]]++;
        }
        vector<pair<int,int>> v;
        for (int i = 0; i < n; i++) v.push_back({cnt[i], i});
        sort(v.begin(), v.end(), greater<pair<int,int>>());
        int cur = n;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += 1LL*v[i].first*cur;
            cur--;
        }
        return ans;
    }
};