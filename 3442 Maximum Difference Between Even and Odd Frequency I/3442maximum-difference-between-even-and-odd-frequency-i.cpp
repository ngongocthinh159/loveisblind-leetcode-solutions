class Solution {
public:
    int maxDifference(string s) {
        int freq[26]{};
        int n = s.size();
        for (int i = 0; i < n; i++) freq[s[i] - 'a']++;
        int mxodd = -1, mneven = 1e9;
        for (int i = 0; i < 26; i++) {
            if (freq[i]) {
                if (freq[i]&1) mxodd = max(mxodd, freq[i]);
                else mneven = min(mneven, freq[i]);
            }
        }
        return mxodd - mneven;
    }
};