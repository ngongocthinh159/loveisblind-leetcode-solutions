class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[s.size()] = true;
        for (int i = s.size() - 1; i >=0; i--) {
            for (int j = 0; j < wordDict.size(); j++) {
                if (i + wordDict[j].size() - 1 < s.size()) {
                    if (s.substr(i, wordDict[j].size()) == wordDict[j]) {
                        if (dp[i + wordDict[j].size()]) {dp[i] = true; break;}
                    }
                }
            }
        }
        return dp[0];
    }
};