class Solution {
public:
    int minimumDeletions(string word, int k) {
        int freq[26]{};
        for (auto c : word) freq[c - 'a']++;
        vector<int> v;
        for (int i = 0; i < 26; i++) if (freq[i]) v.push_back(freq[i]);
        sort(v.begin(), v.end());
        int n = v.size();
        vector<int> pref(n + 1);
        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + v[i];
        int ans = INT_MAX;
        for (int i = v[0], l = 0, r = 0; i <= (int) word.size(); i++) {
            while (l < n && v[l] < i - k) {
                l++;
            }
            while (r < n && v[r] <= i) r++;

            int cur = pref[l];
            if (r < n) {
                int len = n - 1 - r + 1;
                cur += pref[n] - pref[r] - len * i;
            }
            ans = min(ans, cur);
        }
        return ans;
    }
};