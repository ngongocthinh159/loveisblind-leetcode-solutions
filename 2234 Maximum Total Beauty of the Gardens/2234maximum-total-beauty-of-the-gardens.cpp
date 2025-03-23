class Solution {
public:
    bool check(int min, int n, long long remainFlowers, vector<int> &flowers, vector<long long> &pref) {
        auto it = upper_bound(flowers.begin(), flowers.begin() + n, min);
        int idx = it - flowers.begin();
        idx--;
        if (idx >= 0) {
            return pref[idx + 1] + remainFlowers >= 1LL * min * (idx + 1);
        } else
            return true;
    }
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        int n = flowers.size();
        sort(flowers.begin(), flowers.end());
        vector<long long> surf(n + 3), pref(n + 1);
        for (int i = n - 1; i >= 0; i--)
            surf[i + 1] = surf[i + 2] + max(0, target - flowers[i]);
        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + flowers[i];
        long long ans = 0;
        for (int i = n; i >= 0; i--) {
            int complete = n - i;
            if (newFlowers >= surf[i + 1]) {
                if (i == 0) {
                    ans = max(ans, 1LL * complete * full);
                    continue;
                }
                if (flowers[i - 1] >= target) continue;
                long long remainFlowers = newFlowers - surf[i + 1];
                int incomplete = n - complete;
                int min_flower = 0;
                if (incomplete) {
                    int l = 0, r = target;
                    while (r - l > 1) {
                        int m = l + (r - l)/2;
                        if (check(m, incomplete, remainFlowers, flowers, pref))
                            l = m;
                        else
                            r = m;
                    }
                    min_flower = l;
                }
                ans = max(ans, 1LL * complete * full + 1LL * min_flower * partial);
            }
        }
        return ans;
    }
};