class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int l = 0, r = n + 1;
        int prev_len = 0, cur_len;
        vector<vector<int>> freq(26);
        for (int i = 0; i < n; i++) {
            if (i == 0 || s[i] != s[i - 1]) {
                cur_len = 1;
            } else {
                cur_len = 1 + prev_len;
            }
            freq[s[i] - 'a'].push_back(cur_len);
            prev_len = cur_len;
        }
        int ans = -1;
        for (int i = 0; i < 26; i++) {
            if (freq[i].size() >= 3) {
                int mx1 = INT_MIN, mx2 = INT_MIN, mx3 = INT_MIN;
                for (auto len : freq[i]) {
                    if (len > mx1) {
                        mx3 = mx2;
                        mx2 = mx1;
                        mx1 = len;
                    } else if (len > mx2) {
                        mx3 = mx2;
                        mx2 = len;
                    } else if (len > mx3) {
                        mx3 = len;
                    }
                }
                ans = max(ans, mx3);
            }
        }
        return ans;
    }
};