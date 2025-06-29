class Solution {
public:
    bool maxSubstringLength(string s, int k) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1), freq(26, 0);
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (first[idx] == -1) first[idx] = i + 1;
            last[idx] = i + 1;
            freq[idx]++;
        }
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            int c = s[i - 1] - 'a';
            dp[i] = dp[i - 1];
            if (last[c] == i) {
                int l = -1;
                for (int firstC = 0; firstC < 26; firstC++) if (first[firstC] != -1 && first[firstC] <= i){
                    int cnt = 0;
                    for (int curC = 0; curC < 26; curC++) {
                        if (first[curC] != -1 && first[firstC] <= first[curC] && last[curC] <= i) {
                            cnt += freq[curC];
                        }
                    }
                    if (cnt == i - first[firstC] + 1 && cnt != n)
                        l = max(l, first[firstC]);
                }
                if (l != -1)
                    dp[i] = max(dp[i], 1 + dp[l - 1]);
            }
        }
        return dp[n] >= k;
    }
};