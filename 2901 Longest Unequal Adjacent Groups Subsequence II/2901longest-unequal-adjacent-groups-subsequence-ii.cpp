class Solution {
public:
    int dist(string &s, string &t) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) if (s[i] != t[i]) res++;
        return res;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n), trace(n, -1);
        int mx = 0, bestI = -1;
        for (int i = 0; i < n; i++) {
            int mx_j = 0;
            for (int j = 0; j < i; j++) {
                if (words[i].size() == words[j].size() &&
                    groups[i] != groups[j] &&
                    dist(words[i], words[j]) == 1) {
                    if (mx_j < dp[j]) {
                        mx_j = dp[j];
                        trace[i] = j;
                    }
                }
            }
            dp[i] = 1 + mx_j;
            if (mx < dp[i]) {
                mx = dp[i];
                bestI = i;
            }
        }
        vector<string> res;
        while (bestI != -1) {
            res.push_back(words[bestI]);
            bestI = trace[bestI];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};