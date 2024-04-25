class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> dp(26);
        for (int i = n - 1; i >= 0; i--) {
            vector<int> cur(26);
            for (int last = 0; last < 26; last++) {
                if (abs(s[i] - 'a' - last) <= k) {
                    cur[last] = max(dp[last], 1 + dp[s[i] - 'a']);
                } else {
                    cur[last] = dp[last];
                }
            }
            dp = cur;
        }
        return *max_element(dp.begin(), dp.end());
    }
};