class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();
        unordered_map<int,int> f1, f2, f;
        int mn = INT_MAX;
        for (auto x : basket1) f1[x]++, f[x]++, mn = min(mn, x);
        for (auto x : basket2) f[x]++, mn = min(mn, x);
        vector<int> v;
        for (auto [x, cnt] : f) {
            if (cnt&1) return -1;
            int C = abs(f1[x] - cnt/2);
            while (C--) v.push_back(x);
        }
        if (v.empty()) return 0;
        int len = v.size() / 2;
        nth_element(v.begin(), v.begin() + len - 1, v.end());
        long long ans = 0;
        for (int i = 0; i < len; i++)
            ans += min(v[i], 2 * mn);
        return ans;
    }
};