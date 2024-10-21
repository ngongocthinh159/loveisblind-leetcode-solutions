class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int ans =0;
        for (int i = 0; i < s.size(); i++) {
            vector<int> cnt(26);
            bool ok = false;
            for (int j = i; j < s.size(); j++) {
                if (!ok) {
                    cnt[s[j] - 'a']++;
                    if (cnt[s[j] - 'a'] >= k) ok = true;
                }
                if (ok) ans++;
            }
        }
        return ans;
    }
};