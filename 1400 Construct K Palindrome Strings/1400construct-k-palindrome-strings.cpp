class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> freq(26);
        int n = s.size();
        for (auto c : s) {
            freq[c - 'a']++;
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++) if (freq[i]&1) cnt++;
        return cnt <= k && n >= k;
    }
};