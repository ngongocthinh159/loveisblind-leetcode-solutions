class Solution {
public:
    int maximumLength(string s) {
        vector<multiset<int>> freq(26);
        int cur_len, prev_len = 0;
        int ans = -1;
        for (int i = 0; i < s.size(); i++) {
            if (i == 0 || s[i] != s[i - 1]) {
                cur_len = 1;
            } else {
                cur_len = 1 + prev_len;
            }
            if (freq[s[i] - 'a'].size() >= 3) {
                if (*freq[s[i] - 'a'].begin() < cur_len) {
                    freq[s[i] - 'a'].erase(freq[s[i] - 'a'].begin());
                    freq[s[i] - 'a'].insert(cur_len);
                }
            } else {
                freq[s[i] - 'a'].insert(cur_len);
            }
            if (freq[s[i] - 'a'].size() >= 3) ans = max(ans, *freq[s[i] - 'a'].begin());
            prev_len = cur_len;
        }
        return ans;
    }
};