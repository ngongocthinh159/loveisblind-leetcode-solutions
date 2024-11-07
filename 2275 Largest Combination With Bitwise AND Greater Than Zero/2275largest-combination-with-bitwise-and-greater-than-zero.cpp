class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> cnt(32);
        int mx = -1;
        for (auto x : candidates) mx = max(mx, x);
        int LOG = 32 - __builtin_clz(mx) - 1;
        for (auto x : candidates) {
            for (int bit = LOG; bit >= 0; bit--) {
                if ((x >> bit) & 1) cnt[bit]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < cnt.size(); i++) ans = max(ans, cnt[i]);
        return ans;
    }
};