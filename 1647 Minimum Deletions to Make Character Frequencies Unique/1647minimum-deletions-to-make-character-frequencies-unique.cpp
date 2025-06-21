class Solution {
public:
    int minDeletions(string s) {
        int freq[26]{};
        for (auto c : s) freq[c - 'a']++;
        vector<int> v;
        for (int i = 0; i < 26; i++) if (freq[i]) v.push_back(freq[i]);
        sort(v.begin(), v.end());
        int ans = 0;
        for (int i = (int) v.size() - 2; i >= 0; i--) {
            if (v[i] >= v[i + 1]) {
                ans += v[i] - max(0, (v[i + 1] - 1));
                v[i] = max(0, (v[i + 1] - 1));
            }
        }
        return ans;
    }
};